public class Solution {
    private bool valid(string s, int start, int length) {
        return length == 1 ||
               (s[start] != '0' &&
                (length < 3 || int.Parse(s.Substring(start, length)) <= 255));
    }

    public IList<string> RestoreIpAddresses(string s) {
        var ans = new List<string>();
        int length = s.Length;
        for (int len1 = Math.Max(1, length - 9);
             len1 <= 3 && len1 <= length - 3; ++len1) {
            if (!valid(s, 0, len1)) {
                continue;
            }

            for (int len2 = Math.Max(1, length - len1 - 6);
                 len2 <= 3 && len2 <= length - len1 - 2; ++len2) {
                if (!valid(s, len1, len2)) {
                    continue;
                }

                for (int len3 = Math.Max(1, length - len1 - len2 - 3);
                     len3 <= 3 && len3 <= length - len1 - len2 - 1; ++len3) {
                    if (valid(s, len1 + len2, len3) &&
                        valid(s, len1 + len2 + len3,
                              length - len1 - len2 - len3)) {
                        ans.Add(
                            $"{s.Substring(0, len1)}.{s.Substring(len1, len2)}.{s.Substring(len1 + len2, len3)}.{s.Substring(len1 + len2 + len3)}");
                    }
                }
            }
        }

        return ans;
    }
}
