# 3. Longest Substring Without Repeating Characters

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 3 - Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Problem

Given a string `s`, return the length of the longest contiguous substring that contains no repeated characters.

A substring must use consecutive characters from the original string.

## Examples

### Example 1

```text
Input: s = "abcabcbb"
Output: 3
Explanation: "abc", "bca", and "cab" are valid answers of length 3.
```

### Example 2

```text
Input: s = "bbbbb"
Output: 1
Explanation: The longest substring without repeating characters is "b".
```

### Example 3

```text
Input: s = "pwwkew"
Output: 3
Explanation: "wke" has length 3. "pwke" is not valid because it is not contiguous.
```

## Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols, and spaces.

## Follow-Up

Can you solve the problem in linear time?

## Hints

<details>
<summary><strong>Hint 1</strong></summary>

Start by checking every possible starting index. Stop extending a substring as soon as a duplicate character appears.

</details>

<details>
<summary><strong>Hint 2</strong></summary>

A sliding window can represent the current substring with no repeated characters.

</details>

<details>
<summary><strong>Hint 3</strong></summary>

Instead of moving the left side one step at a time, store the last index where each character appeared and jump directly past duplicates.

</details>

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Equal Count Substrings](https://leetcode.com/problems/number-of-equal-count-substrings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Consecutive Cards to Pick Up](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Complete Subarrays in an Array](https://leetcode.com/problems/count-complete-subarrays-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Longest Special Substring That Occurs Thrice II](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Longest Special Substring That Occurs Thrice I](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3. Longest Substring Without Repeating Characters

## Overview

The official editorial uses hash-table-backed substring checks, then improves the search with a sliding window.

The core idea is to keep track of whether the current substring has duplicates. Once a duplicate is present, the left boundary must move until the window becomes valid again.

| Approach | Time | Space | Idea |
|---|:---:|:---:|---|
| Brute Force (TLE) | `O(n^3)` | `O(min(n, k))` | Check every substring for uniqueness. |
| Sliding Window | `O(n)` | `O(min(n, k))` | Maintain a valid window by shrinking from the left when a duplicate appears. |
| Sliding Window Optimized | `O(n)` | `O(min(n, k))` | Store the next valid left position for each character. |

## Approach 1: Brute Force (TLE)

### Intuition

The most direct method is to test each possible substring and update the answer when all characters are unique.

### Algorithm

1. Enumerate every start index `i`.
2. Enumerate every end index `j`.
3. Check whether `s[i..j]` contains duplicate characters.
4. Update the answer for every unique substring.

### Complexity

- Time complexity: `O(n^3)`
- Space complexity: `O(min(n, k))`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool checkRepetition(char* s, int start, int end) {
    bool chars[128] = {0};
    for (int i = start; i <= end; i++) {
        char c = s[i];
        if (chars[c]) {
            return false;
        }
        chars[c] = true;
    }
    return true;
}

int max(int a, int b) { return (a > b) ? a : b; }

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (checkRepetition(s, i, j)) {
                res = max(res, j - i + 1);
            }
        }
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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        unordered_set<char> chars;

        for (int i = start; i <= end; i++) {
            char c = s[i];
            if (chars.count(c)) {
                return false;
            }
            chars.insert(c);
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
    public int LengthOfLongestSubstring(string s) {
        int n = s.Length;

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (CheckRepetition(s, i, j)) {
                    res = Math.Max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    private bool CheckRepetition(string s, int start, int end) {
        HashSet<char> chars = new HashSet<char>();

        for (int i = start; i <= end; i++) {
            char c = s[i];
            if (chars.Contains(c)) {
                return false;
            }

            chars.Add(c);
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lengthOfLongestSubstring(s string) int {
	n := len(s)

	res := 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			if checkRepetition(s, i, j) {
				if res < j-i+1 {
					res = j - i + 1
				}
			}
		}
	}

	return res
}

func checkRepetition(s string, start, end int) bool {
	chars := make(map[byte]bool)

	for i := start; i <= end; i++ {
		c := s[i]
		if _, ok := chars[c]; ok {
			return false
		}
		chars[c] = true
	}

	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int lengthOfLongestSubstring(String s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = Math.max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    private boolean checkRepetition(String s, int start, int end) {
        Set<Character> chars = new HashSet<>();

        for (int i = start; i <= end; i++) {
            char c = s.charAt(i);
            if (chars.contains(c)) {
                return false;
            }
            chars.add(c);
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthOfLongestSubstring = function (s) {
    const n = s.length;

    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (checkRepetition(s, i, j)) {
                res = Math.max(res, j - i + 1);
            }
        }
    }

    function checkRepetition(s, start, end) {
        const chars = new Set();

        for (let i = start; i <= end; i++) {
            const c = s[i];
            if (chars.has(c)) {
                return false;
            }
            chars.add(c);
        }

        return true;
    }

    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def check(start, end):
            chars = set()
            for i in range(start, end + 1):
                c = s[i]
                if c in chars:
                    return False
                chars.add(c)
            return True

        n = len(s)

        res = 0
        for i in range(n):
            for j in range(i, n):
                if check(i, j):
                    res = max(res, j - i + 1)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthOfLongestSubstring(s: string): number {
    const n = s.length;

    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (checkRepetition(s, i, j)) {
                res = Math.max(res, j - i + 1);
            }
        }
    }

    function checkRepetition(s: string, start: number, end: number): boolean {
        const chars = new Set<string>();

        for (let i = start; i <= end; i++) {
            const c = s[i];
            if (chars.has(c)) {
                return false;
            }
            chars.add(c);
        }

        return true;
    }

    return res;
}
```

</details>

<br>

## Approach 2: Sliding Window

### Intuition

Instead of rechecking every substring, keep counts for the current window and move the boundaries as needed.

### Algorithm

1. Move `right` through the string.
2. Add the right character to the window count.
3. While that character appears more than once, remove characters from the left.
4. Update the best window length.

### Complexity

- Time complexity: `O(n)`
- Space complexity: `O(min(n, k))`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int lengthOfLongestSubstring(char* s) {
    int chars[128] = {0};

    int left = 0;
    int right = 0;

    int res = 0;
    int n = strlen(s);
    while (right < n) {
        char r = s[right];
        chars[(int)r]++;

        while (chars[(int)r] > 1) {
            char l = s[left];
            chars[(int)l]--;
            left++;
        }

        int currentLength = right - left + 1;
        if (currentLength > res) {
            res = currentLength;
        }

        right++;
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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> chars = new Dictionary<char, int>();

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.Length) {
            char r = s[right];
            if (!chars.ContainsKey(r)) {
                chars[r] = 0;
            }

            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = Math.Max(res, right - left + 1);

            right++;
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lengthOfLongestSubstring(s string) int {
	chars := make(map[byte]int)

	left := 0
	right := 0

	res := 0
	for right < len(s) {
		r := s[right]
		chars[r]++

		for chars[r] > 1 {
			l := s[left]
			chars[l]--
			left++
		}

		res = max(res, right-left+1)
		right++
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> chars = new HashMap();

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s.charAt(right);
            chars.put(r, chars.getOrDefault(r, 0) + 1);

            while (chars.get(r) > 1) {
                char l = s.charAt(left);
                chars.put(l, chars.get(l) - 1);
                left++;
            }

            res = Math.max(res, right - left + 1);

            right++;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthOfLongestSubstring = function (s) {
    const chars = new Map();

    let left = 0;
    let right = 0;

    let res = 0;
    while (right < s.length) {
        const r = s.charAt(right);
        chars.set(r, (chars.get(r) || 0) + 1);

        while (chars.get(r) > 1) {
            const l = s.charAt(left);
            chars.set(l, chars.get(l) - 1);
            left++;
        }

        res = Math.max(res, right - left + 1);
        right++;
    }

    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = Counter()

        left = right = 0

        res = 0
        while right < len(s):
            r = s[right]
            chars[r] += 1

            while chars[r] > 1:
                l = s[left]
                chars[l] -= 1
                left += 1

            res = max(res, right - left + 1)

            right += 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthOfLongestSubstring(s: string): number {
    const chars = new Map<string, number>();

    let left = 0;
    let right = 0;

    let res = 0;
    while (right < s.length) {
        const r = s[right];
        chars.set(r, (chars.get(r) || 0) + 1);

        while (chars.get(r) > 1) {
            const l = s[left];
            chars.set(l, chars.get(l) - 1);
            left++;
        }

        res = Math.max(res, right - left + 1);
        right++;
    }

    return res;
}
```

</details>

<br>

## Approach 3: Sliding Window Optimized

### Intuition

If a character repeats inside the current window, jump `left` directly past its previous occurrence instead of moving one step at a time.

### Algorithm

1. Track each character with the index after its latest occurrence.
2. For each `right`, update `left` to the larger of its current value and the stored next index.
3. Record the next index for the current character.
4. Update the maximum window length.

### Complexity

- Time complexity: `O(n)`
- Space complexity: `O(min(n, k))`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int a, int b) { return (a > b) ? a : b; }

int lengthOfLongestSubstring(char* s) {
    int charToNextIndex[256] = {0};  // ASCII map to store last index + 1
    int maxLen = 0;
    int left = 0;
    int n = strlen(s);
    for (int right = 0; right < n; right++) {
        int index = (int)s[right];
        if (charToNextIndex[index] > 0) {
            left = max(left, charToNextIndex[index]);
        }
        maxLen = max(maxLen, right - left + 1);
        charToNextIndex[index] = right + 1;
    }
    return maxLen;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> charToNextIndex;

        for (int j = 0, i = 0; j < n; j++) {
            if (charToNextIndex[s[j]] > 0) {
                i = max(charToNextIndex[s[j]], i);
            }
            res = max(res, j - i + 1);
            charToNextIndex[s[j]] = j + 1;
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> charToNextIndex = new Dictionary<char, int>();
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.Length; right++) {
            if (charToNextIndex.ContainsKey(s[right])) {
                left = Math.Max(charToNextIndex[s[right]], left);
            }

            maxLen = Math.Max(maxLen, right - left + 1);
            charToNextIndex[s[right]] = right + 1;
        }

        return maxLen;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lengthOfLongestSubstring(s string) int {
	charToNextIndex := make(map[byte]int)
	maxLen := 0
	left := 0
	for right := 0; right < len(s); right++ {
		if prev, ok := charToNextIndex[s[right]]; ok {
			left = max(left, prev)
		}
		maxLen = max(maxLen, right-left+1)
		charToNextIndex[s[right]] = right + 1
	}
	return maxLen
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> charToNextIndex = new HashMap<>(); // index after current character
        // try to extend the range [i, j]
        for (int j = 0, i = 0; j < n; j++) {
            if (charToNextIndex.containsKey(s.charAt(j))) {
                i = Math.max(charToNextIndex.get(s.charAt(j)), i);
            }
            ans = Math.max(ans, j - i + 1);
            charToNextIndex.put(s.charAt(j), j + 1);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthOfLongestSubstring = function (s) {
    let charToNextIndex = new Map();
    let maxLen = 0;
    let left = 0;
    for (let right = 0; right < s.length; right++) {
        if (charToNextIndex.has(s[right])) {
            left = Math.max(charToNextIndex.get(s[right]), left);
        }
        maxLen = Math.max(maxLen, right - left + 1);
        charToNextIndex.set(s[right], right + 1);
    }
    return maxLen;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0
        # charToNextIndex stores the index after current character
        charToNextIndex = {}

        i = 0
        # try to extend the range [i, j]
        for j in range(n):
            if s[j] in charToNextIndex:
                i = max(charToNextIndex[s[j]], i)

            ans = max(ans, j - i + 1)
            charToNextIndex[s[j]] = j + 1

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthOfLongestSubstring(s: string): number {
    let charToNextIndex = new Map<string, number>();
    let maxLen = 0;
    let left = 0;
    for (let right = 0; right < s.length; right++) {
        if (charToNextIndex.has(s[right])) {
            left = Math.max(charToNextIndex.get(s[right])!, left);
        }
        maxLen = Math.max(maxLen, right - left + 1);
        charToNextIndex.set(s[right], right + 1);
    }
    return maxLen;
}
```

</details>
