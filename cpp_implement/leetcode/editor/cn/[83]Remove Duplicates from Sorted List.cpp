//Given the head of a sorted linked list, delete all duplicates such that each 
//element appears only once. Return the linked list sorted as well. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,1,2]
//Output: [1,2]
// 
//
// Example 2: 
// 
// 
//Input: head = [1,1,2,3,3]
//Output: [1,2,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 300]. 
// -100 <= Node.val <= 100 
// The list is guaranteed to be sorted in ascending order. 
// 
//
// Related Topics 链表 
// 👍 1188 👎 0

#include <iostream>
#include "list_node.h"


//leetcode submit region begin(Prohibit modification and deletion)
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 问题的关键是: Head 是有序的
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev    = head;
        ListNode* current = prev->next;
        while (current != nullptr) {
            if (prev->val == current->val) {
                //  delete current node
                prev->next = current->next;
                current->next = nullptr;
                current = prev->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char const *argv[]) {
    ListNode* head = StringToListNode("[1,2,2,3,3]");
    Solution solution;
    std::cout <<"original " << ListNodeToString(head);
    auto ans = solution.deleteDuplicates(head);
    std::cout <<"process " << ListNodeToString(ans) << std::endl;
    return 0;
}