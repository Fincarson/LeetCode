class Solution {

    public int largestUniqueNumber(int[] nums) {
        // Use a TreeMap to store numbers and their frequencies
        TreeMap<Integer, Integer> frequencyMap = new TreeMap<>();

        // Populate the frequencyMap
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Initialize the result to -1 (default if no unique number is found)
        int largestUnique = -1;

        // Iterate through the map in reverse order (largest to smallest)
        for (Integer num : frequencyMap.descendingKeySet()) {
            // If the frequency is 1, we've found our largest unique number
            if (frequencyMap.get(num) == 1) {
                largestUnique = num;
                break;
            }
        }

        return largestUnique;
    }
}
