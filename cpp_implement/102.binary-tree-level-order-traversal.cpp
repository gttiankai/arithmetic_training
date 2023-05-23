/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (65.60%)
 * Likes:    1695
 * Dislikes: 0
 * Total Accepted:    813.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include <sys/types.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "tree_node.h"

class SolutionUgly {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    std::queue<TreeNode*> queue;
    queue.push(root);
    Generate(queue, ans, queue.size());
    return ans;
  }

 private:
  void Generate(std::queue<TreeNode*>& queue, std::vector<std::vector<int>>& ans, int n) {
    std::vector<int> level;
    for (int i = 0; i < n; ++i) {
      TreeNode* node = queue.front();
      level.push_back(node->val);
      if (node->left != nullptr) {
        queue.push(node->left);
      }
      if (node->right != nullptr) {
        queue.push(node->right);
      }
      queue.pop();
    }
    ans.push_back(level);
    if (!queue.empty()) {
      Generate(queue, ans, queue.size());
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
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
      int size = queue.size();
      std::vector<int> level;
      for (int i = 0; i < size; ++i) {
        TreeNode* node = queue.front();
        queue.pop();
        level.push_back(node->val);
        if (node->left != nullptr) queue.push(node->left);
        if (node->right != nullptr) queue.push(node->right);
      }
      ans.push_back(level);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  std::string input = "[3,9,20,null,null,15,7]";
  auto root         = StringToTreeNode(input);
  Solution solution;
  auto ans = solution.levelOrder(root);
  return 0;
}