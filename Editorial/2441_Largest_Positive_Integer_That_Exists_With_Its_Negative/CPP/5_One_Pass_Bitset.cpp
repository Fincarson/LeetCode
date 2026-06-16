class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        // Initialize a bitset to keep track of seen numbers
        bitset<2048> seen;

        for (int num : nums) {
            const int abs_num = abs(num);

            // If the absolute value is greater than the current answer
            // and its negation was seen before,
            // update the answer
            if (abs_num > ans && seen[-num + 1024])
                ans = abs_num;
            // Mark the current number as seen
            seen[num + 1024] = true;
        }

        return ans;
    }
};
