class Solution {
public:
    int maxLength(vector<string>& arr) {
        // Use depth first search recursion through arr
        // building from an initial empty string
        return dfs(arr, 0, "");
    }

private:
    int dfs(vector<string>& arr, int pos, string res) {    
        // Use a set to check res for duplicate characters
        unordered_set<char> resSet(res.begin(), res.end());
        if (res.size() != resSet.size())
            return 0;
        
        // Recurse through each possible next option
        // and find the best answer
        int best = res.size();
        for (int i = pos; i < arr.size(); i++)
            best = max(best, dfs(arr, i + 1, res + arr[i]));
        return best;
    }
};
