/**
Given an array where elements are sorted in ascending order, convert it to a 

height balanced BST. For this problem, a height-balanced binary tree is defined 

as a binary tree in which the depth of the two subtrees of every node never 

differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following 

height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 * 
 */
package tree.convert_sotred_array_to_binary_search_tree_108;
import tree.TreeNode;

class Solution {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Convert Sorted Array to Binary Search Tree.
     * Memory Usage: 37.6 MB, less than 71.11% of Java online submissions for Convert Sorted Array to Binary Search Tree.
     *
     * */
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0 ){
            return null;
        }
        int left = 0;
        int right = nums.length-1;
        return createBinrary(nums, left, right);
        
    }
    private TreeNode createBinrary(int[] nums, int left, int right) {
        if (left > right) {
            return null;
        }
        if (left == right) {
            return new TreeNode(nums[left]);
        }
        int mid = (left + right) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left =  createBinrary(nums, left, mid-1);
        node.right = createBinrary(nums, mid+1, right);
        return node;
    }
    public static void main(String[] args) {
        int[] nums = new int[] {-10, -3, 0 , 5, 9};
        Solution solution = new Solution();
        TreeNode ans = solution.sortedArrayToBST(nums);
    }
}