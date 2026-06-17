# 159. Longest Substring with At Most Two Distinct Characters

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 159 - Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)

## Problem

Given a string s, return the length of the longest substring that contains at most two distinct characters.

### Example 1

```text
Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
```

### Example 2

```text
Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
```

## Constraints

- 1 <= s.length <= 105
- s consists of English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 159. Longest Substring with At Most Two Distinct Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hash {
    char key;
    int val;
    UT_hash_handle hh;
};

int lengthOfLongestSubstringTwoDistinct(char *s) {
    size_t n = strlen(s);
    if (n < 3) {
        return n;
    }

    int left = 0, right = 0;
    struct hash *hashmap = NULL, *element, *tmp;
    int max_len = 2;

    while (right < n) {
        HASH_FIND(hh, hashmap, &s[right], sizeof(char), element);
        if (element != NULL) {
            HASH_DEL(hashmap, element);
            free(element);
        }

        element = (struct hash *)malloc(sizeof(*element));
        if (element == NULL) return -1;

        element->key = s[right];
        element->val = right;
        HASH_ADD_KEYPTR(hh, hashmap, &element->key, sizeof(char), element);
        right++;

        if (HASH_COUNT(hashmap) == 3) {
            int del_idx = INT_MAX;
            HASH_ITER(hh, hashmap, element, tmp) {
                del_idx = del_idx < element->val ? del_idx : element->val;
            }

            HASH_FIND(hh, hashmap, &s[del_idx], sizeof(char), element);
            if (element != NULL) {
                HASH_DEL(hashmap, element);
                free(element);
            }
            left = del_idx + 1;
        }
        max_len = max_len > (right - left) ? max_len : (right - left);
    }
    return max_len;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        size_t n = s.length();
        if (n < 3) {
            return n;
        }

        // sliding window left and right pointers
        int left = 0, right = 0;
        // hashmap character -> its rightmost position
        // in the sliding window
        map<char, int> hashmap;

        int max_len = 2;

        while (right < n) {
            // when the sliding window contains less than 3 characters
            hashmap[s[right]] = right;
            right++;

            // slidewindow contains 3 characters
            if (hashmap.size() == 3) {
                int del_idx = INT_MAX;
                for (pair<char, int> element : hashmap) {
                    del_idx = min(del_idx, element.second);
                }
                // delete the leftmost character
                hashmap.erase(s[del_idx]);
                left = del_idx + 1;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.Length;
        if (n < 3) return n;

        // sliding window left and right pointers
        int left = 0;
        int right = 0;
        // hashmap character -> its rightmost position
        // in the sliding window
        Dictionary<char, int> hashmap = new Dictionary<char, int>();

        int max_len = 2;

        while (right < n) {
            // when the slidewindow contains less than 3 characters
            hashmap[s[right]] = right++;

            // slidewindow contains 3 characters
            if (hashmap.Count == 3) {
                // delete the leftmost character
                int del_idx = hashmap.Values.Min();
                hashmap.Remove(s[del_idx]);
                // move left pointer of the slidewindow
                left = del_idx + 1;
            }

            max_len = Math.Max(max_len, right - left);
        }

        return max_len;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lengthOfLongestSubstringTwoDistinct(s string) int {
    n := len(s)
    if n < 3 {
        return n
    }

    // sliding window left and right pointers
    left := 0
    right := 0
    // hashmap character -> its rightmost position
    // in the sliding window
    hashmap := make(map[rune]int)

    max_len := 2

    for right < n {
        // when the slidewindow contains less than 3 characters
        hashmap[rune(s[right])] = right
        right++

        // slidewindow contains 3 characters
        if len(hashmap) == 3 {
            // delete the leftmost character
            del_idx := n
            for _, v := range hashmap {
                if v < del_idx {
                    del_idx = v
                }
            }

            delete(hashmap, rune(s[del_idx]))
            left = del_idx + 1
        }

        current_len := right - left
        if current_len > max_len {
            max_len = current_len
        }
    }

    return max_len
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int n = s.length();
        if (n < 3) return n;

        // sliding window left and right pointers
        int left = 0;
        int right = 0;
        // hashmap character -> its rightmost position
        // in the sliding window
        HashMap<Character, Integer> hashmap = new HashMap<Character, Integer>();

        int max_len = 2;

        while (right < n) {
            // when the slidewindow contains less than 3 characters
            hashmap.put(s.charAt(right), right++);

            // slidewindow contains 3 characters
            if (hashmap.size() == 3) {
                // delete the leftmost character
                int del_idx = Collections.min(hashmap.values());
                hashmap.remove(s.charAt(del_idx));
                // move left pointer of the slidewindow
                left = del_idx + 1;
            }

            max_len = Math.max(max_len, right - left);
        }
        return max_len;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthOfLongestSubstringTwoDistinct = function (s) {
    let n = s.length;
    if (n < 3) return n;

    // sliding window left and right pointers
    let left = 0;
    let right = 0;
    // hashmap character -> its rightmost position
    // in the sliding window
    let hashmap = {};

    let max_len = 2;

    while (right < n) {
        // when the slidewindow contains less than 3 characters
        hashmap[s[right]] = right++;

        // slidewindow contains 3 characters
        if (Object.keys(hashmap).length == 3) {
            // delete the leftmost character
            let del_idx = Math.min(...Object.values(hashmap));
            delete hashmap[s[del_idx]];
            // move left pointer of the slidewindow
            left = del_idx + 1;
        }

        max_len = Math.max(max_len, right - left);
    }
    return max_len;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict


class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        n = len(s)
        if n < 3:
            return n

        # sliding window left and right pointers
        left, right = 0, 0
        # hashmap character -> its rightmost position
        # in the sliding window
        hashmap = defaultdict()

        max_len = 2

        while right < n:
            # when the slidewindow contains less than 3 characters
            hashmap[s[right]] = right
            right += 1

            # slidewindow contains 3 characters
            if len(hashmap) == 3:
                # delete the leftmost character
                del_idx = min(hashmap.values())
                del hashmap[s[del_idx]]
                # move left pointer of the slidewindow
                left = del_idx + 1

            max_len = max(max_len, right - left)

        return max_len
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthOfLongestSubstringTwoDistinct(s: string): number {
    let n = s.length;
    if (n < 3) return n;

    // sliding window left and right pointers
    let left = 0;
    let right = 0;
    // hashmap character -> its rightmost position
    // in the sliding window
    let hashmap: { [key: string]: number } = {};

    let max_len = 2;

    while (right < n) {
        // when the slidewindow contains less than 3 characters
        hashmap[s[right]] = right++;
        // slidewindow contains 3 characters
        if (Object.keys(hashmap).length == 3) {
            // delete the leftmost character
            let del_idx = Math.min(...Object.values(hashmap));
            delete hashmap[s[del_idx]];
            // move left pointer of the slidewindow
            left = del_idx + 1;
        }

        max_len = Math.max(max_len, right - left);
    }
    return max_len;
}
```

</details>
