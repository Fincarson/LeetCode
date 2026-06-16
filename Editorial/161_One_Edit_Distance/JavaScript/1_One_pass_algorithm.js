var isOneEditDistance = function (s, t) {
    let ns = s.length;
    let nt = t.length;

    // Ensure that s is shorter than t.
    if (ns > nt) return isOneEditDistance(t, s);

    // The strings are NOT one edit away distance
    // if the length diff is more than 1.
    if (nt - ns > 1) return false;

    for (let i = 0; i < ns; i++)
        if (s[i] != t[i])
            if (ns == nt)
                // if strings have the same length
                return s.slice(i + 1) === t.slice(i + 1);
            // If strings have different lengths
            else return s.slice(i) === t.slice(i + 1);

    // If there are no diffs in ns distance
    // The strings are one edit away only if
    // t has one more character.
    return ns + 1 === nt;
};
