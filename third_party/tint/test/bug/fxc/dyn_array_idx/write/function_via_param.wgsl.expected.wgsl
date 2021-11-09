[[block]]
struct UBO {
  dynamic_idx : i32;
};

[[group(0), binding(0)]] var<uniform> ubo : UBO;

struct S {
  data : array<i32, 64>;
};

[[block]]
struct Result {
  out : i32;
};

[[group(0), binding(1)]] var<storage, read_write> result : Result;

fn x(p : ptr<function, S>) {
  (*(p)).data[ubo.dynamic_idx] = 1;
}

[[stage(compute), workgroup_size(1)]]
fn f() {
  var s : S;
  x(&(s));
  result.out = s.data[3];
}
