package binarry_search.sqrt_69;

public class Solution2 {

    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Sqrt(x).
     * Memory Usage: 33.6 MB, less than 45.72% of Java online submissions for Sqrt(x).
     *
     * */
    public int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        int ans = 0;
        long left = 0;
        /*
         * 这个位置一定要加上 1，是为了特殊的数字“4”
         */
        long right = x / 2 +1;
        while (left<= right){
            long mid = (left + right) /2;
            long value = mid * mid;
            if ( value == x) {
                ans = (int) mid;
                break;
            } else if (value < x){
                left = mid;
            } else {
                right = mid;
            }
            if ( right - left == 1) {
                ans = (int) left;
                break;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int x = 9;
        Solution2 solution = new Solution2();
        System.out.println(solution.mySqrt(x));
    }
}
