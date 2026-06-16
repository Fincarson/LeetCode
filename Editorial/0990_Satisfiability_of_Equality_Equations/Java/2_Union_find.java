class Solution {
    public boolean equationsPossible(String[] equations) {
        int root[] = new int[26];
        for (int i = 0; i < 26; i++) {
            root[i] = i;
        }

        for (String eqn : equations) {
            if (eqn.charAt(1) == '=') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                union(root, x, y);
            }
        }

        for (String eqn : equations) {
            if (eqn.charAt(1) == '!') {
                int x = eqn.charAt(0) - 'a';
                int y = eqn.charAt(3) - 'a';
                if (find(root, x) == find(root, y))
                    return false;
            }
        }

        return true;
    }

    private static int find(int[] root, int x) {
        if (root[x] != x)
            root[x] = find(root, root[x]);
        return root[x];
    }

    private static void union(int[] root, int x, int y) {
        x = find(root, x);
        y = find(root, y);
        if (x != y)
            root[x] = y;
    }
}
