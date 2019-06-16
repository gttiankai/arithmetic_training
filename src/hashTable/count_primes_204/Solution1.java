package hashTable.count_primes_204;

import java.util.Arrays;

public class Solution1 {
    /**
     * Runtime: 19 ms, faster than 34.13% of Java online submissions for Count Primes.
     * Memory Usage: 34.3 MB, less than 23.37% of Java online submissions for Count Primes.
     *
     * */
    public int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        boolean[] sieve = createSieve(n);
        int ans = 0;
        for (Boolean item : sieve) {
            if (item == true) {
                ans++;
            }

        }
        return ans;

    }
    // 这个算法才是自己写出来的算法，虽然还不是最优解，但是最重要的是，理解的解法，
    // 这个算法最重要的就是临界条件的确定，这也是可以优化的地方
    private boolean[] createSieve(int number) {

        boolean[] flags = new boolean[number];
        Arrays.fill(flags, true);
        flags[0] = false;
        flags[1] = false;
        for (int i = 2; i < number; ++i) {
            if (flags[i]) {
                for (int j = i+i ; j < number; j += i) {
                    flags[j] = false;
                }
            }

        }
        return flags;
    }


    public static void main(String[] args) {
        Solution1 solution = new Solution1();
        System.out.println(solution.countPrimes(10));
    }
}
