[numthreads(1, 1, 1)]
void unused_entry_point() {
  return;
}

cbuffer cbuffer_U : register(b0) {
  uint4 U[1];
};

void f() {
  uint2 ubo_load = U[0].xy;
  vector<float16_t, 2> ubo_load_xz = vector<float16_t, 2>(f16tof32(ubo_load & 0xFFFF));
  float16_t ubo_load_y = f16tof32(ubo_load[0] >> 16);
  vector<float16_t, 3> v = vector<float16_t, 3>(ubo_load_xz[0], ubo_load_y, ubo_load_xz[1]);
  float16_t x = float16_t(f16tof32(((U[0].x) & 0xFFFF)));
  float16_t y = float16_t(f16tof32(((U[0].x >> 16) & 0xFFFF)));
  float16_t z = float16_t(f16tof32(((U[0].y) & 0xFFFF)));
  uint2 ubo_load_1 = U[0].xy;
  vector<float16_t, 2> ubo_load_1_xz = vector<float16_t, 2>(f16tof32(ubo_load_1 & 0xFFFF));
  float16_t ubo_load_1_y = f16tof32(ubo_load_1[0] >> 16);
  vector<float16_t, 2> xx = vector<float16_t, 3>(ubo_load_1_xz[0], ubo_load_1_y, ubo_load_1_xz[1]).xx;
  uint2 ubo_load_2 = U[0].xy;
  vector<float16_t, 2> ubo_load_2_xz = vector<float16_t, 2>(f16tof32(ubo_load_2 & 0xFFFF));
  float16_t ubo_load_2_y = f16tof32(ubo_load_2[0] >> 16);
  vector<float16_t, 2> xy = vector<float16_t, 3>(ubo_load_2_xz[0], ubo_load_2_y, ubo_load_2_xz[1]).xy;
  uint2 ubo_load_3 = U[0].xy;
  vector<float16_t, 2> ubo_load_3_xz = vector<float16_t, 2>(f16tof32(ubo_load_3 & 0xFFFF));
  float16_t ubo_load_3_y = f16tof32(ubo_load_3[0] >> 16);
  vector<float16_t, 2> xz = vector<float16_t, 3>(ubo_load_3_xz[0], ubo_load_3_y, ubo_load_3_xz[1]).xz;
  uint2 ubo_load_4 = U[0].xy;
  vector<float16_t, 2> ubo_load_4_xz = vector<float16_t, 2>(f16tof32(ubo_load_4 & 0xFFFF));
  float16_t ubo_load_4_y = f16tof32(ubo_load_4[0] >> 16);
  vector<float16_t, 2> yx = vector<float16_t, 3>(ubo_load_4_xz[0], ubo_load_4_y, ubo_load_4_xz[1]).yx;
  uint2 ubo_load_5 = U[0].xy;
  vector<float16_t, 2> ubo_load_5_xz = vector<float16_t, 2>(f16tof32(ubo_load_5 & 0xFFFF));
  float16_t ubo_load_5_y = f16tof32(ubo_load_5[0] >> 16);
  vector<float16_t, 2> yy = vector<float16_t, 3>(ubo_load_5_xz[0], ubo_load_5_y, ubo_load_5_xz[1]).yy;
  uint2 ubo_load_6 = U[0].xy;
  vector<float16_t, 2> ubo_load_6_xz = vector<float16_t, 2>(f16tof32(ubo_load_6 & 0xFFFF));
  float16_t ubo_load_6_y = f16tof32(ubo_load_6[0] >> 16);
  vector<float16_t, 2> yz = vector<float16_t, 3>(ubo_load_6_xz[0], ubo_load_6_y, ubo_load_6_xz[1]).yz;
  uint2 ubo_load_7 = U[0].xy;
  vector<float16_t, 2> ubo_load_7_xz = vector<float16_t, 2>(f16tof32(ubo_load_7 & 0xFFFF));
  float16_t ubo_load_7_y = f16tof32(ubo_load_7[0] >> 16);
  vector<float16_t, 2> zx = vector<float16_t, 3>(ubo_load_7_xz[0], ubo_load_7_y, ubo_load_7_xz[1]).zx;
  uint2 ubo_load_8 = U[0].xy;
  vector<float16_t, 2> ubo_load_8_xz = vector<float16_t, 2>(f16tof32(ubo_load_8 & 0xFFFF));
  float16_t ubo_load_8_y = f16tof32(ubo_load_8[0] >> 16);
  vector<float16_t, 2> zy = vector<float16_t, 3>(ubo_load_8_xz[0], ubo_load_8_y, ubo_load_8_xz[1]).zy;
  uint2 ubo_load_9 = U[0].xy;
  vector<float16_t, 2> ubo_load_9_xz = vector<float16_t, 2>(f16tof32(ubo_load_9 & 0xFFFF));
  float16_t ubo_load_9_y = f16tof32(ubo_load_9[0] >> 16);
  vector<float16_t, 2> zz = vector<float16_t, 3>(ubo_load_9_xz[0], ubo_load_9_y, ubo_load_9_xz[1]).zz;
  uint2 ubo_load_10 = U[0].xy;
  vector<float16_t, 2> ubo_load_10_xz = vector<float16_t, 2>(f16tof32(ubo_load_10 & 0xFFFF));
  float16_t ubo_load_10_y = f16tof32(ubo_load_10[0] >> 16);
  vector<float16_t, 3> xxx = vector<float16_t, 3>(ubo_load_10_xz[0], ubo_load_10_y, ubo_load_10_xz[1]).xxx;
  uint2 ubo_load_11 = U[0].xy;
  vector<float16_t, 2> ubo_load_11_xz = vector<float16_t, 2>(f16tof32(ubo_load_11 & 0xFFFF));
  float16_t ubo_load_11_y = f16tof32(ubo_load_11[0] >> 16);
  vector<float16_t, 3> xxy = vector<float16_t, 3>(ubo_load_11_xz[0], ubo_load_11_y, ubo_load_11_xz[1]).xxy;
  uint2 ubo_load_12 = U[0].xy;
  vector<float16_t, 2> ubo_load_12_xz = vector<float16_t, 2>(f16tof32(ubo_load_12 & 0xFFFF));
  float16_t ubo_load_12_y = f16tof32(ubo_load_12[0] >> 16);
  vector<float16_t, 3> xxz = vector<float16_t, 3>(ubo_load_12_xz[0], ubo_load_12_y, ubo_load_12_xz[1]).xxz;
  uint2 ubo_load_13 = U[0].xy;
  vector<float16_t, 2> ubo_load_13_xz = vector<float16_t, 2>(f16tof32(ubo_load_13 & 0xFFFF));
  float16_t ubo_load_13_y = f16tof32(ubo_load_13[0] >> 16);
  vector<float16_t, 3> xyx = vector<float16_t, 3>(ubo_load_13_xz[0], ubo_load_13_y, ubo_load_13_xz[1]).xyx;
  uint2 ubo_load_14 = U[0].xy;
  vector<float16_t, 2> ubo_load_14_xz = vector<float16_t, 2>(f16tof32(ubo_load_14 & 0xFFFF));
  float16_t ubo_load_14_y = f16tof32(ubo_load_14[0] >> 16);
  vector<float16_t, 3> xyy = vector<float16_t, 3>(ubo_load_14_xz[0], ubo_load_14_y, ubo_load_14_xz[1]).xyy;
  uint2 ubo_load_15 = U[0].xy;
  vector<float16_t, 2> ubo_load_15_xz = vector<float16_t, 2>(f16tof32(ubo_load_15 & 0xFFFF));
  float16_t ubo_load_15_y = f16tof32(ubo_load_15[0] >> 16);
  vector<float16_t, 3> xyz = vector<float16_t, 3>(ubo_load_15_xz[0], ubo_load_15_y, ubo_load_15_xz[1]).xyz;
  uint2 ubo_load_16 = U[0].xy;
  vector<float16_t, 2> ubo_load_16_xz = vector<float16_t, 2>(f16tof32(ubo_load_16 & 0xFFFF));
  float16_t ubo_load_16_y = f16tof32(ubo_load_16[0] >> 16);
  vector<float16_t, 3> xzx = vector<float16_t, 3>(ubo_load_16_xz[0], ubo_load_16_y, ubo_load_16_xz[1]).xzx;
  uint2 ubo_load_17 = U[0].xy;
  vector<float16_t, 2> ubo_load_17_xz = vector<float16_t, 2>(f16tof32(ubo_load_17 & 0xFFFF));
  float16_t ubo_load_17_y = f16tof32(ubo_load_17[0] >> 16);
  vector<float16_t, 3> xzy = vector<float16_t, 3>(ubo_load_17_xz[0], ubo_load_17_y, ubo_load_17_xz[1]).xzy;
  uint2 ubo_load_18 = U[0].xy;
  vector<float16_t, 2> ubo_load_18_xz = vector<float16_t, 2>(f16tof32(ubo_load_18 & 0xFFFF));
  float16_t ubo_load_18_y = f16tof32(ubo_load_18[0] >> 16);
  vector<float16_t, 3> xzz = vector<float16_t, 3>(ubo_load_18_xz[0], ubo_load_18_y, ubo_load_18_xz[1]).xzz;
  uint2 ubo_load_19 = U[0].xy;
  vector<float16_t, 2> ubo_load_19_xz = vector<float16_t, 2>(f16tof32(ubo_load_19 & 0xFFFF));
  float16_t ubo_load_19_y = f16tof32(ubo_load_19[0] >> 16);
  vector<float16_t, 3> yxx = vector<float16_t, 3>(ubo_load_19_xz[0], ubo_load_19_y, ubo_load_19_xz[1]).yxx;
  uint2 ubo_load_20 = U[0].xy;
  vector<float16_t, 2> ubo_load_20_xz = vector<float16_t, 2>(f16tof32(ubo_load_20 & 0xFFFF));
  float16_t ubo_load_20_y = f16tof32(ubo_load_20[0] >> 16);
  vector<float16_t, 3> yxy = vector<float16_t, 3>(ubo_load_20_xz[0], ubo_load_20_y, ubo_load_20_xz[1]).yxy;
  uint2 ubo_load_21 = U[0].xy;
  vector<float16_t, 2> ubo_load_21_xz = vector<float16_t, 2>(f16tof32(ubo_load_21 & 0xFFFF));
  float16_t ubo_load_21_y = f16tof32(ubo_load_21[0] >> 16);
  vector<float16_t, 3> yxz = vector<float16_t, 3>(ubo_load_21_xz[0], ubo_load_21_y, ubo_load_21_xz[1]).yxz;
  uint2 ubo_load_22 = U[0].xy;
  vector<float16_t, 2> ubo_load_22_xz = vector<float16_t, 2>(f16tof32(ubo_load_22 & 0xFFFF));
  float16_t ubo_load_22_y = f16tof32(ubo_load_22[0] >> 16);
  vector<float16_t, 3> yyx = vector<float16_t, 3>(ubo_load_22_xz[0], ubo_load_22_y, ubo_load_22_xz[1]).yyx;
  uint2 ubo_load_23 = U[0].xy;
  vector<float16_t, 2> ubo_load_23_xz = vector<float16_t, 2>(f16tof32(ubo_load_23 & 0xFFFF));
  float16_t ubo_load_23_y = f16tof32(ubo_load_23[0] >> 16);
  vector<float16_t, 3> yyy = vector<float16_t, 3>(ubo_load_23_xz[0], ubo_load_23_y, ubo_load_23_xz[1]).yyy;
  uint2 ubo_load_24 = U[0].xy;
  vector<float16_t, 2> ubo_load_24_xz = vector<float16_t, 2>(f16tof32(ubo_load_24 & 0xFFFF));
  float16_t ubo_load_24_y = f16tof32(ubo_load_24[0] >> 16);
  vector<float16_t, 3> yyz = vector<float16_t, 3>(ubo_load_24_xz[0], ubo_load_24_y, ubo_load_24_xz[1]).yyz;
  uint2 ubo_load_25 = U[0].xy;
  vector<float16_t, 2> ubo_load_25_xz = vector<float16_t, 2>(f16tof32(ubo_load_25 & 0xFFFF));
  float16_t ubo_load_25_y = f16tof32(ubo_load_25[0] >> 16);
  vector<float16_t, 3> yzx = vector<float16_t, 3>(ubo_load_25_xz[0], ubo_load_25_y, ubo_load_25_xz[1]).yzx;
  uint2 ubo_load_26 = U[0].xy;
  vector<float16_t, 2> ubo_load_26_xz = vector<float16_t, 2>(f16tof32(ubo_load_26 & 0xFFFF));
  float16_t ubo_load_26_y = f16tof32(ubo_load_26[0] >> 16);
  vector<float16_t, 3> yzy = vector<float16_t, 3>(ubo_load_26_xz[0], ubo_load_26_y, ubo_load_26_xz[1]).yzy;
  uint2 ubo_load_27 = U[0].xy;
  vector<float16_t, 2> ubo_load_27_xz = vector<float16_t, 2>(f16tof32(ubo_load_27 & 0xFFFF));
  float16_t ubo_load_27_y = f16tof32(ubo_load_27[0] >> 16);
  vector<float16_t, 3> yzz = vector<float16_t, 3>(ubo_load_27_xz[0], ubo_load_27_y, ubo_load_27_xz[1]).yzz;
  uint2 ubo_load_28 = U[0].xy;
  vector<float16_t, 2> ubo_load_28_xz = vector<float16_t, 2>(f16tof32(ubo_load_28 & 0xFFFF));
  float16_t ubo_load_28_y = f16tof32(ubo_load_28[0] >> 16);
  vector<float16_t, 3> zxx = vector<float16_t, 3>(ubo_load_28_xz[0], ubo_load_28_y, ubo_load_28_xz[1]).zxx;
  uint2 ubo_load_29 = U[0].xy;
  vector<float16_t, 2> ubo_load_29_xz = vector<float16_t, 2>(f16tof32(ubo_load_29 & 0xFFFF));
  float16_t ubo_load_29_y = f16tof32(ubo_load_29[0] >> 16);
  vector<float16_t, 3> zxy = vector<float16_t, 3>(ubo_load_29_xz[0], ubo_load_29_y, ubo_load_29_xz[1]).zxy;
  uint2 ubo_load_30 = U[0].xy;
  vector<float16_t, 2> ubo_load_30_xz = vector<float16_t, 2>(f16tof32(ubo_load_30 & 0xFFFF));
  float16_t ubo_load_30_y = f16tof32(ubo_load_30[0] >> 16);
  vector<float16_t, 3> zxz = vector<float16_t, 3>(ubo_load_30_xz[0], ubo_load_30_y, ubo_load_30_xz[1]).zxz;
  uint2 ubo_load_31 = U[0].xy;
  vector<float16_t, 2> ubo_load_31_xz = vector<float16_t, 2>(f16tof32(ubo_load_31 & 0xFFFF));
  float16_t ubo_load_31_y = f16tof32(ubo_load_31[0] >> 16);
  vector<float16_t, 3> zyx = vector<float16_t, 3>(ubo_load_31_xz[0], ubo_load_31_y, ubo_load_31_xz[1]).zyx;
  uint2 ubo_load_32 = U[0].xy;
  vector<float16_t, 2> ubo_load_32_xz = vector<float16_t, 2>(f16tof32(ubo_load_32 & 0xFFFF));
  float16_t ubo_load_32_y = f16tof32(ubo_load_32[0] >> 16);
  vector<float16_t, 3> zyy = vector<float16_t, 3>(ubo_load_32_xz[0], ubo_load_32_y, ubo_load_32_xz[1]).zyy;
  uint2 ubo_load_33 = U[0].xy;
  vector<float16_t, 2> ubo_load_33_xz = vector<float16_t, 2>(f16tof32(ubo_load_33 & 0xFFFF));
  float16_t ubo_load_33_y = f16tof32(ubo_load_33[0] >> 16);
  vector<float16_t, 3> zyz = vector<float16_t, 3>(ubo_load_33_xz[0], ubo_load_33_y, ubo_load_33_xz[1]).zyz;
  uint2 ubo_load_34 = U[0].xy;
  vector<float16_t, 2> ubo_load_34_xz = vector<float16_t, 2>(f16tof32(ubo_load_34 & 0xFFFF));
  float16_t ubo_load_34_y = f16tof32(ubo_load_34[0] >> 16);
  vector<float16_t, 3> zzx = vector<float16_t, 3>(ubo_load_34_xz[0], ubo_load_34_y, ubo_load_34_xz[1]).zzx;
  uint2 ubo_load_35 = U[0].xy;
  vector<float16_t, 2> ubo_load_35_xz = vector<float16_t, 2>(f16tof32(ubo_load_35 & 0xFFFF));
  float16_t ubo_load_35_y = f16tof32(ubo_load_35[0] >> 16);
  vector<float16_t, 3> zzy = vector<float16_t, 3>(ubo_load_35_xz[0], ubo_load_35_y, ubo_load_35_xz[1]).zzy;
  uint2 ubo_load_36 = U[0].xy;
  vector<float16_t, 2> ubo_load_36_xz = vector<float16_t, 2>(f16tof32(ubo_load_36 & 0xFFFF));
  float16_t ubo_load_36_y = f16tof32(ubo_load_36[0] >> 16);
  vector<float16_t, 3> zzz = vector<float16_t, 3>(ubo_load_36_xz[0], ubo_load_36_y, ubo_load_36_xz[1]).zzz;
  uint2 ubo_load_37 = U[0].xy;
  vector<float16_t, 2> ubo_load_37_xz = vector<float16_t, 2>(f16tof32(ubo_load_37 & 0xFFFF));
  float16_t ubo_load_37_y = f16tof32(ubo_load_37[0] >> 16);
  vector<float16_t, 4> xxxx = vector<float16_t, 3>(ubo_load_37_xz[0], ubo_load_37_y, ubo_load_37_xz[1]).xxxx;
  uint2 ubo_load_38 = U[0].xy;
  vector<float16_t, 2> ubo_load_38_xz = vector<float16_t, 2>(f16tof32(ubo_load_38 & 0xFFFF));
  float16_t ubo_load_38_y = f16tof32(ubo_load_38[0] >> 16);
  vector<float16_t, 4> xxxy = vector<float16_t, 3>(ubo_load_38_xz[0], ubo_load_38_y, ubo_load_38_xz[1]).xxxy;
  uint2 ubo_load_39 = U[0].xy;
  vector<float16_t, 2> ubo_load_39_xz = vector<float16_t, 2>(f16tof32(ubo_load_39 & 0xFFFF));
  float16_t ubo_load_39_y = f16tof32(ubo_load_39[0] >> 16);
  vector<float16_t, 4> xxxz = vector<float16_t, 3>(ubo_load_39_xz[0], ubo_load_39_y, ubo_load_39_xz[1]).xxxz;
  uint2 ubo_load_40 = U[0].xy;
  vector<float16_t, 2> ubo_load_40_xz = vector<float16_t, 2>(f16tof32(ubo_load_40 & 0xFFFF));
  float16_t ubo_load_40_y = f16tof32(ubo_load_40[0] >> 16);
  vector<float16_t, 4> xxyx = vector<float16_t, 3>(ubo_load_40_xz[0], ubo_load_40_y, ubo_load_40_xz[1]).xxyx;
  uint2 ubo_load_41 = U[0].xy;
  vector<float16_t, 2> ubo_load_41_xz = vector<float16_t, 2>(f16tof32(ubo_load_41 & 0xFFFF));
  float16_t ubo_load_41_y = f16tof32(ubo_load_41[0] >> 16);
  vector<float16_t, 4> xxyy = vector<float16_t, 3>(ubo_load_41_xz[0], ubo_load_41_y, ubo_load_41_xz[1]).xxyy;
  uint2 ubo_load_42 = U[0].xy;
  vector<float16_t, 2> ubo_load_42_xz = vector<float16_t, 2>(f16tof32(ubo_load_42 & 0xFFFF));
  float16_t ubo_load_42_y = f16tof32(ubo_load_42[0] >> 16);
  vector<float16_t, 4> xxyz = vector<float16_t, 3>(ubo_load_42_xz[0], ubo_load_42_y, ubo_load_42_xz[1]).xxyz;
  uint2 ubo_load_43 = U[0].xy;
  vector<float16_t, 2> ubo_load_43_xz = vector<float16_t, 2>(f16tof32(ubo_load_43 & 0xFFFF));
  float16_t ubo_load_43_y = f16tof32(ubo_load_43[0] >> 16);
  vector<float16_t, 4> xxzx = vector<float16_t, 3>(ubo_load_43_xz[0], ubo_load_43_y, ubo_load_43_xz[1]).xxzx;
  uint2 ubo_load_44 = U[0].xy;
  vector<float16_t, 2> ubo_load_44_xz = vector<float16_t, 2>(f16tof32(ubo_load_44 & 0xFFFF));
  float16_t ubo_load_44_y = f16tof32(ubo_load_44[0] >> 16);
  vector<float16_t, 4> xxzy = vector<float16_t, 3>(ubo_load_44_xz[0], ubo_load_44_y, ubo_load_44_xz[1]).xxzy;
  uint2 ubo_load_45 = U[0].xy;
  vector<float16_t, 2> ubo_load_45_xz = vector<float16_t, 2>(f16tof32(ubo_load_45 & 0xFFFF));
  float16_t ubo_load_45_y = f16tof32(ubo_load_45[0] >> 16);
  vector<float16_t, 4> xxzz = vector<float16_t, 3>(ubo_load_45_xz[0], ubo_load_45_y, ubo_load_45_xz[1]).xxzz;
  uint2 ubo_load_46 = U[0].xy;
  vector<float16_t, 2> ubo_load_46_xz = vector<float16_t, 2>(f16tof32(ubo_load_46 & 0xFFFF));
  float16_t ubo_load_46_y = f16tof32(ubo_load_46[0] >> 16);
  vector<float16_t, 4> xyxx = vector<float16_t, 3>(ubo_load_46_xz[0], ubo_load_46_y, ubo_load_46_xz[1]).xyxx;
  uint2 ubo_load_47 = U[0].xy;
  vector<float16_t, 2> ubo_load_47_xz = vector<float16_t, 2>(f16tof32(ubo_load_47 & 0xFFFF));
  float16_t ubo_load_47_y = f16tof32(ubo_load_47[0] >> 16);
  vector<float16_t, 4> xyxy = vector<float16_t, 3>(ubo_load_47_xz[0], ubo_load_47_y, ubo_load_47_xz[1]).xyxy;
  uint2 ubo_load_48 = U[0].xy;
  vector<float16_t, 2> ubo_load_48_xz = vector<float16_t, 2>(f16tof32(ubo_load_48 & 0xFFFF));
  float16_t ubo_load_48_y = f16tof32(ubo_load_48[0] >> 16);
  vector<float16_t, 4> xyxz = vector<float16_t, 3>(ubo_load_48_xz[0], ubo_load_48_y, ubo_load_48_xz[1]).xyxz;
  uint2 ubo_load_49 = U[0].xy;
  vector<float16_t, 2> ubo_load_49_xz = vector<float16_t, 2>(f16tof32(ubo_load_49 & 0xFFFF));
  float16_t ubo_load_49_y = f16tof32(ubo_load_49[0] >> 16);
  vector<float16_t, 4> xyyx = vector<float16_t, 3>(ubo_load_49_xz[0], ubo_load_49_y, ubo_load_49_xz[1]).xyyx;
  uint2 ubo_load_50 = U[0].xy;
  vector<float16_t, 2> ubo_load_50_xz = vector<float16_t, 2>(f16tof32(ubo_load_50 & 0xFFFF));
  float16_t ubo_load_50_y = f16tof32(ubo_load_50[0] >> 16);
  vector<float16_t, 4> xyyy = vector<float16_t, 3>(ubo_load_50_xz[0], ubo_load_50_y, ubo_load_50_xz[1]).xyyy;
  uint2 ubo_load_51 = U[0].xy;
  vector<float16_t, 2> ubo_load_51_xz = vector<float16_t, 2>(f16tof32(ubo_load_51 & 0xFFFF));
  float16_t ubo_load_51_y = f16tof32(ubo_load_51[0] >> 16);
  vector<float16_t, 4> xyyz = vector<float16_t, 3>(ubo_load_51_xz[0], ubo_load_51_y, ubo_load_51_xz[1]).xyyz;
  uint2 ubo_load_52 = U[0].xy;
  vector<float16_t, 2> ubo_load_52_xz = vector<float16_t, 2>(f16tof32(ubo_load_52 & 0xFFFF));
  float16_t ubo_load_52_y = f16tof32(ubo_load_52[0] >> 16);
  vector<float16_t, 4> xyzx = vector<float16_t, 3>(ubo_load_52_xz[0], ubo_load_52_y, ubo_load_52_xz[1]).xyzx;
  uint2 ubo_load_53 = U[0].xy;
  vector<float16_t, 2> ubo_load_53_xz = vector<float16_t, 2>(f16tof32(ubo_load_53 & 0xFFFF));
  float16_t ubo_load_53_y = f16tof32(ubo_load_53[0] >> 16);
  vector<float16_t, 4> xyzy = vector<float16_t, 3>(ubo_load_53_xz[0], ubo_load_53_y, ubo_load_53_xz[1]).xyzy;
  uint2 ubo_load_54 = U[0].xy;
  vector<float16_t, 2> ubo_load_54_xz = vector<float16_t, 2>(f16tof32(ubo_load_54 & 0xFFFF));
  float16_t ubo_load_54_y = f16tof32(ubo_load_54[0] >> 16);
  vector<float16_t, 4> xyzz = vector<float16_t, 3>(ubo_load_54_xz[0], ubo_load_54_y, ubo_load_54_xz[1]).xyzz;
  uint2 ubo_load_55 = U[0].xy;
  vector<float16_t, 2> ubo_load_55_xz = vector<float16_t, 2>(f16tof32(ubo_load_55 & 0xFFFF));
  float16_t ubo_load_55_y = f16tof32(ubo_load_55[0] >> 16);
  vector<float16_t, 4> xzxx = vector<float16_t, 3>(ubo_load_55_xz[0], ubo_load_55_y, ubo_load_55_xz[1]).xzxx;
  uint2 ubo_load_56 = U[0].xy;
  vector<float16_t, 2> ubo_load_56_xz = vector<float16_t, 2>(f16tof32(ubo_load_56 & 0xFFFF));
  float16_t ubo_load_56_y = f16tof32(ubo_load_56[0] >> 16);
  vector<float16_t, 4> xzxy = vector<float16_t, 3>(ubo_load_56_xz[0], ubo_load_56_y, ubo_load_56_xz[1]).xzxy;
  uint2 ubo_load_57 = U[0].xy;
  vector<float16_t, 2> ubo_load_57_xz = vector<float16_t, 2>(f16tof32(ubo_load_57 & 0xFFFF));
  float16_t ubo_load_57_y = f16tof32(ubo_load_57[0] >> 16);
  vector<float16_t, 4> xzxz = vector<float16_t, 3>(ubo_load_57_xz[0], ubo_load_57_y, ubo_load_57_xz[1]).xzxz;
  uint2 ubo_load_58 = U[0].xy;
  vector<float16_t, 2> ubo_load_58_xz = vector<float16_t, 2>(f16tof32(ubo_load_58 & 0xFFFF));
  float16_t ubo_load_58_y = f16tof32(ubo_load_58[0] >> 16);
  vector<float16_t, 4> xzyx = vector<float16_t, 3>(ubo_load_58_xz[0], ubo_load_58_y, ubo_load_58_xz[1]).xzyx;
  uint2 ubo_load_59 = U[0].xy;
  vector<float16_t, 2> ubo_load_59_xz = vector<float16_t, 2>(f16tof32(ubo_load_59 & 0xFFFF));
  float16_t ubo_load_59_y = f16tof32(ubo_load_59[0] >> 16);
  vector<float16_t, 4> xzyy = vector<float16_t, 3>(ubo_load_59_xz[0], ubo_load_59_y, ubo_load_59_xz[1]).xzyy;
  uint2 ubo_load_60 = U[0].xy;
  vector<float16_t, 2> ubo_load_60_xz = vector<float16_t, 2>(f16tof32(ubo_load_60 & 0xFFFF));
  float16_t ubo_load_60_y = f16tof32(ubo_load_60[0] >> 16);
  vector<float16_t, 4> xzyz = vector<float16_t, 3>(ubo_load_60_xz[0], ubo_load_60_y, ubo_load_60_xz[1]).xzyz;
  uint2 ubo_load_61 = U[0].xy;
  vector<float16_t, 2> ubo_load_61_xz = vector<float16_t, 2>(f16tof32(ubo_load_61 & 0xFFFF));
  float16_t ubo_load_61_y = f16tof32(ubo_load_61[0] >> 16);
  vector<float16_t, 4> xzzx = vector<float16_t, 3>(ubo_load_61_xz[0], ubo_load_61_y, ubo_load_61_xz[1]).xzzx;
  uint2 ubo_load_62 = U[0].xy;
  vector<float16_t, 2> ubo_load_62_xz = vector<float16_t, 2>(f16tof32(ubo_load_62 & 0xFFFF));
  float16_t ubo_load_62_y = f16tof32(ubo_load_62[0] >> 16);
  vector<float16_t, 4> xzzy = vector<float16_t, 3>(ubo_load_62_xz[0], ubo_load_62_y, ubo_load_62_xz[1]).xzzy;
  uint2 ubo_load_63 = U[0].xy;
  vector<float16_t, 2> ubo_load_63_xz = vector<float16_t, 2>(f16tof32(ubo_load_63 & 0xFFFF));
  float16_t ubo_load_63_y = f16tof32(ubo_load_63[0] >> 16);
  vector<float16_t, 4> xzzz = vector<float16_t, 3>(ubo_load_63_xz[0], ubo_load_63_y, ubo_load_63_xz[1]).xzzz;
  uint2 ubo_load_64 = U[0].xy;
  vector<float16_t, 2> ubo_load_64_xz = vector<float16_t, 2>(f16tof32(ubo_load_64 & 0xFFFF));
  float16_t ubo_load_64_y = f16tof32(ubo_load_64[0] >> 16);
  vector<float16_t, 4> yxxx = vector<float16_t, 3>(ubo_load_64_xz[0], ubo_load_64_y, ubo_load_64_xz[1]).yxxx;
  uint2 ubo_load_65 = U[0].xy;
  vector<float16_t, 2> ubo_load_65_xz = vector<float16_t, 2>(f16tof32(ubo_load_65 & 0xFFFF));
  float16_t ubo_load_65_y = f16tof32(ubo_load_65[0] >> 16);
  vector<float16_t, 4> yxxy = vector<float16_t, 3>(ubo_load_65_xz[0], ubo_load_65_y, ubo_load_65_xz[1]).yxxy;
  uint2 ubo_load_66 = U[0].xy;
  vector<float16_t, 2> ubo_load_66_xz = vector<float16_t, 2>(f16tof32(ubo_load_66 & 0xFFFF));
  float16_t ubo_load_66_y = f16tof32(ubo_load_66[0] >> 16);
  vector<float16_t, 4> yxxz = vector<float16_t, 3>(ubo_load_66_xz[0], ubo_load_66_y, ubo_load_66_xz[1]).yxxz;
  uint2 ubo_load_67 = U[0].xy;
  vector<float16_t, 2> ubo_load_67_xz = vector<float16_t, 2>(f16tof32(ubo_load_67 & 0xFFFF));
  float16_t ubo_load_67_y = f16tof32(ubo_load_67[0] >> 16);
  vector<float16_t, 4> yxyx = vector<float16_t, 3>(ubo_load_67_xz[0], ubo_load_67_y, ubo_load_67_xz[1]).yxyx;
  uint2 ubo_load_68 = U[0].xy;
  vector<float16_t, 2> ubo_load_68_xz = vector<float16_t, 2>(f16tof32(ubo_load_68 & 0xFFFF));
  float16_t ubo_load_68_y = f16tof32(ubo_load_68[0] >> 16);
  vector<float16_t, 4> yxyy = vector<float16_t, 3>(ubo_load_68_xz[0], ubo_load_68_y, ubo_load_68_xz[1]).yxyy;
  uint2 ubo_load_69 = U[0].xy;
  vector<float16_t, 2> ubo_load_69_xz = vector<float16_t, 2>(f16tof32(ubo_load_69 & 0xFFFF));
  float16_t ubo_load_69_y = f16tof32(ubo_load_69[0] >> 16);
  vector<float16_t, 4> yxyz = vector<float16_t, 3>(ubo_load_69_xz[0], ubo_load_69_y, ubo_load_69_xz[1]).yxyz;
  uint2 ubo_load_70 = U[0].xy;
  vector<float16_t, 2> ubo_load_70_xz = vector<float16_t, 2>(f16tof32(ubo_load_70 & 0xFFFF));
  float16_t ubo_load_70_y = f16tof32(ubo_load_70[0] >> 16);
  vector<float16_t, 4> yxzx = vector<float16_t, 3>(ubo_load_70_xz[0], ubo_load_70_y, ubo_load_70_xz[1]).yxzx;
  uint2 ubo_load_71 = U[0].xy;
  vector<float16_t, 2> ubo_load_71_xz = vector<float16_t, 2>(f16tof32(ubo_load_71 & 0xFFFF));
  float16_t ubo_load_71_y = f16tof32(ubo_load_71[0] >> 16);
  vector<float16_t, 4> yxzy = vector<float16_t, 3>(ubo_load_71_xz[0], ubo_load_71_y, ubo_load_71_xz[1]).yxzy;
  uint2 ubo_load_72 = U[0].xy;
  vector<float16_t, 2> ubo_load_72_xz = vector<float16_t, 2>(f16tof32(ubo_load_72 & 0xFFFF));
  float16_t ubo_load_72_y = f16tof32(ubo_load_72[0] >> 16);
  vector<float16_t, 4> yxzz = vector<float16_t, 3>(ubo_load_72_xz[0], ubo_load_72_y, ubo_load_72_xz[1]).yxzz;
  uint2 ubo_load_73 = U[0].xy;
  vector<float16_t, 2> ubo_load_73_xz = vector<float16_t, 2>(f16tof32(ubo_load_73 & 0xFFFF));
  float16_t ubo_load_73_y = f16tof32(ubo_load_73[0] >> 16);
  vector<float16_t, 4> yyxx = vector<float16_t, 3>(ubo_load_73_xz[0], ubo_load_73_y, ubo_load_73_xz[1]).yyxx;
  uint2 ubo_load_74 = U[0].xy;
  vector<float16_t, 2> ubo_load_74_xz = vector<float16_t, 2>(f16tof32(ubo_load_74 & 0xFFFF));
  float16_t ubo_load_74_y = f16tof32(ubo_load_74[0] >> 16);
  vector<float16_t, 4> yyxy = vector<float16_t, 3>(ubo_load_74_xz[0], ubo_load_74_y, ubo_load_74_xz[1]).yyxy;
  uint2 ubo_load_75 = U[0].xy;
  vector<float16_t, 2> ubo_load_75_xz = vector<float16_t, 2>(f16tof32(ubo_load_75 & 0xFFFF));
  float16_t ubo_load_75_y = f16tof32(ubo_load_75[0] >> 16);
  vector<float16_t, 4> yyxz = vector<float16_t, 3>(ubo_load_75_xz[0], ubo_load_75_y, ubo_load_75_xz[1]).yyxz;
  uint2 ubo_load_76 = U[0].xy;
  vector<float16_t, 2> ubo_load_76_xz = vector<float16_t, 2>(f16tof32(ubo_load_76 & 0xFFFF));
  float16_t ubo_load_76_y = f16tof32(ubo_load_76[0] >> 16);
  vector<float16_t, 4> yyyx = vector<float16_t, 3>(ubo_load_76_xz[0], ubo_load_76_y, ubo_load_76_xz[1]).yyyx;
  uint2 ubo_load_77 = U[0].xy;
  vector<float16_t, 2> ubo_load_77_xz = vector<float16_t, 2>(f16tof32(ubo_load_77 & 0xFFFF));
  float16_t ubo_load_77_y = f16tof32(ubo_load_77[0] >> 16);
  vector<float16_t, 4> yyyy = vector<float16_t, 3>(ubo_load_77_xz[0], ubo_load_77_y, ubo_load_77_xz[1]).yyyy;
  uint2 ubo_load_78 = U[0].xy;
  vector<float16_t, 2> ubo_load_78_xz = vector<float16_t, 2>(f16tof32(ubo_load_78 & 0xFFFF));
  float16_t ubo_load_78_y = f16tof32(ubo_load_78[0] >> 16);
  vector<float16_t, 4> yyyz = vector<float16_t, 3>(ubo_load_78_xz[0], ubo_load_78_y, ubo_load_78_xz[1]).yyyz;
  uint2 ubo_load_79 = U[0].xy;
  vector<float16_t, 2> ubo_load_79_xz = vector<float16_t, 2>(f16tof32(ubo_load_79 & 0xFFFF));
  float16_t ubo_load_79_y = f16tof32(ubo_load_79[0] >> 16);
  vector<float16_t, 4> yyzx = vector<float16_t, 3>(ubo_load_79_xz[0], ubo_load_79_y, ubo_load_79_xz[1]).yyzx;
  uint2 ubo_load_80 = U[0].xy;
  vector<float16_t, 2> ubo_load_80_xz = vector<float16_t, 2>(f16tof32(ubo_load_80 & 0xFFFF));
  float16_t ubo_load_80_y = f16tof32(ubo_load_80[0] >> 16);
  vector<float16_t, 4> yyzy = vector<float16_t, 3>(ubo_load_80_xz[0], ubo_load_80_y, ubo_load_80_xz[1]).yyzy;
  uint2 ubo_load_81 = U[0].xy;
  vector<float16_t, 2> ubo_load_81_xz = vector<float16_t, 2>(f16tof32(ubo_load_81 & 0xFFFF));
  float16_t ubo_load_81_y = f16tof32(ubo_load_81[0] >> 16);
  vector<float16_t, 4> yyzz = vector<float16_t, 3>(ubo_load_81_xz[0], ubo_load_81_y, ubo_load_81_xz[1]).yyzz;
  uint2 ubo_load_82 = U[0].xy;
  vector<float16_t, 2> ubo_load_82_xz = vector<float16_t, 2>(f16tof32(ubo_load_82 & 0xFFFF));
  float16_t ubo_load_82_y = f16tof32(ubo_load_82[0] >> 16);
  vector<float16_t, 4> yzxx = vector<float16_t, 3>(ubo_load_82_xz[0], ubo_load_82_y, ubo_load_82_xz[1]).yzxx;
  uint2 ubo_load_83 = U[0].xy;
  vector<float16_t, 2> ubo_load_83_xz = vector<float16_t, 2>(f16tof32(ubo_load_83 & 0xFFFF));
  float16_t ubo_load_83_y = f16tof32(ubo_load_83[0] >> 16);
  vector<float16_t, 4> yzxy = vector<float16_t, 3>(ubo_load_83_xz[0], ubo_load_83_y, ubo_load_83_xz[1]).yzxy;
  uint2 ubo_load_84 = U[0].xy;
  vector<float16_t, 2> ubo_load_84_xz = vector<float16_t, 2>(f16tof32(ubo_load_84 & 0xFFFF));
  float16_t ubo_load_84_y = f16tof32(ubo_load_84[0] >> 16);
  vector<float16_t, 4> yzxz = vector<float16_t, 3>(ubo_load_84_xz[0], ubo_load_84_y, ubo_load_84_xz[1]).yzxz;
  uint2 ubo_load_85 = U[0].xy;
  vector<float16_t, 2> ubo_load_85_xz = vector<float16_t, 2>(f16tof32(ubo_load_85 & 0xFFFF));
  float16_t ubo_load_85_y = f16tof32(ubo_load_85[0] >> 16);
  vector<float16_t, 4> yzyx = vector<float16_t, 3>(ubo_load_85_xz[0], ubo_load_85_y, ubo_load_85_xz[1]).yzyx;
  uint2 ubo_load_86 = U[0].xy;
  vector<float16_t, 2> ubo_load_86_xz = vector<float16_t, 2>(f16tof32(ubo_load_86 & 0xFFFF));
  float16_t ubo_load_86_y = f16tof32(ubo_load_86[0] >> 16);
  vector<float16_t, 4> yzyy = vector<float16_t, 3>(ubo_load_86_xz[0], ubo_load_86_y, ubo_load_86_xz[1]).yzyy;
  uint2 ubo_load_87 = U[0].xy;
  vector<float16_t, 2> ubo_load_87_xz = vector<float16_t, 2>(f16tof32(ubo_load_87 & 0xFFFF));
  float16_t ubo_load_87_y = f16tof32(ubo_load_87[0] >> 16);
  vector<float16_t, 4> yzyz = vector<float16_t, 3>(ubo_load_87_xz[0], ubo_load_87_y, ubo_load_87_xz[1]).yzyz;
  uint2 ubo_load_88 = U[0].xy;
  vector<float16_t, 2> ubo_load_88_xz = vector<float16_t, 2>(f16tof32(ubo_load_88 & 0xFFFF));
  float16_t ubo_load_88_y = f16tof32(ubo_load_88[0] >> 16);
  vector<float16_t, 4> yzzx = vector<float16_t, 3>(ubo_load_88_xz[0], ubo_load_88_y, ubo_load_88_xz[1]).yzzx;
  uint2 ubo_load_89 = U[0].xy;
  vector<float16_t, 2> ubo_load_89_xz = vector<float16_t, 2>(f16tof32(ubo_load_89 & 0xFFFF));
  float16_t ubo_load_89_y = f16tof32(ubo_load_89[0] >> 16);
  vector<float16_t, 4> yzzy = vector<float16_t, 3>(ubo_load_89_xz[0], ubo_load_89_y, ubo_load_89_xz[1]).yzzy;
  uint2 ubo_load_90 = U[0].xy;
  vector<float16_t, 2> ubo_load_90_xz = vector<float16_t, 2>(f16tof32(ubo_load_90 & 0xFFFF));
  float16_t ubo_load_90_y = f16tof32(ubo_load_90[0] >> 16);
  vector<float16_t, 4> yzzz = vector<float16_t, 3>(ubo_load_90_xz[0], ubo_load_90_y, ubo_load_90_xz[1]).yzzz;
  uint2 ubo_load_91 = U[0].xy;
  vector<float16_t, 2> ubo_load_91_xz = vector<float16_t, 2>(f16tof32(ubo_load_91 & 0xFFFF));
  float16_t ubo_load_91_y = f16tof32(ubo_load_91[0] >> 16);
  vector<float16_t, 4> zxxx = vector<float16_t, 3>(ubo_load_91_xz[0], ubo_load_91_y, ubo_load_91_xz[1]).zxxx;
  uint2 ubo_load_92 = U[0].xy;
  vector<float16_t, 2> ubo_load_92_xz = vector<float16_t, 2>(f16tof32(ubo_load_92 & 0xFFFF));
  float16_t ubo_load_92_y = f16tof32(ubo_load_92[0] >> 16);
  vector<float16_t, 4> zxxy = vector<float16_t, 3>(ubo_load_92_xz[0], ubo_load_92_y, ubo_load_92_xz[1]).zxxy;
  uint2 ubo_load_93 = U[0].xy;
  vector<float16_t, 2> ubo_load_93_xz = vector<float16_t, 2>(f16tof32(ubo_load_93 & 0xFFFF));
  float16_t ubo_load_93_y = f16tof32(ubo_load_93[0] >> 16);
  vector<float16_t, 4> zxxz = vector<float16_t, 3>(ubo_load_93_xz[0], ubo_load_93_y, ubo_load_93_xz[1]).zxxz;
  uint2 ubo_load_94 = U[0].xy;
  vector<float16_t, 2> ubo_load_94_xz = vector<float16_t, 2>(f16tof32(ubo_load_94 & 0xFFFF));
  float16_t ubo_load_94_y = f16tof32(ubo_load_94[0] >> 16);
  vector<float16_t, 4> zxyx = vector<float16_t, 3>(ubo_load_94_xz[0], ubo_load_94_y, ubo_load_94_xz[1]).zxyx;
  uint2 ubo_load_95 = U[0].xy;
  vector<float16_t, 2> ubo_load_95_xz = vector<float16_t, 2>(f16tof32(ubo_load_95 & 0xFFFF));
  float16_t ubo_load_95_y = f16tof32(ubo_load_95[0] >> 16);
  vector<float16_t, 4> zxyy = vector<float16_t, 3>(ubo_load_95_xz[0], ubo_load_95_y, ubo_load_95_xz[1]).zxyy;
  uint2 ubo_load_96 = U[0].xy;
  vector<float16_t, 2> ubo_load_96_xz = vector<float16_t, 2>(f16tof32(ubo_load_96 & 0xFFFF));
  float16_t ubo_load_96_y = f16tof32(ubo_load_96[0] >> 16);
  vector<float16_t, 4> zxyz = vector<float16_t, 3>(ubo_load_96_xz[0], ubo_load_96_y, ubo_load_96_xz[1]).zxyz;
  uint2 ubo_load_97 = U[0].xy;
  vector<float16_t, 2> ubo_load_97_xz = vector<float16_t, 2>(f16tof32(ubo_load_97 & 0xFFFF));
  float16_t ubo_load_97_y = f16tof32(ubo_load_97[0] >> 16);
  vector<float16_t, 4> zxzx = vector<float16_t, 3>(ubo_load_97_xz[0], ubo_load_97_y, ubo_load_97_xz[1]).zxzx;
  uint2 ubo_load_98 = U[0].xy;
  vector<float16_t, 2> ubo_load_98_xz = vector<float16_t, 2>(f16tof32(ubo_load_98 & 0xFFFF));
  float16_t ubo_load_98_y = f16tof32(ubo_load_98[0] >> 16);
  vector<float16_t, 4> zxzy = vector<float16_t, 3>(ubo_load_98_xz[0], ubo_load_98_y, ubo_load_98_xz[1]).zxzy;
  uint2 ubo_load_99 = U[0].xy;
  vector<float16_t, 2> ubo_load_99_xz = vector<float16_t, 2>(f16tof32(ubo_load_99 & 0xFFFF));
  float16_t ubo_load_99_y = f16tof32(ubo_load_99[0] >> 16);
  vector<float16_t, 4> zxzz = vector<float16_t, 3>(ubo_load_99_xz[0], ubo_load_99_y, ubo_load_99_xz[1]).zxzz;
  uint2 ubo_load_100 = U[0].xy;
  vector<float16_t, 2> ubo_load_100_xz = vector<float16_t, 2>(f16tof32(ubo_load_100 & 0xFFFF));
  float16_t ubo_load_100_y = f16tof32(ubo_load_100[0] >> 16);
  vector<float16_t, 4> zyxx = vector<float16_t, 3>(ubo_load_100_xz[0], ubo_load_100_y, ubo_load_100_xz[1]).zyxx;
  uint2 ubo_load_101 = U[0].xy;
  vector<float16_t, 2> ubo_load_101_xz = vector<float16_t, 2>(f16tof32(ubo_load_101 & 0xFFFF));
  float16_t ubo_load_101_y = f16tof32(ubo_load_101[0] >> 16);
  vector<float16_t, 4> zyxy = vector<float16_t, 3>(ubo_load_101_xz[0], ubo_load_101_y, ubo_load_101_xz[1]).zyxy;
  uint2 ubo_load_102 = U[0].xy;
  vector<float16_t, 2> ubo_load_102_xz = vector<float16_t, 2>(f16tof32(ubo_load_102 & 0xFFFF));
  float16_t ubo_load_102_y = f16tof32(ubo_load_102[0] >> 16);
  vector<float16_t, 4> zyxz = vector<float16_t, 3>(ubo_load_102_xz[0], ubo_load_102_y, ubo_load_102_xz[1]).zyxz;
  uint2 ubo_load_103 = U[0].xy;
  vector<float16_t, 2> ubo_load_103_xz = vector<float16_t, 2>(f16tof32(ubo_load_103 & 0xFFFF));
  float16_t ubo_load_103_y = f16tof32(ubo_load_103[0] >> 16);
  vector<float16_t, 4> zyyx = vector<float16_t, 3>(ubo_load_103_xz[0], ubo_load_103_y, ubo_load_103_xz[1]).zyyx;
  uint2 ubo_load_104 = U[0].xy;
  vector<float16_t, 2> ubo_load_104_xz = vector<float16_t, 2>(f16tof32(ubo_load_104 & 0xFFFF));
  float16_t ubo_load_104_y = f16tof32(ubo_load_104[0] >> 16);
  vector<float16_t, 4> zyyy = vector<float16_t, 3>(ubo_load_104_xz[0], ubo_load_104_y, ubo_load_104_xz[1]).zyyy;
  uint2 ubo_load_105 = U[0].xy;
  vector<float16_t, 2> ubo_load_105_xz = vector<float16_t, 2>(f16tof32(ubo_load_105 & 0xFFFF));
  float16_t ubo_load_105_y = f16tof32(ubo_load_105[0] >> 16);
  vector<float16_t, 4> zyyz = vector<float16_t, 3>(ubo_load_105_xz[0], ubo_load_105_y, ubo_load_105_xz[1]).zyyz;
  uint2 ubo_load_106 = U[0].xy;
  vector<float16_t, 2> ubo_load_106_xz = vector<float16_t, 2>(f16tof32(ubo_load_106 & 0xFFFF));
  float16_t ubo_load_106_y = f16tof32(ubo_load_106[0] >> 16);
  vector<float16_t, 4> zyzx = vector<float16_t, 3>(ubo_load_106_xz[0], ubo_load_106_y, ubo_load_106_xz[1]).zyzx;
  uint2 ubo_load_107 = U[0].xy;
  vector<float16_t, 2> ubo_load_107_xz = vector<float16_t, 2>(f16tof32(ubo_load_107 & 0xFFFF));
  float16_t ubo_load_107_y = f16tof32(ubo_load_107[0] >> 16);
  vector<float16_t, 4> zyzy = vector<float16_t, 3>(ubo_load_107_xz[0], ubo_load_107_y, ubo_load_107_xz[1]).zyzy;
  uint2 ubo_load_108 = U[0].xy;
  vector<float16_t, 2> ubo_load_108_xz = vector<float16_t, 2>(f16tof32(ubo_load_108 & 0xFFFF));
  float16_t ubo_load_108_y = f16tof32(ubo_load_108[0] >> 16);
  vector<float16_t, 4> zyzz = vector<float16_t, 3>(ubo_load_108_xz[0], ubo_load_108_y, ubo_load_108_xz[1]).zyzz;
  uint2 ubo_load_109 = U[0].xy;
  vector<float16_t, 2> ubo_load_109_xz = vector<float16_t, 2>(f16tof32(ubo_load_109 & 0xFFFF));
  float16_t ubo_load_109_y = f16tof32(ubo_load_109[0] >> 16);
  vector<float16_t, 4> zzxx = vector<float16_t, 3>(ubo_load_109_xz[0], ubo_load_109_y, ubo_load_109_xz[1]).zzxx;
  uint2 ubo_load_110 = U[0].xy;
  vector<float16_t, 2> ubo_load_110_xz = vector<float16_t, 2>(f16tof32(ubo_load_110 & 0xFFFF));
  float16_t ubo_load_110_y = f16tof32(ubo_load_110[0] >> 16);
  vector<float16_t, 4> zzxy = vector<float16_t, 3>(ubo_load_110_xz[0], ubo_load_110_y, ubo_load_110_xz[1]).zzxy;
  uint2 ubo_load_111 = U[0].xy;
  vector<float16_t, 2> ubo_load_111_xz = vector<float16_t, 2>(f16tof32(ubo_load_111 & 0xFFFF));
  float16_t ubo_load_111_y = f16tof32(ubo_load_111[0] >> 16);
  vector<float16_t, 4> zzxz = vector<float16_t, 3>(ubo_load_111_xz[0], ubo_load_111_y, ubo_load_111_xz[1]).zzxz;
  uint2 ubo_load_112 = U[0].xy;
  vector<float16_t, 2> ubo_load_112_xz = vector<float16_t, 2>(f16tof32(ubo_load_112 & 0xFFFF));
  float16_t ubo_load_112_y = f16tof32(ubo_load_112[0] >> 16);
  vector<float16_t, 4> zzyx = vector<float16_t, 3>(ubo_load_112_xz[0], ubo_load_112_y, ubo_load_112_xz[1]).zzyx;
  uint2 ubo_load_113 = U[0].xy;
  vector<float16_t, 2> ubo_load_113_xz = vector<float16_t, 2>(f16tof32(ubo_load_113 & 0xFFFF));
  float16_t ubo_load_113_y = f16tof32(ubo_load_113[0] >> 16);
  vector<float16_t, 4> zzyy = vector<float16_t, 3>(ubo_load_113_xz[0], ubo_load_113_y, ubo_load_113_xz[1]).zzyy;
  uint2 ubo_load_114 = U[0].xy;
  vector<float16_t, 2> ubo_load_114_xz = vector<float16_t, 2>(f16tof32(ubo_load_114 & 0xFFFF));
  float16_t ubo_load_114_y = f16tof32(ubo_load_114[0] >> 16);
  vector<float16_t, 4> zzyz = vector<float16_t, 3>(ubo_load_114_xz[0], ubo_load_114_y, ubo_load_114_xz[1]).zzyz;
  uint2 ubo_load_115 = U[0].xy;
  vector<float16_t, 2> ubo_load_115_xz = vector<float16_t, 2>(f16tof32(ubo_load_115 & 0xFFFF));
  float16_t ubo_load_115_y = f16tof32(ubo_load_115[0] >> 16);
  vector<float16_t, 4> zzzx = vector<float16_t, 3>(ubo_load_115_xz[0], ubo_load_115_y, ubo_load_115_xz[1]).zzzx;
  uint2 ubo_load_116 = U[0].xy;
  vector<float16_t, 2> ubo_load_116_xz = vector<float16_t, 2>(f16tof32(ubo_load_116 & 0xFFFF));
  float16_t ubo_load_116_y = f16tof32(ubo_load_116[0] >> 16);
  vector<float16_t, 4> zzzy = vector<float16_t, 3>(ubo_load_116_xz[0], ubo_load_116_y, ubo_load_116_xz[1]).zzzy;
  uint2 ubo_load_117 = U[0].xy;
  vector<float16_t, 2> ubo_load_117_xz = vector<float16_t, 2>(f16tof32(ubo_load_117 & 0xFFFF));
  float16_t ubo_load_117_y = f16tof32(ubo_load_117[0] >> 16);
  vector<float16_t, 4> zzzz = vector<float16_t, 3>(ubo_load_117_xz[0], ubo_load_117_y, ubo_load_117_xz[1]).zzzz;
}
