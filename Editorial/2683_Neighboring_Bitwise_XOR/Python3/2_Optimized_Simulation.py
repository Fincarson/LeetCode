class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # Initialize the original array with 0 as the first element.
        original = [0]

        # Generate the original array based on derived and original[0] = 0
        for i in range(len(derived)):
            original.append(derived[i] ^ original[i])

        # Check if the array is valid by comparing the first and last elements.
        return original[0] == original[-1]
