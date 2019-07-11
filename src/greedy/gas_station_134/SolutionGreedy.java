package greedy.gas_station_134;

public class SolutionGreedy {

    /**
     * 
     *
     * unite test:
     *      [5,8,2,8]
     *      [6,5,6,6]
     *
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Gas Station.
     * Memory Usage: 36.7 MB, less than 99.75% of Java online submissions for Gas Station.
     *
     * */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < gas.length; i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if ( sum < 0) {
                start = i+1;
                sum = 0;
            }
        }
        return (total < 0) ? -1:start;
    }
}
