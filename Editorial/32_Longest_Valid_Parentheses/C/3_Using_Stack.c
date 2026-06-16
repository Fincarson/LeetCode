// C Solution
int longestValidParentheses(char* s) {
    int maxans = 0;
    int n = strlen(s);
    int* stack = malloc((n + 1) * sizeof(int));
    int top = -1;
    stack[++top] = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top < 0) {
                stack[++top] = i;
            } else {
                maxans = fmax(maxans, i - stack[top]);
            }
        }
    }
    free(stack);
    return maxans;
}
