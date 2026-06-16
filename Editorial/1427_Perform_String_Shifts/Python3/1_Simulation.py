class Solution:
    def stringShift(self, string: str, shift: List[List[int]]) -> str:
        for direction, amount in shift:
            amount %= len(string)
            if direction == 0:
                # Move necessary amount of characters from start to end
                string = string[amount:] + string[:amount]
            else:
                # Move necessary amount of characters from end to start
                string = string[-amount:] + string[:-amount]
        return string
