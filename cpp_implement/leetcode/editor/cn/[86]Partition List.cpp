// Given the head of a linked list and a value x, partition it such that all
// nodes less than x come before nodes greater than or equal to x.
//
//  You should preserve the original relative order of the nodes in each of the
// two partitions.
//
//
//  Example 1:
//
//
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
//
//
//  Example 2:
//
//
// Input: head = [2,1], x = 2
// Output: [1,2]
//
//
//
//  Constraints:
//
//
//  The number of nodes in the list is in the range [0, 200].
//  -100 <= Node.val <= 100
//  -200 <= x <= 200
//
//
//  Related Topics 链表 双指针 👍 903 👎 0
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
    /**
     * 这个题目的解法和思路很重要,在原链表上进行修改的方法太复杂了
     * 使用 Head 中的元素创建两个链表比较简单
     ***/
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy_small = new ListNode(0);
        ListNode* small       = dummy_small;
        ListNode* dummy_large = new ListNode(0);
        ListNode* large       = dummy_large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small       = small->next;
            } else {
                large->next = head;
                large       = large->next;
            }
            head = head->next;
        }
        small->next = dummy_large->next;
        // leetcode 的编译器会检查
        large->next = nullptr;
        return dummy_small->next;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    ListNode* head = StringToListNode("[1, 4, 3, 2, 5, 2]");
    Solution solution;
    solution.partition(head, 3);
}
