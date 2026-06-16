class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sumOfSet = 0, sumOfNums = 0;
        set<int> setNums;
        for (int num : nums) {
            if (setNums.count(num) == 0) {
                setNums.insert(num);
                sumOfSet += num;
            }
            sumOfNums += num;
        }
        return 2 * sumOfSet - sumOfNums;
    }
};
