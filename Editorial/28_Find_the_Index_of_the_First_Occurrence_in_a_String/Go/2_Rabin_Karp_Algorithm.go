func hashValue(string string, RADIX int, MOD int, m int) int {
    ans := 0
    factor := 1
    for i := m - 1; i >= 0; i-- {
        ans += ((int(string[i]) - int('a')) * factor) % MOD
        factor = (factor * RADIX) % MOD
    }
    return ans % MOD
}

func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)
    if n < m {
        return -1
    }

    // CONSTANTS
    RADIX := 26
    MOD := 1000000033
    MAX_WEIGHT := 1

    for i := 0; i < m; i++ {
        MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD
    }

    // Compute hash of needle
    hashNeedle := hashValue(needle, RADIX, MOD, m)
    hashHay := 0

    // Check for each m-substring of haystack, starting at index windowStart
    for windowStart := 0; windowStart <= n-m; windowStart++ {
        if windowStart == 0 {
            // Compute hash of the First Substring
            hashHay = hashValue(haystack, RADIX, MOD, m)
        } else {
            // Update Hash using Previous Hash Value in O(1)
            hashHay = ((hashHay*RADIX)%MOD - ((int(haystack[windowStart-1])-int('a'))*MAX_WEIGHT)%MOD + (int(haystack[windowStart+m-1]) - int('a')) + MOD) % MOD
        }
        // If the hash matches, Check Character by Character.
        // Because of Mod, spurious hits can be there.
        if hashNeedle == hashHay {
            for i := 0; i < m; i++ {
                if needle[i] != haystack[i+windowStart] {
                    break
                }
                if i == m-1 {
                    return windowStart
                }
            }
        }
    }

    return -1
}
