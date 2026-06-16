class Solution {

    private void countingSort(int[] arr) {
        // Create the counting hash map.
        Map<Integer, Integer> counts = new HashMap<>();
        // Find the minimum and maximum values in the array.
        int minVal = Arrays.stream(arr).min().getAsInt();
        int maxVal = Arrays.stream(arr).max().getAsInt();

        // Update element's count in the hash map.
        for (int val : arr) {
            counts.put(val, counts.getOrDefault(val, 0) + 1);
        }

        int index = 0;
        // Place each element in its correct position in the array.
        for (int val = minVal; val <= maxVal; ++val) {
            // Append all 'val's together if they exist.
            while (counts.getOrDefault(val, 0) > 0) {
                arr[index] = val;
                index += 1;
                counts.put(val, counts.get(val) - 1);
            }
        }
    }

    public int heightChecker(int[] heights) {
        // Sort the array using counting sort.
        int[] sortedHeights = heights.clone();
        countingSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.length; ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
}
