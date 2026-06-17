class Solution {
public:
    vector<int> longestCommonSubsequence(const vector<vector<int>>& arrays) {
        unordered_map<int, int> frequencies;
        vector<int> longestCommonSubseq;

        // Count the frequency of each number across all arrays
        for (const auto& array : arrays) {
            for (int num : array) {
                frequencies[num] += 1;
                // If the number appears in all arrays, add it to the result
                if (frequencies[num] == arrays.size()) {
                    longestCommonSubseq.push_back(num);
                }
            }
        }

        return longestCommonSubseq;
    }
};
