/**
 * Implement atoi which converts a string to an integer.
 * <p>
 * The function first discards as many whitespace characters as necessary until the
 * <p>
 * first non-whitespace character is found. Then, starting from this character, takes
 * <p>
 * an optional initial plus or minus sign followed by as many numerical digits as possible,
 * <p>
 * and interprets them as a numerical value.
 * <p>
 * The string can contain additional characters after those that form the integral number,
 * <p>
 * which are ignored and have no effect on the behavior of this function.
 * <p>
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * <p>
 * or if no such sequence exists because either str is empty or it contains only whitespace
 * <p>
 * characters, no conversion is performed.
 * <p>
 * If no valid conversion could be performed, a zero value is returned.
 * <p>
 * Note:
 * <p>
 * Only the space character ' ' is considered as whitespace character.
 * <p>
 * Assume we are dealing with an environment which could only store integers within the
 * <p>
 * 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the
 * <p>
 * range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 * Example 1:
 * <p>
 * Input: "42"
 * Output: 42
 * Example 2:
 * <p>
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus sign.
 * Then take as many numerical digits as possible, which gets 42.
 * Example 3:
 * <p>
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 * Example 4:
 * <p>
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a numerical
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * Example 5:
 * <p>
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * <p>
 * unite test: "    -123"
 * <p>
 * unite test: "  +1 234"
 */
package StringToInteger_8;

public class Solution {
    public static int myAtoi(String str) {
        int index = 0;
        // empty string
        if (str == null || str.length() == 0) {
            return 0;
        }
        if (str.replace(" ", "").length() == 0) {
            return 0;
        }
        // handle whitespace
        while (str.charAt(index) == ' ' &&
                index < str.length()) {
            index++;
        }

        int sign = 1;
        int i = 0;
        if (str.charAt(index) == '-') {
            sign = -1;
            index++;
        } else if (str.charAt(index) == '+') {
            index++;
            sign = 1;
        }
        // convert char to integer
        int result = 0;
        while (index < str.length()) {
            int digit = str.charAt(index) - '0';
            if (digit > 9 || digit < 0) {
                // str start with invalid char
                break;
            }
            /**
             * 这个题目最重要的就是
             * */
            // handle overflow
            if (result > Integer.MAX_VALUE / 10) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            if (result == Integer.MAX_VALUE / 10 && digit > Integer.MAX_VALUE % 10) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            result = 10 * result + digit;
            index++;

        }
        return sign * result;

    }

    public static void main(String[] arguments) {
        String str = String.valueOf((long) Integer.MIN_VALUE + 1);
        System.out.println("the str:" + str);
        System.out.println("the max value: " + Integer.MAX_VALUE);
        System.out.println("the min value: " + Integer.MIN_VALUE);
        System.out.println(myAtoi(" "));
    }

}
