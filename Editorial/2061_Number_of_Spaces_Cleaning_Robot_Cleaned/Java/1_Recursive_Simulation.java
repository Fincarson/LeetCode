class Solution {

    private final int[] DIRECTIONS = { 0, 1, 0, -1, 0 };

    public int numberOfCleanRooms(int[][] room) {
        int rows = room.length;
        int cols = room[0].length;
        Set<String> visited = new HashSet<>();
        Set<String> cleaned = new HashSet<>();
        return clean(room, rows, cols, 0, 0, 0, visited, cleaned);
    }

    private int clean(
        int[][] room,
        int rows,
        int cols,
        int row,
        int col,
        int direction,
        Set<String> visited,
        Set<String> cleaned
    ) {
        // If the robot already visited this space facing this direction
        // Return the number of spaces cleaned
        if (visited.contains(row + "," + col + "," + direction)) {
            return cleaned.size();
        }

        // Mark the space as visited facing this direction and cleaned
        visited.add(row + "," + col + "," + direction);
        cleaned.add(row + "," + col);

        // Clean the next space straight ahead if it's empty and in the room
        int nextRow = row + DIRECTIONS[direction];
        int nextCol = col + DIRECTIONS[direction + 1];
        if (
            0 <= nextRow &&
            nextRow < rows &&
            0 <= nextCol &&
            nextCol < cols &&
            room[nextRow][nextCol] == 0
        ) {
            return clean(
                room,
                rows,
                cols,
                nextRow,
                nextCol,
                direction,
                visited,
                cleaned
            );
        }

        // Otherwise turn right and clean the current space
        return clean(
            room,
            rows,
            cols,
            row,
            col,
            (direction + 1) % 4,
            visited,
            cleaned
        );
    }
}
