package string.letter_combinations_a_phone_number_17;

import java.util.*;

public class Solution1 {
    /**
     * Runtime: 1 ms, faster than 82.77% of Java online submissions for Letter Combinations of a Phone Number.
     *
     * 自己想出来的办法,其实比较简单
     * */
    public List<String> letterCombinations(String digits) {
        Map<Integer, String> map = new HashMap<Integer, String>();
        map.put(2, "abc");
        map.put(3, "def");
        map.put(4, "ghi");
        map.put(5, "jkl");
        map.put(6, "mno");
        map.put(7, "pqrs");
        map.put(8, "tuv");
        map.put(9, "wxyz");

        Queue<String> queue = new ArrayDeque<>();
        int n = digits.length();
        for (int i = 0; i < n; i++) {
            String value = map.get(digits.charAt(i) - '0');
            if (i == 0) {
                // 第一次先入栈
                for (int j = 0; j < value.length(); j++ ) {
                    queue.add(String.valueOf(value.charAt(j)));
                }
            } else {
                int count = queue.size();
                for (int j = 0; j < count; j++) {
                    String tmp = queue.poll();
                    for (int k = 0; k < value.length(); k++) {
                        queue.add(tmp+value.charAt(k));
                    }
                }

            }
        }
        return new ArrayList<>(queue);

    }
    public static void main(String[] arguments) {
        String digits = "23";
        Solution1 solution = new Solution1();
        solution.letterCombinations(digits);
    }
}
