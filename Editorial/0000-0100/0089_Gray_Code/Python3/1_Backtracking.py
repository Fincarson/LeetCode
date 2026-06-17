class Solution:
    def grayCode(self, n: int):
        result = [0]
        isPresent = {0}
        self.grayCodeHelper(result, n, isPresent)
        return result

    def grayCodeHelper(self, result, n, isPresent):
        if len(result) == (1 << n):
            return True
        current = result[-1]
        for i in range(n):
            nextNum = current ^ (1 << i)
            if nextNum not in isPresent:
                isPresent.add(nextNum)
                result.append(nextNum)
                if self.grayCodeHelper(result, n, isPresent):
                    return True
                isPresent.remove(nextNum)
                result.pop()
        return False
