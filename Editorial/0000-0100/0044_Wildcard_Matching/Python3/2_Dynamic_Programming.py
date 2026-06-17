class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_len = len(s)
        p_len = len(p)

        # The base cases
        if p == s or set(p) == {"*"}:
            return True
        if p == "" or s == "":
            return False

        # Initialize all matrix except [0][0] element as False
        d = [[False] * (s_len + 1) for _ in range(p_len + 1)]
        d[0][0] = True

        # DP compute
        for p_idx in range(1, p_len + 1):
            # The current character in the pattern is '*'
            if p[p_idx - 1] == "*":
                s_idx = 1

                # d[p_idx - 1][s_idx - 1] is a string-pattern match
                # on the previous step, i.e. one character before.
                # Find the first idx in the string with the previous math.
                while not d[p_idx - 1][s_idx - 1] and s_idx < s_len + 1:
                    s_idx += 1

                # If (string) matches (pattern),
                # when (string) matches (pattern)* as well
                d[p_idx][s_idx - 1] = d[p_idx - 1][s_idx - 1]

                # If (string) matches (pattern),
                # when (string)(whatever_characters) matches (pattern)* as well
                while s_idx < s_len + 1:
                    d[p_idx][s_idx] = True
                    s_idx += 1

            # The current character in the pattern is '?'
            elif p[p_idx - 1] == "?":
                for s_idx in range(1, s_len + 1):
                    d[p_idx][s_idx] = d[p_idx - 1][s_idx - 1]

            # The current character in the pattern is not '*' or '?'
            else:
                for s_idx in range(1, s_len + 1):
                    # Match is possible if there is a previous match
                    # and current characters are the same
                    d[p_idx][s_idx] = (
                        d[p_idx - 1][s_idx - 1] and p[p_idx - 1] == s[s_idx - 1]
                    )

        return d[p_len][s_len]
