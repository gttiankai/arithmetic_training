// Given the root of a binary tree and an integer targetSum, return all root-to-
// leaf paths where the sum of the node values in the path equals targetSum.
// Each path should be returned as a list of the node values, not node
// references.
//
//  A root-to-leaf path is a path starting from the root and ending at any leaf
// node. A leaf is a node with no children.
//
//
//  Example 1:
//
//
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22
//
//
//  Example 2:
//
//
// Input: root = [1,2,3], targetSum = 5
// Output: []
//
//
//  Example 3:
//
//
// Input: root = [1,2], targetSum = 0
// Output: []
//
//
//
//  Constraints:
//
//
//  The number of nodes in the tree is in the range [0, 5000].
//  -1000 <= Node.val <= 1000
//  -1000 <= targetSum <= 1000
//
//
//  Related Topics 树 深度优先搜索 回溯 二叉树 👍 1188 👎 0
#include <tree_node.h>

#include <iostream>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> ans;
        std::vector<int> path;
        if (root == nullptr) {
            return ans;
        }
        DFSoptimize(root, targetSum, ans, path, 0);
        return ans;
    }

   private:
    void DFS(TreeNode* cur, int target, std::vector<std::vector<int>>& ans,
             std::vector<int>& path, int sum) {
        sum += cur->val;
        path.push_back(cur->val);
        if (sum == target) {
            if (cur->left == nullptr && cur->right == nullptr) {
                ans.push_back(path);
            }
        }
        if (cur->left != nullptr) {
            DFS(cur->left, target, ans, path, sum);
        }
        if (cur->right != nullptr) {
            DFS(cur->right, target, ans, path, sum);
        }
        path.pop_back();
    }
    void DFSoptimize(TreeNode* cur, int target,
                     std::vector<std::vector<int>>& ans, std::vector<int>& path,
                     int sum) {
        if (cur == nullptr) {
            return;
        }
        sum += cur->val;
        path.push_back(cur->val);
        if (sum == target && cur->left == nullptr && cur->right == nullptr) {
            ans.push_back(path);
        }
        DFSoptimize(cur->left, target, ans, path, sum);
        DFSoptimize(cur->right, target, ans, path, sum);
        path.pop_back();
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    auto root = StringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    solution.pathSum(root, 22);
    // TreeNode* root = StringToTreeNode("[-2, null, -3]");
    // solution.pathSum(root, -1);
    std::cout << "Finish build Tree" << std::endl;
}
