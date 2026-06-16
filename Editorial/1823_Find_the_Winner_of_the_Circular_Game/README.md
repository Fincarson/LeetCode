# 1823. Find the Winner of the Circular Game

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)  
`Array` `Math` `Recursion` `Queue` `Simulation`

**Problem Link:** [LeetCode 1823 - Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)

## Problem

There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Given the number of friends, n, and an integer k, return the winner of the game.

### Example 1

```text
Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
```

### Example 2

```text
Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
```

## Constraints

- 1 <= k <= n <= 500

Follow up:

Could you solve this problem in linear time with constant space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1823. Find the Winner of the Circular Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation with List | C++, Java, Python3 |
| Simulation with Queue | C++, Java, Python3 |
| Recursion | C++, Java, Python3 |
| Iterative | C++, Java, Python3 |

## Approach 1: Simulation with List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize vector of N friends, labeled from 1-N
        vector<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
        }

        // Maintain the index of the friend to start the count on
        int startIndex = 0;

        // Perform eliminations while there is more than 1 friend left
        while (circle.size() > 1) {
            // Calculate the index of the friend to be removed
            int removalIndex = (startIndex + k - 1) % circle.size();

            // Erase the friend at removalIndex
            circle.erase(circle.begin() + removalIndex);

            // Update startIndex for the next round
            startIndex = removalIndex;
        }

        return circle.front();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheWinner(int n, int k) {
        // Initialize list of N friends, labeled from 1-N
        List<Integer> circle = new LinkedList<Integer>();
        for (int i = 1; i <= n; i++) {
            circle.add(i);
        }

        // Maintain the index of the friend to start the count on
        int startIndex = 0;

        // Perform eliminations while there is more than 1 friend left
        while (circle.size() > 1) {
            // Calculate the index of the friend to be removed
            int removalIndex = (startIndex + k - 1) % circle.size();

            // Erase the friend at removalIndex
            circle.remove(removalIndex);

            // Update startIndex for the next round
            startIndex = removalIndex;
        }

        return circle.getFirst();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        # Initialize list of N friends, labeled from 1-N
        circle = list(range(1, n + 1))

        # Maintain the index of the friend to start the count on
        start_index = 0

        # Perform eliminations while there is more than 1 friend left
        while len(circle) > 1:
            # Calculate the index of the friend to be removed
            removal_index = (start_index + k - 1) % len(circle)

            # Remove the friend at removal_index
            circle.pop(removal_index)

            # Update the start_index for the next round
            start_index = removal_index

        return circle[0]
```

</details>

<br>

## Approach 2: Simulation with Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize queue with n friends
        queue<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push(i);
        }

        // Perform eliminations while more than 1 player remains
        while (circle.size() > 1) {
            // Process the first k-1 friends without eliminating them
            for (int i = 0; i < k - 1; i++) {
                circle.push(circle.front());
                circle.pop();
            }
            // Eliminate the k-th friend
            circle.pop();
        }

        return circle.front();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheWinner(int n, int k) {
        // Initialize queue with n friends
        Queue<Integer> circle = new LinkedList<Integer>();
        for (int i = 1; i <= n; i++) {
            circle.add(i);
        }

        // Perform eliminations while more than 1 player remains
        while (circle.size() > 1) {
            // Process the first k-1 friends without eliminating them
            for (int i = 0; i < k - 1; i++) {
                circle.add(circle.remove());
            }
            // Eliminate the k-th friend
            circle.remove();
        }

        return circle.peek();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        # Initialize deque with n friends
        circle = deque(range(1, n + 1))

        # Perform eliminations while more than 1 player remains
        while len(circle) > 1:
            # Process the first k-1 friends without eliminating them
            for _ in range(k - 1):
                circle.append(circle.popleft())
            # Eliminate the k-th friend
            circle.popleft()

        return circle[0]
```

</details>

<br>

## Approach 3: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheWinner(int n, int k) { return winnerHelper(n, k) + 1; }

private:
    int winnerHelper(int n, int k) {
        if (n == 1) return 0;
        return (winnerHelper(n - 1, k) + k) % n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheWinner(int n, int k) {
        return winnerHelper(n, k) + 1;
    }

    private int winnerHelper(int n, int k) {
        if (n == 1) {
            return 0;
        }
        return (winnerHelper(n - 1, k) + k) % n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        return self.winnerHelper(n, k) + 1

    def winnerHelper(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        return (self.winnerHelper(n - 1, k) + k) % n
```

</details>

<br>

## Approach 4: Iterative

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }
        // add 1 to convert back to 1 indexing
        return ans + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }
        // add 1 to convert back to 1 indexing
        return ans + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        ans = 0
        for i in range(2, n + 1):
            ans = (ans + k) % i
        # add 1 to convert back to 1 indexing
        return ans + 1
```

</details>
