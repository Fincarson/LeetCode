# 1561. Maximum Number of Coins You Can Get

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/)  
`Array` `Math` `Greedy` `Sorting` `Game Theory`

**Problem Link:** [LeetCode 1561 - Maximum Number of Coins You Can Get](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/)

## Problem

There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

- In each step, you will choose any 3 piles of coins (not necessarily consecutive).
- Of your choice, Alice will pick the pile with the maximum number of coins.
- You will pick the next pile with the maximum number of coins.
- Your friend Bob will pick the last pile.
- Repeat until there are no more piles of coins.

Given an array of integers piles where piles[i] is the number of coins in the ith pile.

Return the maximum number of coins that you can have.

### Example 1

```text
Input: piles = [2,4,1,2,7,8]
Output: 9
Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with 7 coins and Bob the last one.
Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with 2 coins and Bob the last one.
The maximum number of coins which you can have are: 7 + 2 = 9.
On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you only get 2 + 4 = 6 coins which is not optimal.
```

### Example 2

```text
Input: piles = [2,4,5]
Output: 4
```

### Example 3

```text
Input: piles = [9,8,7,6,5,1,2,3,4]
Output: 18
```

## Constraints

- 3 <= piles.length <= 105
- piles.length % 3 == 0
- 1 <= piles[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1561. Maximum Number of Coins You Can Get

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Simulation With Deque | C++, Java, Python3 |
| No Queue | C++, Java, Python3 |

## Approach 1: Greedy Simulation With Deque

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        deque<int> queue;
        for (int num : piles) {
            queue.push_back(num);
        }
        
        int ans = 0;
        while (!queue.empty()) {
            queue.pop_back(); // alice
            ans += queue.back(); // us
            queue.pop_back();
            queue.pop_front(); // bob
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        ArrayDeque<Integer> queue = new ArrayDeque();
        for (int num : piles) {
            queue.addLast(num);
        }
        
        int ans = 0;
        while (!queue.isEmpty()) {
            queue.removeLast(); // alice
            ans += queue.removeLast(); // us
            queue.removeFirst(); // bob
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        queue = deque(piles)
        ans = 0
        while queue:
            queue.pop() # alice
            ans += queue.pop() # us
            queue.popleft() # bob

        return ans
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
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        
        for (int i = piles.size() / 3; i < piles.size(); i += 2) {
            ans += piles[i];
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int ans = 0;
        
        for (int i = piles.length / 3; i < piles.length; i += 2) {
            ans += piles[i];
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        ans = 0
        
        for i in range(len(piles) // 3, len(piles), 2):
            ans += piles[i]
        
        return ans
```

</details>
