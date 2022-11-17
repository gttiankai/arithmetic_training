package hashTable.daily_tmperatures_739;

import java.util.Stack;

public class Solution1 {
    public int[] dailyTemperatures(int[] T) {

        int[] ans = new int[T.length];
        Stack<Integer> stack = new Stack();
        for (int i = T.length - 1; i >= 0; --i) {
            while (!stack.isEmpty() && T[i] >= T[stack.peek()]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                ans[i] = 0;
            } else {
                ans[i] = stack.peek() - i;
            }

            stack.push(i);
        }
        return ans;
    }

    public static void main(String[] arguments) {
        int[] T = new int[]{73, 74, 75, 71, 69, 72, 76, 73};

        Solution1 solution1 = new Solution1();
        solution1.dailyTemperatures(T);
    }
}
