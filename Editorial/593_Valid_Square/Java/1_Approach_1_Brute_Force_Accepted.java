class Solution {

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[][] p = { p1, p2, p3, p4 };
        return checkAllPermutations(p, 0);
    }

    private double dist(int[] p1, int[] p2) {
        return (
            (p2[1] - p1[1]) * (p2[1] - p1[1]) +
            (p2[0] - p1[0]) * (p2[0] - p1[0])
        );
    }

    private boolean check(int[] p1, int[] p2, int[] p3, int[] p4) {
        double d1 = dist(p1, p2);
        double d2 = dist(p2, p3);
        double d3 = dist(p3, p4);
        double d4 = dist(p1, p4);
        double d5 = dist(p1, p3);
        double d6 = dist(p2, p4);

        return d1 > 0 && d1 == d2 && d2 == d3 && d3 == d4 && d5 == d6;
    }

    private void swap(int[][] p, int x, int y) {
        int[] temp = p[x];
        p[x] = p[y];
        p[y] = temp;
    }

    private boolean checkAllPermutations(int[][] p, int l) {
        if (l == 4) {
            if (
                Arrays.equals(p[0], p[1]) ||
                Arrays.equals(p[1], p[2]) ||
                Arrays.equals(p[2], p[3]) ||
                Arrays.equals(p[3], p[0]) ||
                Arrays.equals(p[0], p[2]) ||
                Arrays.equals(p[1], p[3])
            ) {
                return false;
            }
            return check(p[0], p[1], p[2], p[3]);
        } else {
            boolean res = false;
            for (int i = l; i < 4; i++) {
                swap(p, l, i);
                res |= checkAllPermutations(p, l + 1);
                swap(p, l, i);
                if (res) return true;
            }
            return res;
        }
    }
}
