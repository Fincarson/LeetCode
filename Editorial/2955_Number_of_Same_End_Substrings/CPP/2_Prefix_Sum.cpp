class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        int n = s.length();
        // 2D array to store prefix sum of character frequencies for each
        // character 'a' to 'z'
        vector<vector<int>> charFreqPrefixSum(26, vector<int>(n, 0));

        // Fill the frequency array
        for (int i = 0; i < n; i++) {
            charFreqPrefixSum[s[i] - 'a'][i]++;
        }

        // Convert the frequency array into a prefix sum array
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < n; j++) {
                charFreqPrefixSum[i][j] += charFreqPrefixSum[i][j - 1];
            }
        }

        vector<int> results(queries.size());

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int leftIndex = queries[i][0];
            int rightIndex = queries[i][1];
            int countSameEndSubstrings = 0;

            // For each character, calculate the frequency of occurrences within
            // the query range
            for (int charIndex = 0; charIndex < 26; charIndex++) {
                // Calculate frequency within the query range
                int leftFreq =
                    (leftIndex == 0)
                        ? 0
                        : charFreqPrefixSum[charIndex][leftIndex - 1];
                int rightFreq = charFreqPrefixSum[charIndex][rightIndex];
                int frequencyInRange = rightFreq - leftFreq;

                // Calculate the number of same-end substrings for this
                // character
                countSameEndSubstrings +=
                    frequencyInRange * (frequencyInRange + 1) / 2;
            }

            results[i] = countSameEndSubstrings;
        }

        return results;
    }
};
