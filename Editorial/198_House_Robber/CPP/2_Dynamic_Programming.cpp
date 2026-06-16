class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();

        // Special handling for empty case.
        if (N == 0) {
            return 0;
        }

        vector<int> maxRobbedAmount(N + 1);

        // Base case initializations.
        maxRobbedAmount[N] = 0;
        maxRobbedAmount[N - 1] = nums[N - 1];

        // DP table calculations.
        for (int i = N - 2; i >= 0; --i) {
            // Same as the recursive solution.
            maxRobbedAmount[i] =
                max(maxRobbedAmount[i + 1], maxRobbedAmount[i + 2] + nums[i]);
        }

        return maxRobbedAmount[0];
    }
};
