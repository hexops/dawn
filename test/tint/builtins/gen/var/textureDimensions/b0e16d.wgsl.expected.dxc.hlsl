Texture2D<int4> arg_0 : register(t0, space1);

void textureDimensions_b0e16d() {
  int arg_1 = 1;
  int3 tint_tmp;
  arg_0.GetDimensions(arg_1, tint_tmp.x, tint_tmp.y, tint_tmp.z);
  int2 res = tint_tmp.xy;
}

struct tint_symbol {
  float4 value : SV_Position;
};

float4 vertex_main_inner() {
  textureDimensions_b0e16d();
  return (0.0f).xxxx;
}

tint_symbol vertex_main() {
  const float4 inner_result = vertex_main_inner();
  tint_symbol wrapper_result = (tint_symbol)0;
  wrapper_result.value = inner_result;
  return wrapper_result;
}

void fragment_main() {
  textureDimensions_b0e16d();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  textureDimensions_b0e16d();
  return;
}
