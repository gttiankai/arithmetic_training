// Given a binary tree, find its minimum depth.
//
//  The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.
//
//  Note: A leaf is a node with no children.
//
//  Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 2
//
//  Example 2:
// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5
//  Constraints:
//  The number of nodes in the tree is in the range [0, 10⁵].
//  -1000 <= Node.val <= 1000
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1263 👎 0
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
    int minDepthComplex(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left != nullptr && root->right != nullptr) {
            return std::min(minDepthComplex(root->left), minDepthComplex(root->right)) + 1;
        } else if (root->left == nullptr && root->right == nullptr) {
            return 1;
        } else if (root->left == nullptr) {
            return minDepthComplex(root->right) + 1;
        } else {
            return minDepthComplex(root->left) + 1;
        }
    }
    /**
     * 性能和我自己实现的差不多,但是下面的实现,更清楚一点
     */
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = std::min(min_depth, minDepth(root->left));
        }
        if (root->right != nullptr) {
            min_depth = std::min(min_depth, minDepth(root->right));
        }
        return min_depth + 1;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<TreeNode*> nodes;
    nodes.push_back(StringToTreeNode("[3,9,20,null,null,15,7]"));
    nodes.push_back(StringToTreeNode("[2,null,3,null,4,null,5,null,6]"));
    for (auto& node : nodes) {
        std::cout << solution.minDepth(node) << std::endl;
    }
    return 0;
}
