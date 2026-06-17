class Solution {

    public int largestUniqueNumber(int[] nums) {
        // Create a HashMap to store the frequency of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        // Populate the frequencyMap
        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Initialize the result to -1 (default if no unique number is found)
        int largestUnique = -1;

        for (int num : frequencyMap.keySet()) {
            // Check if the number appears only once and is larger than the current largestUnique
            if (frequencyMap.get(num) == 1 && num > largestUnique) {
                largestUnique = num;
            }
        }

        return largestUnique;
    }
}
