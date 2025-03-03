// Given the root of a binary tree, return the inorder traversal of its nodes'
// values.
//
//
//  Example 1:
//
//  Input: root = [1,null,2,3]
//
//  Output: [1,3,2]
//
//  Explanation:
//
//  Example 2:
//  Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
//
//
//  Output: [4,2,6,5,7,1,3,9,8]
//
//  Explanation:
//  Example 3:
//
//  Input: root = []
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
//  The number of nodes in the tree is in the range [0, 100].
//  -100 <= Node.val <= 100
//
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
//
//  Related Topics 栈 树 深度优先搜索 二叉树
//   👍 2201 👎 0
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        Inorder(root, ans);
        return ans;
    }

   private:
    void Inorder(TreeNode* root, std::vector<int>& ans) {
        if (root == nullptr) return;
        Inorder(root->left, ans);
        ans.push_back(root->val);
        Inorder(root->right, ans);
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<TreeNode*> nodes;
    nodes.push_back(StringToTreeNode("[1, null, 2, 3]"));
    nodes.push_back(StringToTreeNode("[1,2,3,4,5,null,8,null,null,6,7,9]"));
    for (auto& node : nodes) {
        std::vector<int> ans = solution.inorderTraversal(node);
        for (int i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}