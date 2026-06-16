class Solution {
public:
    // Return true if in arrangement (a, b), b has a higher column number.
    static bool compare(vector<int>& a, vector<int>& b) {
        return b[1] - a[1] > 0;
    }

    int minMoves(vector<vector<int>>& rooks) {
        int minMoves = 0;

        // Moves required to place rooks in each row.
        sort(rooks.begin(), rooks.end());
        for (int i = 0; i < rooks.size(); i++) {
            minMoves += abs(i - rooks[i][0]);
        }

        // Moves required to place rooks in each column.
        sort(rooks.begin(), rooks.end(), compare);
        for (int i = 0; i < rooks.size(); i++) {
            minMoves += abs(i - rooks[i][1]);
        }

        return minMoves;
    }
};
