class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;
        map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }

        // Calculate subsets for each remainder group
        for (auto& fr : freqMap) {
            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            // Store counts of subsets for memoization
            vector<int> counts(subsets.size(), -1);
            totalCount *=
                countBeautifulSubsets(subsets, subsets.size(), k, 0, counts);
        }
        return totalCount - 1;
    }

private:
    int countBeautifulSubsets(vector<pair<int, int>>& subsets, int numSubsets,
                              int difference, int i, vector<int>& counts) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // If the count is already calculated, return it
        if (counts[i] != -1) {
            return counts[i];
        }

        // Calculate subsets where the current subset is not taken
        int skip = countBeautifulSubsets(subsets, numSubsets, difference, i + 1,
                                         counts);

        // Calculate subsets where the current subset is taken
        int take = (1 << subsets[i].second) - 1;  // take the current subset

        // If the next number has a difference of 'difference', calculate
        // subsets accordingly
        if (i + 1 < numSubsets &&
            subsets[i + 1].first - subsets[i].first == difference) {
            take *= countBeautifulSubsets(subsets, numSubsets, difference,
                                          i + 2, counts);
        } else {
            take *= countBeautifulSubsets(subsets, numSubsets, difference,
                                          i + 1, counts);
        }

        return counts[i] =
                   skip + take;  // Store and return total count of subsets
    }
};
