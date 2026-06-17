class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int rows = room.size();
        int cols = room[0].size();
        unordered_set<string> visited;
        unordered_set<string> cleaned;
        return clean(room, rows, cols, 0, 0, 0, visited, cleaned);
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};
    int clean(vector<vector<int>>& room, int rows, int cols, int row, int col,
              int direction, unordered_set<string> visited,
              unordered_set<string> cleaned) {
        // If the robot already visited this space facing this direction
        // Return the number of spaces cleaned
        if (visited.find(to_string(row) + to_string(col) +
                         to_string(direction)) != visited.end()) {
            return cleaned.size();
        }

        // Mark the space as visited facing this direction and cleaned
        visited.insert(to_string(row) + to_string(col) + to_string(direction));
        cleaned.insert(to_string(row) + to_string(col));

        // Clean the next space straight ahead if it's empty and in the room
        int nextRow = row + DIRECTIONS[direction];
        int nextCol = col + DIRECTIONS[direction + 1];
        if (0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols &&
            room[nextRow][nextCol] == 0) {
            return clean(room, rows, cols, nextRow, nextCol, direction, visited,
                         cleaned);
        }

        // Otherwise turn right and clean the current space
        return clean(room, rows, cols, row, col, (direction + 1) % 4, visited,
                     cleaned);
    };
};
