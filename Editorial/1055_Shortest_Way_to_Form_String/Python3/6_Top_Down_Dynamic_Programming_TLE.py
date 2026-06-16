class Solution:
    def shortestWay(self, source: str, target: str) -> int:

        # Check if the Task is possible or not
        # Set of all characters of source. Can use a boolean array too.
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

        # Optimal Answer for a given ending index. Memoizing using a dictionary
        memo = {}

        def optimal_answer(ending_index):

            # Base case
            if ending_index == 0:
                return 1

            # If already computed, return the value
            if ending_index in memo:
                return memo[ending_index]

            # If is subsequence, return 1
            if is_subsequence(0, ending_index):
                memo[ending_index] = 1
                return 1

            # If not subsequence, partition into two parts and find minimum
            answer = float('inf')

            for partition_index in range(ending_index):

                # Check for subsequence only if the answer is less
                # than the current answer. Using AND Short Circuiting
                if (optimal_answer(partition_index) + 1 < answer and
                        is_subsequence(partition_index + 1, ending_index)):
                    answer = min(answer, optimal_answer(partition_index) + 1)

            # Memoize and return
            memo[ending_index] = answer
            return answer

        # Want to find the optimal answer for the last index.
        # Case when the task is not possible is already handled
        return optimal_answer(len(target) - 1)
