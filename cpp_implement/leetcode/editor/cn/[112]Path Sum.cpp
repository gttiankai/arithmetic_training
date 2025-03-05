// Given the root of a binary tree and an integer targetSum, return true if the
// tree has a root-to-leaf path such that adding up all the values along the path
// equals targetSum.
//
//  A leaf is a node with no children.
//
//  Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown.
//
//  Example 2:
// Input: root = [1,2,3], targetSum = 5
// Output: false
// Explanation: There are two root-to-leaf paths in the tree:
//(1 --> 2): The sum is 3.
//(1 --> 3): The sum is 4.
// There is no root-to-leaf path with sum = 5.
//
//  Example 3:
// Input: root = [], targetSum = 0
// Output: false
// Explanation: Since the tree is empty, there are no root-to-leaf paths.
//
//
//  Constraints:
//
//  The number of nodes in the tree is in the range [0, 5000].
//  -1000 <= Node.val <= 1000
//  -1000 <= targetSum <= 1000
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1428 👎 0

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
     *  找到所有的 root-to-leaf, 然后计算所有的 sum, 再在结果中查找是否有 target sum
     *
     *  使用 DFS 算法,直接一次性过了.
     **/
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        std::vector<int> sum_vector;
        DFS(root, 0, sum_vector);
        for (int i = 0; i < sum_vector.size(); i++) {
            if (sum_vector[i] == targetSum) {
                return true;
            }
        }
        return false;
    }

   private:
    void DFS(TreeNode* root, int parent_sum, std::vector<int>& sume_vector) {
        if (root == nullptr) {
            return;
        }
        int carry = parent_sum + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sume_vector.push_back(carry);
        }
        if (root->left != nullptr) {
            DFS(root->left, carry, sume_vector);
        }
        if (root->right != nullptr) {
            DFS(root->right, carry, sume_vector);
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
