public class Solution {
    public bool IsMatch(string s, string p) {
        int sLen = s.Length, pLen = p.Length;
        // base cases
        if (p == s) {
            return true;
        }

        if (pLen > 0 && p.All(c => c == '*')) {
            return true;
        }

        if (p.Length == 0 || s.Length == 0) {
            return false;
        }

        // init all matrix except [0][0] element as False
        bool[,] d = new bool[pLen + 1, sLen + 1];
        d[0, 0] = true;
        // DP compute
        for (int pIdx = 1; pIdx < pLen + 1; pIdx++) {
            // the current character in the pattern is '*'
            if (p[pIdx - 1] == '*') {
                int sIdx = 1;
                // d[p_idx - 1][s_idx - 1] is a string-pattern match
                // on the previous step, i.e. one character before.
                // Find the first idx in string with the previous math.
                while ((!d[pIdx - 1, sIdx - 1]) && (sIdx < sLen + 1)) {
                    sIdx++;
                }

                // If (string) matches (pattern),
                // when (string) matches (pattern)* as well
                d[pIdx, sIdx - 1] = d[pIdx - 1, sIdx - 1];
                // If (string) matches (pattern),
                // when (string)(whatever_characters) matches (pattern)* as well
                while (sIdx < sLen + 1) {
                    d[pIdx, sIdx++] = true;
                }
                // the current character in the pattern is '?'
            } else if (p[pIdx - 1] == '?') {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    d[pIdx, sIdx] = d[pIdx - 1, sIdx - 1];
                }
                // the current character in the pattern is not '*' or '?'
            } else {
                for (int sIdx = 1; sIdx < sLen + 1; sIdx++) {
                    // Match is possible if there is a previous match
                    // and current characters are the same
                    d[pIdx, sIdx] =
                        d[pIdx - 1, sIdx - 1] && (p[pIdx - 1] == s[sIdx - 1]);
                }
            }
        }

        return d[pLen, sLen];
    }
}
