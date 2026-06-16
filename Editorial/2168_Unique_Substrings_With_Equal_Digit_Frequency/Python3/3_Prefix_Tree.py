class Solution:
    def equalDigitFrequency(self, s: str) -> int:
        root = self.TrieNode()  # Initialize the Trie root
        total_valid_substrings = 0

        # Iterate through all starting indices of substrings
        for start in range(len(s)):
            current_node = root
            digit_frequency = [0] * 10  # Frequency table for digits 0-9
            unique_digits_count = 0
            max_digit_frequency = 0

            # Extend the substring from 'start' to different end positions
            for end in range(start, len(s)):
                current_digit = int(s[end])  # Current digit

                # Update digit frequency and unique digits count
                if digit_frequency[current_digit] == 0:
                    unique_digits_count += 1
                digit_frequency[current_digit] += 1
                max_digit_frequency = max(
                    max_digit_frequency, digit_frequency[current_digit]
                )

                # Traverse or create a new node in the Trie
                if not current_node.children[current_digit]:
                    # Add new node for the digit
                    current_node.children[current_digit] = self.TrieNode()
                # Move to the child node
                current_node = current_node.children[current_digit]

                # Check if the substring is valid
                if (
                    unique_digits_count * max_digit_frequency == end - start + 1
                    and not current_node.is_visited
                ):
                    # Increment count of valid substrings
                    total_valid_substrings += 1
                    # Mark this substring as seen
                    current_node.is_visited = True

        return total_valid_substrings

    class TrieNode:
        def __init__(self):
            self.children = [None] * 10  # List of children nodes (0-9)
            self.is_visited = False  # Mark if the substring has been seen
