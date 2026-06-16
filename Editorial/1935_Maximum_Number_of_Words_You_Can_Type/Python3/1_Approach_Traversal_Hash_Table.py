class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(brokenLetters)  # set of broken letter keys
        res = 0  # the number of words that can be fully inputted
        flag = (
            True  # is the current character in the word completely inputtable
        )
        for ch in text:
            if ch == " ":
                # the current character is a space, check the status of the previous word, update the count and initialize the flag
                if flag:
                    res += 1
                flag = True
            elif ch in broken:
                # the current character cannot be entered, the word it is in cannot be fully entered, update flag
                flag = False
        # judge the status of the last word and update the count
        if flag:
            res += 1
        return res
