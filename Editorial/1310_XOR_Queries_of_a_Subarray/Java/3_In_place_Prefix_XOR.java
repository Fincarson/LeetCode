class Solution {

    public int[] xorQueries(int[] arr, int[][] queries) {
        List<Integer> result = new ArrayList<>();

        // Step 1: Convert arr into an in-place prefix XOR array
        for (int i = 1; i < arr.length; ++i) {
            arr[i] ^= arr[i - 1];
        }

        // Step 2: Resolve each query using the prefix XOR array
        for (int[] q : queries) {
            if (q[0] > 0) {
                result.add(arr[q[0] - 1] ^ arr[q[1]]);
            } else {
                result.add(arr[q[1]]);
            }
        }

        return result.stream().mapToInt(i -> i).toArray();
    }
}
