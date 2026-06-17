# 2040. Kth Smallest Product of Two Sorted Arrays

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 2040 - Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)

## Problem

### Example 1

```text
Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.
```

### Example 2

```text
Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.
```

### Example 3

```text
Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 5 * 104
- -105 <= nums1[i], nums2[j] <= 105
- 1 <= k <= nums1.length * nums2.length
- nums1 and nums2 are sorted.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2040. Kth Smallest Product of Two Sorted Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search + Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Search + Divide and Conquer | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Search + Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int f(int* nums2, int nums2Size, long long x1, long long v) {
    int left = 0, right = nums2Size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long prod = (long long)nums2[mid] * x1;
        if ((x1 >= 0 && prod <= v) || (x1 < 0 && prod > v)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (x1 >= 0) {
        return left;
    } else {
        return nums2Size - left;
    }
}

long long kthSmallestProduct(int* nums1, int nums1Size, int* nums2,
                             int nums2Size, long long k) {
    long long left = -10000000000LL, right = 10000000000LL;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;
        for (int i = 0; i < nums1Size; i++) {
            count += f(nums2, nums2Size, (long long)nums1[i], mid);
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int f(vector<int>& nums2, long long x1, long long v) {
        int n2 = nums2.size();
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x1 >= 0 && nums2[mid] * x1 <= v ||
                x1 < 0 && nums2[mid] * x1 > v) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (x1 >= 0) {
            return left;
        } else {
            return n2 - left;
        }
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i = 0; i < n1; i++) {
                count += f(nums2, nums1[i], mid);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    int F(int[] nums2, long x1, long v) {
        int n2 = nums2.Length;
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            long prod = (long)nums2[mid] * x1;
            if ((x1 >= 0 && prod <= v) || (x1 < 0 && prod > v)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (x1 >= 0) {
            return left;
        } else {
            return n2 - left;
        }
    }

    public long KthSmallestProduct(int[] nums1, int[] nums2, long k) {
        int n1 = nums1.Length;
        long left = -10000000000L, right = 10000000000L;
        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;
            for (int i = 0; i < n1; i++) {
                count += F(nums2, nums1[i], mid);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func f(nums2 []int, x1 int64, v int64) int {
	n2 := len(nums2)
	left, right := 0, n2-1
	for left <= right {
		mid := (left + right) / 2
		prod := int64(nums2[mid]) * x1
		if (x1 >= 0 && prod <= v) || (x1 < 0 && prod > v) {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	if x1 >= 0 {
		return left
	} else {
		return n2 - left
	}
}

func kthSmallestProduct(nums1 []int, nums2 []int, k int64) int64 {
	n1 := len(nums1)
	left, right := int64(-1e10), int64(1e10)
	for left <= right {
		mid := (left + right) / 2
		count := int64(0)
		for i := 0; i < n1; i++ {
			count += int64(f(nums2, int64(nums1[i]), mid))
		}
		if count < k {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return left
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int f(int[] nums2, long x1, long v) {
        int n2 = nums2.length;
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            long prod = (long) nums2[mid] * x1;
            if ((x1 >= 0 && prod <= v) || (x1 < 0 && prod > v)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (x1 >= 0) {
            return left;
        } else {
            return n2 - left;
        }
    }

    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        int n1 = nums1.length;
        long left = -10000000000L, right = 10000000000L;
        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;
            for (int i = 0; i < n1; i++) {
                count += f(nums2, nums1[i], mid);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var f = function (nums2, x1, v) {
    let n2 = nums2.length;
    let left = 0,
        right = n2 - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        let prod = nums2[mid] * x1;
        if ((x1 >= 0 && prod <= v) || (x1 < 0 && prod > v)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (x1 >= 0) {
        return left;
    } else {
        return n2 - left;
    }
};

var kthSmallestProduct = function (nums1, nums2, k) {
    let n1 = nums1.length;
    let left = -1e10,
        right = 1e10;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        let count = 0;
        for (let i = 0; i < n1; i++) {
            count += f(nums2, nums1[i], mid);
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def f(self, nums2: List[int], x1: int, v: int) -> int:
        if x1 > 0:
            return bisect_right(nums2, v // x1)
        elif x1 < 0:
            return len(nums2) - bisect_left(nums2, -(-v // x1))
        else:
            return len(nums2) if v >= 0 else 0

    def kthSmallestProduct(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> int:
        n1 = len(nums1)
        left, right = -(10**10), 10**10
        while left <= right:
            mid = (left + right) // 2
            count = 0
            for i in range(n1):
                count += self.f(nums2, nums1[i], mid)
            if count < k:
                left = mid + 1
            else:
                right = mid - 1
        return left
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function f(nums2: number[], x1: number, v: number): number {
    const n2 = nums2.length;
    let left = 0,
        right = n2 - 1;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const prod = nums2[mid] * x1;
        if ((x1 >= 0 && prod <= v) || (x1 < 0 && prod > v)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (x1 >= 0) {
        return left;
    } else {
        return n2 - left;
    }
}

function kthSmallestProduct(
    nums1: number[],
    nums2: number[],
    k: number,
): number {
    const n1 = nums1.length;
    let left = -1e10,
        right = 1e10;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        let count = 0;
        for (let i = 0; i < n1; i++) {
            count += f(nums2, nums1[i], mid);
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

</details>

<br>

## Approach 2: Binary Search + Divide and Conquer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long kthSmallestProduct(int* nums1, int nums1Size, int* nums2,
                             int nums2Size, long long k) {
    int n1 = nums1Size, n2 = nums2Size;
    int pos1 = 0, pos2 = 0;
    while (pos1 < n1 && nums1[pos1] < 0) {
        pos1++;
    }
    while (pos2 < n2 && nums2[pos2] < 0) {
        pos2++;
    }
    long long left = -1e10, right = 1e10;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;
        int i1 = 0, i2 = pos2 - 1;
        while (i1 < pos1 && i2 >= 0) {
            if ((long long)nums1[i1] * nums2[i2] > mid) {
                i1++;
            } else {
                count += pos1 - i1;
                i2--;
            }
        }
        i1 = pos1;
        i2 = n2 - 1;
        while (i1 < n1 && i2 >= pos2) {
            if ((long long)nums1[i1] * nums2[i2] > mid) {
                i2--;
            } else {
                count += i2 - pos2 + 1;
                i1++;
            }
        }
        i1 = 0;
        i2 = pos2;
        while (i1 < pos1 && i2 < n2) {
            if ((long long)nums1[i1] * nums2[i2] > mid) {
                i2++;
            } else {
                count += n2 - i2;
                i1++;
            }
        }
        i1 = pos1;
        i2 = 0;
        while (i1 < n1 && i2 < pos2) {
            if ((long long)nums1[i1] * nums2[i2] > mid) {
                i1++;
            } else {
                count += n1 - i1;
                i2++;
            }
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i1 = 0, i2 = pos2 - 1; i1 < pos1 && i2 >= 0;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += pos1 - i1;
                    i2--;
                }
            }
            for (int i1 = pos1, i2 = n2 - 1; i1 < n1 && i2 >= pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2--;
                } else {
                    count += i2 - pos2 + 1;
                    i1++;
                }
            }
            for (int i1 = 0, i2 = pos2; i1 < pos1 && i2 < n2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2++;
                } else {
                    count += n2 - i2;
                    i1++;
                }
            }
            for (int i1 = pos1, i2 = 0; i1 < n1 && i2 < pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += n1 - i1;
                    i2++;
                }
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long KthSmallestProduct(int[] nums1, int[] nums2, long k) {
        int n1 = nums1.Length, n2 = nums2.Length;
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        long left = -10000000000L, right = 10000000000L;
        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;
            int i1 = 0, i2 = pos2 - 1;
            while (i1 < pos1 && i2 >= 0) {
                if ((long)nums1[i1] * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += pos1 - i1;
                    i2--;
                }
            }
            i1 = pos1;
            i2 = n2 - 1;
            while (i1 < n1 && i2 >= pos2) {
                if ((long)nums1[i1] * nums2[i2] > mid) {
                    i2--;
                } else {
                    count += i2 - pos2 + 1;
                    i1++;
                }
            }
            i1 = 0;
            i2 = pos2;
            while (i1 < pos1 && i2 < n2) {
                if ((long)nums1[i1] * nums2[i2] > mid) {
                    i2++;
                } else {
                    count += n2 - i2;
                    i1++;
                }
            }
            i1 = pos1;
            i2 = 0;
            while (i1 < n1 && i2 < pos2) {
                if ((long)nums1[i1] * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += n1 - i1;
                    i2++;
                }
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func kthSmallestProduct(nums1 []int, nums2 []int, k int64) int64 {
	n1, n2 := len(nums1), len(nums2)
	pos1, pos2 := 0, 0
	for pos1 < n1 && nums1[pos1] < 0 {
		pos1++
	}
	for pos2 < n2 && nums2[pos2] < 0 {
		pos2++
	}
	left, right := int64(-1e10), int64(1e10)
	for left <= right {
		mid := (left + right) / 2
		count := int64(0)
		i1, i2 := 0, pos2-1
		for i1 < pos1 && i2 >= 0 {
			if int64(nums1[i1])*int64(nums2[i2]) > mid {
				i1++
			} else {
				count += int64(pos1 - i1)
				i2--
			}
		}
		i1, i2 = pos1, n2-1
		for i1 < n1 && i2 >= pos2 {
			if int64(nums1[i1])*int64(nums2[i2]) > mid {
				i2--
			} else {
				count += int64(i2 - pos2 + 1)
				i1++
			}
		}
		i1, i2 = 0, pos2
		for i1 < pos1 && i2 < n2 {
			if int64(nums1[i1])*int64(nums2[i2]) > mid {
				i2++
			} else {
				count += int64(n2 - i2)
				i1++
			}
		}
		i1, i2 = pos1, 0
		for i1 < n1 && i2 < pos2 {
			if int64(nums1[i1])*int64(nums2[i2]) > mid {
				i1++
			} else {
				count += int64(n1 - i1)
				i2++
			}
		}
		if count < k {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return left
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        int n1 = nums1.length, n2 = nums2.length;
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        long left = (long) -1e10, right = (long) 1e10;
        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;
            int i1 = 0, i2 = pos2 - 1;
            while (i1 < pos1 && i2 >= 0) {
                if ((long) nums1[i1] * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += pos1 - i1;
                    i2--;
                }
            }
            i1 = pos1;
            i2 = n2 - 1;
            while (i1 < n1 && i2 >= pos2) {
                if ((long) nums1[i1] * nums2[i2] > mid) {
                    i2--;
                } else {
                    count += i2 - pos2 + 1;
                    i1++;
                }
            }
            i1 = 0;
            i2 = pos2;
            while (i1 < pos1 && i2 < n2) {
                if ((long) nums1[i1] * nums2[i2] > mid) {
                    i2++;
                } else {
                    count += n2 - i2;
                    i1++;
                }
            }
            i1 = pos1;
            i2 = 0;
            while (i1 < n1 && i2 < pos2) {
                if ((long) nums1[i1] * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += n1 - i1;
                    i2++;
                }
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kthSmallestProduct = function (nums1, nums2, k) {
    const n1 = nums1.length,
        n2 = nums2.length;
    let pos1 = 0,
        pos2 = 0;
    while (pos1 < n1 && nums1[pos1] < 0) {
        pos1++;
    }
    while (pos2 < n2 && nums2[pos2] < 0) {
        pos2++;
    }
    let left = -1e10,
        right = 1e10;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        let count = 0;
        let i1 = 0,
            i2 = pos2 - 1;
        while (i1 < pos1 && i2 >= 0) {
            if (nums1[i1] * nums2[i2] > mid) {
                i1++;
            } else {
                count += pos1 - i1;
                i2--;
            }
        }
        i1 = pos1;
        i2 = n2 - 1;
        while (i1 < n1 && i2 >= pos2) {
            if (nums1[i1] * nums2[i2] > mid) {
                i2--;
            } else {
                count += i2 - pos2 + 1;
                i1++;
            }
        }
        i1 = 0;
        i2 = pos2;
        while (i1 < pos1 && i2 < n2) {
            if (nums1[i1] * nums2[i2] > mid) {
                i2++;
            } else {
                count += n2 - i2;
                i1++;
            }
        }
        i1 = pos1;
        i2 = 0;
        while (i1 < n1 && i2 < pos2) {
            if (nums1[i1] * nums2[i2] > mid) {
                i1++;
            } else {
                count += n1 - i1;
                i2++;
            }
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kthSmallestProduct(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> int:
        n1, n2 = len(nums1), len(nums2)
        pos1, pos2 = 0, 0
        while pos1 < n1 and nums1[pos1] < 0:
            pos1 += 1
        while pos2 < n2 and nums2[pos2] < 0:
            pos2 += 1
        left, right = int(-1e10), int(1e10)
        while left <= right:
            mid = (left + right) // 2
            count = 0
            i1, i2 = 0, pos2 - 1
            while i1 < pos1 and i2 >= 0:
                if nums1[i1] * nums2[i2] > mid:
                    i1 += 1
                else:
                    count += pos1 - i1
                    i2 -= 1
            i1, i2 = pos1, n2 - 1
            while i1 < n1 and i2 >= pos2:
                if nums1[i1] * nums2[i2] > mid:
                    i2 -= 1
                else:
                    count += i2 - pos2 + 1
                    i1 += 1
            i1, i2 = 0, pos2
            while i1 < pos1 and i2 < n2:
                if nums1[i1] * nums2[i2] > mid:
                    i2 += 1
                else:
                    count += n2 - i2
                    i1 += 1
            i1, i2 = pos1, 0
            while i1 < n1 and i2 < pos2:
                if nums1[i1] * nums2[i2] > mid:
                    i1 += 1
                else:
                    count += n1 - i1
                    i2 += 1
            if count < k:
                left = mid + 1
            else:
                right = mid - 1
        return left
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function kthSmallestProduct(
    nums1: number[],
    nums2: number[],
    k: number,
): number {
    const n1 = nums1.length,
        n2 = nums2.length;
    let pos1 = 0,
        pos2 = 0;
    while (pos1 < n1 && nums1[pos1] < 0) {
        pos1++;
    }
    while (pos2 < n2 && nums2[pos2] < 0) {
        pos2++;
    }
    let left = -1e10,
        right = 1e10;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        let count = 0;
        let i1 = 0,
            i2 = pos2 - 1;
        while (i1 < pos1 && i2 >= 0) {
            if (nums1[i1] * nums2[i2] > mid) {
                i1++;
            } else {
                count += pos1 - i1;
                i2--;
            }
        }
        i1 = pos1;
        i2 = n2 - 1;
        while (i1 < n1 && i2 >= pos2) {
            if (nums1[i1] * nums2[i2] > mid) {
                i2--;
            } else {
                count += i2 - pos2 + 1;
                i1++;
            }
        }
        i1 = 0;
        i2 = pos2;
        while (i1 < pos1 && i2 < n2) {
            if (nums1[i1] * nums2[i2] > mid) {
                i2++;
            } else {
                count += n2 - i2;
                i1++;
            }
        }
        i1 = pos1;
        i2 = 0;
        while (i1 < n1 && i2 < pos2) {
            if (nums1[i1] * nums2[i2] > mid) {
                i1++;
            } else {
                count += n1 - i1;
                i2++;
            }
        }
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
```

</details>
