# 1399. Count Largest Group

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-largest-group/)  
`Hash Table` `Math` `Counting`

**Problem Link:** [LeetCode 1399 - Count Largest Group](https://leetcode.com/problems/count-largest-group/)

## Problem

You are given an integer n.

We need to group the numbers from 1 to n according to the sum of its digits. For example, the numbers 14 and 5 belong to the same group, whereas 13 and 3 belong to different groups.

Return the number of groups that have the largest size, i.e. the maximum number of elements.

### Example 1

```text
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
```

### Example 2

```text
Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
```

## Constraints

- 1 <= n <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1399. Count Largest Group

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Map | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Map

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countLargestGroup(int n) {
    int hashMap[100] = {0};
    int maxValue = 0;
    for (int i = 1; i <= n; ++i) {
        int key = 0, i0 = i;
        while (i0) {
            key += i0 % 10;
            i0 /= 10;
        }
        hashMap[key]++;
        if (hashMap[key] > maxValue) {
            maxValue = hashMap[key];
        }
    }

    int count = 0;
    for (int i = 0; i < 100; ++i) {
        if (hashMap[i] == maxValue) {
            count++;
        }
    }
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hashMap;
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int key = 0, i0 = i;
            while (i0) {
                key += i0 % 10;
                i0 /= 10;
            }
            ++hashMap[key];
            maxValue = max(maxValue, hashMap[key]);
        }
        int count = 0;
        for (auto& [_, value] : hashMap) {
            if (value == maxValue) {
                ++count;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CountLargestGroup(int n) {
        var hashMap = new Dictionary<int, int>();
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int key = 0, i0 = i;
            while (i0 > 0) {
                key += i0 % 10;
                i0 /= 10;
            }
            if (hashMap.ContainsKey(key)) {
                hashMap[key]++;
            } else {
                hashMap[key] = 1;
            }
            maxValue = Math.Max(maxValue, hashMap[key]);
        }

        int count = 0;
        foreach (var value in hashMap.Values) {
            if (value == maxValue) {
                count++;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countLargestGroup(n int) int {
	hashMap := make(map[int]int)
	maxValue := 0
	for i := 1; i <= n; i++ {
		key := 0
		i0 := i
		for i0 > 0 {
			key += i0 % 10
			i0 /= 10
		}
		hashMap[key]++
		maxValue = max(maxValue, hashMap[key])
	}

	count := 0
	for _, value := range hashMap {
		if value == maxValue {
			count++
		}
	}
	return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countLargestGroup(int n) {
        Map<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
        int maxValue = 0;
        for (int i = 1; i <= n; ++i) {
            int key = 0, i0 = i;
            while (i0 != 0) {
                key += i0 % 10;
                i0 /= 10;
            }
            hashMap.put(key, hashMap.getOrDefault(key, 0) + 1);
            maxValue = Math.max(maxValue, hashMap.get(key));
        }
        int count = 0;
        for (Map.Entry<Integer, Integer> kvpair : hashMap.entrySet()) {
            if (kvpair.getValue() == maxValue) {
                ++count;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countLargestGroup = function (n) {
    let hashMap = {};
    let maxValue = 0;
    for (let i = 1; i <= n; ++i) {
        let key = 0,
            i0 = i;
        while (i0) {
            key += i0 % 10;
            i0 = Math.floor(i0 / 10);
        }
        hashMap[key] = (hashMap[key] || 0) + 1;
        maxValue = Math.max(maxValue, hashMap[key]);
    }

    let count = 0;
    for (let value of Object.values(hashMap)) {
        if (value === maxValue) {
            count++;
        }
    }
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countLargestGroup(self, n: int) -> int:
        hashMap = collections.Counter()
        for i in range(1, n + 1):
            key = sum([int(x) for x in str(i)])
            hashMap[key] += 1
        maxValue = max(hashMap.values())
        count = sum(1 for v in hashMap.values() if v == maxValue)
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countLargestGroup(n: number): number {
    let hashMap: { [key: number]: number } = {};
    let maxValue = 0;
    for (let i = 1; i <= n; ++i) {
        let key = 0,
            i0 = i;
        while (i0) {
            key += i0 % 10;
            i0 = Math.floor(i0 / 10);
        }
        hashMap[key] = (hashMap[key] || 0) + 1;
        maxValue = Math.max(maxValue, hashMap[key]);
    }

    let count = 0;
    for (let value of Object.values(hashMap)) {
        if (value === maxValue) {
            count++;
        }
    }
    return count;
}
```

</details>
