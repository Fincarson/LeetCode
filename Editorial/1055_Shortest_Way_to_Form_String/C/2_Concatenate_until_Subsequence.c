// To check if toCheck is a subsequence of inString
bool isSubsequence(char * toCheck, char * inString) {
    int i = 0, j = 0;
    while (toCheck[i] != '\0' && inString[j] != '\0') {
        if (toCheck[i] == inString[j]) {
            i++;
        }
        j++;
    }

    return toCheck[i] == '\0';
}

int shortestWay(char * source, char * target){
    
    // Boolean array to mark all characters of the source
    bool sourceChars[26] = {false};
    for (int i = 0; source[i] != '\0'; i++) {
        sourceChars[source[i] - 'a'] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (int i = 0; target[i] != '\0'; i++) {
        if (!sourceChars[target[i] - 'a']) {
            return -1;
        }
    }

    // Concatenate source until target is a subsequence of the concatenated string
    char concatenatedSource[1000001];
    strcpy(concatenatedSource, source);
    int count = 1;
    while (!isSubsequence(target, concatenatedSource)) {
        strcat(concatenatedSource, source);
        count++;
    }

    // Number of concatenations done
    return count;
}
