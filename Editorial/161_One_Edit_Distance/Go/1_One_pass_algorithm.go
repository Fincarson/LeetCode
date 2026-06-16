func isOneEditDistance(s string, t string) bool {
    ns := len(s)
    nt := len(t)

    // Ensure that s is shorter than t.
    if ns > nt {
        return isOneEditDistance(t, s)
    }

    // The strings are NOT one edit away from distance
    // if the length diff is more than 1.
    if nt-ns > 1 {
        return false
    }

    for i := 0; i < ns; i++ {
        if s[i] != t[i] {
            // If strings have the same length
            if ns == nt {
                return s[i+1:] == t[i+1:]
            } else { // If strings have different lengths
                return s[i:] == t[i+1:]
            }
        }
    }

    // If there are no diffs in ns distance
    // The strings are one edit away only if
    // t has one more character.
    return ns+1 == nt
}
