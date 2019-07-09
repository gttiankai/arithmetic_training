package DFS.surrounded_regions_130;

public class Solution1 {

    public class UFUnionFind {
        private int[] id;   // 父链接数组
        private int[] sz;   // 各个根节点所对应的分量的大小
        private int count;  // 连通分量的数量

        /**
         * 以整数标识(0 ~ N-1)初始化 N 个触点
         * @param N
         */
        public UFUnionFind(int N){
            count = N;
            id = new int[N];
            for (int i = 0; i < N; i++) {
                id[i] = i;
            }
            sz = new int[N];
            for (int i = 0; i < N; i++) {
                sz[i] = 1;
            }

        }

        /**
         * p(0 ~ N-1)所在的分量的标识符
         * @param p
         * @return
         */
        public int find(int p){
            while (p != id[p]) {
                p = id[p];
            }
            return p;
        }

        /**
         * 在 p 和 q 之间添加一条连接
         * @param p
         * @param q
         */
        public void union(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot) {
                return;
            }
            // 将连通分量比较小的连接到连通分量比较大的树上
            if (sz[pRoot] < sz[qRoot]) {
                id[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else {
                id[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];

            }
            count--;
        }

        /**
         * 如果 p 和 q 存在于同一个分量中,则返回 true
         * 否则,返回 false
         * @param p
         * @param q
         * @return
         */
        public boolean connected(int p, int q){
            return find(p) == find(q);
        }
        /**
         * 连通分量的数量
         * @return
         */
        public int count() {
            return count;
        }
    }



    /**
     * 主要时对相连的元素的处理,
     * unite test:
     * input:
     * [["O","X","X","O","X"],
     *  ["X","O","O","X","O"],
     *  ["X","O","X","O","X"],
     *  ["O","X","O","O","X"],
     *  ["X","X","O","X","O"]]
     *
     * expected
     * [["O","X","X","O","X"],
     *  ["X","X","X","X","O"],
     *  ["X","X","X","O","X"],
     *  ["O","X","O","O","X"],
     *  ["X","X","O","X","O"]]
     * */
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }
        int m = board.length;
        int n = board[0].length;
        UFUnionFind uf = new UFUnionFind(m * n + 1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O') {
                    uf.union( i*n + j,m*n);
                } else if (board[i][j] == 'O') {

                    if (board[i - 1][j] == 'O') {

                        uf.union(i * n + j, (i - 1) * n + j);

                    } else if (board[i + 1][j] == 'O') {

                        uf.union(i * n + j, (i + 1) * n + j);

                    } else if (board[i][j - 1] == 'O') {

                        uf.union(i * n + j, i * n + j - 1);


                    } else if (board[i][j + 1] == 'O') {

                        uf.union(i * n + j, i * n + j + 1);

                    }
                }
            }
        }
        for (int i = 0; i < m;i++) {
            for (int j = 0; j < n; j++) {
                if (!uf.connected(i*n + j, m*n)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    public static void main(String[] arguments) {
        char[][] board = {
                {'O','X', 'X','O', 'X'},
                {'X','O', 'O','X', 'O'},
                {'X','O', 'X','O', 'X'},
                {'X','O', 'O','O', 'O'},
                {'X','X', 'O','X', 'O'}
        };
        Solution1 solution = new Solution1();
        solution.solve(board);
    }
}


