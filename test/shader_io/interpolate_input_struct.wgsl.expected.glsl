#version 310 es
precision mediump float;

struct In {
  float none;
  float tint_symbol;
  float perspective_center;
  float perspective_centroid;
  float perspective_sample;
  float linear_center;
  float linear_centroid;
  float linear_sample;
};
struct tint_symbol_4 {
  float none;
  float tint_symbol;
  float perspective_center;
  float perspective_centroid;
  float perspective_sample;
  float linear_center;
  float linear_centroid;
  float linear_sample;
};

void tint_symbol_1_inner(In tint_symbol_2) {
}

void tint_symbol_1(tint_symbol_4 tint_symbol_3) {
  In tint_symbol_5 = In(tint_symbol_3.none, tint_symbol_3.tint_symbol, tint_symbol_3.perspective_center, tint_symbol_3.perspective_centroid, tint_symbol_3.perspective_sample, tint_symbol_3.linear_center, tint_symbol_3.linear_centroid, tint_symbol_3.linear_sample);
  tint_symbol_1_inner(tint_symbol_5);
  return;
}
layout(location = 0) in float none;
layout(location = 1) in float tint_symbol;
layout(location = 2) in float perspective_center;
layout(location = 3) in float perspective_centroid;
layout(location = 4) in float perspective_sample;
layout(location = 5) in float linear_center;
layout(location = 6) in float linear_centroid;
layout(location = 7) in float linear_sample;
void main() {
  tint_symbol_4 inputs;
  inputs.none = none;
  inputs.tint_symbol = tint_symbol;
  inputs.perspective_center = perspective_center;
  inputs.perspective_centroid = perspective_centroid;
  inputs.perspective_sample = perspective_sample;
  inputs.linear_center = linear_center;
  inputs.linear_centroid = linear_centroid;
  inputs.linear_sample = linear_sample;
  tint_symbol_1(inputs);
}


