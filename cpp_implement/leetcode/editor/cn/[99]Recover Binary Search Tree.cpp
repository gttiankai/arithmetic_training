// You are given the root of a binary search tree (BST), where the values of
// exactly two nodes of the tree were swapped by mistake. Recover the tree
// without changing its structure.
//
//
//  Example 1:
//
//
// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
// makes the BST valid.
//
//
//  Example 2:
//
//
// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
// and 3 makes the BST valid.
//
//
//
//  Constraints:
//
//
//  The number of nodes in the tree is in the range [2, 1000].
//  -2³¹ <= Node.val <= 2³¹ - 1
//
//
//
// Follow up: A solution using
// O(n) space is pretty straight-forward. Could you devise a constant
// O(1) space solution?
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 1002 👎 0

#include <tree_node.h>

#include <iostream>
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
     * 时间复杂度:
     *      遍历部分: max( O(log(N)), O(N))
     *      总体的时间复杂度: O(N)
     * 空间复杂度:
     *      O(n)
     ***/
    void recoverTreeNormal(TreeNode* root) {
        std::vector<TreeNode*> nodes;
        InOrderTraversal(root, nodes);
        int start = -1;
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i]->val > nodes[i + 1]->val) {
                start = i;
                i++;
                while (i < nodes.size() && nodes[start]->val > nodes[i]->val) {
                    i++;
                }
                std::swap(nodes[start]->val, nodes[i - 1]->val);
                break;
            }
        }
    }

   private:
    void InOrderTraversal(TreeNode* root, std::vector<TreeNode*>& nodes) {
        if (root == nullptr) {
            return;
        }
        InOrderTraversal(root->left, nodes);
        nodes.push_back(root);
        InOrderTraversal(root->right, nodes);
    }

   public:
    /**
     * 时间复杂度:
     *      遍历部分: O(log(N))
     * 空间复杂度:
     *      O(n)
     ***/
    void recoverTreeOn(TreeNode* root) {
        InOrderTraversal(root);
        if (large != nullptr && small != nullptr) {
            std::swap(large->val, small->val);
        }
    }

   private:
    void InOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        InOrderTraversal(root->left);
        if (pre == nullptr) {
            pre = root;
        } else {
            if (pre->val < root->val) {
                pre = root;
                // do nothing
            } else {
                // get wrong index
                // 注意下面 small 和 large 的赋值都是很有讲究的
                small = root;
                if (large == nullptr) {
                    large = pre;
                }
                pre = root;
            }
        }
        InOrderTraversal(root->right);
    }
    // 下面三个参数必须作为私有变量存在,如果使用指针作为参数,在递归子函数中赋值,
    // 并不会影响上一级的参数
   private:
    TreeNode* pre   = nullptr;
    TreeNode* large = nullptr;
    TreeNode* small = nullptr;

   public:
    void recoverTree(TreeNode* root) {
        TreeNode* cur       = root;
        TreeNode* rightmost = nullptr;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                rightmost = cur->left;
                while (rightmost->right != nullptr && rightmost->right != cur) {
                    rightmost = rightmost->right;
                }
                if (rightmost->right == nullptr) {
                    rightmost->right = cur;
                    // pre              = cur;
                    cur = cur->left;
                } else {
                    // rightmost->right == cur
                    /**
                     * 遍历节点对节点进行处理的关键位置
                     ***/
                    if (pre->val > cur->val) {
                        small = cur;
                        if (large == nullptr) {
                            large = pre;
                        }
                    }
                    pre              = cur;
                    rightmost->right = nullptr;
                    cur              = cur->right;
                }
            } else {
                /**
                 * 遍历节点的关键位置
                 ***/
                if (pre != nullptr && pre->val > cur->val) {
                    small = cur;
                    if (large == nullptr) {
                        large = pre;
                    }
                }
                pre = cur;
                cur = cur->right;
            }
        }
        std::swap(large->val, small->val);
    }
};
#include <algorithm>
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> test_case;
    test_case.push_back(
        "[146,71,-13,55,null,231,399,321,null,null,null,null,null,-33]");
    test_case.push_back("[4,6,2,1,3,5,7]");
    for (auto& item : test_case) {
        auto root = StringToTreeNode(item);
        std::cout << TreeNodeToString(root) << std::endl;
        solution.recoverTree(root);
        std::cout << TreeNodeToString(root) << std::endl;
    }
}
