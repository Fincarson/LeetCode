class Solution:
    def minimumLength(self, s: str) -> int:
        # Step 1: Initialize a frequency array to count occurrences of each character
        char_frequency = [0] * 26
        total_length = 0

        # Step 2: Count the frequency of each character in the string
        for current_char in s:
            char_frequency[ord(current_char) - ord("a")] += 1

        # Step 3: Calculate the total length after deletions count
        for frequency in char_frequency:
            if frequency == 0:
                continue  # Skip characters that don't appear
            if frequency % 2 == 0:
                total_length += 2  # If frequency is even, add 2 characters
            else:
                total_length += 1  # If frequency is odd, add 1 character

        # Step 4: Return the minimum length after deletions count
        return total_length
