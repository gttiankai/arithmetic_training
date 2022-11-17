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
#include "command_include.h"
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/**
 * 这个题目对我最大的挑战在于 List node 的计数
 * 这个题目用的是经典的算法：快慢指针法
 * */
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    int size        = 0;
    ListNode* guard = head;
    ListNode* ptr   = head;
    while (ptr != nullptr) {
      ptr = ptr->next;
      size++;
      if (size % 2 == 0) {
        guard = guard->next;
      }
    };
    return guard;
  }
};
int main(int argc, char* argv[]) {
  auto* node_5 = new ListNode(5);
  auto* node_4 = new ListNode(4, node_5);
  auto* node_3 = new ListNode(3, node_4);
  auto* node_2 = new ListNode(2, node_3);
  auto* node_1 = new ListNode(1, node_2);
  Solution solution;
  auto* middle_node = solution.middleNode(node_1);
  std::cout << middle_node->val;
}