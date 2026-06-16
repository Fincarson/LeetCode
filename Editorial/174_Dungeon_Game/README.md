# 174. Dungeon Game

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/dungeon-game/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 174 - Dungeon Game](https://leetcode.com/problems/dungeon-game/)

## Problem

The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

### Example 1

```text
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
```

### Example 2

```text
Input: dungeon = [[0]]
Output: 1
```

## Constraints

- m == dungeon.length
- n == dungeon[i].length
- 1 <= m, n <= 200
- -1000 <= dungeon[i][j] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Paths](https://leetcode.com/problems/unique-paths/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Cherry Pickup](https://leetcode.com/problems/cherry-pickup/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Path Cost in a Grid](https://leetcode.com/problems/minimum-path-cost-in-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Health to Beat Game](https://leetcode.com/problems/minimum-health-to-beat-game/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Check if There is a Path With Equal Number of 0's And 1's](https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 174. Dungeon Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming with Circular Queue | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int rows = dungeonSize, cols = *dungeonColSize;
    int dp[rows][cols];
    memset(dp, 0, sizeof(dp));

    int get_min_health(int currCell, int nextRow, int nextCol) {
        if (nextRow >= rows || nextCol >= cols) {
            return INT_MAX;
        }
        int nextCell = dp[nextRow][nextCol];
        // hero needs at least 1 point to survive
        return nextCell - currCell >= 1 ? nextCell - currCell : 1;
    }

    for (int row = rows - 1; row >= 0; --row) {
        for (int col = cols - 1; col >= 0; --col) {
            int currCell = dungeon[row][col];

            int right_health = get_min_health(currCell, row, col + 1);
            int down_health = get_min_health(currCell, row + 1, col);
            int next_health =
                right_health < down_health ? right_health : down_health;

            int min_health;
            if (next_health != INT_MAX) {
                min_health = next_health;
            } else {
                min_health = currCell >= 0 ? 1 : 1 - currCell;
            }

            dp[row][col] = min_health;
        }
    }

    return dp[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

        auto get_min_health = [&](int currCell, int nextRow,
                                  int nextCol) -> int {
            if (nextRow >= rows || nextCol >= cols) {
                return INT_MAX;
            }
            int nextCell = dp[nextRow][nextCol];
            // hero needs at least 1 point to survive
            return max(1, nextCell - currCell);
        };

        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                int currCell = dungeon[row][col];

                int right_health = get_min_health(currCell, row, col + 1);
                int down_health = get_min_health(currCell, row + 1, col);
                int next_health = min(right_health, down_health);

                int min_health;
                if (next_health != INT_MAX) {
                    min_health = next_health;
                } else {
                    min_health = currCell >= 0 ? 1 : 1 - currCell;
                }

                dp[row][col] = min_health;
            }
        }

        return dp[0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    const int inf = int.MaxValue;
    int[,] dp;
    int rows, cols;

    public int GetMinHealth(int currCell, int nextRow, int nextCol) {
        if (nextRow >= this.rows || nextCol >= this.cols)
            return inf;
        int nextCell = this.dp[nextRow, nextCol];
        // hero needs at least 1 point to survive
        return Math.Max(1, nextCell - currCell);
    }

    public int CalculateMinimumHP(int[][] dungeon) {
        this.rows = dungeon.Length;
        this.cols = dungeon[0].Length;
        this.dp = new int[rows, cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i, j] = inf;
            }
        }

        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = this.rows - 1; row >= 0; --row) {
            for (int col = this.cols - 1; col >= 0; --col) {
                currCell = dungeon[row][col];

                rightHealth = GetMinHealth(currCell, row, col + 1);
                downHealth = GetMinHealth(currCell, row + 1, col);
                nextHealth = Math.Min(rightHealth, downHealth);

                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }

                this.dp[row, col] = minHealth;
            }
        }

        return this.dp[0, 0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func calculateMinimumHP(dungeon [][]int) int {
    rows, cols := len(dungeon), len(dungeon[0])
    dp := make([][]int, rows)
    for i := 0; i < rows; i++ {
        dp[i] = make([]int, cols)
        for j := 0; j < cols; j++ {
            dp[i][j] = 1<<31 - 1
        }
    }

    get_min_health := func(currCell int, nextRow int, nextCol int) int {
        if nextRow >= rows || nextCol >= cols {
            return 1<<31 - 1
        }
        nextCell := dp[nextRow][nextCol]
        // hero needs at least 1 point to survive
        return max(1, nextCell-currCell)
    }

    for row := rows - 1; row >= 0; row-- {
        for col := cols - 1; col >= 0; col-- {
            currCell := dungeon[row][col]

            right_health := get_min_health(currCell, row, col+1)
            down_health := get_min_health(currCell, row+1, col)
            next_health := min(right_health, down_health)

            min_health := 0
            if next_health != 1<<31-1 {
                min_health = next_health
            } else {
                if currCell >= 0 {
                    min_health = 1
                } else {
                    min_health = 1 - currCell
                }
            }

            dp[row][col] = min_health
        }
    }

    return dp[0][0]
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int inf = Integer.MAX_VALUE;
    int[][] dp;
    int rows, cols;

    public int getMinHealth(int currCell, int nextRow, int nextCol) {
        if (nextRow >= this.rows || nextCol >= this.cols) return inf;
        int nextCell = this.dp[nextRow][nextCol];
        // hero needs at least 1 point to survive
        return Math.max(1, nextCell - currCell);
    }

    public int calculateMinimumHP(int[][] dungeon) {
        this.rows = dungeon.length;
        this.cols = dungeon[0].length;
        this.dp = new int[rows][cols];
        for (int[] arr : this.dp) {
            Arrays.fill(arr, this.inf);
        }
        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = this.rows - 1; row >= 0; --row) {
            for (int col = this.cols - 1; col >= 0; --col) {
                currCell = dungeon[row][col];

                rightHealth = getMinHealth(currCell, row, col + 1);
                downHealth = getMinHealth(currCell, row + 1, col);
                nextHealth = Math.min(rightHealth, downHealth);

                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }
                this.dp[row][col] = minHealth;
            }
        }
        return this.dp[0][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var calculateMinimumHP = function (dungeon) {
    let rows = dungeon.length,
        cols = dungeon[0].length;
    let dp = Array(rows)
        .fill()
        .map(() => Array(cols).fill(Number.MAX_SAFE_INTEGER));

    const get_min_health = (currCell, nextRow, nextCol) => {
        if (nextRow >= rows || nextCol >= cols) {
            return Number.MAX_SAFE_INTEGER;
        }
        let nextCell = dp[nextRow][nextCol];
        // hero needs at least 1 point to survive
        return Math.max(1, nextCell - currCell);
    };

    for (let row = rows - 1; row >= 0; --row) {
        for (let col = cols - 1; col >= 0; --col) {
            let currCell = dungeon[row][col];

            let right_health = get_min_health(currCell, row, col + 1);
            let down_health = get_min_health(currCell, row + 1, col);
            let next_health = Math.min(right_health, down_health);

            let min_health;
            if (next_health !== Number.MAX_SAFE_INTEGER) {
                min_health = next_health;
            } else {
                min_health = currCell >= 0 ? 1 : 1 - currCell;
            }

            dp[row][col] = min_health;
        }
    }

    return dp[0][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows, cols = len(dungeon), len(dungeon[0])
        dp = [[float("inf")] * cols for _ in range(rows)]

        def get_min_health(currCell: int, nextRow: int, nextCol: int) -> float:
            if nextRow >= rows or nextCol >= cols:
                return float("inf")
            nextCell = dp[nextRow][nextCol]
            # hero needs at least 1 point to survive
            return max(1, nextCell - currCell)

        for row in reversed(range(rows)):
            for col in reversed(range(cols)):
                currCell = dungeon[row][col]

                right_health = get_min_health(currCell, row, col + 1)
                down_health = get_min_health(currCell, row + 1, col)
                next_health = min(right_health, down_health)

                if next_health != float("inf"):
                    min_health = next_health
                else:
                    min_health = 1 if currCell >= 0 else (1 - currCell)

                dp[row][col] = min_health

        return dp[0][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function calculateMinimumHP(dungeon: number[][]): number {
    let rows = dungeon.length,
        cols = dungeon[0].length;
    let dp: number[][] = Array.from(Array(rows), () =>
        Array(cols).fill(Number.MAX_SAFE_INTEGER),
    );

    const get_min_health = (
        currCell: number,
        nextRow: number,
        nextCol: number,
    ) => {
        if (nextRow >= rows || nextCol >= cols) {
            return Number.MAX_SAFE_INTEGER;
        }
        let nextCell = dp[nextRow][nextCol];
        // hero needs at least 1 point to survive
        return Math.max(1, nextCell - currCell);
    };

    for (let row = rows - 1; row >= 0; --row) {
        for (let col = cols - 1; col >= 0; --col) {
            let currCell = dungeon[row][col];

            let right_health = get_min_health(currCell, row, col + 1);
            let down_health = get_min_health(currCell, row + 1, col);
            let next_health = Math.min(right_health, down_health);

            let min_health;
            if (next_health !== Number.MAX_SAFE_INTEGER) {
                min_health = next_health;
            } else {
                min_health = currCell >= 0 ? 1 : 1 - currCell;
            }

            dp[row][col] = min_health;
        }
    }

    return dp[0][0];
}
```

</details>

<br>

## Approach 2: Dynamic Programming with Circular Queue

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_INT 2147483647

typedef struct MyCircularQueue {
    int capacity;
    int tailIndex;
    int* queue;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int capacity) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->queue = (int*)malloc(sizeof(int) * capacity);
    obj->tailIndex = 0;
    obj->capacity = capacity;
    return obj;
}

void myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    obj->queue[obj->tailIndex] = value;
    obj->tailIndex = (obj->tailIndex + 1) % obj->capacity;
}

int myCircularQueueGet(MyCircularQueue* obj, int index) {
    return obj->queue[index % obj->capacity];
}

int getMinHealth(int currCell, int nextRow, int nextCol, int rows, int cols,
                 MyCircularQueue* dp) {
    if (nextRow < 0 || nextCol < 0) return MAX_INT;

    int index = cols * nextRow + nextCol;
    int nextCell = myCircularQueueGet(dp, index);
    // hero needs at least 1 point to survive
    return (1 > nextCell - currCell) ? 1 : nextCell - currCell;
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int rows = dungeonSize;
    int cols = (*dungeonColSize);
    MyCircularQueue* dp = myCircularQueueCreate(cols);

    int currCell, rightHealth, downHealth, nextHealth, minHealth;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            currCell = dungeon[rows - row - 1][cols - col - 1];

            rightHealth = getMinHealth(currCell, row, col - 1, rows, cols, dp);
            downHealth = getMinHealth(currCell, row - 1, col, rows, cols, dp);
            nextHealth = (rightHealth < downHealth) ? rightHealth : downHealth;

            if (nextHealth != MAX_INT) {
                minHealth = nextHealth;
            } else {
                minHealth = (currCell >= 0) ? 1 : 1 - currCell;
            }
            myCircularQueueEnQueue(dp, minHealth);
        }
    }

    // retrieve the last element in the queue
    return myCircularQueueGet(dp, cols - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
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
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class MyCircularQueue {
    protected int capacity;
    protected int tailIndex;
    public int[] queue;

    public MyCircularQueue(int capacity) {
        this.queue = new int[capacity];
        this.tailIndex = 0;
        this.capacity = capacity;
    }

    public void EnQueue(int value) {
        this.queue[this.tailIndex] = value;
        this.tailIndex = (this.tailIndex + 1) % this.capacity;
    }

    public int Get(int index) {
        return this.queue[index % this.capacity];
    }
}

public class Solution {
    int inf = int.MaxValue;
    MyCircularQueue dp;
    int rows, cols;

    public int GetMinHealth(int currCell, int nextRow, int nextCol) {
        if (nextRow < 0 || nextCol < 0)
            return inf;

        int index = cols * nextRow + nextCol;
        int nextCell = this.dp.Get(index);
        return Math.Max(1, nextCell - currCell);
    }

    public int CalculateMinimumHP(int[][] dungeon) {
        this.rows = dungeon.Length;
        this.cols = dungeon[0].Length;
        this.dp = new MyCircularQueue(this.cols);

        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = 0; row < this.rows; ++row) {
            for (int col = 0; col < this.cols; ++col) {
                currCell = dungeon[rows - row - 1][cols - col - 1];

                rightHealth = GetMinHealth(currCell, row, col - 1);
                downHealth = GetMinHealth(currCell, row - 1, col);
                nextHealth = Math.Min(rightHealth, downHealth);

                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }

                this.dp.EnQueue(minHealth);
            }
        }

        return this.dp.Get(this.cols - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type MyCircularQueue struct {
    queue     []int
    tailIndex int
    capacity  int
}

func CreateMyCircularQueue(capacity int) MyCircularQueue {
    return MyCircularQueue{make([]int, capacity), 0, capacity}
}

func (q *MyCircularQueue) enQueue(value int) {
    q.queue[q.tailIndex] = value
    q.tailIndex = (q.tailIndex + 1) % q.capacity
}

func (q *MyCircularQueue) get(index int) int {
    return q.queue[index%q.capacity]
}

func calculateMinimumHP(dungeon [][]int) int {
    rows := len(dungeon)
    cols := len(dungeon[0])
    dp := CreateMyCircularQueue(cols)
    inf := int(^uint(0) >> 1)

    getMinHealth := func(currCell, nextRow, nextCol int) int {
        if nextRow < 0 || nextCol < 0 {
            return inf
        }

        index := cols*nextRow + nextCol
        nextCell := dp.get(index)
        return max(1, nextCell-currCell)
    }

    for row := 0; row < rows; row++ {
        for col := 0; col < cols; col++ {
            currCell := dungeon[rows-row-1][cols-col-1]
            rightHealth := getMinHealth(currCell, row, col-1)
            downHealth := getMinHealth(currCell, row-1, col)
            nextHealth := min(rightHealth, downHealth)

            minHealth := 0
            if nextHealth != inf {
                minHealth = nextHealth
            } else {
                if currCell >= 0 {
                    minHealth = 1
                } else {
                    minHealth = 1 - currCell
                }
            }

            dp.enQueue(minHealth)
        }
    }

    return dp.get(cols - 1)
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class MyCircularQueue {
    protected int capacity;
    protected int tailIndex;
    public int[] queue;

    public MyCircularQueue(int capacity) {
        this.queue = new int[capacity];
        this.tailIndex = 0;
        this.capacity = capacity;
    }

    public void enQueue(int value) {
        this.queue[this.tailIndex] = value;
        this.tailIndex = (this.tailIndex + 1) % this.capacity;
    }

    public int get(int index) {
        return this.queue[index % this.capacity];
    }
}

class Solution {
    int inf = Integer.MAX_VALUE;
    MyCircularQueue dp;
    int rows, cols;

    public int getMinHealth(int currCell, int nextRow, int nextCol) {
        if (nextRow < 0 || nextCol < 0) return inf;

        int index = cols * nextRow + nextCol;
        int nextCell = this.dp.get(index);
        // hero needs at least 1 point to survive
        return Math.max(1, nextCell - currCell);
    }

    public int calculateMinimumHP(int[][] dungeon) {
        this.rows = dungeon.length;
        this.cols = dungeon[0].length;
        this.dp = new MyCircularQueue(this.cols);

        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = 0; row < this.rows; ++row) {
            for (int col = 0; col < this.cols; ++col) {
                currCell = dungeon[rows - row - 1][cols - col - 1];

                rightHealth = getMinHealth(currCell, row, col - 1);
                downHealth = getMinHealth(currCell, row - 1, col);
                nextHealth = Math.min(rightHealth, downHealth);

                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }
                this.dp.enQueue(minHealth);
            }
        }

        // retrieve the last element in the queue
        return this.dp.get(this.cols - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class MyCircularQueue {
    constructor(capacity) {
        this.queue = new Array(capacity);
        this.tailIndex = 0;
        this.capacity = capacity;
    }

    enQueue(value) {
        this.queue[this.tailIndex] = value;
        this.tailIndex = (this.tailIndex + 1) % this.capacity;
    }

    get(index) {
        return this.queue[index % this.capacity];
    }
}

var calculateMinimumHP = function (dungeon) {
    const rows = dungeon.length;
    const cols = dungeon[0].length;
    const dp = new MyCircularQueue(cols);

    const getMinHealth = (currCell, nextRow, nextCol) => {
        if (nextRow < 0 || nextCol < 0) return Infinity;
        const index = cols * nextRow + nextCol;
        const nextCell = dp.get(index);
        return Math.max(1, nextCell - currCell);
    };

    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            const currCell = dungeon[rows - row - 1][cols - col - 1];
            const rightHealth = getMinHealth(currCell, row, col - 1);
            const downHealth = getMinHealth(currCell, row - 1, col);
            const nextHealth = Math.min(rightHealth, downHealth);

            let minHealth;
            if (nextHealth !== Infinity) {
                minHealth = nextHealth;
            } else {
                minHealth = currCell >= 0 ? 1 : 1 - currCell;
            }

            dp.enQueue(minHealth);
        }
    }

    return dp.get(cols - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MyCircularQueue:
    def __init__(self, capacity: int) -> None:
        """
        Set the size of the queue to be k.
        """
        self.queue = [0] * capacity
        self.tailIndex = 0
        self.capacity = capacity

    def enQueue(self, value: int) -> None:
        """
        Insert an element into the circular queue.
        """
        self.queue[self.tailIndex] = value
        self.tailIndex = (self.tailIndex + 1) % self.capacity

    def get(self, index: int) -> int:
        return self.queue[index % self.capacity]


class Solution(object):
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows, cols = len(dungeon), len(dungeon[0])
        # Use a circular queue to keep a sliding window of DP values
        dp = MyCircularQueue(cols)

        def get_min_health(currCell: int, nextRow: int, nextCol: int) -> int:
            if nextRow < 0 or nextCol < 0:
                return float("inf")
            index = cols * nextRow + nextCol
            nextCell = dp.get(index)
            # hero needs at least 1 point to survive
            return max(1, nextCell - currCell)

        for row in range(rows):
            for col in range(cols):
                # iterate the grid in the reversed order
                currCell = dungeon[rows - row - 1][cols - col - 1]

                right_health = get_min_health(currCell, row, col - 1)
                down_health = get_min_health(currCell, row - 1, col)
                next_health = min(right_health, down_health)

                if next_health != float("inf"):
                    min_health = next_health
                else:
                    min_health = 1 if currCell >= 0 else (1 - currCell)

                dp.enQueue(min_health)
        # return the last element in the queue
        return dp.get(cols - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class MyCircularQueue {
    queue: number[];
    tailIndex: number;
    capacity: number;

    constructor(capacity: number) {
        this.queue = new Array(capacity);
        this.tailIndex = 0;
        this.capacity = capacity;
    }

    enQueue(value: number): void {
        this.queue[this.tailIndex] = value;
        this.tailIndex = (this.tailIndex + 1) % this.capacity;
    }

    get(index: number): number {
        return this.queue[index % this.capacity];
    }
}

function calculateMinimumHP(dungeon: number[][]): number {
    const rows = dungeon.length;
    const cols = dungeon[0].length;
    const dp = new MyCircularQueue(cols);

    const getMinHealth = (
        currCell: number,
        nextRow: number,
        nextCol: number,
    ): number => {
        if (nextRow < 0 || nextCol < 0) return Infinity;
        const index = cols * nextRow + nextCol;
        const nextCell = dp.get(index);
        return Math.max(1, nextCell - currCell);
    };

    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            const currCell = dungeon[rows - row - 1][cols - col - 1];
            const rightHealth = getMinHealth(currCell, row, col - 1);
            const downHealth = getMinHealth(currCell, row - 1, col);
            const nextHealth = Math.min(rightHealth, downHealth);

            let minHealth;
            if (nextHealth !== Infinity) {
                minHealth = nextHealth;
            } else {
                minHealth = currCell >= 0 ? 1 : 1 - currCell;
            }

            dp.enQueue(minHealth);
        }
    }

    return dp.get(cols - 1);
}
```

</details>
