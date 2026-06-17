# 277. Find the Celebrity

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-celebrity/)  
`Two Pointers` `Graph Theory` `Interactive`

**Problem Link:** [LeetCode 277 - Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/)

## Problem

Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given an integer n and a helper function bool knows(a, b) that tells you whether a knows b. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.

Note that the n x n 2D array graph given as input is not directly available to you, and instead only accessible through the helper function knows. graph[i][j] == 1 represents person i knows person j, wherease graph[i][j] == 0 represents person j does not know person i.

### Example 1

```text
Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
```

### Example 2

```text
Input: graph = [[1,0,1],[1,1,0],[0,1,1]]
Output: -1
Explanation: There is no celebrity.
```

## Constraints

- n == graph.length == graph[i].length
- 2 <= n <= 100
- graph[i][j] is 0 or 1.
- graph[i][i] == 1

Follow up: If the maximum number of allowed calls to the API knows is 3 * n, could you find a solution without exceeding the maximum number of calls?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 277. Find the Celebrity

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, JavaScript, Python |
| Logical Deduction | Java, JavaScript, Python |
| Logical Deduction with Caching | Java, JavaScript, Python |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution extends Relation {
    
    private int numberOfPeople;
    
    public int findCelebrity(int n) {
        numberOfPeople = n;
        for (int i = 0; i < n; i++) {
            if (isCelebrity(i)) {
                return i;
            }
        }
        return -1;
    }
    
    private boolean isCelebrity(int i) {
        for (int j = 0; j < numberOfPeople; j++) {
            if (i == j) continue; // Don't ask if they know themselves.
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function solution(knows) {
    function isCelebrity(i, n) {
        for (let j = 0; j < n; j++) {
            if (i === j) continue;
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }

    return function findCelebrity(n) {
        for (let i = 0; i < n; i++) {
            if (isCelebrity(i, n)) {
                return i;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def findCelebrity(self, n: int) -> int:
        self.n = n
        for i in range(n):
            if self.is_celebrity(i):
                return i
        return -1
    
    def is_celebrity(self, i):
        for j in range(self.n):
            if i == j: continue # Don't ask if they know themselves.
            if knows(i, j) or not knows(j, i):
                return False
        return True
```

</details>

<br>

## Approach 2: Logical Deduction

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution extends Relation {
    
    private int numberOfPeople;
    
    public int findCelebrity(int n) {
        numberOfPeople = n;
        int celebrityCandidate = 0;
        for (int i = 0; i < n; i++) {
            if (knows(celebrityCandidate, i)) {
                celebrityCandidate = i;
            }
        }
        if (isCelebrity(celebrityCandidate)) {
            return celebrityCandidate;
        }
        return -1;
    }
    
    private boolean isCelebrity(int i) {
        for (int j = 0; j < numberOfPeople; j++) {
            if (i == j) continue; // Don't ask if they know themselves.
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function solution(knows) {
    function isCelebrity(i, n) {
        for (let j = 0; j < n; j++) {
            if (i === j) continue;
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }

    return function findCelebrity(n) {
        let celebrityCandidate = 0;
        for (let i = 0; i < n; i++) {
            if (knows(celebrityCandidate, i)) {
                celebrityCandidate = i;
            }
        }
        if (isCelebrity(celebrityCandidate, n)) {
            return celebrityCandidate;
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def findCelebrity(self, n: int) -> int:
        self.n = n
        celebrity_candidate = 0
        for i in range(1, n):
            if knows(celebrity_candidate, i):
                celebrity_candidate = i
        if self.is_celebrity(celebrity_candidate):
            return celebrity_candidate
        return -1

    def is_celebrity(self, i):
        for j in range(self.n):
            if i == j: continue
            if knows(i, j) or not knows(j, i):
                return False
        return True
```

</details>

<br>

## Approach 3: Logical Deduction with Caching

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution extends Relation {
    
    private int numberOfPeople;
    private Map<Pair<Integer, Integer>, Boolean> cache = new HashMap<>(); 
    
    @Override
    public boolean knows(int a, int b) {
        if (!cache.containsKey(new Pair(a, b))) {
            cache.put(new Pair(a, b), super.knows(a, b));
        }
        return cache.get(new Pair(a, b));
    }
    
    public int findCelebrity(int n) {
        numberOfPeople = n;
        int celebrityCandidate = 0;
        for (int i = 0; i < n; i++) {
            if (knows(celebrityCandidate, i)) {
                celebrityCandidate = i;
            }
        }
        if (isCelebrity(celebrityCandidate)) {
            return celebrityCandidate;
        }
        return -1;
    }
    
    private boolean isCelebrity(int i) {
        for (int j = 0; j < numberOfPeople; j++) {
            if (i == j) continue; // Don't ask if they know themselves.
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function cached(f) {
    const cache = new Map();
    return function(...args) {
        const cacheKey = args.join(',');
        if (!cache.has(cacheKey)) {
            const value = f(...args);
            cache.set(cacheKey, value);
        }

        return cache.get(cacheKey);
    }
}

function solution(knows) {
    knows = cached(knows);

    function isCelebrity(i, n) {
        for (let j = 0; j < n; j++) {
            if (i === j) continue;
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }

    return function findCelebrity(n) {
        let celebrityCandidate = 0;
        for (let i = 0; i < n; i++) {
            if (knows(celebrityCandidate, i)) {
                celebrityCandidate = i;
            }
        }
        if (isCelebrity(celebrityCandidate, n)) {
            return celebrityCandidate;
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from functools import lru_cache

class Solution:
    
    @lru_cache(maxsize=None)
    def cachedKnows(self, a, b):
        return knows(a, b)
    
    def findCelebrity(self, n: int) -> int:
        self.n = n
        celebrity_candidate = 0
        for i in range(1, n):
            if self.cachedKnows(celebrity_candidate, i):
                celebrity_candidate = i
        if self.is_celebrity(celebrity_candidate):
            return celebrity_candidate
        return -1

    def is_celebrity(self, i):
        for j in range(self.n):
            if i == j: continue
            if self.cachedKnows(i, j) or not self.cachedKnows(j, i):
                return False
        return True
```

</details>
