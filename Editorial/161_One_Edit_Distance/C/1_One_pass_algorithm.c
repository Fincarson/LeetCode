bool isOneEditDistance(char* s, char* t) {
    int ns = strlen(s);
    int nt = strlen(t);

    // Ensure that s is shorter than t.
    if (ns > nt) return isOneEditDistance(t, s);

    // The strings are NOT one edit away distance
    // if the length diff is more than 1.
    if (nt - ns > 1) return false;

    for (int i = 0; i < ns; i++)
        if (s[i] != t[i])
            // if strings have the same length
            if (ns == nt) return strcmp(s + i + 1, t + i + 1) == 0;
            // If strings have different lengths
            else
                return strcmp(s + i, t + i + 1) == 0;

    // If there are no diffs in ns distance
    // The strings are one edit away only if
    // t has one more character.
    return (ns + 1 == nt);
}
