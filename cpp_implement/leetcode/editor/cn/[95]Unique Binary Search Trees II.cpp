// Given an integer n, return all the structurally unique BST's (binary search
// trees), which has exactly n nodes of unique values from 1 to n. Return the
// answer in any order.
//
//
//  Example 1:
//
//
// Input: n = 3
// Output:
// [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]
//]
//
//
//  Example 2:
//
//
// Input: n = 1
// Output: [[1]]
//
//
//
//  Constraints:
//
//
//  1 <= n <= 8
//
//
//  Related Topics 树 二叉搜索树 动态规划 回溯 二叉树 👍 1615 👎 0
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
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 1) {
            return {new TreeNode(1)};
        }
        std::vector<TreeNode*> ans;
        std::vector<bool> flags(n, false);
        for (int i = 1; i <= n; i++) {
            flags[i - 1]   = true;
            TreeNode* root = new TreeNode(i);
            BackTracking(ans, n, root, flags, 1);
            root = nullptr;
        }
        return ans;
    }

   private:
    void BackTracking(std::vector<TreeNode*>& ans, int n, TreeNode* root,
                      std::vector<bool>& flags, int count) {
        if (count == n) {
            ans.push_back(root);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!flags[i]) {
                flags[i] = true;
                Insert(root, i + 1);
                BackTracking(ans, n, root, flags, count + 1);
                Delete(root, i + 1);
                flags[i] = false;
            }
        }
    }
    void Insert(TreeNode*& root, int value) {
        if (value < root->val) {
            if (root->left != nullptr) {
                Insert(root->left, value);
            } else {
                root->left = new TreeNode(value);
            }
            return;
        }
        if (value > root->val) {
            if (root->right != nullptr) {
                Insert(root->right, value);
            } else {
                root->right = new TreeNode(value);
            }
        }
    }
    void Delete(TreeNode*& root, int value) {
        if (value < root->val && root->left != nullptr) {
            if (root->left->val == value) {
                root->left = nullptr;
            } else {
                Delete(root->left, value);
            }
        }
        if (value > root->val && root->right != nullptr) {
            if (root->right->val == value) {
                root->right = nullptr;
            } else {
                Delete(root->right, value);
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    auto ans = solution.generateTrees(3);
}
