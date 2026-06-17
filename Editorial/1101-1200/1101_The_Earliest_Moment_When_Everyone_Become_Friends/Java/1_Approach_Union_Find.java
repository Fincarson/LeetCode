class Solution {
    public int earliestAcq(int[][] logs, int n) {
        // In order to ensure that we find the _earliest_ moment,
        //  first of all we need to sort the events in chronological order.
        Arrays.sort(logs, new Comparator<int[]>() {
            @Override
            public int compare(int[] log1, int[] log2) {
                Integer tsp1 = new Integer(log1[0]);
                Integer tsp2 = new Integer(log2[0]);
                return tsp1.compareTo(tsp2);
            }
        });

        // Initially, we treat each individual as a separate group.
        int groupCount = n;
        UnionFind uf = new UnionFind(n);

        for (int[] log : logs) {
            int timestamp = log[0];
            int friendA = log[1];
            int friendB = log[2];
            // We merge the groups along the way.
            if (uf.union(friendA, friendB)) {
                groupCount -= 1;
            }

            // The moment when all individuals are connected to each other.
            if (groupCount == 1) {
                return timestamp;
            }
        }

        // There are still more than one groups left,
        //  i.e. not everyone is connected.
        return -1;
    }
}
