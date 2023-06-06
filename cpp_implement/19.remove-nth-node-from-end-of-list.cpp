/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (45.57%)
 * Likes:    2553
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include "list_node.h"
class SolutionUgly {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count   = 0;
    ListNode* p = head;
    while (p != nullptr) {
      count++;
      p = p->next;
    }
    p          = head;
    int target = count - n;
    if (target == 0) {
      return head->next;
    }
    for (int i = 0; i < target - 1; ++i) {
      p = p->next;
    }
    if (p->next != nullptr) {
      p->next = p->next->next;
    } else {
      p->next = nullptr;
    }
    return head;
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
/**
 * 关键点:使用 dummy 节点简化计算
 * */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count   = 0;
    ListNode* p = head;
    while (p != nullptr) {
      count++;
      p = p->next;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next     = head;
    p               = dummy;
    int target      = count - n;
    // 注意遍历时的结束条件和下标的关系
    for (int i = 0; i < target; ++i) {
      p = p->next;
    }
    p->next = p->next->next;
    return dummy->next;
  }
};

// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;

  std::vector<std::string> test_case;
  std::vector<int> nums;
  test_case.push_back("[1]");
  nums.push_back(1);
  test_case.push_back("[1,2,3,4,5]");
  nums.push_back(2);

  for (int i = 0; i < test_case.size(); ++i) {
    std::cout << test_case[i] << " remove " << nums[i] << " node: ";
    ListNode* root = StringToListNode(test_case[i]);
    std::cout << ListNodeToString(solution.removeNthFromEnd(root, nums[i])) << std::endl;
  }
  return 0;
}
