class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int cols = points[0].size();
        vector<long long> previousRow(cols);

        for (auto& row : points) {
            // runningMax holds the maximum value generated in the previous
            // iteration of each loop
            long long runningMax = 0;

            // Left to right pass
            for (int col = 0; col < cols; ++col) {
                runningMax = max(runningMax - 1, previousRow[col]);
                previousRow[col] = runningMax;
            }

            runningMax = 0;
            // Right to left pass
            for (int col = cols - 1; col >= 0; --col) {
                runningMax = max(runningMax - 1, previousRow[col]);
                previousRow[col] = max(previousRow[col], runningMax) + row[col];
            }
        }

        // Find maximum points in the last row
        long long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = max(maxPoints, previousRow[col]);
        }

        return maxPoints;
    }
};
