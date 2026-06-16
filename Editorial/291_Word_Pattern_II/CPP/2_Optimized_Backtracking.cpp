class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        vector<string> symbols(26, "");
        unordered_set<string> wordSet;

        return isMatch(s, 0, pattern, 0, symbols, wordSet);
    }

private:
    bool isMatch(string& s, int sIndex, string& pattern, int pIndex,
                 vector<string>& symbols, unordered_set<string>& wordSet) {
        // Base case: reached end of pattern
        if (pIndex == pattern.length()) {
            return sIndex == s.length(); // True if and only if also reached end of s
        }

        // Get current pattern character
        char symbol = pattern[pIndex];

        // This symbol already has an associated word
        if (!symbols[symbol - 'a'].empty()) {
            string word = symbols[symbol - 'a'];
            // Check if it matches s[sIndex...sIndex + word.length()]
            if (s.compare(sIndex, word.length(), word)) {
                return false;
            }
            // If it matches continue to match the rest
            return isMatch(s, sIndex + word.length(), pattern, pIndex + 1,
                           symbols, wordSet);
        }

        // Count the number of spots the remaining symbols in the pattern take
        int filledSpots = 0;
        for (int i = pIndex + 1; i < pattern.length(); i++) {
            char p = pattern[i];
            filledSpots += symbols[p - 'a'].empty() ? 1 : symbols[p - 'a'].length();
        }

        // This symbol does not have an associated word
        for (int k = sIndex + 1; k <= s.length() - filledSpots; k++) {
            string newWord = s.substr(sIndex, k - sIndex);
            if (wordSet.find(newWord) != wordSet.end())
                continue;
            // Create or update it
            symbols[symbol - 'a'] = newWord;
            wordSet.insert(newWord);
            // Continue to match the rest
            if (isMatch(s, k, pattern, pIndex + 1, symbols, wordSet)) {
                return true;
            }
            // Backtracking
            symbols[symbol - 'a'] = "";
            wordSet.erase(newWord);
        }
        // No mappings were valid
        return false;
    }
};
