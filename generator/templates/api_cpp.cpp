//* Copyright 2017 The Dawn Authors
//*
//* Licensed under the Apache License, Version 2.0 (the "License");
//* you may not use this file except in compliance with the License.
//* You may obtain a copy of the License at
//*
//*     http://www.apache.org/licenses/LICENSE-2.0
//*
//* Unless required by applicable law or agreed to in writing, software
//* distributed under the License is distributed on an "AS IS" BASIS,
//* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//* See the License for the specific language governing permissions and
//* limitations under the License.

#include <utility>

{% set api = metadata.api.lower() %}
{% if 'dawn' in enabled_tags %}
    #include "dawn/{{api}}_cpp.h"
{% else %}
    #include "{{api}}/{{api}}_cpp.h"
{% endif %}

#ifdef __GNUC__
// error: 'offsetof' within non-standard-layout type '{{metadata.namespace}}::XXX' is conditionally-supported
#pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif

namespace {{metadata.namespace}} {
    {% for type in by_category["enum"] %}
        {% set CppType = as_cppType(type.name) %}
        {% set CType = as_cType(type.name) %}

        // {{CppType}}

        static_assert(sizeof({{CppType}}) == sizeof({{CType}}), "sizeof mismatch for {{CppType}}");
        static_assert(alignof({{CppType}}) == alignof({{CType}}), "alignof mismatch for {{CppType}}");

        {% for value in type.values %}
            static_assert(static_cast<uint32_t>({{CppType}}::{{as_cppEnum(value.name)}}) == {{as_cEnum(type.name, value.name)}}, "value mismatch for {{CppType}}::{{as_cppEnum(value.name)}}");
        {% endfor %}
    {% endfor -%}

    {% for type in by_category["bitmask"] %}
        {% set CppType = as_cppType(type.name) %}
        {% set CType = as_cType(type.name) + "Flags" %}

        // {{CppType}}

        static_assert(sizeof({{CppType}}) == sizeof({{CType}}), "sizeof mismatch for {{CppType}}");
        static_assert(alignof({{CppType}}) == alignof({{CType}}), "alignof mismatch for {{CppType}}");

        {% for value in type.values %}
            static_assert(static_cast<uint32_t>({{CppType}}::{{as_cppEnum(value.name)}}) == {{as_cEnum(type.name, value.name)}}, "value mismatch for {{CppType}}::{{as_cppEnum(value.name)}}");
        {% endfor %}
    {% endfor %}

    // ChainedStruct

    {% set c_prefix = metadata.c_prefix %}
    static_assert(sizeof(ChainedStruct) == sizeof({{c_prefix}}ChainedStruct),
            "sizeof mismatch for ChainedStruct");
    static_assert(alignof(ChainedStruct) == alignof({{c_prefix}}ChainedStruct),
            "alignof mismatch for ChainedStruct");
    static_assert(offsetof(ChainedStruct, nextInChain) == offsetof({{c_prefix}}ChainedStruct, next),
            "offsetof mismatch for ChainedStruct::nextInChain");
    static_assert(offsetof(ChainedStruct, sType) == offsetof({{c_prefix}}ChainedStruct, sType),
            "offsetof mismatch for ChainedStruct::sType");
    {% for type in by_category["structure"] %}
        {% set CppType = as_cppType(type.name) %}
        {% set CType = as_cType(type.name) %}

        // {{CppType}}

        static_assert(sizeof({{CppType}}) == sizeof({{CType}}), "sizeof mismatch for {{CppType}}");
        static_assert(alignof({{CppType}}) == alignof({{CType}}), "alignof mismatch for {{CppType}}");

        {% if type.extensible %}
            static_assert(offsetof({{CppType}}, nextInChain) == offsetof({{CType}}, nextInChain),
                    "offsetof mismatch for {{CppType}}::nextInChain");
        {% endif %}
        {% for member in type.members %}
            {% set memberName = member.name.camelCase() %}
            static_assert(offsetof({{CppType}}, {{memberName}}) == offsetof({{CType}}, {{memberName}}),
                    "offsetof mismatch for {{CppType}}::{{memberName}}");
        {% endfor %}
    {% endfor -%}

    {%- macro render_c_actual_arg(arg) -%}
        {%- if arg.annotation == "value" -%}
            {%- if arg.type.category == "object" -%}
                {{as_varName(arg.name)}}.Get()
            {%- elif arg.type.category == "enum" or arg.type.category == "bitmask" -%}
                static_cast<{{as_cType(arg.type.name)}}>({{as_varName(arg.name)}})
            {%- elif arg.type.category in ["function pointer", "native"] -%}
                {{as_varName(arg.name)}}
            {%- else -%}
                UNHANDLED
            {%- endif -%}
        {%- else -%}
            reinterpret_cast<{{decorate("", as_cType(arg.type.name), arg)}}>({{as_varName(arg.name)}})
        {%- endif -%}
    {%- endmacro -%}

    template <typename T>
    static T& AsNonConstReference(const T& value) {
        return const_cast<T&>(value);
    }

    {% for type in by_category["structure"] if type.has_free_members_function %}
        // {{as_cppType(type.name)}}
        {{as_cppType(type.name)}}::~{{as_cppType(type.name)}}() {
            if (
                {%- for member in type.members if member.annotation != 'value' %}
                    {% if not loop.first %} || {% endif -%}
                    this->{{member.name.camelCase()}} != nullptr
                {%- endfor -%}
            ) {
                {{as_cMethod(type.name, Name("free members"))}}(
                    *reinterpret_cast<{{as_cType(type.name)}}*>(this));
            }
        }

        static void Reset({{as_cppType(type.name)}}& value) {
            {{as_cppType(type.name)}} defaultValue{};
            {% for member in type.members %}
                AsNonConstReference(value.{{member.name.camelCase()}}) = defaultValue.{{member.name.camelCase()}};
            {% endfor %}
        }

        {{as_cppType(type.name)}}::{{as_cppType(type.name)}}({{as_cppType(type.name)}}&& rhs)
        : {% for member in type.members %}
            {%- set memberName = member.name.camelCase() -%}
            {{memberName}}(rhs.{{memberName}}){% if not loop.last %},{{"\n      "}}{% endif %}
        {% endfor -%}
        {
            Reset(rhs);
        }

        {{as_cppType(type.name)}}& {{as_cppType(type.name)}}::operator=({{as_cppType(type.name)}}&& rhs) {
            if (&rhs == this) {
                return *this;
            }
            this->~{{as_cppType(type.name)}}();
            {% for member in type.members %}
                AsNonConstReference(this->{{member.name.camelCase()}}) = std::move(rhs.{{member.name.camelCase()}});
            {% endfor %}
            Reset(rhs);
            return *this;
        }

    {% endfor %}

    {% for type in by_category["object"] %}
        {% set CppType = as_cppType(type.name) %}
        {% set CType = as_cType(type.name) %}

        // {{CppType}}

        static_assert(sizeof({{CppType}}) == sizeof({{CType}}), "sizeof mismatch for {{CppType}}");
        static_assert(alignof({{CppType}}) == alignof({{CType}}), "alignof mismatch for {{CppType}}");

        {% macro render_cpp_method_declaration(type, method) -%}
            {% set CppType = as_cppType(type.name) %}
            {{as_cppType(method.return_type.name)}} {{CppType}}::{{method.name.CamelCase()}}(
                {%- for arg in method.arguments -%}
                    {%- if not loop.first %}, {% endif -%}
                    {%- if arg.type.category == "object" and arg.annotation == "value" -%}
                        {{as_cppType(arg.type.name)}} const& {{as_varName(arg.name)}}
                    {%- else -%}
                        {{as_annotated_cppType(arg)}}
                    {%- endif -%}
                {%- endfor -%}
            ) const
        {%- endmacro -%}

        {%- macro render_cpp_to_c_method_call(type, method) -%}
            {{as_cMethod(type.name, method.name)}}(Get()
                {%- for arg in method.arguments -%},{{" "}}{{render_c_actual_arg(arg)}}
                {%- endfor -%}
            )
        {%- endmacro -%}

        {% for method in type.methods -%}
            {{render_cpp_method_declaration(type, method)}} {
                {% for arg in method.arguments if arg.type.has_free_members_function and arg.annotation == '*' %}
                    *{{as_varName(arg.name)}} = {{as_cppType(arg.type.name)}}();
                {% endfor %}
                {% if method.return_type.name.concatcase() == "void" %}
                    {{render_cpp_to_c_method_call(type, method)}};
                {% else %}
                    auto result = {{render_cpp_to_c_method_call(type, method)}};
                    return {{convert_cType_to_cppType(method.return_type, 'value', 'result') | indent(8)}};
                {% endif %}
            }
        {% endfor %}
        void {{CppType}}::{{c_prefix}}Reference({{CType}} handle) {
            if (handle != nullptr) {
                {{as_cMethod(type.name, Name("reference"))}}(handle);
            }
        }
        void {{CppType}}::{{c_prefix}}Release({{CType}} handle) {
            if (handle != nullptr) {
                {{as_cMethod(type.name, Name("release"))}}(handle);
            }
        }
    {% endfor %}

    // Function

    {% for function in by_category["function"] if not function.no_cpp %}
        {%- macro render_function_call(function) -%}
            {{as_cMethod(None, function.name)}}(
                {%- for arg in function.arguments -%}
                    {% if not loop.first %}, {% endif %}{{render_c_actual_arg(arg)}}
                {%- endfor -%}
            )
        {%- endmacro -%}

        {{as_cppType(function.return_type.name) | indent(4, true) }} {{as_cppType(function.name) }}(
            {%- for arg in function.arguments -%}
                {% if not loop.first %}, {% endif %}{{as_annotated_cppType(arg)}}
            {%- endfor -%}
        ) {
            {% if function.return_type.name.concatcase() == "void" %}
                {{render_function_call(function)}};
            {% else %}
                auto result = {{render_function_call(function)}};
                return {{convert_cType_to_cppType(function.return_type, 'value', 'result')}};
            {% endif %}
        }
    {% endfor %}

}
