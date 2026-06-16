class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> shortestArray = arrays[0];
        for (const auto& array : arrays) {
            if (array.size() < shortestArray.size()) {
                shortestArray = array;
            }
        }

        vector<int> longestCommonSubseq(shortestArray.begin(),
                                        shortestArray.end());

        for (const auto& array : arrays) {
            // There are no elements that are common to all of the arrays
            if (longestCommonSubseq.empty()) {
                return longestCommonSubseq;
            }

            // Remove any elements from the longest common subsequence
            // that are not in current array
            vector<int> uncommon;
            for (int num : longestCommonSubseq) {
                if (!binarySearch(num, array)) {
                    uncommon.push_back(num);
                }
            }
            for (int num : uncommon) {
                longestCommonSubseq.erase(
                    remove(longestCommonSubseq.begin(),
                           longestCommonSubseq.end(), num),
                    longestCommonSubseq.end());
            }
        }

        return longestCommonSubseq;
    }

private:
    bool binarySearch(int target, const vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
