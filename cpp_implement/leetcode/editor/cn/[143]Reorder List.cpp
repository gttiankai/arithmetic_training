// You are given the head of a singly linked-list. The list can be represented
// as:
//
//
// L0 → L1 → … → Ln - 1 → Ln
//
//
//  Reorder the list to be on the following form:
//
//
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//
//
//  You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.
//
//
//  Example 1:
//
//
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
//
//
//  Example 2:
//
//
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
//
//
//
//  Constraints:
//
//
//  The number of nodes in the list is in the range [1, 5 * 10⁴].
//  1 <= Node.val <= 1000
//
//
//  Related Topics 栈 递归 链表 双指针 👍 1601 👎 0
#include <queue>
#include <stack>
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
    /**
     * 时间复杂度: O(N)
     * 空间复杂度: O(N)
     *
     ***/
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* cur = head;
        int size      = 0;
        while (cur != nullptr) {
            size++;
            cur = cur->next;
        }
        int mid = (size + 1) / 2;
        std::queue<ListNode*> node_queue;
        cur   = head;
        int i = 0;
        while (i < mid && cur != nullptr) {
            node_queue.push(cur);
            cur = cur->next;
            i++;
        }
        std::stack<ListNode*> node_stack;
        while (cur != nullptr) {
            node_stack.push(cur);
            cur = cur->next;
        }
        i   = 0;
        cur = new ListNode(0);
        while (!node_stack.empty() && !node_queue.empty()) {
            ListNode* node;
            if (i % 2 == 0) {
                node = node_queue.front();
                node_queue.pop();
                cur->next = node;
                cur       = cur->next;
            } else {
                node = node_stack.top();
                node_stack.pop();
                cur->next = node;
                cur       = cur->next;
            }
            i++;
        }
        while (!node_queue.empty()) {
            cur->next = node_queue.front();
            node_queue.pop();
            cur       = cur->next;
            cur->next = nullptr;
        }
        while (!node_stack.empty()) {
            cur->next = node_stack.top();
            node_stack.pop();
            cur       = cur->next;
            cur->next = nullptr;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    auto head = StringToListNode("[1,2,3,4]");
    solution.reorderList(head);
}
