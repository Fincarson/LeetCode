class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int N = stations.length;
        double[] deltas = new double[N-1];
        for (int i = 0; i < N-1; ++i)
            deltas[i] = stations[i+1] - stations[i];

        double[][] dp = new double[N-1][K+1];
        //dp[i][j] = answer for deltas[:i+1] when adding j gas stations
        for (int i = 0; i <= K; ++i)
            dp[0][i] = deltas[0] / (i+1);

        for (int p = 1; p < N-1; ++p)
            for (int k = 0; k <= K; ++k) {
                double bns = 999999999;
                for (int x = 0; x <= k; ++x)
                    bns = Math.min(bns, Math.max(deltas[p] / (x+1), dp[p-1][k-x]));
                dp[p][k] = bns;
            }

        return dp[N-2][K];
    }
}
