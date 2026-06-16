class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0]) if rows else 0
        maxsqlen = 0
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == "1":
                    sqlen = 1
                    flag = True
                    while sqlen + i < rows and sqlen + j < cols and flag:
                        for k in range(j, sqlen + j + 1):
                            if matrix[i + sqlen][k] == "0":
                                flag = False
                                break
                        for k in range(i, sqlen + i + 1):
                            if matrix[k][j + sqlen] == "0":
                                flag = False
                                break
                        if flag:
                            sqlen += 1
                    if maxsqlen < sqlen:
                        maxsqlen = sqlen
        return maxsqlen * maxsqlen
