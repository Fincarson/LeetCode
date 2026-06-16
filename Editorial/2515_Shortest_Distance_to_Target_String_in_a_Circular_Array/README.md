# 2515. Shortest Distance to Target String in a Circular Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/)  
`Array` `String`

**Problem Link:** [LeetCode 2515 - Shortest Distance to Target String in a Circular Array](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/)

## Problem

You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

- Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.

Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

### Example 1

```text
Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
Output: 1
Explanation: We start from index 1 and can reach "hello" by
- moving 3 units to the right to reach index 4.
- moving 2 units to the left to reach index 4.
- moving 4 units to the right to reach index 0.
- moving 1 unit to the left to reach index 0.
The shortest distance to reach "hello" is 1.
```

### Example 2

```text
Input: words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
Output: 1
Explanation: We start from index 0 and can reach "leetcode" by
- moving 2 units to the right to reach index 2.
- moving 1 unit to the left to reach index 2.
The shortest distance to reach "leetcode" is 1.
```

### Example 3

```text
Input: words = ["i","eat","leetcode"], target = "ate", startIndex = 0
Output: -1
Explanation: Since "ate" does not exist in words, we return -1.
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] and target consist of only lowercase English letters.
- 0 <= startIndex < words.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Defuse the Bomb](https://leetcode.com/problems/defuse-the-bomb/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2515. Shortest Distance to Target String in a Circular Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int ans = wordsSize;
    int n = wordsSize;

    for (int i = 0; i < wordsSize; ++i) {
        if (strcmp(words[i], target) == 0) {
            int dist = abs(i - startIndex);
            ans = fmin(ans, fmin(dist, n - dist));
        }
    }

    return ans < n ? ans : -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = words.size();
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                ans = min(ans, min(dist, n - dist));
            }
        }

        return ans < n ? ans : -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int ClosestTarget(string[] words, string target, int startIndex) {
        int ans = words.Length;
        int n = words.Length;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int dist = Math.Abs(i - startIndex);
                ans = Math.Min(ans, Math.Min(dist, n - dist));
            }
        }

        return ans < n ? ans : -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func closestTarget(words []string, target string, startIndex int) int {
	ans := len(words)
	n := len(words)

	for i, word := range words {
		if word == target {
			dist := abs(i - startIndex)
			ans = min(ans, min(dist, n-dist))
		}
	}

	if ans < n {
		return ans
	}
	return -1
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int closestTarget(String[] words, String target, int startIndex) {
        int ans = words.length;
        int n = words.length;

        for (int i = 0; i < n; ++i) {
            if (words[i].equals(target)) {
                int dist = Math.abs(i - startIndex);
                ans = Math.min(ans, Math.min(dist, n - dist));
            }
        }

        return ans < n ? ans : -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var closestTarget = function (words, target, startIndex) {
    let ans = words.length;
    const n = words.length;

    for (let i = 0; i < n; ++i) {
        if (words[i] === target) {
            const dist = Math.abs(i - startIndex);
            ans = Math.min(ans, Math.min(dist, n - dist));
        }
    }

    return ans < n ? ans : -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closestTarget(
        self, words: List[str], target: str, startIndex: int
    ) -> int:
        ans = n = len(words)
        for i, word in enumerate(words):
            if word == target:
                ans = min(ans, abs(i - startIndex), n - abs(i - startIndex))
        return ans if ans < n else -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function closestTarget(
    words: string[],
    target: string,
    startIndex: number,
): number {
    let ans = words.length;
    const n = words.length;

    for (let i = 0; i < n; ++i) {
        if (words[i] === target) {
            const dist = Math.abs(i - startIndex);
            ans = Math.min(ans, Math.min(dist, n - dist));
        }
    }

    return ans < n ? ans : -1;
}
```

</details>
