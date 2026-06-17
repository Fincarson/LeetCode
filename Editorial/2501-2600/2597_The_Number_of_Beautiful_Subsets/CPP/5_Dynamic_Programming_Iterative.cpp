class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;

        map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }

        // Iterate through each remainder group
        for (auto& fr : freqMap) {
            int n =
                fr.second.size();  // Number of elements in the current group

            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            vector<int> counts(n + 1);  // Array to store counts of subsets
            counts[n] = 1;              // Initialize count for the last subset

            // Calculate counts for each subset starting from the second last
            for (int i = n - 1; i >= 0; i--) {
                // Count of subsets skipping the current subset
                int skip = counts[i + 1];

                // Count of subsets including the current subset
                int take = (1 << subsets[i].second) - 1;

                // If next number has a 'difference', calculate subsets;
                // otherwise, move to next
                if (i + 1 < n && subsets[i + 1].first - subsets[i].first == k) {
                    take *= counts[i + 2];
                } else {
                    take *= counts[i + 1];
                }

                // Store the total count for the current subset
                counts[i] = skip + take;
            }

            totalCount *= counts[0];
        }

        return totalCount - 1;
    }
};
