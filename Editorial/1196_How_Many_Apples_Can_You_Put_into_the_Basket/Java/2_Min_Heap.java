class Solution {
    public int maxNumberOfApples(int[] arr) {
        List<Integer> list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        Queue<Integer> heap = new PriorityQueue<>(list);

        int apples = 0, units = 0;

        while (!heap.isEmpty() && units + heap.peek() <= 5000) {
            units += heap.remove();
            apples += 1;
        }
        return apples;
    }
}
