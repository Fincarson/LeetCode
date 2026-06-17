int maxDistance(int* colors, int colorsSize) {
    int n = colorsSize;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (colors[i] != colors[n - 1]) {
            int d = i > n - 1 - i ? i : n - 1 - i;
            if (d > ans) ans = d;
        }
    }
    return ans;
}
