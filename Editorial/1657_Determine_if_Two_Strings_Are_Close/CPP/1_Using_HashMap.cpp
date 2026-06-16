class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> word1Map;
        unordered_map<char, int> word2Map;
        vector<char> word1KeySet, word2KeySet, word1FrequencyList,
            word2FrequencyList;
        for (char c : word1) {
            word1Map[c - 'a'] = word1Map[c - 'a'] + 1;
        }
        for (char c : word2) {
            word2Map[c - 'a'] = word2Map[c - 'a'] + 1;
        }
        for (auto keyValuePair : word1Map) {
            word1KeySet.push_back(keyValuePair.first);
            word1FrequencyList.push_back(keyValuePair.second);
        }
        for (auto keyValuePair : word2Map) {
            word2KeySet.push_back(keyValuePair.first);
            word2FrequencyList.push_back(keyValuePair.second);
        }
        sort(word1KeySet.begin(), word1KeySet.end());
        sort(word2KeySet.begin(), word2KeySet.end());

        if (word1KeySet != word2KeySet) return false;

        sort(word1FrequencyList.begin(), word1FrequencyList.end());
        sort(word2FrequencyList.begin(), word2FrequencyList.end());

        return word1FrequencyList == word2FrequencyList;
    }
};
