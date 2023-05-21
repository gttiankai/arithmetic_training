#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "tree_node.h"
/*
1. 这个题目的关键点是如何找到需要调整的两个 node
 */
/**
 * Time complexity:
 * Space complexity: O(n)
 * */
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    std::vector<TreeNode*> inorder_list;
    Inorder(root, inorder_list);

    // recover the binary search tree
    // bad case: [1, 3, null, 2]
    // bad case: [3,1,4,null,null,2]
    int left  = 0;
    int right = inorder_list.size() - 1;
    while (left < right) {
      while (inorder_list[left]->val < inorder_list[left + 1]->val) {
        left++;
      }
      //错误的原因：将代码写错了，错误的将指针进行了比较，在很多机器上无法发现,有些情况下指针和值的大小情况正好相同
      // while (inorder_list[left] < inorder_list[right]) {
      while (inorder_list[left]->val < inorder_list[right]->val) {
        right--;
      }
      int temp                 = inorder_list[left]->val;
      inorder_list[left]->val  = inorder_list[right]->val;
      inorder_list[right]->val = temp;
      break;
    }
    return;
  }

 private:
  void Inorder(TreeNode* root, std::vector<TreeNode*>& inorder_list) {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr) {
      Inorder(root->left, inorder_list);
    }
    inorder_list.push_back(root);
    if (root->right != nullptr) {
      Inorder(root->right, inorder_list);
    }
    return;
  }
};

int main(int argc, char* argv[]) {
  std::string input = "[3,1,4,null,null,2]";
  TreeNode* root = StringToTreeNode(input);
  Solution solution;
  solution.recoverTree(root);
  std::string output = TreeNodeToString(root);
  std::cout << output << std::endl;
  return 0;
}
