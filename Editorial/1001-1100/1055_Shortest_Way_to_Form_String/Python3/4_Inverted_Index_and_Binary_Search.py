class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # List of indices for all characters in source
        char_to_indices = defaultdict(list)
        for i, c in enumerate(source):
            char_to_indices[c].append(i)

        # Pointer for source
        source_iterator = 0

        # Number of times we need to iterate through source
        count = 1

        # Find all characters of target in source
        for char in target:

            # If character is not in source, return -1
            if char not in char_to_indices:
                return -1

            # Binary Search to find the index of the character in source
            # next to the current source_iterator
            index = bisect.bisect_left(char_to_indices[char], source_iterator)

            # If we have reached the end of the list, we need to iterate
            # through source again, hence first index of character in source.
            if index == len(char_to_indices[char]):
                count += 1
                source_iterator = char_to_indices[char][0] + 1
            else:
                source_iterator = char_to_indices[char][index] + 1

        # Return the number of times we need to iterate through source
        return count
