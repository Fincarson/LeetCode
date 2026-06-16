class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        // Sort the original array
        Arrays.sort(arr);

        // Initialize minimum difference `minPairDiff` as a huge integer in order not 
        // to miss the absolute difference of the first pair. 
        int minPairDiff = Integer.MAX_VALUE;
        List<List<Integer>> answer = new ArrayList();

        // Traverse the sorted array
        for (int i = 0; i < arr.length - 1; ++i) {
            // For the absolute value `currPairDiff` of the current pair:
            int currPairDiff = arr[i + 1] - arr[i];

            // If `currPairDiff` equals `minPairDiff`, add this pair to the answer list.
            // If `currPairDiff` is smaller than `minPairDiff`, discard all pairs in the answer list, 
            // add this pair to the answer list and update `minPairDiff`.
            // If `currPairDiff` is larger than `minPairDiff`, we just go ahead.
            if (currPairDiff == minPairDiff) {
                answer.add(Arrays.asList(arr[i], arr[i + 1]));
            } else if (currPairDiff < minPairDiff) {
                answer.clear();
                answer.add(Arrays.asList(arr[i], arr[i + 1]));
                minPairDiff = currPairDiff;
            }
        }

        return answer;   
    }
}
