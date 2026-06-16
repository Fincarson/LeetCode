class Solution:
    def generateAbbreviations(self, word):
        N = len(word)
        abbreviations = []

        for mask in range(1 << N):
            curr_word = []
            abbreviated_count = 0

            for index in range(N):
                # If the bit at the position index is 1, increment the abbreviated substring.
                if mask & (1 << index):
                    abbreviated_count += 1
                else:
                    # Append the last substring and then the current character.
                    if abbreviated_count > 0:
                        curr_word.append(str(abbreviated_count))
                        abbreviated_count = 0
                    curr_word.append(word[index])

            if abbreviated_count > 0:
                curr_word.append(str(abbreviated_count))

            abbreviations.append("".join(curr_word))

        return abbreviations
