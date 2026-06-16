class Solution(object):
    def isIdealPermutation(self, A):
        return all(abs(i-x) <= 1 for i,x in enumerate(A))
