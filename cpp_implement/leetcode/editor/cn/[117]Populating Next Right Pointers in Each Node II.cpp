// Given a binary tree
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
// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should
// populate each next pointer to point to its next right node, just like in
// Figure B. The serialized output is in level order as connected by the next
// pointers, with
//'#' signifying the end of each level.
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
//  The number of nodes in the tree is in the range [0, 6000].
//  -100 <= Node.val <= 100
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
//  Related Topics 树 深度优先搜索 广度优先搜索 链表 二叉树 👍 915 👎 0

#include <sys/syslimits.h>

#include <algorithm>

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
     * 使用层次遍历是可以轻松的解决的, 但是有没有时间复杂度是 O(1) 的解法呢?
     *
     ***/
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        Node* cur = root;
        while (cur != nullptr) {
            Node* first_node = cur;
            for (Node* p = cur; p != nullptr; p = p->next) {
                if (p->left != nullptr) {
                    if (p->right != nullptr) {
                        p->left->next = p->right;
                    } else {
                        Node* q = p;
                        while (q->next != nullptr) {
                            if (q->next->left != nullptr) {
                                p->left->next = q->next->left;
                                break;
                            }
                            if (q->next->right != nullptr) {
                                p->left->next = q->next->right;
                                break;
                            }
                            q = q->next;
                        }
                    }
                }
                if (p->right != nullptr) {
                    Node* q = p;
                    while (q->next != nullptr) {
                        if (q->next->left != nullptr) {
                            p->right->next = q->next->left;
                            break;
                        }
                        if (q->next->right != nullptr) {
                            p->right->next = q->next->right;
                            break;
                        }
                        q = q->next;
                    }
                }
            }
            while (first_node != nullptr) {
                if (first_node->left != nullptr) {
                    cur = first_node->left;
                    break;
                }
                if (first_node->right != nullptr) {
                    cur = first_node->right;
                    break;
                }
                first_node = first_node->next;
                cur        = first_node;
            }
        }
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    // Node* root = StringToNode("[1,2,3,4,5,null,7]");
    // Node* root = StringToNode("[1,2,3,4,5,null,6,7,null,null,null,null,8]");
    Node* root = StringToNode("[1,2,3,4,5]");
    solution.connect(root);
}
