class Solution {

    public int nthUglyNumber(int n) {
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        Set<Long> seenNumbers = new HashSet<>(); // Set to avoid duplicates
        int[] primeFactors = { 2, 3, 5 }; // Factors for generating new ugly numbers

        minHeap.offer(1L);
        seenNumbers.add(1L);

        long currentUgly = 1L;
        for (int i = 0; i < n; i++) {
            currentUgly = minHeap.poll(); // Get the smallest number

            // Generate and push the next ugly numbers
            for (int prime : primeFactors) {
                long nextUgly = currentUgly * prime;
                if (seenNumbers.add(nextUgly)) { // Avoid duplicates
                    minHeap.offer(nextUgly);
                }
            }
        }

        return (int) currentUgly; // Return the nth ugly number
    }
}
