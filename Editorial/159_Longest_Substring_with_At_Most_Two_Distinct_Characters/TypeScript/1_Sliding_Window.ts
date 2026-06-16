function lengthOfLongestSubstringTwoDistinct(s: string): number {
    let n = s.length;
    if (n < 3) return n;

    // sliding window left and right pointers
    let left = 0;
    let right = 0;
    // hashmap character -> its rightmost position
    // in the sliding window
    let hashmap: { [key: string]: number } = {};

    let max_len = 2;

    while (right < n) {
        // when the slidewindow contains less than 3 characters
        hashmap[s[right]] = right++;
        // slidewindow contains 3 characters
        if (Object.keys(hashmap).length == 3) {
            // delete the leftmost character
            let del_idx = Math.min(...Object.values(hashmap));
            delete hashmap[s[del_idx]];
            // move left pointer of the slidewindow
            left = del_idx + 1;
        }

        max_len = Math.max(max_len, right - left);
    }
    return max_len;
}
