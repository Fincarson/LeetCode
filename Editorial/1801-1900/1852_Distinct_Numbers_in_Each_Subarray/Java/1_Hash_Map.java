class Solution {

    public int[] distinctNumbers(int[] nums, int k) {
        int len = nums.length;
        int[] answer = new int[len - k + 1];

        // Map to store number -> frequency count
        Map<Integer, Integer> freqMap = new HashMap<>();

        // Process first window
        for (int pos = 0; pos < k; pos++) {
            freqMap.put(nums[pos], freqMap.getOrDefault(nums[pos], 0) + 1);
        }
        answer[0] = freqMap.size();

        // Slide window and update counts
        for (int pos = k; pos < len; pos++) {
            // Remove leftmost element of previous window
            int leftNum = nums[pos - k];
            freqMap.put(leftNum, freqMap.get(leftNum) - 1);
            freqMap.remove(leftNum, 0);

            // Add rightmost element of current window
            int rightNum = nums[pos];
            freqMap.put(rightNum, freqMap.getOrDefault(rightNum, 0) + 1);

            // Store distinct count for current window
            answer[pos - k + 1] = freqMap.size();
        }

        return answer;
    }
}
