class Solution(object):
    def isIdealPermutation(self, A):
        return all(x < A[j]
                   for i, x in enumerate(A)
                   for j in xrange(i+2, len(A)))
