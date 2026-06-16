class Solution {
    public int findMaxK(int[] nums) {
        // Initialize a HashSet to store negative numbers
        Set<Integer> neg = new HashSet<>();
        
        // Loop through the numbers and insert negative numbers into the set
        for (int num : nums) {
            if (num < 0)
                neg.add(num);
        }
        
        int ans = -1;
        
        for (int num : nums) {
            // If current number is greater than ans and its negation exists in the set
            if (num > ans && neg.contains(-num))
                ans = num;
        }
        
        return ans;
    }
}
