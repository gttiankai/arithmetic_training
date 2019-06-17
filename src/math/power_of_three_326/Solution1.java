package math.power_of_three_326;

class Solution1 {
    // Runtime: 11 ms, faster than 56.03% of Java online submissions for Power of Three.
    // Memory Usage: 35.9 MB, less than 16.19% of Java online submissions for Power of Three.
    public boolean isPowerOfThree(int n) {
        // 也可以将Math.pow(3, 19), 替换成为常数1162261467
        // 为什么要选3^19,这是因为
         return (n > 0 && Math.pow(3, 19) % n == 0);
    }
}
