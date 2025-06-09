// Given the head of a linked list, return the node where the cycle begins. If
// there is no cycle, return null.
//
//  There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos
// is used to denote the index of the node that tail's next pointer is connected
// to (0 -indexed). It is -1 if there is no cycle. Note that pos is not passed
// as a parameter.
//
//  Do not modify the linked list.
//
//
//  Example 1:
//
//
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the
// second node.
//
//
//  Example 2:
//
//
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the
// first node.
//
//
//  Example 3:
//
//
// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
//
//
//
//  Constraints:
//
//
//  The number of the nodes in the list is in the range [0, 10⁴].
//  -10⁵ <= Node.val <= 10⁵
//  pos is -1 or a valid index in the linked-list.
//
//
//
//  Follow up: Can you solve it using O(1) (i.e. constant) memory?
//
//  Related Topics 哈希表 链表 双指针 👍 2813 👎 0
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
     * 下面的题目有一种很直接的解法:
     * 解法一:
     *     使用一个 std::unordered_set 记录已经访问过的 ListNode ,每次访问新的
     *     ListNode 时,首先在 set 中查找,该 ListNode 是否已经存在,如果没有存在,将
     *     该节点 insert 到 set 中,如果第一次出现 set 中已经存在的节点,那么这个节
     *     点就是我们要找的循环开始的节点
     * 由于题目中有进一步的要求: 空间复杂度: O(1) ,解法 1 的空间复杂度为: O(n)
     * 解法二:
     *     可以看下题目中的解题思路, 这个思路完全是数学推理
     **/
    ListNode* detectCycle(ListNode* head) {
    }
};
// leetcode submit region end(Prohibit modification and deletion)
