class Solution {
public:
    unordered_map<string, int> wordCount;
    int wordLength;
    int substringSize;
    int k;
    bool check(int i, string s) {
        // Copy the original dictionary to use for this index
        unordered_map<string, int> remaining = wordCount;
        int wordsUsed = 0;
        // Each iteration will check for a match in words
        for (int j = i; j < i + substringSize; j += wordLength) {
            string sub = s.substr(j, wordLength);
            if (remaining[sub] != 0) {
                remaining[sub]--;
                wordsUsed++;
            } else {
                break;
            }
        }
        return wordsUsed == k;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        k = words.size();
        wordLength = words[0].size();
        substringSize = wordLength * k;
        for (string word : words) {
            if (wordCount.find(word) == wordCount.end()) {
                wordCount[word] = 1;
            } else {
                wordCount[word] += 1;
            }
        }
        vector<int> answer;
        for (int i = 0; i < n - substringSize + 1; i++) {
            if (check(i, s)) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};
