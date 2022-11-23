#include "command_include.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * 平衡二叉树
 *
 * */
class Solution {
 public:
  int depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    int left_depth  = 0;
    int right_depth = 0;
    if (root->left != nullptr) {
      left_depth = depth(root->left) + 1;
    }
    if (root->right != nullptr) {
      right_depth = depth(root->right) + 1;
    }
    return left_depth >= right_depth ? left_depth : right_depth;
  }

  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (!isBalanced(root->left) || !isBalanced(root->right)) {
      return false;
    }
    int left_depth  = depth(root->left);
    int right_depth = depth(root->right);
    int diff        = std::abs(left_depth - right_depth);
    if (diff > 1) {
      return false;
    } else {
      return true;
    }
  }
};

/**
 * 这个版本只是优化了写法，主要的思想还是没有变化，还是利用了平衡二叉树的定义
 * 思路上还是自上往下的思路
 * 缺点：计算 depth 时有重复计算，
 * 优化点：如何解决 depth 计算重复的问题
 * */
class SolutionO1 {
 public:
  int Depth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return std::max(Depth(root->left), Depth(root->right)) + 1;
  }

  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    if (!isBalanced(root->left) || !isBalanced(root->right)) {
      return false;
    }
    int left_depth  = Depth(root->left);
    int right_depth = Depth(root->right);
    return std::abs(left_depth - right_depth) <= 1;
  }
};
/**
 * 思考：如何自下而上进行
 * 用了一个技巧：使用了一个特殊值 -1， 标记子节点是否是平衡二叉树，非 -1 的值表示的深度，
 * 这个技巧就是我一直思考了，如何返回两个值：是否是平衡二叉树；树的深度
 * */
class SolutionOptimize2 {
 public:
  int Balance(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left_depth = Balance(root->left);
    if (left_depth < 0) {
      return -1;
    }
    int right_depth = Balance(root->right);
    if (right_depth < 0) {
      return -1;
    }
    if (std::abs(left_depth - right_depth) > 1) {
      return -1;
    }
    return std::max(left_depth, right_depth) + 1;
  }
  bool isBalanced(TreeNode *root) { return Balance(root) >= 0; }
};