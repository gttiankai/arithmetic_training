#include "command_include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
 public:
  // TODO: 回溯 or 分治， 需要研究下
  std::vector<TreeNode *> CreateBST(int start, int end) {
    if (start > end) {
      return {nullptr};
    }
    std::vector<TreeNode *> res;
    for (int i = start; i <= end; ++i) {
      std::vector<TreeNode *> left_tree  = CreateBST(start, i - 1);
      std::vector<TreeNode *> right_tree = CreateBST(i + 1, end);
      for (auto &left : left_tree) {
        for (auto &right : right_tree) {
          TreeNode *node = new TreeNode(i);
          node->left     = left;
          node->right    = right;
          res.push_back(node);
        }
      }
    }
    return res;
  }
  std::vector<TreeNode *> generateTrees(int n) {
    if (n < 1) {
      return {nullptr};
    }
    CreateBST(1, n);
  }
};
