// Given the head of a singly linked list and two integers left and right where
// left <= right, reverse the nodes of the list from position left to position
// right, and return the reversed list.
//
//
//  Example 1:
//
//
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
//
// 6
//  Example 2:
//
//
// Input: head = [5], left = 1, right = 1
// Output: [5]
//
//
//
//  Constraints:
//
//
//  The number of nodes in the list is n.
//  1 <= n <= 500
//  -500 <= Node.val <= 500
//  1 <= left <= right <= n
//
//
//
// Follow up: Could you do it in one pass?
//
//  Related Topics 链表 👍 1966 👎 0

#include <algorithm>
#include <vector>
#include "list_node.h"
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
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode* p = head;
        for (int i = 1; i < left; i++) {
            p = p->next;
        }
        ListNode* q = p->next;
        for (int i = 1; i < (right - left); i++) {
            q = q->next;
        }
        // reverse list node from p to q
        std::vector<int> nums;
        ListNode* k = p;
        while (k != q) {
            nums.push_back(k->val);
            k = k->next;
        }
        nums.push_back(q->val);
        k = p;
        for (int i = nums.size() - 1; i >= 0; i--) {
            k->val = nums[i];
            k      = k->next;
        }
        return head;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
