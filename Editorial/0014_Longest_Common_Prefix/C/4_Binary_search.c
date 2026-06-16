bool isCommonPrefix(char** strs, int strsSize, int len) {
    for (int i = 1; i < strsSize; i++) {
        if (strncmp(strs[0], strs[i], len) != 0) {
            return false;
        }
    }
    return true;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL || strsSize == 0) return "";
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) minLen = len;
    }
    int low = 1, high = minLen;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isCommonPrefix(strs, strsSize, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    char* prefix = calloc(high + 1, sizeof(char));
    memcpy(prefix, strs[0], high);
    return prefix;
}
