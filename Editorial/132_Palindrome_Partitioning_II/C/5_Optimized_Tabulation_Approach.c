int minCut(char *s) {
    int n = strlen(s);
    int *cutsDp = (int *)malloc(n * sizeof(int));
    int **palindromeDp = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        palindromeDp[i] = (int *)malloc(n * sizeof(int));
        memset(palindromeDp[i], 0, n * sizeof(int));  // Initialize to false
    }

    for (int end = 0; end < n; end++) {
        int minimumCut = end;  // Initialize the minimumCut to the worst case:
                               // one cut per character
        for (int start = 0; start <= end; start++) {
            // Check if substring (start, end) is a palindrome
            if (s[start] == s[end] &&
                (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                palindromeDp[start][end] =
                    1;  // Mark this substring as a palindrome
                // Calculate minimum cuts
                minimumCut = start == 0 ? 0
                                        : (minimumCut < cutsDp[start - 1] + 1
                                               ? minimumCut
                                               : cutsDp[start - 1] + 1);
            }
        }
        cutsDp[end] = minimumCut;
    }

    int result = cutsDp[n - 1];
    free(cutsDp);
    for (int i = 0; i < n; i++) {
        free(palindromeDp[i]);
    }
    free(palindromeDp);
    return result;
}
