class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size(); // nums2 is the same length

        // Difference[i] stores nums1[i] - nums2[i]
        vector<int> difference(N);
        for (int i = 0; i < N; i++) {
            difference[i] = nums1[i] - nums2[i];
        }
        sort(begin(difference), end(difference));

        // Count the number of valid pairs
        long long result = 0;
        int left = 0;
        int right = N - 1;
        while (left < right) {
            // Left makes a valid pair with right
            // Right also makes a valid pair with the indices between the pointers
            if (difference[left] + difference[right] > 0) {
                result += right - left;
                right--;
            // Left and right are not a valid pair
            } else {
                left++;
            }
        }
        return result;
    }
};
