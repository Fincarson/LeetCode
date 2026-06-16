// Utility function to check if a string is a palindrome
bool isPalindrome(char *str, int low, int high) {
    while (low < high) {
        if (str[low++] != str[high--]) return false;
    }
    return true;
}
// Function is used as a utility function to get the
// minimum number of cuts for the given string
int getMinCuts(char *str, int low, int high, int minCuts) {
    // Base case: no cuts are needed for a string
    // of length 1 or if the string is a palindrome
    if (low == high || isPalindrome(str, low, high)) return 0;
    // Now check all substrings from the start
    // of the string and get the minimum number of cuts
    // needed for each. Pick the minimum and add 1 to the result.
    for (int i = low; i <= high; i++) {
        if (isPalindrome(str, low, i)) {
            minCuts = min(minCuts, 1 + getMinCuts(str, i + 1, high, minCuts));
        }
    }
    return minCuts;
}
int minCut(char *str) {
    return getMinCuts(str, 0, strlen(str) - 1, strlen(str) - 1);
}
int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
