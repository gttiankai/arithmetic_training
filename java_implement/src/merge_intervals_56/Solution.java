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

import java.util.*;

public class Solution {

    /**
     * 这个方案失败了, 原因是没有对List进行排序,处理不了一种特殊情况:
     *  {[2, 3],[4, 5],[6, 7],[1, 8]}
     * 而且会报错: java.util.ConcurrentModificationException,因为在对set进行删除或者添加的同时做了遍历操作.所以会产生这个问题.
     * */
    public static List<Interval> mergeFailed(List<Interval> intervals) {
        if (intervals == null || intervals.size() == 0) {
            return new ArrayList<Interval>();
        }
        Set<Interval> res = new HashSet<>();
        for (Interval originalItem :
                intervals) {
            if (res.size() == 0) {
                res.add(originalItem);
                continue;
            }
            Iterator<Interval> iterator = res.iterator();
            while (iterator.hasNext()) {
                Interval item = iterator.next();
                // case 6
                if (item.start <= originalItem.start && item.end >= originalItem.end) {
                    continue;
                } else
                    // case 3
                    if (item.start <= originalItem.start && item.end < originalItem.end && item.end >= originalItem.start) {
                        //iterator.remove();
                        Interval newItem = new Interval(item.start, originalItem.end);
                        if (!res.contains(newItem)) {
                            res.add(newItem);
                        }

                        //break;
                    } else
                        // case 2
                        if (item.start > originalItem.start && item.end >= originalItem.end && item.start <= originalItem.end) {
                            //res.remove(item);
                            //iterator.remove();
                            Interval newItem = new Interval(originalItem.start, item.end);
                            if (!res.contains(newItem)) {
                                res.add(newItem);
                            }

                        } else
                            // case 5
                            if (item.start > originalItem.start && item.end < originalItem.end) {
                                //res.remove(item);
                                //iterator.remove();
                                Interval newItem = new Interval(originalItem.start, originalItem.end);
                                if (!res.contains(newItem)) {
                                    res.add(newItem);
                                }
                            } else {
                                // case 1 and case 4
                                if (!res.contains(originalItem)) {
                                    res.add(originalItem);
                                }
                            }
            }
        }
        return new ArrayList<Interval>(res);
    }


    public static List<Interval> merge(List<Interval> intervals) {
        if (intervals == null || intervals.size() <= 1) {
            return intervals;
        }
        // 通过新建比较器, 并且通过排序的方式解决很难处理的问题
        Collections.sort(intervals, (a, b) -> a.start - b.start);
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        List<Interval> res = new ArrayList<>();
        for (Interval interval : intervals) {
            if (interval.start <= end) {
                end = Math.max(end, interval.end);
            } else {
                res.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        // 最后这一步尤其重要,最后这一步是为了添加第一个interval
        res.add(new Interval(start, end));// key point here dont forget to add this line
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
        //intervals.add(new Interval(1, 8));
        List<Interval> res = merge(intervals);
        for (Interval item : res) {
            System.out.printf("[" + item.start + "," + item.end + "]");
        }
    }
}
