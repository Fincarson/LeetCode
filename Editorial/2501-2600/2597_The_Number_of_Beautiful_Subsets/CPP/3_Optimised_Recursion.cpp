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
            totalCount *= countBeautifulSubsets(subsets, subsets.size(), k, 0);
        }

        return totalCount - 1;
    }

private:
    int countBeautifulSubsets(vector<pair<int, int>>& subsets, int numSubsets,
                              int difference, int i) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // Calculate subsets where the current subset is not taken
        int skip =
            countBeautifulSubsets(subsets, numSubsets, difference, i + 1);
        // Calculate subsets where the current subset is taken
        int take = (1 << subsets[i].second) - 1;

        // If next number has a 'difference', calculate subsets; otherwise, move
        // to next
        if (i + 1 < numSubsets &&
            subsets[i + 1].first - subsets[i].first == difference) {
            take *=
                countBeautifulSubsets(subsets, numSubsets, difference, i + 2);
        } else {
            take *=
                countBeautifulSubsets(subsets, numSubsets, difference, i + 1);
        }

        return skip + take;  // Return total count of subsets
    }
};
