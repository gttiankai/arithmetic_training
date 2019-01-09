/**
 * Given a collection of intervals(区间), merge all overlapping(重叠的) intervals.
 * <p>
 * Example 1:
 * <p>
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * Example 2:
 * <p>
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * <p>
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 * <p>
 * Definition for an interval.
 * public class Interval {
 * int start;
 * int end;
 * Interval() { start = 0; end = 0; }
 * Interval(int s, int e) { start = s; end = e; }
 * }
 */
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

package merge_intervals_56;

import java.util.ArrayList;
import java.util.List;

public class Solution {


    public static List<Interval> merge(List<Interval> intervals) {
        if (intervals == null || intervals.size() == 0) {
            return new ArrayList<Interval>();
        }
        ArrayList<Interval> res = new ArrayList<Interval>();
        for (Interval newItem :
                intervals) {
            if (res.size() == 0) {
                res.add(newItem);
                continue;
            }
            for (int j = 0; j < res.size(); j++) {
                Interval item = res.get(j);
                if (item.start <= newItem.start && item.end >= newItem.end) {
                    continue;
                }
                if (item.start <= newItem.start && item.end < newItem.end && item.end >= newItem.start) {
                    res.remove(j);
                    res.add(new Interval(item.start, newItem.end));
                    //break;
                }
                if (item.start > newItem.start && item.end >= newItem.end && item.start <= newItem.end) {
                    res.remove(j);
                    res.add(new Interval(newItem.start, item.end));
                    //break;
                }
                if (item.start > newItem.start && item.end < newItem.end) {
                    res.remove(j);
                    res.add(new Interval(newItem.start, newItem.end));
                    //break;
                } else {
                    res.add(newItem);
                    break;
                }
            }
        }
        return res;
    }

    public static void main(String[] arguments) {
        ArrayList<Interval> intervals = new ArrayList<>();
        /*
         * [1,3],[2,6],[8,10],[15,18]
         * */
        intervals.add(new Interval(2, 3));
        intervals.add(new Interval(4, 5));
        intervals.add(new Interval(6, 7));
        intervals.add(new Interval(1, 8));
        List<Interval> res = merge(intervals);
        for (Interval item : res) {
            System.out.printf("[" + item.start + "," + item.end + "]");
        }
    }
}
