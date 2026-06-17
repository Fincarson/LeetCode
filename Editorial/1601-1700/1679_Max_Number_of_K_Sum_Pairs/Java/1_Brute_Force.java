class Solution {
    public int maxOperations(int[] nums, int k) {
        int count = 0;
        for (int first = 0; first < nums.length; first++) {
            // check if element pointed by first is already taken up
            if (nums[first] == 0) continue;
            for (int second = first + 1; second < nums.length; second++) {
                // check if element pointed by second is already taken up
                if (nums[second] == 0) continue;
                if (nums[first] + nums[second] == k) {
                    nums[first] = nums[second] = 0;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
