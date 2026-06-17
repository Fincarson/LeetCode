public class Solution {
    public bool IsOneEditDistance(string s, string t) {
        int ns = s.Length;
        int nt = t.Length;

        // Ensure that s is shorter than t.
        if (ns > nt)
            return IsOneEditDistance(t, s);

        // The strings are NOT one edit away from distance  
        // if the length diff is more than 1.
        if (nt - ns > 1)
            return false;

        for (int i = 0; i < ns; i++)
            if (s[i] != t[i])
                // If strings have the same length
                if (ns == nt)
                    return s.Substring(i + 1) == t.Substring(i + 1);
                // If strings have different lengths
                else
                    return s.Substring(i) == t.Substring(i + 1);

        // If there are no diffs in ns distance
        // The strings are one edit away only if
        // t has one more character. 
        return ns + 1 == nt;
    }
}
