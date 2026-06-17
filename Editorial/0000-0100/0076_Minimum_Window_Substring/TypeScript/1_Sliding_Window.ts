function minWindow(s: string, t: string): string {
    if (s.length === 0 || t.length === 0) return "";
    // Dictionary which keeps a count of all the unique characters in t.
    let dictT: Map<string, number> = new Map();
    for (let i = 0; i < t.length; i++) {
        dictT.set(t.charAt(i), (dictT.get(t.charAt(i)) || 0) + 1);
    }
    // Number of unique characters in t, which need to be present in the desired window.
    let required: number = dictT.size;
    // Left and Right pointer
    let l = 0,
        r = 0;
    // formed is used to track how many unique characters in the desired window.
    let formed: number = 0;
    // Dictionary which keeps a count of all the unique characters in the window.
    let windowCounts: Map<string, number> = new Map();
    // ans list of the form (window length, left, right)
    let ans: number[] = [-1, 0, 0];
    while (r < s.length) {
        // Add one character from the right into window.
        let c: string = s.charAt(r);
        windowCounts.set(c, (windowCounts.get(c) || 0) + 1);
        // If the frequency of the current character added equals the count, increase `forms` counter.
        if (dictT.has(c) && windowCounts.get(c) === dictT.get(c)) {
            formed++;
        }
        while (l <= r && formed === required) {
            c = s.charAt(l);
            // Save the smallest window.
            if (ans[0] === -1 || r - l + 1 < ans[0]) {
                ans[0] = r - l + 1;
                ans[1] = l;
                ans[2] = r;
            }
            // Move the left pointer forward to explore a new window.
            windowCounts.set(c, windowCounts.get(c)! - 1);
            if (dictT.has(c) && windowCounts.get(c)! < dictT.get(c)!) {
                formed--;
            }
            l++;
        }
        // Keep expanding the window once we are done contracting.
        r++;
    }
    return ans[0] === -1 ? "" : s.substring(ans[1], ans[2] + 1);
}
