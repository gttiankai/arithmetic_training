/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 *
 * In this case, 6 units of rain water (blue section) are being trapped.
 *
 * Thanks Marcos for contributing this image!
 *
 * Example:
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 * */

package trapping_rain_water_42;

/**
 * 这种解法并不是一种很通用的解法,是通过观察得出的结论. 要尝试有没有其他解法.
 * */
public class Solution {
    public static int trap(int[] height) {
        if (height == null || height.length < 3) {
            return 0;
        }
        int left = 0;
        int right = height.length -1;
        int res = 0;

        while (left < right) {
            int guard = Math.min(height[left], height[right]);
            if (height[left] < height[right]) {
                left++;
                while (left < right && guard > height[left]){
                    res += guard - height[left];
                    left++;
                }
            } else {
                right--;
                while (left < right && height[right] < guard) {
                    res += guard - height[right];
                    right--;
                }
            }
        }
        return res;
    }
    public static void main(String[] arguments) {
        int[] height = {0,1,0,2,1,0,1,3,2,1,2,1};
        System.out.printf("the values: " + trap(height));
    }
}
