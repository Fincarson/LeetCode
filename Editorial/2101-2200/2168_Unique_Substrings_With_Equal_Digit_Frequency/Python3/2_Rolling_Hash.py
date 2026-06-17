class Solution:
    def equalDigitFrequency(self, s: str) -> int:
        n = len(s)  # Size of the string
        prime = 31  # Prime base for the rolling hash
        mod = 10**9  # Large prime modulus to avoid overflow
        valid_substring_hashes = set()

        for start in range(n):
            digit_frequency = [0] * 10  # Frequency array for digits 0-9
            # Track number of unique digits in the substring
            unique_digits_count = 0
            substring_hash = 0  # Rolling hash for the current substring
            # Maximum frequency of any digit in the substring
            max_digit_frequency = 0

            for end in range(start, n):
                current_digit = int(s[end]) - 0  # Convert char to digit (0-9)

                # If this digit appears for the first time, increment unique_digits
                if digit_frequency[current_digit] == 0:
                    unique_digits_count += 1

                digit_frequency[current_digit] += 1
                max_digit_frequency = max(
                    max_digit_frequency, digit_frequency[current_digit]
                )

                # Update rolling hash
                substring_hash = (
                    prime * substring_hash + current_digit + 1
                ) % mod

                # Check if all digits in the substring have the same frequency
                if max_digit_frequency * unique_digits_count == end - start + 1:
                    # Insert unique hash
                    valid_substring_hashes.add(substring_hash)

        return len(valid_substring_hashes)
