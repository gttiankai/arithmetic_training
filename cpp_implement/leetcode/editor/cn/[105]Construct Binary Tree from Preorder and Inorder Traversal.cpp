// Given two integer arrays preorder and inorder where preorder is the preorder
// traversal of a binary tree and inorder is the inorder traversal of the same
// tree,
//  construct and return the binary tree.
//
//
//  Example 1:
//
//
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
//
//
//  Example 2:
//
//
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
//
//
//
//  Constraints:
//
//
//  1 <= preorder.length <= 3000
//  inorder.length == preorder.length
//  -3000 <= preorder[i], inorder[i] <= 3000
//  preorder and inorder consist of unique values.
//  Each value of inorder also appears in preorder.
//  preorder is guaranteed to be the preorder traversal of the tree.
//  inorder is guaranteed to be the inorder traversal of the tree.
//
//
//  Related Topics 树 数组 哈希表 分治 二叉树 👍 2540 👎 0
#include <iostream>
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        int n     = preorder.size();
        auto root = CreateBT(preorder, 0, n - 1, inorder, 0, n - 1);
        return root;
    }

   private:
    TreeNode* CreateBT(std::vector<int>& preorder, int pre_left, int pre_right,
                       std::vector<int>& inorder, int in_left, int in_right) {
        if (pre_left > pre_right) {
            // 这个边界条件很重要,当 preorder 中只有一个能访问的节点时,下面的 CreateBT
            // 还是会继续 pre_left + 1, 但此时 offset 是 0 , 故 pre_left > pre_right
            return nullptr;
        }
        auto root      = new TreeNode(preorder[pre_left]);
        int root_index = map[preorder[pre_left]];
        int offset     = root_index - in_left;
        root->left     = CreateBT(preorder, pre_left + 1, pre_left + offset,
                                  inorder, in_left, root_index - 1);
        root->right    = CreateBT(preorder, pre_left + offset + 1, pre_right,
                                  inorder, root_index + 1, in_right);
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<int> preorder = {3, 9, 1, 2, 20, 15, 7};
    std::vector<int> inorder  = {1, 9, 2, 3, 15, 20, 7};
    Solution solution;
    auto root = solution.buildTree(preorder, inorder);
    std::cout << "Finish build Binary Tree" << std::endl;
}
