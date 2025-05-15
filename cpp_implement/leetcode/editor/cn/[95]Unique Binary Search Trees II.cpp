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
   public:
    /**
     * 下面的解法有问题,添加节点之后后面再删除,导致最后 ans
     * 中的二叉树只有一个根节点
     * 下面的方案的完全不能修改
     ***/
    std::vector<TreeNode*> generateTreesWrong(int n) {
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
    // 下面的解法是从上到下构建一棵树,但是 root 下面有两种不同的形式,这就导致了不能正确的解决
    // 题目
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

   public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 1) {
            return {new TreeNode(1)};
        }
        return BackTracking(1, n);
    }

   private:
    std::vector<TreeNode*> BackTracking(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        // 第二个隐藏你的点, 这个 ans 并不通过参数传递到底层,这就保证了上面的解法的 root
        // 由于传递到叶子结点,导致出现问题的现象
        std::vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            std::vector<TreeNode*> left_trees  = BackTracking(start, i - 1);
            std::vector<TreeNode*> right_trees = BackTracking(i + 1, end);
            for (const auto& left : left_trees) {
                for (const auto& right : right_trees) {
                    // 第一个精妙的点, 从叶子到根部创建每一个节点
                    TreeNode* root = new TreeNode(i);
                    root->left     = left;
                    root->right    = right;
                    ans.emplace_back(root);
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    auto ans = solution.generateTrees(3);
    for (auto root : ans) {
        std::cout << TreeNodeToString(root) << std::endl;
    }
}
