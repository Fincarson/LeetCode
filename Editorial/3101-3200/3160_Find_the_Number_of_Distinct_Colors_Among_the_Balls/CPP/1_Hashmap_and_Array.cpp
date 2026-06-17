class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap;
        vector<int> ballArray(limit + 1);

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0], color = queries[i][1];

            // Check if ball is already colored
            if (ballArray[ball] != 0) {
                // Decrement count of the previous color on the ball
                int prevColor = ballArray[ball];
                colorMap[prevColor]--;

                // If there are no balls with previous color left, remove color
                // from color map
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            // Set color of ball to the new color
            ballArray[ball] = color;

            // Increment the count of the new color
            colorMap[color]++;

            result[i] = colorMap.size();
        }
        return result;
    }
};
