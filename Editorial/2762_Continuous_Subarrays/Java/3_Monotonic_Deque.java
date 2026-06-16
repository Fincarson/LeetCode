class Solution {

    public long continuousSubarrays(int[] nums) {
        // Monotonic deque to track maximum and minimum elements
        Deque<Integer> maxQ = new ArrayDeque<>();
        Deque<Integer> minQ = new ArrayDeque<>();
        int left = 0;
        long count = 0;

        for (int right = 0; right < nums.length; right++) {
            // Maintain decreasing monotonic queue for maximum values
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] < nums[right]) {
                maxQ.pollLast();
            }
            maxQ.offerLast(right);

            // Maintain increasing monotonic queue for minimum values
            while (!minQ.isEmpty() && nums[minQ.peekLast()] > nums[right]) {
                minQ.pollLast();
            }
            minQ.offerLast(right);

            // Shrink window if max-min difference exceeds 2
            while (
                !maxQ.isEmpty() &&
                !minQ.isEmpty() &&
                nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > 2
            ) {
                // Move left pointer past the element that breaks the condition
                if (maxQ.peekFirst() < minQ.peekFirst()) {
                    left = maxQ.peekFirst() + 1;
                    maxQ.pollFirst();
                } else {
                    left = minQ.peekFirst() + 1;
                    minQ.pollFirst();
                }
            }

            // Add count of all valid subarrays ending at current right pointer
            count += right - left + 1;
        }
        return count;
    }
}
