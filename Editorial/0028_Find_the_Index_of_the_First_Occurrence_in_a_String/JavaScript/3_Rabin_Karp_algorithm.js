// CONSTANTS
const RADIX_1 = 26;
const MOD_1 = 1000000033;
const RADIX_2 = 27;
const MOD_2 = 2147483647;

// Return Pair of Hash Values
function hashPair(string, m) {
    let hash = [0, 0];
    let factor1 = 1;
    let factor2 = 1;

    for (let i = m - 1; i >= 0; i--) {
        hash[0] +=
            ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor1) % MOD_1;
        factor1 = (factor1 * RADIX_1) % MOD_1;
        hash[1] +=
            ((string.charCodeAt(i) - "a".charCodeAt(0)) * factor2) % MOD_2;
        factor2 = (factor2 * RADIX_2) % MOD_2;
    }

    hash[0] = hash[0] % MOD_1;
    hash[1] = hash[1] % MOD_2;
    return hash;
}

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
var strStr = function (haystack, needle) {
    let m = needle.length;
    let n = haystack.length;
    if (n < m) return -1;

    // COMPUTING CONSTANTS
    let MAX_WEIGHT_1 = 1;
    let MAX_WEIGHT_2 = 1;
    for (let i = 0; i < m; i++) {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
    }

    // Compute hash pair of needle
    let hashNeedle = hashPair(needle, m);
    let hashHay = [0, 0];

    // Check for each m-substring of haystack, starting at index windowStart
    for (let windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hashPair of First Substring
            hashHay = hashPair(haystack, m);
        } else {
            // Update Hash Pair using Previous Hash Value in O(1)
            hashHay[0] =
                (((hashHay[0] * RADIX_1) % MOD_1) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT_1) %
                        MOD_1) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD_1) %
                MOD_1;
            hashHay[1] =
                (((hashHay[1] * RADIX_2) % MOD_2) -
                    (((haystack.charCodeAt(windowStart - 1) -
                        "a".charCodeAt(0)) *
                        MAX_WEIGHT_2) %
                        MOD_2) +
                    (haystack.charCodeAt(windowStart + m - 1) -
                        "a".charCodeAt(0)) +
                    MOD_2) %
                MOD_2;
        }

        // If the hash matches, return immediately. Probability of Spurious Hit tends to zero.
        if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
            return windowStart;
        }
    }

    return -1;
};
