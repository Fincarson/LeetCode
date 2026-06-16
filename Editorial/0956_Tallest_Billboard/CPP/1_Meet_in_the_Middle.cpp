class Solution {
public:
    map<int, int> helper(vector<int>& rods, int leftIndex, int rightIndex) {
        set<pair<int, int>> states;
        states.insert({0, 0});
        for (int i = leftIndex; i < rightIndex; ++i) {
            int r = rods[i];
            set<pair<int, int>> newStates;
            for (auto p : states) {
                newStates.insert({p.first + r, p.second});
                newStates.insert({p.first, p.second + r});
            }
            states.insert(newStates.begin(), newStates.end());
        }

        map<int, int> dp;
        for (auto p : states) {
            int left = p.first, right = p.second;
            if (dp.find(left - right) == dp.end())
                dp[left - right] = left;
            else
                dp[left - right] = max(dp[left - right], left);
        }
        return dp;
    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        map<int, int> firstHalf = helper(rods, 0, n / 2);
        map<int, int> secondHalf = helper(rods, n / 2, n);

        int answer = 0;
        for (pair<int, int> it : firstHalf) {
            if (secondHalf.count(-it.first) != 0) {
                answer = max(answer, it.second + secondHalf[-it.first]);
            }
        }
        return answer;
    }
};
