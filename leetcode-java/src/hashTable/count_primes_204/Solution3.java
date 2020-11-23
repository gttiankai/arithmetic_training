package hashTable.count_primes_204;

import java.util.Arrays;

public class Solution3 {
    // 筛选算法是终极的优化算法
    // Runtime: 10 ms, faster than 84.88% of Java online submissions for Count Primes.
    // Memory Usage: 34.5 MB, less than 22.35% of Java online submissions for Count Primes.
    // 通过运行时间的比较，还有其他的算法，比筛选算法快。
    public int countPrimes(int n) {
        if (n < 2){
            return 0;
        }
        boolean[] flags = new boolean[n];
        Arrays.fill(flags, true);
        flags[0] = false;
        flags[1] = false;
        for (int i = 2; i*i <= n; i++) {
            if (flags[i]) {
                for (int j = i*i; j < n; j += i) {
                    flags[j] = false;
                } 
            }
        } 
        int ans = 0;
        for (boolean item: flags ) {
           if (item) {
                ans++;
           } 
        }
        return ans;
    }
}
