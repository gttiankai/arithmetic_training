#include <queue>
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
  void LevelOrderTraversal(std::queue<TreeNode *> queue, std::vector<std::vector<int>> &res) {
    std::queue<TreeNode* > sub_queue;
    std::vector<int> data ;
    while (!queue.empty()) {
      TreeNode* node;
      queue.pop();
      data.push_back(node->val);
      if (node->left != nullptr) {
        sub_queue.push(node->left);
      }
      if (node->right != nullptr) {
        sub_queue.push(node->right);
      }
    }
    res.push_back(data);
    if (!sub_queue.empty()) {
      LevelOrderTraversal(sub_queue, res);
    }
  }

  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    std::queue<TreeNode *> queue;
    queue.push(root);
    LevelOrderTraversal(queue, res);
    return res;
  }
};