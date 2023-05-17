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
#include <vector>
#include "tree_node.h"

class Solution {
 public:
  std::vector<TreeNode*> generateTrees(int n) {
    return CreateBST(1, n);
  }

 private:
  std::vector<TreeNode*> CreateBST(int start, int end) {
    if (start > end) {
      return {nullptr};
    }
    std::vector<TreeNode*> all_trees;
    for (int i = start; i <= end; ++i) {
      std::vector<TreeNode*> left_trees  = CreateBST(start, i - 1);
      std::vector<TreeNode*> right_trees = CreateBST(i + 1, end);
      for (const auto& left : left_trees) {
        for (const auto& right : right_trees) {
          TreeNode* currTree = new TreeNode(i);
          currTree->left     = left;
          currTree->right    = right;
          all_trees.emplace_back(currTree);
        }
      }
    }
    return all_trees;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  int n    = 3;
  auto ans = solution.generateTrees(n);
  std::cout << n << " generate bst: " << ans.size() << std::endl;
  return 0;
}
