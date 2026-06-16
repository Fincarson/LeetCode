class Solution {
public:
    string longestWord(vector<string>& words) {
        // Sort the words lexicographically
        sort(words.begin(), words.end());

        // Set to store valid words
        unordered_set<string> validWords;
        string longestValidWord = "";

        // Iterate through each word
        for (string& currentWord : words) {
            // Check if the word is of length 1 or if its prefix exists in the
            // set
            if (currentWord.length() == 1 ||
                validWords.find(currentWord.substr(
                    0, currentWord.length() - 1)) != validWords.end()) {
                validWords.insert(currentWord);

                if (longestValidWord.length() < currentWord.length()) {
                    longestValidWord = currentWord;
                }
            }
        }

        return longestValidWord;
    }
};
