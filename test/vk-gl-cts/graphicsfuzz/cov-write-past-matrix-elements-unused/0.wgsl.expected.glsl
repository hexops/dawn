SKIP: FAILED

vk-gl-cts/graphicsfuzz/cov-write-past-matrix-elements-unused/0.wgsl:1:13 warning: use of deprecated language feature: the @stride attribute is deprecated; use a larger type if necessary
type Arr = @stride(16) array<f32, 2>;
            ^^^^^^

vk-gl-cts/graphicsfuzz/cov-write-past-matrix-elements-unused/0.wgsl:7:15 warning: use of deprecated language feature: the @stride attribute is deprecated; use a larger type if necessary
type Arr_1 = @stride(16) array<i32, 3>;
              ^^^^^^

#version 310 es
precision mediump float;

struct tint_padded_array_element {
  float el;
};
struct buf1 {
  tint_padded_array_element x_GLF_uniform_float_values[2];
};
struct tint_padded_array_element_1 {
  int el;
};
struct buf0 {
  tint_padded_array_element_1 x_GLF_uniform_int_values[3];
};

layout (binding = 1) uniform buf1_1 {
  tint_padded_array_element x_GLF_uniform_float_values[2];
} x_6;
layout (binding = 0) uniform buf0_1 {
  tint_padded_array_element_1 x_GLF_uniform_int_values[3];
} x_8;
vec4 x_GLF_color = vec4(0.0f, 0.0f, 0.0f, 0.0f);

void main_1() {
  mat3x2 m32 = mat3x2(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  float sums[3] = float[3](0.0f, 0.0f, 0.0f);
  int x_52_phi = 0;
  float x_40 = x_6.x_GLF_uniform_float_values[0].el;
  m32 = mat3x2(vec2(x_40, 0.0f), vec2(0.0f, x_40), vec2(0.0f, 0.0f));
  int x_45 = x_8.x_GLF_uniform_int_values[0].el;
  if ((x_45 == 1)) {
    m32[3][x_45] = x_40;
  }
  float tint_symbol_2[3] = float[3](x_40, x_40, x_40);
  sums = tint_symbol_2;
  x_52_phi = x_45;
  while (true) {
    int x_53 = 0;
    int x_52 = x_52_phi;
    int x_56 = x_8.x_GLF_uniform_int_values[2].el;
    if ((x_52 < x_56)) {
    } else {
      break;
    }
    {
      float x_60 = m32[x_52][x_45];
      int x_61_save = x_56;
      float x_62 = sums[x_61_save];
      sums[x_61_save] = (x_62 + x_60);
      x_53 = (x_52 + 1);
      x_52_phi = x_53;
    }
  }
  float x_65 = sums[x_45];
  float x_67 = x_6.x_GLF_uniform_float_values[1].el;
  int x_69 = x_8.x_GLF_uniform_int_values[1].el;
  float x_71 = sums[x_69];
  x_GLF_color = vec4(x_65, x_67, x_67, x_71);
  return;
}

struct main_out {
  vec4 x_GLF_color_1;
};
struct tint_symbol_1 {
  vec4 x_GLF_color_1;
};

main_out tint_symbol_inner() {
  main_1();
  main_out tint_symbol_3 = main_out(x_GLF_color);
  return tint_symbol_3;
}

tint_symbol_1 tint_symbol() {
  main_out inner_result = tint_symbol_inner();
  tint_symbol_1 wrapper_result = tint_symbol_1(vec4(0.0f, 0.0f, 0.0f, 0.0f));
  wrapper_result.x_GLF_color_1 = inner_result.x_GLF_color_1;
  return wrapper_result;
}
layout(location = 0) out vec4 x_GLF_color_1;
void main() {
  tint_symbol_1 outputs;
  outputs = tint_symbol();
  x_GLF_color_1 = outputs.x_GLF_color_1;
}


Error parsing GLSL shader:
ERROR: 0:33: '[' :  matrix index out of range '3'
ERROR: 0:33: '' : compilation terminated 
ERROR: 2 compilation errors.  No code generated.



