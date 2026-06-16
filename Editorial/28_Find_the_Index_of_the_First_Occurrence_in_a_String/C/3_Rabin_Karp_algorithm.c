// CONSTANTS
int RADIX_1 = 26;
int MOD_1 = 1000000033;
int RADIX_2 = 27;
int MOD_2 = 2147483647;

// Return Pair of Hash Values
long* hashPair(char* string, int m) {
    long* hash = (long*)malloc(2 * sizeof(long));
    hash[0] = 0;
    hash[1] = 0;
    long factor1 = 1;
    long factor2 = 1;

    for (int i = m - 1; i >= 0; i--) {
        hash[0] += ((int)(string[i] - 'a') * (factor1)) % MOD_1;
        factor1 = (factor1 * RADIX_1) % MOD_1;
        hash[1] += ((int)(string[i] - 'a') * (factor2)) % MOD_2;
        factor2 = (factor2 * RADIX_2) % MOD_2;
    }

    hash[0] = hash[0] % MOD_1;
    hash[1] = hash[1] % MOD_2;
    return hash;
}

// Return the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.
int strStr(char* haystack, char* needle) {
    int m = strlen(needle);
    int n = strlen(haystack);
    if (n < m) return -1;

    // COMPUTING CONSTANTS
    long MAX_WEIGHT_1 = 1;
    long MAX_WEIGHT_2 = 1;
    for (int i = 0; i < m; i++) {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
    }

    // Compute hash pair of needle
    long* hashNeedle = hashPair(needle, m);
    long* hashHay = (long*)malloc(2 * sizeof(long));

    // Check for each m-substring of haystack, starting at index windowStart
    for (int windowStart = 0; windowStart <= n - m; windowStart++) {
        if (windowStart == 0) {
            // Compute hashPair of First Substring
            hashHay = hashPair(haystack, m);
        } else {
            // Update Hash Pair using Previous Hash Value in O(1)
            hashHay[0] =
                ((hashHay[0] * RADIX_1) % MOD_1 -
                 ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_1) %
                     MOD_1 +
                 (int)(haystack[windowStart + m - 1] - 'a') + MOD_1) %
                MOD_1;
            hashHay[1] =
                ((hashHay[1] * RADIX_2) % MOD_2 -
                 ((int)(haystack[windowStart - 1] - 'a') * MAX_WEIGHT_2) %
                     MOD_2 +
                 (int)(haystack[windowStart + m - 1] - 'a') + MOD_2) %
                MOD_2;
        }

        // If the hash matches, return immediately. Probability of Spurious Hit
        // tends to zero.
        if (hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1]) {
            return windowStart;
        }
    }

    return -1;
}
