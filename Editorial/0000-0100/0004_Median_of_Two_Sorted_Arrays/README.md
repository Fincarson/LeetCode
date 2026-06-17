# 4. Median of Two Sorted Arrays

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/median-of-two-sorted-arrays/)  
`Array` `Binary Search` `Divide and Conquer`

**Problem Link:** [LeetCode 4 - Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

## Problem

Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n`, return the median of the two sorted arrays.

The overall runtime complexity should be `O(log(m + n))`.

## Examples

### Example 1

```text
Input: nums1 = [1, 3], nums2 = [2]
Output: 2.00000
Explanation: The merged array is [1, 2, 3], and the median is 2.
```

### Example 2

```text
Input: nums1 = [1, 2], nums2 = [3, 4]
Output: 2.50000
Explanation: The merged array is [1, 2, 3, 4], and the median is (2 + 3) / 2 = 2.5.
```

## Constraints

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

## Follow-Up

Can you solve it in `O(log(m + n))` time?

## Hints

<details>
<summary><strong>Hint 1</strong></summary>

The direct way is to think about the merged sorted order, even if you do not physically build the merged array.

</details>

<details>
<summary><strong>Hint 2</strong></summary>

The median can be described as one or two kth elements in the combined sorted order.

</details>

<details>
<summary><strong>Hint 3</strong></summary>

For the optimal solution, search for a partition where every value on the left side is less than or equal to every value on the right side.

</details>

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Median of a Row Wise Sorted Matrix](https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 4. Median of Two Sorted Arrays

## Overview

The official editorial starts with a merge-style scan, then reaches the required logarithmic runtime with binary search.

The median is the middle value of the combined sorted order. For an even total length, it is the average of the two middle values.

| Approach | Time | Space | Idea |
|---|:---:|:---:|---|
| Merge Sort | `O(m + n)` | `O(1)` | Walk through the arrays as if merging and stop at the median position. |
| Binary Search, Recursive | `O(log(m + n))` | `O(log(m + n))` | Find the kth element by recursively discarding impossible halves. |
| A Better Binary Search | `O(log(min(m, n)))` | `O(1)` | Binary search the partition point in the smaller array. |

## Approach 1: Merge Sort

### Intuition

The median is determined by the middle element or two middle elements of the merged sorted order. We do not need to store the merged array; we can advance two pointers until the needed positions are reached.

### Algorithm

1. Track two pointers, one for each array.
2. Repeatedly take the smaller current value, advancing that array pointer.
3. For an odd total length, return the middle taken value.
4. For an even total length, average the two middle taken values.

### Complexity

- Time complexity: `O(m + n)`
- Space complexity: `O(1)`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    int m = nums1Size, n = nums2Size;
    int p1 = 0, p2 = 0;
    int getMin() {
        if (p1 < m && p2 < n) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < m) {
            return nums1[p1++];
        } else if (p2 < n) {
            return nums2[p2++];
        }
        return -1;
    }

    double median;
    if ((m + n) % 2 == 0) {
        for (int i = 0; i < ((m + n) / 2) - 1; ++i) {
            int temp = getMin();
        }
        median = (getMin() + getMin()) / 2.0;
    } else {
        for (int i = 0; i < (m + n) / 2; ++i) {
            int temp = getMin();
        }
        median = getMin();
    }

    return median;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int p1 = 0, p2 = 0;

    // Get the smaller value between nums1[p1] and nums2[p2] and move the
    // pointer forward.

    int getMin(vector<int>& nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());

        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    int p1 = 0, p2 = 0;

    private int GetMin(int[] nums1, int[] nums2) {
        if (p1 < nums1.Length && p2 < nums2.Length) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.Length) {
            return nums1[p1++];
        } else if (p2 < nums2.Length) {
            return nums2[p2++];
        }

        return -1;
    }

    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.Length, n = nums2.Length;
        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int tmp = GetMin(nums1, nums2);
            }

            return (double)(GetMin(nums1, nums2) + GetMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int tmp = GetMin(nums1, nums2);
            }

            return GetMin(nums1, nums2);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    m, n := len(nums1), len(nums2)
    p1, p2 := 0, 0

    getMin := func() int {
        if p1 < m && p2 < n {
            if nums1[p1] < nums2[p2] {
                p1++
                return nums1[p1-1]
            } else {
                p2++
                return nums2[p2-1]
            }
        } else if p1 < m {
            p1++
            return nums1[p1-1]
        } else {
            p2++
            return nums2[p2-1]
        }
        return -1
    }

    var median float64
    if (m+n)%2 == 0 {
        for i := 0; i < (m+n)/2-1; i++ {
            getMin()
        }
        median = float64(getMin()+getMin()) / 2
    } else {
        for i := 0; i < (m+n)/2; i++ {
            getMin()
        }
        median = float64(getMin())
    }

    return median
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int p1 = 0, p2 = 0;

    // Get the smaller value between nums1[p1] and nums2[p2] and move the pointer forwards.

    private int getMin(int[] nums1, int[] nums2) {
        if (p1 < nums1.length && p2 < nums2.length) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.length) {
            return nums1[p1++];
        } else if (p2 < nums2.length) {
            return nums2[p2++];
        }
        return -1;
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int tmp = getMin(nums1, nums2);
            }
            return (double) (getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int tmp = getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findMedianSortedArrays = function (nums1, nums2) {
    let m = nums1.length,
        n = nums2.length;
    let p1 = 0,
        p2 = 0;

    let getMin = function () {
        if (p1 < m && p2 < n) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < m) {
            return nums1[p1++];
        } else if (p2 < n) {
            return nums2[p2++];
        }
        return -1;
    };

    if ((m + n) % 2 === 0) {
        for (let i = 0; i < (m + n) / 2 - 1; ++i) {
            let temp = getMin();
        }
        return (getMin() + getMin()) / 2.0;
    } else {
        for (let i = 0; i < Math.floor((m + n) / 2); ++i) {
            let temp = getMin();
        }
        return getMin();
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMedianSortedArrays(
        self, nums1: List[int], nums2: List[int]
    ) -> float:
        m, n = len(nums1), len(nums2)
        p1, p2 = 0, 0

        # Get the smaller value between nums1[p1] and nums2[p2].
        def get_min():
            nonlocal p1, p2
            if p1 < m and p2 < n:
                if nums1[p1] < nums2[p2]:
                    ans = nums1[p1]
                    p1 += 1
                else:
                    ans = nums2[p2]
                    p2 += 1
            elif p2 == n:
                ans = nums1[p1]
                p1 += 1
            else:
                ans = nums2[p2]
                p2 += 1
            return ans

        if (m + n) % 2 == 0:
            for _ in range((m + n) // 2 - 1):
                _ = get_min()
            return (get_min() + get_min()) / 2
        else:
            for _ in range((m + n) // 2):
                _ = get_min()
            return get_min()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let m = nums1.length,
        n = nums2.length;
    let p1 = 0,
        p2 = 0;

    const getMin = function (): number {
        if (p1 < m && p2 < n) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < m) {
            return nums1[p1++];
        } else if (p2 < n) {
            return nums2[p2++];
        }
        return -1;
    };

    if ((m + n) % 2 === 0) {
        for (let i = 0; i < (m + n) / 2 - 1; ++i) {
            getMin();
        }
        return (getMin() + getMin()) / 2;
    } else {
        for (let i = 0; i < Math.floor((m + n) / 2); ++i) {
            getMin();
        }
        return getMin();
    }
}
```

</details>

<br>

## Approach 2: Binary Search, Recursive

### Intuition

The median can be expressed as one or two kth elements. By comparing middle candidates from the active ranges, we can discard a section that cannot contain the kth value.

### Algorithm

1. Convert the median query into one or two kth-element queries.
2. If one active range is empty, return the kth element from the other array.
3. If `k == 0`, return the smaller active first element.
4. Compare middle values from both active ranges and discard the side that cannot contain the kth element.
5. Recurse on the reduced ranges.

### Complexity

- Time complexity: `O(log(m + n))`
- Space complexity: `O(log(m + n))`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int solve(int* A, int aStart, int aEnd, int* B, int bStart, int bEnd, int k) {
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other array.
    if (aEnd < aStart) {
        return B[k - aStart];
    }
    if (bEnd < bStart) {
        return A[k - bStart];
    }

    // Get the middle indexes and middle values of A and B.
    int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
    int aValue = A[aIndex], bValue = B[bIndex];

    // If k is in the right half of A + B, remove the smaller left half.
    if (aIndex + bIndex < k) {
        if (aValue > bValue) {
            return solve(A, aStart, aEnd, B, bIndex + 1, bEnd, k);
        } else {
            return solve(A, aIndex + 1, aEnd, B, bStart, bEnd, k);
        }
    }
    // Otherwise, remove the larger right half.
    else {
        if (aValue > bValue) {
            return solve(A, aStart, aIndex - 1, B, bStart, bEnd, k);
        } else {
            return solve(A, aStart, aEnd, B, bStart, bIndex - 1, k);
        }
    }
}

double findMedianSortedArrays(int* A, int na, int* B, int nb) {
    int n = na + nb;
    if (n % 2 == 1) {
        return solve(A, 0, na - 1, B, 0, nb - 1, n / 2);
    } else {
        return (solve(A, 0, na - 1, B, 0, nb - 1, n / 2) +
                solve(A, 0, na - 1, B, 0, nb - 1, n / 2 - 1)) /
               2.0;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int na = int(A.size()), nb = int(B.size());
        int n = na + nb;
        if (n % 2) {
            return solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
        } else {
            return 1.0 *
                   (solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1) +
                    solve(A, B, n / 2, 0, na - 1, 0, nb - 1)) /
                   2;
        }
    }
    int solve(vector<int>& A, vector<int>& B, int k, int aStart, int aEnd,
              int bStart, int bEnd) {
        // If the segment of on array is empty, it means we have passed all
        // its element, just return the corresponding element in the other
        // array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }
        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        }
        // Otherwise, remove the larger right half.
        else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public double FindMedianSortedArrays(int[] A, int[] B) {
        int na = A.Length, nb = B.Length;
        int n = na + nb;
        if ((na + nb) % 2 == 1) {
            return Solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
        } else {
            return (double)(Solve(A, B, n / 2, 0, na - 1, 0, nb - 1) +
                            Solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1)) /
                   2;
        }
    }

    public int Solve(int[] A, int[] B, int k, int aStart, int aEnd, int bStart,
                     int bEnd) {
        // If the segment of on array is empty, it means we have passed all
        // its element, just return the corresponding element in the other
        // array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }

        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return Solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return Solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        }
        // Otherwise, remove the larger right half.
        else {
            if (aValue > bValue) {
                return Solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return Solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func solve(
    A []int,
    aStart int,
    aEnd int,
    B []int,
    bStart int,
    bEnd int,
    k int,
) int {
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other array.
    if aEnd < aStart {
        return B[k-aStart]
    }
    if bEnd < bStart {
        return A[k-bStart]
    }

    // Get the middle indexes and middle values of A and B.
    aIndex, bIndex := (aStart+aEnd)/2, (bStart+bEnd)/2
    aValue, bValue := A[aIndex], B[bIndex]

    // If k is in the right half of A + B, remove the smaller left half.
    if aIndex+bIndex < k {
        if aValue > bValue {
            return solve(A, aStart, aEnd, B, bIndex+1, bEnd, k)
        }
        return solve(A, aIndex+1, aEnd, B, bStart, bEnd, k)
    }

    // Otherwise, remove the larger right half.
    if aValue > bValue {
        return solve(A, aStart, aIndex-1, B, bStart, bEnd, k)
    }
    return solve(A, aStart, aEnd, B, bStart, bIndex-1, k)
}

func findMedianSortedArrays(A []int, B []int) float64 {
    na, nb := len(A), len(B)
    n := na + nb
    if n%2 == 1 {
        return float64(solve(A, 0, na-1, B, 0, nb-1, n/2))
    }
    return (float64(solve(A, 0, na-1, B, 0, nb-1, n/2)) + float64(solve(A, 0, na-1, B, 0, nb-1, n/2-1))) / 2
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int na = A.length, nb = B.length;
        int n = na + nb;
        if ((na + nb) % 2 == 1) {
            return solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
        } else {
            return (
                (double) (solve(A, B, n / 2, 0, na - 1, 0, nb - 1) +
                    solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1)) /
                2
            );
        }
    }

    public int solve(
        int[] A,
        int[] B,
        int k,
        int aStart,
        int aEnd,
        int bStart,
        int bEnd
    ) {
        // If the segment of on array is empty, it means we have passed all
        // its element, just return the corresponding element in the other array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }
        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        }
        // Otherwise, remove the larger right half.
        else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findMedianSortedArrays = function (A, B) {
    var na = A.length,
        nb = B.length;
    var n = na + nb;

    function solve(A, B, k, aStart, aEnd, bStart, bEnd) {
        // If the segment of one array is empty, it means we have passed all
        // its element, just return the corresponding element in the other array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }
        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        var aIndex = Math.floor((aStart + aEnd) / 2),
            bIndex = Math.floor((bStart + bEnd) / 2);
        var aValue = A[aIndex],
            bValue = B[bIndex];

        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        }
        // Otherwise, remove the larger right half.
        else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
    }

    if (n % 2 == 1) {
        return solve(A, B, Math.floor(n / 2), 0, na - 1, 0, nb - 1);
    } else {
        return (
            (solve(A, B, Math.floor(n / 2 - 1), 0, na - 1, 0, nb - 1) +
                solve(A, B, Math.floor(n / 2), 0, na - 1, 0, nb - 1)) /
            2.0
        );
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
        na, nb = len(A), len(B)
        n = na + nb

        def solve(k, a_start, a_end, b_start, b_end):
            # If the segment of on array is empty, it means we have passed all
            # its element, just return the corresponding element in the other array.
            if a_start > a_end:
                return B[k - a_start]
            if b_start > b_end:
                return A[k - b_start]

            # Get the middle indexes and middle values of A and B.
            a_index, b_index = (a_start + a_end) // 2, (b_start + b_end) // 2
            a_value, b_value = A[a_index], B[b_index]

            # If k is in the right half of A + B, remove the smaller left half.
            if a_index + b_index < k:
                if a_value > b_value:
                    return solve(k, a_start, a_end, b_index + 1, b_end)
                else:
                    return solve(k, a_index + 1, a_end, b_start, b_end)
            # Otherwise, remove the larger right half.
            else:
                if a_value > b_value:
                    return solve(k, a_start, a_index - 1, b_start, b_end)
                else:
                    return solve(k, a_start, a_end, b_start, b_index - 1)

        if n % 2:
            return solve(n // 2, 0, na - 1, 0, nb - 1)
        else:
            return (
                solve(n // 2 - 1, 0, na - 1, 0, nb - 1)
                + solve(n // 2, 0, na - 1, 0, nb - 1)
            ) / 2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findMedianSortedArrays(A: number[], B: number[]): number {
    var na = A.length,
        nb = B.length;
    var n = na + nb;

    function solve(
        A: number[],
        B: number[],
        k: number,
        aStart: number,
        aEnd: number,
        bStart: number,
        bEnd: number,
    ): number {
        // If the segment of one array is empty, it means we have passed all
        // its element, just return the corresponding element in the other array.
        if (aEnd < aStart) {
            return B[k - aStart];
        }
        if (bEnd < bStart) {
            return A[k - bStart];
        }

        // Get the middle indexes and middle values of A and B.
        var aIndex = Math.floor((aStart + aEnd) / 2),
            bIndex = Math.floor((bStart + bEnd) / 2);
        var aValue = A[aIndex],
            bValue = B[bIndex];

        // If k is in the right half of A + B, remove the smaller left half.
        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        }
        // Otherwise, remove the larger right half.
        else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
    }

    if (n % 2 == 1) {
        return solve(A, B, Math.floor(n / 2), 0, na - 1, 0, nb - 1);
    } else {
        return (
            (solve(A, B, Math.floor(n / 2 - 1), 0, na - 1, 0, nb - 1) +
                solve(A, B, Math.floor(n / 2), 0, na - 1, 0, nb - 1)) /
            2.0
        );
    }
}
```

</details>

<br>

## Approach 3: A Better Binary Search

### Intuition

A valid median partition puts half the combined elements on the left and half on the right, with every left-side value less than or equal to every right-side value. Searching the smaller array gives the required logarithmic bound.

### Algorithm

1. Make sure `nums1` is the smaller array.
2. Binary search how many elements to take from `nums1` for the left partition.
3. Derive how many elements must be taken from `nums2`.
4. Check whether the partition boundaries are valid.
5. Return the middle value or average of two middle values once the partition is valid.

### Complexity

- Time complexity: `O(log(min(m, n)))`
- Space complexity: `O(1)`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    // Ensure nums1 is the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size, n = nums2Size;
    int left = 0, right = m;

    while (left <= right) {
        int partitionA = (left + right) / 2;
        int partitionB = (m + n + 1) / 2 - partitionA;

        int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
        int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
        int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
        int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) /
                       2.0;
            } else {
                return max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            right = partitionA - 1;
        } else {
            left = partitionA + 1;
        }
    }

    return 0.0;  // control should never reach here
}

int max(int a, int b) { return (a > b) ? a : b; }

int min(int a, int b) { return (a < b) ? a : b; }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }

        return 0.0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.Length > nums2.Length) {
            return FindMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.Length, n = nums2.Length;
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA =
                (partitionA == 0) ? int.MinValue : nums1[partitionA - 1];
            int minRightA =
                (partitionA == m) ? int.MaxValue : nums1[partitionA];
            int maxLeftB =
                (partitionB == 0) ? int.MinValue : nums2[partitionB - 1];
            int minRightB =
                (partitionB == n) ? int.MaxValue : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (Math.Max(maxLeftA, maxLeftB) +
                            Math.Min(minRightA, minRightB)) /
                           2.0;
                } else {
                    return Math.Max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }

        return 0.0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    if len(nums1) > len(nums2) {
        temp := nums1
        nums1 = nums2
        nums2 = temp
    }

    m, n := len(nums1), len(nums2)
    left, right := 0, m

    for left <= right {
        partitionA := (left + right) / 2
        partitionB := (m+n+1)/2 - partitionA

        maxLeftA := math.MinInt64
        if partitionA != 0 {
            maxLeftA = nums1[partitionA-1]
        }
        minRightA := math.MaxInt64
        if partitionA != m {
            minRightA = nums1[partitionA]
        }

        maxLeftB := math.MinInt64
        if partitionB != 0 {
            maxLeftB = nums2[partitionB-1]
        }
        minRightB := math.MaxInt64
        if partitionB != n {
            minRightB = nums2[partitionB]
        }

        if maxLeftA <= minRightB && maxLeftB <= minRightA {
            if (m+n)%2 == 0 {
                maxLeft := math.Max(float64(maxLeftA), float64(maxLeftB))
                minRight := math.Min(float64(minRightA), float64(minRightB))
                return (maxLeft + minRight) / 2.0
            } else {
                return math.Max(float64(maxLeftA), float64(maxLeftB))
            }
        } else if maxLeftA > minRightB {
            right = partitionA - 1
        } else {
            left = partitionA + 1
        }
    }
    return 0.0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length, n = nums2.length;
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0)
                ? Integer.MIN_VALUE
                : nums1[partitionA - 1];
            int minRightA = (partitionA == m)
                ? Integer.MAX_VALUE
                : nums1[partitionA];
            int maxLeftB = (partitionB == 0)
                ? Integer.MIN_VALUE
                : nums2[partitionB - 1];
            int minRightB = (partitionB == n)
                ? Integer.MAX_VALUE
                : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (
                        (Math.max(maxLeftA, maxLeftB) +
                            Math.min(minRightA, minRightB)) /
                        2.0
                    );
                } else {
                    return Math.max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }
        return 0.0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findMedianSortedArrays = function (nums1, nums2) {
    if (nums1.length > nums2.length) {
        let temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }

    let m = nums1.length,
        n = nums2.length;
    let left = 0,
        right = m;

    while (left <= right) {
        let partitionA = Math.floor((left + right) / 2);
        let partitionB = Math.floor((m + n + 1) / 2 - partitionA);

        let maxLeftA =
            partitionA == 0 ? Number.MIN_SAFE_INTEGER : nums1[partitionA - 1];
        let minRightA =
            partitionA == m ? Number.MAX_SAFE_INTEGER : nums1[partitionA];
        let maxLeftB =
            partitionB == 0 ? Number.MIN_SAFE_INTEGER : nums2[partitionB - 1];
        let minRightB =
            partitionB == n ? Number.MAX_SAFE_INTEGER : nums2[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((m + n) % 2 == 0) {
                return (
                    (Math.max(maxLeftA, maxLeftB) +
                        Math.min(minRightA, minRightB)) /
                    2.0
                );
            } else {
                return Math.max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            right = partitionA - 1;
        } else {
            left = partitionA + 1;
        }
    }
    return 0.0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMedianSortedArrays(
        self, nums1: List[int], nums2: List[int]
    ) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        m, n = len(nums1), len(nums2)
        left, right = 0, m

        while left <= right:
            partitionA = (left + right) // 2
            partitionB = (m + n + 1) // 2 - partitionA

            maxLeftA = (
                float("-inf") if partitionA == 0 else nums1[partitionA - 1]
            )
            minRightA = float("inf") if partitionA == m else nums1[partitionA]
            maxLeftB = (
                float("-inf") if partitionB == 0 else nums2[partitionB - 1]
            )
            minRightB = float("inf") if partitionB == n else nums2[partitionB]

            if maxLeftA <= minRightB and maxLeftB <= minRightA:
                if (m + n) % 2 == 0:
                    return (
                        max(maxLeftA, maxLeftB) + min(minRightA, minRightB)
                    ) / 2
                else:
                    return max(maxLeftA, maxLeftB)
            elif maxLeftA > minRightB:
                right = partitionA - 1
            else:
                left = partitionA + 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    if (nums1.length > nums2.length) {
        let temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }

    let m = nums1.length,
        n = nums2.length;
    let left = 0,
        right = m;

    while (left <= right) {
        let partitionA = Math.floor((left + right) / 2);
        let partitionB = Math.floor((m + n + 1) / 2 - partitionA);

        let maxLeftA =
            partitionA == 0 ? Number.MIN_SAFE_INTEGER : nums1[partitionA - 1];
        let minRightA =
            partitionA == m ? Number.MAX_SAFE_INTEGER : nums1[partitionA];
        let maxLeftB =
            partitionB == 0 ? Number.MIN_SAFE_INTEGER : nums2[partitionB - 1];
        let minRightB =
            partitionB == n ? Number.MAX_SAFE_INTEGER : nums2[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((m + n) % 2 == 0) {
                return (
                    (Math.max(maxLeftA, maxLeftB) +
                        Math.min(minRightA, minRightB)) /
                    2.0
                );
            } else {
                return Math.max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            right = partitionA - 1;
        } else {
            left = partitionA + 1;
        }
    }
    return 0.0;
}
```

</details>
