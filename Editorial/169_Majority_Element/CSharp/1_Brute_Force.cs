public class Solution {
    public int MajorityElement(int[] nums) {
        int majorityCount = nums.Length / 2;

        foreach (int num in nums) {
            int count = 0;
            foreach (int elem in nums) {
                if (elem == num) {
                    count += 1;
                }
            }

            if (count > majorityCount) {
                return num;
            }
        }

        return -1;
    }
}
