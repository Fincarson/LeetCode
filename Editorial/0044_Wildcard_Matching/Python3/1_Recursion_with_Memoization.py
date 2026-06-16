class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        def remove_duplicate_stars(p: str) -> str:
            new_string = []
            for char in p:
                if not new_string or char != "*":
                    new_string.append(char)
                elif new_string[-1] != "*":
                    new_string.append(char)
            return "".join(new_string)

        def helper(s: str, p: str) -> bool:
            if (s, p) in dp:
                return dp[(s, p)]

            if p == s or p == "*":
                dp[(s, p)] = True
            elif p == "" or s == "":
                dp[(s, p)] = False
            elif p[0] == s[0] or p[0] == "?":
                dp[(s, p)] = helper(s[1:], p[1:])
            elif p[0] == "*":
                dp[(s, p)] = helper(s, p[1:]) or helper(s[1:], p)
            else:
                dp[(s, p)] = False

            return dp[(s, p)]

        dp = {}
        p = remove_duplicate_stars(p)
        return helper(s, p)
