class Solution {

    public int minimizedMaximum(int n, int[] quantities) {
        int m = quantities.length;

        // Helper arrays - useful for the efficient initialization of the
        // priority queue
        List<int[]> typeStorePairsArray = new ArrayList<>();

        // Push all product types to the list, after assigning one store to each of them
        for (int i = 0; i < m; i++) {
            typeStorePairsArray.add(new int[] { quantities[i], 1 });
        }

        PriorityQueue<int[]> typeStorePairs = new PriorityQueue<>((a, b) ->
            Long.compare((long) b[0] * a[1], (long) a[0] * b[1])
        );

        // Initialize the priority queue
        typeStorePairs.addAll(typeStorePairsArray);

        // Iterate over the remaining n - m stores.
        for (int i = 0; i < n - m; i++) {
            // Pop the first element
            int[] pairWithMaxRatio = typeStorePairs.poll();
            int totalQuantityOfType = pairWithMaxRatio[0];
            int storesAssignedToType = pairWithMaxRatio[1];

            // Push the same element after assigning one more store to its product type
            typeStorePairs.offer(
                new int[] { totalQuantityOfType, storesAssignedToType + 1 }
            );
        }

        // Pop the first element
        int[] pairWithMaxRatio = typeStorePairs.poll();
        int totalQuantityOfType = pairWithMaxRatio[0];
        int storesAssignedToType = pairWithMaxRatio[1];

        // Return the maximum minimum ratio
        return (int) Math.ceil(
            (double) totalQuantityOfType / storesAssignedToType
        );
    }
}
