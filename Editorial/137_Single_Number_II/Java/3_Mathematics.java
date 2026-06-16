class Solution {
    public int singleNumber(int[] nums) {
        Set<Long> numsSet = new HashSet<>();
        long sumNums = 0;
        for (int num : nums) {
            numsSet.add((long) num);
            sumNums += num;
        }

        long sumSet = 0;
        for (long num : numsSet) {
            sumSet += num;
        }

        return (int) ((3 * sumSet - sumNums) / 2);
    }
}
