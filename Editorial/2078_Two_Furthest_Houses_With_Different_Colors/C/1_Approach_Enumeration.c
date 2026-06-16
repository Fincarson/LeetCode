int maxDistance(int* colors, int colorsSize) {
    int n = colorsSize;
    int res = 0;  // the maximum distance between two houses of different colors
    // traverse the indices of two houses and maintain the maximum distance
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (colors[i] != colors[j]) {
                if (j - i > res) {
                    res = j - i;
                }
            }
        }
    }
    return res;
}
