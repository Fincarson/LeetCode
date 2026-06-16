public class Solution {
    private Dictionary<int, int> memo = new Dictionary<int, int>();

    private int RecursiveWithMemo(int index, string s) {
        if (memo.ContainsKey(index)) {
            return memo[index];
        }

        if (index == s.Length) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        if (index == s.Length - 1) {
            return 1;
        }

        int ans = RecursiveWithMemo(index + 1, s);
        if (int.Parse(s.Substring(index, 2)) <= 26) {
            ans += RecursiveWithMemo(index + 2, s);
        }

        memo[index] = ans;
        return ans;
    }

    public int NumDecodings(string s) {
        return RecursiveWithMemo(0, s);
    }
}
