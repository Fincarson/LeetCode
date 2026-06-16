class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int msb = 0, lsb = 0;
        for (int num : nums) {
            int new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
            int new_msb = (lsb & num) | (msb & ~num);
            lsb = new_lsb;
            msb = new_msb;
        }
        return lsb;
    }
};
