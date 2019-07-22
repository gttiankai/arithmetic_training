package search.search_in_rotated_sorted_array_33;


public class Solution1 {

    /*
      执行用时 :2 ms, 在所有 Java 提交中击败了85.59%的用户
      内存消耗 :36.2 MB, 在所有 Java 提交中击败了85.51%的用户

      算法思想: 使用最简单的算法遍历的思想,解决这个问题
      时间复杂度: O(n)
      空间复杂度: O(1)
     */
    public int search(int[] nums, int target){
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
}
