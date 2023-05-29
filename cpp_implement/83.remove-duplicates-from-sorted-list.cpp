/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (53.11%)
 * Likes:    992
 * Dislikes: 0
 * Total Accepted:    577.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,2]'
 *
 * Given the head of a sorted linked list, delete all duplicates such that each
 * element appears only once. Return the linked list sorted as well.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,1,2]
 * Output: [1,2]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
 *
 *
 */
#include <iostream>
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
class SolutionO0 {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr) {
      if (slow->val != fast->val) {
        slow      = slow->next;
        slow->val = fast->val;
      }
      fast = fast->next;
    }
    slow->next = nullptr;
    return head;
  }
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode* cur = head;
    while (cur != nullptr) {
      if (cur->next == nullptr) {
        break;
      }
      if (cur->val == cur->next->val) {
        DeleteNode(cur, cur->next);
      } else {
        cur = cur->next;
      }
    }
    return head;
  }

 private:
  void DeleteNode(ListNode* pre_node, ListNode* node) {
    pre_node->next = node->next;
    node->next     = nullptr;
    delete node;
  }
};
// @lc code=end

int main(int argc, char*[]) {
  std::vector<std::string> test_case;
  test_case.push_back("[1,1,2,3,3]");
  test_case.push_back("[]");
  test_case.push_back("[1]");
  test_case.push_back("[1,1,1]");  // failed test case
  Solution solution;
  for (const auto& test : test_case) {
    ListNode* root = StringToListNode(test);
    solution.deleteDuplicates(root);
    std::string output = ListNodeToString(root);
    std::cout << test << " vs " << output << std::endl;
  }
}
