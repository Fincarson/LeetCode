int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int ans = wordsSize;
    int n = wordsSize;

    for (int i = 0; i < wordsSize; ++i) {
        if (strcmp(words[i], target) == 0) {
            int dist = abs(i - startIndex);
            ans = fmin(ans, fmin(dist, n - dist));
        }
    }

    return ans < n ? ans : -1;
}
