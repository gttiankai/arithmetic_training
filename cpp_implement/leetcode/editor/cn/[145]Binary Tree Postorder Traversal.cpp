// Given the root of a binary tree, return the postorder traversal of its nodes'
// values.
//
//
//  Example 1:
//
//
//  Input: root = [1,null,2,3]
//
//
//  Output: [3,2,1]
//
//  Explanation:
//
//
//
//  Example 2:
//
//
//  Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
//
//
//  Output: [4,6,7,5,2,9,8,3,1]
//
//  Explanation:
//
//
//
//  Example 3:
//
//
//  Input: root = []
//
//
//  Output: []
//
//  Example 4:
//
//
//  Input: root = [1]
//
//
//  Output: [1]
//
//
//  Constraints:
//
//
//  The number of the nodes in the tree is in the range [0, 100].
//  -100 <= Node.val <= 100
//
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
//
//  Related Topics 栈 树 深度优先搜索 二叉树 👍 1227 👎 0
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        Post(root, ans);
        return ans;
    }

   private:
    void Post(TreeNode* root, std::vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        Post(root->left, ans);
        Post(root->right, ans);
        ans.push_back(root->val);
    }
};
// leetcode submit region end(Prohibit modification and deletion)
