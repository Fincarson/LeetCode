// CONSTANTS
const (
    RADIX_1 = 26
    MOD_1   = 1000000033
    RADIX_2 = 27
    MOD_2   = 2147483647
)

// Return Pair of Hash Values
func hashPair(string string, m int) []int {
    hash := make([]int, 2)
    factor1 := 1
    factor2 := 1

    for i := m - 1; i >= 0; i-- {
        hash[0] += ((int(string[i]) - int('a')) * (factor1)) % MOD_1
        factor1 = (factor1 * RADIX_1) % MOD_1
        hash[1] += ((int(string[i]) - int('a')) * (factor2)) % MOD_2
        factor2 = (factor2 * RADIX_2) % MOD_2
    }

    hash[0] = hash[0] % MOD_1
    hash[1] = hash[1] % MOD_2
    return hash
}

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)
    if n < m {
        return -1
    }

    // COMPUTING CONSTANTS
    MAX_WEIGHT_1 := 1
    MAX_WEIGHT_2 := 1
    for i := 0; i < m; i++ {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2
    }

    // Compute hash pair of needle
    hashNeedle := hashPair(needle, m)
    hashHay := make([]int, 2)

    // Check for each m-substring of haystack, starting at index windowStart
    for windowStart := 0; windowStart <= n-m; windowStart++ {
        if windowStart == 0 {
            // Compute hashPair of First Substring
            hashHay = hashPair(haystack, m)
        } else {
            // Update Hash Pair using Previous Hash Value in O(1)
            hashHay[0] = ((hashHay[0]*RADIX_1)%MOD_1 - ((int(haystack[windowStart-1])-int('a'))*MAX_WEIGHT_1)%MOD_1 + (int(haystack[windowStart+m-1]) - int('a')) + MOD_1) % MOD_1
            hashHay[1] = ((hashHay[1]*RADIX_2)%MOD_2 - ((int(haystack[windowStart-1])-int('a'))*MAX_WEIGHT_2)%MOD_2 + (int(haystack[windowStart+m-1]) - int('a')) + MOD_2) % MOD_2
        }

        // If the hash matches, return immediately. Probability of Spurious Hit tends to zero.
        if hashNeedle[0] == hashHay[0] && hashNeedle[1] == hashHay[1] {
            return windowStart
        }
    }

    return -1
}
