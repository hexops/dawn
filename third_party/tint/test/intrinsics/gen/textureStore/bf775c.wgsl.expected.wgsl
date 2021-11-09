[[group(1), binding(0)]] var arg_0 : texture_storage_1d<rgba8sint, write>;

fn textureStore_bf775c() {
  textureStore(arg_0, 1, vec4<i32>());
}

[[stage(vertex)]]
fn vertex_main() -> [[builtin(position)]] vec4<f32> {
  textureStore_bf775c();
  return vec4<f32>();
}

[[stage(fragment)]]
fn fragment_main() {
  textureStore_bf775c();
}

[[stage(compute), workgroup_size(1)]]
fn compute_main() {
  textureStore_bf775c();
}
