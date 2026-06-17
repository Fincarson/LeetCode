# 41. First Missing Positive

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/first-missing-positive/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 41 - First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

## Problem

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

### Example 1

```text
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

### Example 2

```text
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
```

### Example 3

```text
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
```

## Constraints

- 1 <= nums.length <= 105
- -231 <= nums[i] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Missing Number](https://leetcode.com/problems/missing-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Smallest Number in Infinite Set](https://leetcode.com/problems/smallest-number-in-infinite-set/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Integers to Choose From a Range I](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Smallest Missing Non-negative Integer After Operations](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Integers to Choose From a Range II](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Smallest Missing Integer Greater Than Sequential Prefix Sum](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 41. First Missing Positive

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Boolean Array | C, C++, C#, Java, JavaScript, Python3, TypeScript |
| Index as a Hash Key | C, C++, Java, JavaScript, Python3, TypeScript |
| Cycle Sort | C, C++, C#, Java, JavaScript, Python3, TypeScript |

## Approach 1: Boolean Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int firstMissingPositive(int* nums, int numsSize) {
    int n = numsSize;
    bool* seen = calloc(n + 1, sizeof(bool));  // Array for lookup
    // Mark the elements from nums in the lookup array
    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        if (num > 0 && num <= n) {
            seen[num] = true;
        }
    }
    // Iterate through integers 1 to n
    // return smallest missing positive integer
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            return i;
        }
    }
    // If seen contains all elements 1 to n
    // the smallest missing positive number is n + 1
    return n + 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, false);  // Array for lookup

        // Mark the elements from nums in the lookup array
        for (int num : nums) {
            if (num > 0 && num <= n) {
                seen[num] = true;
            }
        }

        // Iterate through integers 1 to n
        // return smallest missing positive integer
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                return i;
            }
        }

        // If seen contains all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int n = nums.Length;
        bool[] seen = new bool[n + 1];  // Array for lookup
        // Mark the elements from nums in the lookup array
        foreach (int num in nums) {
            if (num > 0 && num <= n) {
                seen[num] = true;
            }
        }

        // Iterate through integers 1 to n
        // return smallest missing positive integer
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                return i;
            }
        }

        // If seen contains all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean[] seen = new boolean[n + 1]; // Array for lookup

        // Mark the elements from nums in the lookup array
        for (int num : nums) {
            if (num > 0 && num <= n) {
                seen[num] = true;
            }
        }

        // Iterate through integers 1 to n
        // return smallest missing positive integer
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                return i;
            }
        }

        // If seen contains all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var firstMissingPositive = function (nums) {
    let n = nums.length;
    const seen = new Array(n + 1).fill(false); // Array for lookup
    // Mark the elements from nums in the lookup array
    for (const num of nums) {
        if (num > 0 && num <= n) {
            seen[num] = true;
        }
    }
    // Iterate through integers 1 to n
    // return smallest missing positive integer
    for (let i = 1; i <= n; i++) {
        if (!seen[i]) {
            return i;
        }
    }
    // If seen contains all elements 1 to n
    // the smallest missing positive number is n + 1
    return n + 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)
        seen = [False] * (n + 1)  # Array for lookup

        # Mark the elements from nums in the lookup array
        for num in nums:
            if 0 < num <= n:
                seen[num] = True

        # Iterate through integers 1 to n
        # return smallest missing positive integer
        for i in range(1, n + 1):
            if not seen[i]:
                return i

        # If seen contains all elements 1 to n
        # the smallest missing positive number is n + 1
        return n + 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function firstMissingPositive(nums: number[]): number {
    let n = nums.length;
    const seen: boolean[] = new Array(n + 1).fill(false); // Array for lookup
    // Mark the elements from nums in the lookup array
    for (const num of nums) {
        if (num > 0 && num <= n) {
            seen[num] = true;
        }
    }
    // Iterate through integers 1 to n
    // return smallest missing positive integer
    for (let i = 1; i <= n; i++) {
        if (!seen[i]) {
            return i;
        }
    }
    // If seen contains all elements 1 to n
    // the smallest missing positive number is n + 1
    return n + 1;
}
```

</details>

<br>

## Approach 2: Index as a Hash Key

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int firstMissingPositive(int* nums, int numsSize) {
    int n = numsSize;
    short contains1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            contains1 = 1;
        }
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 1;
        }
    }
    if (!contains1) return 1;
    for (int i = 0; i < n; i++) {
        int a = abs(nums[i]);
        if (a == n) {
            nums[0] = -abs(nums[0]);
        } else {
            nums[a] = -abs(nums[a]);
        }
    }
    for (int i = 1; i < n; i++) {
        if (nums[i] > 0) {
            return i;
        }
    }
    if (nums[0] > 0) return n;
    return n + 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool contains1 = false;

        // Replace negative numbers, zeros,
        // and numbers larger than n with 1s.
        // After this nums contains only positive numbers.
        for (int i = 0; i < n; i++) {
            // Check whether 1 is in the original array
            if (nums[i] == 1) {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        if (!contains1) return 1;

        // Mark whether integers 1 to n are in nums
        // Use index as a hash key and negative sign as a presence detector.
        for (int i = 0; i < n; i++) {
            int value = abs(nums[i]);
            if (value == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[value] = -abs(nums[value]);
            }
        }

        // First positive in nums is smallest missing positive integer
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }

        // nums[0] stores whether n is in nums
        if (nums[0] > 0) {
            return n;
        }

        // If nums contained all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean contains1 = false;

        // Replace negative numbers, zeros,
        // and numbers larger than n with 1s.
        // After this nums contains only positive numbers.
        for (int i = 0; i < n; i++) {
            // Check whether 1 is in the original array
            if (nums[i] == 1) {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        if (!contains1) return 1;

        // Mark whether integers 1 to n are in nums
        // Use index as a hash key and negative sign as a presence detector.
        for (int i = 0; i < n; i++) {
            int value = Math.abs(nums[i]);
            if (value == n) {
                nums[0] = -Math.abs(nums[0]);
            } else {
                nums[value] = -Math.abs(nums[value]);
            }
        }

        // First positive in nums is smallest missing positive integer
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }

        // nums[0] stores whether n is in nums
        if (nums[0] > 0) {
            return n;
        }

        // If nums contains all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var firstMissingPositive = function (nums) {
    let contains1 = false;
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) {
            contains1 = true;
        }
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 1;
        }
    }
    if (!contains1) return 1;
    for (let i = 0; i < n; i++) {
        let value = Math.abs(nums[i]);
        if (value === n) {
            nums[0] = -Math.abs(nums[0]);
        } else {
            nums[value] = -Math.abs(nums[value]);
        }
    }
    for (let i = 1; i < n; i++) {
        if (nums[i] > 0) return i;
    }
    if (nums[0] > 0) return n;
    return n + 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        contains_1 = False

        # Replace negative numbers, zeros,
        # and numbers larger than n with 1s.
        # After this nums contains only positive numbers.
        for i in range(n):
            # Check whether 1 is in the original array
            if nums[i] == 1:
                contains_1 = True
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1

        if not contains_1:
            return 1

        # Mark whether integers 1 to n are in nums
        # Use index as a hash key and negative sign as a presence detector.
        for i in range(n):
            value = abs(nums[i])
            # If you meet number a in the array - change the sign of a-th element.
            # Be careful with duplicates : do it only once.
            if value == n:
                nums[0] = -abs(nums[0])
            else:
                nums[value] = -abs(nums[value])

        # First positive in nums is smallest missing positive integer
        for i in range(1, n):
            if nums[i] > 0:
                return i

        # nums[0] stores whether n is in nums
        if nums[0] > 0:
            return n

        # If nums contained all elements 1 to n
        # the smallest missing positive number is n + 1
        return n + 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function firstMissingPositive(nums: number[]): number {
    let contains1 = false;
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) {
            contains1 = true;
        }
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 1;
        }
    }
    if (!contains1) return 1;
    for (let i = 0; i < n; i++) {
        let value = Math.abs(nums[i]);
        if (value === n) {
            nums[0] = -Math.abs(nums[0]);
        } else {
            nums[value] = -Math.abs(nums[value]);
        }
    }
    for (let i = 1; i < n; i++) {
        if (nums[i] > 0) return i;
    }
    if (nums[0] > 0) return n;
    return n + 1;
}
```

</details>

<br>

## Approach 3: Cycle Sort

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int firstMissingPositive(int* nums, int numsSize) {
    int n = numsSize;
    // Use cycle sort to place positive elements smaller than n
    // at the correct index
    int i = 0;
    while (i < n) {
        int correctIdx = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx]) {
            int temp = nums[i];
            nums[i] = nums[correctIdx];
            nums[correctIdx] = temp;
        } else {
            i++;
        }
    }
    // Iterate through nums
    // return smallest missing positive integer
    for (i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    // If all elements are at the correct index
    // the smallest missing positive number is n + 1
    return n + 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Use cycle sort to place positive elements smaller than n
        // at the correct index
        int i = 0;
        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        // Iterate through nums
        // return smallest missing positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all elements are at the correct index
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int n = nums.Length;
        // Use cycle sort to place positive elements smaller than n
        // at the correct index
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx]) {
                Swap(nums, i, correctIdx);
            } else {
                i++;
            }
        }

        // Iterate through nums
        // return smallest missing positive integer
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all elements are at the correct index
        // the smallest missing positive number is n + 1
        return n + 1;
    }

    // Swaps two elements in nums
    private static void Swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // Use cycle sort to place positive elements smaller than n
        // at the correct index
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx]) {
                swap(nums, i, correctIdx);
            } else {
                i++;
            }
        }

        // Iterate through nums
        // return smallest missing positive integer
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all elements are at the correct index
        // the smallest missing positive number is n + 1
        return n + 1;
    }

    // Swaps two elements in nums
    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var firstMissingPositive = function (nums) {
    let n = nums.length;
    // Use cycle sort to place positive elements smaller than n
    // at the correct index
    let i = 0;
    while (i < n) {
        let correctIdx = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx]) {
            [nums[i], nums[correctIdx]] = [nums[correctIdx], nums[i]];
        } else {
            i++;
        }
    }
    // Iterate through nums
    // return smallest missing positive integer
    for (i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    // If all elements are at the correct index
    // the smallest missing positive number is n + 1
    return n + 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)

        # Use cycle sort to place positive elements smaller than n
        # at the correct index
        i = 0
        while i < n:
            correct_idx = nums[i] - 1
            if 0 < nums[i] <= n and nums[i] != nums[correct_idx]:
                # swap
                nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
            else:
                i += 1

        # Iterate through nums
        # return smallest missing positive integer
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        # If all elements are at the correct index
        # the smallest missing positive number is n + 1
        return n + 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function firstMissingPositive(nums: number[]): number {
    let n = nums.length;
    // Use cycle sort to place positive elements smaller than n
    // at the correct index
    let i = 0;
    while (i < n) {
        let correctIdx = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx]) {
            [nums[i], nums[correctIdx]] = [nums[correctIdx], nums[i]];
        } else {
            i++;
        }
    }
    // Iterate through nums
    // return smallest missing positive integer
    for (i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    // If all elements are at the correct index
    // the smallest missing positive number is n + 1
    return n + 1;
}
```

</details>
