/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (58.79%)
 * Likes:    2436
 * Dislikes: 0
 * Total Accepted:    836.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
 */
#include "tree_node.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/**
 * 这个解法是错误的,中序遍历之后的 list,即使是回文的,也不能保证二叉树是镜像的
 * bad case: [1, 2, 2, 2, null, 2]
 * 即使将 null 也考虑进行也不能解决这个问题,详见下面的这个 bad case
 * bad case: [5,4,1,null,1,null,4,2,null,2,null]
 * */
class SolutionWrong {
 public:
  bool isSymmetric(TreeNode* root) {
    std::vector<int> list;
    Inorder(root, list);
    int N = list.size();
    if (N == 1) {
      return true;
    }
    int mid = N / 2;
    for (int i = 0; i < mid; ++i) {
      if (list[i] != list[N - 1 - i]) {
        return false;
      }
    }
    return true;
  }

 private:
  void Inorder(TreeNode* root, std::vector<int>& list) {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr || root->right != nullptr) {
      if (root->left == nullptr) {
        list.push_back(INT_MIN);
      } else {
        Inorder(root->left, list);
      }
      list.push_back(root->val);
      if (root->right == nullptr) {
        list.push_back(INT_MIN);
      } else {
        Inorder(root->right, list);
      }
    } else {
      list.push_back(root->val);
      return;
    }
  }
};
// @lc code=start
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
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (root != nullptr && root->left == nullptr && root->right == nullptr) {
      return true;
    }
    return Symmetric(root->left, root->right);
  }

 private:
  bool Symmetric(TreeNode* node_1, TreeNode* node_2) {
    if (node_1 == nullptr && node_2 == nullptr) {
      return true;
    }
    if (node_1 == nullptr || node_2 == nullptr) {
      return false;
    }
    if (node_1->val != node_2->val) {
      return false;
    }
    return Symmetric(node_1->left, node_2->right) && Symmetric(node_1->right, node_2->left);
  }
};

// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<std::string> test_case;
  test_case.push_back("[5,4,1,null,1,null,4,2,null,2,null]");
  test_case.push_back("[1,2,2,2,null,2]");
  test_case.push_back("[1,2,2,3,4,4,3]");
  test_case.push_back("[1,2,2,null,3,null,3]");
  test_case.push_back("[1]");

  Solution solution;
  for (const auto& item : test_case) {
    TreeNode* root = StringToTreeNode(item);
    std::cout << item << " is symmetric: " << solution.isSymmetric(root) << std::endl;
  }
  return 0;
}
