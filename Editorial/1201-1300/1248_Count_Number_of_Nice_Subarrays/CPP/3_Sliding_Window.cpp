class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int subarrays = 0, initialGap = 0, qsize = 0, start = 0;
        for (int end = 0; end < nums.size(); end++) {
            // If current element is odd, increment qsize by 1.
            if (nums[end] % 2 == 1) {
                qsize++;
            }
            // If qsize is k, calculate initialGap and add it in the answer.
            if (qsize == k) {
                initialGap = 0;
                // Calculate the number of even elements in the beginning of
                // subarray.
                while (qsize == k) {
                    qsize -= nums[start] % 2;
                    initialGap++;
                    start++;
                }
            }
            subarrays += initialGap;
        }

        return subarrays;
    }
};
