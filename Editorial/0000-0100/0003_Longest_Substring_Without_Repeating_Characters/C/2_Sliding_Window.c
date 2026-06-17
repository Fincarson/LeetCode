int lengthOfLongestSubstring(char* s) {
    int chars[128] = {0};

    int left = 0;
    int right = 0;

    int res = 0;
    int n = strlen(s);
    while (right < n) {
        char r = s[right];
        chars[(int)r]++;

        while (chars[(int)r] > 1) {
            char l = s[left];
            chars[(int)l]--;
            left++;
        }

        int currentLength = right - left + 1;
        if (currentLength > res) {
            res = currentLength;
        }

        right++;
    }

    return res;
}
