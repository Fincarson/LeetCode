class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        mergeSort(names, heights, 0, heights.length - 1);
        return names;
    }

    private void mergeSort(String[] names, int[] heights, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(names, heights, start, mid);
            mergeSort(names, heights, mid + 1, end);
            merge(names, heights, start, mid, end);
        }
    }

    private void merge(
        String[] names,
        int[] heights,
        int start,
        int mid,
        int end
    ) {
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        // Create temporary arrays
        int[] leftHeights = new int[leftSize];
        int[] rightHeights = new int[rightSize];
        String[] leftNames = new String[leftSize];
        String[] rightNames = new String[rightSize];

        // Copy data to temporary arrays
        for (int i = 0; i < leftSize; i++) {
            leftHeights[i] = heights[start + i];
            leftNames[i] = names[start + i];
        }
        for (int j = 0; j < rightSize; j++) {
            rightHeights[j] = heights[mid + 1 + j];
            rightNames[j] = names[mid + 1 + j];
        }

        // Merge the temporary arrays
        int leftIndex = 0, rightIndex = 0;
        int mergeIndex = start;
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (leftHeights[leftIndex] >= rightHeights[rightIndex]) { // Descending order
                heights[mergeIndex] = leftHeights[leftIndex];
                names[mergeIndex] = leftNames[leftIndex];
                leftIndex++;
            } else {
                heights[mergeIndex] = rightHeights[rightIndex];
                names[mergeIndex] = rightNames[rightIndex];
                rightIndex++;
            }
            mergeIndex++;
        }

        // Copy remaining elements of leftHeights[], if any
        while (leftIndex < leftSize) {
            heights[mergeIndex] = leftHeights[leftIndex];
            names[mergeIndex] = leftNames[leftIndex];
            leftIndex++;
            mergeIndex++;
        }

        // Copy remaining elements of rightHeights[], if any
        while (rightIndex < rightSize) {
            heights[mergeIndex] = rightHeights[rightIndex];
            names[mergeIndex] = rightNames[rightIndex];
            rightIndex++;
            mergeIndex++;
        }
    }
}
