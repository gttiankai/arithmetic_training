// Given an array of intervals where intervals[i] = [starti, endi], merge all
// overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.
//
//
//  Example 1:
//
//
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//
//
//  Example 2:
//
//
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
//
//
//  Constraints:
//
//
//  1 <= intervals.length <= 10⁴
//  intervals[i].length == 2
//  0 <= starti <= endi <= 10⁴
//
//
//  Related Topics 数组 排序 👍 2564 👎 0

#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> merge(
        std::vector<std::vector<int>>& intervals) {
        // 将 intervals 进行排序
        std::vector<std::vector<int>> ans;
        std::sort(intervals.begin(), intervals.end());
        int n     = intervals.size();
        int left  = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            int start = intervals[i][0];
            int end   = intervals[i][1];
            if (start <= right) {
                // 要选相对更大的那个
                right = std::max(right, end);
            }else {
                ans.push_back({left, right});
                left = start;
                right = end;
            }
        }
        // 别忘记把最后的一对也添加到最终的答案里面去
        ans.push_back({left, right});

        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> intervals = {
        {8, 10}, {1, 3}, {10, 18}, {2, 6}};
    Solution solution;
    solution.merge(intervals);
}
