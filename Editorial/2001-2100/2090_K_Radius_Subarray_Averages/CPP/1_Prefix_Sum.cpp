class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // When a single element is considered then its average will be the number itself only.
        if (k == 0) {
            return nums;
        }

        int windowSize = 2 * k + 1;
        int n = nums.size();
        vector<int> averages(n, -1);

        // Any index will not have 'k' elements in it's left and right.
        if (windowSize > n) {
            return averages;
        }

        // Generate 'prefix' array for 'nums'.
        // 'prefix[i + 1]' will be sum of all elements of 'nums' from index '0' to 'i'.
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        // We iterate only on those indices which have atleast 'k' elements in their left and right.
        // i.e. indices from 'k' to 'n - k'
        for (int i = k; i < (n - k); ++i) {
            int leftBound = i - k, rightBound = i + k;
            long long subArraySum = prefix[rightBound + 1] - prefix[leftBound];
            int average = subArraySum / windowSize;
            averages[i] = average;
        }

        return averages;
    }
};
