/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * Note:
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * Example 1:
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * Example 2:
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 *
 */
package BFS.word_ladder_127;


import java.util.ArrayList;
import java.util.List;

class Solution {
    /**
     * Time Limit Exceeded
     * 我设计的 DFS 算法超时了,需要进行优化.
     * 啊啊啊, 居然将 DFS 算法错误的当成了 BFS 算法,果然脑子不清晰的时候不要做算法题.
     * 怪不得会超时的呢
     * */
    private int ans = Integer.MAX_VALUE;
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        if ( beginWord == null || endWord == null ||
                beginWord.length() == 0 || endWord.length() == 0  ||
                wordList== null || wordList.size() == 0 || !wordList.contains(endWord)) {
            return 0;
        }
        List<String> tmpList = new ArrayList<>();
        tmpList.add(beginWord);
        DFS(beginWord, endWord, wordList, tmpList);

        if(ans == Integer.MAX_VALUE){
            return 0;
        } else {
            return ans;
        }

    }
    private void DFS(String preWord, String endWord, List<String> wordList, List<String> tmpList){

        if (preWord.equals(endWord)) {
            if (ans > tmpList.size()) {
                ans = tmpList.size();
                return;
            }
        } else if(tmpList.size() == wordList.size()) {
            return;
        }
        /**
         * 只能按照顺序去增长,不能去其他方向拓展
         * */
        for (int i = 0; i < wordList.size(); i++) {
            String curString = wordList.get(i);
            if ( tmpList.contains(curString)){
                continue;
            }
            if (isValid(preWord, curString)) {
                tmpList.add(curString);
                DFS(curString, endWord, wordList, tmpList);
                tmpList.remove(tmpList.size()-1);
            }
        }

    }
    private boolean isValid(String begin, String end) {
        int N = begin.length();
        int num = 0;
        for (int i = 0; i < N; i++) {
            if (begin.charAt(i) != end.charAt(i)) {
                num++;
            }
            if (num >1) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String beginWord = "hit";
        String endWord = "cog";
        List<String> wordList = new ArrayList<String>();
        // "hot", "dot", "dog", "lot", "log", "cog"
        wordList.add("hot");
        wordList.add("dot");
        wordList.add("dog");


        wordList.add("lot");
        wordList.add("log");
        wordList.add("cog");

        Solution solution = new Solution();
        System.out.println(solution.ladderLength(beginWord, endWord, wordList));
    }

}