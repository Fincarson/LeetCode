class Solution {
public:
    int shortestWay(string source, string target) {
        
        // Boolean array to mark all characters of source
        bool sourceChars[26] = {false};
        for (auto c : source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (auto c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Optimal Answer for a given ending index. Memoizing using an Array
        vector <int> memo(target.length(), INT_MAX);
        memo[0] = 1;

        for (int endingIndex = 1; endingIndex < target.length(); endingIndex++) {
            if (isSubsequence(0, endingIndex, source, target)) {
                memo[endingIndex] = 1;
            } else {
                for (int partitionIndex = endingIndex - 1; partitionIndex >= 0; partitionIndex--) {
                    if (memo[partitionIndex] != INT_MAX &&
                            isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                        memo[endingIndex] = min(memo[endingIndex], memo[partitionIndex] + 1);
                    }
                }
            }
        }

        return memo[target.length() - 1];
    }

    
    // For toCheck passing indices of target, both included.
    bool isSubsequence(int start, int end, string source, string target) {

        if end - start + 1 > source.length() {
            return false;
        }

        int i = start;
        int j = 0;

        while (i <= end && j < source.length()) {
            if (target[i] == source[j]) {
                i++;
            }
            j++;
        }

        return i == end + 1;
    }
};
