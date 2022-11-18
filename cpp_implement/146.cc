/**
请你设计并实现一个满足 LRU (最近最少使用) 缓存约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value)如果关键字 key 已经存在，则变更其数据值value ；如果不存在，则向缓存中插入该组key-value 。
如果插入操作导致关键字数量超过capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
示例：
  输入
  ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
  [[2], [1, 0], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
  输出
  [null, null, null, 1, null, -1, null, -1, 3, 4]

解释
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4

提示：
    1 <= capacity <= 3000
    0 <= key <= 10000
    0 <= value <= 105
   最多调用 2 * 105 次 get 和 put
 ***/
#include "command_include.h"
/**
 * 在做这个题目中易错的点：
 * 1. 创建双向链表最好是创建 head 和 tail 两个伪节点，
 * 2. 调整双向链表时需要调整 4 条指针链， 这一点尤其需要注意
 * 3. 删除 map 中的节点是按照 key 进行删除的，所以 struct 结构体中需要保存 key 的值
 * 4. 还要注意具体的删除节点的顺序
 *
 *
 *
 * **/

class LRUCache {
 public:
  LRUCache(int capacity) {
    size            = 0;
    capacity_       = capacity;
    head            = new Node();
    head->key       = -1;
    head->value     = -1;
    tail            = new Node();
    tail->key       = -1;
    tail->value     = -1;
    head->pre_node  = nullptr;
    head->next_node = tail;
    tail->pre_node  = head;
    tail->next_node = nullptr;
  }

  int get(int key) {
    if (cache_map_.find(key) == cache_map_.end()) {
      return -1;
    }
    Node* node      = cache_map_[key];
    Node* pre_node  = node->pre_node;
    Node* next_node = node->next_node;
    // older position
    pre_node->next_node = next_node;
    next_node->pre_node = pre_node;

    // insert node to head
    node->pre_node            = head;
    node->next_node           = head->next_node;
    head->next_node->pre_node = node;
    head->next_node           = node;
    return node->value;
  }

  void put(int key, int value) {
    int res = get(key);
    if (res != -1) {
      cache_map_[key]->value = value;
      return;
    }
    if (size < capacity_) {
      // insert new node
      Node* node                = new Node;
      node->key                 = key;
      node->value               = value;
      node->pre_node            = head;
      node->next_node           = head->next_node;
      head->next_node->pre_node = node;
      head->next_node           = node;
      cache_map_.insert(std::make_pair(key, node));
      size++;
    } else {
      // overflow
      Node* node  = new Node;
      node->key   = key;
      node->value = value;

      node->next_node           = head->next_node;
      node->pre_node            = head;
      node->next_node->pre_node = node;
      head->next_node           = node;
      cache_map_.insert(std::make_pair(key, node));

      Node* last_node = tail->pre_node;
      cache_map_.erase(last_node->key);
      last_node->value     = -1;
      last_node->value     = -1;
      last_node->next_node = nullptr;
      delete tail;
      tail = last_node;
    }
  }

 private:
  struct Node {
    int key;
    int value;
    Node* pre_node;
    Node* next_node;
  };
  std::map<int, Node*> cache_map_;
  int size;
  Node* head;
  Node* tail;
  int capacity_;
};

int main(int argc, char* argv[]) {
  LRUCache lRUCache(2);
  lRUCache.put(1, 0);                         // 缓存是 {1=1}
  lRUCache.put(2, 2);                         // 缓存是 {1=1, 2=2}
  lRUCache.get(1);                            // 返回 1
  lRUCache.put(3, 3);                         // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  lRUCache.get(2);                            // 返回 -1 (未找到)
  lRUCache.put(4, 4);                         // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  std::cout << lRUCache.get(1) << std::endl;  // 返回 -1 (未找到)
  std::cout << lRUCache.get(3) << std::endl;  // 返回 3
  std::cout << lRUCache.get(4) << std::endl;  // 返回 4
}