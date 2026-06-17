class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        if k > 26:
            return 0
        answer = 0
        n = len(s)

        for i in range(n - k + 1):
            # Initializing an empty frequency array
            freq = [0] * 26

            for j in range(i, i + k):
                curr_char = ord(s[j]) - ord("a")

                # Incrementing the frequency of current character
                freq[curr_char] += 1

                # If a repeated character is found, we stop the loop
                if freq[curr_char] > 1:
                    break
            else:
                # If the substring does not have any repeated characters,
                # we increment the answer
                answer += 1

        return answer
