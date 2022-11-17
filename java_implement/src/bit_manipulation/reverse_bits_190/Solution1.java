package bit_manipulation.reverse_bits_190;

public class Solution1 {
    /**
     * 这个方案将
     *
     * */
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans += n & 0x1;
            n = n >> 1;
            if (i < 31) {
                ans = ans << 1;
            }
        }
        return ans;
    }
}
