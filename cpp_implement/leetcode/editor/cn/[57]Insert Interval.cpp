// You are given an array of non-overlapping intervals intervals where
// intervals[ i] = [starti, endi] represent the start and the end of the iᵗʰ
// interval and intervals is sorted in ascending order by starti. You are also
// given an interval newInterval = [start, end] that represents the start and
// end of another interval.
//
//  Insert newInterval into intervals such that intervals is still sorted in
// ascending order by starti and intervals still does not have any overlapping
// intervals (merge overlapping intervals if necessary).
//
//  Return intervals after the insertion.
//
//  Note that you don't need to modify intervals in-place. You can make a new
// array and return it.
//
//
//  Example 1:
//
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
//
//  Example 2:
//
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
//
//
//  Constraints:
//
//
//  0 <= intervals.length <= 10⁴
//  intervals[i].length == 2
//  0 <= starti <= endi <= 10⁵
//  intervals is sorted by starti in ascending order.
//  newInterval.length == 2
//  0 <= start <= end <= 10⁵
//
//
//  Related Topics 数组 👍 981 👎 0
#include <algorithm>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 下面的算法实现是对的,但是最后使用了一个排序算法,有其他替代的算法避免掉最后的排序操作吗?
     ***/
    std::vector<std::vector<int>> insertOne(
        std::vector<std::vector<int>>& intervals,
        std::vector<int>& newInterval) {
        int left  = newInterval[0];
        int right = newInterval[1];
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end   = intervals[i][1];
            if (right < start || left > end) {
                ans.push_back({start, end});
            } else {
                left  = std::min(start, left);
                right = std::max(end, right);
            }
        }
        ans.push_back({left, right});
        std::sort(ans.begin(), ans.end());
        return ans;
    }
    /**
     * 下面这个实现需要好好的研究一下
     ***/
    std::vector<std::vector<int>> insert(
        std::vector<std::vector<int>>& intervals,
        std::vector<int>& newInterval) {
        int left  = newInterval[0];
        int right = newInterval[1];
        std::vector<std::vector<int>> ans;
        int n       = intervals.size();
        bool placed = false;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end   = intervals[i][1];
            if (right < start) {
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back({start, end});
            } else if (end < left) {
                ans.push_back({start, end});
            } else {
                left  = std::min(left, start);
                right = std::max(right, end);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> intervals = {{1, 5}};
    std::vector<int> newInterval            = {2, 3};
    Solution solution;
    solution.insert(intervals, newInterval);
}
