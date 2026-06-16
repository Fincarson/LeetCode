struct List {
    char **strings;
    int size;
};
bool valid(char *s, int start, int length) {
    if (length == 1) return true;
    if (s[start] != '0') {
        return length < 3 || strncmp(s + start, "255", length) <= 0;
    }
    return false;
}
void helper(char *s, int startIndex, int *dots, struct List *ans, int size) {
    const int remainingLength = strlen(s) - startIndex;
    const int remainingNumberOfIntegers = 4 - size;
    if (remainingLength > remainingNumberOfIntegers * 3 ||
        remainingLength < remainingNumberOfIntegers) {
        return;
    }
    char *temp = NULL;
    int last = 0;
    if (size == 3) {
        temp = (char *)calloc(1800, sizeof(char));
        if (valid(s, startIndex, remainingLength)) {
            for (int i = 0; i < size; i++) {
                strncat(temp, s + last, dots[i]);
                last += dots[i];
                strcat(temp, ".");
            }
            strcat(temp, s + startIndex);
            ans->strings[ans->size] = temp;
            ans->size++;
        }
        return;
    }
    for (int curPos = 1; curPos <= 3 && curPos <= remainingLength; ++curPos) {
        dots[size] = curPos;
        if (valid(s, startIndex, curPos)) {
            helper(s, startIndex + curPos, dots, ans, size + 1);
        }
    }
}
char **restoreIpAddresses(char *s, int *returnSize) {
    struct List ans;
    ans.strings = (char **)malloc((1 << 18) * sizeof(char *));
    ans.size = 0;
    int dots[4];
    memset(dots, 0, sizeof(dots));
    helper(s, 0, dots, &ans, 0);
    *returnSize = ans.size;
    return ans.strings;
}
