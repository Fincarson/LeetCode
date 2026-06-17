public class Solution {
    public int MaximumGap(int[] nums) {
        if (nums == null || nums.Length < 2) {
            return 0;
        }

        int maxVal = nums.Max();

        int exp = 1;
        int radix = 10;
        int[] aux = new int[nums.Length];

        while (maxVal / exp > 0) {
            int[] count = new int[radix];

            foreach (int num in nums)
                count[(num / exp) % 10]++;

            for (int i = 1; i < radix; i++)
                count[i] += count[i - 1];

            for (int i = nums.Length - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.Length; i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.Length - 1; i++)
            maxGap = Math.Max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
}
