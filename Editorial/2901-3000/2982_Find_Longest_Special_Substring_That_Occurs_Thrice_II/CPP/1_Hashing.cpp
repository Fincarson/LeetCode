class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> frequency(26, vector<int>(s.size() + 1, 0));
        char previousCharacter = s[0];
        int substringLength = 1;

        frequency[s[0] - 'a'][1] = 1;
        int ans = -1;

        for (int charIdx = 1; charIdx < s.size(); charIdx++) {
            char currentCharacter = s[charIdx];
            // If the current character is equal to the previous character, add
            // it to the mapping and increment the substring length.
            if (currentCharacter == previousCharacter) {
                substringLength++;
                int count = 1;
                frequency[currentCharacter - 'a'][substringLength] += 1;
            } else {
                // Otherwise, reset substring length to 1.
                previousCharacter = currentCharacter;
                substringLength = 1;
                frequency[currentCharacter - 'a'][1] += 1;
            }
        }

        // Calculate the cumulative sum from the end for every character and
        // find the maximum possible answer.
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            for (int len = s.size() - 1; len >= 1; len--) {
                frequency[charIdx][len] += frequency[charIdx][len + 1];
                if (frequency[charIdx][len] >= 3) {
                    ans = max(ans, len);
                    break;
                }
            }
        }

        return ans;
    }
};
