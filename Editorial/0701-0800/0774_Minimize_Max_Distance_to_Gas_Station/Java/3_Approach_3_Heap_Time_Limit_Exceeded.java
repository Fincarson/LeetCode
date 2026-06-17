class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) ->
            (double)b[0]/b[1] < (double)a[0]/a[1] ? -1 : 1);
        for (int i = 0; i < N-1; ++i)
            pq.add(new int[]{stations[i+1] - stations[i], 1});

        for (int k = 0; k < K; ++k) {
            int[] node = pq.poll();
            node[1]++;
            pq.add(node);
        }

        int[] node = pq.poll();
        return (double)node[0] / node[1];
    }
}
