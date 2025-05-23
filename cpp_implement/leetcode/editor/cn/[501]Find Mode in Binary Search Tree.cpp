// Given the root of a binary search tree (BST) with duplicates, return all the
// mode(s) (i.e., the most frequently occurred element) in it.
//
//  If the tree has more than one mode, return them in any order.
//
//  Assume a BST is defined as follows:
//
//
//  The left subtree of a node contains only nodes with keys less than or equal
// to the node's key.
//  The right subtree of a node contains only nodes with keys greater than or
// equal to the node's key.
//  Both the left and right subtrees must also be binary search trees.
//
//
//
//  Example 1:
//
//
// Input: root = [1,null,2,2]
// Output: [2]
//
//
//  Example 2:
//
//
// Input: root = [0]
// Output: [0]
//
//
//
//  Constraints:
//
//
//  The number of nodes in the tree is in the range [1, 10⁴].
//  -10⁵ <= Node.val <= 10⁵
//
//
//
// Follow up: Could you do that without using any extra space? (Assume that the
// implicit stack space incurred due to recursion does not count).
//
//  Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 800 👎 0

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
     * 下面的是实现有问题
     *  bad case: [1, null, 2]
     *  答案应该是: [1, 2]
     *  但是下面的实现返回: [1], 最后的 2 加不到数组里面
     ***/
    std::vector<int> findModeWrong(TreeNode* root) {
        std::vector<int> nums;
        InOrderTraversal(root, nums);
        if (nums.size() == 1) {
            return nums;
        }
        std::vector<int> ans;
        int n         = nums.size();
        int base      = nums[0];
        int max_count = 0;
        int count     = 0;
        for (int i = 1; i < n; i++) {
            int count = 1;
            while (i < n && base == nums[i]) {
                i++;
                count++;
            }
            if (count > max_count) {
                max_count = count;
                ans.clear();
                ans.push_back(base);
            } else if (count == max_count) {
                max_count = count;
                ans.push_back(base);
            }
            if (i == n) {
                break;
            }
            base = nums[i];
        }
        return ans;
    }

    /**
     * 下面实现的思路和上面是一致的,但是实现细节有区别,所以下面的的实现可以解决
     * 上面的 bad case
     * 空间复杂度: O(N)
     * 时间复杂度: max(O(N))
     ***/
   public:
    std::vector<int> findModeON(TreeNode* root) {
        std::vector<int> nums;
        InOrderTraversal(root, nums);
        if (nums.size() == 1) {
            return nums;
        }
        std::vector<int> ans;
        int n         = nums.size();
        int base      = nums[0];
        int count     = 0;
        int max_count = 0;
        for (int i = 0; i < n; i++) {
            if (base == nums[i]) {
                count++;
            } else {
                count = 1;
                base  = nums[i];
            }
            if (count == max_count) {
                ans.push_back(base);
            }
            if (count > max_count) {
                max_count = count;
                ans.clear();
                ans.push_back(base);
            }
        }
        return ans;
    }

   private:
    void InOrderTraversal(TreeNode* root, std::vector<int>& nums) {
        if (root == nullptr) return;
        InOrderTraversal(root->left, nums);
        nums.push_back(root->val);
        InOrderTraversal(root->right, nums);
    }

   public:
    /**
     * 递归遍历本质上也是使用了栈结构,使用的栈结构是函数的递归调用栈,
     * 时间复杂度: O(N)
     * 时间复杂度: O(N)
     ***/
    std::vector<int> findModeSimple(TreeNode* root) {
        DFS(root);
        return ans;
    }

   private:
    int base      = INT_MAX;
    int count     = 0;
    int max_count = 0;
    std::vector<int> ans;

    void updata(int x) {
        if (x == base) {
            count++;
        } else {
            count = 1;
            base  = x;
        }
        if (count == max_count) {
            ans.push_back(base);
        }
        if (count > max_count) {
            max_count = count;
            ans.clear();
            ans.push_back(base);
        }
    }
    void DFS(TreeNode* root) {
        if (root == nullptr) return;
        DFS(root->left);
        updata(root->val);
        DFS(root->right);
    }

   public:
    std::vector<int> findMode(TreeNode* root) {
        // 下面的就是典型的 Morris 的实现
        TreeNode* cur = root;
        TreeNode* rightmost = nullptr;

        while (cur != nullptr) {
            if (cur -> left != nullptr) {
                rightmost = cur->left;
                while (rightmost->right != nullptr && rightmost->right != cur) {
                    rightmost = rightmost->right;
                }
                if (rightmost->right == nullptr) {
                    rightmost->right = cur;
                    cur = cur -> left;
                } else {
                    // rightmost->right == cur
                    updata(cur -> val);
                    rightmost->right = nullptr;
                    cur = cur->right;
                }

            } else {
                // 叶子节点
                updata(cur -> val);
                cur = cur -> right;
            }
        }
        return ans;
    }
};

// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    TreeNode* root = StringToTreeNode("[1,null,2, 2]");
    // TreeNode* root = StringToTreeNode("[1,null,2]");
    Solution solution;
    auto ans = solution.findMode(root);
    for (int item : ans) {
        std::cout << item << " ";
    }
}
