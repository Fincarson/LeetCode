class Solution {

    public boolean canBeEqual(int[] target, int[] arr) {
        // Dictionary to maintain frequency count for arr
        Map<Integer, Integer> arrFreq = new HashMap<>();
        for (int num : arr) {
            arrFreq.put(num, arrFreq.getOrDefault(num, 0) + 1);
        }

        // Dictionary to maintain frequency count for target
        Map<Integer, Integer> targetFreq = new HashMap<>();
        for (int num : target) {
            targetFreq.put(num, targetFreq.getOrDefault(num, 0) + 1);
        }

        // Number of distinct elements of the 2 arrays are not equal
        if (arrFreq.keySet().size() != targetFreq.keySet().size()) {
            return false;
        }

        for (int num : arrFreq.keySet()) {
            // Frequency for num differs
            if (targetFreq.getOrDefault(num, 0) != arrFreq.get(num)) {
                return false;
            }
        }

        return true;
    }
}
