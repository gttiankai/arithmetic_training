/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (71.29%)
 * Likes:    1832
 * Dislikes: 0
 * Total Accepted:    633.1K
 * Total Submissions: 888K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head. You
 * must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1]
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 *
 *
 */
#include <complex>
#include <ostream>
#include <ratio>
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
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* guard = new ListNode(-1);
    guard->next     = head;
    ListNode* pre   = guard;
    while (head != nullptr && head->next != nullptr) {
      AdjustNode(pre, head, head->next);
      pre  = head;
      head = head->next;
    }
    return guard->next;
  }

 private:
  void AdjustNode(ListNode* pre, ListNode* first, ListNode* second) {
    pre->next    = second;
    first->next  = second->next;
    second->next = first;
    return;
  }
};

// @lc code=end

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> test_case;
  test_case.emplace_back("[1, 2]");
  test_case.emplace_back("[1, 2, 3]");
  test_case.emplace_back("[1, 2, 3, 4]");
  for (const auto& item : test_case) {
    ListNode* root = StringToListNode(item);
    auto ans       = solution.swapPairs(root);
    std::cout << item << " swap paris: " << ListNodeToString(ans) << std::endl;
  }
  return 0;
}
