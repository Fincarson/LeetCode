# 3445. Maximum Difference Between Even and Odd Frequency II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/)  
`String` `Sliding Window` `Enumeration` `Prefix Sum`

**Problem Link:** [LeetCode 3445 - Maximum Difference Between Even and Odd Frequency II](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/)

## Problem

You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:

- subs has a size of at least k.
- Character a has an odd frequency in subs.
- Character b has a non-zero even frequency in subs.

Return the maximum difference.

Note that subs can contain more than 2 distinct characters.

### Example 1

### Example 2

### Example 3

## Constraints

- 3 <= s.length <= 3 * 104
- s consists only of digits '0' to '4'.
- The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
- 1 <= k <= s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3445. Maximum Difference Between Even and Odd Frequency II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumerate Two Characters + Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumerate Two Characters + Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int getStatus(int cnt_a, int cnt_b) { return ((cnt_a & 1) << 1) | (cnt_b & 1); }

int maxDifference(char* s, int k) {
    int n = strlen(s);
    int ans = INT_MIN;

    for (char a = '0'; a <= '4'; ++a) {
        for (char b = '0'; b <= '4'; ++b) {
            if (a == b) {
                continue;
            }
            int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
            int cnt_a = 0, cnt_b = 0;
            int prev_a = 0, prev_b = 0;
            int left = -1;
            for (int right = 0; right < n; ++right) {
                cnt_a += (s[right] == a) ? 1 : 0;
                cnt_b += (s[right] == b) ? 1 : 0;

                while (right - left >= k && cnt_b - prev_b >= 2) {
                    int left_status = getStatus(prev_a, prev_b);
                    if (prev_a - prev_b < best[left_status]) {
                        best[left_status] = prev_a - prev_b;
                    }
                    ++left;
                    prev_a += (s[left] == a) ? 1 : 0;
                    prev_b += (s[left] == b) ? 1 : 0;
                }

                int right_status = getStatus(cnt_a, cnt_b);
                if (best[right_status ^ 0b10] != INT_MAX) {
                    int current = cnt_a - cnt_b - best[right_status ^ 0b10];
                    if (current > ans) {
                        ans = current;
                    }
                }
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
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) -> int {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int n = s.size();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) {
                    continue;
                }
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);
                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] =
                            min(best[left_status], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != INT_MAX) {
                        ans =
                            max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
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
    public int MaxDifference(string s, int k) {
        int n = s.Length;
        int ans = int.MinValue;
        foreach (char a in new char[] { '0', '1', '2', '3', '4' }) {
            foreach (char b in new char[] { '0', '1', '2', '3', '4' }) {
                if (a == b) {
                    continue;
                }
                int[] best = new int[4];
                Array.Fill(best, int.MaxValue);
                int cntA = 0, cntB = 0;
                int prevA = 0, prevB = 0;
                int left = -1;
                for (int right = 0; right < n; right++) {
                    if (s[right] == a) {
                        cntA++;
                    }
                    if (s[right] == b) {
                        cntB++;
                    }
                    while (right - left >= k && cntB - prevB >= 2) {
                        int leftStatus = GetStatus(prevA, prevB);
                        best[leftStatus] =
                            Math.Min(best[leftStatus], prevA - prevB);
                        left++;
                        if (s[left] == a) {
                            prevA++;
                        }
                        if (s[left] == b) {
                            prevB++;
                        }
                    }
                    int rightStatus = GetStatus(cntA, cntB);
                    if (best[rightStatus ^ 0b10] != int.MaxValue) {
                        ans = Math.Max(
                            ans, (cntA - cntB) - best[rightStatus ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }

    private int GetStatus(int cntA, int cntB) {
        return ((cntA & 1) << 1) | (cntB & 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDifference(s string, k int) int {
	n := len(s)
	ans := math.MinInt32
	for _, a := range []byte{'0', '1', '2', '3', '4'} {
		for _, b := range []byte{'0', '1', '2', '3', '4'} {
			if a == b {
				continue
			}
			best := make([]int, 4)
			for i := range best {
				best[i] = math.MaxInt32
			}
			cntA, cntB := 0, 0
			prevA, prevB := 0, 0
			left := -1
			for right := 0; right < n; right++ {
				if s[right] == a {
					cntA++
				}
				if s[right] == b {
					cntB++
				}
				for right-left >= k && cntB-prevB >= 2 {
					leftStatus := getStatus(prevA, prevB)
					if prevA-prevB < best[leftStatus] {
						best[leftStatus] = prevA - prevB
					}
					left++
					if s[left] == a {
						prevA++
					}
					if s[left] == b {
						prevB++
					}
				}
				rightStatus := getStatus(cntA, cntB)
				if best[rightStatus^0b10] != math.MaxInt32 {
					current := (cntA - cntB) - best[rightStatus^0b10]
					if current > ans {
						ans = current
					}
				}
			}
		}
	}
	return ans
}

func getStatus(cntA, cntB int) int {
	return ((cntA & 1) << 1) | (cntB & 1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxDifference(String s, int k) {
        int n = s.length();
        int ans = Integer.MIN_VALUE;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) {
                    continue;
                }
                int[] best = new int[4];
                Arrays.fill(best, Integer.MAX_VALUE);
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;

                for (int right = 0; right < n; ++right) {
                    cnt_a += (s.charAt(right) == a) ? 1 : 0;
                    cnt_b += (s.charAt(right) == b) ? 1 : 0;

                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] = Math.min(
                            best[left_status],
                            prev_a - prev_b
                        );
                        ++left;
                        prev_a += (s.charAt(left) == a) ? 1 : 0;
                        prev_b += (s.charAt(left) == b) ? 1 : 0;
                    }

                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != Integer.MAX_VALUE) {
                        ans = Math.max(
                            ans,
                            cnt_a - cnt_b - best[right_status ^ 0b10]
                        );
                    }
                }
            }
        }
        return ans;
    }

    private int getStatus(int cnt_a, int cnt_b) {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDifference = function (s, k) {
    const n = s.length;
    let ans = -Infinity;

    const getStatus = (cnt_a, cnt_b) => {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    };

    for (const a of ["0", "1", "2", "3", "4", "5"]) {
        for (const b of ["0", "1", "2", "3", "4", "5"]) {
            if (a === b) {
                continue;
            }
            const best = [Infinity, Infinity, Infinity, Infinity];
            let cnt_a = 0,
                cnt_b = 0;
            let prev_a = 0,
                prev_b = 0;
            let left = -1;

            for (let right = 0; right < n; right++) {
                cnt_a += s[right] === a ? 1 : 0;
                cnt_b += s[right] === b ? 1 : 0;

                while (right - left >= k && cnt_b - prev_b >= 2) {
                    const left_status = getStatus(prev_a, prev_b);
                    best[left_status] = Math.min(
                        best[left_status],
                        prev_a - prev_b,
                    );
                    left++;
                    prev_a += s[left] === a ? 1 : 0;
                    prev_b += s[left] === b ? 1 : 0;
                }

                const right_status = getStatus(cnt_a, cnt_b);
                if (best[right_status ^ 0b10] !== Infinity) {
                    ans = Math.max(
                        ans,
                        cnt_a - cnt_b - best[right_status ^ 0b10],
                    );
                }
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
    def maxDifference(self, s: str, k: int) -> int:
        def getStatus(cnt_a: int, cnt_b: int) -> int:
            return ((cnt_a & 1) << 1) | (cnt_b & 1)

        n = len(s)
        ans = float("-inf")
        for a in ["0", "1", "2", "3", "4"]:
            for b in ["0", "1", "2", "3", "4"]:
                if a == b:
                    continue

                best = [float("inf")] * 4
                cnt_a = cnt_b = 0
                prev_a = prev_b = 0
                left = -1
                for right in range(n):
                    cnt_a += s[right] == a
                    cnt_b += s[right] == b
                    while right - left >= k and cnt_b - prev_b >= 2:
                        left_status = getStatus(prev_a, prev_b)
                        best[left_status] = min(
                            best[left_status], prev_a - prev_b
                        )
                        left += 1
                        prev_a += s[left] == a
                        prev_b += s[left] == b

                    right_status = getStatus(cnt_a, cnt_b)
                    if best[right_status ^ 0b10] != float("inf"):
                        ans = max(
                            ans, cnt_a - cnt_b - best[right_status ^ 0b10]
                        )

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDifference(s: string, k: number): number {
    const n = s.length;
    let ans = -Infinity;

    const getStatus = (cnt_a: number, cnt_b: number): number => {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    };

    for (const a of ["0", "1", "2", "3", "4", "5"]) {
        for (const b of ["0", "1", "2", "3", "4", "5"]) {
            if (a === b) {
                continue;
            }
            const best: number[] = [Infinity, Infinity, Infinity, Infinity];
            let cnt_a = 0,
                cnt_b = 0;
            let prev_a = 0,
                prev_b = 0;
            let left = -1;
            for (let right = 0; right < n; right++) {
                cnt_a += s[right] === a ? 1 : 0;
                cnt_b += s[right] === b ? 1 : 0;

                while (right - left >= k && cnt_b - prev_b >= 2) {
                    const left_status = getStatus(prev_a, prev_b);
                    best[left_status] = Math.min(
                        best[left_status],
                        prev_a - prev_b,
                    );
                    left++;
                    prev_a += s[left] === a ? 1 : 0;
                    prev_b += s[left] === b ? 1 : 0;
                }

                const right_status = getStatus(cnt_a, cnt_b);
                if (best[right_status ^ 0b10] !== Infinity) {
                    ans = Math.max(
                        ans,
                        cnt_a - cnt_b - best[right_status ^ 0b10],
                    );
                }
            }
        }
    }
    return ans;
}
```

</details>
