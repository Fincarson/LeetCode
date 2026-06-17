class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        // If k is 0, return the result directly.
        if (k == 0) {
            return result;
        }
        for (int i = 0; i < result.size(); i++) {
            if (k > 0) {
                // If k is greater than 0, store the sum of next k numbers.
                for (int j = i + 1; j < i + k + 1; j++) {
                    result[i] += code[j % code.size()];
                }
            } else {
                // If k is less than 0, store the sum of previous -1*k numbers.
                for (int j = i - abs(k); j < i; j++) {
                    result[i] += code[(j + code.size()) % code.size()];
                }
            }
        }
        return result;
    }
};
