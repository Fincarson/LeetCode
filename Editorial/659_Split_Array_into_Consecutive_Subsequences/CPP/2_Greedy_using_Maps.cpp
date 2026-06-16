class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> subsequences;
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        for (int num : nums) {
            //num already part of a valid subsequence.
            if (frequency[num] == 0) {
                continue;
            }
            //If a valid subsequence exists with last element = num - 1.
            if (subsequences[num - 1] > 0) {
                subsequences[num - 1]--;
                subsequences[num]++;
            } else if (frequency[num + 1] > 0 && frequency[num + 2] > 0) {
                // If we want to start a new subsequence, check if num + 1 and num + 2 exists
                // Update the list of subsequences with the newly created subsequence
                subsequences[num + 2]++;
                frequency[num + 1]--;
                frequency[num + 2]--;
            } else {
                // No valid subsequence is possible with num
                return false;
            }
            frequency[num]--;
        }
        return true;
    }
};
