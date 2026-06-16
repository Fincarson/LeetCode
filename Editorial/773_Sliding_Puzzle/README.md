# 773. Sliding Puzzle

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/sliding-puzzle/)  
`Array` `Dynamic Programming` `Backtracking` `Breadth-First Search` `Memoization` `Matrix`

**Problem Link:** [LeetCode 773 - Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle/)

## Problem

On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

### Example 1

```text
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
```

### Example 2

```text
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
```

### Example 3

```text
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
```

## Constraints

- board.length == 2
- board[i].length == 3
- 0 <= board[i][j] <= 5
- Each value board[i][j] is unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 773. Sliding Puzzle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java, Python3 |
| Breadth-First Search (BFS) | C++, Java, Python3 |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Direction map for zero's possible moves in a flattened 1D array (2x3
    // board)
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                      {0, 4}, {3, 5, 1}, {4, 2}};

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Convert the 2D board into a string representation to use as state
        string startState;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                startState += to_string(board[i][j]);
            }
        }

        // Map to store the minimum moves for each visited state
        unordered_map<string, int> visited;

        // Start DFS traversal from initial board state
        dfs(startState, visited, startState.find('0'), 0);

        // Return the minimum moves required to reach the target state, or -1 if
        // unreachable
        return visited.count("123450") ? visited["123450"] : -1;
    }

private:
    void dfs(string state, unordered_map<string, int>& visited, int zeroPos,
             int moves) {
        // Skip if this state has been visited with fewer or equal moves
        if (visited.count(state) && visited[state] <= moves) {
            return;
        }
        visited[state] = moves;

        // Try moving zero to each possible adjacent position
        for (int nextPos : directions[zeroPos]) {
            swap(state[zeroPos], state[nextPos]);  // Swap to generate new state
            dfs(state, visited, nextPos,
                moves + 1);  // Recursive DFS with updated state and move count
            swap(state[zeroPos],
                 state[nextPos]);  // Swap back to restore original state
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction map for zero's possible moves in a flattened 1D array (2x3 board)
    private final int[][] directions = {
        { 1, 3 },
        { 0, 2, 4 },
        { 1, 5 },
        { 0, 4 },
        { 3, 5, 1 },
        { 4, 2 },
    };

    public int slidingPuzzle(int[][] board) {
        // Convert the 2D board into a string representation to use as state
        StringBuilder startState = new StringBuilder();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                startState.append(board[i][j]);
            }
        }

        // Map to store the minimum moves for each visited state
        Map<String, Integer> visited = new HashMap<>();

        // Start DFS traversal from initial board state
        dfs(startState.toString(), visited, startState.indexOf("0"), 0);

        // Return the minimum moves required to reach the target state, or -1 if unreachable
        return visited.getOrDefault("123450", -1);
    }

    private void dfs(
        String state,
        Map<String, Integer> visited,
        int zeroPos,
        int moves
    ) {
        // Skip if this state has been visited with fewer or equal moves
        if (visited.containsKey(state) && visited.get(state) <= moves) {
            return;
        }
        visited.put(state, moves);

        // Try moving zero to each possible adjacent position
        for (int nextPos : directions[zeroPos]) {
            String newState = swap(state, zeroPos, nextPos); // Swap to generate new state
            dfs(newState, visited, nextPos, moves + 1); // Recursive DFS with updated state and move count
        }
    }

    // Helper method to swap characters at indices i and j in the string
    private String swap(String str, int i, int j) {
        StringBuilder sb = new StringBuilder(str);
        sb.setCharAt(i, str.charAt(j));
        sb.setCharAt(j, str.charAt(i));
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Direction map for zero's possible moves in a flattened 1D array (2x3 board)
    directions = [
        [1, 3],
        [0, 2, 4],
        [1, 5],
        [0, 4],
        [3, 5, 1],
        [4, 2],
    ]

    def slidingPuzzle(self, board: List[List[int]]) -> int:
        # Helper method to swap characters at indices i and j in the string
        def _swap(s, i, j):
            s = list(s)
            s[i], s[j] = s[j], s[i]
            return "".join(s)

        # Convert the 2D board into a string representation to use as state
        start_state = "".join(str(num) for row in board for num in row)

        # Dictionary to store the minimum moves for each visited state
        visited = {}

        def _dfs(state, zero_pos, moves):
            # Skip if this state has been visited with fewer or equal moves
            if state in visited and visited[state] <= moves:
                return
            visited[state] = moves

            # Try moving zero to each possible adjacent position
            for next_pos in self.directions[zero_pos]:
                new_state = _swap(
                    state, zero_pos, next_pos
                )  # Swap to generate new state
                _dfs(
                    new_state, next_pos, moves + 1
                )  # Recursive DFS with updated state and move count

        # Start DFS traversal from initial board state
        _dfs(start_state, start_state.index("0"), 0)

        # Return the minimum moves required to reach the target state, or -1 if unreachable
        return visited.get("123450", -1)
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Direction map for zero's possible moves in a 1D representation of the
        // 2x3 board
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                          {0, 4}, {1, 3, 5}, {2, 4}};

        string target = "123450";
        string startState;

        // Convert the 2D board into a string representation
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                startState += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited;  // To store visited states
        queue<string> queue;
        queue.push(startState);
        visited.insert(startState);

        int moves = 0;

        // BFS to find the minimum number of moves
        while (!queue.empty()) {
            int size = queue.size();
            while (size-- > 0) {
                string currentState = queue.front();
                queue.pop();

                // Check if we reached the target solved state
                if (currentState == target) {
                    return moves;
                }

                int zeroPos = currentState.find('0');
                for (int newPos : directions[zeroPos]) {
                    string nextState = currentState;
                    swap(nextState[zeroPos], nextState[newPos]);

                    // Skip if this state has been visited
                    if (visited.count(nextState)) continue;

                    // Mark the new state as visited and add it to the queue
                    visited.insert(nextState);
                    queue.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int slidingPuzzle(int[][] board) {
        // Direction map for zero's possible moves in a 1D representation of the 2x3 board
        int[][] directions = new int[][] {
            { 1, 3 },
            { 0, 2, 4 },
            { 1, 5 },
            { 0, 4 },
            { 1, 3, 5 },
            { 2, 4 },
        };

        String target = "123450";
        StringBuilder startState = new StringBuilder();

        // Convert the 2D board into a string representation
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                startState.append(board[i][j]);
            }
        }

        Set<String> visited = new HashSet<>(); // To store visited states
        Queue<String> queue = new LinkedList<>();
        queue.add(startState.toString());
        visited.add(startState.toString());

        int moves = 0;

        // BFS to find the minimum number of moves
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                String currentState = queue.poll();

                // Check if we reached the target solved state
                if (currentState.equals(target)) {
                    return moves;
                }

                int zeroPos = currentState.indexOf('0');
                for (int newPos : directions[zeroPos]) {
                    String nextState = swap(currentState, zeroPos, newPos);

                    // Skip if this state has been visited
                    if (visited.contains(nextState)) continue;

                    // Mark the new state as visited and add it to the queue
                    visited.add(nextState);
                    queue.add(nextState);
                }
            }
            moves++;
        }
        return -1;
    }

    // Helper method to swap characters at indices i and j in the string
    private String swap(String str, int i, int j) {
        StringBuilder sb = new StringBuilder(str);
        sb.setCharAt(i, str.charAt(j));
        sb.setCharAt(j, str.charAt(i));
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def slidingPuzzle(self, board):
        # Direction map for zero's possible moves in a 1D representation of the 2x3 board
        directions = [
            [1, 3],
            [0, 2, 4],
            [1, 5],
            [0, 4],
            [1, 3, 5],
            [2, 4],
        ]

        # Helper method to swap characters at indices i and j in the string
        def _swap(state, i, j):
            state_list = list(state)
            state_list[i], state_list[j] = state_list[j], state_list[i]
            return "".join(state_list)

        target = "123450"
        start_state = "".join(str(num) for row in board for num in row)

        visited = set()  # To store visited states
        queue = deque([start_state])
        visited.add(start_state)

        moves = 0

        # BFS to find the minimum number of moves
        while queue:
            for _ in range(len(queue)):
                current_state = queue.popleft()

                # Check if we reached the target solved state
                if current_state == target:
                    return moves

                zero_pos = current_state.index("0")
                for new_pos in directions[zero_pos]:
                    next_state = _swap(current_state, zero_pos, new_pos)

                    # Skip if this state has been visited
                    if next_state in visited:
                        continue

                    # Mark the new state as visited and add it to the queue
                    visited.add(next_state)
                    queue.append(next_state)
            moves += 1

        return -1
```

</details>
