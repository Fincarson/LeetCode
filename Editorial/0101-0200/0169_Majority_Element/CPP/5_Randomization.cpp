class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2;
        while (true) {
            int candidate = nums[rand() % nums.size()];
            if (countOccurrences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }

private:
    // function to count occurrences of an element
    int countOccurrences(vector<int>& nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }
};
