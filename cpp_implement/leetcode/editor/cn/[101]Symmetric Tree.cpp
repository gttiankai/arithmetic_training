// Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
//  symmetric around its center).
//
//  Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true
//
//  Example 2:
//
// Input: root = [1,2,2,null,3,null,3]
// Output: false
//
//  Constraints:
//  The number of nodes in the tree is in the range [1, 1000].
//  -100 <= Node.val <= 100
// Follow up: Could you solve it both recursively and iteratively?

#include <algorithm>
#include <iostream>
#include <string>
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
    /**
     *  之前担心的问题出现了，只使用中序遍历之后获得的数组，不能保证是镜像的
     *
     */
    bool isSymmetricWrong(TreeNode* root) {
        std::vector<int> values;
        InorderTraversal(root, values);
        if (values.size() == 1) {
            return true;
        }
        int count = values.size();
        // 如果返回的数组的 size 是偶数，直接返回
        if (count % 2 == 0) {
            return false;
        }
        std::vector<int> reverse_values = values;
        std::reverse(reverse_values.begin(), reverse_values.end());
        for (int i = 0; i < count; i++) {
            if (reverse_values[i] != values[i]) {
                return false;
            }
        }
        return true;
    }

   private:
    void InorderTraversal(TreeNode* node, std::vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        InorderTraversal(node->left, values);
        values.push_back(node->val);
        InorderTraversal(node->right, values);
    }

   public:
    /**
     * 类似于这种判断二叉树的用递归进行解题是比较好的思路
     */
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left, root->right);
    }

    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left == nullptr || right == nullptr) {
            return false;
        }
        // left != nullptr and right != nullptr;
        if (left->val != right->val) {
            return false;
        }
        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<TreeNode*> test_cases;
    test_cases.push_back(StringToTreeNode("[1,2,2,2,null,2]"));
    test_cases.push_back(StringToTreeNode("[1,2,2,3,4,4,3]"));
    test_cases.push_back(StringToTreeNode("[1,2,2,null,3,null,3]"));
    Solution solution;
    for (auto case_ : test_cases) {
        bool is_symmetric = solution.isSymmetric(case_);
        std::cout << TreeNodeToString(case_) << " is symmetric: " << is_symmetric << std::endl;
    }
}
