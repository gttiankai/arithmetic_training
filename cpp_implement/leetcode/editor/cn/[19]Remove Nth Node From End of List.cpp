/**
Given the head of a linked list, remove the nᵗʰ node from the end of the list
and return its head.


 Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


 Example 2:


Input: head = [1], n = 1
Output: []


 Example 3:


Input: head = [1,2], n = 1
Output: [1]



 Constraints:


 The number of nodes in the list is sz.
 1 <= sz <= 30
 0 <= Node.val <= 100
 1 <= n <= sz



 Follow up: Could you do this in one pass?

 Related Topics 链表 双指针 👍 3094 👎 0

*/
#include <iostream>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size  = GetListSize(head);
        int index = size - n;
        // 处理特殊的 case
        if (index == 0) {
            return head->next;
        }
        int i       = 1;
        ListNode* p = head;
        while (i < index) {
            p = p->next;
            i++;
        }
        // remo the node
        ListNode* q = p->next;
        if (q != nullptr) {
            p->next = q->next;
            q->next = nullptr;
        } else {
            p->next = nullptr;
        }
        return head;
    }

   private:
    int GetListSize(ListNode* head) {
        int n = 0;
        while (head != nullptr) {
            n++;
            head = head->next;
        }
        return n;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> test_case;
    std::vector<int> index;
    test_case.push_back("[1,2,3,4,5]");
    index.push_back(1);
    //  这个特殊的 case 应该如何解决呢?
    test_case.push_back("[1]");
    index.push_back(1);
    for (int i = 0; i < test_case.size(); ++i) {
        ListNode* head = StringToListNode(test_case[i]);
        head           = solution.removeNthFromEnd(head, index[i]);
        std::cout << ListNodeToString(head) << std::endl;
    }
    return 0;
}
