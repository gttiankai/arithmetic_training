#include <iostream>
#include <vector>
#include "tree_node.h"

class SolutionWrong {
 public:
  bool isValidBST(TreeNode* root) {
    bool ans = true;
    if (root == nullptr) {
      return ans;
    }
    bool left = true;
    if (root->left != nullptr) {
      left = (root->val > root->left->val) && isValidBST(root->left);
    }
    bool right = true;
    if (root->right != nullptr) {
      right = (root->val < root->right->val) && isValidBST(root->right);
    }
    return left && right;
  }
};

int main(int argc, char* argv[]) {
  TreeNode one(1), two(2), three(3), four(4), five(5), six(6);
  five.left  = &one;
  five.right = &four;
  four.left  = &three;
  four.right = &six;
  Solution solution;
  std::cout << solution.isValidBST(&five) << std::endl;
  return 0;
}
