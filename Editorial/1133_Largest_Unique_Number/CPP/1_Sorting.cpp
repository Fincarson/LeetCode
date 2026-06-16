class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int n = nums.size();

        // If there's only one element, it's unique by default
        if (n == 1) {
            return nums[0];
        }

        sort(nums.begin(), nums.end(), greater<int>());

        // Start from the beginning (largest numbers)
        int currentIndex = 0;

        while (currentIndex < n) {
            // If it's the last element or different from the next one,
            // it's unique
            if (currentIndex == n - 1 ||
                nums[currentIndex] != nums[currentIndex + 1]) {
                return nums[currentIndex];
            }

            // Skip duplicates
            while (currentIndex < n - 1 &&
                   nums[currentIndex] == nums[currentIndex + 1]) {
                currentIndex++;
            }

            // Move to the next unique number
            currentIndex++;
        }

        return -1;
    }
};
