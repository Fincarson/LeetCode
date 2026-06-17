class Solution {
public:
    int shortestWay(string source, string target) {
        
        // Boolean array to mark all characters of source
        bool sourceChars[26] = {false};
        for (char c : source) {
            sourceChars[c - 'a'] = true;
        }

        // Check if all characters of target are present in source
        // If any character is not present, return -1
        for (char c : target) {
            if (!sourceChars[c - 'a']) {
                return -1;
            }
        }

        // Optimal Answer for a given ending index. Memoizing using an Array
        int memo[target.length()];
        fill(memo, memo + target.length(), INT_MAX / 2);

        // Want to find optimal answer for the last index.
        // Case when task is not possible is already handled
        return optimalAnswer(target.length() - 1, memo, source, target);
    }
    
    int optimalAnswer(int endingIndex, int memo[], string source, string target) {

        // Base Case
        if (endingIndex == 0) {
            return 1;
        }

        // If already calculated, return
        if (memo[endingIndex] != INT_MAX / 2) {
            return memo[endingIndex];
        }

        // If subsequence, return 1
        if (isSubsequence(0, endingIndex, source, target)) {
            memo[endingIndex] = 1;
            return 1;
        }

        // If not subsequence, partition into two parts and find minimum
        int answer = INT_MAX / 2;

        for (int partitionIndex = 0; partitionIndex < endingIndex; partitionIndex++) {

            // Check for subsequence only if the answer is less
            // than the current answer. Using AND Short Circuiting
            if (optimalAnswer(partitionIndex, memo, source, target) + 1 < answer
                    && isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                answer = min(answer, optimalAnswer(partitionIndex, memo, source, target) + 1);
            }
        }

        // Memoize and return
        memo[endingIndex] = answer;
        return answer;
    }

    // For toCheck, passing indices of target, both included.
    bool isSubsequence(int start, int end, string toCheck, string inString) {
        int i = start;
        int j = 0;

        while (i <= end && j < inString.length()) {
            if (toCheck[i] == inString[j]) {
                i++;
            }
            j++;
        }

        return i == end + 1;
    }
};
