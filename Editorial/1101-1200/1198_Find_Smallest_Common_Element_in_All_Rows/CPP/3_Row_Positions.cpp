int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int cur_max = 0, cnt = 0;
    vector<int> pos(n);
    while (true) {
        for (int i = 0; i < n; ++i) {
            while (pos[i] < m && mat[i][pos[i]] < cur_max) {
                ++pos[i];
            }
            if (pos[i] >= m) {
                return -1;
            }
            if (cur_max != mat[i][pos[i]]) {
                cnt = 1;
                cur_max = mat[i][pos[i]];
            } else if (++cnt == n) {
                return cur_max;
            }
        }
    }
    return -1;
}
