class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Use depth first search recursion through arr
        // with backracking and a map for results
        unordered_map<char, int> resMap;
        return backtracking(arr, 0, resMap);
    }
    
private:
    int backtracking(vector<string>& arr, int pos, unordered_map<char, int>& resMap) {
        // Check for duplicate characters
        for (auto& kv : resMap)
            if (kv.second > 1)
                return 0;

        // Recurse through each possible next option
        // and find the best answer
        int best = resMap.size();
        for (int i = pos; i < arr.size(); i++) {
            // Add the current word to the result map
            // and recurse to the next position
            string& word = arr[i];
            for (char& c : word) {
                if (resMap.find(c) != resMap.end()) {
                    resMap[c]++;
                } else {
                    resMap[c] = 1;
                }
            }
            best = max(best, backtracking(arr, i + 1, resMap));

            // Backtrack the result map before continuing
            for (char& c : word) {
                if (resMap[c] == 1) {
                    resMap.erase(c);
                } else {
                    resMap[c]--;
                }
            }
        }
        return best;
    }
};
