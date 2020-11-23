/* *
* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together.
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV.

 Because the one is before the five we subtract it making four.
 The same principle applies to the number nine, which is written as IX.
 There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*
* */

package IntegerToRoman_12;

import org.w3c.dom.CDATASection;

import java.util.Dictionary;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    // 这个方法完全的是错误的，只是考虑了单个值的判断
    public static String intToRomanOlder(int num) {

        // 创建字典
        HashMap<String, String> map = new HashMap<String, String>();
        map.put("1", "I");
        map.put("5", "V");
        map.put("10", "X");
        map.put("50", "L");
        map.put("100", "C");
        map.put("500", "D");
        map.put("1000", "M");

        map.put("4", "IV");
        map.put("9", "IX");
        map.put("40", "XL");
        map.put("90", "XC");
        map.put("400", "CD");
        map.put("900", "CM");


        int[] values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        StringBuilder result = new StringBuilder();
        //  按照降序进行排列，然后进行
        for (int i = 0; i < values.length; i++) {
            while (num  > values[i]) {
                num -= values[i];
                result.append(strs[i]);
            }
        }
        return result.toString();
    }

    /* *
    *
    * 这种方式非常巧妙的实现了对罗马数字转换
    * */
    public static String intToRoman(int num) {
        if (num < 1 || num > 3999) {
            return null;
        }
        String[] M = {"","M", "MM", "MMM"};
        String[] C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num%1000) /100] + X[((num%1000)%100)/10] + I[((num%1000)%100)%10];
    }

    public static void main(String[] arguments) {
        int number = 1994;

        System.out.println(intToRoman(number));
    }
}
