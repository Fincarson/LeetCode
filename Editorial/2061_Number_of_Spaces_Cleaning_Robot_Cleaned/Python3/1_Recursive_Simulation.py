class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        DIRECTIONS = (0, 1, 0, -1, 0)
        rows, cols = len(room), len(room[0])
        visited = set()
        cleaned = set()

        def clean(row, col, direction):
            # If the robot already visited this space facing this direction
            # Return the number of spaces cleaned
            if (row, col, direction) in visited:
                return len(cleaned)

            # Mark the space as visited facing this direction and cleaned
            visited.add((row, col, direction))
            cleaned.add((row, col))

            # Clean the next space straight ahead if it's empty and in the room
            next_row = row + DIRECTIONS[direction]
            next_col = col + DIRECTIONS[direction + 1]
            if (
                0 <= next_row < rows
                and 0 <= next_col < cols
                and not room[next_row][next_col]
            ):
                return clean(next_row, next_col, direction)

            # Otherwise turn right and clean the current space
            return clean(row, col, (direction + 1) % 4)

        return clean(0, 0, 0)
