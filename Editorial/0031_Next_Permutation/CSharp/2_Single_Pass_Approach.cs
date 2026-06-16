public class Solution {
    public void NextPermutation(int[] nums) {
        int i = nums.Length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }

        if (i >= 0) {
            int j = nums.Length - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }

            Swap(nums, i, j);
        }

        Reverse(nums, i + 1);
    }

    private void Reverse(int[] nums, int start) {
        int i = start, j = nums.Length - 1;
        while (i < j) {
            Swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void Swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
