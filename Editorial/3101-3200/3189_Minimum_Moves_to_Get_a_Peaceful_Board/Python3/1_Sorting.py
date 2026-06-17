class Solution:
    def minMoves(self, rooks):
        min_moves = 0

        rooks.sort(key=lambda x: x[0])
        # Moves required to place rooks in each row
        for i in range(len(rooks)):
            min_moves += abs(i - rooks[i][0])

        rooks.sort(key=lambda x: x[1])
        # Moves required to place rooks in each column
        for i in range(len(rooks)):
            min_moves += abs(i - rooks[i][1])

        return min_moves
