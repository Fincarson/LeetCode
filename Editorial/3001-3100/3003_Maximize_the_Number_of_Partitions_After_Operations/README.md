# 3003. Maximize the Number of Partitions After Operations

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/)  
`String` `Dynamic Programming` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 3003 - Maximize the Number of Partitions After Operations](https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/)

## Problem

You are given a string s and an integer k.

First, you are allowed to change at most one index in s to another lowercase English letter.

After that, do the following partitioning operation until s is empty:

- Choose the longest prefix of s containing at most k distinct characters.
- Delete the prefix from s and increase the number of partitions by one. The remaining characters (if any) in s maintain their initial order.

Return an integer denoting the maximum number of resulting partitions after the operations by optimally choosing at most one index to change.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 104
- s consists only of lowercase English letters.
- 1 <= k <= 26

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Can Make Palindrome from Substring](https://leetcode.com/problems/can-make-palindrome-from-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3003. Maximize the Number of Partitions After Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Bitwise Operations + Preprocessing + Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Bitwise Operations + Preprocessing + Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxPartitionsAfterOperations(char* s, int k) {
    int n = strlen(s);
    int** left = (int**)malloc(n * sizeof(int*));
    int** right = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        left[i] = (int*)malloc(3 * sizeof(int));
        right[i] = (int*)malloc(3 * sizeof(int));
        memset(left[i], 0, sizeof(int) * 3);
        memset(right[i], 0, sizeof(int) * 3);
    }

    int num = 0, mask = 0, count = 0;
    for (int i = 0; i < n - 1; i++) {
        int binary = 1 << (s[i] - 'a');
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        left[i + 1][0] = num;
        left[i + 1][1] = mask;
        left[i + 1][2] = count;
    }

    num = 0;
    mask = 0;
    count = 0;
    for (int i = n - 1; i > 0; i--) {
        int binary = 1 << (s[i] - 'a');
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        right[i - 1][0] = num;
        right[i - 1][1] = mask;
        right[i - 1][2] = count;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        int seg = left[i][0] + right[i][0] + 2;
        int totMask = left[i][1] | right[i][1];
        int totCount = 0;
        while (totMask) {
            totMask = totMask & (totMask - 1);
            totCount++;
        }
        if (left[i][2] == k && right[i][2] == k && totCount < 26) {
            seg++;
        } else {
            int minVal = fmin(totCount + 1, 26);
            if (minVal <= k) {
                seg--;
            }
        }
        max = fmax(max, seg);
    }

    for (int i = 0; i < n; i++) {
        free(left[i]);
        free(right[i]);
    }
    free(left);
    free(right);

    return max;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.length();
        vector<vector<int>> left(n, vector<int>(3)), right(n, vector<int>(3));
        int num = 0, mask = 0, count = 0;
        for (int i = 0; i < n - 1; i++) {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary)) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        num = 0, mask = 0, count = 0;
        for (int i = n - 1; i > 0; i--) {
            int binary = 1 << (s[i] - 'a');
            if (!(mask & binary)) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        int Max = 0;
        for (int i = 0; i < n; i++) {
            int seg = left[i][0] + right[i][0] + 2;
            int totMask = left[i][1] | right[i][1];
            int totCount = 0;
            while (totMask) {
                totMask = totMask & (totMask - 1);
                totCount++;
            }
            if (left[i][2] == k && right[i][2] == k && totCount < 26) {
                seg++;
            } else if (min(totCount + 1, 26) <= k) {
                seg--;
            }
            Max = max(Max, seg);
        }
        return Max;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxPartitionsAfterOperations(string s, int k) {
        int n = s.Length;
        int[][] left = new int [n][];
        int[][] right = new int [n][];

        for (int i = 0; i < n; i++) {
            left[i] = new int[3];
            right[i] = new int[3];
        }

        int num = 0, mask = 0, count = 0;
        for (int i = 0; i < n - 1; i++) {
            int binary = 1 << (s[i] - 'a');
            if ((mask & binary) == 0) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        num = 0;
        mask = 0;
        count = 0;
        for (int i = n - 1; i > 0; i--) {
            int binary = 1 << (s[i] - 'a');
            if ((mask & binary) == 0) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        int max = 0;
        for (int i = 0; i < n; i++) {
            int seg = left[i][0] + right[i][0] + 2;
            int totMask = left[i][1] | right[i][1];
            int totCount = 0;
            while (totMask != 0) {
                totMask = totMask & (totMask - 1);
                totCount++;
            }
            if (left[i][2] == k && right[i][2] == k && totCount < 26) {
                seg++;
            } else if (Math.Min(totCount + 1, 26) <= k) {
                seg--;
            }
            max = Math.Max(max, seg);
        }
        return max;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxPartitionsAfterOperations(s string, k int) int {
	n := len(s)
	left := make([][3]int, n)
	right := make([][3]int, n)

	num, mask, count := 0, 0, 0
	for i := 0; i < n-1; i++ {
		binary := 1 << (s[i] - 'a')
		if mask&binary == 0 {
			count++
			if count <= k {
				mask |= binary
			} else {
				num++
				mask = binary
				count = 1
			}
		}
		left[i+1][0] = num
		left[i+1][1] = mask
		left[i+1][2] = count
	}

	num, mask, count = 0, 0, 0
	for i := n - 1; i > 0; i-- {
		binary := 1 << (s[i] - 'a')
		if mask&binary == 0 {
			count++
			if count <= k {
				mask |= binary
			} else {
				num++
				mask = binary
				count = 1
			}
		}
		right[i-1][0] = num
		right[i-1][1] = mask
		right[i-1][2] = count
	}

	maxVal := 0
	for i := 0; i < n; i++ {
		seg := left[i][0] + right[i][0] + 2
		totMask := left[i][1] | right[i][1]
		totCount := 0
		for totMask != 0 {
			totMask = totMask & (totMask - 1)
			totCount++
		}
		if left[i][2] == k && right[i][2] == k && totCount < 26 {
			seg++
		} else if min(totCount+1, 26) <= k {
			seg--
		}
		if seg > maxVal {
			maxVal = seg
		}
	}
	return maxVal
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxPartitionsAfterOperations(String s, int k) {
        int n = s.length();
        int[][] left = new int[n][3];
        int[][] right = new int[n][3];

        int num = 0;
        int mask = 0;
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int binary = 1 << (s.charAt(i) - 'a');
            if ((mask & binary) == 0) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            left[i + 1][0] = num;
            left[i + 1][1] = mask;
            left[i + 1][2] = count;
        }

        num = 0;
        mask = 0;
        count = 0;
        for (int i = n - 1; i > 0; i--) {
            int binary = 1 << (s.charAt(i) - 'a');
            if ((mask & binary) == 0) {
                count++;
                if (count <= k) {
                    mask |= binary;
                } else {
                    num++;
                    mask = binary;
                    count = 1;
                }
            }
            right[i - 1][0] = num;
            right[i - 1][1] = mask;
            right[i - 1][2] = count;
        }

        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            int seg = left[i][0] + right[i][0] + 2;
            int totMask = left[i][1] | right[i][1];
            int totCount = Integer.bitCount(totMask);
            if (left[i][2] == k && right[i][2] == k && totCount < 26) {
                seg++;
            } else if (Math.min(totCount + 1, 26) <= k) {
                seg--;
            }
            maxVal = Math.max(maxVal, seg);
        }
        return maxVal;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxPartitionsAfterOperations = function (s, k) {
    const n = s.length;
    const left = Array(n)
        .fill()
        .map(() => Array(3).fill(0));
    const right = Array(n)
        .fill()
        .map(() => Array(3).fill(0));

    let num = 0,
        mask = 0,
        count = 0;
    for (let i = 0; i < n - 1; i++) {
        const binary = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        left[i + 1][0] = num;
        left[i + 1][1] = mask;
        left[i + 1][2] = count;
    }

    num = 0;
    mask = 0;
    count = 0;
    for (let i = n - 1; i > 0; i--) {
        const binary = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        right[i - 1][0] = num;
        right[i - 1][1] = mask;
        right[i - 1][2] = count;
    }

    let max = 0;
    for (let i = 0; i < n; i++) {
        let seg = left[i][0] + right[i][0] + 2;
        let totMask = left[i][1] | right[i][1];
        let totCount = 0;
        while (totMask) {
            totMask = totMask & (totMask - 1);
            totCount++;
        }
        if (left[i][2] === k && right[i][2] === k && totCount < 26) {
            seg++;
        } else if (Math.min(totCount + 1, 26) <= k) {
            seg--;
        }
        max = Math.max(max, seg);
    }
    return max;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        n = len(s)
        left = [[0] * 3 for _ in range(n)]
        right = [[0] * 3 for _ in range(n)]

        num, mask, count = 0, 0, 0
        for i in range(n - 1):
            binary = 1 << (ord(s[i]) - ord("a"))
            if not (mask & binary):
                count += 1
                if count <= k:
                    mask |= binary
                else:
                    num += 1
                    mask = binary
                    count = 1
            left[i + 1][0] = num
            left[i + 1][1] = mask
            left[i + 1][2] = count

        num, mask, count = 0, 0, 0
        for i in range(n - 1, 0, -1):
            binary = 1 << (ord(s[i]) - ord("a"))
            if not (mask & binary):
                count += 1
                if count <= k:
                    mask |= binary
                else:
                    num += 1
                    mask = binary
                    count = 1
            right[i - 1][0] = num
            right[i - 1][1] = mask
            right[i - 1][2] = count

        max_val = 0
        for i in range(n):
            seg = left[i][0] + right[i][0] + 2
            tot_mask = left[i][1] | right[i][1]
            tot_count = bin(tot_mask).count("1")
            if left[i][2] == k and right[i][2] == k and tot_count < 26:
                seg += 1
            elif min(tot_count + 1, 26) <= k:
                seg -= 1
            max_val = max(max_val, seg)
        return max_val
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxPartitionsAfterOperations(s: string, k: number): number {
    const n: number = s.length;
    const left: number[][] = Array(n)
        .fill(0)
        .map(() => Array(3).fill(0));
    const right: number[][] = Array(n)
        .fill(0)
        .map(() => Array(3).fill(0));

    let num: number = 0,
        mask: number = 0,
        count: number = 0;
    for (let i = 0; i < n - 1; i++) {
        const binary: number = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        left[i + 1][0] = num;
        left[i + 1][1] = mask;
        left[i + 1][2] = count;
    }

    num = 0;
    mask = 0;
    count = 0;
    for (let i = n - 1; i > 0; i--) {
        const binary: number = 1 << (s.charCodeAt(i) - 97);
        if (!(mask & binary)) {
            count++;
            if (count <= k) {
                mask |= binary;
            } else {
                num++;
                mask = binary;
                count = 1;
            }
        }
        right[i - 1][0] = num;
        right[i - 1][1] = mask;
        right[i - 1][2] = count;
    }

    let max: number = 0;
    for (let i = 0; i < n; i++) {
        let seg: number = left[i][0] + right[i][0] + 2;
        let totMask: number = left[i][1] | right[i][1];
        let totCount: number = 0;
        while (totMask) {
            totMask = totMask & (totMask - 1);
            totCount++;
        }
        if (left[i][2] === k && right[i][2] === k && totCount < 26) {
            seg++;
        } else if (Math.min(totCount + 1, 26) <= k) {
            seg--;
        }
        max = Math.max(max, seg);
    }
    return max;
}
```

</details>
