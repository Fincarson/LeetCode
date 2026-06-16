/** Vanilla Disjoint-set Union Find **/
class DisjointSet {
    private int[] parents;

    public void Union(int a, int b) {
        int rootA = Find(a);
        int rootB = Find(b);
        // If both a and b have same root, i.e. they both belong to the same set, hence we don't need to take union
        if (rootA == rootB) return;
        // Take union by assigning rootA as the parent of rootB
        this.parents[rootB] = rootA;
    }

    public int Find(int a) {
        // Traverse all the way to the top (root) going through the parent nodes
        while (a != this.parents[a]) {
            a = this.parents[a];
        }
        return a;
    }

    public boolean isInSameGroup(int a, int b) {
        // Return true if both a and b belong to the same set, otherwise return false
        return Find(a) == Find(b);
    }

    public DisjointSet(int N) {
        this.parents = new int[N + 1];
        // Set the initial parent node to itself
        for (int i = 1; i <= N; ++i) {
            this.parents[i] = i;
        }
    }
}
