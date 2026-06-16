int *cutsDp;
int **palindromeDp;

// Function to build the palindrome dynamic programming table
void buildPalindromeDp(char *s, int n) {
    for (int end = 0; end < n; end++) {
        for (int start = 0; start <= end; start++) {
            // Check if characters match and the substring between them is a
            // palindrome
            if (s[start] == s[end] &&
                (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                palindromeDp[start][end] = 1;
            } else {
                palindromeDp[start][end] = 0;
            }
        }
    }
}

// Main function to compute the minimum cut
int minCut(char *s) {
    int n = strlen(s);
    cutsDp = (int *)malloc(n * sizeof(int));
    palindromeDp = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        palindromeDp[i] = (int *)malloc(n * sizeof(int));
        memset(palindromeDp[i], 0, n * sizeof(int));  // Initialize to false
    }

    buildPalindromeDp(s, n);

    for (int end = 0; end < n; end++) {
        int minimumCut =
            end;  // Initialize to the worst case: one cut per character
        for (int start = 0; start <= end; start++) {
            if (palindromeDp[start][end]) {
                // No cut needed if the whole substring is a palindrome
                // Otherwise, add 1 to the cuts required for the substring just
                // before the current palindrome
                minimumCut = (start == 0) ? 0
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
