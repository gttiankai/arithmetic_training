// Given the head of a singly linked list where elements are sorted in ascending
// order, convert it to a height-balanced binary search tree.
//
//
//  Example 1:
//
//
// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the
// shown height balanced BST.
//
//
//  Example 2:
//
//
// Input: head = []
// Output: []
//
//
//
//  Constraints:
//
//
//  The number of nodes in head is in the range [0, 2 * 10⁴].
//  -10⁵ <= Node.val <= 10⁵
//
//
//  Related Topics 树 二叉搜索树 链表 分治 二叉树 👍 945 👎 0

#include <iostream>

#include "list_node.h"
#include "tree_node.h"
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBSTComplex(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }
        auto root = BuildTree(head, nullptr);
        return root;
    }

   private:
    TreeNode* BuildTree(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        auto mid    = GetMiddle(left, right);
        auto root   = new TreeNode(mid->val);
        root->left  = BuildTree(left, mid);
        root->right = BuildTree(mid->next, right);
        return root;
    }
    // 下面的快慢指针法是这个解法的关键点
    ListNode* GetMiddle(ListNode* left, ListNode* right) {
        ListNode* slow = left;
        ListNode* fast = left;
        // key point, 要到达右边的边界
        while (fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 下面的实现,只能处理最长的 List,
    ListNode* GetMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (slow == nullptr) {
                break;
            }
            fast = fast->next->next;
        }
        return slow;
    }

   public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size  = GetSize(head);
        auto root = BuildTree(head, 0, size - 1);
        return root;
    }

   private:
    /**
     * TreeNode* BuildTreeWrong(ListNode* head, int left, int right)
     * 上面是错误的实现,错误的关键点是 Head 的指针,如果只传递指针, head 在递归调用中只会在
     * 子递归函数中更新,并不会影响到父递归函数,所以起不到更新 head 头指针的目的.
     * 所以只有传递的事 Head 指针的引用,子递归函数中对 head 的修改,才会影响到父递归函数中的
     * head 指针
     ***/

    TreeNode* BuildTree(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid    = (left + right) / 2;
        auto root  = new TreeNode();
        root->left = BuildTree(head, left, mid - 1);
        root->val  = head->val;
        // key point, 这一步是真的想不到,比较精妙
        head        = head->next;
        root->right = BuildTree(head, mid + 1, right);
        return root;
    }
    int GetSize(ListNode* head) {
        int size          = 0;
        ListNode* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        return size;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    auto head = StringToListNode("[-10,-3,0,5,9]");
    auto root = solution.sortedListToBST(head);
    std::cout << "Finish build Tree" << std::endl;
    return 0;
}
