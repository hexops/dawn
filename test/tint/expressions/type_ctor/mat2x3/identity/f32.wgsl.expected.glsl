#version 310 es

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void unused_entry_point() {
  return;
}
const mat2x3 m = mat2x3(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
