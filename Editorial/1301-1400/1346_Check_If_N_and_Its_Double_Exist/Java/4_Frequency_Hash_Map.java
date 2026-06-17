class Solution {

    public boolean checkIfExist(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : arr) {
            // Count occurrences of each number
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int num : arr) {
            // Check for double
            if (num != 0 && map.containsKey(2 * num)) {
                return true;
            }
            // Handle zero case (ensure there are at least two zeros)
            if (num == 0 && map.get(num) > 1) {
                return true;
            }
        }
        return false;
    }
}
