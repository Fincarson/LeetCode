class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        queue<int> oddIndices;
        int subarrays = 0, lastPopped = -1, initialGap = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If element is odd, push it in queue.
            if (nums[i] % 2 == 1) {
                oddIndices.push(i);
            }
            // If queue size exceeds k, perform pop operation.
            if (oddIndices.size() > k) {
                lastPopped = oddIndices.front();
                oddIndices.pop();
            }
            // If there are exactly k odd numbers,
            // add the number of even numbers in the
            // beginning of the subarray to the result.
            if (oddIndices.size() == k) {
                initialGap = oddIndices.front() - lastPopped;
                subarrays += initialGap;
            }
        }

        return subarrays;
    }
};
