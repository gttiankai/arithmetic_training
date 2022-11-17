package backtracking.NQueens_51;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Solution {

    public List<List<String>> solveNQueens(int n) {
        if (n == 0) {
            return new LinkedList<>();
        }
        List<List<String>> ans = new ArrayList<>();
        char[][] arrays = new char[n][n];
        for (int i = 0; i < arrays.length; i++) {
            Arrays.fill(arrays[i], '.');
        }
        backTrace(ans, arrays, 0, n);
        return ans;
    }

    private void backTrace(List<List<String>> ans, char[][] chars, int colIndex, int n) {
        // 这个思路也非常的关键,是按照列来的,其实不用每个元素都适配,当然了也可以按照行来.
        if (colIndex == n) {
            ans.add(charsToList(chars));
            return;
        }

        for (int i = 0; i < n; i++) {
            if(isValid(chars, i, colIndex)) {
                chars[i][colIndex] = 'Q';
                backTrace(ans, chars, colIndex+1, n);
                chars[i][colIndex] = '.';
            }
        }

    }

    private boolean isValid(char[][] chars, int x, int y) {
        int n = chars.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 这个判断 N 皇后问题的是否合法的地方非常的关键
                if (chars[i][j] == 'Q' && (x == i || x + y == i + j || x + j == y + i)) {
                    return false;
                }
            }
        }
        return true;
    }


    private List<String> charsToList(char[][] chars) {
        int n = chars.length;
        ArrayList<String> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringBuilder tmp = new StringBuilder();
            for (char item : chars[i]){
                tmp.append(item);
            }
            ans.add(tmp.toString());
        }
        return ans;
    }


}
