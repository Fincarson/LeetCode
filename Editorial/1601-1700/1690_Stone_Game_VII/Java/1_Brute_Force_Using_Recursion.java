class Solution {
    int[] prefixSum;

    private int findDifference(int start, int end, boolean alice) {
        if (start == end) {
            return 0;
        }
        int difference;
        int scoreRemoveFirst = prefixSum[end + 1] - prefixSum[start + 1];
        int scoreRemoveLast = prefixSum[end] - prefixSum[start];

        if (alice) {
            difference = Math.max(
                    findDifference(start + 1, end, !alice) + scoreRemoveFirst,
                    findDifference(start, end - 1, !alice) + scoreRemoveLast);
        } else {
            difference = Math.min(
                    findDifference(start + 1, end, !alice) - scoreRemoveFirst,
                    findDifference(start, end - 1, !alice) - scoreRemoveLast);
        }
        return difference;
    }

    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }
        return Math.abs(findDifference(0, n - 1, true));
    }
}
