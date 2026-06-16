class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        // Find the maximum value in the input array
        int maxValue = 0;
        for (int num : nums) {
            if (num > maxValue) {
                maxValue = num;
            }
        }

        // Create a frequency array based on the maximum value in the input
        vector<int> freq(maxValue + 1, 0);
        int distinctCount = 0;
        vector<int> answer;

        for (int pos = 0; pos < nums.size(); pos++) {
            // Add new number to window
            freq[nums[pos]]++;
            if (freq[nums[pos]] == 1) {
                distinctCount++;
            }

            // Remove number from previous window
            if (pos >= k) {
                freq[nums[pos - k]]--;
                if (freq[nums[pos - k]] == 0) {
                    distinctCount--;
                }
            }

            // Store result when window is complete
            if (pos + 1 >= k) {
                answer.push_back(distinctCount);
            }
        }

        return answer;
    }
};
