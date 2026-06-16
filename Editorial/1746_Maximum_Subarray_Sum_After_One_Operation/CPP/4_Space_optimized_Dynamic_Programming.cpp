class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array.

        // Initialize variables to store the maximum sums.
        int maxSumWithoutSquare = nums[0];
        int maxSumWithSquare = nums[0] * nums[0];
        int maxSum = maxSumWithSquare;

        for (int index = 1; index < n; index++) {
            // Option 1: Start a new subarray.
            // Option 2: Square the current element.
            // Option 3: Do not square the element.
            maxSumWithSquare =
                max(max(nums[index] * nums[index],
                        maxSumWithoutSquare + nums[index] * nums[index]),
                    maxSumWithSquare + nums[index]);

            // Option 1: Start a new subarray.
            // Option 2: Continue the previous subarray.
            maxSumWithoutSquare =
                max(nums[index], maxSumWithoutSquare + nums[index]);

            // Update maxSum
            maxSum = max(maxSum, maxSumWithSquare);
        }

        return maxSum;
    }
};
