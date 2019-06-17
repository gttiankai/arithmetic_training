/**

Given two arrays, write a function to compute their intersection(交集).

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
    answer: 就不要对已有得元素进行排序了.
What if nums1's size is small compared to nums2's size? Which algorithm is better?
    answer: 
What if elements of nums2 are stored on disk, and the memory is limited such that 
you cannot load all elements into the memory at once?
    answer: 
    1. If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, 
       read chunks of array that fit into the memory, and record the intersections.

    2. If both nums1 and nums2 are so huge that neither fit into the memory, sort 
       them individually (external sort), then read 2 elements from each array 
       at a time in memory, record intersections.
 * */

package hashTable.intersection_of_two_arrays_ii_350;
import java.util.*;

class Solution {
    // Runtime: 2 ms, faster than 90.62% of Java online submissions for Intersection of Two Arrays II.
    // Memory Usage: 37.7 MB, less than 41.40% of Java online submissions for Intersection of Two Arrays II.
    public int[] intersect(int[] nums1, int[] nums2){
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int m = nums1.length;
        int n = nums2.length;
        List<Integer> ans = new ArrayList<Integer>();
        int p1 = 0;
        int p2 = 0;
        while(p1 < m && p2 < n){
            if (nums1[p1] == nums2[p2]) {
                ans.add(nums1[p1]);
                p1++;
                p2++;
            } else if (nums1[p1] < nums2[p2]){
                p1++;
            } else {
                p2++;
            }
        }

        // return ans.toArray(new int[ans.size()]);
        int[] res = new int[ans.size()];
        for(int i = 0; i < ans.size(); i++) {
           res[i] = ans.get(i);
        }
        return res;
    }

}
