package test;

public class Cut {
    public static int cut(int[] p, int n) {
        if (n == 0) {
            return 0;
        }
        int q = Integer.MIN_VALUE;
        for (int i = 1; i <= n; i++) {
            q = Math.max(q, p[i - 1] + cut(p, n - i));
        }
        return q;
    }

    public static int cutMode(int[] p, int n) {
        int[] r = new int[p.length + 1];
        for (int i = 0; i <= p.length; i++) {
            r[i] = -1;
        }
        return cut(p, n, r);
    }

    public static int cut(int[] p, int n, int[] r) {
        int result = -1;
        // 备忘录的查找
        if (r[n] != -1) {
            return r[n];
        }
        if (n == 0) {
            result = 0;
        }
        for (int i = 0; i <= n; i++) {
            // 递归壳的进行求值
            result = Math.max(result, p[i - 1] + cut(p, n - i, r));
        }
        // 将备忘录赋值
        r[n] = result;
        return result;
    }

    public static int buttom_up_cut(int[] p) {
        int[] r = new int[p.length + 1];
        for (int i = 1; i <= p.length; i++) {
            int q = -1;

            for (int j = 1; j <= i; j++) {
                q = Math.max(q, p[j - 1] + r[i - j]);
            }
            r[i] = q;
        }
        return r[p.length];
    }

    public static void main(String[] args) {
        int[] p = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
        int length = 4;
        System.out.println("the max value: " + cut(p, length));
    }
}
