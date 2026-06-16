class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums2.size(); i++) {
            hash[nums2[i]] = i;
        }

        vector<int> res(nums1.size());
        int j;
        for (int i = 0; i < nums1.size(); i++) {
            for (j = hash[nums1[i]] + 1; j < nums2.size(); j++) {
                if (nums1[i] < nums2[j]) {
                    res[i] = nums2[j];
                    break;
                }
            }
            if (j == nums2.size()) {
                res[i] = -1;
            }
        }

        return res;
    }
};
