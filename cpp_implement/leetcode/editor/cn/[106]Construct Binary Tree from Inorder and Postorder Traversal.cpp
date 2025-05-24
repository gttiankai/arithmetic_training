// Given two integer arrays inorder and postorder where inorder is the inorder
// traversal of a binary tree and postorder is the postorder traversal of the
// same tree, construct and return the binary tree.
//
//
//  Example 1:
//
//
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
//
//
//  Example 2:
//
//
// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
//
//
//
//  Constraints:
//
//
//  1 <= inorder.length <= 3000
//  postorder.length == inorder.length
//  -3000 <= inorder[i], postorder[i] <= 3000
//  inorder and postorder consist of unique values.
//  Each value of postorder also appears in inorder.
//  inorder is guaranteed to be the inorder traversal of the tree.
//  postorder is guaranteed to be the postorder traversal of the tree.
//
//
//  Related Topics 树 数组 哈希表 分治 二叉树 👍 1340 👎 0

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
   private:
    std::unordered_map<int, int> map;

   public:
    TreeNode* buildTree(std::vector<int>& inorder,
                        std::vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        int n     = inorder.size();
        auto root = CreateBT(postorder, 0, n - 1, inorder, 0, n - 1);
        return root;
    }
    TreeNode* CreateBT(std::vector<int> postorder, int post_left,
                       int post_right, std::vector<int>& inorder, int in_left,
                       int in_right) {
        if (post_left > post_right) {
            return nullptr;
        }
        auto root     = new TreeNode(postorder[post_right]);
        int in_index  = map[postorder[post_right]];
        int in_offset = in_right - in_index;
        root->left  = CreateBT(postorder, post_left, post_right - in_offset - 1,
                               inorder, in_left, in_index - 1);
        root->right = CreateBT(postorder, post_right - in_offset,
                               post_right - 1, inorder, in_index + 1, in_right);
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
