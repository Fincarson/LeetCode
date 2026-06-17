function lengthOfLongestSubstring(s: string): number {
    const chars = new Map<string, number>();

    let left = 0;
    let right = 0;

    let res = 0;
    while (right < s.length) {
        const r = s[right];
        chars.set(r, (chars.get(r) || 0) + 1);

        while (chars.get(r) > 1) {
            const l = s[left];
            chars.set(l, chars.get(l) - 1);
            left++;
        }

        res = Math.max(res, right - left + 1);
        right++;
    }

    return res;
}
