class Solution:
    def customSortString(self, order: str, s: str) -> str:
        # Create a list from s to allow modification (strings are immutable in Python)
        result = list(s)

        # Sort using the index in order as the key
        result.sort(key=lambda c: order.index(c) if c in order else len(order))

        # Concatenate the list into a string
        return ''.join(result)
