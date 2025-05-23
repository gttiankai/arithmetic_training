// Given the root of a binary tree, return the level order traversal of its
// nodes' values. (i.e., from left to right, level by level).
//
//
//  Example 1:
//
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
//
//
//  Example 2:
//
//
// Input: root = [1]
// Output: [[1]]
//
//
//  Example 3:
//
//
// Input: root = []
// Output: []
//
//
//
//  Constraints:
//
//
//  The number of nodes in the tree is in the range [0, 2000].
//  -1000 <= Node.val <= 1000
//
//
//  Related Topics 树 广度优先搜索 二叉树 👍 2139 👎 0
#include <iostream>
#include <queue>
#include <vector>
#include "tree_node.h"
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        TreeNode* cur;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            std::cout << "size: " << size << std::endl;
            std::vector<int> level;
            for (int i = 0; i < size; i++) {
                cur = queue.front();
                level.push_back(cur->val);
                queue.pop();
                if (cur->left != nullptr) {
                    queue.push(cur->left);
                }
                if (cur->right != nullptr) {
                    queue.push(cur->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)