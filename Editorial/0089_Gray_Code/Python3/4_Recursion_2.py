class Solution:
    def __init__(self):
        self.nextNum = 0

    def grayCode(self, n):
        self.result = []
        self.grayCodeHelper(n)
        return self.result

    def grayCodeHelper(self, n):
        if n == 0:
            self.result.append(self.nextNum)
            return
        self.grayCodeHelper(n - 1)
        # Flip the bit at (n - 1)th position from right
        self.nextNum = self.nextNum ^ (1 << (n - 1))
        self.grayCodeHelper(n - 1)
