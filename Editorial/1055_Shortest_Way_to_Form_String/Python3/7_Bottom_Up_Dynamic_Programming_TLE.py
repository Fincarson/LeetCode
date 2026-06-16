class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # Check if the Task is possible or not
        # Set of all characters of source. Can use boolean array too.
        source_chars = set(source)

        # Check if all characters of target are present in source
        # If any character is not present, return -1
        for char in target:
            if char not in source_chars:
                return -1

        # Modified is_subsequence function. in_string will always be source
        # For to_check, passing indices of target, both included
        def is_subsequence(start, end):

            i = start
            j = 0

            while i <= end and j < len(source):
                if target[i] == source[j]:
                    i += 1
                j += 1

            return i == end + 1

        # Optimal Answer Array for each ending Index
        opt = [float('inf')] * len(target)
        opt[0] = 1

        for ending_index in range(1, len(target)):
            if is_subsequence(0, ending_index):
                opt[ending_index] = 1
            else:
                for partition_index in range(ending_index):
                    if (opt[partition_index] != float('inf') and
                            is_subsequence(partition_index + 1, ending_index)):
                        opt[ending_index] = min(
                            opt[ending_index], opt[partition_index] + 1)

        # Return Optimal Answer for last index
        return opt[-1]
