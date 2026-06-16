class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        prefix_common_array = [0] * n

        # Initialize sets to store elements from A and B
        elements_in_A, elements_in_B = set(), set()

        # Iterate through the elements of both arrays
        for current_index in range(n):

            # Add current elements from A and B to respective sets
            elements_in_A.add(A[current_index])
            elements_in_B.add(B[current_index])

            common_count = 0

            # Count common elements between the sets
            for element in elements_in_A:
                if element in elements_in_B:
                    common_count += 1

            # Store the count of common elements for the current prefix
            prefix_common_array[current_index] = common_count

        # Return the final array with counts of common elements in each prefix
        return prefix_common_array
