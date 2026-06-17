class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        // Number of substrings can exceed the integer range
        long long answer = 0;
        vector<long long> prefixCount(26, 0);

        for (int i = 0; i < s.size(); i++) {
            // Increment the number of times we encountered the current letter
            // so far.
            prefixCount[s[i] - 'a']++;

            // Current letter can be paired with all the occurrences of it that
            // comes before, including itself, to form a valid substring.
            answer += prefixCount[s[i] - 'a'];
        }

        return answer;
    }
};
