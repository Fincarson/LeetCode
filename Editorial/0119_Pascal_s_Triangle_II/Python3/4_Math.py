class Solution:
    def getRow(self, n):
        row = [1]
        for k in range(1, n + 1):
            row.append(int((row[-1] * (n - k + 1)) / k))
        return row
