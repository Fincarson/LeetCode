# 165. Compare Version Numbers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/compare-version-numbers/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 165 - Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/)

## Problem

Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

- If version1 < version2, return -1.
- If version1 > version2, return 1.
- Otherwise, return 0.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= version1.length, version2.length <= 500
- version1 and version2 only contain digits and '.'.
- version1 and version2 are valid version numbers.
- All the given revisions in version1 and version2 can be stored in a 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 165. Compare Version Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Split + Parse, Two Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers, One Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Split + Parse, Two Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compareVersion(char* version1, char* version2) {
    while (*version1 || *version2) {
        long num1 = strtol(version1, &version1, 10);
        long num2 = strtol(version2, &version2, 10);

        if (num1 > num2) return 1;
        if (num1 < num2) return -1;

        if (*version1) version1++;
        if (*version2) version2++;
    }

    return 0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> tokens1, tokens2;
        istringstream iss1(version1), iss2(version2);
        string token;

        while (getline(iss1, token, '.')) tokens1.push_back(token);
        while (getline(iss2, token, '.')) tokens2.push_back(token);

        int i1, i2;
        for (int i = 0; i < max(tokens1.size(), tokens2.size()); ++i) {
            i1 = i < tokens1.size() ? stoi(tokens1[i]) : 0;
            i2 = i < tokens2.size() ? stoi(tokens2[i]) : 0;

            if (i1 != i2) return i1 > i2 ? 1 : -1;
        }
        // The versions are equal
        return 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int CompareVersion(string version1, string version2) {
        string[] nums1 = version1.Split('.');
        string[] nums2 = version2.Split('.');
        int n1 = nums1.Length, n2 = nums2.Length;
        int i1, i2;
        for (int i = 0; i < Math.Max(n1, n2); ++i) {
            i1 = i < n1 ? Int32.Parse(nums1[i]) : 0;
            i2 = i < n2 ? Int32.Parse(nums2[i]) : 0;

            if (i1 != i2)
                return i1 > i2 ? 1 : -1;
        }

        // The versions are equal
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func compareVersion(version1 string, version2 string) int {
    tokens1 := strings.Split(version1, ".")
    tokens2 := strings.Split(version2, ".")

    for i := 0; i < max(len(tokens1), len(tokens2)); i++ {
        i1 := 0
        i2 := 0
        if i < len(tokens1) {
            i1, _ = strconv.Atoi(tokens1[i])
        }
        if i < len(tokens2) {
            i2, _ = strconv.Atoi(tokens2[i])
        }

        if i1 != i2 {
            if i1 > i2 {
                return 1
            }
            return -1
        }
    }

    // The versions are equal
    return 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] nums1 = version1.split("\\.");
        String[] nums2 = version2.split("\\.");
        int n1 = nums1.length, n2 = nums2.length;

        // compare versions
        int i1, i2;
        for (int i = 0; i < Math.max(n1, n2); ++i) {
            i1 = i < n1 ? Integer.parseInt(nums1[i]) : 0;
            i2 = i < n2 ? Integer.parseInt(nums2[i]) : 0;
            if (i1 != i2) {
                return i1 > i2 ? 1 : -1;
            }
        }
        //The versions are equal
        return 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var compareVersion = function (version1, version2) {
    let nums1 = version1.split(".");
    let nums2 = version2.split(".");
    let n1 = nums1.length,
        n2 = nums2.length;

    // compare versions
    for (let i = 0; i < Math.max(n1, n2); ++i) {
        let i1 = i < n1 ? parseInt(nums1[i]) : 0;
        let i2 = i < n2 ? parseInt(nums2[i]) : 0;
        if (i1 != i2) {
            return i1 > i2 ? 1 : -1;
        }
    }
    // The versions are equal
    return 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        nums1 = version1.split(".")
        nums2 = version2.split(".")
        n1, n2 = len(nums1), len(nums2)

        # compare versions
        for i in range(max(n1, n2)):
            i1 = int(nums1[i]) if i < n1 else 0
            i2 = int(nums2[i]) if i < n2 else 0
            if i1 != i2:
                return 1 if i1 > i2 else -1

        # The versions are equal
        return 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function compareVersion(version1: string, version2: string): number {
    let nums1 = version1.split(".");
    let nums2 = version2.split(".");
    let n1 = nums1.length,
        n2 = nums2.length;

    // compare versions
    for (let i = 0; i < Math.max(n1, n2); ++i) {
        let i1 = i < n1 ? parseInt(nums1[i]) : 0;
        let i2 = i < n2 ? parseInt(nums2[i]) : 0;
        if (i1 != i2) {
            return i1 > i2 ? 1 : -1;
        }
    }
    // The versions are equal
    return 0;
}
```

</details>

<br>

## Approach 2: Two Pointers, One Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct st {
    int i;
    int p;
} Pair;

Pair getNextChunk(char *version, int n, int p) {
    if (p > n - 1) {
        return (Pair){0, p};
    }
    int pEnd = p;
    while (pEnd < n && version[pEnd] != '.') {
        pEnd++;
    }
    int subLength = pEnd != n - 1 ? pEnd - p : n - p;
    char substr[subLength + 1];
    strncpy(substr, &version[p], subLength);
    substr[subLength] = '\0';

    int i = atoi(substr);
    p = pEnd + 1;

    return (Pair){i, p};
}

int compareVersion(char *version1, char *version2) {
    int p1 = 0, p2 = 0;
    int n1 = strlen(version1), n2 = strlen(version2);

    Pair pair1, pair2;
    while (p1 < n1 || p2 < n2) {
        pair1 = getNextChunk(version1, n1, p1);
        p1 = pair1.p;
        pair2 = getNextChunk(version2, n2, p2);
        p2 = pair2.p;
        if (pair1.i != pair2.i) {
            return pair1.i > pair2.i ? 1 : -1;
        }
    }
    return 0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    pair<int, int> getNextChunk(string& version, int n, int p) {
        if (p > n - 1) {
            return make_pair(0, p);
        }

        int pEnd = p;
        while (pEnd < n && version[pEnd] != '.') {
            ++pEnd;
        }

        int i = stoi(version.substr(p, pEnd != n - 1 ? pEnd - p : n - p));
        p = pEnd + 1;

        return make_pair(i, p);
    }

    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (p1 < n1 || p2 < n2) {
            pair<int, int> pair1 = getNextChunk(version1, n1, p1);
            p1 = pair1.second;
            pair<int, int> pair2 = getNextChunk(version2, n2, p2);
            p2 = pair2.second;
            if (pair1.first != pair2.first) {
                return pair1.first > pair2.first ? 1 : -1;
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private (int, int) getNextChunk(string version, int n, int p) {
        if (p > n - 1) {
            return (0, p);
        }

        int pEnd = p;
        while (pEnd < n && version[pEnd] != '.') {
            ++pEnd;
        }

        int i = Int32.Parse(version.Substring(p,
            pEnd != n - 1 ? pEnd - p : n - p));
        p = pEnd + 1;
        return (i, p);
    }

    public int CompareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int n1 = version1.Length, n2 = version2.Length;

        while (p1 < n1 || p2 < n2) {
            (int i1, int p1_) = getNextChunk(version1, n1, p1);
            p1 = p1_;
            (int i2, int p2_) = getNextChunk(version2, n2, p2);
            p2 = p2_;
            if (i1 != i2) {
                return i1 > i2 ? 1 : -1;
            }
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getNextChunk(version string, n int, p int) (int, int) {
    if p > n-1 {
        return 0, p
    }

    pEnd := p
    for pEnd < n && version[pEnd] != '.' {
        pEnd++
    }
    i, _ := strconv.Atoi(version[p:pEnd])
    p = pEnd + 1
    return i, p
}

func compareVersion(version1 string, version2 string) int {
    p1, p2 := 0, 0
    n1, n2 := len(version1), len(version2)

    for p1 < n1 || p2 < n2 {
        i1, p1_ := getNextChunk(version1, n1, p1)
        p1 = p1_
        i2, p2_ := getNextChunk(version2, n2, p2)
        p2 = p2_
        if i1 != i2 {
            if i1 > i2 {
                return 1
            } else {
                return -1
            }
        }
    }
    return 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Pair<Integer, Integer> getNextChunk(String version, int n, int p) {
        //If the pointer is set to the end of the string, return 0
        if (p > n - 1) {
            return new Pair(0, p);
        }

        // Find the end of chunk
        int i, pEnd = p;
        while (pEnd < n && version.charAt(pEnd) != '.') {
            ++pEnd;
        }

        // Retrieve the chunk
        if (pEnd != n - 1) {
            i = Integer.parseInt(version.substring(p, pEnd));
        } else {
            i = Integer.parseInt(version.substring(p, n));
        }

        // Find the beginning of the next chunk
        p = pEnd + 1;

        return new Pair(i, p);
    }

    public int compareVersion(String version1, String version2) {
        int p1 = 0, p2 = 0;
        int n1 = version1.length(), n2 = version2.length();

        // Compare versions
        int i1, i2;
        Pair<Integer, Integer> pair;
        while (p1 < n1 || p2 < n2) {
            pair = getNextChunk(version1, n1, p1);
            i1 = pair.getKey();
            p1 = pair.getValue();

            pair = getNextChunk(version2, n2, p2);
            i2 = pair.getKey();
            p2 = pair.getValue();
            if (i1 != i2) {
                return i1 > i2 ? 1 : -1;
            }
        }

        // The versions are equal
        return 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var compareVersion = function (version1, version2) {
    var getNextChunk = function (version, n, p) {
        if (p > n - 1) {
            return [0, p];
        }
        let pEnd = p;
        while (pEnd < n && version[pEnd] != ".") {
            pEnd++;
        }
        let i = parseInt(version.substring(p, pEnd != n - 1 ? pEnd : n));
        p = pEnd + 1;
        return [i, p];
    };

    let p1 = 0,
        p2 = 0;
    let n1 = version1.length,
        n2 = version2.length;
    while (p1 < n1 || p2 < n2) {
        let [i1, p1_] = getNextChunk(version1, n1, p1);
        p1 = p1_;
        let [i2, p2_] = getNextChunk(version2, n2, p2);
        p2 = p2_;
        if (i1 != i2) {
            return i1 > i2 ? 1 : -1;
        }
    }
    return 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def get_next_chunk(self, version: str, n: int, p: int) -> List[int]:
        # If pointer is set to the end of the string, return 0
        if p > n - 1:
            return 0, p

        # Find the end of the chunk
        p_end = p
        while p_end < n and version[p_end] != ".":
            p_end += 1

        # Retrieve the chunk
        i = int(version[p:p_end]) if p_end != n - 1 else int(version[p:n])

        # Find the beginning of the next chunk
        p = p_end + 1

        return i, p

    def compareVersion(self, version1: str, version2: str) -> int:
        p1 = p2 = 0
        n1, n2 = len(version1), len(version2)

        # Compare versions
        while p1 < n1 or p2 < n2:
            i1, p1 = self.get_next_chunk(version1, n1, p1)
            i2, p2 = self.get_next_chunk(version2, n2, p2)
            if i1 != i2:
                return 1 if i1 > i2 else -1

        # The versions are equal
        return 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function compareVersion(version1: string, version2: string): number {
    let getNextChunk = function (
        version: string,
        n: number,
        p: number,
    ): [number, number] {
        if (p > n - 1) {
            return [0, p];
        }
        let pEnd = p;
        while (pEnd < n && version[pEnd] != ".") {
            pEnd++;
        }
        let i = parseInt(version.substring(p, pEnd != n - 1 ? pEnd : n));
        p = pEnd + 1;

        return [i, p];
    };

    let p1 = 0;
    let p2 = 0;
    let n1 = version1.length;
    let n2 = version2.length;

    while (p1 < n1 || p2 < n2) {
        let [i1, p1_] = getNextChunk(version1, n1, p1);
        p1 = p1_;
        let [i2, p2_] = getNextChunk(version2, n2, p2);
        p2 = p2_;

        if (i1 != i2) {
            return i1 > i2 ? 1 : -1;
        }
    }

    return 0;
}
```

</details>
