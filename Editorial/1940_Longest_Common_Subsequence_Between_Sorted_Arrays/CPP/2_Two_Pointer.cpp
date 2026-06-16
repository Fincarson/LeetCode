class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> longestCommonSubseq = arrays[0];

        // Iterate through the rest of the arrays and
        // If the common subsequence is empty, return immediately
        // Else update the longest common subsequence
        for (int i = 1; i < arrays.size(); i++) {
            if (longestCommonSubseq.empty()) {
                return longestCommonSubseq;
            }
            longestCommonSubseq = longestSeq(longestCommonSubseq, arrays[i]);
        }

        return longestCommonSubseq;
    }

private:
    vector<int> longestSeq(vector<int>& nums1, vector<int>& nums2) {
        vector<int> longestCommonSeq;
        int first = 0;
        int second = 0;

        // Traverse through both arrays with two pointers
        // Increment the pointer with a smaller value at that index
        // When the values are equal, add to the longest common subsequence
        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                longestCommonSeq.push_back(nums1[first]);
                first++;
                second++;
            }
        }
        return longestCommonSeq;
    }
};
