class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        seen_substrings = set()
        max_length = len(s) - 1

        while max_length > 0:
            seen_substrings.clear()
            for start in range(len(s) - max_length + 1):
                end = start
                # Extract substring of length max_length
                current_substring = s[end : end + max_length]
                # If the substring is already in the set,
                # it means we've found a repeating substring
                if current_substring in seen_substrings:
                    return max_length
                seen_substrings.add(current_substring)
            # If no repeating substring found,
            # decrease max_length and try again
            max_length -= 1
        return 0
