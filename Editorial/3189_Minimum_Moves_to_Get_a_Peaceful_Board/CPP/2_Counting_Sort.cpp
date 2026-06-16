class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int minMoves = 0;

        // Store the count of rooks in each row and column.
        vector<int> row(rooks.size(), 0);
        vector<int> col(rooks.size(), 0);
        for (int i = 0; i < rooks.size(); i++) {
            row[rooks[i][0]]++;
            col[rooks[i][1]]++;
        }

        int rowMinMoves = 0, colMinMoves = 0;
        for (int i = 0; i < rooks.size(); i++) {
            // Difference between the rooks count at row and column and one.
            rowMinMoves += row[i] - 1;
            colMinMoves += col[i] - 1;

            // Moves required for row and column constraints.
            minMoves += abs(rowMinMoves) + abs(colMinMoves);
        }

        return minMoves;
    }
};
