char* LCP(char* s1, char* s2) {
    int minLen = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
    char* res = (char*)calloc(minLen + 1, sizeof(char));
    for (int i = 0; i < minLen; i++) {
        if (s1[i] != s2[i]) {
            res[i] = '\0';
            break;
        }
        res[i] = s1[i];
    }
    return res;
}

char* divide_and_conquer(char** strs, int l, int r) {
    if (l == r)
        return strs[l];
    else {
        int mid = (l + r) / 2;
        char* lcpLeft = divide_and_conquer(strs, l, mid);
        char* lcpRight = divide_and_conquer(strs, mid + 1, r);
        char* res = LCP(lcpLeft, lcpRight);
        if (lcpLeft != strs[l]) free(lcpLeft);
        if (lcpRight != strs[mid + 1]) free(lcpRight);
        return res;
    }
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL || strsSize == 0) return "";
    return divide_and_conquer(strs, 0, strsSize - 1);
}
