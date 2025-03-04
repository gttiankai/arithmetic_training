// Given an integer array nums where the elements are sorted in ascending order,
// convert it to a height-balanced binary search tree.
//
//
//  Example 1:
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:
//
//  Example 2:
// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
//
//  Constraints:
//  1 <= nums.length <= 10⁴
//  -10⁴ <= nums[i] <= 10⁴
//  nums is sorted in a strictly increasing order.
//
//
//  Related Topics 树 二叉搜索树 数组 分治 二叉树 👍 1623 👎 0
#include "tree_node.h"

#include <vector>

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return CreateBST(nums, 0, nums.size() -1);
    }

   private:
    TreeNode* CreateBST(std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        // 选择中间节点左边的位置为根节点
        int mid = left + (right - left ) / 2;
        // 如果选择中间位置右边的数字作为根节点
        // int mid = left + (right - left + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = CreateBST(nums, left, mid - 1);
        root->right = CreateBST(nums, mid + 1, right);
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
