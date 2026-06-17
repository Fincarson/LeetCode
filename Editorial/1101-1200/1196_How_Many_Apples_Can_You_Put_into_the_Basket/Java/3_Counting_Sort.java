class Solution {
    public int maxNumberOfApples(int[] arr) {
        // initialize the counts to store all elements
        int size = -1;
        for (Integer weight: arr) {
            size = Math.max(size, weight);
        }
        int[] counts = new int[size + 1];
        for (Integer weight: arr) {
            counts[weight]++;
        }

        int apples = 0, units = 0;
        for (int i = 0; i < size + 1; i++) {
            // if we have apples of i units of weight
            if (counts[i] != 0) {
                // we need to make sure that:
                // 1. we do not take more apples than those provided
                // 2. we do not exceed 5000 units of weight
                int take = Math.min(counts[i], (5000 - units) / i);

                if (take == 0) {
                    break;
                }
                units += take * i;
                apples += take;

            }
        }
        return apples;
    }
}
