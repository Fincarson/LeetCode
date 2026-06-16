class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int num : nums) {
            hash_table[num]++;
        }
        for (int num : nums) {
            if (hash_table[num] == 1) {
                return num;
            }
        }
        return 0;
    }
};
