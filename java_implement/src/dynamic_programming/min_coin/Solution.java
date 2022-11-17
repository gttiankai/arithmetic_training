/**
 *  1 3 5
 *  min(11)
 *
 *  f(0) = 0;
 *  f(1) = f(1-1) + 1
 *  f(2) = f(2-1) + 1
 *  f(3) = min {f(3-1)+1, f(3-3) +1}
 *  if I
 *  f(i) = min {f(i-1) + 1, f(i-3) + 1, f(i-5) +1}
 * */
package dynamic_programming.min_coin;

public class Solution {
    private  static int[] array = {1, 3, 5};
    /**
     * recursion
     * */
    public static int minCoin(int sum) {
        if (sum >= 5) {
            return minCoin(sum-5) + 1;
        }else if (sum >= 3) {
            return minCoin(sum-3) + 1;
        }else if (sum >= 1){
            return minCoin(sum-1) + 1;
        }else if (sum ==1 ){
            return 1;
        } else {
            return 0;
        }
    }

    public static int f(int sum) {
        /**
         * 这个是第一个写出来的动态规划算法
         * */
        int[] map = new int[sum+1];
        map[0] = 0;
        map[1] = 1;
        for (int i = 2; i < sum + 1; i++) {
            if (i >= 5) {
                map[i] = map[i-5] + 1;
            }else if (i >= 3) {
                map[i] = map[i - 3] + 1;
            } else {
                map[i] = map[i-1] +1;
            }
        }
        return map[sum];
    }
    public static void main(String[] arguments) {
        System.out.println("the min coin number: " + f(1001));
    }
}
