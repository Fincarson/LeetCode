# 1128. Number of Equivalent Domino Pairs

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/number-of-equivalent-domino-pairs/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 1128 - Number of Equivalent Domino Pairs](https://leetcode.com/problems/number-of-equivalent-domino-pairs/)

## Problem

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

### Example 1

```text
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
```

### Example 2

```text
Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3
```

## Constraints

- 1 <= dominoes.length <= 4 * 104
- dominoes[i].length == 2
- 1 <= dominoes[i][j] <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1128. Number of Equivalent Domino Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Tuple Representation + Counting | C, C++, Go, Java, JavaScript, Python3 |

## Approach: Tuple Representation + Counting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numEquivDominoPairs(int** dominoes, int dominoesSize,
                        int* dominoesColSize) {
    int num[100];
    memset(num, 0, sizeof(num));
    int ret = 0;
    for (int i = 0; i < dominoesSize; i++) {
        int val = dominoes[i][0] < dominoes[i][1]
                      ? dominoes[i][0] * 10 + dominoes[i][1]
                      : dominoes[i][1] * 10 + dominoes[i][0];
        ret += num[val];
        num[val]++;
    }
    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100);
        int ret = 0;
        for (auto& it : dominoes) {
            int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
            ret += num[val];
            num[val]++;
        }
        return ret;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numEquivDominoPairs(dominoes [][]int) (ans int) {
	cnt := [100]int{}
	for _, d := range dominoes {
		if d[0] > d[1] {
			d[0], d[1] = d[1], d[0]
		}
		v := d[0]*10 + d[1]
		ans += cnt[v]
		cnt[v]++
	}
	return
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numEquivDominoPairs(int[][] dominoes) {
        int[] num = new int[100];
        int ret = 0;
        for (int[] domino : dominoes) {
            int val = domino[0] < domino[1]
                ? domino[0] * 10 + domino[1]
                : domino[1] * 10 + domino[0];
            ret += num[val];
            num[val]++;
        }
        return ret;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numEquivDominoPairs = function (dominoes) {
    const num = new Array(100).fill(0);
    let ret = 0;
    for (const domino of dominoes) {
        const val =
            domino[0] < domino[1]
                ? domino[0] * 10 + domino[1]
                : domino[1] * 10 + domino[0];
        ret += num[val];
        num[val]++;
    }
    return ret;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        num = [0] * 100
        ret = 0
        for x, y in dominoes:
            val = x * 10 + y if x <= y else y * 10 + x
            ret += num[val]
            num[val] += 1
        return ret
```

</details>
