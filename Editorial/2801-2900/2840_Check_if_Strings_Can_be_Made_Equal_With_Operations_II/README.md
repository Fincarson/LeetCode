# 2840. Check if Strings Can be Made Equal With Operations II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/)  
`Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 2840 - Check if Strings Can be Made Equal With Operations II](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/)

## Problem

You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

- Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.

Return true if you can make the strings s1 and s2 equal, and false otherwise.

### Example 1

```text
Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
```

### Example 2

```text
Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
```

## Constraints

- n == s1.length == s2.length
- 1 <= n <= 105
- s1 and s2 consist only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2840. Check if Strings Can be Made Equal With Operations II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool checkStrings(char* s1, char* s2) {
    int len = strlen(s1);
    int counts[256] = {0};

    for (int i = 0; i < len; i++) {
        int offset = (i & 1) << 7;
        counts[offset + s1[i]]++;
        counts[offset + s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (counts[i] != 0) {
            return false;
        }
    }

    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int counts[256] = {0};

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CheckStrings(string s1, string s2) {
        int[] counts = new int[256];

        for (int i = 0; i < s1.Length; i++) {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        foreach (int count in counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func checkStrings(s1 string, s2 string) bool {
	var counts [256]int

	for i := 0; i < len(s1); i++ {
		offset := (i & 1) << 7
		counts[offset+int(s1[i])]++
		counts[offset+int(s2[i])]--
	}

	for _, count := range counts {
		if count != 0 {
			return false
		}
	}

	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkStrings(String s1, String s2) {
        int[] count = new int[256];

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            count[offset + s1.charAt(i)]++;
            count[offset + s2.charAt(i)]--;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
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
var checkStrings = function (s1, s2) {
    const counts = new Int32Array(256);

    for (let i = 0; i < s1.length; i++) {
        const offset = (i & 1) << 7;
        counts[offset + s1.charCodeAt(i)]++;
        counts[offset + s2.charCodeAt(i)]--;
    }

    for (let i = 0; i < 256; i++) {
        if (counts[i] !== 0) {
            return false;
        }
    }

    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        return Counter(s1[::2]) == Counter(s2[::2]) and Counter(
            s1[1::2]
        ) == Counter(s2[1::2])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function checkStrings(s1: string, s2: string): boolean {
    const counts = new Int32Array(256);

    for (let i = 0; i < s1.length; i++) {
        const offset = (i & 1) << 7;
        counts[offset + s1.charCodeAt(i)]++;
        counts[offset + s2.charCodeAt(i)]--;
    }

    for (let i = 0; i < 256; i++) {
        if (counts[i] !== 0) {
            return false;
        }
    }

    return true;
}
```

</details>
