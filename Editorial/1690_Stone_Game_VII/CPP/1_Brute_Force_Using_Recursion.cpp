class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }
        return abs(findDifference(prefixSum, 0, n - 1, true));
    }

    int findDifference(vector<int>& prefixSum, int start, int end, bool alice) {
        if (start == end) {
            return 0;
        }
        int difference;
        int scoreRemoveFirst = prefixSum[end + 1] - prefixSum[start + 1];
        int scoreRemoveLast = prefixSum[end] - prefixSum[start];

        if (alice) {
            difference = max(findDifference(prefixSum, start + 1, end, !alice) +
                                 scoreRemoveFirst,
                             findDifference(prefixSum, start, end - 1, !alice) +
                                 scoreRemoveLast);
        } else {
            difference = min(findDifference(prefixSum, start + 1, end, !alice) -
                                 scoreRemoveFirst,
                             findDifference(prefixSum, start, end - 1, !alice) -
                                 scoreRemoveLast);
        }
        return difference;
    }
};
