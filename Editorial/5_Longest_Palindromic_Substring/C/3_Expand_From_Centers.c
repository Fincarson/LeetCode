char *longestPalindrome(char *s) {
    if (!s || strlen(s) == 0) return s;

    int stringLength = strlen(s);
    char *palindrome(char *s, int left, int right) {
        int stringLengthLocal = strlen(s);
        while (left >= 0 && right < stringLengthLocal && s[left] == s[right]) {
            left--;
            right++;
        }
        char *p = (char *)malloc(sizeof(char) * (right - left));
        memcpy(p, &s[left + 1], sizeof(char) * (right - left - 1));
        p[right - left - 1] = '\0';  // Add null character at the end
        return p;
    }

    int start = 0, len = 0;
    for (int i = 0; i < stringLength; i++) {
        char *odd = palindrome(s, i, i);
        char *even = palindrome(s, i, i + 1);
        int max_len = strlen(odd) > strlen(even) ? strlen(odd) : strlen(even);

        if (max_len > len) {
            start = i - (max_len - 1) / 2;
            len = max_len;
        }

        free(odd);   // free the allocated memory
        free(even);  // free the allocated memory
    }
    char *ans =
        (char *)malloc(sizeof(char) * (len + 1));  // including space for '\0'
    strncpy(ans, &s[start], len);
    ans[len] = '\0';  // null-terminate the string
    return ans;
}
