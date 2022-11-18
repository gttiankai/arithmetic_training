#include "command_include.h"
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
  void Inorder(TreeNode *root, std::vector<int>& res) {
    if (root == nullptr) {
      return;
    }
    Inorder(root->left, res);
    res.push_back(root->val);
    Inorder(root->right, res);
  }
  void InorderO1(TreeNode* root, std::vector<int>& res) {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr){
      Inorder(root->left, res);
    }
    res.push_back(root->val);
    if (root->right != nullptr) {
      Inorder(root->right, res);
    }
  }

  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    Inorder(root, res);
    return res;
  }
};