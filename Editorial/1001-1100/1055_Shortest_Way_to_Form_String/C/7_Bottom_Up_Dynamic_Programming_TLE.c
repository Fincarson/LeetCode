// For toCheck passing indices of target, both included.
bool isSubsequence(int start, int end, char * source, char * target) {

    if (end - start + 1 > strlen(source)) {
        return false;
    }

    int i = start;
    int j = 0;

    while (i <= end && j < strlen(source)) {
        if (target[i] == source[j]) {
            i++;
        }
        j++;
    }

    return i == end + 1;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int shortestWay(char * source, char * target){
    
    // Boolean array to mark all characters of source
    bool sourceChars[26] = {false};
    for (int i = 0; i < strlen(source); i++) {
        sourceChars[source[i] - 'a'] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (int i = 0; i < strlen(target); i++) {
        if (!sourceChars[target[i] - 'a']) {
            return -1;
        }
    }

    // Optimal Answer for a given ending index. Memoizing using an Array
    int memo[strlen(target)];
    for (int i = 0; i < strlen(target); i++) {
        memo[i] = INT_MAX;
    }
    memo[0] = 1;

    for (int endingIndex = 1; endingIndex < strlen(target); endingIndex++) {
        if (isSubsequence(0, endingIndex, source, target)) {
            memo[endingIndex] = 1;
        } else {
            for (int partitionIndex = endingIndex - 1; partitionIndex >= 0; partitionIndex--) {
                if (memo[partitionIndex] != INT_MAX &&
                        isSubsequence(partitionIndex + 1, endingIndex, source, target)) {
                    memo[endingIndex] = min(memo[endingIndex], memo[partitionIndex] + 1);
                }
            }
        }
    }

    return memo[strlen(target) - 1];
}
