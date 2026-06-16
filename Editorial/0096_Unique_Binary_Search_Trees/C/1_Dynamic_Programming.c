// C Solution
int numTrees(int n) {
    int* G = (int*)calloc(n + 1, sizeof(int));
    G[0] = 1;
    G[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    int result = G[n];
    free(G);
    return result;
}
