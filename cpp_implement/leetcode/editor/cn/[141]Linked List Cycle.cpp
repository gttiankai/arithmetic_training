// Given head, the head of a linked list, determine if the linked list has a
// cycle in it.
//
//  There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos is
// used to denote the index of the node that tail's next pointer is connected to.
// Note that pos is not passed as a parameter.
//
//  Return true if there is a cycle in the linked list. Otherwise, return false.
//
//
//  Example 1:
//
//
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to
// the 1st node (0-indexed).
//
//
//  Example 2:
//
//
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to
// the 0th node.
//
//
//  Example 3:
//
//
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
//
//
//
//  Constraints:
//
//  The number of the nodes in the list is in the range [0, 10⁴].
//  -10⁵ <= Node.val <= 10⁵
//  pos is -1 or a valid index in the linked-list.
//
//
//  Follow up: Can you solve it using O(1) (i.e. constant) memory?
//
//   Related Topics 哈希表 链表 双指针 👍 2293 👎 0
#include <cstddef>
#include <unordered_set>
#include "list_node.h"

// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    /**
     * Hash_map
     * 一开始我有个思维的误区,认为如果 ListNote 中的 value 是重复的,那么使用 hash map 的方式
     * 是没有办法区分重复的,但是我的想法是错误的,hash_map 存储的是 ListNote* ,也就是指针,及时
     * ListNode 的 value 是相同的,但是两个 ListNode 的地址是不同的,所以 Hash_map 是可以区分的
     *
     * 代码中频繁使用了 unordered_set 的查找算法, 查找算法的最好的时间复杂度是 O(1) ,最坏的
     * 时间复杂度是:O(N)
     * 所以基于 HashMap 的算法没有没有 Floyd 算法快
     */
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode *> nodes;
        while (head != nullptr) {
            if (nodes.find(head) != nodes.end()) {
                return true;
            }
            nodes.insert(head);
            head = head->next;
        }
        return false;
    }
    /**
       准备使用 Floyd 判圈算法
     **/
    bool hasCycleFloyd(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
