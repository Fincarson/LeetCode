int smallestCommonElement(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    for (int j = 0; j < m; ++j) {
        bool found = true;
        for (int i = 1; i < n && found; ++i) {
            found = binary_search(begin(mat[i]), end(mat[i]), mat[0][j]);
        }
        if (found) {
            return mat[0][j];
        }
    }
    return -1;
}
