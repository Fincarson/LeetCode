function hashValue(
    string: string,
    RADIX: number,
    MOD: number,
    m: number,
): number {
    let ans = 0;
    let factor = 1;
    for (let i = m - 1; i >= 0; i--) {
        ans += ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor) % MOD;
        factor = (factor * RADIX) % MOD;
    }
    return ans % MOD;
}

function strStr(haystack: string, needle: string): number {
    let m = needle.length;
    let n = haystack.length;
    if (n < m) return -1;

    // CONSTANTS
    let RADIX = 26;
    let MOD = 1000000033;
    let MAX_WEIGHT = 1;

    for (let i = 0; i < m; i++) MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;

    // Compute hash of needle
    let hashNeedle = hashValue(needle, RADIX, MOD, m),
        hashHay = 0;

    // Check for each m-substring of haystack, starting at index windowStart
    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hash of the First Substring
            hashHay = hashValue(haystack, RADIX, MOD, m);
        } else {
            // Update Hash using Previous Hash Value in O(1)
            hashHay =
                (((hashHay * RADIX) % MOD) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT) %
                        MOD) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD) %
                MOD;
        }
        // If the hash matches, Check Character by Character.
        // Because of Mod, spurious hits can be there.
        if (hashNeedle == hashHay) {
            for (let i = 0; i < m; i++) {
                if (needle[i] != haystack[i + windowStart]) {
                    break;
                }
                if (i == m - 1) {
                    return windowStart;
                }
            }
        }
    }

    return -1;
}
