class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxReach(n);

        // Step 1: Compute the maximum reachable index for each starting index
        // from last to first
        maxReach[n - 1] = n - 1; // The last index can only reach itself
        for (int i = n - 2; i >= 0; i--) {
            // Check if adjacent elements have different parity
            if ((nums[i] % 2) != (nums[i + 1] % 2)) {
                maxReach[i] = maxReach[i + 1]; // Extend the reach
            } else {
                maxReach[i] = i; // Can only reach itself
            }
        }

        vector<bool> ans(queries.size());

        // Step 2: Answer each query based on precomputed 'maxReach'
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            // Check if the query range [start, end] lies within the max
            // reachable range
            ans[i] = end <= maxReach[start];
        }

        return ans;
    }
};
