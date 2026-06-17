# 1298. Maximum Candies You Can Get from Boxes

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/)  
`Array` `Breadth-First Search` `Graph Theory`

**Problem Link:** [LeetCode 1298 - Maximum Candies You Can Get from Boxes](https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/)

## Problem

You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:

- status[i] is 1 if the ith box is open and 0 if the ith box is closed,
- candies[i] is the number of candies in the ith box,
- keys[i] is a list of the labels of the boxes you can open after opening the ith box.
- containedBoxes[i] is a list of the boxes you found inside the ith box.

You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.

### Example 1

```text
Input: status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
Output: 16
Explanation: You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2.
Box 1 is closed and you do not have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
Total number of candies collected = 7 + 4 + 5 = 16 candy.
```

### Example 2

```text
Input: status = [1,0,0,0,0,0], candies = [1,1,1,1,1,1], keys = [[1,2,3,4,5],[],[],[],[],[]], containedBoxes = [[1,2,3,4,5],[],[],[],[],[]], initialBoxes = [0]
Output: 6
Explanation: You have initially box 0. Opening it you can find boxes 1,2,3,4 and 5 and their keys.
The total number of candies will be 6.
```

## Constraints

- n == status.length == candies.length == keys.length == containedBoxes.length
- 1 <= n <= 1000
- status[i] is either 0 or 1.
- 1 <= candies[i] <= 1000
- 0 <= keys[i].length <= n
- 0 <= keys[i][j] < n
- All values of keys[i] are unique.
- 0 <= containedBoxes[i].length <= n
- 0 <= containedBoxes[i][j] < n
- All values of containedBoxes[i] are unique.
- Each box is contained in one box at most.
- 0 <= initialBoxes.length <= n
- 0 <= initialBoxes[i] < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1298. Maximum Candies You Can Get from Boxes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Breadth-First Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Breadth-First Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxCandies(int* status, int statusSize, int* candies, int candiesSize,
               int** keys, int keysSize, int* keysColSize, int** containedBoxes,
               int containedBoxesSize, int* containedBoxesColSize,
               int* initialBoxes, int initialBoxesSize) {
    int n = statusSize;
    bool* canOpen = (bool*)calloc(n, sizeof(bool));
    bool* hasBox = (bool*)calloc(n, sizeof(bool));
    bool* used = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; ++i) {
        canOpen[i] = (status[i] == 1);
    }
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    int ans = 0;
    for (int i = 0; i < initialBoxesSize; ++i) {
        int box = initialBoxes[i];
        hasBox[box] = true;
        if (canOpen[box]) {
            queue[rear++] = box;
            used[box] = true;
            ans += candies[box];
        }
    }
    while (front < rear) {
        int bigBox = queue[front++];
        for (int i = 0; i < keysColSize[bigBox]; ++i) {
            int key = keys[bigBox][i];
            canOpen[key] = true;
            if (!used[key] && hasBox[key]) {
                queue[rear++] = key;
                used[key] = true;
                ans += candies[key];
            }
        }
        for (int i = 0; i < containedBoxesColSize[bigBox]; ++i) {
            int box = containedBoxes[bigBox][i];
            hasBox[box] = true;
            if (!used[box] && canOpen[box]) {
                queue[rear++] = box;
                used[box] = true;
                ans += candies[box];
            }
        }
    }
    free(canOpen);
    free(hasBox);
    free(used);
    free(queue);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> can_open(n), has_box(n), used(n);
        for (int i = 0; i < n; ++i) {
            can_open[i] = (status[i] == 1);
        }

        queue<int> q;
        int ans = 0;
        for (int box : initialBoxes) {
            has_box[box] = true;
            if (can_open[box]) {
                q.push(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (!q.empty()) {
            int big_box = q.front();
            q.pop();
            for (int key : keys[big_box]) {
                can_open[key] = true;
                if (!used[key] && has_box[key]) {
                    q.push(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            for (int box : containedBoxes[big_box]) {
                has_box[box] = true;
                if (!used[box] && can_open[box]) {
                    q.push(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxCandies(int[] status, int[] candies, int[][] keys,
                          int[][] containedBoxes, int[] initialBoxes) {
        int n = status.Length;
        bool[] canOpen = new bool[n];
        bool[] hasBox = new bool[n];
        bool[] used = new bool[n];

        for (int i = 0; i < n; ++i) {
            canOpen[i] = (status[i] == 1);
        }
        Queue<int> q = new Queue<int>();
        int ans = 0;
        foreach (int box in initialBoxes) {
            hasBox[box] = true;
            if (canOpen[box]) {
                q.Enqueue(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (q.Count > 0) {
            int bigBox = q.Dequeue();
            foreach (int key in keys[bigBox]) {
                canOpen[key] = true;
                if (!used[key] && hasBox[key]) {
                    q.Enqueue(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            foreach (int box in containedBoxes[bigBox]) {
                hasBox[box] = true;
                if (!used[box] && canOpen[box]) {
                    q.Enqueue(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxCandies(status []int, candies []int, keys [][]int, containedBoxes [][]int, initialBoxes []int) int {
    n := len(status)
	canOpen := make([]bool, n)
	hasBox := make([]bool, n)
	used := make([]bool, n)

	for i := 0; i < n; i++ {
		canOpen[i] = (status[i] == 1)
	}
	q := []int{}
	ans := 0
	for _, box := range initialBoxes {
		hasBox[box] = true
		if canOpen[box] {
            q = append(q, box)
			used[box] = true
			ans += candies[box]
		}
	}

	for len(q) > 0 {
		bigBox := q[0]
        q = q[1:]
		for _, key := range keys[bigBox] {
			canOpen[key] = true
			if !used[key] && hasBox[key] {
                q = append(q, key)
				used[key] = true
				ans += candies[key]
			}
		}
		for _, box := range containedBoxes[bigBox] {
			hasBox[box] = true
			if !used[box] && canOpen[box] {
				q = append(q, box)
				used[box] = true
				ans += candies[box]
			}
		}
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxCandies(
        int[] status,
        int[] candies,
        int[][] keys,
        int[][] containedBoxes,
        int[] initialBoxes
    ) {
        int n = status.length;
        boolean[] canOpen = new boolean[n];
        boolean[] hasBox = new boolean[n];
        boolean[] used = new boolean[n];

        for (int i = 0; i < n; ++i) {
            canOpen[i] = (status[i] == 1);
        }

        Queue<Integer> q = new LinkedList<>();
        int ans = 0;
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (canOpen[box]) {
                q.offer(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (!q.isEmpty()) {
            int bigBox = q.poll();
            for (int key : keys[bigBox]) {
                canOpen[key] = true;
                if (!used[key] && hasBox[key]) {
                    q.offer(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            for (int box : containedBoxes[bigBox]) {
                hasBox[box] = true;
                if (!used[box] && canOpen[box]) {
                    q.offer(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxCandies = function (
    status,
    candies,
    keys,
    containedBoxes,
    initialBoxes,
) {
    const n = status.length;
    const canOpen = new Array(n).fill(false);
    const hasBox = new Array(n).fill(false);
    const used = new Array(n).fill(false);

    for (let i = 0; i < n; ++i) {
        canOpen[i] = status[i] === 1;
    }
    const q = [];
    let ans = 0;
    for (const box of initialBoxes) {
        hasBox[box] = true;
        if (canOpen[box]) {
            q.push(box);
            used[box] = true;
            ans += candies[box];
        }
    }
    while (q.length > 0) {
        const bigBox = q.shift();
        for (const key of keys[bigBox]) {
            canOpen[key] = true;
            if (!used[key] && hasBox[key]) {
                q.push(key);
                used[key] = true;
                ans += candies[key];
            }
        }
        for (const box of containedBoxes[bigBox]) {
            hasBox[box] = true;
            if (!used[box] && canOpen[box]) {
                q.push(box);
                used[box] = true;
                ans += candies[box];
            }
        }
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCandies(
        self,
        status: List[int],
        candies: List[int],
        keys: List[List[int]],
        containedBoxes: List[List[int]],
        initialBoxes: List[int],
    ) -> int:
        n = len(status)
        can_open = [status[i] == 1 for i in range(n)]
        has_box, used = [False] * n, [False] * n

        q = collections.deque()
        ans = 0
        for box in initialBoxes:
            has_box[box] = True
            if can_open[box]:
                q.append(box)
                used[box] = True
                ans += candies[box]

        while len(q) > 0:
            big_box = q.popleft()
            for key in keys[big_box]:
                can_open[key] = True
                if not used[key] and has_box[key]:
                    q.append(key)
                    used[key] = True
                    ans += candies[key]
            for box in containedBoxes[big_box]:
                has_box[box] = True
                if not used[box] and can_open[box]:
                    q.append(box)
                    used[box] = True
                    ans += candies[box]

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxCandies(
    status: number[],
    candies: number[],
    keys: number[][],
    containedBoxes: number[][],
    initialBoxes: number[],
): number {
    const n = status.length;
    const canOpen: boolean[] = new Array(n).fill(false);
    const hasBox: boolean[] = new Array(n).fill(false);
    const used: boolean[] = new Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        canOpen[i] = status[i] === 1;
    }
    const q: number[] = [];
    let ans = 0;
    for (const box of initialBoxes) {
        hasBox[box] = true;
        if (canOpen[box]) {
            q.push(box);
            used[box] = true;
            ans += candies[box];
        }
    }
    while (q.length > 0) {
        const bigBox = q.shift()!;
        for (const key of keys[bigBox]) {
            canOpen[key] = true;
            if (!used[key] && hasBox[key]) {
                q.push(key);
                used[key] = true;
                ans += candies[key];
            }
        }
        for (const box of containedBoxes[bigBox]) {
            hasBox[box] = true;
            if (!used[box] && canOpen[box]) {
                q.push(box);
                used[box] = true;
                ans += candies[box];
            }
        }
    }

    return ans;
}
```

</details>
