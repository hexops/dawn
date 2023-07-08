#!/usr/bin/python3
#
# Copyright 2022 The ANGLE Project Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# gen_interpreter_utils.py:
#   Code generator for the GLC interpreter.
#   NOTE: don't run this script directly. Run scripts/run_code_generation.py.

import os
import re
import sys

import registry_xml

EXIT_SUCCESS = 0
EXIT_FAILURE = 1

BASE_PATH = '../util/capture/trace_interpreter_autogen'

CPP_TEMPLATE = """\
// GENERATED FILE - DO NOT EDIT.
// Generated by {script_name} using data from {data_source_name}.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// {file_name}.cpp:
//   Helper code for trace interpreter.

#include "angle_trace_gl.h"
#include "trace_fixture.h"
#include "trace_interpreter.h"

namespace angle
{{
CallCapture ParseCallCapture(const Token &nameToken, size_t numParamTokens, const Token *paramTokens, const TraceStringMap &strings)
{{
{parse_cases}
    if (numParamTokens > 0)
    {{
        printf("Expected zero parameter tokens for %s\\n", nameToken);
        UNREACHABLE();
    }}
    return CallCapture(nameToken, ParamBuffer());
}}

{dispatch_cases}

void ReplayCustomFunctionCall(const CallCapture &call, const TraceFunctionMap &customFunctions)
{{
    ASSERT(call.entryPoint == EntryPoint::Invalid);
    const Captures &captures = call.params.getParamCaptures();

{custom_dispatch_cases}

    auto iter = customFunctions.find(call.customFunctionName);
    if (iter == customFunctions.end())
    {{
        printf("Unknown custom function: %s\\n", call.customFunctionName.c_str());
        UNREACHABLE();
    }}
    else
    {{
        ASSERT(call.params.empty());
        const TraceFunction &customFunc = iter->second;
        for (const CallCapture &customCall : customFunc)
        {{
            ReplayTraceFunctionCall(customCall, customFunctions);
        }}
    }}
}}
}}  // namespace angle
"""

PARSE_CASE = """\
    if (strcmp(nameToken, "{ep}") == 0)
    {{
        ParamBuffer params = ParseParameters<{pfn}>(paramTokens, strings);
        return CallCapture({call}, std::move(params));
    }}
"""

CUSTOM_DISPATCH_CASE = """\
    if (call.customFunctionName == "{fn}")
    {{
        DispatchCallCapture({fn}, captures);
        return;
    }}
"""

DISPATCH_CASE = """\
template <typename Fn, EnableIfNArgs<Fn, {nargs}> = 0>
void DispatchCallCapture(Fn *fn, const Captures &cap)
{{
    (*fn)({args});
}}
"""

FIXTURE_H = '../util/capture/trace_fixture.h'


def GetFunctionsFromFixture():
    funcs = []
    arg_counts = set()
    pattern = 'void '
    with open(FIXTURE_H) as f:
        lines = f.read().split(';')
        for line in lines:
            line = re.sub('// .*\n', '', line.strip())
            if line.startswith(pattern):
                func_name = line[len(pattern):line.find('(')]
                func_args = line.count(',') + 1
                funcs.append(func_name)
                arg_counts.add(func_args)
        f.close()
    return sorted(funcs), arg_counts


def get_dispatch(n):
    return ', '.join(['Arg<Fn, %d>(cap)' % i for i in range(n)])


def main(cpp_output_path):
    gles = registry_xml.GetGLES()
    egl = registry_xml.GetEGL()

    def fn(ep):
        return 'std::remove_pointer<PFN%sPROC>::type' % ep.upper()

    fixture_functions, arg_counts = GetFunctionsFromFixture()

    eps_and_enums = sorted(list(set(gles.GetEnums() + egl.GetEnums())))
    parse_cases = [
        PARSE_CASE.format(ep=ep, pfn=fn(ep), call='EntryPoint::%s' % enum)
        for (enum, ep) in eps_and_enums
    ]
    parse_cases += [
        PARSE_CASE.format(ep=fn, pfn='decltype(%s)' % fn, call='"%s"' % fn)
        for fn in fixture_functions
    ]

    dispatch_cases = [DISPATCH_CASE.format(nargs=n, args=get_dispatch(n)) for n in arg_counts]

    custom_dispatch_cases = [CUSTOM_DISPATCH_CASE.format(fn=fn) for fn in fixture_functions]

    format_args = {
        'script_name': os.path.basename(sys.argv[0]),
        'data_source_name': 'gl.xml and gl_angle_ext.xml',
        'file_name': os.path.basename(BASE_PATH),
        'parse_cases': ''.join(parse_cases),
        'dispatch_cases': '\n'.join(dispatch_cases),
        'custom_dispatch_cases': ''.join(custom_dispatch_cases),
    }

    cpp_content = CPP_TEMPLATE.format(**format_args)
    cpp_output_path = registry_xml.script_relative(cpp_output_path)
    with open(cpp_output_path, 'w') as f:
        f.write(cpp_content)

    return EXIT_SUCCESS


if __name__ == '__main__':
    inputs = registry_xml.xml_inputs + [FIXTURE_H]
    outputs = [
        '%s.cpp' % BASE_PATH,
    ]

    if len(sys.argv) > 1:
        if sys.argv[1] == 'inputs':
            print(','.join(inputs))
        elif sys.argv[1] == 'outputs':
            print(','.join(outputs))
    else:
        sys.exit(main(registry_xml.script_relative(outputs[0])))