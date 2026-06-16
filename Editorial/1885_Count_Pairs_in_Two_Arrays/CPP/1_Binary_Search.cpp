class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();  // nums2 is the same length

        // Difference[i] stores nums1[i] - nums2[i]
        vector<long long> difference(N);
        for (int i = 0; i < N; i++) {
            difference[i] = static_cast<long>(nums1[i]) - nums2[i];
        }
        sort(difference.begin(), difference.end());

        // Count the number of valid pairs
        long long result = 0;
        for (int i = 0; i < N; i++) {
            // All indices j following i make a valid pair
            if (difference[i] > 0) {
                result += N - i - 1;
            } else {
                // Binary search to find the first index j
                // that makes a valid pair with i
                int left = i + 1;
                int right = N - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    // If difference[mid] is a valid pair, search in left half
                    if (difference[i] + difference[mid] > 0) {
                        right = mid - 1;
                    // If difference[mid] does not make a valid pair, search in right half
                    } else {
                        left = mid + 1;
                    }
                }
                // After the search left points to the first index j that makes
                // a valid pair with i so we count that and all following indices
                result += N - left;
            }
        }
        return result;
    }
};
