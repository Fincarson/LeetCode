class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // It can't be doubled array, if the size is odd
        if (changed.size() % 2) {
            return {};
        }
        
        // Sort in ascending order
        sort(changed.begin(), changed.end());
        unordered_map<int, int> freq;
        // Store the frequency in the map
        for (int num : changed) {
            freq[num]++;
        }
        
        vector<int> original;
        for (int num : changed) {
            // If element exists
            if (freq[num]) {
				freq[num]--;
                int twiceNum = num * 2;
                if (freq[twiceNum] > 0) {
                    // Pair up the elements, decrement the count
                    freq[twiceNum]--;
                    // Add the original number to answer
                    original.push_back(num);
                } else {
                    return {};
                }
            }
        }
        
        return original;
    }
};
