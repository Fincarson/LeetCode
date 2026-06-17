# 2138. Divide a String Into Groups of Size k

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/)  
`String` `Simulation`

**Problem Link:** [LeetCode 2138 - Divide a String Into Groups of Size k](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/)

## Problem

A string s can be partitioned into groups of size k using the following procedure:

- The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
- For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.

Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.

### Example 1

```text
Input: s = "abcdefghi", k = 3, fill = "x"
Output: ["abc","def","ghi"]
Explanation:
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.
Since all groups can be completely filled by characters from the string, we do not need to use fill.
Thus, the groups formed are "abc", "def", and "ghi".
```

### Example 2

```text
Input: s = "abcdefghij", k = 3, fill = "x"
Output: ["abc","def","ghi","jxx"]
Explanation:
Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".
```

## Constraints

- 1 <= s.length <= 100
- s consists of lowercase English letters only.
- 1 <= k <= 100
- fill is a lowercase English letter.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Text Justification](https://leetcode.com/problems/text-justification/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Positions of Large Groups](https://leetcode.com/problems/positions-of-large-groups/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2138. Divide a String Into Groups of Size k

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Search for the starting index of each group | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Search for the starting index of each group

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char** divideString(char* s, int k, char fill, int* returnSize) {
    int n = strlen(s);
    int groupCount = (n + k - 1) / k;  // calculate the number of groups
    char** res = (char**)malloc(groupCount * sizeof(char*));
    *returnSize = groupCount;
    int curr = 0;  // starting index of each group
    // split string
    for (int i = 0; i < groupCount; ++i) {
        res[i] = (char*)malloc((k + 1) * sizeof(char));
        int len = (curr + k <= n) ? k : (n - curr);
        snprintf(res[i], len + 1, "%s", s + curr);
        curr += k;
    }
    // try to fill in the last group
    int lastLen = strlen(res[groupCount - 1]);
    if (lastLen < k) {
        for (int i = lastLen; i < k; ++i) {
            res[groupCount - 1][i] = fill;
        }
        res[groupCount - 1][k] = '\0';
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;  // grouped string
        int n = s.size();
        int curr = 0;  // starting index of each group
        // split string
        while (curr < n) {
            res.push_back(s.substr(curr, k));
            curr += k;
        }
        // try to fill in the last group
        res.back() += string(k - res.back().length(), fill);
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string[] DivideString(string s, int k, char fill) {
        List<string> res = new List<string>();  // grouped string
        int n = s.Length;
        int curr = 0;  // starting index of each group
        // split string
        while (curr < n) {
            int end = Math.Min(curr + k, n);
            res.Add(s.Substring(curr, end - curr));
            curr += k;
        }
        // try to fill in the last group
        string last = res[res.Count - 1];
        if (last.Length < k) {
            last += new string(fill, k - last.Length);
            res[res.Count - 1] = last;
        }
        return res.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func divideString(s string, k int, fill byte) []string {
	var res []string // grouped string
	n := len(s)
	curr := 0 // starting index of each group
	// split string
	for curr < n {
		end := curr + k
		if end > n {
			end = n
		}
		res = append(res, s[curr:end])
		curr += k
	}
	// try to fill in the last group
	last := res[len(res)-1]
	if len(last) < k {
		last += strings.Repeat(string(fill), k-len(last))
		res[len(res)-1] = last
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String[] divideString(String s, int k, char fill) {
        List<String> res = new ArrayList<>(); // grouped string
        int n = s.length();
        int curr = 0; // starting index of each group
        // split string
        while (curr < n) {
            int end = Math.min(curr + k, n);
            res.add(s.substring(curr, end));
            curr += k;
        }
        // try to fill in the last group
        String last = res.get(res.size() - 1);
        if (last.length() < k) {
            last += String.valueOf(fill).repeat(k - last.length());
            res.set(res.size() - 1, last);
        }
        return res.toArray(new String[0]);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var divideString = function (s, k, fill) {
    const res = []; // grouped string
    const n = s.length;
    let curr = 0; // starting index of each group
    // split string
    while (curr < n) {
        const end = Math.min(curr + k, n);
        res.push(s.slice(curr, end));
        curr += k;
    }
    // try to fill in the last group
    const last = res[res.length - 1];
    if (last.length < k) {
        res[res.length - 1] = last + fill.repeat(k - last.length);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        res = []  # grouped string
        n = len(s)
        curr = 0  # starting index of each group
        # split string
        while curr < n:
            res.append(s[curr : curr + k])
            curr += k
        # try to fill in the last group
        res[-1] += fill * (k - len(res[-1]))
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function divideString(s: string, k: number, fill: string): string[] {
    const res: string[] = []; // grouped string
    const n = s.length;
    let curr = 0; // starting index of each group
    // split string
    while (curr < n) {
        const end = Math.min(curr + k, n);
        res.push(s.slice(curr, end));
        curr += k;
    }
    // try to fill in the last group
    const last = res[res.length - 1];
    if (last.length < k) {
        res[res.length - 1] = last + fill.repeat(k - last.length);
    }
    return res;
}
```

</details>
