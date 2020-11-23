/***
 * Given a non-negative integer numRows, generate the first numRows of Pascal's 
 * triangle. In Pascal's triangle, each number is the sum of the two numbers 
 * directly above it.
 * Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 * 
 * 
 * 
 */
package array.pascal_triangle_230;

import java.util.*;

class Solution {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Pascal's Triangle.
     * Memory Usage: 34.1 MB, less than 19.72% of Java online submissions for Pascal's Triangle.
     *
     * 总算是做出来了，花费了不少时间，主要的时间花在了处理
     *
     * */
    public List<List<Integer>> generate(int numRows) {
        if (numRows <= 0 ) {
            return new ArrayList<>();
        }
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> preList = new ArrayList<Integer>();
        preList.add(1);
        ans.add(preList);
        if (numRows == 1) {
            return ans;
        }
        for(int i = 2; i <= numRows; i++) {
            ArrayList<Integer> curList = new ArrayList<Integer>(i);
            pascal(preList, curList, i);
            ans.add(curList);
            preList = curList;
        }
        return ans;
    }
    private void pascal(List<Integer> preList, List<Integer> curList, int length) {
        curList.add(0, 1);
        for (int i = 1; i < length; i++) {
            if (i == length - 1 ) {
                curList.add(1);
            } else {
                curList.add(preList.get(i-1) + preList.get(i));
            }
        }
    }

    /**
     * 下面的代码是有问题的
     *
     * */
    private void pascalOlder(List<Integer> preList, List<Integer> curList, int length) {
        curList.add(0, 1);
        //这种对 List 的指定位置的赋值，前提是这个 List 以前不为空，如果前面有空的话，就会报错
        curList.add(length - 1, 1);
        int left = 1;
        int right = length -2;
        while(left <= right) {
            curList.add(left, preList.get(left-1) + preList.get(left));
            curList.add(right, preList.get(right-1) + preList.get(right));
            left ++;
            right--;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        int numRows = 5;
        System.out.println(solution.generate(numRows));
    }
}

