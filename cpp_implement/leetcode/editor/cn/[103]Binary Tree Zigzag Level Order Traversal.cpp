// Given the root of a binary tree, return the zigzag level order traversal of
// its nodes' values. (i.e., from left to right, then right to left for the next
// level and alternate between).
//
//
//  Example 1:
//
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
//
//
//  Example 2:
//
//
// Input: root = [1]
// Output: [[1]]
//
//
//  Example 3:
//
//
// Input: root = []
// Output: []
//
//
//
//  Constraints:
//
//
//  The number of nodes in the tree is in the range [0, 2000].
//  -100 <= Node.val <= 100
//
//
//  Related Topics 树 广度优先搜索 二叉树 👍 964 👎 0
#include <deque>
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
     * 这个题目本质上和 102 题是一样的,只是增加了一个双端队列
     ***/
    std::vector<std::vector<int>> zigzagLevelOrderComplex(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        std::deque<TreeNode*> queue;
        queue.push_back(root);
        int count = 0;
        while (!queue.empty()) {
            int size = queue.size();
            std::vector<int> level;
            for (int i = 0; i < size; i++) {
                if (count % 2 == 0) {
                    // from left to right
                    TreeNode* node = queue.front();
                    queue.pop_front();
                    level.push_back(node->val);
                    if (node->left != nullptr) {
                        queue.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        queue.push_back(node->right);
                    }
                } else {
                    // from right to left
                    TreeNode* node = queue.back();
                    queue.pop_back();
                    level.push_back(node->val);
                    // 下面先处理 right,在处理 left 是关键的位置
                    if (node->right != nullptr) {
                        queue.push_front(node->right);
                    }
                    if (node->left != nullptr) {
                        queue.push_front(node->left);
                    }
                }
            }
            count++;
            ans.push_back(level);
        }
        return ans;
    }

    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        std::queue<TreeNode*> queue;
        bool left_to_right = true;
        while (!queue.empty()) {
            std::deque<int> level;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                auto cur = queue.front();
                queue.pop();
                if (left_to_right) {
                    level.push_back(cur->val);
                } else {
                    level.push_front(cur->val);
                }
                if (cur->left != nullptr) {
                    queue.push(cur->left);
                }
                if (cur->right != nullptr) {
                    queue.push(cur->right);
                }
            }
            ans.emplace_back(std::vector<int>(level.begin(), level.end()));
            left_to_right = !left_to_right;
        }

        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> test_case;
    test_case.push_back("[3,9,20,null,null,15,7]");
    for (auto& item : test_case) {
        auto root = StringToTreeNode(item);
        auto ans  = solution.zigzagLevelOrder(root);
        for (int i = 0; i < ans.size(); i++) {
            std::cout << "[";
            for (int j = 0; j < ans[i].size(); j++) {
                std::cout << ans[i][j] << " ";
            }
            std::cout << "]\n";
        }
    }
}
