class Solution {

    public int[] arrayRankTransform(int[] arr) {
        // Store the rank for each number in arr
        TreeMap<Integer, List<Integer>> numToIndices = new TreeMap<>();

        for (int i = 0; i < arr.length; i++) {
            if (!numToIndices.containsKey(arr[i])) {
                numToIndices.put(arr[i], new ArrayList<>());
            }
            numToIndices.get(arr[i]).add(i);
        }
        int rank = 1;
        for (int num : numToIndices.keySet()) {
            for (int index : numToIndices.get(num)) {
                arr[index] = rank;
            }
            rank++;
        }
        return arr;
    }
}
