int minCut(char* s) {
    int n = strlen(s);
    int* cutsDp = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cutsDp[i] = i;
    }
    for (int mid = 0; mid < n; mid++) {
        findMinimumCuts(mid, mid, cutsDp, s, n);
        findMinimumCuts(mid - 1, mid, cutsDp, s, n);
    }
    int result = cutsDp[n - 1];
    free(cutsDp);
    return result;
}
void findMinimumCuts(int startIndex, int endIndex, int* cutsDp, char* s,
                     int n) {
    for (int start = startIndex, end = endIndex;
         start >= 0 && end < n && s[start] == s[end]; start--, end++) {
        int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
        cutsDp[end] = cutsDp[end] < newCut ? cutsDp[end] : newCut;
    }
}
