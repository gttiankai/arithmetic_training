// Given a reference of a node in a connected undirected graph.
//
//  Return a deep copy (clone) of the graph.
//
//  Each node in the graph contains a value (int) and a list (List[Node]) of its
// neighbors.
//
//
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
//
//
//
//
//  Test case format:
//
//  For simplicity, each node's value is the same as the node's index
//  (1-indexed)
//. For example, the first node with val == 1, the second node with val == 2,
// and so on. The graph is represented in the test case using an adjacency list.
//
//  An adjacency list is a collection of unordered lists used to represent a
// finite graph. Each list describes the set of neighbors of a node in the
// graph.
//
//  The given node will always be the first node with val = 1. You must return
// the copy of the given node as a reference to the cloned graph.
//
//
//  Example 1:
//
//
// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
//
//
//  Example 2:
//
//
// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists
// of only one node with val = 1 and it does not have any neighbors.
//
//
//  Example 3:
//
//
// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.
//
//
//
//  Constraints:
//
//
//  The number of nodes in the graph is in the range [0, 100].
//  1 <= Node.val <= 100
//  Node.val is unique for each node.
//  There are no repeated edges and no self-loops in the graph.
//  The Graph is connected and all nodes can be visited starting from the given
// node.
//
//
//  Related Topics 深度优先搜索 广度优先搜索 图 哈希表 👍 779 👎 0

#include <queue>
#include <unordered_map>

#include "graph_node.h"
// leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraphComplex(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::queue<Node*> queue;
        std::unordered_map<int, Node*> map;
        queue.push(node);
        Node* root = nullptr;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node* cur = queue.front();
                queue.pop();
                Node* new_node = nullptr;
                if (map.find(cur->val) != map.end()) {
                    new_node = map[cur->val];
                } else {
                    new_node      = new Node(cur->val);
                    map[cur->val] = new_node;
                }
                if (root == nullptr) {
                    // only assign once
                    root = new_node;
                }
                std::vector<Node*> new_neighbors;
                for (auto& neighbor : cur->neighbors) {
                    if (map.find(neighbor->val) == map.end()) {
                        queue.push(neighbor);
                    }
                    Node* new_neighbor = nullptr;
                    if (map.find(neighbor->val) != map.end()) {
                        new_neighbor = map[neighbor->val];
                    } else {
                        new_neighbor       = new Node(neighbor->val);
                        map[neighbor->val] = new_neighbor;
                    }
                    new_neighbors.push_back(new_neighbor);
                }
                new_node->neighbors = new_neighbors;
            }
        }
        return root;
    }

   private:
    // map[node] = clone_node
    std::unordered_map<Node*, Node*> map;

   public:
    // 使用 DFS 的实现好简单
    // depth search first
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (map.find(node) != map.end()) {
            return map[node];
        }
        Node* root = new Node(node->val);
        map[node]  = root;
        for (auto& neighbor : node->neighbors) {
            root->neighbors.push_back(cloneGraph(neighbor));
        }
        return root;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Node* one        = new Node(1);
    Node* two        = new Node(2);
    Node* three      = new Node(3);
    Node* four       = new Node(4);
    one->neighbors   = {two, four};
    two->neighbors   = {one, four};
    three->neighbors = {one, four};
    four->neighbors  = {two, three};
    Node* root       = one;
    Solution solution;
    auto new_root = solution.cloneGraph(root);
}
