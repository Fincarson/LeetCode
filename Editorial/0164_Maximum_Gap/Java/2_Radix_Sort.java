class Solution {
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) {
            return 0;
        }

        int maxVal = Integer.MIN_VALUE;
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }

        int exp = 1;
        int radix = 10;
        int[] aux = new int[nums.length];

        while (maxVal / exp > 0) {
            int[] count = new int[radix];

            for (int num : nums) {
                count[(num / exp) % 10]++;
            }

            for (int i = 1; i < count.length; i++) {
                count[i] += count[i - 1];
            }

            for (int i = nums.length - 1; i >= 0; i--) {
                aux[--count[(nums[i] / exp) % 10]] = nums[i];
            }

            System.arraycopy(aux, 0, nums, 0, nums.length);

            exp *= 10;
        }
        int maxGap = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            maxGap = Math.max(nums[i + 1] - nums[i], maxGap);
        }
        return maxGap;
    }
}
