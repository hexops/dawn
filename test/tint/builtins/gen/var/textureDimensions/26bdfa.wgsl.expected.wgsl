@group(1) @binding(0) var arg_0 : texture_3d<f32>;

fn textureDimensions_26bdfa() {
  var arg_1 = 1i;
  var res : vec3<i32> = textureDimensions(arg_0, arg_1);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureDimensions_26bdfa();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  textureDimensions_26bdfa();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureDimensions_26bdfa();
}
