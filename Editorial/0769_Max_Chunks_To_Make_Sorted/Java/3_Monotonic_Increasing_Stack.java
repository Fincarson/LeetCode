public class Solution {

    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        // Stack to store the maximum elements of each chunk
        Stack<Integer> monotonicStack = new Stack<>();

        for (int i = 0; i < n; i++) {
            // Case 1: Current element is larger, starts a new chunk
            if (monotonicStack.isEmpty() || arr[i] > monotonicStack.peek()) {
                monotonicStack.push(arr[i]);
            } else {
                // Case 2: Merge chunks
                int maxElement = monotonicStack.peek();
                while (
                    !monotonicStack.isEmpty() && arr[i] < monotonicStack.peek()
                ) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
}
