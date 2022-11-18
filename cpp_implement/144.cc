
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

  void PreOrder(TreeNode* root, std::vector<int>& res) {
    if (root == nullptr) {
      return ;
    }
    res.push_back(root->val);
    PreOrder(root->left, res);
    PreOrder(root->right, res);
  }

  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    PreOrder(root, res);
    return res;
  }
};