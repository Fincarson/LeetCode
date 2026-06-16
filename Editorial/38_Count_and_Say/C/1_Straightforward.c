char* countAndSay(int n) {
    char* currentString = (char*)malloc(sizeof(char) * 5000);
    strcpy(currentString, "1");
    for (int i = 2; i <= n; i++) {
        char* nextString = (char*)malloc(sizeof(char) * 5000);
        int k = 0;
        int ptr = 0;
        for (int j = 0; currentString[j] != '\0'; j = k) {
            while (currentString[k] != '\0' &&
                   currentString[k] == currentString[j])
                k++;
            int diff = k - j;
            sprintf(&nextString[ptr], "%d%c", diff, currentString[j]);
            while (nextString[ptr] != '\0') ptr++;
        }
        free(currentString);
        currentString = nextString;
    }
    return currentString;
}
