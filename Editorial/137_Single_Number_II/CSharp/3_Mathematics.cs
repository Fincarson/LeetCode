public class Solution {
    public int SingleNumber(int[] nums) {
        long sumNums = 0;
        HashSet<long> numsSet = new HashSet<long>();
        foreach (int num in nums) {
            numsSet.Add((long)num);
            sumNums += num;
        }

        long sumSet = 0;
        foreach (long num in numsSet) {
            sumSet += num;
        }

        return (int)((3 * sumSet - sumNums) / 2);
    }
}
