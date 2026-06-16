class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        # initialize row with all elements as 1
        row = [1] * (rowIndex + 1)
        # populate each row element
        for i in range(1, rowIndex):
            for j in range(i, 0, -1):
                # current element is sum of current and previous element in above row
                row[j] += row[j - 1]
        return row
