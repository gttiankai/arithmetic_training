/**

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order,
not the kth distinct element.

Implement KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element
in the stream.

Example 1:

Input
    ["KthLargest", "add", "add", "add", "add", "add"]
    [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
    Output
        [null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4 [8, 5, 4, 2]
kthLargest.add(5);   // return 5 [8, 5, 5, 4, 2]
kthLargest.add(10);  // return 5 [10, 8, 5, 4, 2]
kthLargest.add(9);   // return 8 [10, 9, 8, 5, 4, 2]
kthLargest.add(4);   // return 8 [10, 9, 8, 5, 4, 4, 2]



Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.
 * */

#include "command_include.h"
#include <queue>
/**
 * 这种方案已经超时了.
 * 方案介绍:
 *      初始排序: 快排;
 *      add 添加元素: 插入排序
 * */
class KthLargest {
 public:
  KthLargest(int k, std::vector<int>& nums) {
    key = k - 1;
    Sort(nums);
    sort_nums = nums;
  }

  int add(int val) {
    if (sort_nums.empty()) {
      sort_nums.push_back(val);
      return val;
    }
    int position = sort_nums.size();
    for (int i = 0; i < sort_nums.size(); ++i) {
      if (val >= sort_nums[i]) {
        position = i;
        break;
      }
    }
    sort_nums.insert(sort_nums.begin() + position, val);
    return sort_nums[key];
  }

 private:
  void Sort(std::vector<int>& nums) {
    if (nums.empty()) {
      return;
    }
    QuickSort(nums, 0, nums.size() - 1);
  }
  // sort by descending
  void QuickSort(std::vector<int>& nums, int start, int end) {
    if (nums.empty() || start >= end) {
      return;
    }
    int bars  = nums[start];
    int left  = start;
    int right = end;
    while (left < right) {
      while (left < right && nums[right] < bars) {
        right--;
      }
      Exchange(&nums[left], &nums[right]);
      while (left < right && nums[left] > bars) {
        left++;
      }
      Exchange(&nums[left], &nums[right]);
    }
    QuickSort(nums, start, left - 1);
    QuickSort(nums, right + 1, end);
  }

  void Exchange(int* p, int* q) {
    int temp;
    temp = *q;
    *q   = *p;
    *p   = temp;
  }

  int key = 0;
  std::vector<int> sort_nums;
};

class KthLargestO1{
 public:
  KthLargestO1(int k, std::vector<int>& num) {
    this->k = k;
    for (const auto& item : num) {
      add(item);
    }
  }
  int add(int val) {
    heap.push(val);
    if (heap.size() > k) {
      heap.pop();
    }
    return heap.top();
  }

 private:
  // 创建一个小顶堆,这个堆只保留 K 个元素, 头部第一个元素就是第 K 大元素
  std::priority_queue<int,std::vector<int>, std::greater<int>> heap;
  int k;
};



int main(int argc, char* argv[]) {
  /**
   * case 1
   * ["KthLargest","add","add","add","add","add"]
     [[1,[]],[-3],[-2],[-4],[0],[4]]
     case 2
     ["KthLargest","add","add","add","add","add"]
    [[2,[0]],[-1],[1],[-2],[-4],[3]]
   * */
  std::vector<int> nums = {0};
  KthLargestO1 kth_largest(2, nums);
  std::cout << kth_largest.add(-1) << std::endl;
  std::cout << kth_largest.add(1) << std::endl;
  std::cout << kth_largest.add(-2) << std::endl;
  std::cout << kth_largest.add(-4) << std::endl;
  std::cout << kth_largest.add(3) << std::endl;
}