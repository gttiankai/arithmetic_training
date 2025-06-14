// Design a data structure that follows the constraints of a Least Recently Used
//(LRU) cache.
//
//  Implement the LRUCache class:
//
//
//  LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//
//  int get(int key) Return the value of the key if the key exists, otherwise
// return -1.
//  void put(int key, int value) Update the value of the key if the key exists.
// Otherwise, add the key-value pair to the cache. If the number of keys exceeds
// the capacity from this operation, evict the least recently used key.
//
//
//  The functions get and put must each run in O(1) average time complexity.
//
//
//  Example 1:
//
//
// Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
//
//
//
//  Constraints:
//
//
//  1 <= capacity <= 3000
//  0 <= key <= 10⁴
//  0 <= value <= 10⁵
//  At most 2 * 10⁵ calls will be made to get and put.
//
//
//  Related Topics 设计 哈希表 链表 双向链表 👍 3513 👎 0
#include <unordered_map>

// leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
   private:
    struct Node {
        int key;
        int val;
        Node* pre;
        Node* next;
        Node(int key, int val)
            : key(key), val(val), pre(nullptr), next(nullptr) {};
        Node(int key, int val, Node* pre, Node* next)
            : key(key), val(val), pre(pre), next(next) {};
    };
    std::unordered_map<int, Node*> map;
    Node* dummpy_head;
    Node* dummpy_tail;
    int capacity_;
    int count_;

   public:
    LRUCache(int capacity) {
        capacity_         = capacity;
        count_            = 0;
        dummpy_head       = new Node(-1, -1);
        dummpy_tail       = new Node(-1, -1);
        dummpy_head->next = dummpy_tail;
        dummpy_tail->pre  = dummpy_head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node* cur = map[key];
        move_to_head(cur);
        return cur->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* cur = map[key];
            cur->val  = value;
            move_to_head(cur);
            return;
        }
        // inser new node
        if (count_ >= capacity_) {
            remove_tail();
        }
        Node* node = new Node(key, value);
        inser_node(node);
        map[key] = node;
    }

   private:
    void move_to_head(Node* node) {
        Node* pre  = node->pre;
        Node* next = node->next;
        pre->next  = next;
        next->pre  = pre;

        node->pre  = dummpy_head;
        node->next = dummpy_head->next;
        // 开始实现时忘记了下面这行代码,导致很多错误
        dummpy_head->next->pre = node;
        dummpy_head->next      = node;
    }
    void remove_tail() {
        Node* remove_node = dummpy_tail->pre;
        Node* pre         = remove_node->pre;
        pre->next         = dummpy_tail;
        dummpy_tail->pre  = pre;
        // map.erase 需要 key 才可以,这就是为什么 struct 里面需要添加 key 属性
        map.erase(remove_node->key);
        count_--;
        delete remove_node;
    }
    void inser_node(Node* node) {
        node->next        = dummpy_head->next;
        node->pre         = dummpy_head;
        dummpy_head->next = node;
        node->next->pre   = node;
        count_++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);
    cache.put(3, 3);
    cache.get(2);
    cache.put(4, 4);
    cache.get(1);
    cache.get(3);
    cache.get(4);
}
