void reverse(char* s, int start, int end) {
    while (start < end) {
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}

void removeSpaces(char* s) {
    int i, j;
    for (i = 0, j = 0; s[i]; ++i)
        if (s[i] != ' ' || (i > 0 && s[i - 1] != ' ')) s[j++] = s[i];
    if (j > 0 && s[j - 1] == ' ') j--;
    s[j] = '\0';
}

char* reverseWords(char* s) {
    removeSpaces(s);

    int n = strlen(s);

    for (int i = 0; i < n / 2; i++) {
        char tmp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = tmp;
    }

    int start = 0;
    for (int end = 0; end < n; end++) {
        if (s[end] == ' ') {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }

    reverse(s, start, n - 1);
    return s;
}
