// Given the head of a linked list, rotate the list to the right by k places.
//
//
//  Example 1:
//
//
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
//
//
//  Example 2:
//
//
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
//
//
//
//  Constraints:
//
//
//  The number of nodes in the list is in the range [0, 500].
//  -100 <= Node.val <= 100
//  0 <= k <= 2 * 10⁹
//
//
//  Related Topics 链表 双指针 👍 1134 👎 0

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
    /****/
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = head;
        int count   = 0;
        while (p != nullptr) {
            count++;
            p = p->next;
        }
        if (count == 1) {
            return head;
        }
        k     = k % count;
        // k == 0 代表旋转 0 个, 或者是旋转 count 个,
        if (k == 0) {
            return head;
        }
        int m = count - k;
        p     = head;
        while (m > 1) {
            p = p->next;
            m--;
        }
        head    = p->next;
        p->next = nullptr;
        p       = head;
        while (k > 1) {
            p = p->next;
            k--;
        }
        p->next = q;
        return head;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    ListNode* head = StringToListNode("[1, 2]");
    Solution solution;
    solution.rotateRight(head, 2);
}
