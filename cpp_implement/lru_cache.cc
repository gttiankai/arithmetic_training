/**
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value
。如果插入操作导致关键字数量超过 capacity ， 则应该逐出最久未使用的关键字。函数 get 和 put 必须以 O(1)
的平均时间复杂度运行。
 **/
#include <iostream>
#include <map>
#include <vector>

struct Node {
  int value;
  std::shared_ptr<Node> pre_ptr;
  std::shared_ptr<Node> post_ptr;
};
class LRUCache {
 public:
  LRUCache(int capacity) {
    if (capacity <= 0) {
      std::cout << "get wrong capacity\n" << std::endl;
      return;
    }
    capacity_ = capacity;
    head_ptr  = nullptr;
    tail_ptr  = nullptr;
  }
  int get(int key) {
    if (map_.empty()) {
      std::cout << "Cache is empty" << std::endl;
      return -1;
    }
    if (map_.find(key) == map_.end()) {
      std::cout << "Cache can not find the " << key << std::endl;
      return -1;
    }
    // update use count
    std::shared_ptr<Node> node = map_[key];
    AdjustList(node);
    return node->value;
  }
  void put(int key, int value) {
    if (map_.size() == 0) {
      auto node      = std::make_shared<Node>();
      node->value    = value;
      node->pre_ptr  = nullptr;
      node->post_ptr = nullptr;
      head_ptr       = node;
      tail_ptr       = node;
      map_.insert(std::make_pair(key, node));
      return;
    }
    if (map_.find(key) == map_.end()) {
      if (map_.size() < capacity_) {
        auto node   = std::make_shared<Node>();
        node->value = value;
        AdjustList(node);
        map_.insert(std::make_pair(key, node));
        return;
      } else {
        // remove older
        auto dead_node = tail_ptr;
        auto pre_node = tail_ptr->pre_ptr;
        tail_ptr      = pre_node;
        map_.erase(dead_node->value);
        auto node     = std::make_shared<Node>();
        node->value   = value;
        map_.insert(std::make_pair(key, node));
        AdjustList(node);
        return;
      }
    } else {
      auto node = map_[key];
      AdjustList(node);
      return;
    }
  }

 private:
  std::map<int, std::shared_ptr<Node>> map_;
  int capacity_                  = 0;
  std::shared_ptr<Node> head_ptr = nullptr;
  std::shared_ptr<Node> tail_ptr = nullptr;

  void AdjustList(std::shared_ptr<Node> node) {
    std::shared_ptr<Node> pre_node  = node->pre_ptr;
    std::shared_ptr<Node> post_node = node->post_ptr;

    node->pre_ptr  = nullptr;
    node->post_ptr = head_ptr;
    head_ptr       = node;
    if (pre_node != nullptr) {
      pre_node->post_ptr = post_node;
    }
    if (post_node != nullptr) {
      post_node->pre_ptr = pre_node;
    }
  }
};

int main(int argc, char* argv[]) {
  // [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
  int capacity  = 3;
  LRUCache* obj = new LRUCache(capacity);
  obj->get(2);
  obj->put(1, 1);
  obj->put(2, 2);
  obj->get(1);
  obj->put(3, 3);
  obj->get(2);
  obj->put(4, 4);
  obj->get(1);
  obj->get(3);
  obj->get(4);
}