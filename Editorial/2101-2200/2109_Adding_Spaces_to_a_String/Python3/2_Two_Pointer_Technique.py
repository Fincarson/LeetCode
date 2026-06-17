class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        # Pre-allocate approximate space for efficiency
        result = [None] * (len(s) + len(spaces))

        space_index = 0
        string_index = 0

        for char_index in range(len(s)):
            if space_index < len(spaces) and char_index == spaces[space_index]:
                # Insert space at the correct position
                result[string_index] = " "
                string_index += 1
                space_index += 1

            # Append the current character
            result[string_index] = s[char_index]
            string_index += 1

        # Join the list into a string and return only the used portion
        return "".join(result[:string_index])
