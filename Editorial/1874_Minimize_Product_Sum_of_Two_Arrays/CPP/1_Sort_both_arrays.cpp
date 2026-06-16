class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        // Sort nums1 in ascending order, and nums2 in
        // descending order.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>());
        
        // Initialize sum as 0.
        int ans = 0;

        // Iterate over two sorted arrays and calculate the 
        // cumulative product sum.
        for (int i = 0; i < nums1.size(); ++i) {
            ans += nums1[i] * nums2[i];
        } 

        return ans;        
    }
};
