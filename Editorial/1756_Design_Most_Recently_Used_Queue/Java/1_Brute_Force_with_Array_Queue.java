class MRUQueue {

    private List<Integer> queue = new ArrayList<>();

    public MRUQueue(int n) {
        // Initialize the queue with numbers from 1 to n
        for (int number = 1; number <= n; ++number) {
            queue.add(number);
        }
    }

    public int fetch(int k) {
        // Get the k-th element (1-indexed)
        int value = queue.get(k - 1);
        // Remove the element from its current position in the queue
        queue.remove(k - 1);
        // Append the element to the end of the queue
        queue.add(value);
        return value;
    }
}
