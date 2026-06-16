class Solution {
    public int minProductSum(int[] nums1, int[] nums2) {
        // Sort nums1 in ascending order.
        Arrays.sort(nums1);

        // Initialize a PriorityQueue pq as a Max-Heap, and add 
        // every element of nums2 to pq.
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());    
        for (int num : nums2) {
            pq.add(num);
        }
        
        // Initialize the product sum as 0 before the iteration.
        int ans = 0;
        
        // During the iteration
        for (int idx = 0; idx < nums2.length; ++idx) {
            // Add the product of nums[idx] and the maximum element
            // left in pq, remove this element from pq.
            ans += nums1[idx] * pq.poll();
        }
        
        return ans;       
    }
}
