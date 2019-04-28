/**
 * Given an encoded string, return it's decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string
 *
 * inside the square brackets is being repeated exactly k times.
 *
 * Note that k is guaranteed to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 *
 * digits and that digits are only for those repeat numbers, k.
 *
 * For example, there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 * */

package stack.decode_string_394;

import java.util.Stack;

public class Solution {
    public String decodeString(String s) {
        if (s == null) {
            return "";
        }
        char[] chars = s.toCharArray();
        /**
         * 我懂了,可以使用两个栈,将数组和字符分别入栈,可以解决问题.
         * */
        Stack<String> charsStack = new Stack<>();
        Stack<Integer> countStack = new Stack<>();
        String ans = "";
        boolean needPop = false;
        int n = chars.length;
        int index = 0;
        while (index < n ) {
            if (Character.isDigit(chars[index])) {
                int count = 0;
                while (Character.isDigit(chars[index])) {
                    count = count * 10 + (chars[index] - '0');
                    index++;
                }
                countStack.push(count);
            } else if (chars[index] == '[') {
                charsStack.push(ans);
                ans = "";
                index++;
            } else if (chars[index] == ']') {
                // TODO
                // 这个地方是关键点,尤其是对 tmp 以及 ans 的处理,
                // 虽然一开始看很简单,但是自己写的话,还是有一定的苦难
                int count = countStack.pop();
                StringBuilder tmp = new StringBuilder(charsStack.pop());
                for (int i = 0; i < count; i++) {
                    tmp = tmp.append(ans)  ;
                }
                ans = tmp.toString();
                index++;
            } else {
                ans += chars[index];
                index++;
            }
        }
        return ans;
    }
    public static void main(String[] arguments) {
        String s = "3[a2[c]]";
        Solution solution = new Solution();
        System.out.println(solution.decodeString(s));
    }
}
