class Solution:
    def sameEndSubstringCount(
        self, s: str, queries: list[list[int]]
    ) -> list[int]:
        # Dictionary to store each character and its positions in the string 's'
        char_positions_map = {}

        # Traverse the string and store the index of each character in the dictionary
        for i, c in enumerate(s):
            if c not in char_positions_map:
                char_positions_map[c] = []
            char_positions_map[c].append(i)

        result = []

        # Process each query
        for left_index, right_index in queries:
            count_same_end_substrings = 0

            # For each unique character in the string, calculate the number of same-end substrings
            for positions in char_positions_map.values():
                # Get the number of occurrences of the character within the range [left_index, right_index]
                left_bound = bisect_left(positions, left_index)
                right_bound = bisect_right(positions, right_index)
                num_occurrences = right_bound - left_bound

                # Calculate the number of same-end substrings for this character
                count_same_end_substrings += (
                    num_occurrences * (num_occurrences + 1) // 2
                )

            # Store the result for this query
            result.append(count_same_end_substrings)

        return result
