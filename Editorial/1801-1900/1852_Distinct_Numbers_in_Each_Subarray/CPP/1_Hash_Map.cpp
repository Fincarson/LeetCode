class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> answer(len - k + 1);

        // Map to store number -> frequency count
        unordered_map<int, int> freqMap;

        // Process first window
        for (int pos = 0; pos < k; pos++) {
            freqMap[nums[pos]]++;
        }
        answer[0] = freqMap.size();

        // Slide window and update counts
        for (int pos = k; pos < len; pos++) {
            // Remove leftmost element of previous window
            int leftNum = nums[pos - k];
            freqMap[leftNum]--;
            if (freqMap[leftNum] == 0) {
                freqMap.erase(leftNum);
            }

            // Add rightmost element of current window
            int rightNum = nums[pos];
            freqMap[rightNum]++;

            // Store distinct count for current window
            answer[pos - k + 1] = freqMap.size();
        }

        return answer;
    }
};
