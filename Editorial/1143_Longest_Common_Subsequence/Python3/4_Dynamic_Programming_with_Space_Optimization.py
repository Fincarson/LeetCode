class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        # If text1 doesn't reference the shortest string, swap them.
        if len(text2) < len(text1):
            text1, text2 = text2, text1
        
        
        # The previous column starts with all 0's and like before is 1
        # more than the length of the first word.
        previous = [0] * (len(text1) + 1)
        
        # Iterate up each column, starting from the last one.
        for col in reversed(range(len(text2))):
            # Create a new array to represent the current column.
            current = [0] * (len(text1) + 1)
            for row in reversed(range(len(text1))):
                if text2[col] == text1[row]:
                    current[row] = 1 + previous[row + 1]
                else:
                    current[row] = max(previous[row], current[row + 1])
            # The current column becomes the previous one.
            previous = current
        
        # The original problem's answer is in previous[0]. Return it.
        return previous[0]
