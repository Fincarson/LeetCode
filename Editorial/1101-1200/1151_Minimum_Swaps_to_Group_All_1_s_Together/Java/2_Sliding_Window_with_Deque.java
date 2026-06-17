class Solution {

    public int minSwaps(int[] data) {
        int ones = Arrays.stream(data).sum();
        int cntOne = 0, maxOne = 0;
        // Maintain a deque with the size = ones
        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = 0; i < data.length; i++) {
            // We would always add the new element into the deque
            deque.addLast(data[i]);
            cntOne += data[i];

            // When there are more than ones elements in the deque,
            // remove the leftmost one
            if (deque.size() > ones) {
                cntOne -= deque.removeFirst();
            }
            maxOne = Math.max(maxOne, cntOne);
        }
        return ones - maxOne;
    }
}
