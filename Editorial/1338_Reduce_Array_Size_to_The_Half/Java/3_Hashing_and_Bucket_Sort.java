class Solution {
    public int minSetSize(int[] arr) {
        
        Map<Integer, Integer> counts = new HashMap<>();
        int maxCount = 0;
        for (int num : arr) {
            if (!counts.containsKey(num)) {
                counts.put(num, 0);
            }
            int newCount = counts.get(num) + 1;
            counts.put(num, newCount);
            maxCount = Math.max(maxCount, newCount);
        }
        
        // Put the counts into buckets.
        int[] buckets = new int[maxCount + 1];
        for (int count : counts.values()) {
            buckets[count]++;
        }


        // Determine setSize.
        int setSize = 0;
        int numbersToRemoveFromArr = arr.length / 2;
        int bucket = maxCount;
        while (numbersToRemoveFromArr > 0) {
            int maxNeededFromBucket = numbersToRemoveFromArr / bucket;
            if (numbersToRemoveFromArr % bucket != 0) {
                maxNeededFromBucket++;
            }
            int setSizeIncrease = Math.min(buckets[bucket], maxNeededFromBucket);
            setSize += setSizeIncrease;
            numbersToRemoveFromArr -= setSizeIncrease * bucket;
            bucket--;
        }
        return setSize;        
    }
}
