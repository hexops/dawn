SKIP: FAILED

vk-gl-cts/graphicsfuzz/cov-fract-asin-undefined-never-used/0-opt.wgsl:1:13 warning: use of deprecated language feature: the @stride attribute is deprecated; use a larger type if necessary
type Arr = @stride(16) array<f32, 1>;
            ^^^^^^

vk-gl-cts/graphicsfuzz/cov-fract-asin-undefined-never-used/0-opt.wgsl:7:15 warning: use of deprecated language feature: the @stride attribute is deprecated; use a larger type if necessary
type Arr_1 = @stride(16) array<i32, 2>;
              ^^^^^^

#version 310 es
precision mediump float;

struct tint_padded_array_element {
  float el;
};
struct buf0 {
  tint_padded_array_element x_GLF_uniform_float_values[1];
};
struct tint_padded_array_element_1 {
  int el;
};
struct buf1 {
  tint_padded_array_element_1 x_GLF_uniform_int_values[2];
};

vec4 tint_symbol = vec4(0.0f, 0.0f, 0.0f, 0.0f);
layout (binding = 0) uniform buf0_1 {
  tint_padded_array_element x_GLF_uniform_float_values[1];
} x_8;
vec4 x_GLF_color = vec4(0.0f, 0.0f, 0.0f, 0.0f);
layout (binding = 1) uniform buf1_1 {
  tint_padded_array_element_1 x_GLF_uniform_int_values[2];
} x_10;

void main_1() {
  float f0 = 0.0f;
  float f1 = 0.0f;
  f0 = uintBitsToFloat(0x7f800000u);
  f1 = frac(f0);
  float x_38 = tint_symbol.x;
  float x_40 = x_8.x_GLF_uniform_float_values[0].el;
  if ((x_38 > x_40)) {
    int x_46 = x_10.x_GLF_uniform_int_values[1].el;
    int x_49 = x_10.x_GLF_uniform_int_values[0].el;
    int x_52 = x_10.x_GLF_uniform_int_values[0].el;
    int x_55 = x_10.x_GLF_uniform_int_values[1].el;
    x_GLF_color = vec4(float(x_46), float(x_49), float(x_52), float(x_55));
  } else {
    float x_58 = f1;
    x_GLF_color = vec4(x_58, x_58, x_58, x_58);
  }
  return;
}

struct main_out {
  vec4 x_GLF_color_1;
};
struct tint_symbol_4 {
  vec4 tint_symbol_2;
};
struct tint_symbol_5 {
  vec4 x_GLF_color_1;
};

main_out tint_symbol_1_inner(vec4 tint_symbol_2) {
  tint_symbol = tint_symbol_2;
  main_1();
  main_out tint_symbol_6 = main_out(x_GLF_color);
  return tint_symbol_6;
}

tint_symbol_5 tint_symbol_1(tint_symbol_4 tint_symbol_3) {
  main_out inner_result = tint_symbol_1_inner(tint_symbol_3.tint_symbol_2);
  tint_symbol_5 wrapper_result = tint_symbol_5(vec4(0.0f, 0.0f, 0.0f, 0.0f));
  wrapper_result.x_GLF_color_1 = inner_result.x_GLF_color_1;
  return wrapper_result;
}
layout(location = 0) out vec4 x_GLF_color_1;
void main() {
  tint_symbol_4 inputs;
  inputs.tint_symbol_2 = gl_FragCoord;
  tint_symbol_5 outputs;
  outputs = tint_symbol_1(inputs);
  x_GLF_color_1 = outputs.x_GLF_color_1;
}


Error parsing GLSL shader:
ERROR: 0:30: 'frac' : no matching overloaded function found 
ERROR: 0:30: '' : compilation terminated 
ERROR: 2 compilation errors.  No code generated.



