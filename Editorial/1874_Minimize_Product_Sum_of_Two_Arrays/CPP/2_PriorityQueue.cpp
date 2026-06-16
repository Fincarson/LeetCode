class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        // Sort nums1 in ascending order.
        sort(nums1.begin(), nums1.end());
        
        // Initialize a PriorityQueue pq as a Max-Heap, and add 
        // every element of nums2 to pq.
        priority_queue<int, vector<int>> pq;      
        for (int num : nums2)
            pq.push(num);
        
        // Initialize the product sum as 0 before the iteration.
        int ans = 0;

        // During the iteration 
        for (int idx = 0; idx < nums2.size(); ++idx) {
            // Add the product of nums[idx] and the maximum element
            // left in pq, remove this element from pq.
            ans += nums1[idx] * pq.top();
            pq.pop();
        }
        
        return ans;       
    }
};
