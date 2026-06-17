class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters,
                                   vector<int>& coins) {
        vector<long long> ans(heroes.size());
        vector<pair<int, int>> monsterAndCoin(monsters.size());

        for (int i = 0; i < monsters.size(); i++) {
            monsterAndCoin[i].first = monsters[i];
            monsterAndCoin[i].second = coins[i];
        }

        // sort by ascending value of monster power
        sort(monsterAndCoin.begin(), monsterAndCoin.end());

        vector<long long> coinsSum(coins.size());
        long long prefixSum = 0;
        for (int i = 0; i < monsterAndCoin.size(); i++) {
            prefixSum += monsterAndCoin[i].second;
            coinsSum[i] = prefixSum;
        }

        for (int i = 0; i < heroes.size(); i++) {
            ans[i] = findTotalCoins(monsterAndCoin, heroes[i], coinsSum);
        }

        return ans;
    }

private:
    long long findTotalCoins(vector<pair<int, int>>& monsterAndCoin,
                             int heroPower, vector<long long>& coinsSum) {
        int l = 0;
        int r = monsterAndCoin.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (monsterAndCoin[mid].first > heroPower)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (l == 0 && monsterAndCoin[l].first > heroPower) {
            // hero can't defeat any monsters
            return 0;
        }

        return coinsSum[r];
    }
};
