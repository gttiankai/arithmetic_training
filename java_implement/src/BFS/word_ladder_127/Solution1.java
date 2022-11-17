package BFS.word_ladder_127;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution1 {
    /**
     * 要自己写 BFS 算法
     *
     * Runtime: 207 ms, faster than 25.09% of Java online submissions for Word Ladder.
     * Memory Usage: 37.2 MB, less than 99.97% of Java online submissions for Word Ladder.
     *
     * 终于使用自己的BFS 算法,解决了这个问题,初步学习了 DFS 和 BFS 算法.
     */

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (beginWord == null || endWord == null ||
                beginWord.length() == 0 || endWord.length() == 0 ||
                wordList == null || wordList.size() == 0 || !wordList.contains(endWord)) {
            return 0;
        }
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);

        return BFS(endWord, wordList, queue);

    }

    private int BFS(String endWord, List<String> wordList, Queue<String> queue) {
        int ans = 0;
        boolean[] flags = new boolean[wordList.size()];
        int levelNumber = queue.size();
        while (!queue.isEmpty()) {
            ans++;
            for (int count = 0; count < levelNumber; count++) {
                String preString = queue.poll();
                for (int i = 0; i < wordList.size(); i++) {
                    String curString = wordList.get(i);
                    if (flags[i]) {
                        continue;
                    }
                    if (isValid(preString, curString)) {
                        if (curString.equals(endWord)) {
                            return ++ans;
                        }
                        flags[i] = true;
                        queue.add(curString);
                    }
                }
            }
            levelNumber = queue.size();
        }
        return 0;

    }

    private boolean isValid(String begin, String end) {
        int N = begin.length();
        int num = 0;
        for (int i = 0; i < N; i++) {
            if (begin.charAt(i) != end.charAt(i)) {
                num++;
            }
            if (num > 1) {
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

        Solution1 solution = new Solution1();
        System.out.println(solution.ladderLength(beginWord, endWord, wordList));
    }
}
