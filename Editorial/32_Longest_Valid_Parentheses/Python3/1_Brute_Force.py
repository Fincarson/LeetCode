class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char == "(":
                stack.append("(")
            elif stack and stack[-1] == "(":
                stack.pop()
            else:
                return False
        return len(stack) == 0

    def longestValidParentheses(self, s: str) -> int:
        maxlen = 0
        for i in range(len(s)):
            for j in range(i + 2, len(s) + 1, 2):
                if self.isValid(s[i:j]):
                    maxlen = max(maxlen, j - i)
        return maxlen
