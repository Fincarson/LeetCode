int max(int a, int b) { return (a > b) ? a : b; }

int lengthOfLongestSubstring(char* s) {
    int charToNextIndex[256] = {0};  // ASCII map to store last index + 1
    int maxLen = 0;
    int left = 0;
    int n = strlen(s);
    for (int right = 0; right < n; right++) {
        int index = (int)s[right];
        if (charToNextIndex[index] > 0) {
            left = max(left, charToNextIndex[index]);
        }
        maxLen = max(maxLen, right - left + 1);
        charToNextIndex[index] = right + 1;
    }
    return maxLen;
}
