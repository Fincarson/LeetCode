class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        // Map to track the frequencies of elements
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        // List to track all the frequencies
        List<Integer> frequencies = new ArrayList<>(map.values());

        // Sorting the frequencies
        Collections.sort(frequencies);

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        for (int i = 0; i < frequencies.size(); i++) {
            // Removing frequencies[i] elements, which equates to
            // removing one unique element
            elementsRemoved += frequencies.get(i);

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size() - i;
            }
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
}
