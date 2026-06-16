public class Solution {
    public bool IsValid(string s) {
        Stack<char> stack = new Stack<char>();
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(') {
                stack.Push('(');
            } else if (stack.Count > 0 && stack.Peek() == '(') {
                stack.Pop();
            } else {
                return false;
            }
        }

        return stack.Count == 0;
    }

    public int LongestValidParentheses(string s) {
        int maxlen = 0;
        for (int i = 0; i < s.Length; i++) {
            for (int j = i + 2; j <= s.Length; j += 2) {
                if (IsValid(s.Substring(i, j - i))) {
                    maxlen = Math.Max(maxlen, j - i);
                }
            }
        }

        return maxlen;
    }
}
