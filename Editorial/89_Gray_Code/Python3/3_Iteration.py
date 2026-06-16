class Solution:
    def grayCode(self, n):
        result = [0]
        for i in range(1, n + 1):
            previousSequenceLength = len(result)
            mask = 1 << (i - 1)
            for j in range(previousSequenceLength - 1, -1, -1):
                result.append(mask + result[j])
        return result
