#include <climits>
#include <iostream>
#include <vector>
#include "tree_node.h"

/**
 * 错误点:虽然是使用递归的方式进行判断,但是只保证了每个树的左边值小于 root value, 右边值大于root value
 * wrong case: [5, 4, 6, null, null, 3, 7]
 * **/
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
/**
 *  关键点 1: 根据提醒,value 有可能是 INT_MIN 和 INT_MAX,所以设置的 down 和 up 必须要是 LONG_INT 和 LONG_MAX
 *
 * **/
class Solution { public:
  bool isValidBST(TreeNode* root) {
    return Valid(root, LONG_MIN, LONG_MAX);
  }

 private:
  bool Valid(TreeNode* root, long down, long up) {
    if (root == nullptr) {
      return true;
    }
    if (root->val <= down || root->val >= up) {
      return false;
    }
    bool left = true;
    if (root->left != nullptr) {
      left = (root->val > root->left->val) && Valid(root->left, down, root->val);
    }
    bool right = true;
    if (root->right != nullptr) {
      right = (root->val < root->right->val) && Valid(root->right, root->val, up);
    }
    return left && right;
  }
};
/**
 * 关键点: 使用中序遍历的方式,然后最后检查是否为升序就可以判断是否是二叉查找树
 * **/
class SolutionInOrder {
 public:
  bool isValidBST(TreeNode* root) {
    std::vector<int> ans;
    InOrder(ans, root);
    for (int i = 0; i < ans.size() - 1; ++i) {
      if (ans[i] >= ans[i + 1]) {
        return false;
      }
    }
    return true;
  }

 private:
  void InOrder(std::vector<int>& ans, TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr) {
      InOrder(ans, root->left);
    }
    ans.push_back(root->val);
    if (root->right != nullptr) {
      InOrder(ans, root->right);
    }
  }
};

int main(int argc, char* argv[]) {
  TreeNode zero(0), one(1), two(2), three(3), four(4), five(5), six(6), seven(7);
  // three.left  = &one;
  // three.right = &five;
  // one.left    = &zero;
  // one.right   = &two;
  // two.right   = &three;
  // five.left   = &four;
  // five.right  = &six;
  five.left  = &four;
  five.right = &six;
  six.left   = &three;
  six.right  = &seven;
  Solution solution;
  std::cout << solution.isValidBST(&five) << std::endl;
  SolutionInOrder solution_in_order;
  std::cout << solution_in_order.isValidBST(&five) << std::endl;

  return 0;
}
