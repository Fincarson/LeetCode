class MyCircularQueue {
public:
    MyCircularQueue(int capacity) {
        this->capacity = capacity;
        this->tailIndex = 0;
        this->queue = vector<int>(capacity);
    }

    void enQueue(int value) {
        this->queue[this->tailIndex] = value;
        this->tailIndex = (this->tailIndex + 1) % this->capacity;
    }

    int get(int index) { return this->queue[index % this->capacity]; }

private:
    vector<int> queue;
    int tailIndex;
    int capacity;
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        MyCircularQueue dp(cols);
        int inf = numeric_limits<int>::max();

        auto getMinHealth = [&](int currCell, int nextRow, int nextCol) -> int {
            if (nextRow < 0 || nextCol < 0) return inf;

            int index = cols * nextRow + nextCol;
            int nextCell = dp.get(index);
            return max(1, nextCell - currCell);
        };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int currCell = dungeon[rows - row - 1][cols - col - 1];
                int rightHealth = getMinHealth(currCell, row, col - 1);
                int downHealth = getMinHealth(currCell, row - 1, col);
                int nextHealth = min(rightHealth, downHealth);

                int minHealth;
                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }

                dp.enQueue(minHealth);
            }
        }

        return dp.get(cols - 1);
    }
};
