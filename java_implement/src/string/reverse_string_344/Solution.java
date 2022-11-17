/**
Write a function that reverses a string. The input string is given as an array

of characters char[].

Do not allocate extra space for another array, you must do this by modifying 

the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 * */
package string.reverse_strings_244;

class Solution {
    // Runtime: 1 ms, faster than 100.00% of Java online submissions for Reverse String.
    // Memory Usage: 52.3 MB, less than 9.41% of Java online submissions for Reverse String.
    public void reverserString(char[] s) {
        int n = s.length;
        int left = 0;
        int right = n-1;
        char tmp;
        while(left <= right) {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

}
