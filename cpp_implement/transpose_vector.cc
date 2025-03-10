// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include <arm_neon.h>
#include <iostream>
#include <string>

void Transpose4x4(float32x4_t& a0, float32x4_t& a1, float32x4_t& a2, float32x4_t& a3) {
  float32x4_t v01_e = vtrn1q_f32(a0, a1);
  float32x4_t v01_o = vtrn2q_f32(a0, a1);

  float32x4_t v23_e = vtrn1q_f32(a2, a3);
  float32x4_t v23_o = vtrn2q_f32(a2, a3);

  a0 = vcombine_f32(vget_low_f32(v01_e), vget_low_f32(v23_e));
  a1 = vcombine_f32(vget_low_f32(v01_o), vget_low_f32(v23_o));

  a2 = vcombine_f32(vget_high_f32(v01_e), vget_high_f32(v23_e));
  a3 = vcombine_f32(vget_high_f32(v01_o), vget_high_f32(v23_o));
  return ;


  float32x4x2_t v01 = vtrnq_f32(a0, a1);
  float32x4x2_t v23 = vtrnq_f32(a2, a3);

  float32x2_t d00 = vget_low_f32(v01.val[0]);
  float32x2_t d01 = vget_high_f32(v01.val[0]);

  float32x2_t d10 = vget_low_f32(v01.val[1]);
  float32x2_t d11 = vget_high_f32(v01.val[1]);

  float32x2_t d20 = vget_low_f32(v23.val[0]);
  float32x2_t d21 = vget_high_f32(v23.val[0]);

  float32x2_t d30 = vget_low_f32(v23.val[1]);
  float32x2_t d31 = vget_high_f32(v23.val[1]);

  a0 = vcombine_f32(d00, d20);
  a1 = vcombine_f32(d10, d30);
  a2 = vcombine_f32(d01, d21);
  a3 = vcombine_f32(d11, d31);
}

void Transpose8x8(float16_t* dst_buffer, float16_t* src_buffer) {
  float16x8_t a0 = vld1q_f16(src_buffer);
  src_buffer += 8;
  float16x8_t a1 = vld1q_f16(src_buffer);
  src_buffer += 8;
  float16x8_t a2 = vld1q_f16(src_buffer);
  src_buffer += 8;
  float16x8_t a3 = vld1q_f16(src_buffer);
  src_buffer += 8;
  float16x8_t a4 = vld1q_f16(src_buffer);
  src_buffer += 8;
  float16x8_t a5 = vld1q_f16(src_buffer);
  src_buffer += 8;
  float16x8_t a6 = vld1q_f16(src_buffer);
  src_buffer += 8;
  float16x8_t a7 = vld1q_f16(src_buffer);
  src_buffer += 8;

  // even number
  float16x8_t e_v01 = vtrn1q_f16(a0, a1);
  // odd number
  float16x8_t o_v01 = vtrn2q_f16(a0, a1);

  float16x8_t e_v23 = vtrn1q_f16(a2, a3);
  float16x8_t o_v23 = vtrn2q_f16(a2, a3);

  float16x8_t e_v45 = vtrn1q_f16(a4, a5);
  float16x8_t o_v45 = vtrn2q_f16(a4, a5);

  float16x8_t e_v67 = vtrn1q_f16(a6, a7);
  float16x8_t o_v67 = vtrn2q_f16(a6, a7);

  //  float16x4_t v0_low = vreinterpret_f16_f32(
  //      vtrn1_f32(vreinterpret_f32_f16(vget_low_f16(e_v01)), vreinterpret_f32_f16(vget_low_f16(e_v23))));
  //  float16x4_t v0_high = vreinterpret_f16_f32(
  //      vtrn1_f32(vreinterpret_f32_f16(vget_low_f16(e_v45)), vreinterpret_f32_f16(vget_low_f16(e_v67))));

  float16x8_t v0;
  asm volatile("TRN1 %0.4s, %2.4s, %3.4s \n\t" : "=w"(v0) : "0"(v0), "w"(e_v01), "w"(e_v23) : "cc", "memory");

  float16x4_t v0_low = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_low_f16(e_v01)), vreinterpret_f32_f16(vget_low_f16(e_v23))));
  float16x4_t v0_high = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_low_f16(e_v45)), vreinterpret_f32_f16(vget_low_f16(e_v67))));

  float16x4_t v1_low = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_low_f16(o_v01)), vreinterpret_f32_f16(vget_low_f16(o_v23))));
  float16x4_t v1_high = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_low_f16(o_v45)), vreinterpret_f32_f16(vget_low_f16(o_v67))));

  float16x4_t v2_low = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_low_f16(e_v01)), vreinterpret_f32_f16(vget_low_f16(e_v23))));
  float16x4_t v2_high = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_low_f16(e_v45)), vreinterpret_f32_f16(vget_low_f16(e_v67))));

  float16x4_t v3_low = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_low_f16(o_v01)), vreinterpret_f32_f16(vget_low_f16(o_v23))));
  float16x4_t v3_high = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_low_f16(o_v45)), vreinterpret_f32_f16(vget_low_f16(o_v67))));

  float16x4_t v4_low = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_high_f16(e_v01)), vreinterpret_f32_f16(vget_high_f16(e_v23))));
  float16x4_t v4_high = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_high_f16(e_v45)), vreinterpret_f32_f16(vget_high_f16(e_v67))));

  float16x4_t v5_low = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_high_f16(o_v01)), vreinterpret_f32_f16(vget_high_f16(o_v23))));
  float16x4_t v5_high = vreinterpret_f16_f32(
      vtrn1_f32(vreinterpret_f32_f16(vget_high_f16(o_v45)), vreinterpret_f32_f16(vget_high_f16(o_v67))));

  float16x4_t v6_low = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_high_f16(e_v01)), vreinterpret_f32_f16(vget_high_f16(e_v23))));
  float16x4_t v6_high = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_high_f16(e_v45)), vreinterpret_f32_f16(vget_high_f16(e_v67))));

  float16x4_t v7_low = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_high_f16(o_v01)), vreinterpret_f32_f16(vget_high_f16(o_v23))));
  float16x4_t v7_high = vreinterpret_f16_f32(
      vtrn2_f32(vreinterpret_f32_f16(vget_high_f16(o_v45)), vreinterpret_f32_f16(vget_high_f16(o_v67))));

  vst1q_f16(dst_buffer, vcombine_f16(v0_low, v0_high));
  dst_buffer += 8;
  vst1q_f16(dst_buffer, vcombine_f16(v1_low, v1_high));
  dst_buffer += 8;
  vst1q_f16(dst_buffer, vcombine_f16(v2_low, v2_high));
  dst_buffer += 8;
  vst1q_f16(dst_buffer, vcombine_f16(v3_low, v3_high));
  dst_buffer += 8;
  vst1q_f16(dst_buffer, vcombine_f16(v4_low, v4_high));
  dst_buffer += 8;
  vst1q_f16(dst_buffer, vcombine_f16(v5_low, v5_high));
  dst_buffer += 8;
  vst1q_f16(dst_buffer, vcombine_f16(v6_low, v6_high));
  dst_buffer += 8;
  vst1q_f16(dst_buffer, vcombine_f16(v7_low, v7_high));
  dst_buffer += 8;
}

// define TRANSPOSE4x4(pSrc,pDst) vst1q_f32_x4(pDst,vld4q_f32(pSrc))
int main(int argc, char* argv[]) {
  //  float32x4x4_t v0123 = vld4q_f32(src_fp32);
  //  vst1q_f32_x4(dst_fp32, v0123);

  float32x4_t a0 = {0, 1, 2, 3};
  float32x4_t a1 = {4, 5, 6, 7};
  float32x4_t a2 = {8, 9, 10, 11};
  float32x4_t a3 = {12, 13, 14, 15};

  std::cout << a0[0] << " " << a0[1] << " " << a0[2] << " " << a0[3] << std::endl;
  std::cout << a1[0] << " " << a1[1] << " " << a1[2] << " " << a1[3] << std::endl;
  std::cout << a2[0] << " " << a2[1] << " " << a2[2] << " " << a2[3] << std::endl;
  std::cout << a3[0] << " " << a3[1] << " " << a3[2] << " " << a3[3] << std::endl;
  Transpose4x4(a0, a1, a2, a3);
  std::cout << "----------Transpose 4x4------------------" << std::endl;
  std::cout << a0[0] << " " << a0[1] << " " << a0[2] << " " << a0[3] << std::endl;
  std::cout << a1[0] << " " << a1[1] << " " << a1[2] << " " << a1[3] << std::endl;
  std::cout << a2[0] << " " << a2[1] << " " << a2[2] << " " << a2[3] << std::endl;
  std::cout << a3[0] << " " << a3[1] << " " << a3[2] << " " << a3[3] << std::endl;
  std::cout << std::endl << std::endl;

  const int count  = 64;
  auto* src_buffer = new float16_t[count]();
  auto* dst_buffer = new float16_t[count]();
  for (int i = 0; i < 64; ++i) {
    src_buffer[i] = (float16_t)i;
  }
  for (int i = 0; i < 8; ++i) {
    std::string message;
    for (int j = 0; j < 8; ++j) {
      message += std::to_string((int)src_buffer[i * 8 + j]) + "\t";
    }
    std::cout << message << std::endl;
  }
  Transpose8x8(dst_buffer, src_buffer);
  std::cout << "============ transpose 8x8 ===========" << std::endl;
  for (int i = 0; i < 8; ++i) {
    std::string message;
    for (int j = 0; j < 8; ++j) {
      message += std::to_string((int)dst_buffer[i * 8 + j]) + "\t";
    }
    std::cout << message << std::endl;
  }
}
