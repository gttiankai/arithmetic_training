/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * <p>
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * <p>
 * Note that 1 does not map to any letters.
 * <p>
 * Example:
 * <p>
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * <p>
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 **/

package LetterCombinationsOfAPhoneNumber;

import java.util.*;

public class Solution {
    /**
     * 采用循环的方式，会有问题。
     * */
    public static List<String> letterCombinationsOlder(String digits) {

        Map<Character, String> map = new HashMap<>();
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");

        int number = 1;
        char[] array = digits.toCharArray();
        for (char item : array) {
            number *= map.get(item).length();
        }
        List<String> res = new ArrayList<>(number);
        return null;
    }

    public static List<String> letterCombinations(String digits) {
        LinkedList<String> ans = new LinkedList<String>();
        if (digits.isEmpty()) {
            return ans;
        }

        String[] mapping = new String[]{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.add("");
        // 遍历整个数组
        for (int i = 0; i < digits.length(); i++) {
            int x = Character.getNumericValue(digits.charAt(i));
            //TODO: 这一步要进行特殊的处理
            /*
             *
             * 巧妙的利用已经在队列中的长度进行处理
             *
             * 个人感觉这一步是最重要也是最巧妙的部分。
             * */

            while (ans.peek().length() == i) {
                // 出队之后
                String t = ans.remove();
                for (char s : mapping[x].toCharArray()) {
                    ans.add(t + s);
                }
            }
        }
        return ans;
    }

    public static void main(String[] arguments) {
        String digits = "534";
        System.out.println(letterCombinations(digits));

    }
}
