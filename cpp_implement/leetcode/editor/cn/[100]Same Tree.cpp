// Given the roots of two binary trees p and q, write a function to check if
// they are the same or not.
//
//  Two binary trees are considered the same if they are structurally identical,
// and the nodes have the same value.
//
//
//  Example 1:
//
//
// Input: p = [1,2,3], q = [1,2,3]
// Output: true
//
//
//  Example 2:
//
//
// Input: p = [1,2], q = [1,null,2]
// Output: false
//
//
//  Example 3:
//
//
// Input: p = [1,2,1], q = [1,1,2]
// Output: false
//
//
//
//  Constraints:
//
//
//  The number of nodes in both trees is in the range [0, 100].
//  -10⁴ <= Node.val <= 10⁴
//
//
//   Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1209 👎 0
#include <iostream>
#include <queue>
#include <stack>
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
    // Depth First Search
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else {
            // p-val == q->val
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
    /**
     * Breath First Search
     * 这个实现就有点太复杂了,不如 DFS 简单
     */
    bool isSameTreeHard(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }
        std::queue<TreeNode*> queue_for_p;
        std::queue<TreeNode*> queue_for_q;
        queue_for_p.push(p);
        queue_for_q.push(q);
        while (!queue_for_p.empty() && !queue_for_q.empty()) {
            auto node_for_p = queue_for_p.front();
            queue_for_p.pop();
            auto node_for_q = queue_for_q.front();
            queue_for_q.pop();
            if (node_for_p->val != node_for_q->val) {
                return false;
            }
            if ((node_for_p->left == nullptr) ^ (node_for_q->left == nullptr)) {
                return false;
            }
            if ((node_for_p->right == nullptr) ^ (node_for_q->right == nullptr)) {
                return false;
            }
            if (node_for_p->left != nullptr) {
                queue_for_p.push(node_for_p->left);
            }
            if (node_for_q->left != nullptr) {
                queue_for_q.push(node_for_q->left);
            }
            if (node_for_p->right != nullptr) {
                queue_for_p.push(node_for_p->right);
            }
            if (node_for_q->right != nullptr) {
                queue_for_q.push(node_for_q->right);
            }
        }
        return queue_for_p.empty() && queue_for_q.empty();
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<TreeNode*> test_cases_for_p;
    test_cases_for_p.push_back(StringToTreeNode("[10,5,15]"));
    test_cases_for_p.push_back(StringToTreeNode("[1, 2, 3]"));
    test_cases_for_p.push_back(StringToTreeNode("[1, 2]"));
    test_cases_for_p.push_back(StringToTreeNode("[1, 2, 1]"));
    std::vector<TreeNode*> test_cases_for_q;
    test_cases_for_q.push_back(StringToTreeNode("[10,5,null,null,15]"));
    test_cases_for_q.push_back(StringToTreeNode("[1, 2, 3]"));
    test_cases_for_q.push_back(StringToTreeNode("[1, null, 2]"));
    test_cases_for_q.push_back(StringToTreeNode("[1, 1, 2]"));
    for (int i = 0; i < test_cases_for_p.size(); ++i) {
        std::cout << TreeNodeToString(test_cases_for_p[i]) << " vs ";
        std::cout << TreeNodeToString(test_cases_for_q[i]) << ": ";
        bool is_same = solution.isSameTree(test_cases_for_p[i], test_cases_for_q[i]);
        std::cout << is_same << std::endl;
    }
}