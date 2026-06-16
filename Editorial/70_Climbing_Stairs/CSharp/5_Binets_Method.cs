/* C# */

public class Solution {
    public int ClimbStairs(int n) {
        int[][] q = new int [2][] { new int[2] { 1, 1 }, new int[2] { 1, 0 } };
        int[][] res = Pow(q, n);
        return res[0][0];
    }

    public int[][] Pow(int[][] a, int n) {
        int[][] ret =
            new int [2][] { new int[2] { 1, 0 }, new int[2] { 0, 1 } };
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = Multiply(ret, a);
            }

            n >>= 1;
            a = Multiply(a, a);
        }

        return ret;
    }

    public int[][] Multiply(int[][] a, int[][] b) {
        int[][] c = new int [2][] { new int[2] { 0, 0 }, new int[2] { 0, 0 } };
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }

        return c;
    }
}
