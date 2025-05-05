// Given an array nums with n objects colored red, white, or blue, sort them in-
// place so that objects of the same color are adjacent, with the colors in the
// order red, white, and blue.
//
//  We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.
//
//  You must solve this problem without using the library's sort function.
//
//
//  Example 1:
//
//
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//
//
//  Example 2:
//
//
// Input: nums = [2,0,1]
// Output: [0,1,2]
//
//
//
//  Constraints:
//
//
//  n == nums.length
//  1 <= n <= 300
//  nums[i] is either 0, 1, or 2.
//
//
//
//  Follow up: Could you come up with a one-pass algorithm using only constant
// extra space?
//
//   Related Topics 数组 双指针 排序 👍 1917 👎 0

#include <valarray>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    // 由于需要排序的数字只有{0, 1, 2},
    // 尝试使用快排,遍历一次数组应该就可以完成题目了;
    // 使用快速排序好像不能解决这个问题
    void sortColorsWrong(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int guard = 1;
        int left  = 0;
        int right = n - 1;
        while (left != right) {
            while (left < right && nums[right] > guard) {
                right--;
            }
            while (left < right && nums[left] < guard) {
                left++;
            }
            swap(nums[left], nums[right]);
        }
    }

   private:
    void swap(int& a, int& b) {
        int t = a;
        a     = b;
        b     = t;
    }

   public:
    void sortColors(std::vector<int>& nums) {
        int p0 = 0, p1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                swap(nums[p1], nums[i]);
                p1++;
            } else if (nums[i] == 0) {
                swap(nums[p0], nums[i]);
                // 只会存在 p0==p1 和 p0 < p1
                if (p0 < p1) {
                    swap(nums[p1], nums[i]);
                }
                // 更新 p0 的同时,同步需要更新 p1
                p0++;
                p1++;
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<int> nums = {1, 0};
    Solution solution;
    solution.sortColors(nums);
}
