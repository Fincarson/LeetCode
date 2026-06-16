func isMatch(s string, p string) bool {
    sLen := len(s)
    pLen := len(p)
    // base cases
    if p == s {
        return true
    }
    if pLen > 0 && strings.Count(p, "*") == pLen {
        return true
    }
    if len(p) == 0 || len(s) == 0 {
        return false
    }
    // init all matrix except [0][0] element as False
    d := make([][]bool, pLen+1)
    for i := range d {
        d[i] = make([]bool, sLen+1)
    }
    d[0][0] = true
    // DP compute
    for pIdx := 1; pIdx < pLen+1; pIdx++ {
        // the current character in the pattern is '*'
        if p[pIdx-1:pIdx] == "*" {
            sIdx := 1
            // d[p_idx - 1][s_idx - 1] is a string-pattern match
            // on the previous step, i.e. one character before.
            // Find the first idx in string with the previous math.
            for !d[pIdx-1][sIdx-1] && sIdx < sLen+1 {
                sIdx++
            }
            // If (string) matches (pattern),
            // when (string) matches (pattern)* as well
            d[pIdx][sIdx-1] = d[pIdx-1][sIdx-1]
            // If (string) matches (pattern),
            // when (string)(whatever_characters) matches (pattern)* as well
            for sIdx < sLen+1 {
                d[pIdx][sIdx] = true
                sIdx++
            }
            // the current character in the pattern is '?'
        } else if p[pIdx-1:pIdx] == "?" {
            for sIdx := 1; sIdx < sLen+1; sIdx++ {
                d[pIdx][sIdx] = d[pIdx-1][sIdx-1]
            }
            // the current character in the pattern is not '*' or '?'
        } else {
            for sIdx := 1; sIdx < sLen+1; sIdx++ {
                // Match is possible if there is a previous match
                // and current characters are the same
                d[pIdx][sIdx] = d[pIdx-1][sIdx-1] && p[pIdx-1:pIdx] == s[sIdx-1:sIdx]
            }
        }
    }
    return d[pLen][sLen]
}
