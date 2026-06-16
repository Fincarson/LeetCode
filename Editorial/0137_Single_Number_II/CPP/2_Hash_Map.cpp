class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (freq.find(num) == freq.end()) {
                freq[num] = 1;
            } else {
                freq[num]++;
            }
        }

        int loner = 0;
        for (auto entry : freq) {
            if (entry.second == 1) {
                loner = entry.first;
                break;
            }
        }

        return loner;
    }
};
