# 1306. Jump Game III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/jump-game-iii/)  
`Array` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 1306 - Jump Game III](https://leetcode.com/problems/jump-game-iii/)

## Problem

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

### Example 1

```text
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation:
All possible ways to reach at index 3 with value 0 are:
index 5 -> index 4 -> index 1 -> index 3
index 5 -> index 6 -> index 4 -> index 1 -> index 3
```

### Example 2

```text
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true
Explanation:
One possible way to reach at index 3 with value 0 is:
index 0 -> index 4 -> index 1 -> index 3
```

### Example 3

```text
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
```

## Constraints

- 1 <= arr.length <= 5 * 104
- 0 <= arr[i] < arr.length
- 0 <= start < arr.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game](https://leetcode.com/problems/jump-game/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game VIII](https://leetcode.com/problems/jump-game-viii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1306. Jump Game III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search | C++, Java, Python3 |
| Depth-First Search | C++, Java, Python3 |

## Approach 1: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        size_t n = arr.size();

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // check if we reached zero
            if (arr[node] == 0) {
                return true;
            }
            if (arr[node] > 0) {
                // check available next steps
                if (node + arr[node] < n) {
                    q.push(node + arr[node]);
                }
                if (node - arr[node] >= 0) {
                    q.push(node - arr[node]);
                }
                // mark as visited
                arr[node] = -arr[node];
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canReach(int[] arr, int start) {
        int n = arr.length;

        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        while (!q.isEmpty()) {
            int node = q.poll();
            // check if reach zero
            if (arr[node] == 0) {
                return true;
            }
            if (arr[node] < 0) {
                continue;
            }

            // check available next steps
            if (node + arr[node] < n) {
                q.offer(node + arr[node]);
            }
            if (node - arr[node] >= 0) {
                q.offer(node - arr[node]);
            }
            // mark as visited
            arr[node] = -arr[node];
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        q = deque([start])

        while q:
            node = q.popleft()
            # Check if we reached zero
            if arr[node] == 0:
                return True
            if arr[node] < 0:
                continue

            # Check available next steps
            for i in [node + arr[node], node - arr[node]]:
                if 0 <= i < n:
                    q.append(i)

            # Mark as visited
            arr[node] = -arr[node]
        return False
```

</details>

<br>

## Approach 2: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start >= 0 and start < arr.size() and arr[start] >= 0) {
            if (arr[start] == 0) {
                return true;
            }
            arr[start] = -arr[start];
            return canReach(arr, start + arr[start]) or
                   canReach(arr, start - arr[start]);
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canReach(int[] arr, int start) {
        if (start >= 0 && start < arr.length && arr[start] >= 0) {
            if (arr[start] == 0) {
                return true;
            }
            arr[start] = -arr[start];
            return (
                canReach(arr, start + arr[start]) ||
                canReach(arr, start - arr[start])
            );
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if 0 <= start < len(arr) and arr[start] >= 0:
            if arr[start] == 0:
                return True

            arr[start] = -arr[start]
            return self.canReach(arr, start + arr[start]) or self.canReach(
                arr, start - arr[start]
            )

        return False
```

</details>
