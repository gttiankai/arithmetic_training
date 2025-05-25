// Given the root of a binary tree, return the bottom-up level order traversal
// of its nodes' values. (i.e., from left to right, level by level from leaf to
// root)
//.
//
//
//  Example 1:
//
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
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
//  Related Topics 树 广度优先搜索 二叉树 👍 836 👎 0
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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
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
                TreeNode* cur = queue.front();
                queue.pop();
                level.push_back(cur->val);
                if (cur->left != nullptr) {
                    queue.push(cur->left);
                }
                if (cur->right != nullptr) {
                    queue.push(cur->right);
                }
            }
            ans.push_back(level);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
