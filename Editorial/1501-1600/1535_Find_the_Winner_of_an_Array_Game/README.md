# 1535. Find the Winner of an Array Game

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-winner-of-an-array-game/)  
`Array` `Simulation`

**Problem Link:** [LeetCode 1535 - Find the Winner of an Array Game](https://leetcode.com/problems/find-the-winner-of-an-array-game/)

## Problem

Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]). In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0, and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.

### Example 1

```text
Input: arr = [2,1,3,5,4,6,7], k = 2
Output: 5
Explanation: Let's see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.
```

### Example 2

```text
Input: arr = [3,2,1], k = 10
Output: 3
Explanation: 3 will win the first 10 rounds consecutively.
```

## Constraints

- 2 <= arr.length <= 105
- 1 <= arr[i] <= 106
- arr contains distinct integers.
- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1535. Find the Winner of an Array Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulate Process With Queue | C++, Java, Python3 |
| No Queue | C++, Java, Python3 |

## Approach 1: Simulate Process With Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = arr[0];
        queue<int> queue;
        for (int i = 1; i < arr.size(); i++) {
            maxElement = max(maxElement, arr[i]);
            queue.push(arr[i]);
        }
        
        int curr = arr[0];
        int winstreak = 0;
        
        while (!queue.empty()) {
            int opponent = queue.front();
            queue.pop();
            
            if (curr > opponent) {
                queue.push(opponent);
                winstreak++;
            } else {
                queue.push(curr);
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxElement) {
                return curr;
            }
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
    public int getWinner(int[] arr, int k) {
        int maxElement = arr[0];
        Queue<Integer> queue = new LinkedList();
        for (int i = 1; i < arr.length; i++) {
            maxElement = Math.max(maxElement, arr[i]);
            queue.offer(arr[i]);
        }
        
        int curr = arr[0];
        int winstreak = 0;
        
        while (!queue.isEmpty()) {
            int opponent = queue.poll();
            
            if (curr > opponent) {
                queue.offer(opponent);
                winstreak++;
            } else {
                queue.offer(curr);
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxElement) {
                return curr;
            }
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        max_element = max(arr)
        queue = deque(arr[1:])
        curr = arr[0]
        winstreak = 0

        while queue:
            opponent = queue.popleft()
            if curr > opponent:
                queue.append(opponent)
                winstreak += 1
            else:
                queue.append(curr)
                curr = opponent
                winstreak = 1
            
            if winstreak == k or curr == max_element:
                return curr
```

</details>

<br>

## Approach 2: No Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxElement = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            maxElement = max(maxElement, arr[i]);
        }
        
        int curr = arr[0];
        int winstreak = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            int opponent = arr[i];
            
            if (curr > opponent) {
                winstreak++;
            } else {
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxElement) {
                return curr;
            }
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
    public int getWinner(int[] arr, int k) {
        int maxElement = arr[0];
        for (int i = 1; i < arr.length; i++) {
            maxElement = Math.max(maxElement, arr[i]);
        }
        
        int curr = arr[0];
        int winstreak = 0;
        
        for (int i = 1; i < arr.length; i++) {
            int opponent = arr[i];
            
            if (curr > opponent) {
                winstreak++;
            } else {
                curr = opponent;
                winstreak = 1;
            }
            
            if (winstreak == k || curr == maxElement) {
                return curr;
            }
        }
        
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        max_element = max(arr)
        curr = arr[0]
        winstreak = 0

        for i in range(1, len(arr)):
            opponent = arr[i]
            if curr > opponent:
                winstreak += 1
            else:
                curr = opponent
                winstreak = 1
            
            if winstreak == k or curr == max_element:
                return curr
```

</details>
