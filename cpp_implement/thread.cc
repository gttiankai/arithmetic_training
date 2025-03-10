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

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
//  int WARP_SIZE = 32;
//  for (int i = 0; i < 128; ++i) {
//    uint32_t lane_id       = i % WARP_SIZE;
//    uint32_t Offset_Shared = lane_id * 2;
//    uint32_t Offset_Global = lane_id / 4 + (lane_id % 4) * 16;
//    printf("index: %3d lane_id:%2d offset_shared: %2d %2d Offset_Global: %2d %2d\n", i, lane_id, Offset_Shared,
//           Offset_Shared + 1, Offset_Global, Offset_Global + 8);
//  }
  uint32_t a[4]        = {0, 1, 2, 3};
  // uint32_t(*a_read)[4] = reinterpret_cast<uint32_t(*)[4]>(a);
  uint32_t(*a_read)[4] = &a;
  for (int i = 0; i < 4; ++i) {
    printf("a_read[%2d]: %d", i, (*a_read)[i]);
  }
  return 0;
}