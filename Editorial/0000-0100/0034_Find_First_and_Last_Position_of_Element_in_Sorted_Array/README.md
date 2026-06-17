# 34. Find First and Last Position of Element in Sorted Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 34 - Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## Problem

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

### Example 1

```text
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

### Example 2

```text
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

### Example 3

```text
Input: nums = [], target = 0
Output: [-1,-1]
```

## Constraints

- 0 <= nums.length <= 105
- -109 <= nums[i] <= 109
- nums is a non-decreasing array.
- -109 <= target <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Bad Version](https://leetcode.com/problems/first-bad-version/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Plates Between Candles](https://leetcode.com/problems/plates-between-candles/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 34. Find First and Last Position of Element in Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findBound(int* nums, int numsSize, int target, int isFirst) {
    int begin = 0, end = numsSize - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (nums[mid] == target) {
            if (isFirst) {
                if (mid == begin || nums[mid - 1] != target) {
                    return mid;
                }
                end = mid - 1;
            } else {
                if (mid == end || nums[mid + 1] != target) {
                    return mid;
                }
                begin = mid + 1;
            }
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(sizeof(int) * 2);
    int firstOccurrence = findBound(nums, numsSize, target, 1);
    if (firstOccurrence == -1) {
        result[0] = -1;
        result[1] = -1;
        *returnSize = 2;
        return result;
    }
    int lastOccurrence = findBound(nums, numsSize, target, 0);
    result[0] = firstOccurrence;
    result[1] = lastOccurrence;
    *returnSize = 2;
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurrence = this->findBound(nums, target, true);
        if (firstOccurrence == -1) {
            return vector<int>{-1, -1};
        }
        int lastOccurrence = this->findBound(nums, target, false);
        return vector<int>{firstOccurrence, lastOccurrence};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int N = nums.size();
        int begin = 0, end = N - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                if (isFirst) {
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }
                    end = mid - 1;
                } else {
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }
                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
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
    public int[] SearchRange(int[] nums, int target) {
        int firstOccurrence = this.FindBound(nums, target, true);
        if (firstOccurrence == -1) {
            return new int[] { -1, -1 };
        }

        int lastOccurrence = this.FindBound(nums, target, false);
        return new int[] { firstOccurrence, lastOccurrence };
    }

    private int FindBound(int[] nums, int target, bool isFirst) {
        int N = nums.Length;
        int begin = 0, end = N - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                if (isFirst) {
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }

                    end = mid - 1;
                } else {
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }

                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func searchRange(nums []int, target int) []int {
    firstOccurrence := findBound(nums, target, true)
    if firstOccurrence == -1 {
        return []int{-1, -1}
    }
    lastOccurrence := findBound(nums, target, false)
    return []int{firstOccurrence, lastOccurrence}
}

func findBound(nums []int, target int, isFirst bool) int {
    N := len(nums)
    begin, end := 0, N-1
    for begin <= end {
        mid := (begin + end) / 2
        if nums[mid] == target {
            if isFirst {
                if mid == begin || nums[mid-1] != target {
                    return mid
                }
                end = mid - 1
            } else {
                if mid == end || nums[mid+1] != target {
                    return mid
                }
                begin = mid + 1
            }
        } else if nums[mid] > target {
            end = mid - 1
        } else {
            begin = mid + 1
        }
    }
    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int firstOccurrence = this.findBound(nums, target, true);

        if (firstOccurrence == -1) {
            return new int[] { -1, -1 };
        }

        int lastOccurrence = this.findBound(nums, target, false);

        return new int[] { firstOccurrence, lastOccurrence };
    }

    private int findBound(int[] nums, int target, boolean isFirst) {
        int N = nums.length;
        int begin = 0, end = N - 1;

        while (begin <= end) {
            int mid = (begin + end) / 2;

            if (nums[mid] == target) {
                if (isFirst) {
                    // This means we found our lower bound.
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }

                    // Search on the left side for the bound.
                    end = mid - 1;
                } else {
                    // This means we found our upper bound.
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }

                    // Search on the right side for the bound.
                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var searchRange = function (nums, target) {
    const firstOccurrence = findBound(nums, target, true);
    if (firstOccurrence == -1) {
        return [-1, -1];
    }
    const lastOccurrence = findBound(nums, target, false);
    return [firstOccurrence, lastOccurrence];
    function findBound(nums, target, isFirst) {
        let N = nums.length;
        let begin = 0,
            end = N - 1;
        while (begin <= end) {
            let mid = Math.floor((begin + end) / 2);
            if (nums[mid] == target) {
                if (isFirst) {
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }
                    end = mid - 1;
                } else {
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }
                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        lower_bound = self.findBound(nums, target, True)
        if lower_bound == -1:
            return [-1, -1]

        upper_bound = self.findBound(nums, target, False)

        return [lower_bound, upper_bound]

    def findBound(self, nums: List[int], target: int, isFirst: bool) -> int:

        N = len(nums)
        begin, end = 0, N - 1
        while begin <= end:
            mid = int((begin + end) / 2)

            if nums[mid] == target:

                if isFirst:
                    # This means we found our lower bound.
                    if mid == begin or nums[mid - 1] < target:
                        return mid

                    # Search on the left side for the bound.
                    end = mid - 1
                else:

                    # This means we found our upper bound.
                    if mid == end or nums[mid + 1] > target:
                        return mid

                    # Search on the right side for the bound.
                    begin = mid + 1

            elif nums[mid] > target:
                end = mid - 1
            else:
                begin = mid + 1

        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function searchRange(nums: number[], target: number): number[] {
    const firstOccurrence = findBound(nums, target, true);
    if (firstOccurrence == -1) {
        return [-1, -1];
    }
    const lastOccurrence = findBound(nums, target, false);
    return [firstOccurrence, lastOccurrence];
    function findBound(
        nums: number[],
        target: number,
        isFirst: boolean,
    ): number {
        let N = nums.length;
        let begin = 0,
            end = N - 1;
        while (begin <= end) {
            let mid = Math.floor((begin + end) / 2);
            if (nums[mid] == target) {
                if (isFirst) {
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }
                    end = mid - 1;
                } else {
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }
                    begin = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }
}
```

</details>
