class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        answer = 0
        frequency_count = [0] * 26

        # Count the frequency of each character in the string.
        for ch in s:
            frequency_count[ord(ch) - ord("a")] += 1

        # Calculate the total number of valid substrings.
        for current_count in frequency_count:
            # Using (current_count + 1) choose 2 to calculate valid substrings
            # for the current letter.
            answer += ((current_count + 1) * current_count) // 2

        return answer
