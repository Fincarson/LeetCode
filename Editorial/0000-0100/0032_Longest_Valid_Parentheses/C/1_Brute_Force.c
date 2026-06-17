int longestValidParentheses(char *s) {
    int maxLen = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j <= n; j += 2) {
            if (isValid(s, i, j)) {
                maxLen = (maxLen > j - i) ? maxLen : j - i;
            }
        }
    }
    return maxLen;
}
int isValid(char *s, int start, int end) {
    int stack[end - start];
    int top = -1;
    for (int i = start; i < end; i++) {
        if (s[i] == '(') {
            stack[++top] = '(';
        } else if (top != -1 && stack[top] == '(') {
            top--;
        } else {
            return 0;
        }
    }
    return top == -1;
}
