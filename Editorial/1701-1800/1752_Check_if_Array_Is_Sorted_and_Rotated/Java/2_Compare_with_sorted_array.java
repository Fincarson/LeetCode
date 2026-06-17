class Solution {

    public boolean check(int[] nums) {
        int size = nums.length;

        // Create a sorted copy of the array
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);

        // Compare the original array with the sorted array, considering all possible rotations
        for (int rotationOffset = 0; rotationOffset < size; ++rotationOffset) {
            boolean isMatch = true;
            for (int index = 0; index < size; ++index) {
                if (
                    nums[(rotationOffset + index) % size] != sortedNums[index]
                ) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }
}
