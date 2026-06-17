class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        max_length = 0
        seen_substrings = set()

        start = 0
        while start < length:
            end = start
            # Stop if it's not possible to find a
            # longer repeating substring
            if end + max_length >= length:
                return max_length
            # Generate substrings of length max_length + 1
            current_substring = s[end : end + max_length + 1]
            # If a repeating substring is found,
            #  increase max_length and restart
            if current_substring in seen_substrings:
                start = -1  # Restart search for new length
                seen_substrings.clear()
                max_length += 1
            else:
                seen_substrings.add(current_substring)
            start += 1

        return max_length
