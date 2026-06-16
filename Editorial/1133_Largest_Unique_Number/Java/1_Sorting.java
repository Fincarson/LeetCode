class Solution {

    public int largestUniqueNumber(int[] nums) {
        int n = nums.length;

        // If there's only one element, it's unique by default
        if (n == 1) {
            return nums[0];
        }

        Arrays.sort(nums);

        // Start from the end (largest numbers)
        int currentIndex = n - 1;

        while (currentIndex >= 0) {
            // If it's the first element or different from the previous one, it's unique
            if (
                currentIndex == 0 ||
                nums[currentIndex] != nums[currentIndex - 1]
            ) {
                return nums[currentIndex];
            }

            // Skip duplicates
            while (
                currentIndex > 0 && nums[currentIndex] == nums[currentIndex - 1]
            ) {
                currentIndex--;
            }

            // Move to the next unique number
            currentIndex--;
        }

        return -1;
    }
}
