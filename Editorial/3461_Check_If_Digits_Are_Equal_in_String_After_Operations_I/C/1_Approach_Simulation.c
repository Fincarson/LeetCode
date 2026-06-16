bool hasSameDigits(char* s) {
    int n = strlen(s);
    char* arr = strdup(s);
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 0; j <= n - 1 - i; j++) {
            arr[j] = ((arr[j] - '0') + (arr[j + 1] - '0')) % 10 + '0';
        }
    }
    bool res = arr[0] == arr[1];
    free(arr);
    return res;
}
