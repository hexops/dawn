#version 310 es
precision mediump float;

struct VertexOutputs {
  int loc0;
  uint loc1;
  float loc2;
  vec4 loc3;
  vec4 position;
};
struct tint_symbol_1 {
  int loc0;
  uint loc1;
  float loc2;
  vec4 loc3;
  vec4 position;
};

VertexOutputs tint_symbol_inner() {
  VertexOutputs tint_symbol_2 = VertexOutputs(1, 1u, 1.0f, vec4(1.0f, 2.0f, 3.0f, 4.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f));
  return tint_symbol_2;
}

tint_symbol_1 tint_symbol() {
  VertexOutputs inner_result = tint_symbol_inner();
  tint_symbol_1 wrapper_result = tint_symbol_1(0, 0u, 0.0f, vec4(0.0f, 0.0f, 0.0f, 0.0f), vec4(0.0f, 0.0f, 0.0f, 0.0f));
  wrapper_result.loc0 = inner_result.loc0;
  wrapper_result.loc1 = inner_result.loc1;
  wrapper_result.loc2 = inner_result.loc2;
  wrapper_result.loc3 = inner_result.loc3;
  wrapper_result.position = inner_result.position;
  return wrapper_result;
}
layout(location = 0) out int loc0;
layout(location = 1) out uint loc1;
layout(location = 2) out float loc2;
layout(location = 3) out vec4 loc3;
void main() {
  tint_symbol_1 outputs;
  outputs = tint_symbol();
  loc0 = outputs.loc0;
  loc1 = outputs.loc1;
  loc2 = outputs.loc2;
  loc3 = outputs.loc3;
  gl_Position = outputs.position;
  gl_Position.y = -gl_Position.y;
}


