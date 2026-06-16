char* minWindow(char* s, char* t) {
    if (strlen(s) == 0 || strlen(t) == 0) {
        return "";
    }
    // Dictionary which keeps a count of all the unique characters in t.
    int dictT[128] = {0};
    for (int i = 0; i < strlen(t); i++) {
        dictT[t[i]]++;
    }
    // Number of unique characters in t, which need to be present in the desired
    // window.
    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (dictT[i] > 0) required++;
    }
    // Left and Right pointer
    int l = 0, r = 0;
    // formed is used to keep track of how many unique characters in t
    // are present in the current window in its desired frequency.
    // e.g. if t is "AABC" then the window must have two A's, one B and one C.
    // Thus formed would be = 3 when all these conditions are met.
    int formed = 0;
    // Dictionary which keeps a count of all the unique characters in the
    // current window.
    int windowCounts[128] = {0};
    // ans list of the form (window length, left, right)
    int ans[3] = {-1, 0, 0};
    while (r < strlen(s)) {
        // Add one character from the right to the window
        char c = s[r];
        windowCounts[c]++;
        // If the frequency of the current character added equals to the
        // desired count in t then increment the formed count by 1.
        if (dictT[c] != 0 && windowCounts[c] == dictT[c]) {
            formed++;
        }
        // Try and contract the window till the point where it ceases to be
        // 'desirable'.
        while (l <= r && formed == required) {
            c = s[l];
            // Save the smallest window until now.
            if (ans[0] == -1 || r - l + 1 < ans[0]) {
                ans[0] = r - l + 1;
                ans[1] = l;
                ans[2] = r;
            }
            // The character at the position pointed by the
            // `Left` pointer is no longer a part of the window.
            windowCounts[c]--;
            if (dictT[c] != 0 && windowCounts[c] < dictT[c]) {
                formed--;
            }
            // Move the left pointer ahead, this would help to look for a new
            // window.
            l++;
        }
        // Keep expanding the window once we are done contracting.
        r++;
    }
    if (ans[0] == -1) return "";
    char* res = (char*)malloc(sizeof(char) * (ans[0] + 1));
    strncpy(res, s + ans[1], ans[0]);
    res[ans[0]] = '\0';
    return res;
}
