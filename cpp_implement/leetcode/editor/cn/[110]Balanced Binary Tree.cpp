// Given a binary tree, determine if it is height-balanced.
//
//  Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true
//
//  Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
//
//  Example 3:
// Input: root = []
// Output: true
//
//  Constraints:
//  The number of nodes in the tree is in the range [0, 5000].
//  -10⁴ <= Node.val <= 10⁴
//
//  Related Topics 树 深度优先搜索 二叉树 👍 1581 👎 0
#include <iostream>

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool is_balanced = isBalanced(root->left) && isBalanced(root->right);
        if (!is_balanced) {
            return false;
        }
        int left_depth  = MaxDepth(root->left);
        int right_depth = MaxDepth(root->right);
        is_balanced     = std::abs(left_depth - right_depth) <= 1 ? true : false;
        return is_balanced;
    }

   private:
    int MaxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<TreeNode*> nodes;
    nodes.push_back(StringToTreeNode("[3,9,20,null,null,15,7]"));
    for (auto& node : nodes) {
        std::cout << TreeNodeToString(node) << " balanced: ";
        std::cout << solution.isBalanced(node) << std::endl;
    }
}
