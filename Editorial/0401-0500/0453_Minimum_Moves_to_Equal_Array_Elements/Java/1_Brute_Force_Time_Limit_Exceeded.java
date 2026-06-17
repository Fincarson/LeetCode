public class Solution {
    public int minMoves(int[] nums) {
        int min = 0, max = nums.length - 1, count = 0;
        while (true) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[max] < nums[i]) {
                    max = i;
                }
                if (nums[min] > nums[i]) {
                    min = i;
                }
            }
            if (nums[max] == nums[min]) {
                break;
            }
            for (int i = 0; i < nums.length; i++) {
                if (i != max) {
                    nums[i]++;
                }
            }
            count++;
        }
        return count;
    }
}
