// You are given a perfect binary tree where all leaves are on the same level,
// and every parent has two children. The binary tree has the following
// definition:
//
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
//
//
//  Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to NULL.
//
//  Initially, all next pointers are set to NULL.
//
//
//  Example 1:
//
//
// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function
// should populate each next pointer to point to its next right node, just like
// in Figure B. The serialized output is in level order as connected by the next
// pointers, with '#' signifying the end of each level.
//
//
//  Example 2:
//
//
// Input: root = []
// Output: []
//
//
//
//  Constraints:
//
//
//  The number of nodes in the tree is in the range [0, 2¹² - 1].
//  -1000 <= Node.val <= 1000
//
//
//
//  Follow-up:
//
//
//  You may only use constant extra space.
//  The recursive approach is fine. You may assume implicit stack space does not
// count as extra space for this problem.
//
//
//  Related Topics 树 深度优先搜索 广度优先搜索 链表 二叉树 👍 1189 👎 0
#include <queue>
#include "node_utils.h"
// leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
   public:
    /**
     * 时间复杂度: O(logN)
     * 空间复杂度: O(N)
     *
     ***/
    Node* connectLevel(Node* root) {
        if (root == nullptr) return root;
        std::queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node* cur = queue.front();
                queue.pop();
                if (i == size - 1) {
                    cur->next = nullptr;
                } else {
                    cur->next = queue.front();
                }
                if (cur->left != nullptr) {
                    queue.push(cur->left);
                }
                if (cur->right != nullptr) {
                    queue.push(cur->right);
                }
            }
        }
        return root;
    }

    /**
     * 时间复杂度: O(N)
     * 空间复杂度: O(1)
     ***/
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        // leftmost 节点作为每一层的第一个 Node 保存,以便找到下一层的第一个节点
        Node* leftmost = root;
        while (leftmost->left != nullptr) {
            Node* cur = leftmost;
            while (cur != nullptr) {
                cur->left->next = cur->right;
                if (cur->next != nullptr) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
