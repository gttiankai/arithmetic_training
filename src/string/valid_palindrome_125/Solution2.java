package string.valid_palindrome_125;

public class Solution2 {
    /**
     * 已经找到最快的算法了。
     *
     * */
    private static final char[] charMap = new char[256];

    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true;
        }
        initCharMap();
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;
        char leftChar;
        char rightChar;
        while (left <= right) {
            leftChar= charMap[chars[left]];
            rightChar = charMap[chars[right]];
            if (leftChar != 0 && rightChar != 0) {
                if (leftChar != rightChar) {
                    return false;
                }
                left++;
                right--;
            } else {
                if (leftChar == 0) left++;
                if (rightChar == 0) right--;
            }
        }
        return true;
    }

    private void initCharMap() {
        for (int i = 0; i < 10; i++) {
            charMap[i + '0'] = (char) (1 + i);
        }
        for (int i = 0; i < 26; i++) {
            charMap['A' + i] = (char) ('a' + i);
            charMap['a' + i] = (char) ('a' + i);
        }
    }

    public static void main(String[] args) {
        String s = "A man, a plan, a canal: Panama";
        Solution2 solution = new Solution2();
        System.out.println(solution.isPalindrome(s));
    }
}
