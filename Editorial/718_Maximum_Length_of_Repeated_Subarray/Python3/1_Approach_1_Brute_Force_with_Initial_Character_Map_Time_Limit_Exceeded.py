class Solution(object):
    def findLength(self, A, B):
        ans = 0
        Bstarts = collections.defaultdict(list)
        for j, y in enumerate(B):
            Bstarts[y].append(j)

        for i, x in enumerate(A):
            for j in Bstarts[x]:
                k = 0
                while i + k < len(A) and j + k < len(B) and A[i + k] == B[j + k]:
                    k += 1
                ans = max(ans, k)
        return ans
