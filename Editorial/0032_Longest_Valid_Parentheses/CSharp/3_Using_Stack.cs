// C# Solution

public class Solution {
    public int LongestValidParentheses(string s) {
        int maxans = 0;
        Stack<int> stack = new Stack<int>();
        stack.Push(-1);
        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(') {
                stack.Push(i);
            } else {
                stack.Pop();
                if (stack.Count == 0) {
                    stack.Push(i);
                } else {
                    maxans = Math.Max(maxans, i - stack.Peek());
                }
            }
        }

        return maxans;
    }
}
