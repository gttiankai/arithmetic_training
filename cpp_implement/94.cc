#include "tree_node.h"

#include <iostream>
#include <vector>
class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> ans;
    Traversal(root, ans);
    return ans;
  }

 private:
  void Traversal(TreeNode* root, std::vector<int>& ans) {
    if (root == nullptr) {
      return;
    }
    Traversal(root->left, ans);
    ans.push_back(root->val);
    Traversal(root->right, ans);
  }
};

int main(int argc, char* argv[]) {
  TreeNode root;
  TreeNode two_node;
  TreeNode three_node;
  root.val         = 1;
  two_node.val     = 2;
  three_node.val   = 3;
  root.left        = nullptr;
  root.right       = &two_node;
  two_node.left    = &three_node;
  two_node.right   = nullptr;
  three_node.left  = nullptr;
  three_node.right = nullptr;
  Solution solution;
  auto ans = solution.inorderTraversal(&root);
  for (const auto& item : ans) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return 0;
}