# 76. Minimum Window Substring

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-window-substring/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 76 - Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

## Problem

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

### Example 1

```text
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

### Example 2

```text
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

### Example 3

```text
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

## Constraints

- m == s.length
- n == t.length
- 1 <= m, n <= 105
- s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Permutation in String](https://leetcode.com/problems/permutation-in-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Substrings That Can Be Rearranged to Contain a String II](https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Substrings That Can Be Rearranged to Contain a String I](https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 76. Minimum Window Substring

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Optimized Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* minWindow(char* s, char* t) {
    if (strlen(s) == 0 || strlen(t) == 0) {
        return "";
    }
    // Dictionary which keeps a count of all the unique characters in t.
    int dictT[128] = {0};
    for (int i = 0; i < strlen(t); i++) {
        dictT[t[i]]++;
    }
    // Number of unique characters in t, which need to be present in the desired
    // window.
    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (dictT[i] > 0) required++;
    }
    // Left and Right pointer
    int l = 0, r = 0;
    // formed is used to keep track of how many unique characters in t
    // are present in the current window in its desired frequency.
    // e.g. if t is "AABC" then the window must have two A's, one B and one C.
    // Thus formed would be = 3 when all these conditions are met.
    int formed = 0;
    // Dictionary which keeps a count of all the unique characters in the
    // current window.
    int windowCounts[128] = {0};
    // ans list of the form (window length, left, right)
    int ans[3] = {-1, 0, 0};
    while (r < strlen(s)) {
        // Add one character from the right to the window
        char c = s[r];
        windowCounts[c]++;
        // If the frequency of the current character added equals to the
        // desired count in t then increment the formed count by 1.
        if (dictT[c] != 0 && windowCounts[c] == dictT[c]) {
            formed++;
        }
        // Try and contract the window till the point where it ceases to be
        // 'desirable'.
        while (l <= r && formed == required) {
            c = s[l];
            // Save the smallest window until now.
            if (ans[0] == -1 || r - l + 1 < ans[0]) {
                ans[0] = r - l + 1;
                ans[1] = l;
                ans[2] = r;
            }
            // The character at the position pointed by the
            // `Left` pointer is no longer a part of the window.
            windowCounts[c]--;
            if (dictT[c] != 0 && windowCounts[c] < dictT[c]) {
                formed--;
            }
            // Move the left pointer ahead, this would help to look for a new
            // window.
            l++;
        }
        // Keep expanding the window once we are done contracting.
        r++;
    }
    if (ans[0] == -1) return "";
    char* res = (char*)malloc(sizeof(char) * (ans[0] + 1));
    strncpy(res, s + ans[1], ans[0]);
    res[ans[0]] = '\0';
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        // Dictionary which keeps a count of all the unique characters in t.
        unordered_map<char, int> dictT;
        for (int i = 0; i < t.length(); i++) {
            dictT[t[i]]++;
        }
        // Number of unique characters in t, which need to be present in the
        // desired window.
        int required = dictT.size();
        // Left and Right pointer
        int l = 0, r = 0;
        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one
        // C. Thus formed would be = 3 when all these conditions are met.
        int formed = 0;
        // Dictionary which keeps a count of all the unique characters in the
        // current window.
        unordered_map<char, int> windowCounts;
        // ans list of the form (window length, left, right)
        int ans[3] = {-1, 0, 0};
        while (r < s.length()) {
            // Add one character from the right to the window
            char c = s[r];
            windowCounts[c]++;
            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }
            // Try and contract the window till the point where it ceases to be
            // 'desirable'.
            while (l <= r && formed == required) {
                c = s[l];
                // Save the smallest window until now.
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }
                // The character at the position pointed by the
                // `Left` pointer is no longer a part of the window.
                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() &&
                    windowCounts[c] < dictT[c]) {
                    formed--;
                }
                // Move the left pointer ahead, this would help to look for a
                // new window.
                l++;
            }
            // Keep expanding the window once we are done contracting.
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string MinWindow(string s, string t) {
        if (s.Length == 0 || t.Length == 0) {
            return "";
        }

        // Dictionary which keeps a count of all the unique characters in t.
        Dictionary<char, int> dictT = new Dictionary<char, int>();
        for (int i = 0; i < t.Length; i++) {
            if (dictT.ContainsKey(t[i])) {
                dictT[t[i]]++;
            } else {
                dictT[t[i]] = 1;
            }
        }

        // Number of unique characters in t, which need to be present in the
        // desired window.
        int required = dictT.Count;
        // Left and Right pointer
        int l = 0, r = 0;
        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one
        // C. Thus formed would be = 3 when all these conditions are met.
        int formed = 0;
        // Dictionary which keeps a count of all the unique characters in the
        // current window.
        Dictionary<char, int> windowCounts = new Dictionary<char, int>();
        // ans list of the form (window length, left, right)
        int[] ans = { -1, 0, 0 };
        while (r < s.Length) {
            // Add one character from the right to the window
            char c = s[r];
            if (windowCounts.ContainsKey(c)) {
                windowCounts[c]++;
            } else {
                windowCounts[c] = 1;
            }

            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (dictT.ContainsKey(c) && windowCounts[c] == dictT[c]) {
                formed++;
            }

            // Try and contract the window till the point where it ceases to be
            // 'desirable'.
            while (l <= r && formed == required) {
                c = s[l];
                // Save the smallest window until now.
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                // The character at the position pointed by the
                // `Left` pointer is no longer a part of the window.
                windowCounts[c]--;
                if (dictT.ContainsKey(c) && windowCounts[c] < dictT[c]) {
                    formed--;
                }

                // Move the left pointer ahead, this would help to look for a
                // new window.
                l++;
            }

            // Keep expanding the window once we are done contracting.
            r++;
        }

        return ans[0] == -1 ? "" : s.Substring(ans[1], ans[2] - ans[1] + 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minWindow(s string, t string) string {
    if len(s) == 0 || len(t) == 0 {
        return ""
    }
    // Dictionary which keeps a count of all the unique characters in t.
    dictT := make(map[rune]int)
    for _, c := range t {
        dictT[c]++
    }
    // Number of unique characters in t, which need to be present in the desired window.
    required := len(dictT)
    // Left and Right pointer
    l, r := 0, 0
    // formed is used to keep track of how many unique characters in t
    // are present in the current window in its desired frequency.
    formed := 0
    // Dictionary which keeps a count of all the unique characters in the current window.
    windowCounts := make(map[rune]int)
    // ans list of the form (window length, left, right)
    ans := []int{-1, 0, 0}
    for r < len(s) {
        // Add one character from the right to the window
        c := rune(s[r])
        windowCounts[c]++
        // If the frequency of the current character added equals the desired count in t then increment the formed count by 1.
        if _, ok := dictT[c]; ok && windowCounts[c] == dictT[c] {
            formed++
        }
        // Try and contract the window until it ceases to be 'desirable'.
        for l <= r && formed == required {
            c = rune(s[l])
            // Save the smallest window until now.
            if ans[0] == -1 || r-l+1 < ans[0] {
                ans[0] = r - l + 1
                ans[1] = l
                ans[2] = r
            }
            // The character at the position pointed by the `left` pointer is no longer a part of the window.
            windowCounts[c]--
            if _, ok := dictT[c]; ok && windowCounts[c] < dictT[c] {
                formed--
            }
            // Move the left pointer ahead to explore a new window.
            l++
        }
        // Keep expanding the window once we are done contracting.
        r++
    }
    if ans[0] == -1 {
        return ""
    }
    return s[ans[1] : ans[2]+1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        // Dictionary which keeps a count of all the unique characters in t.
        Map<Character, Integer> dictT = new HashMap<Character, Integer>();
        for (int i = 0; i < t.length(); i++) {
            int count = dictT.getOrDefault(t.charAt(i), 0);
            dictT.put(t.charAt(i), count + 1);
        }

        // Number of unique characters in t, which need to be present in the desired window.
        int required = dictT.size();

        // Left and Right pointer
        int l = 0, r = 0;

        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one C.
        // Thus formed would be = 3 when all these conditions are met.
        int formed = 0;

        // Dictionary which keeps a count of all the unique characters in the current window.
        Map<Character, Integer> windowCounts = new HashMap<
            Character,
            Integer
        >();

        // ans list of the form (window length, left, right)
        int[] ans = { -1, 0, 0 };

        while (r < s.length()) {
            // Add one character from the right to the window
            char c = s.charAt(r);
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);

            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (
                dictT.containsKey(c) &&
                windowCounts.get(c).intValue() == dictT.get(c).intValue()
            ) {
                formed++;
            }

            // Try and contract the window till the point where it ceases to be 'desirable'.
            while (l <= r && formed == required) {
                c = s.charAt(l);
                // Save the smallest window until now.
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                // The character at the position pointed by the
                // `Left` pointer is no longer a part of the window.
                windowCounts.put(c, windowCounts.get(c) - 1);
                if (
                    dictT.containsKey(c) &&
                    windowCounts.get(c).intValue() < dictT.get(c).intValue()
                ) {
                    formed--;
                }

                // Move the left pointer ahead, this would help to look for a new window.
                l++;
            }

            // Keep expanding the window once we are done contracting.
            r++;
        }

        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minWindow = function (s, t) {
    if (s.length === 0 || t.length === 0) {
        return "";
    }
    // Dictionary which keeps a count of all the unique characters in t.
    let dictT = new Map();
    for (let i = 0; i < t.length; i++) {
        let count = dictT.get(t.charAt(i)) || 0;
        dictT.set(t.charAt(i), count + 1);
    }
    // Number of unique characters in t, which need to be present in the desired window.
    let required = dictT.size;
    // Left and Right pointer
    let l = 0,
        r = 0;
    // formed is used to keep track of how many unique characters in t
    // are present in the current window in its desired frequency.
    // e.g. if t is "AABC" then the window must have two A's, one B and one C.
    // Thus formed would be = 3 when all these conditions are met.
    let formed = 0;
    // Dictionary which keeps a count of all the unique characters in the current window.
    let windowCounts = new Map();
    // ans list of the form (window length, left, right)
    let ans = [-1, 0, 0];
    while (r < s.length) {
        // Add one character from the right to the window
        let c = s.charAt(r);
        let count = windowCounts.get(c) || 0;
        windowCounts.set(c, count + 1);
        // If the frequency of the current character added equals to the
        // desired count in t then increment the formed count by 1.
        if (dictT.has(c) && windowCounts.get(c) === dictT.get(c)) {
            formed++;
        }
        // Try and contract the window till the point where it ceases to be 'desirable'.
        while (l <= r && formed === required) {
            c = s.charAt(l);
            // Save the smallest window until now.
            if (ans[0] === -1 || r - l + 1 < ans[0]) {
                ans[0] = r - l + 1;
                ans[1] = l;
                ans[2] = r;
            }
            // The character at the position pointed by the
            // `Left` pointer is no longer a part of the window.
            windowCounts.set(c, windowCounts.get(c) - 1);
            if (dictT.has(c) && windowCounts.get(c) < dictT.get(c)) {
                formed--;
            }
            // Move the left pointer ahead, this would help to look for a new window.
            l++;
        }
        // Keep expanding the window once we are done contracting.
        r++;
    }
    return ans[0] === -1 ? "" : s.substring(ans[1], ans[2] + 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        # Dictionary which keeps a count of all the unique characters in t.
        dict_t = Counter(t)

        # Number of unique characters in t, which need to be present in the desired window.
        required = len(dict_t)

        # left and right pointer
        l, r = 0, 0

        # formed is used to keep track of how many unique characters in t are present in the current window in its desired frequency.
        # e.g. if t is "AABC" then the window must have two A's, one B and one C. Thus formed would be = 3 when all these conditions are met.
        formed = 0

        # Dictionary which keeps a count of all the unique characters in the current window.
        window_counts = {}

        # ans tuple of the form (window length, left, right)
        ans = float("inf"), None, None

        while r < len(s):

            # Add one character from the right to the window
            character = s[r]
            window_counts[character] = window_counts.get(character, 0) + 1

            # If the frequency of the current character added equals to the desired count in t then increment the formed count by 1.
            if (
                character in dict_t
                and window_counts[character] == dict_t[character]
            ):
                formed += 1

            # Try and contract the window till the point where it ceases to be 'desirable'.
            while l <= r and formed == required:
                character = s[l]

                # Save the smallest window until now.
                if r - l + 1 < ans[0]:
                    ans = (r - l + 1, l, r)

                # The character at the position pointed by the `left` pointer is no longer a part of the window.
                window_counts[character] -= 1
                if (
                    character in dict_t
                    and window_counts[character] < dict_t[character]
                ):
                    formed -= 1

                # Move the left pointer ahead, this would help to look for a new window.
                l += 1

            # Keep expanding the window once we are done contracting.
            r += 1
        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minWindow(s: string, t: string): string {
    if (s.length === 0 || t.length === 0) return "";
    // Dictionary which keeps a count of all the unique characters in t.
    let dictT: Map<string, number> = new Map();
    for (let i = 0; i < t.length; i++) {
        dictT.set(t.charAt(i), (dictT.get(t.charAt(i)) || 0) + 1);
    }
    // Number of unique characters in t, which need to be present in the desired window.
    let required: number = dictT.size;
    // Left and Right pointer
    let l = 0,
        r = 0;
    // formed is used to track how many unique characters in the desired window.
    let formed: number = 0;
    // Dictionary which keeps a count of all the unique characters in the window.
    let windowCounts: Map<string, number> = new Map();
    // ans list of the form (window length, left, right)
    let ans: number[] = [-1, 0, 0];
    while (r < s.length) {
        // Add one character from the right into window.
        let c: string = s.charAt(r);
        windowCounts.set(c, (windowCounts.get(c) || 0) + 1);
        // If the frequency of the current character added equals the count, increase `forms` counter.
        if (dictT.has(c) && windowCounts.get(c) === dictT.get(c)) {
            formed++;
        }
        while (l <= r && formed === required) {
            c = s.charAt(l);
            // Save the smallest window.
            if (ans[0] === -1 || r - l + 1 < ans[0]) {
                ans[0] = r - l + 1;
                ans[1] = l;
                ans[2] = r;
            }
            // Move the left pointer forward to explore a new window.
            windowCounts.set(c, windowCounts.get(c)! - 1);
            if (dictT.has(c) && windowCounts.get(c)! < dictT.get(c)!) {
                formed--;
            }
            l++;
        }
        // Keep expanding the window once we are done contracting.
        r++;
    }
    return ans[0] === -1 ? "" : s.substring(ans[1], ans[2] + 1);
}
```

</details>

<br>

## Approach 2: Optimized Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Element {
    int index;
    char char_val;
};
char* minWindow(char* s, char* t) {
    if (strlen(s) == 0 || strlen(t) == 0) {
        return "";
    }
    struct HashT {
        char id;
        int count;
        UT_hash_handle hh;
    };
    struct HashT *dictT = NULL, *el, *tmp, *windowCounts = NULL;
    for (int i = 0; i < strlen(t); i++) {
        HASH_FIND(hh, dictT, &(t[i]), sizeof(char), tmp);
        if (tmp) {
            tmp->count++;
        } else {
            tmp = (struct HashT*)malloc(sizeof *tmp);
            tmp->id = t[i];
            tmp->count = 1;
            HASH_ADD(hh, dictT, id, sizeof(char), tmp);
        }
    }
    int required = HASH_COUNT(dictT);
    struct Element* filteredS =
        (struct Element*)malloc(strlen(s) * sizeof(struct Element));
    int filteredSCount = 0;
    for (int i = 0; i < strlen(s); i++) {
        HASH_FIND(hh, dictT, &(s[i]), sizeof(char), tmp);
        if (tmp) {
            filteredS[filteredSCount].index = i;
            filteredS[filteredSCount].char_val = s[i];
            filteredSCount++;
        }
    }
    int l = 0, r = 0, formed = 0, ans[3] = {-1, 0, 0};
    while (r < filteredSCount) {
        char c = filteredS[r].char_val;
        HASH_FIND(hh, windowCounts, &c, sizeof(char), tmp);
        if (tmp) {
            tmp->count++;
        } else {
            tmp = (struct HashT*)malloc(sizeof *tmp);
            tmp->id = c;
            tmp->count = 1;
            HASH_ADD(hh, windowCounts, id, sizeof(char), tmp);
        }
        HASH_FIND(hh, dictT, &c, sizeof(char), el);
        if (el && tmp->count == el->count) {
            formed++;
        }
        while (l <= r && formed == required) {
            c = filteredS[l].char_val;
            int end = filteredS[r].index;
            int start = filteredS[l].index;
            if (ans[0] == -1 || end - start + 1 < ans[0]) {
                ans[0] = end - start + 1;
                ans[1] = start;
                ans[2] = end;
            }
            HASH_FIND(hh, windowCounts, &c, sizeof(char), tmp);
            if (tmp) {
                tmp->count--;
            }
            HASH_FIND(hh, dictT, &c, sizeof(char), el);
            if (el && tmp->count < el->count) {
                formed--;
            }
            l++;
        }
        r++;
    }
    return ans[0] == -1 ? "" : strndup(s + ans[1], ans[0]);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        struct element {
            int index;
            char char_val;
        };
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        unordered_map<char, int> dictT;
        for (int i = 0; i < t.length(); i++) {
            dictT[t[i]]++;
        }
        int required = dictT.size();
        vector<element> filteredS;
        for (int i = 0; i < s.length(); i++) {
            if (dictT.find(s[i]) != dictT.end()) filteredS.push_back({i, s[i]});
        }
        int l = 0, r = 0, formed = 0;
        unordered_map<char, int> windowCounts;
        vector<int> ans = {-1, 0, 0};
        while (r < filteredS.size()) {
            char c = filteredS[r].char_val;
            windowCounts[c]++;
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }
            while (l <= r && formed == required) {
                char c = filteredS[l].char_val;
                int end = filteredS[r].index;
                int start = filteredS[l].index;
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }
                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() &&
                    windowCounts[c] < dictT[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string MinWindow(string s, string t) {
        if (s.Length == 0 || t.Length == 0) {
            return "";
        }

        Dictionary<char, int> dictT = new Dictionary<char, int>();
        for (int i = 0; i < t.Length; i++) {
            int count = dictT.ContainsKey(t[i]) ? dictT[t[i]] : 0;
            dictT[t[i]] = count + 1;
        }

        int required = dictT.Count;
        List<KeyValuePair<int, char>> filteredS =
            new List<KeyValuePair<int, char>>();
        for (int i = 0; i < s.Length; i++) {
            char c = s[i];
            if (dictT.ContainsKey(c)) {
                filteredS.Add(new KeyValuePair<int, char>(i, c));
            }
        }

        int l = 0, r = 0, formed = 0;
        Dictionary<char, int> windowCounts = new Dictionary<char, int>();
        int[] ans = { -1, 0, 0 };
        while (r < filteredS.Count) {
            char c = filteredS[r].Value;
            int count = windowCounts.ContainsKey(c) ? windowCounts[c] : 0;
            windowCounts[c] = count + 1;
            if (dictT.ContainsKey(c) && windowCounts[c] == dictT[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = filteredS[l].Value;
                int end = filteredS[r].Key;
                int start = filteredS[l].Key;
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts[c] = windowCounts[c] - 1;
                if (dictT.ContainsKey(c) && windowCounts[c] < dictT[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return ans[0] == -1 ? "" : s.Substring(ans[1], ans[2] - ans[1] + 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minWindow(s string, t string) string {
    if len(s) == 0 || len(t) == 0 {
        return ""
    }
    dictT := make(map[rune]int)
    for _, char := range t {
        dictT[char]++
    }
    required := len(dictT)
    filteredS := []struct {
        index   int
        element rune
    }{}
    for i, char := range s {
        if _, ok := dictT[char]; ok {
            filteredS = append(filteredS, struct {
                index   int
                element rune
            }{index: i, element: char})
        }
    }
    l, r, formed := 0, 0, 0
    windowCounts := make(map[rune]int)
    ans := []int{-1, 0, 0}
    for r < len(filteredS) {
        char := filteredS[r].element
        windowCounts[char]++
        if count, ok := dictT[char]; ok && windowCounts[char] == count {
            formed++
        }
        for l <= r && formed == required {
            char := filteredS[l].element
            end := filteredS[r].index
            start := filteredS[l].index
            if ans[0] == -1 || end-start+1 < ans[0] {
                ans[0] = end - start + 1
                ans[1] = start
                ans[2] = end
            }
            windowCounts[char]--
            if count, ok := dictT[char]; ok && windowCounts[char] < count {
                formed--
            }
            l++
        }
        r++
    }
    if ans[0] == -1 {
        return ""
    } else {
        return s[ans[1] : ans[2]+1]
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        Map<Character, Integer> dictT = new HashMap<Character, Integer>();

        for (int i = 0; i < t.length(); i++) {
            int count = dictT.getOrDefault(t.charAt(i), 0);
            dictT.put(t.charAt(i), count + 1);
        }

        int required = dictT.size();

        // Filter all the characters from s into a new list along with their index.
        // The filtering criteria is that the character should be present in t.
        List<Pair<Integer, Character>> filteredS = new ArrayList<
            Pair<Integer, Character>
        >();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (dictT.containsKey(c)) {
                filteredS.add(new Pair<Integer, Character>(i, c));
            }
        }

        int l = 0, r = 0, formed = 0;
        Map<Character, Integer> windowCounts = new HashMap<
            Character,
            Integer
        >();
        int[] ans = { -1, 0, 0 };

        // Look for the characters only in the filtered list instead of entire s.
        // This helps to reduce our search.
        // Hence, we follow the sliding window approach on as small list.
        while (r < filteredS.size()) {
            char c = filteredS.get(r).getValue();
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);

            if (
                dictT.containsKey(c) &&
                windowCounts.get(c).intValue() == dictT.get(c).intValue()
            ) {
                formed++;
            }

            // Try and contract the window till the point where it ceases to be 'desirable'.
            while (l <= r && formed == required) {
                c = filteredS.get(l).getValue();

                // Save the smallest window until now.
                int end = filteredS.get(r).getKey();
                int start = filteredS.get(l).getKey();
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts.put(c, windowCounts.get(c) - 1);
                if (
                    dictT.containsKey(c) &&
                    windowCounts.get(c).intValue() < dictT.get(c).intValue()
                ) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function minWindow(s, t) {
    if (s.length == 0 || t.length == 0) {
        return "";
    }
    let dictT = {};
    for (let i = 0; i < t.length; i++) {
        let count = dictT.hasOwnProperty(t.charAt(i)) ? dictT[t.charAt(i)] : 0;
        dictT[t.charAt(i)] = count + 1;
    }
    let required = Object.keys(dictT).length;
    let filteredS = [];
    for (let i = 0; i < s.length; i++) {
        let c = s.charAt(i);
        if (dictT.hasOwnProperty(c)) {
            filteredS.push([i, c]);
        }
    }
    let l = 0,
        r = 0,
        formed = 0;
    let windowCounts = {};
    let ans = [-1, 0, 0];
    while (r < filteredS.length) {
        let c = filteredS[r][1];
        let count = windowCounts.hasOwnProperty(c) ? windowCounts[c] : 0;
        windowCounts[c] = count + 1;
        if (dictT.hasOwnProperty(c) && windowCounts[c] == dictT[c]) {
            formed++;
        }
        while (l <= r && formed == required) {
            c = filteredS[l][1];
            let end = filteredS[r][0];
            let start = filteredS[l][0];
            if (ans[0] == -1 || end - start + 1 < ans[0]) {
                ans[0] = end - start + 1;
                ans[1] = start;
                ans[2] = end;
            }
            windowCounts[c] = windowCounts[c] - 1;
            if (dictT.hasOwnProperty(c) && windowCounts[c] < dictT[c]) {
                formed--;
            }
            l++;
        }
        r++;
    }
    return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        dict_t = Counter(t)

        required = len(dict_t)

        # Filter all the characters from s into a new list along with their index.
        # The filtering criteria is that the character should be present in t.
        filtered_s = []
        for i, char in enumerate(s):
            if char in dict_t:
                filtered_s.append((i, char))

        l, r = 0, 0
        formed = 0
        window_counts = {}

        ans = float("inf"), None, None

        # Look for the characters only in the filtered list instead of entire s. This helps to reduce our search.
        # Hence, we follow the sliding window approach on as small list.
        while r < len(filtered_s):
            character = filtered_s[r][1]
            window_counts[character] = window_counts.get(character, 0) + 1

            if window_counts[character] == dict_t[character]:
                formed += 1

            # If the current window has all the characters in desired frequencies i.e. t is present in the window
            while l <= r and formed == required:
                character = filtered_s[l][1]

                # Save the smallest window until now.
                end = filtered_s[r][0]
                start = filtered_s[l][0]
                if end - start + 1 < ans[0]:
                    ans = (end - start + 1, start, end)

                window_counts[character] -= 1
                if window_counts[character] < dict_t[character]:
                    formed -= 1
                l += 1

            r += 1
        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minWindow(s: string, t: string): string {
    if (s.length === 0 || t.length === 0) {
        return "";
    }
    let dictT: Record<string, number> = {};
    for (let i = 0; i < t.length; i++) {
        let count = dictT[t.charAt(i)] || 0;
        dictT[t.charAt(i)] = count + 1;
    }
    let required = Object.keys(dictT).length;
    let filteredS: [number, string][] = [];
    for (let i = 0; i < s.length; i++) {
        let c = s.charAt(i);
        if (dictT.hasOwnProperty(c)) {
            filteredS.push([i, c]);
        }
    }
    let l = 0,
        r = 0,
        formed = 0;
    let windowCounts: Record<string, number> = {};
    let ans: number[] = [-1, 0, 0];
    while (r < filteredS.length) {
        let c = filteredS[r][1];
        let count = windowCounts[c] || 0;
        windowCounts[c] = count + 1;
        if (dictT.hasOwnProperty(c) && windowCounts[c] === dictT[c]) {
            formed++;
        }
        while (l <= r && formed === required) {
            c = filteredS[l][1];
            let end = filteredS[r][0];
            let start = filteredS[l][0];
            if (ans[0] === -1 || end - start + 1 < ans[0]) {
                ans[0] = end - start + 1;
                ans[1] = start;
                ans[2] = end;
            }
            windowCounts[c] = windowCounts[c] - 1;
            if (dictT.hasOwnProperty(c) && windowCounts[c] < dictT[c]) {
                formed--;
            }
            l++;
        }
        r++;
    }
    return ans[0] === -1 ? "" : s.substring(ans[1], ans[2] + 1);
}
```

</details>
