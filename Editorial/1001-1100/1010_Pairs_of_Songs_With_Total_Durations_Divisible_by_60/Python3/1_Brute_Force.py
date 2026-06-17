class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        ret, n = 0, len(time)
        for i in range(n):
            # j starts with i+1 so that i is always to the left of j
            # to avoid repetitive counting
            for j in range(i + 1, n):
                ret += (time[i] + time[j]) % 60==0
        return ret
