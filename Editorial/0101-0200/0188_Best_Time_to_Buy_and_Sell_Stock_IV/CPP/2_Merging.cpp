class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        // find all consecutively increasing subsequence
        vector<vector<int>> transactions;
        int start = 0;
        int end = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {
                end = i;
            } else {
                if (end > start) {
                    vector<int> t = {start, end};
                    transactions.push_back(t);
                }
                start = i;
            }
        }
        if (end > start) {
            vector<int> t = {start, end};
            transactions.push_back(t);
        }

        while (transactions.size() > k) {
            // check delete loss
            int delete_index = 0;
            int min_delete_loss = INT_MAX;
            for (int i = 0; i < transactions.size(); i++) {
                vector<int> t = transactions[i];
                int profit_loss = prices[t[1]] - prices[t[0]];
                if (profit_loss < min_delete_loss) {
                    min_delete_loss = profit_loss;
                    delete_index = i;
                }
            }

            // check merge loss
            int merge_index = 0;
            int min_merge_loss = INT_MAX;
            for (int i = 1; i < transactions.size(); i++) {
                vector<int> t1 = transactions[i - 1];
                vector<int> t2 = transactions[i];
                int profit_loss = prices[t1[1]] - prices[t2[0]];
                if (profit_loss < min_merge_loss) {
                    min_merge_loss = profit_loss;
                    merge_index = i;
                }
            }

            // delete or merge
            if (min_delete_loss <= min_merge_loss) {
                transactions.erase(transactions.begin() + delete_index);
            } else {
                vector<int>& t1 = transactions[merge_index - 1];
                vector<int>& t2 = transactions[merge_index];
                t1[1] = t2[1];
                transactions.erase(transactions.begin() + merge_index);
            }
        }

        int res = 0;
        for (auto& t : transactions) {
            res += prices[t[1]] - prices[t[0]];
        }

        return res;
    }
};
