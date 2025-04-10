// You are given an integer array height of length n. There are n vertical lines
// drawn such that the two endpoints of the iᵗʰ line are (i, 0) and (i, height[i]).
//
//
//  Find two lines that together with the x-axis form a container, such that the
// container contains the most water.
//
//  Return the maximum amount of water a container can store.
//
//  Notice that you may not slant the container.
//
//
//  Example 1:
//
//
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,
// 3,7]. In this case, the max area of water (blue section) the container can
// contain is 49.
//
//
//  Example 2:
//
//
// Input: height = [1,1]
// Output: 1
//
//
//
//  Constraints:
//
//
//  n == height.length
//  2 <= n <= 10⁵
//  0 <= height[i] <= 10⁴
//
//
//  Related Topics 贪心 数组 双指针 👍 5427 👎 0
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int maxAreaSlow(std::vector<int>& height) {
        int n = height.size();
        if (n < 2) {
            return 0;
        }
        int max_area = 0;
        // 这个里面有很多重复的计算,如果能够减少的话,可以有效的提升性能
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = (j - i) * std::min(height[i], height[j]);
                max_area = std::max(max_area, area);
            }
        }
        return max_area;
    }
    // 双指针解法
    int maxArea(std::vector<int>& height) {
        int n = height.size();
        if (n < 2) {
            return 0;
        }
        int left     = 0;
        int right    = n - 1;
        int max_area = (n - 1) * std::min(height[left], height[right]);
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
            int area = (right - left) * std::min(height[left], height[right]);
            max_area = std::max(max_area, area);
        }
        return max_area;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_case = {{1, 2, 4, 3}, {1, 8, 6, 2, 5, 4, 8, 3, 7}};
    for (auto& height : test_case) {
        int max_area = solution.maxArea(height);
        std::cout << max_area << std::endl;
    }
}
