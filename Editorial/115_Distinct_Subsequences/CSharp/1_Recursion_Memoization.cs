public class Solution {
    private Dictionary<string, int> memo;

    public int NumDistinct(string s, string t) {
        if (s.Length < t.Length)
            return 0;
        if (s == t || t == "")
            return 1;
        memo = new Dictionary<string, int>();
        return DistinctHelper(s.Substring(0, s.Length - 1), t) +
               ((s[s.Length - 1] == t[t.Length - 1])
                    ? DistinctHelper(s.Substring(0, s.Length - 1),
                                     t.Substring(0, t.Length - 1))
                    : 0);
    }

    private int DistinctHelper(string s, string t) {
        if (memo.ContainsKey(s + "," + t))
            return memo[s + "," + t];
        if (s.Length < t.Length)
            return 0;
        if (s == t || t == "")
            return 1;
        memo[s + "," + t] = DistinctHelper(s.Substring(0, s.Length - 1), t) +
                            ((s[s.Length - 1] == t[t.Length - 1])
                                 ? DistinctHelper(s.Substring(0, s.Length - 1),
                                                  t.Substring(0, t.Length - 1))
                                 : 0);
        return memo[s + "," + t];
    }
}
