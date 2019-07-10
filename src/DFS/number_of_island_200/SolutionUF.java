package DFS.number_of_island_200;

public class SolutionUF {

    private class UF {

        private int[] id;
        private int[] sz;
        private int count;

        public UF(int N) {
            count = N;
            id = new int[N];
            sz = new int[N];
            for (int i = 0; i < N; i++) {
                id[i] = i;
                sz[i] = 1;
            }
        }

        public void delete(){
            count--;
        }

        public int getCount() {
            return count;
        }

        public int find(int p) {
            while (p != id[p]) {
                p = id[p];
            }
            return p;
        }

        public boolean connected(int p, int q) {
            return find(p) == find(q);
        }

        public void union(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot) {
                return;
            }

            if (sz[pRoot] < sz[qRoot]) {
                id[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else {
                id[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
            count--;
        }
    }

    /**
     * Runtime: 5 ms, faster than 15.32% of Java online submissions for Number of Islands.
     * Memory Usage: 40.7 MB, less than 99.55% of Java online submissions for Number of Islands.
     * 使用 UF 解决了这个问题
     * */
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        UF uf = new UF(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if ((i - 1 >= 0) && (grid[i - 1][j] == '1')) {
                        uf.union(i * n + j, (i - 1) * n + j);
                    }
                    if ((i + 1 < m) && (grid[i + 1][j] == '1')) {
                        uf.union(i * n + j, (i + 1) * n + j);

                    }
                    if ((j - 1 >= 0) && (grid[i][j - 1] == '1')) {
                        uf.union(i * n + j, i * n + j - 1);
                    }
                    if ((j + 1 < n) && (grid[i][j + 1] == '1')) {
                        uf.union(i * n + j, i * n + j + 1);

                    }
                } else {
                    uf.delete();
                }
            }
        }
        return uf.getCount();
    }

    public static void main(String[] args) {
        char[][] grid = {
                {'1','1','1','1','0'},
                {'1','1','0','1','0'},
                {'1','1','0','0','0'},
                {'0','0','0','0','0'}
        };
        SolutionUF solution = new SolutionUF();
        System.out.println(solution.numIslands(grid));
    }

}
