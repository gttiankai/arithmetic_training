/**
 * The thief has found himself a new place for his thievery again. There is only
 *
 * one entrance to this area, called the "root." Besides the root, each house has
 *
 * one and only one parent house. After a tour, the smart thief realized that "all
 *
 * houses in this place forms a binary tree". It will automatically contact the police
 *
 * if two directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting
 *
 * the police.
 *
 * Example 1:
 *
 * Input: [3,2,3,null,3,null,1]
 *
 *      3
 *     / \
 *    2   3
 *     \   \
 *      3   1
 *
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:
 *
 * Input: [3,4,5,1,3,null,1]
 *
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  1   3   1
 *
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 * */

package tree.house_robber_3_337;

import tree.TreeNode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class Solution {
    /**
     * 思路:
     *  1. 对一棵树进行层次遍历,获取层次遍历之后的数组
     *  2. 分别计算数组中的奇数和偶数元素的和
     *  3. 返回两个值之中比较大的值,这个值就是 maximum amount
     *  层次遍历为什么不行?
     *  unite test:
     *     input: [4,1,null,2,null,3]
     *     output: 6
     *     expected: 7
     *     我想不明白答案为什么是7, 我认为应该是6?
     *     想明白了,一看之后恍然大悟
     *        4
     *       /
     *      1
     *     /
     *    2
     *   /
     *  3
     *
     *  由于4和3中间也不相连,所以,可以使用4和3进行.
     *  这个测试例,就标志着我下面基于层次遍历的方法,完全行不通.
     *  其实层次遍历是一个很好的方法,但是不适用于这个方法
     * */
    //TODO: need more research
    public int rob(TreeNode root) {
        if (null == root) {
            return 0;
        }
        List<List<Integer>> levelOrderList = levelOrder(root);
        int oddMax = 0;
        int evenMax = 0;
        for (int i = 0;i < levelOrderList.size(); i++) {
            List<Integer> tmp = levelOrderList.get(i);
            if (i % 2 == 0) {
                // 偶数
                for (Integer item : tmp) {
                    oddMax += item;
                }
            } else {
                for (Integer item: tmp) {
                    evenMax += item;
                }
            }
        }
        return Math.max(oddMax, evenMax);
    }
    private  List<List<Integer>> levelOrder(TreeNode root) {
        List ans = new ArrayList();
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        while (queue.size() != 0) {
            int levelNumber = queue.size();
            List<Integer> subList = new ArrayList<>();
            for (int i = 0;i < levelNumber; i++) {
                if (queue.peek().left != null) {
                    queue.offer(queue.peek().left);
                }
                if (queue.peek().right != null) {
                    queue.offer(queue.peek().right);
                }
                subList.add(queue.poll().val);
            }
            ans.add(subList);
        }
        return ans;
    }
}
