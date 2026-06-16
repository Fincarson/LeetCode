# 3160. Find the Number of Distinct Colors Among the Balls

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/)  
`Array` `Hash Table` `Simulation`

**Problem Link:** [LeetCode 3160 - Find the Number of Distinct Colors Among the Balls](https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/)

## Problem

You are given an integer limit and a 2D array queries of size n x 2.

There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of colors among the balls.

Return an array result of length n, where result[i] denotes the number of colors after ith query.

Note that when answering a query, lack of a color will not be considered as a color.

### Example 1

### Example 2

## Constraints

- 1 <= limit <= 109
- 1 <= n == queries.length <= 105
- queries[i].length == 2
- 0 <= queries[i][0] <= limit
- 1 <= queries[i][1] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Number of Balls in a Box](https://leetcode.com/problems/maximum-number-of-balls-in-a-box/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3160. Find the Number of Distinct Colors Among the Balls

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashmap and Array (MLE) | C++, Java, Python3 |
| Two Hash Maps | C++, Java, Python3 |

## Approach 1: Hashmap and Array (MLE)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap;
        vector<int> ballArray(limit + 1);

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0], color = queries[i][1];

            // Check if ball is already colored
            if (ballArray[ball] != 0) {
                // Decrement count of the previous color on the ball
                int prevColor = ballArray[ball];
                colorMap[prevColor]--;

                // If there are no balls with previous color left, remove color
                // from color map
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            // Set color of ball to the new color
            ballArray[ball] = color;

            // Increment the count of the new color
            colorMap[color]++;

            result[i] = colorMap.size();
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] result = new int[n];
        Map<Integer, Integer> colorMap = new HashMap<>();
        int[] ballArray = new int[limit + 1];

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0];
            int color = queries[i][1];

            // Check if ball is already colored
            if (ballArray[ball] != 0) {
                // Decrement count of the previous color on the ball
                int prevColor = ballArray[ball];
                colorMap.put(prevColor, colorMap.get(prevColor) - 1);

                // If there are no balls with previous color left, remove color from color map
                if (colorMap.get(prevColor) == 0) {
                    colorMap.remove(prevColor);
                }
            }
            // Set color of ball to the new color
            ballArray[ball] = color;

            // Increment the count of the new color
            colorMap.put(color, colorMap.getOrDefault(color, 0) + 1);

            result[i] = colorMap.size();
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        n = len(queries)
        result = []
        color_map = {}
        ball_array = [0] * (limit + 1)

        # Iterate through queries
        for i in range(n):
            # Extract ball label and color from query
            ball, color = queries[i]

            # Check if ball is already colored
            if ball_array[ball] != 0:
                # Decrement count of the previous color on the ball
                prev_color = ball_array[ball]
                color_map[prev_color] -= 1

                # If there are no balls with previous color left, remove color from color map
                if color_map[prev_color] == 0:
                    del color_map[prev_color]

            # Set color of ball to the new color
            ball_array[ball] = color

            # Increment the count of the new color
            color_map[color] = color_map.get(color, 0) + 1

            result.append(len(color_map))

        return result
```

</details>

<br>

## Approach 2: Two Hash Maps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap, ballMap;

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0], color = queries[i][1];

            // Check if ball is already covered
            if (ballMap.find(ball) != ballMap.end()) {
                // Decrement count of the previous color on the ball
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;

                // If there are no balls with previous color left, remove color
                // from color map
                if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
            }
            // Set color of ball to the new color
            ballMap[ball] = color;

            // Increment the count of the new color
            colorMap[color]++;

            result[i] = colorMap.size();
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] result = new int[n];
        Map<Integer, Integer> colorMap = new HashMap<>();
        Map<Integer, Integer> ballMap = new HashMap<>();

        // Iterate through queries
        for (int i = 0; i < n; i++) {
            // Extract ball label and color from query
            int ball = queries[i][0];
            int color = queries[i][1];

            // Check if ball is already colored
            if (ballMap.containsKey(ball)) {
                // Decrement count of the previous color on the ball
                int prevColor = ballMap.get(ball);
                colorMap.put(prevColor, colorMap.get(prevColor) - 1);

                // If there are no balls with previous color left, remove color from color map
                if (colorMap.get(prevColor) == 0) {
                    colorMap.remove(prevColor);
                }
            }
            // Set color of ball to the new color
            ballMap.put(ball, color);

            // Increment the count of the new color
            colorMap.put(color, colorMap.getOrDefault(color, 0) + 1);

            result[i] = colorMap.size();
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        n = len(queries)
        result = []
        color_map = {}
        ball_map = {}

        # Iterate through queries
        for i in range(n):
            # Extract ball label and color from query
            ball, color = queries[i]

            # Check if ball is already colored
            if ball in ball_map:
                # Decrement count of the previous color on the ball
                prev_color = ball_map[ball]
                color_map[prev_color] -= 1

                # If there are no balls with previous color left, remove color from color map
                if color_map[prev_color] == 0:
                    del color_map[prev_color]

            # Set color of ball to the new color
            ball_map[ball] = color

            # Increment the count of the new color
            color_map[color] = color_map.get(color, 0) + 1

            result.append(len(color_map))

        return result
```

</details>
