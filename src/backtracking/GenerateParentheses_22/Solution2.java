package backtracking.GenerateParentheses_22;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class Solution2 {
    /**
     * 基于上一个版本做优化,由于上一个版本时间太长了,一定可以优化.
     *
     *
     * Runtime: 1 ms, faster than 94.89% of Java online submissions for Generate Parentheses.
     * Memory Usage: 35.4 MB, less than 99.96% of Java online submissions for Generate Parentheses.
     * 这种方式基本上已经做到了最优解了
     */
    private List<String> ans = new LinkedList<>();

    public List<String> generateParenthesis(int n) {
        backTrack("", 0, 0, n);
        return ans;
    }

    private void backTrack(String tmp, int left, int right, int slot) {
        if (tmp.length() == slot * 2) {
            ans.add(tmp);
            return;
        }

        /**
         * 讲真的,这种方式保证合法性的方式是第一次见.
         * 而且顺序不能改变
         * tmp + "("以及 tmp + ")" 也不能改变
         * 个人感觉这种方式也可以用到其他类似的问题上.
         * */
        if (left < slot) {
            backTrack(tmp + "(", left + 1, right, slot);
        }
//         哈哈,这个题目还有陷阱, 又踩到坑里面去了.
//        if (right < slot) {
//            backTrack(tmp + ")", left, right + 1, slot);
//        }
        if (right < left) {
            backTrack(tmp + ")", left, right + 1, slot);
        }

    }

    public static void main(String[] arguments) {
        int n = 3;
        Solution2 solution = new Solution2();
        List<String> ans = solution.generateParenthesis(n);
        System.out.println(ans);
    }

}
