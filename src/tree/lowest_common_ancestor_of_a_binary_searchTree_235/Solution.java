/**
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 *
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
 *
 * （一个节点也可以是它自己的祖先）。”
 *
 * 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 * 示例 1:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 * 示例 2:
 *
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 *  
 *
 * 说明:
 *
 * 1. 所有节点的值都是唯一的。 ---> 唯一性
 * 2. p、q 为不同节点且均存在于给定的二叉搜索树中。 ---> 解一定存在
 *
 * */

package tree.lowest_common_ancestor_of_a_binary_searchTree_235;

import tree.TreeNode;

import java.util.LinkedList;
import java.util.List;

public class Solution {
    /**
     * Runtime: 5 ms, faster than 20.54% of Java online submissions for Lowest Common Ancestor of a Binary Search Tree.
     * Memory Usage: 36.8 MB, less than 5.06% of Java online submissions for Lowest Common Ancestor of a Binary Search Tree.
     *
     * 时间复杂度: O(N^2)时间主要浪费在遍历两个 List,一判断公共节点
     * 空间复杂度: O(N)
     *
     * */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        List<TreeNode> pList = new LinkedList<TreeNode>();
        List<TreeNode> qList = new LinkedList<TreeNode>();

        searchNode(root, p, pList);
        searchNode(root, q, qList);
        TreeNode ans = null;
        for (int i = 0; i < pList.size(); i++) {
            if (qList.contains(pList.get(i))) {
                ans = pList.get(i);
            }
        }
        return ans;
    }

    private void searchNode(TreeNode node, TreeNode key, List<TreeNode> list) {
        if (node == null) {
            return;
        }
        list.add(node);
        if (node.val == key.val ) {
            return;
        }else if (key.val < node.val) {
            searchNode(node.left, key, list);
        } else {
            searchNode(node.right, key, list);
        }
    }
}
