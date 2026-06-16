// Declare the memoization arrays and their companion arrays to check if a value
// is set
int *memoCuts;
bool **memoPalindrome;
bool **isPalindromeComputed;

// Function to determine if a substring is a palindrome
bool isPalindrome(const char *s, int start, int end) {
    if (start >= end) return true;
    if (isPalindromeComputed[start][end]) {
        return memoPalindrome[start][end];
    }
    bool result = (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
    memoPalindrome[start][end] = result;
    isPalindromeComputed[start][end] = true;
    return result;
}

// Recursive function to find the minimum cuts needed for palindrome
// partitioning
int findMinimumCut(const char *s, int start, int end, int minimumCut) {
    // base case
    if (start == end || isPalindrome(s, start, end)) {
        return 0;
    }

    // check for results in memoCuts
    if (memoCuts[start] != -1) {
        return memoCuts[start];
    }

    for (int currentEndIndex = start; currentEndIndex <= end;
         currentEndIndex++) {
        if (isPalindrome(s, start, currentEndIndex)) {
            int possibleCut =
                1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut);
            if (possibleCut < minimumCut) {
                minimumCut = possibleCut;
            }
        }
    }
    memoCuts[start] = minimumCut;
    return minimumCut;
}

// Main function to compute the minimum cut
int minCut(char *s) {
    int length = strlen(s);
    memoCuts = malloc(length * sizeof(int));
    memset(memoCuts, -1, length * sizeof(int));

    memoPalindrome = malloc(length * sizeof(bool *));
    isPalindromeComputed = malloc(length * sizeof(bool *));
    for (int i = 0; i < length; i++) {
        memoPalindrome[i] = malloc(length * sizeof(bool));
        isPalindromeComputed[i] = malloc(length * sizeof(bool));
        memset(memoPalindrome[i], 0, length * sizeof(bool));
        memset(isPalindromeComputed[i], 0, length * sizeof(bool));
    }

    int result = findMinimumCut(s, 0, length - 1, length - 1);

    // Free memory
    for (int i = 0; i < length; i++) {
        free(memoPalindrome[i]);
        free(isPalindromeComputed[i]);
    }
    free(memoPalindrome);
    free(isPalindromeComputed);
    free(memoCuts);

    return result;
}
