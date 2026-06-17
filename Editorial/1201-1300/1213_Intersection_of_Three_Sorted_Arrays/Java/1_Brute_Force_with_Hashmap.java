class Solution {

    public List<Integer> arraysIntersection(
        int[] arr1,
        int[] arr2,
        int[] arr3
    ) {
        List<Integer> ans = new ArrayList<>();

        // note that HashMap won't work here as it does not guarantee
        // the key orders
        Map<Integer, Integer> counter = new TreeMap<>();

        // iterate through arr1, arr2, and arr3 to count the frequencies
        for (Integer e : arr1) {
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }
        for (Integer e : arr2) {
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }
        for (Integer e : arr3) {
            counter.put(e, counter.getOrDefault(e, 0) + 1);
        }

        for (Integer item : counter.keySet()) {
            if (counter.get(item) == 3) {
                ans.add(item);
            }
        }
        return ans;
    }
}
