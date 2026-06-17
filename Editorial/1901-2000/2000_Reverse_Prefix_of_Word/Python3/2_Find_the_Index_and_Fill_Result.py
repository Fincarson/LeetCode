class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        ch_index = word.find(ch)
        if (ch_index == -1):
            return word

        result = ""

        for i in range(0, len(word)):
            # Add characters through ch to the result in reverse order
            if (i <= ch_index):
                result += word[ch_index - i]
            # Add the rest of the characters to result
            else:
                result += word[i]

        return result
