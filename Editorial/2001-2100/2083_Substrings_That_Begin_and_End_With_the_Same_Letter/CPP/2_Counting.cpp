class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long answer = 0;
        vector<long long> frequencyCount(26, 0);

        // Count the frequency of each character in the string.
        for (char ch : s) {
            frequencyCount[ch - 'a']++;
        }

        // Calculate the total number of valid substrings.
        for (long long currentCount : frequencyCount) {
            // Using (currentCount + 1) choose 2 to calculate valid substrings
            // for the current letter.
            answer += ((currentCount + 1) * currentCount) / 2;
        }

        return answer;
    }
};
