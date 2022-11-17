/**
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
 *
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * */

package hashTable.count_primes_204;

public class Solution {
    /**
     * 时间复杂度 O（n^2）,所以超时了
     * Time Limit Exceeded
     *
     * 想办法优化之后通过了：
     * Runtime: 469 ms, faster than 13.21% of Java online submissions for Count Primes.
     * Memory Usage: 33.1 MB, less than 64.02% of Java online submissions for Count Primes.
     * */
    public int countPrimes(int n) {
        if (n < 2 ){
            return 0;
        }
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)){
                ans++;
            }
        }
        return ans;
    }
    // 这个是原来的算法，由于是从 2 到 number -1， 再加上层的循环，时间复杂度
    // 为O(n^2),所以这个算法超时了。
     private boolean isPrimeOlder(int number) {
        for (int i = 2; i < number; i++) {
            if (number % i == 0){
                return false;
            }
        }
        return true;
    }

    // 上面的算法超时了，所以就想到办法加快速度,其实不用遍历到 number-1 的，
    // 最大到 sqrt(number),就可以了。结果证明 leetcode 也通过了。
    private boolean isPrime(int number) {
        int max = (int)Math.sqrt(number) + 1;
        for (int i = 2; i < max; i++) {
            if (number % i == 0){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int n = 10;
        Solution solution = new Solution();
        System.out.println(solution.countPrimes(n));
    }
}
