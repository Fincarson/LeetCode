class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            if (!freq.containsKey(num)) {
                freq.put(num, 1);
            } else {
                freq.put(num, freq.get(num) + 1);
            }
        }

        int loner = 0;
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            if (entry.getValue() == 1) {
                loner = entry.getKey();
                break;
            }
        }

        return loner;
    }
}
