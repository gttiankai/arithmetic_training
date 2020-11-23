/* *
* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* Note: You may not slant the container and n is at least 2.
*
* Input: [1,8,6,2,5,4,8,3,7]
Output: 49
* */

package ContainerwithMostWater_11;

public class Solution {

    /* *
     * time complexity (n^2)
     * space complextity(n)
     *
     * */
    public static int maxAreaBF(int[] height) {
        int length = height.length;
        if (length < 2) {
            return 0;
        }
        /* *
         * 使用 dp 和下面使用普通的方式，没有太多的区别
         * */
//        int dp[] = new int[length];
//        dp[0] = 0;
//        int max = 0;
//        for (int i = 1; i < length; i++) {
//            for (int j = 0; j < i; j++) {
//               dp[i] = Math.max(dp[i], calculatedArea(j , height[j], i, height[i]));
//            }
//            max = Math.max(max, dp[i]);
//        }

        int max = 0;
        for (int i = 1; i < length; i++) {
            int itemMax = 0;
            for (int j = 0; j < i; j++) {
                itemMax = Math.max(itemMax, calculatedArea(j, height[j], i, height[i]));
            }
            max = Math.max(max, itemMax);
        }
        return max;

    }
    /* *
    *
    * 这种办法称之为两点法，从前后两个点进行遍历。
    * 理论基础：计算最大的面积，有两个前提，长和高都是最大的。
    * 1. 先从最长的开始算起，长是最长的，也就是 height 的长度，计算一个长度
    * 2. 接下来进行下一步的运算，这个时候面临两个选择，left 增加还是 right 减少。这个时候看的是，height[left] 和 height[right] 哪一个
    * 比较大，只有其中一个比原来的大，新的 Area 才有可能大于以前的。其实这一步里面包含了筛选的操作。有这个筛选的操作，才会使这个解法的操作变得
    * 很简单。
    * 3. 如果 left 和 right 的高度一样，则移动哪一个都可以。
    *
    * */

    public static int maxArea(int[] height) {
        int len = height.length;
        if (len < 2) {
            return 0;
        }
        int left = 0;
        int right = len - 1;
        int max = 0;
        while (left < right) {
            max = Math.max(max, (right - left) * Math.min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;

    }


    private static int calculatedArea(int indexX, int valueX,
                                      int indexY, int valueY) {
        return Math.min(valueX, valueY) * (indexY - indexX);
    }

    public static void main(String[] arguments) {
        //int[] height = {9, 8, 6, 2, 5, 4, 8, 3, 9};
        int[] height ={9,9,9,9};
        System.out.println(maxArea(height));
    }
}
