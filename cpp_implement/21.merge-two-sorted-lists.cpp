/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.22%)
 * Likes:    3116
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists in a one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list
 *
 * Example 1:
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 * Example 2:
 * Input: list1 = [], list2 = []
 * Output: []
 *
 * Example 3:
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 * Constraints:
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 *
 *
 */
#include <cmath>
#include <iostream>
#include <locale>
#include <ostream>
#include <string>
#include <vector>
#include "list_node.h"

// @lc code=start
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode guard(-101);
        ListNode* ans = &guard;
        ListNode* p   = ans;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                p->next = list1;
                p       = p->next;
                list1   = list1->next;
            } else {
                p->next = list2;
                p       = p->next;
                list2   = list2->next;
            }
        }
        if (list1 != nullptr) {
            p->next = list1;
        } else {
            p->next = list2;
        }
        return ans->next;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
  ListNode* list1 = StringToListNode("[1, 2]");
  ListNode* list2 = StringToListNode("[1, 3, 4]");
  Solution solution;
  auto ans = solution.mergeTwoLists(list1, list2);
  std::cout << ListNodeToString(ans) << std::endl;

  return 0;
}
