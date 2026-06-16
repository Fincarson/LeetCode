# 997. Find the Town Judge

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-the-town-judge/)  
`Array` `Hash Table` `Graph Theory`

**Problem Link:** [LeetCode 997 - Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/)

## Problem

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

### Example 1

```text
Input: n = 2, trust = [[1,2]]
Output: 2
```

### Example 2

```text
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
```

### Example 3

```text
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

## Constraints

- 1 <= n <= 1000
- 0 <= trust.length <= 104
- trust[i].length == 2
- All the pairs of trust are unique.
- ai != bi
- 1 <= ai, bi <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 997. Find the Town Judge

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Arrays | Java, Python |
| One Array | Java, Python |

## Approach 1: Two Arrays

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int findJudge(int N, int[][] trust) {
    
    if (trust.length < N - 1) {
        return -1;
    }
    
    int[] indegrees = new int[N + 1];
    int[] outdegrees = new int[N + 1];

    for (int[] relation : trust) {
        outdegrees[relation[0]]++;
        indegrees[relation[1]]++; 
    }

    for (int i = 1; i <= N; i++) {
        if (indegrees[i] == N - 1 && outdegrees[i] == 0) {
            return i;
        }
    }
    return -1;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def findJudge(self, N: int, trust: List[List[int]]) -> int:
    
    if len(trust) < N - 1:
        return -1
    
    indegree = [0] * (N + 1)
    outdegree = [0] * (N + 1)
    
    for a, b in trust:
        outdegree[a] += 1
        indegree[b] += 1
        
    for i in range(1, N + 1):
        if indegree[i] == N - 1 and outdegree[i] == 0:
            return i
    return -1
```

</details>

<br>

## Approach 2: One Array

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int findJudge(int N, int[][] trust) {
        
    if (trust.length < N - 1) {
        return -1;
    }
    
    int[] trustScores = new int[N + 1];

    for (int[] relation : trust) {
        trustScores[relation[0]]--;
        trustScores[relation[1]]++; 
    }
    
    for (int i = 1; i <= N; i++) {
        if (trustScores[i] == N - 1) {
            return i;
        }
    }
    return -1;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def findJudge(self, N: int, trust: List[List[int]]) -> int:

    if len(trust) < N - 1:
        return -1

    trust_scores = [0] * (N + 1)

    for a, b in trust:
        trust_scores[a] -= 1
        trust_scores[b] += 1
    
    for i, score in enumerate(trust_scores[1:], 1):
        if score == N - 1:
            return i
    return -1
```

</details>
