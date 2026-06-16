class Solution {

    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        int[] shortestArray = arrays[0];
        for (int[] array : arrays) {
            if (array.length < shortestArray.length) {
                shortestArray = array;
            }
        }

        List<Integer> longestCommonSubseq = new ArrayList<>();
        for (int num : shortestArray) {
            longestCommonSubseq.add(num);
        }

        for (int[] array : arrays) {
            // There are no elements that are common to all of the arrays
            if (longestCommonSubseq.isEmpty()) {
                return longestCommonSubseq;
            }

            // Remove any elements from the longest common subsequence
            // that are not in current array
            List<Integer> uncommon = new ArrayList<>();
            for (Integer num : longestCommonSubseq) {
                if (!binarySearch(num, array)) uncommon.add(num);
            }
            for (Integer num : uncommon) {
                longestCommonSubseq.remove(num);
            }
        }

        return longestCommonSubseq;
    }

    private boolean binarySearch(int target, int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
