public class Solution {
    private bool valid(string s, int start, int length) {
        return length == 1 ||
               (s[start] != '0' &&
                (length < 3 || int.Parse(s.Substring(start, length)) <= 255));
    }

    private void helper(string s, int startIndex, List<int> dots,
                        List<string> ans) {
        var remainingLength = s.Length - startIndex;
        var remainingNumberOfIntegers = 4 - dots.Count;
        if (remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers)
            return;
        if (dots.Count == 3) {
            if (valid(s, startIndex, remainingLength)) {
                var temp = "";
                var last = 0;
                foreach (var dot in dots) {
                    temp += s.Substring(last, dot) + ".";
                    last += dot;
                }

                temp += s.Substring(startIndex);
                ans.Add(temp);
            }

            return;
        }

        for (int curPos = 1; curPos <= 3 && curPos <= remainingLength;
             ++curPos) {
            dots.Add(curPos);
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos, dots, ans);
            }

            dots.RemoveAt(dots.Count - 1);
        }
    }

    public IList<string> RestoreIpAddresses(string s) {
        var ans = new List<string>();
        helper(s, 0, new List<int>(), ans);
        return ans;
    }
}
