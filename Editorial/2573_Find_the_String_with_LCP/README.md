# 2573. Find the String with LCP

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/find-the-string-with-lcp/)  
`Array` `String` `Dynamic Programming` `Greedy` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 2573 - Find the String with LCP](https://leetcode.com/problems/find-the-string-with-lcp/)

## Problem

We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:

- lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].

Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.

### Example 1

```text
Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
Output: "abab"
Explanation: lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
```

### Example 2

```text
Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
Output: "aaaa"
Explanation: lcp corresponds to any 4 letter string with a single distinct letter. The lexicographically smallest of them is "aaaa".
```

### Example 3

```text
Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
Output: ""
Explanation: lcp[3][3] cannot be equal to 3 since word[3,...,3] consists of only a single letter; Thus, no answer exists.
```

## Constraints

- 1 <= n == lcp.length == lcp[i].length <= 1000
- 0 <= lcp[i][j] <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2573. Find the String with LCP

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy Construction | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy Construction

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* findTheString(int** lcp, int lcpSize, int* lcpColSize) {
    int n = lcpSize;
    char* word = (char*)malloc((n + 1) * sizeof(char));
    memset(word, 0, sizeof(char) * (n + 1));
    char current = 'a';

    // construct the string starting from 'a' to 'z' sequentially
    for (int i = 0; i < n; i++) {
        if (word[i] == '\0') {
            if (current > 'z') {
                word[0] = '\0';
                return word;
            }
            word[i] = current;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = word[i];
                }
            }
            current++;
        }
    }

    // verify if the constructed string meets the LCP matrix requirements
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (word[i] != word[j]) {
                if (lcp[i][j] != 0) {
                    word[0] = '\0';
                    return word;
                }
            } else {
                if (i == n - 1 || j == n - 1) {
                    if (lcp[i][j] != 1) {
                        word[0] = '\0';
                        return word;
                    }
                } else {
                    if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                        word[0] = '\0';
                        return word;
                    }
                }
            }
        }
    }

    return word;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char current = 'a';

        // construct the string starting from 'a' to 'z' sequentially
        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (current > 'z') {
                    return "";
                }
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        // verify if the constructed string meets the LCP matrix requirements
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j]) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }

        return word;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string FindTheString(int[][] lcp) {
        int n = lcp.Length;
        char[] word = new char[n];
        char current = 'a';

        // construct the string starting from 'a' to 'z' sequentially
        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (current > 'z') {
                    return "";
                }
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        // verify if the constructed string meets the LCP matrix requirements
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j] != 0) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }

        return new string(word);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findTheString(lcp [][]int) string {
	n := len(lcp)
	word := make([]byte, n)
	current := byte('a')

	// construct the string starting from 'a' to 'z' sequentially
	for i := 0; i < n; i++ {
		if word[i] == 0 {
			if current > 'z' {
				return ""
			}
			word[i] = current
			for j := i + 1; j < n; j++ {
				if lcp[i][j] > 0 {
					word[j] = word[i]
				}
			}
			current++
		}
	}

	// verify if the constructed string meets the LCP matrix requirements
	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if word[i] != word[j] {
				if lcp[i][j] != 0 {
					return ""
				}
			} else {
				if i == n-1 || j == n-1 {
					if lcp[i][j] != 1 {
						return ""
					}
				} else {
					if lcp[i][j] != lcp[i+1][j+1]+1 {
						return ""
					}
				}
			}
		}
	}

	return string(word)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String findTheString(int[][] lcp) {
        int n = lcp.length;
        char[] word = new char[n];
        char current = 'a';

        // construct the string starting from 'a' to 'z' sequentially
        for (int i = 0; i < n; i++) {
            if (word[i] == 0) {
                if (current > 'z') {
                    return "";
                }
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        // verify if the constructed string meets the LCP matrix requirements
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j] != 0) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }

        return new String(word);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findTheString = function (lcp) {
    const n = lcp.length;
    const word = new Array(n).fill("");
    let current = "a".charCodeAt(0);

    // construct the string starting from 'a' to 'z' sequentially
    for (let i = 0; i < n; i++) {
        if (!word[i]) {
            if (current > "z".charCodeAt(0)) {
                return "";
            }
            word[i] = String.fromCharCode(current);
            for (let j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = word[i];
                }
            }
            current++;
        }
    }

    // verify if the constructed string meets the LCP matrix requirements
    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (word[i] !== word[j]) {
                if (lcp[i][j] !== 0) {
                    return "";
                }
            } else {
                if (i === n - 1 || j === n - 1) {
                    if (lcp[i][j] !== 1) {
                        return "";
                    }
                } else {
                    if (lcp[i][j] !== lcp[i + 1][j + 1] + 1) {
                        return "";
                    }
                }
            }
        }
    }

    return word.join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        word = [""] * n
        current = ord("a")

        # construct the string starting from 'a' to 'z' sequentially
        for i in range(n):
            if not word[i]:
                if current > ord("z"):
                    return ""
                word[i] = chr(current)
                for j in range(i + 1, n):
                    if lcp[i][j]:
                        word[j] = word[i]
                current += 1

        # verify if the constructed string meets the LCP matrix requirements
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if word[i] != word[j]:
                    if lcp[i][j]:
                        return ""
                else:
                    if i == n - 1 or j == n - 1:
                        if lcp[i][j] != 1:
                            return ""
                    else:
                        if lcp[i][j] != lcp[i + 1][j + 1] + 1:
                            return ""

        return "".join(word)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findTheString(lcp: number[][]): string {
    const n = lcp.length;
    const word: string[] = new Array(n).fill("");
    let current = "a".charCodeAt(0);

    // construct the string starting from 'a' to 'z' sequentially
    for (let i = 0; i < n; i++) {
        if (!word[i]) {
            if (current > "z".charCodeAt(0)) {
                return "";
            }
            word[i] = String.fromCharCode(current);
            for (let j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = word[i];
                }
            }
            current++;
        }
    }

    // verify if the constructed string meets the LCP matrix requirements
    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (word[i] !== word[j]) {
                if (lcp[i][j] !== 0) {
                    return "";
                }
            } else {
                if (i === n - 1 || j === n - 1) {
                    if (lcp[i][j] !== 1) {
                        return "";
                    }
                } else {
                    if (lcp[i][j] !== lcp[i + 1][j + 1] + 1) {
                        return "";
                    }
                }
            }
        }
    }

    return word.join("");
}
```

</details>
