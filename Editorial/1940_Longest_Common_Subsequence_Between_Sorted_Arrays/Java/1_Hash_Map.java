class Solution {

    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        Map<Integer, Integer> frequencies = new HashMap<>();
        List<Integer> longestCommonSubseq = new ArrayList<>();

        // Count the frequency of each number across all arrays
        for (int[] array : arrays) {
            for (int num : array) {
                frequencies.put(num, frequencies.getOrDefault(num, 0) + 1);
                // If the number appears in all arrays, add it to the result
                if (frequencies.get(num) == arrays.length) {
                    longestCommonSubseq.add(num);
                }
            }
        }

        return longestCommonSubseq;
    }
}
