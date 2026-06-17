class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 1;      // Pointer to iterate through the array
        int j = 1;      // Pointer to track position for valid elements
        int count = 1;  // Count of occurrences of the current element

        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                count++;
                if (count > 2) {
                    i++;
                    continue;
                }
            } else {
                count = 1;
            }
            nums[j] = nums[i];
            j++;
            i++;
        }

        nums.resize(j);
        return j;
    }
};
