class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<vector<int>> lsts = {A, B, C, D};
        int k = int(lsts.size());

        auto countSum = [&](int start, int end) {
            map<int, int> cnt({{0, 1}});
            for (int i = start; i < end; i++) {
                map<int, int> temp;
                for (int total : lsts[i]) {
                    for (auto k = cnt.begin(); k != cnt.end(); k++) {
                        temp[total + k->first] += k->second;
                    }
                }
                cnt = temp;
            }
            return cnt;
        };

        map<int, int> left = countSum(0, k / 2);
        map<int, int> right = countSum(k / 2, k);
        int res = 0;
        for (auto k = left.begin(); k != left.end(); k++) {
            res += k->second * right[-k->first];
        }
        return res;
    }
};
