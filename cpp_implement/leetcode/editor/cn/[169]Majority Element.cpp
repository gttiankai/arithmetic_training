// Given an array nums of size n, return the majority element.
//
//  The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.
//
//
//  Example 1:
//  Input: nums = [3,2,3]
// Output: 3
//
//  Example 2:
//  Input: nums = [2,2,1,1,1,2,2]
// Output: 2
//
//
//  Constraints:
//
//
//  n == nums.length
//  1 <= n <= 5 * 10⁴
//  -10⁹ <= nums[i] <= 10⁹
//
//
//
// Follow-up: Could you solve the problem in linear time and in
// O(1) space?
//

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 使用 hash_map 进行解决就很简单
     ***/
    int majorityElementHashMap(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        int m = nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
            if (map[nums[i]] > m) {
                return nums[i];
            }
        }
        return 0;
    }
    /**
     * 如果将所有的元素进行排序,因为众数的个数超过了一般,所以排序数组中间位置的数肯定是众数
     ***/
    int majorityElement(std::vector<int>& nums) {
        // sort the nums
        // 快排算法
        QuickSort(nums, 0, nums.size()-1);
        return nums[nums.size()/2];
    }

   private:
    void QuickSort(std::vector<int>& nums, int low, int hight) {
        if (low >= hight) {
            return;
        }
        int j = Partition(nums, low, hight);
        QuickSort(nums, low, j - 1);
        QuickSort(nums, j + 1, hight);
    }
    int Partition(std::vector<int>& nums, int low, int hight) {
        int i = low;
        int j = hight + 1;
        int v = nums[low];
        while (true) {
            while (nums[++i] < v) {
                if (i == hight) {
                    break;
                }
            }
            while (v < nums[--j]) {
                if (j == low) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            swap(&nums[i], &nums[j]);
        }
        swap(&nums[low], &nums[j]);
        return j;
    }
    void swap(int* a, int* b) {
        int c = *a;
        *a    = *b;
        *b    = c;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_cases({{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}});
    for (auto& case_ : test_cases) {
        int majority_element = solution.majorityElement(case_);
        std::cout << "majority element is:" << majority_element << std::endl;
    }
    return 0;
}
