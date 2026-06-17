class Solution:
    def __init__(self):
        self.min_minutes = float("inf")

    def takeCharacters(self, s: str, k: int) -> int:
        if k == 0:
            return 0
        count = [0, 0, 0]
        self._solve(s, k, 0, len(s) - 1, count, 0)
        return -1 if self.min_minutes == float("inf") else self.min_minutes

    def _solve(self, s, k, left, right, count, minutes):
        # Base case: check if we have k of each character
        if count[0] >= k and count[1] >= k and count[2] >= k:
            self.min_minutes = min(self.min_minutes, minutes)
            return
        # If we can't take more characters
        if left > right:
            return

        # Take from left
        left_count = count.copy()
        left_count[ord(s[left]) - ord("a")] += 1
        self._solve(s, k, left + 1, right, left_count, minutes + 1)

        # Take from right
        right_count = count.copy()
        right_count[ord(s[right]) - ord("a")] += 1
        self._solve(s, k, left, right - 1, right_count, minutes + 1)
