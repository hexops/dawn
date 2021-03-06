RWByteAddressBuffer sb_rw : register(u0, space0);

uint tint_atomicXor(RWByteAddressBuffer buffer, uint offset, uint value) {
  uint original_value = 0;
  buffer.InterlockedXor(offset, value, original_value);
  return original_value;
}


void atomicXor_54510e() {
  uint res = 0u;
  const uint x_9 = tint_atomicXor(sb_rw, 0u, 1u);
  res = x_9;
  return;
}

void fragment_main_1() {
  atomicXor_54510e();
  return;
}

void fragment_main() {
  fragment_main_1();
  return;
}

void compute_main_1() {
  atomicXor_54510e();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  compute_main_1();
  return;
}
