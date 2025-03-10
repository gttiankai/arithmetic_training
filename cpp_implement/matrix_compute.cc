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
#include <random>

int main(int argc, char* argv[]) {
  const int M   = 3;
  const int K   = 2;
  const int N   = 3;
  int* matrix_a = new int[3 * 2]();
  int* matrix_b = new int[3 * 2]();
  int* matrix_c = new int[3 * 3]();
  for (int m = 0; m < M; ++m) {
    for (int k = 0; k < K; ++k) {
      matrix_a[m * K + k] = m * K + k;
    }
  }
  for (int k = 0; k < K; ++k) {
    for (int n = 0; n < N; ++n) {
      matrix_b[k * N + n] = matrix_a[n * K + k];
    }
  }
  for (int m = 0; m < M; ++m) {
    for (int n = m; n < N; ++n) {
      for (int k = 0; k < K; ++k) {
        matrix_c[m * N + n] += matrix_a[m * K + k] * matrix_b[k * N + n];
      }
    }
  }
  delete[] matrix_a;
  delete[] matrix_b;
  delete[] matrix_c;
  return 0;
}
