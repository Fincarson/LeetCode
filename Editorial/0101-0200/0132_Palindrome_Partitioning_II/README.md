# 132. Palindrome Partitioning II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/palindrome-partitioning-ii/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 132 - Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/)

## Problem

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

### Example 1

```text
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

### Example 2

```text
Input: s = "a"
Output: 0
```

### Example 3

```text
Input: s = "ab"
Output: 1
```

## Constraints

- 1 <= s.length <= 2000
- s consists of lowercase English letters only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Palindrome Partitioning IV](https://leetcode.com/problems/palindrome-partitioning-iv/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Great Partitions](https://leetcode.com/problems/number-of-great-partitions/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 132. Palindrome Partitioning II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming - Top Down (Recursion, Memoization) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming - Top Down (Optimized Space Complexity) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming - Bottom Up (Tabulation) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Optimized Tabulation Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Expand Around the Center | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Utility function to check if a string is a palindrome
bool isPalindrome(char *str, int low, int high) {
    while (low < high) {
        if (str[low++] != str[high--]) return false;
    }
    return true;
}
// Function is used as a utility function to get the
// minimum number of cuts for the given string
int getMinCuts(char *str, int low, int high, int minCuts) {
    // Base case: no cuts are needed for a string
    // of length 1 or if the string is a palindrome
    if (low == high || isPalindrome(str, low, high)) return 0;
    // Now check all substrings from the start
    // of the string and get the minimum number of cuts
    // needed for each. Pick the minimum and add 1 to the result.
    for (int i = low; i <= high; i++) {
        if (isPalindrome(str, low, i)) {
            minCuts = min(minCuts, 1 + getMinCuts(str, i + 1, high, minCuts));
        }
    }
    return minCuts;
}
int minCut(char *str) {
    return getMinCuts(str, 0, strlen(str) - 1, strlen(str) - 1);
}
int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCut(string s) {
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome
        // substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            // find result for substring (start, currentEnd) if it is palindrome
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
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
    public int MinCut(string s) {
        return findMinimumCut(s, 0, s.Length - 1, s.Length - 1);
    }

    private int findMinimumCut(string s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome
        // substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            // find result for substring (start, currentEndIndex) if it is
            // palindrome
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.Min(
                    minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1, end,
                                                   minimumCut));
            }
        }

        return minimumCut;
    }

    private bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
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
func minCut(s string) int {
    return findMinimumCut(s, 0, len(s)-1, len(s)-1)
}

func findMinimumCut(s string, start int, end int, minimumCut int) int {
    // base condition, no cut needed for an empty substring or palindrome substring.
    if start == end || isPalindrome(s, start, end) {
        return 0
    }
    for currentEndIndex := start; currentEndIndex <= end; currentEndIndex++ {
        // find result for substring (start, currentEndIndex) if it is palindrome
        if isPalindrome(s, start, currentEndIndex) {
            minimumCut = min(
                minimumCut,
                1+findMinimumCut(s, currentEndIndex+1, end, minimumCut),
            )
        }
    }
    return minimumCut
}

func isPalindrome(s string, start int, end int) bool {
    for start < end {
        if s[start] != s[end] {
            return false
        }
        start++
        end--
    }
    return true
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCut(String s) {
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    private int findMinimumCut(String s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        for (
            int currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            // find result for substring (start, currentEndIndex) if it is palindrome
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut)
                );
            }
        }
        return minimumCut;
    }

    private boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start++) != s.charAt(end--)) {
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
var minCut = function (s) {
    return findMinimumCut(s, 0, s.length - 1, s.length - 1);
};
var findMinimumCut = function (s, start, end, minimumCut) {
    // base condition, no cut needed for an empty substring or palindrome substring
    if (start === end || isPalindrome(s, start, end)) {
        return 0;
    }
    for (
        let currentEndIndex = start;
        currentEndIndex <= end;
        currentEndIndex++
    ) {
        // find result for substring (start, currentEndIndex) is it is palindrome
        if (isPalindrome(s, start, currentEndIndex)) {
            minimumCut = Math.min(
                minimumCut,
                1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut),
            );
        }
    }
    return minimumCut;
};
var isPalindrome = function (s, start, end) {
    while (start < end) {
        if (s[start++] !== s[end--]) {
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
    def minCut(self, s: str) -> int:
        return self.findMinimumCut(s, 0, len(s) - 1, len(s) - 1)

    def findMinimumCut(
        self, s: str, start: int, end: int, minimumCut: int
    ) -> int:
        # base condition, no cut needed for an empty substring or palindrome substring.
        if start == end or self.isPalindrome(s, start, end):
            return 0
        for currentEndIndex in range(start, end + 1):
            # find result for substring (start, currentEndIndex) if it is palindrome
            if self.isPalindrome(s, start, currentEndIndex):
                minimumCut = min(
                    minimumCut,
                    1
                    + self.findMinimumCut(
                        s, currentEndIndex + 1, end, minimumCut
                    ),
                )
        return minimumCut

    def isPalindrome(self, s: str, start: int, end: int) -> bool:
        while start < end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCut(s: string): number {
    return findMinimumCut(s, 0, s.length - 1, s.length - 1);
}
function findMinimumCut(
    s: string,
    start: number,
    end: number,
    minimumCut: number,
): number {
    // base condition, no cut needed for an empty substring or palindrome substring
    if (start === end || isPalindrome(s, start, end)) {
        return 0;
    }
    for (
        let currentEndIndex = start;
        currentEndIndex <= end;
        currentEndIndex++
    ) {
        // find result for substring (start, currentEndIndex) is it is palindrome
        if (isPalindrome(s, start, currentEndIndex)) {
            minimumCut = Math.min(
                minimumCut,
                1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut),
            );
        }
    }
    return minimumCut;
}
function isPalindrome(s: string, start: number, end: number): boolean {
    while (start < end) {
        if (s[start++] !== s[end--]) {
            return false;
        }
    }
    return true;
}
```

</details>

<br>

## Approach 2: Dynamic Programming - Top Down (Recursion, Memoization)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Structures for memoization
int** memoCuts;
bool** memoPalindrome;          // Using bool instead of optional
bool** isPalindromeCalculated;  // To handle optional-like behavior

// Function to check if the substring is a palindrome
bool isPalindrome(char* s, int start, int end) {
    if (start >= end) return true;
    if (isPalindromeCalculated[start][end]) {
        return memoPalindrome[start][end];
    }
    bool result = (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
    memoPalindrome[start][end] = result;
    isPalindromeCalculated[start][end] = true;
    return result;
}

// Function to find the minimum cut for palindrome partitioning
int findMinimumCut(char* s, int start, int end, int minimumCut) {
    // base case
    if (start == end || isPalindrome(s, start, end)) {
        return 0;
    }

    // check for results in memoCuts
    if (memoCuts[start][end] != -1) {
        return memoCuts[start][end];
    }

    for (int currentEndIndex = start; currentEndIndex <= end;
         currentEndIndex++) {
        if (isPalindrome(s, start, currentEndIndex)) {
            minimumCut = fmin(
                minimumCut,
                1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut));
        }
    }
    memoCuts[start][end] = minimumCut;
    return minimumCut;
}

// Main function for external call
int minCut(char* s) {
    int len = strlen(s);
    memoCuts = malloc(len * sizeof(int*));
    memoPalindrome = malloc(len * sizeof(bool*));
    isPalindromeCalculated = malloc(len * sizeof(bool*));

    for (int i = 0; i < len; i++) {
        memoCuts[i] = malloc(len * sizeof(int));
        memoPalindrome[i] = malloc(len * sizeof(bool));
        isPalindromeCalculated[i] = malloc(len * sizeof(bool));
        for (int j = 0; j < len; j++) {
            memoCuts[i][j] = -1;  // Initialize memoization for cuts
            memoPalindrome[i][j] =
                false;  // Initialize memoization for palindrome checks
            isPalindromeCalculated[i][j] = false;  // Initialize check state
        }
    }

    int result = findMinimumCut(s, 0, len - 1, len - 1);

    // Free allocated memory
    for (int i = 0; i < len; i++) {
        free(memoCuts[i]);
        free(memoPalindrome[i]);
        free(isPalindromeCalculated[i]);
    }
    free(memoCuts);
    free(memoPalindrome);
    free(isPalindromeCalculated);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memoCuts;
    vector<vector<optional<bool>>> memoPalindrome;

    int minCut(string s) {
        memoCuts.resize(s.length(), vector<int>(s.length(), -1));
        memoPalindrome.resize(s.length(),
                              vector<optional<bool>>(s.length(), nullopt));
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end] != -1) {
            return memoCuts[start][end];
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return memoCuts[start][end] = minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) return true;
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != nullopt)
            return (memoPalindrome[start][end] == true);
        memoPalindrome[start][end] =
            (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
        return (memoPalindrome[start][end] == true);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int?[][] memoCuts;
    private bool?[][] memoPalindrome;

    public int MinCut(string s) {
        memoCuts = new int ?[s.Length][];
        memoPalindrome = new bool ?[s.Length][];
        for (int i = 0; i < s.Length; i++) {
            memoCuts[i] = new int?[s.Length];
            memoPalindrome[i] = new bool?[s.Length];
        }

        return FindMinimumCut(s, 0, s.Length - 1, s.Length - 1).Value;
    }

    private int? FindMinimumCut(string s, int start, int end, int minimumCut) {
        // base case
        if (start == end || IsPalindrome(s, start, end).Value) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end].HasValue) {
            return memoCuts[start][end].Value;
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (IsPalindrome(s, start, currentEndIndex).Value) {
                minimumCut = Math.Min(
                    minimumCut,
                    1 + FindMinimumCut(s, currentEndIndex + 1, end, minimumCut)
                            .Value);
            }
        }

        return memoCuts[start][end] = minimumCut;
    }

    private bool? IsPalindrome(string s, int start, int end) {
        if (start >= end) {
            return true;
        }

        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != null) {
            return memoPalindrome[start][end].Value;
        }

        return memoPalindrome[start][end] =
                   (s[start] == s[end]) &&
                   IsPalindrome(s, start + 1, end - 1).Value;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
var (
    memoCuts       [][]int
    memoPalindrome [][]*bool
)

func minCut(s string) int {
    memoCuts = make([][]int, len(s))
    memoPalindrome = make([][]*bool, len(s))
    for i := range memoCuts {
        memoCuts[i] = make([]int, len(s))
        for j := range memoCuts[i] {
            memoCuts[i][j] = -1
        }
    }
    for i := range memoPalindrome {
        memoPalindrome[i] = make([]*bool, len(s))
    }
    return findMinimumCut(s, 0, len(s)-1, len(s)-1)
}

func findMinimumCut(s string, start, end, minimumCut int) int {
    if start == end || isPalindrome(s, start, end) {
        return 0
    }
    if memoCuts[start][end] != -1 {
        return memoCuts[start][end]
    }
    for currentEndIndex := start; currentEndIndex <= end; currentEndIndex++ {
        if isPalindrome(s, start, currentEndIndex) {
            minCut := findMinimumCut(s, currentEndIndex+1, end, minimumCut)
            if minCut+1 < minimumCut {
                minimumCut = minCut + 1
            }
        }
    }
    memoCuts[start][end] = minimumCut
    return minimumCut
}

func isPalindrome(s string, start, end int) bool {
    if start >= end {
        return true
    }
    if memoPalindrome[start][end] != nil {
        return *memoPalindrome[start][end]
    }
    palindrome := s[start] == s[end] && isPalindrome(s, start+1, end-1)
    memoPalindrome[start][end] = &palindrome
    return palindrome
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Integer memoCuts[][];
    private Boolean memoPalindrome[][];

    public int minCut(String s) {
        memoCuts = new Integer[s.length()][s.length()];
        memoPalindrome = new Boolean[s.length()][s.length()];
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    private int findMinimumCut(String s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        // check for results in memoCuts
        if (memoCuts[start][end] != null) {
            return memoCuts[start][end];
        }
        for (
            int currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut)
                );
            }
        }
        return memoCuts[start][end] = minimumCut;
    }

    private boolean isPalindrome(String s, int start, int end) {
        if (start >= end) {
            return true;
        }
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != null) {
            return memoPalindrome[start][end];
        }
        return (
            memoPalindrome[start][end] = (s.charAt(start) == s.charAt(end)) &&
            isPalindrome(s, start + 1, end - 1)
        );
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCut = function (s) {
    const n = s.length;
    const memoCuts = Array.from({ length: n }, () => Array(n).fill(-1));
    const memoPalindrome = Array.from({ length: n }, () => Array(n).fill(null));

    // Function to check if the substring is a palindrome
    const isPalindrome = (start, end) => {
        if (start >= end) return true;
        if (memoPalindrome[start][end] !== null)
            return memoPalindrome[start][end];
        memoPalindrome[start][end] =
            s[start] === s[end] && isPalindrome(start + 1, end - 1);
        return memoPalindrome[start][end];
    };

    // Function to find the minimum cut for palindrome partitioning
    const findMinimumCut = (start, end, minimumCut) => {
        // base case
        if (start === end || isPalindrome(start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end] !== -1) {
            return memoCuts[start][end];
        }

        for (
            let currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(currentEndIndex + 1, end, minimumCut),
                );
            }
        }
        memoCuts[start][end] = minimumCut;
        return minimumCut;
    };

    return findMinimumCut(0, n - 1, n - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.memoCuts = []
        self.memoPalindrome = []

    def minCut(self, s: str) -> int:
        self.memoCuts = [[None] * len(s) for _ in range(len(s))]
        self.memoPalindrome = [[None] * len(s) for _ in range(len(s))]
        return self.findMinimumCut(s, 0, len(s) - 1, len(s) - 1)

    def findMinimumCut(self, s, start, end, minimumCut):
        # base case
        if start == end or self.isPalindrome(s, start, end):
            return 0
        # check for results in memoCuts
        if self.memoCuts[start][end] != None:
            return self.memoCuts[start][end]
        for currentEndIndex in range(start, end + 1):
            if self.isPalindrome(s, start, currentEndIndex):
                minimumCut = min(
                    minimumCut,
                    1
                    + self.findMinimumCut(
                        s, currentEndIndex + 1, end, minimumCut
                    ),
                )
        self.memoCuts[start][end] = minimumCut
        return self.memoCuts[start][end]

    def isPalindrome(self, s, start, end):
        if start >= end:
            return True
        # check for results in memoPalindrome
        if self.memoPalindrome[start][end] != None:
            return self.memoPalindrome[start][end]
        self.memoPalindrome[start][end] = (
            s[start] == s[end]
        ) and self.isPalindrome(s, start + 1, end - 1)
        return self.memoPalindrome[start][end]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCut(s: string): number {
    const n = s.length;
    const memoCuts: number[][] = Array.from({ length: n }, () =>
        Array(n).fill(-1),
    );
    const memoPalindrome: (boolean | null)[][] = Array.from({ length: n }, () =>
        Array(n).fill(null),
    );

    // Function to check if the substring is a palindrome
    const isPalindrome = (start: number, end: number): boolean => {
        if (start >= end) return true;
        if (memoPalindrome[start][end] !== null)
            return memoPalindrome[start][end];
        memoPalindrome[start][end] =
            s[start] === s[end] && isPalindrome(start + 1, end - 1);
        return memoPalindrome[start][end];
    };

    // Function to find the minimum cut for palindrome partitioning
    const findMinimumCut = (
        start: number,
        end: number,
        minimumCut: number,
    ): number => {
        // base case
        if (start === end || isPalindrome(start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end] !== -1) {
            return memoCuts[start][end];
        }

        for (
            let currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(currentEndIndex + 1, end, minimumCut),
                );
            }
        }
        memoCuts[start][end] = minimumCut;
        return minimumCut;
    };

    return findMinimumCut(0, n - 1, n - 1);
}
```

</details>

<br>

## Approach 3: Dynamic Programming - Top Down (Optimized Space Complexity)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Declare the memoization arrays and their companion arrays to check if a value
// is set
int *memoCuts;
bool **memoPalindrome;
bool **isPalindromeComputed;

// Function to determine if a substring is a palindrome
bool isPalindrome(const char *s, int start, int end) {
    if (start >= end) return true;
    if (isPalindromeComputed[start][end]) {
        return memoPalindrome[start][end];
    }
    bool result = (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
    memoPalindrome[start][end] = result;
    isPalindromeComputed[start][end] = true;
    return result;
}

// Recursive function to find the minimum cuts needed for palindrome
// partitioning
int findMinimumCut(const char *s, int start, int end, int minimumCut) {
    // base case
    if (start == end || isPalindrome(s, start, end)) {
        return 0;
    }

    // check for results in memoCuts
    if (memoCuts[start] != -1) {
        return memoCuts[start];
    }

    for (int currentEndIndex = start; currentEndIndex <= end;
         currentEndIndex++) {
        if (isPalindrome(s, start, currentEndIndex)) {
            int possibleCut =
                1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut);
            if (possibleCut < minimumCut) {
                minimumCut = possibleCut;
            }
        }
    }
    memoCuts[start] = minimumCut;
    return minimumCut;
}

// Main function to compute the minimum cut
int minCut(char *s) {
    int length = strlen(s);
    memoCuts = malloc(length * sizeof(int));
    memset(memoCuts, -1, length * sizeof(int));

    memoPalindrome = malloc(length * sizeof(bool *));
    isPalindromeComputed = malloc(length * sizeof(bool *));
    for (int i = 0; i < length; i++) {
        memoPalindrome[i] = malloc(length * sizeof(bool));
        isPalindromeComputed[i] = malloc(length * sizeof(bool));
        memset(memoPalindrome[i], 0, length * sizeof(bool));
        memset(isPalindromeComputed[i], 0, length * sizeof(bool));
    }

    int result = findMinimumCut(s, 0, length - 1, length - 1);

    // Free memory
    for (int i = 0; i < length; i++) {
        free(memoPalindrome[i]);
        free(isPalindromeComputed[i]);
    }
    free(memoPalindrome);
    free(isPalindromeComputed);
    free(memoCuts);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> memoCuts;
    vector<vector<optional<bool>>> memoPalindrome;

    int minCut(string s) {
        memoCuts.resize(s.length(), -1);
        memoPalindrome.resize(s.length(),
                              vector<optional<bool>>(s.length(), nullopt));
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    int findMinimumCut(string &s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start] != -1) {
            return memoCuts[start];
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut =
                    min(minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1,
                                                       end, minimumCut));
            }
        }
        return memoCuts[start] = minimumCut;
    }

    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) return true;
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != nullopt)
            return (memoPalindrome[start][end] == true);
        memoPalindrome[start][end] =
            (s[start] == s[end]) && isPalindrome(s, start + 1, end - 1);
        return (memoPalindrome[start][end] == true);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int?[] memoCuts;
    private bool?[,] memoPalindrome;

    public int MinCut(string s) {
        memoCuts = new int?[s.Length];
        memoPalindrome = new bool?[s.Length, s.Length];
        return FindMinimumCut(s, 0, s.Length - 1, s.Length - 1) ?? 0;
    }

    private int? FindMinimumCut(string s, int start, int end, int minimumCut) {
        // base case
        if (start == end || (IsPalindrome(s, start, end) ?? false)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start].HasValue) {
            return memoCuts[start].Value;
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (IsPalindrome(s, start, currentEndIndex) ?? false) {
                minimumCut = Math.Min(
                    minimumCut, 1 + (FindMinimumCut(s, currentEndIndex + 1, end,
                                                    minimumCut) ??
                                     0));
            }
        }

        return memoCuts[start] = minimumCut;
    }

    private bool? IsPalindrome(string s, int start, int end) {
        if (start >= end) {
            return true;
        }

        // check for results in memoPalindrome
        if (memoPalindrome[start, end].HasValue) {
            return memoPalindrome[start, end].Value;
        }

        return memoPalindrome[start, end] =
                   (s[start] == s[end]) &&
                   (IsPalindrome(s, start + 1, end - 1) ?? false);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minCut(s string) int {
    memoCuts := make([]int, len(s))
    for i := range memoCuts {
        memoCuts[i] = -1
    }
    memoPalindrome := make([][]bool, len(s))
    for i := range memoPalindrome {
        memoPalindrome[i] = make([]bool, len(s))
    }
    var findMinimumCut func(string, int, int, int) int
    var isPalindrome func(string, int, int) bool
    var min func(int, int) int
    findMinimumCut = func(s string, start int, end int, minimumCut int) int {
        // base case
        if start == end || isPalindrome(s, start, end) {
            return 0
        }
        // check for results in memoCuts
        if memoCuts[start] != -1 {
            return memoCuts[start]
        }
        for currentEndIndex := start; currentEndIndex <= end; currentEndIndex++ {
            if isPalindrome(s, start, currentEndIndex) {
                minimumCut = min(
                    minimumCut,
                    1+findMinimumCut(s, currentEndIndex+1, end, minimumCut),
                )
            }
        }
        memoCuts[start] = minimumCut
        return minimumCut
    }
    isPalindrome = func(s string, start int, end int) bool {
        if start >= end {
            return true
        }
        // check for results in memoPalindrome
        if memoPalindrome[start][end] != false {
            return memoPalindrome[start][end]
        }
        memoPalindrome[start][end] = (s[start] == s[end]) &&
            isPalindrome(s, start+1, end-1)
        return memoPalindrome[start][end]
    }
    min = func(x, y int) int {
        if x < y {
            return x
        }
        return y
    }
    return findMinimumCut(s, 0, len(s)-1, len(s)-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Integer memoCuts[];
    private Boolean memoPalindrome[][];

    public int minCut(String s) {
        memoCuts = new Integer[s.length()];
        memoPalindrome = new Boolean[s.length()][s.length()];
        return findMinimumCut(s, 0, s.length() - 1, s.length() - 1);
    }

    private int findMinimumCut(String s, int start, int end, int minimumCut) {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        // check for results in memoCuts
        if (memoCuts[start] != null) {
            return memoCuts[start];
        }
        for (
            int currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut)
                );
            }
        }
        return memoCuts[start] = minimumCut;
    }

    private boolean isPalindrome(String s, int start, int end) {
        if (start >= end) {
            return true;
        }
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != null) {
            return memoPalindrome[start][end];
        }
        return (
            memoPalindrome[start][end] = (s.charAt(start) == s.charAt(end)) &&
            isPalindrome(s, start + 1, end - 1)
        );
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCut = function (s) {
    let memoCuts = new Array(s.length).fill(null);
    let memoPalindrome = new Array(s.length)
        .fill(null)
        .map((_) => new Array(s.length).fill(null));
    let findMinimumCut = (s, start, end, minimumCut) => {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        // check for results in memoCuts
        if (memoCuts[start] != null) {
            return memoCuts[start];
        }
        for (
            let currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut),
                );
            }
        }
        return (memoCuts[start] = minimumCut);
    };
    let isPalindrome = (s, start, end) => {
        if (start >= end) {
            return true;
        }
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != null) {
            return memoPalindrome[start][end];
        }
        return (memoPalindrome[start][end] =
            s[start] == s[end] && isPalindrome(s, start + 1, end - 1));
    };
    return findMinimumCut(s, 0, s.length - 1, s.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.memo_cuts = []
        self.memo_palindrome = []

    def minCut(self, s: str) -> int:
        self.memo_cuts = [None] * len(s)
        self.memo_palindrome = [[None] * len(s) for _ in range(len(s))]
        return self.find_minimum_cut(s, 0, len(s) - 1, len(s) - 1)

    def find_minimum_cut(
        self, s: str, start: int, end: int, minimum_cut: int
    ) -> int:
        # base case
        if start == end or self.is_palindrome(s, start, end):
            return 0
        # check for results in memo_cuts
        if self.memo_cuts[start] is not None:
            return self.memo_cuts[start]
        for current_end_index in range(start, end + 1):
            if self.is_palindrome(s, start, current_end_index):
                minimum_cut = min(
                    minimum_cut,
                    1
                    + self.find_minimum_cut(
                        s, current_end_index + 1, end, minimum_cut
                    ),
                )
        self.memo_cuts[start] = minimum_cut
        return minimum_cut

    def is_palindrome(self, s: str, start: int, end: int) -> bool:
        if start >= end:
            return True
        # check for results in memo_palindrome
        if self.memo_palindrome[start][end] is not None:
            return self.memo_palindrome[start][end]
        self.memo_palindrome[start][end] = s[start] == s[
            end
        ] and self.is_palindrome(s, start + 1, end - 1)
        return self.memo_palindrome[start][end]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const minCut = (s: string): number => {
    let memoCuts: number[] = new Array(s.length).fill(null);
    let memoPalindrome: boolean[][] = new Array(s.length)
        .fill(null)
        .map((_) => new Array(s.length).fill(null));
    const findMinimumCut = (
        s: string,
        start: number,
        end: number,
        minimumCut: number,
    ): number => {
        // base case
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }
        // check for results in memoCuts
        if (memoCuts[start] != null) {
            return memoCuts[start];
        }
        for (
            let currentEndIndex = start;
            currentEndIndex <= end;
            currentEndIndex++
        ) {
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.min(
                    minimumCut,
                    1 + findMinimumCut(s, currentEndIndex + 1, end, minimumCut),
                );
            }
        }
        return (memoCuts[start] = minimumCut);
    };
    const isPalindrome = (s: string, start: number, end: number): boolean => {
        if (start >= end) {
            return true;
        }
        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != null) {
            return memoPalindrome[start][end];
        }
        return (memoPalindrome[start][end] =
            s[start] == s[end] && isPalindrome(s, start + 1, end - 1));
    };
    return findMinimumCut(s, 0, s.length - 1, s.length - 1);
};
```

</details>

<br>

## Approach 4: Dynamic Programming - Bottom Up (Tabulation)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int *cutsDp;
int **palindromeDp;

// Function to build the palindrome dynamic programming table
void buildPalindromeDp(char *s, int n) {
    for (int end = 0; end < n; end++) {
        for (int start = 0; start <= end; start++) {
            // Check if characters match and the substring between them is a
            // palindrome
            if (s[start] == s[end] &&
                (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                palindromeDp[start][end] = 1;
            } else {
                palindromeDp[start][end] = 0;
            }
        }
    }
}

// Main function to compute the minimum cut
int minCut(char *s) {
    int n = strlen(s);
    cutsDp = (int *)malloc(n * sizeof(int));
    palindromeDp = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        palindromeDp[i] = (int *)malloc(n * sizeof(int));
        memset(palindromeDp[i], 0, n * sizeof(int));  // Initialize to false
    }

    buildPalindromeDp(s, n);

    for (int end = 0; end < n; end++) {
        int minimumCut =
            end;  // Initialize to the worst case: one cut per character
        for (int start = 0; start <= end; start++) {
            if (palindromeDp[start][end]) {
                // No cut needed if the whole substring is a palindrome
                // Otherwise, add 1 to the cuts required for the substring just
                // before the current palindrome
                minimumCut = (start == 0) ? 0
                                          : (minimumCut < cutsDp[start - 1] + 1
                                                 ? minimumCut
                                                 : cutsDp[start - 1] + 1);
            }
        }
        cutsDp[end] = minimumCut;
    }

    int result = cutsDp[n - 1];
    free(cutsDp);
    for (int i = 0; i < n; i++) {
        free(palindromeDp[i]);
    }
    free(palindromeDp);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> cutsDp;
    vector<vector<bool>> palindromeDp;

    int minCut(string s) {
        cutsDp.resize(s.length());
        palindromeDp.resize(s.length(), vector<bool>(s.length(), false));
        // build the palindrome cutsDp for all susbtrings
        buildPalindromeDp(s, s.length());
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (palindromeDp[start][end]) {
                    minimumCut =
                        start == 0 ? 0 : min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }

    void buildPalindromeDp(string &s, int n) {
        for (int end = 0; end < s.length(); end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                    palindromeDp[start][end] = true;
                }
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinCut(string s) {
        int[] cutsDp = new int[s.Length];
        bool[,] palindromeDp = new bool[s.Length, s.Length];
        // build the palindrome cutsDp for all susbtrings
        buildPalindromeDp(s, s.Length, ref palindromeDp);
        for (int end = 0; end < s.Length; end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (palindromeDp[start, end]) {
                    minimumCut = start == 0 ? 0
                                            : Math.Min(minimumCut,
                                                       cutsDp[start - 1] + 1);
                }
            }

            cutsDp[end] = minimumCut;
        }

        return cutsDp[s.Length - 1];
    }

    void buildPalindromeDp(string s, int n, ref bool[,] palindromeDp) {
        for (int end = 0; end < s.Length; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1, end - 1])) {
                    palindromeDp[start, end] = true;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minCut(s string) int {
    cutsDp := make([]int, len(s))
    palindromeDp := make([][]bool, len(s))
    for i := range palindromeDp {
        palindromeDp[i] = make([]bool, len(s))
    }
    // build the palindrome cutsDp for all susbtrings
    buildPalindromeDp(s, len(s), palindromeDp)
    for end := 0; end < len(s); end++ {
        minimumCut := end
        for start := 0; start <= end; start++ {
            if palindromeDp[start][end] {
                if start == 0 {
                    minimumCut = 0
                } else {
                    minimumCut = Min(minimumCut, cutsDp[start-1]+1)
                }
            }
        }
        cutsDp[end] = minimumCut
    }
    return cutsDp[len(s)-1]
}

func buildPalindromeDp(s string, n int, palindromeDp [][]bool) {
    for end := 0; end < len(s); end++ {
        for start := 0; start <= end; start++ {
            if s[start] == s[end] &&
                (end-start <= 2 || palindromeDp[start+1][end-1]) {
                palindromeDp[start][end] = true
            }
        }
    }
}

func Min(x, y int) int {
    if x <= y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Integer cutsDp[];
    private boolean palindromeDp[][];

    public int minCut(String s) {
        cutsDp = new Integer[s.length()];
        palindromeDp = new boolean[s.length()][s.length()];
        // build the palindrome cutsDp for all susbtrings
        buildPalindromeDp(s, s.length());

        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (palindromeDp[start][end]) {
                    minimumCut = start == 0
                        ? 0
                        : Math.min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }

    private void buildPalindromeDp(String s, int n) {
        for (int end = 0; end < s.length(); end++) {
            for (int start = 0; start <= end; start++) {
                if (
                    s.charAt(start) == s.charAt(end) &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])
                ) {
                    palindromeDp[start][end] = true;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCut = function (s) {
    let cutsDp = new Array(s.length).fill(0);
    let palindromeDp = Array.from(Array(s.length), () =>
        new Array(s.length).fill(false),
    );
    // build the palindrome cutsDp for all susbtrings
    buildPalindromeDp(s, s.length);
    for (let end = 0; end < s.length; end++) {
        let minimumCut = end;
        for (let start = 0; start <= end; start++) {
            if (palindromeDp[start][end]) {
                minimumCut =
                    start === 0
                        ? 0
                        : Math.min(minimumCut, cutsDp[start - 1] + 1);
            }
        }
        cutsDp[end] = minimumCut;
    }
    return cutsDp[s.length - 1];
    function buildPalindromeDp(s, n) {
        for (let end = 0; end < s.length; end++) {
            for (let start = 0; start <= end; start++) {
                if (
                    s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])
                ) {
                    palindromeDp[start][end] = true;
                }
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCut(self, s: str) -> int:
        cutsDP = [0] * len(s)
        palindromeDP = [[False] * len(s) for _ in range(len(s))]
        # build the palindrome cutsDP for all substrings
        self.buildPalindromeDP(s, len(s), palindromeDP)
        for end in range(len(s)):
            minimumCut = end
            for start in range(end + 1):
                if palindromeDP[start][end]:
                    minimumCut = (
                        0
                        if start == 0
                        else min(minimumCut, cutsDP[start - 1] + 1)
                    )
            cutsDP[end] = minimumCut
        return cutsDP[len(s) - 1]

    def buildPalindromeDP(self, s, n, palindromeDP):
        for end in range(len(s)):
            for start in range(end + 1):
                if s[start] == s[end] and (
                    end - start <= 2 or palindromeDP[start + 1][end - 1]
                ):
                    palindromeDP[start][end] = True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCut(s: string): number {
    let cutsDp: Array<number> = new Array<number>(s.length);
    let palindromeDp: Array<Array<boolean>> = Array.from(
        Array(s.length),
        () => new Array<boolean>(s.length),
    );
    // build the palindrome cutsDp for all susbtrings
    buildPalindromeDp(s, s.length, palindromeDp);
    for (let end = 0; end < s.length; end++) {
        let minimumCut: number = end;
        for (let start = 0; start <= end; start++) {
            if (palindromeDp[start][end]) {
                minimumCut =
                    start === 0
                        ? 0
                        : Math.min(minimumCut, cutsDp[start - 1] + 1);
            }
        }
        cutsDp[end] = minimumCut;
    }
    return cutsDp[s.length - 1];
    function buildPalindromeDp(
        s: string,
        n: number,
        palindromeDp: Array<Array<boolean>>,
    ) {
        for (let end = 0; end < s.length; end++) {
            for (let start = 0; start <= end; start++) {
                if (
                    s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])
                ) {
                    palindromeDp[start][end] = true;
                }
            }
        }
    }
}
```

</details>

<br>

## Approach 5: Optimized Tabulation Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minCut(char *s) {
    int n = strlen(s);
    int *cutsDp = (int *)malloc(n * sizeof(int));
    int **palindromeDp = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        palindromeDp[i] = (int *)malloc(n * sizeof(int));
        memset(palindromeDp[i], 0, n * sizeof(int));  // Initialize to false
    }

    for (int end = 0; end < n; end++) {
        int minimumCut = end;  // Initialize the minimumCut to the worst case:
                               // one cut per character
        for (int start = 0; start <= end; start++) {
            // Check if substring (start, end) is a palindrome
            if (s[start] == s[end] &&
                (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                palindromeDp[start][end] =
                    1;  // Mark this substring as a palindrome
                // Calculate minimum cuts
                minimumCut = start == 0 ? 0
                                        : (minimumCut < cutsDp[start - 1] + 1
                                               ? minimumCut
                                               : cutsDp[start - 1] + 1);
            }
        }
        cutsDp[end] = minimumCut;
    }

    int result = cutsDp[n - 1];
    free(cutsDp);
    for (int i = 0; i < n; i++) {
        free(palindromeDp[i]);
    }
    free(palindromeDp);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCut(string s) {
        vector<int> cutsDp;
        vector<vector<bool>> palindromeDp;
        cutsDp.resize(s.length());
        palindromeDp.resize(s.length(), vector<bool>(s.length(), false));
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                // check if substring (start, end) is palidrome
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                    palindromeDp[start][end] = true;
                    minimumCut =
                        start == 0 ? 0 : min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinCut(string s) {
        int[] cuts = new int[s.Length];
        bool[][] palindrome = new bool [s.Length][];
        for (int i = 0; i < s.Length; i++) palindrome[i] = new bool[s.Length];
        for (int end = 0; end < s.Length; end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                // check if substring (start, end) is palindrome
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindrome[start + 1][end - 1])) {
                    palindrome[start][end] = true;
                    minimumCut =
                        start == 0 ? 0
                                   : Math.Min(minimumCut, cuts[start - 1] + 1);
                }
            }

            cuts[end] = minimumCut;
        }

        return cuts[s.Length - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minCut(s string) int {
    length := len(s)
    cuts := make([]int, length)
    palindrome := make([][]bool, length)
    for i := 0; i < length; i++ {
        palindrome[i] = make([]bool, length)
    }
    for end := 0; end < length; end++ {
        minimumCut := end
        for start := 0; start <= end; start++ {
            // check if substring (start, end) is palindrome
            if s[start] == s[end] &&
                (end-start <= 2 || palindrome[start+1][end-1]) {
                palindrome[start][end] = true
                if start == 0 {
                    minimumCut = 0
                } else {
                    minimumCut = min(minimumCut, cuts[start-1]+1)
                }
            }
        }
        cuts[end] = minimumCut
    }
    return cuts[length-1]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCut(String s) {
        Integer cutsDp[];
        boolean palindromeDp[][];
        cutsDp = new Integer[s.length()];
        palindromeDp = new boolean[s.length()][s.length()];
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                // check if substring (start, end) is palidrome
                if (
                    s.charAt(start) == s.charAt(end) &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])
                ) {
                    palindromeDp[start][end] = true;
                    minimumCut = start == 0
                        ? 0
                        : Math.min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCut = function (s) {
    let cuts = new Array(s.length),
        palindrome = new Array(s.length)
            .fill()
            .map(() => new Array(s.length).fill(false));
    for (let end = 0; end < s.length; end++) {
        let minimumCut = end;
        for (let start = 0; start <= end; start++) {
            // check if substring (start, end) is palindrome
            if (
                s.charAt(start) == s.charAt(end) &&
                (end - start <= 2 || palindrome[start + 1][end - 1])
            ) {
                palindrome[start][end] = true;
                minimumCut =
                    start == 0 ? 0 : Math.min(minimumCut, cuts[start - 1] + 1);
            }
        }
        cuts[end] = minimumCut;
    }
    return cuts[s.length - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCut(self, s: str) -> int:
        cuts, palindrome = [0] * len(s), [[0] * len(s) for _ in range(len(s))]
        for end in range(len(s)):
            minimumCut = end
            for start in range(end + 1):
                # check if substring (start, end) is palidrome
                if s[start] == s[end] and (
                    end - start <= 2 or palindrome[start + 1][end - 1]
                ):
                    palindrome[start][end] = 1
                    minimumCut = (
                        0
                        if start == 0
                        else min(minimumCut, cuts[start - 1] + 1)
                    )
            cuts[end] = minimumCut
        return cuts[-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCut(s: string): number {
    let cuts = new Array(s.length),
        palindrome = new Array(s.length)
            .fill(false)
            .map(() => new Array(s.length).fill(false));
    for (let end = 0; end < s.length; end++) {
        let minimumCut = end;
        for (let start = 0; start <= end; start++) {
            // check if substring (start, end) is palindrome
            if (
                s.charAt(start) == s.charAt(end) &&
                (end - start <= 2 || palindrome[start + 1][end - 1])
            ) {
                palindrome[start][end] = true;
                minimumCut =
                    start == 0 ? 0 : Math.min(minimumCut, cuts[start - 1] + 1);
            }
        }
        cuts[end] = minimumCut;
    }
    return cuts[s.length - 1];
}
```

</details>

<br>

## Approach 6: Expand Around the Center

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minCut(char* s) {
    int n = strlen(s);
    int* cutsDp = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cutsDp[i] = i;
    }
    for (int mid = 0; mid < n; mid++) {
        findMinimumCuts(mid, mid, cutsDp, s, n);
        findMinimumCuts(mid - 1, mid, cutsDp, s, n);
    }
    int result = cutsDp[n - 1];
    free(cutsDp);
    return result;
}
void findMinimumCuts(int startIndex, int endIndex, int* cutsDp, char* s,
                     int n) {
    for (int start = startIndex, end = endIndex;
         start >= 0 && end < n && s[start] == s[end]; start--, end++) {
        int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
        cutsDp[end] = cutsDp[end] < newCut ? cutsDp[end] : newCut;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCut(string s) {
        vector<int> cutsDp;
        cutsDp.resize(s.length());
        for (int i = 1; i < s.length(); i++) {
            cutsDp[i] = i;
        }
        for (int mid = 0; mid < s.length(); mid++) {
            // check for odd length palindrome around mid index
            findMinimumCuts(mid, mid, cutsDp, s);
            // check for even length palindrome around mid index
            findMinimumCuts(mid - 1, mid, cutsDp, s);
        }
        return cutsDp[s.length() - 1];
    }

    void findMinimumCuts(int startIndex, int endIndex, vector<int> &cutsDp,
                         string s) {
        for (int start = startIndex, end = endIndex;
             start >= 0 && end < s.length() && s[start] == s[end];
             start--, end++) {
            int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
            cutsDp[end] = min(cutsDp[end], newCut);
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinCut(string s) {
        int[] cutsDp = new int[s.Length];
        for (int i = 1; i < s.Length; i++) {
            cutsDp[i] = i;
        }

        for (int mid = 0; mid < s.Length; mid++) {
            // check for odd length palindrome around mid index
            FindMinimumCuts(mid, mid, cutsDp, s);
            // check for even length palindrome around mid index
            FindMinimumCuts(mid - 1, mid, cutsDp, s);
        }

        return cutsDp[s.Length - 1];
    }

    public void FindMinimumCuts(int startIndex, int endIndex, int[] cutsDp,
                                string s) {
        for (int start = startIndex, end = endIndex;
             start >= 0 && end < s.Length && s[start] == s[end];
             start--, end++) {
            int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
            cutsDp[end] = Math.Min(cutsDp[end], newCut);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minCut(s string) int {
    cutsDp := make([]int, len(s))
    for i := 1; i < len(s); i++ {
        cutsDp[i] = i
    }
    for mid := 0; mid < len(s); mid++ {
        findMinimumCuts(mid, mid, cutsDp, s)
        findMinimumCuts(mid-1, mid, cutsDp, s)
    }
    return cutsDp[len(s)-1]
}

func findMinimumCuts(startIndex, endIndex int, cutsDp []int, s string) {
    for start, end := startIndex, endIndex; start >= 0 && end < len(s) && s[start] == s[end]; start, end = start-1, end+1 {
        var newCut int
        if start == 0 {
            newCut = 0
        } else {
            newCut = cutsDp[start-1] + 1
        }
        if cutsDp[end] > newCut {
            cutsDp[end] = newCut
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCut(String s) {
        int cutsDp[];
        cutsDp = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            cutsDp[i] = i;
        }
        for (int mid = 0; mid < s.length(); mid++) {
            // check for odd length palindrome around mid index
            findMinimumCuts(mid, mid, cutsDp, s);
            // check for even length palindrome around mid index
            findMinimumCuts(mid - 1, mid, cutsDp, s);
        }
        return cutsDp[s.length() - 1];
    }

    public void findMinimumCuts(
        int startIndex,
        int endIndex,
        int[] cutsDp,
        String s
    ) {
        for (
            int start = startIndex, end = endIndex;
            start >= 0 && end < s.length() && s.charAt(start) == s.charAt(end);
            start--, end++
        ) {
            int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
            cutsDp[end] = Math.min(cutsDp[end], newCut);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minCut = function (s) {
    let cutsDp = new Array(s.length).fill(0);
    for (let i = 1; i < s.length; i++) {
        cutsDp[i] = i;
    }
    for (let mid = 0; mid < s.length; mid++) {
        findMinimumCuts(mid, mid, cutsDp, s);
        findMinimumCuts(mid - 1, mid, cutsDp, s);
    }
    return cutsDp[s.length - 1];
};
function findMinimumCuts(startIndex, endIndex, cutsDp, s) {
    for (
        let start = startIndex, end = endIndex;
        start >= 0 && end < s.length && s.charAt(start) == s.charAt(end);
        start--, end++
    ) {
        let newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
        cutsDp[end] = Math.min(cutsDp[end], newCut);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCut(self, s):
        cutsDp = [0] * len(s)
        for i in range(1, len(s)):
            cutsDp[i] = i
        for mid in range(len(s)):
            # check for odd length palindrome around mid index
            self.findMinimumCuts(mid, mid, cutsDp, s)
            # check for even length palindrome around mid index
            self.findMinimumCuts(mid - 1, mid, cutsDp, s)
        return cutsDp[len(s) - 1]

    def findMinimumCuts(self, startIndex, endIndex, cutsDp, s):
        start = startIndex
        end = endIndex
        while start >= 0 and end < len(s) and s[start] == s[end]:
            newCut = 0 if start == 0 else cutsDp[start - 1] + 1
            cutsDp[end] = min(cutsDp[end], newCut)
            start -= 1
            end += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCut(s: string): number {
    let cutsDp: number[] = new Array(s.length).fill(0);
    for (let i = 1; i < s.length; i++) {
        cutsDp[i] = i;
    }
    for (let mid = 0; mid < s.length; mid++) {
        findMinimumCuts(mid, mid, cutsDp, s);
        findMinimumCuts(mid - 1, mid, cutsDp, s);
    }
    return cutsDp[s.length - 1];
}
function findMinimumCuts(
    startIndex: number,
    endIndex: number,
    cutsDp: number[],
    s: string,
): void {
    for (
        let start = startIndex, end = endIndex;
        start >= 0 && end < s.length && s.charAt(start) == s.charAt(end);
        start--, end++
    ) {
        let newCut: number = start == 0 ? 0 : cutsDp[start - 1] + 1;
        cutsDp[end] = Math.min(cutsDp[end], newCut);
    }
}
```

</details>
