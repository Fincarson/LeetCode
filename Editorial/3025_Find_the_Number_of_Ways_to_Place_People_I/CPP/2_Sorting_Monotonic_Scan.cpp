class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort by x ascending, and if tie, y descending
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size();
        int ans = 0;

        // Iterate over all left points
        for (int i = 0; i < n - 1; i++) {
            int pi2 = points[i][1];
            int minh = INT_MIN;

            // Check right-side points
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] > minh && points[j][1] <= pi2) {
                    ans++;
                    minh = points[j][1];
                }
            }
        }
        return ans;
    }
};
