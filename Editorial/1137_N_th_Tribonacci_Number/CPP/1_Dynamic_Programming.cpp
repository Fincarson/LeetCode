class Solution {
private:
    unordered_map<int, int> dp = {
        {0, 0},
        {1, 1},
        {2, 1}
    };
    
    int dfs(int i) {
        if (dp.count(i)) {
            return dp[i];
        }
        
        int answer = dfs(i - 1) + dfs(i - 2) + dfs(i - 3);
        dp[i] = answer;
        return answer;
    }
    
public:
    int tribonacci(int n) {
        return dfs(n);
    }
};
