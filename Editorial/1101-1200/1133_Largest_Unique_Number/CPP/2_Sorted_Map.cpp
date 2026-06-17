class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        // Use a map to store numbers and their frequencies
        map<int, int> frequencyMap;

        // Populate the frequencyMap
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Initialize the result to -1 (default if no unique number is found)
        int largestUnique = -1;

        // Iterate through the map in reverse order (largest to smallest)
        for (auto it = frequencyMap.rbegin(); it != frequencyMap.rend(); ++it) {
            // If the frequency is 1, we've found our largest unique number
            if (it->second == 1) {
                largestUnique = it->first;
                break;
            }
        }

        return largestUnique;
    }
};
