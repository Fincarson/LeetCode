class Solution:

    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        length_str1 = len(str1)

        # Try all possible combinations of character increments
        for mask in range(1 << length_str1):
            temp = list(str1)
            # Apply increments based on current mask
            for str1_index in range(length_str1):
                if (mask & (1 << str1_index)) != 0:
                    temp[str1_index] = self._get_next_char(temp[str1_index])
            # Check if str2 is a subsequence of the modified string
            if self._is_subsequence("".join(temp), str2):
                return True

        return False

    # Helper function to get the next character cyclically
    def _get_next_char(self, str1Char: str) -> str:
        return "a" if str1Char == "z" else chr(ord(str1Char) + 1)

    # Helper function to check if str2 is a subsequence of str1
    def _is_subsequence(self, str1: str, str2: str) -> bool:
        str1_index, str2_index = 0, 0
        length_str1, length_str2 = len(str1), len(str2)

        # Traverse through both strings using a while loop
        while str1_index < length_str1 and str2_index < length_str2:
            if str1[str1_index] == str2[str2_index]:
                str2_index += 1
            str1_index += 1

        # Check if all characters in str2 were matched
        return str2_index == length_str2
