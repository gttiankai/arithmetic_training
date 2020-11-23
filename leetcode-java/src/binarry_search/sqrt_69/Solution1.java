package binarry_search.sqrt_69;

public class Solution1{

    /**
     * Runtime: 26 ms, faster than 7.11% of Java online submissions for Sqrt(x).
     * Memory Usage: 33.5 MB, less than 46.86% of Java online submissions for Sqrt(x).
     * 由于是从 i 开始一个一个查找的，所以很慢，如果优化该算法的话，可以优化查找的方式
     * */
    public int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        int half = x / 2;
        long i =0;
        long target = x;
        int ans = 0;
        for (; i <= half; i++) {
            if (i*i == target) {
                ans = (int)i;
                break;
            } else if (i * i < target && (i+1)*(i+1) > target){
                ans= (int)i;
                break;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int x = 2147483647;
        Solution1 solution = new Solution1();
        System.out.println(solution.mySqrt(x));
    }
}
