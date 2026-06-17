char** divideString(char* s, int k, char fill, int* returnSize) {
    int n = strlen(s);
    int groupCount = (n + k - 1) / k;  // calculate the number of groups
    char** res = (char**)malloc(groupCount * sizeof(char*));
    *returnSize = groupCount;
    int curr = 0;  // starting index of each group
    // split string
    for (int i = 0; i < groupCount; ++i) {
        res[i] = (char*)malloc((k + 1) * sizeof(char));
        int len = (curr + k <= n) ? k : (n - curr);
        snprintf(res[i], len + 1, "%s", s + curr);
        curr += k;
    }
    // try to fill in the last group
    int lastLen = strlen(res[groupCount - 1]);
    if (lastLen < k) {
        for (int i = lastLen; i < k; ++i) {
            res[groupCount - 1][i] = fill;
        }
        res[groupCount - 1][k] = '\0';
    }
    return res;
}
