class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a map to store the anagrams, where the keys are the sorted
        // strings and the values are the lists of anagrams
        unordered_map<string, vector<string>> ans;
        for (auto& s : strs) {
            string key = s;
            // Sort the key
            sort(key.begin(), key.end());
            // If the string is an anagram of another string, they will have the
            // same key and thus be grouped together
            ans[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& p : ans) {
            result.push_back(p.second);
        }
        return result;
    }
};
