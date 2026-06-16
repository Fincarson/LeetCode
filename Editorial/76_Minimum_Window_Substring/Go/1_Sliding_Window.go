func minWindow(s string, t string) string {
    if len(s) == 0 || len(t) == 0 {
        return ""
    }
    // Dictionary which keeps a count of all the unique characters in t.
    dictT := make(map[rune]int)
    for _, c := range t {
        dictT[c]++
    }
    // Number of unique characters in t, which need to be present in the desired window.
    required := len(dictT)
    // Left and Right pointer
    l, r := 0, 0
    // formed is used to keep track of how many unique characters in t
    // are present in the current window in its desired frequency.
    formed := 0
    // Dictionary which keeps a count of all the unique characters in the current window.
    windowCounts := make(map[rune]int)
    // ans list of the form (window length, left, right)
    ans := []int{-1, 0, 0}
    for r < len(s) {
        // Add one character from the right to the window
        c := rune(s[r])
        windowCounts[c]++
        // If the frequency of the current character added equals the desired count in t then increment the formed count by 1.
        if _, ok := dictT[c]; ok && windowCounts[c] == dictT[c] {
            formed++
        }
        // Try and contract the window until it ceases to be 'desirable'.
        for l <= r && formed == required {
            c = rune(s[l])
            // Save the smallest window until now.
            if ans[0] == -1 || r-l+1 < ans[0] {
                ans[0] = r - l + 1
                ans[1] = l
                ans[2] = r
            }
            // The character at the position pointed by the `left` pointer is no longer a part of the window.
            windowCounts[c]--
            if _, ok := dictT[c]; ok && windowCounts[c] < dictT[c] {
                formed--
            }
            // Move the left pointer ahead to explore a new window.
            l++
        }
        // Keep expanding the window once we are done contracting.
        r++
    }
    if ans[0] == -1 {
        return ""
    }
    return s[ans[1] : ans[2]+1]
}
