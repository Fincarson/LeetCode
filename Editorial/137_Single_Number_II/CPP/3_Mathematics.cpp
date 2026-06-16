class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<long> numsSet;
        long sumNums = 0;
        for (int num : nums) {
            numsSet.insert((long)num);
            sumNums += num;
        }

        long sumSet = 0;
        for (long num : numsSet) {
            sumSet += num;
        }

        return (int)((3 * sumSet - sumNums) / 2);
    }
};
