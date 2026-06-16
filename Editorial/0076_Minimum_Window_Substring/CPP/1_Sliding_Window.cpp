class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> dictT;
        for (int i = 0; i < t.length(); i++) {
            dictT[t[i]]++;
        }
        // Number of unique characters in t, which need to be present in the
        // desired window.
        int required = dictT.size();
        // Left and Right pointer
        int l = 0, r = 0;
        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one
        // C. Thus formed would be = 3 when all these conditions are met.
        int formed = 0;
        // Dictionary which keeps a count of all the unique characters in the
        // current window.
        unordered_map<char, int> windowCounts;
        // ans list of the form (window length, left, right)
        int ans[3] = {-1, 0, 0};
        while (r < s.length()) {
            // Add one character from the right to the window
            char c = s[r];
            windowCounts[c]++;
            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
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
                if (dictT.find(c) != dictT.end() &&
                    windowCounts[c] < dictT[c]) {
                    formed--;
                }
                // Move the left pointer ahead, this would help to look for a
                // new window.
                l++;
            }
            // Keep expanding the window once we are done contracting.
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};
