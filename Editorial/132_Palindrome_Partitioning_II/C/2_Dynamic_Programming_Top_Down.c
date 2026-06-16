// Structures for memoization
int** memoCuts;
bool** memoPalindrome;          // Using bool instead of optional
bool** isPalindromeCalculated;  // To handle optional-like behavior

// Function to check if the substring is a palindrome
bool isPalindrome(char* s, int start, int end) {
    if (start >= end) return true;
    if (isPalindromeCalculated[start][end]) {
        return memoPalindrome[start][end];
    }
    bool result = (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
    memoPalindrome[start][end] = result;
    isPalindromeCalculated[start][end] = true;
    return result;
}

// Function to find the minimum cut for palindrome partitioning
int findMinimumCut(char* s, int start, int end, int minimumCut) {
    // base case
    if (start == end || isPalindrome(s, start, end)) {
        return 0;
    }

    // check for results in memoCuts
    if (memoCuts[start][end] != -1) {
        return memoCuts[start][end];
    }

    for (int currentEndIndex = start; currentEndIndex <= end;
         currentEndIndex++) {
        if (isPalindrome(s, start, currentEndIndex)) {
            minimumCut = fmin(
                minimumCut,
                1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut));
        }
    }
    memoCuts[start][end] = minimumCut;
    return minimumCut;
}

// Main function for external call
int minCut(char* s) {
    int len = strlen(s);
    memoCuts = malloc(len * sizeof(int*));
    memoPalindrome = malloc(len * sizeof(bool*));
    isPalindromeCalculated = malloc(len * sizeof(bool*));

    for (int i = 0; i < len; i++) {
        memoCuts[i] = malloc(len * sizeof(int));
        memoPalindrome[i] = malloc(len * sizeof(bool));
        isPalindromeCalculated[i] = malloc(len * sizeof(bool));
        for (int j = 0; j < len; j++) {
            memoCuts[i][j] = -1;  // Initialize memoization for cuts
            memoPalindrome[i][j] =
                false;  // Initialize memoization for palindrome checks
            isPalindromeCalculated[i][j] = false;  // Initialize check state
        }
    }

    int result = findMinimumCut(s, 0, len - 1, len - 1);

    // Free allocated memory
    for (int i = 0; i < len; i++) {
        free(memoCuts[i]);
        free(memoPalindrome[i]);
        free(isPalindromeCalculated[i]);
    }
    free(memoCuts);
    free(memoPalindrome);
    free(isPalindromeCalculated);

    return result;
}
