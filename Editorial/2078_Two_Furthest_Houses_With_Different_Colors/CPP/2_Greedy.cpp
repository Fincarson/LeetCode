class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                ans = max(ans, max(i, n - 1 - i));
            }
        }
        return ans;
    }
};
