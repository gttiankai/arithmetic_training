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
 *
 * Example 1:
 *
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: list1 = [], list2 = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
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

/**
    这个版本的实现是正确的,但是实现的不够优雅,太丑了
 */
class SolutionUgly {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* root = nullptr;
    if (list1 == nullptr) {
      return list2;
    } else if (list2 == nullptr) {
      return list1;
    }
    // list1 != nullptr && list2 != nullptr
    if (list1->val <= list2->val) {
      root  = list1;
      list1 = list1->next;
    } else {
      root  = list2;
      list2 = list2->next;
    }
    ListNode* guard = root;
    while (list1 != nullptr || list2 != nullptr) {
      if (list1 == nullptr) {
        guard->next = list2;
        break;
      } else if (list2 == nullptr) {
        guard->next = list1;
        break;
      } else {
        if (list1->val <= list2->val) {
          guard->next = list1;
          guard       = guard->next;
          list1       = list1->next;
        } else {
          guard->next = list2;
          guard       = guard->next;
          list2       = list2->next;
        }
      }
    }
    return root;
  }
};
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
    ListNode pre_node(-1);
    ListNode* guard = &pre_node;

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        guard->next = list1;
        guard       = guard->next;
        list1       = list1->next;
      } else {
        guard->next = list2;
        guard       = guard->next;
        list2       = list2->next;
      }
    }
    if (list1 == nullptr) {
      guard->next = list2;
    } else {
      guard->next = list1;
    }
    return pre_node.next;
  }
};
// TODO: 实现递归版本
// TODO: 实现迭代的版本
// @lc code=end

int main(int argc, char* argv[]) {
  ListNode* list1 = StringToListNode("[1, 2]");
  ListNode* list2 = StringToListNode("[1, 3, 4]");
  Solution solution;
  auto ans = solution.mergeTwoLists(list1, list2);
  std::cout << ListNodeToString(ans) << std::endl;

  return 0;
}
