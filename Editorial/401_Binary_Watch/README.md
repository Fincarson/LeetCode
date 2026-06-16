# 401. Binary Watch

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/binary-watch/)  
`Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 401 - Binary Watch](https://leetcode.com/problems/binary-watch/)

## Problem

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

- For example, the below binary watch reads "4:51".

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

- For example, "01:00" is not valid. It should be "1:00".

The minute must consist of two digits and may contain a leading zero.

- For example, "10:2" is not valid. It should be "10:02".

### Example 1

```text
Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
```

### Example 2

```text
Input: turnedOn = 9
Output: []
```

## Constraints

- 0 <= turnedOn <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 401. Binary Watch

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumerating Hours and Minutes | C, C++, C#, Go, Java, JavaScript, Python3 |
| Binary Enumeration | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach 1: Enumerating Hours and Minutes

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** ans = malloc(sizeof(char*) * 12 * 60);
    *returnSize = 0;
    for (int h = 0; h < 12; ++h) {
        for (int m = 0; m < 60; ++m) {
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                char* tmp = malloc(sizeof(char) * 6);
                sprintf(tmp, "%d:%02d", h, m);
                ans[(*returnSize)++] = tmp;
            }
        }
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") +
                                  to_string(m));
                }
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<string> ReadBinaryWatch(int turnedOn) {
        IList<String> ans = new List<String>();
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (BitCount(h) + BitCount(m) == turnedOn) {
                    ans.Add(h + ":" + (m < 10 ? "0" : "") + m);
                }
            }
        }
        return ans;
    }

    private static int BitCount(int i) {
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        i = (i + (i >> 4)) & 0x0f0f0f0f;
        i = i + (i >> 8);
        i = i + (i >> 16);
        return i & 0x3f;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func readBinaryWatch(turnedOn int) (ans []string) {
	for h := uint8(0); h < 12; h++ {
		for m := uint8(0); m < 60; m++ {
			if bits.OnesCount8(h)+bits.OnesCount8(m) == turnedOn {
				ans = append(ans, fmt.Sprintf("%d:%02d", h, m))
			}
		}
	}
	return
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> readBinaryWatch(int turnedOn) {
        List<String> ans = new ArrayList<String>();
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {
                    ans.add(h + ":" + (m < 10 ? "0" : "") + m);
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var readBinaryWatch = function (turnedOn) {
    const ans = [];
    for (let h = 0; h < 12; ++h) {
        for (let m = 0; m < 60; ++m) {
            if (
                h.toString(2).split("0").join("").length +
                    m.toString(2).split("0").join("").length ===
                turnedOn
            ) {
                ans.push(h + ":" + (m < 10 ? "0" : "") + m);
            }
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = list()
        for h in range(12):
            for m in range(60):
                if bin(h).count("1") + bin(m).count("1") == turnedOn:
                    ans.append(f"{h}:{m:02d}")
        return ans
```

</details>

<br>

## Approach 2: Binary Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** ans = malloc(sizeof(char*) * 12 * 60);
    *returnSize = 0;
    for (int i = 0; i < 1024; ++i) {
        int h = i >> 6, m = i & 63;  // Extract the high 4 bits and low 6 bits
                                     // using bitwise operations
        if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
            char* tmp = malloc(sizeof(char) * 6);
            sprintf(tmp, "%d:%02d", h, m);
            ans[(*returnSize)++] = tmp;
        }
    }

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 1024; ++i) {
            int h = i >> 6, m = i & 63;  // Extract the high 4 bits and low 6
                                         // bits using bitwise operations
            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") +
                              to_string(m));
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<string> ReadBinaryWatch(int turnedOn) {
        IList<String> ans = new List<String>();
        for (int i = 0; i < 1024; ++i) {
            int h = i >> 6, m = i & 63;  // Extract the high 4 bits and low 6
                                         // bits using bitwise operations
            if (h < 12 && m < 60 && BitCount(i) == turnedOn) {
                ans.Add(h + ":" + (m < 10 ? "0" : "") + m);
            }
        }
        return ans;
    }

    private static int BitCount(int i) {
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        i = (i + (i >> 4)) & 0x0f0f0f0f;
        i = i + (i >> 8);
        i = i + (i >> 16);
        return i & 0x3f;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func readBinaryWatch(turnedOn int) (ans []string) {
    for i := 0; i < 1024; i++ {
        h, m := i>>6, i&63 // Extract the high 4 bits and low 6 bits using bitwise operations
        if h < 12 && m < 60 && bits.OnesCount(uint(i)) == turnedOn {
            ans = append(ans, fmt.Sprintf("%d:%02d", h, m))
        }
    }
    return
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> readBinaryWatch(int turnedOn) {
        List<String> ans = new ArrayList<String>();
        for (int i = 0; i < 1024; ++i) {
            int h = i >> 6;
            int m = i & 63; // Extract the high 4 bits and low 6 bits using bitwise operations
            if (h < 12 && m < 60 && Integer.bitCount(i) == turnedOn) {
                ans.add(h + ":" + (m < 10 ? "0" : "") + m);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var readBinaryWatch = function (turnedOn) {
    const ans = [];
    for (let i = 0; i < 1024; ++i) {
        let h = i >> 6,
            m = i & 63; // Extract the high 4 bits and low 6 bits using bitwise operations
        if (
            h < 12 &&
            m < 60 &&
            i.toString(2).split("0").join("").length === turnedOn
        ) {
            ans.push(h + ":" + (m < 10 ? "0" : "") + m);
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = list()
        for i in range(1024):
            h, m = (
                i >> 6,
                i & 0x3F,
            )  # Extract the high 4 bits and low 6 bits using bitwise operations
            if h < 12 and m < 60 and bin(i).count("1") == turnedOn:
                ans.append(f"{h}:{m:02d}")
        return ans
```

</details>
