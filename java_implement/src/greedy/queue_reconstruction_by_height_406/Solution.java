/**
 * Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 *
 * Note:
 * The number of people is less than 1,100.
 *
 *
 * Example
 *
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * */

package greedy.queue_reconstruction_by_height_406;

import java.util.*;
import java.util.stream.Collector;

public class Solution {
    public int[][] reconstructQueue(int[][] people) {

        if (null == people ) {
            return new int[0][0];
        }
        // TODO: 后续看下如何进行 comparator 的创建.
        //  这个地方其实是考察了如何新建comparator 的方式.
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                } else {
                    return o2[0] - o1[0];
                }
            }
        });
        int n = people.length;
        List<int[]> ans = new ArrayList<>();
        for (int[] cur: people){
            ans.add(cur[1], cur);
        }
        return ans.toArray(new int[n][2]);
    }
}