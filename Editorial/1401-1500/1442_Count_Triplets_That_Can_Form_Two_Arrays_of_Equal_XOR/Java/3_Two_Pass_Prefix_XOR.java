class Solution {

    public int countTriplets(int[] arr) {
        int[] prefixXOR = new int[arr.length + 1];
        prefixXOR[0] = 0;
        System.arraycopy(arr, 0, prefixXOR, 1, arr.length);
        int size = prefixXOR.length;
        int count = 0;

        // Performing XOR operation on the array elements
        for (int i = 1; i < size; ++i) prefixXOR[i] ^= prefixXOR[i - 1];

        // Maps to store counts and totals of XOR values encountered
        HashMap<Integer, Integer> countMap = new HashMap<>();
        HashMap<Integer, Integer> totalMap = new HashMap<>();

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating contribution of current element to the result
            count +=
            countMap.getOrDefault(prefixXOR[i], 0) * (i - 1) -
            totalMap.getOrDefault(prefixXOR[i], 0);

            // Updating total count of current XOR value
            totalMap.put(
                prefixXOR[i],
                totalMap.getOrDefault(prefixXOR[i], 0) + i
            );
            countMap.put(
                prefixXOR[i],
                countMap.getOrDefault(prefixXOR[i], 0) + 1
            );
        }

        return count;
    }
}
