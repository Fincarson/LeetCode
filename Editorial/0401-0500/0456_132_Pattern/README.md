# 456. 132 Pattern

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/132-pattern/)  
`Array` `Binary Search` `Stack` `Monotonic Stack` `Ordered Set`

**Problem Link:** [LeetCode 456 - 132 Pattern](https://leetcode.com/problems/132-pattern/)

## Problem

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

### Example 1

```text
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
```

### Example 2

```text
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
```

### Example 3

```text
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
```

## Constraints

- n == nums.length
- 1 <= n <= 2 * 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 456. 132 Pattern

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Better Brute Force | C++, Java, Python3 |
| Searching Intervals | C++, Java, Python3 |
| Stack | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |
| Using Array as a Stack | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        for (size_t i = 0; i < nums.size() - 2; i++) {
            for (size_t j = i + 1; j < nums.size() - 1; j++) {
                for (size_t k = j + 1; k < nums.size(); k++) {
                    if (nums[k] > nums[i] and nums[j] > nums[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean find132pattern(int[] nums) {
        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i + 1; j < nums.length - 1; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[k] > nums[i] && nums[j] > nums[k]) return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                for k in range(j + 1, len(nums)):
                    if nums[i] < nums[k] < nums[j]:
                        return True
        return False
```

</details>

<br>

## Approach 2: Better Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min_i = INT_MAX;
        for (size_t j = 0; j < nums.size() - 1; j++) {
            min_i = min(min_i, nums[j]);
            for (size_t k = j + 1; k < nums.size(); k++) {
                if (nums[k] < nums[j] and min_i < nums[k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean find132pattern(int[] nums) {
        int min_i = Integer.MAX_VALUE;
        for (int j = 0; j < nums.length - 1; j++) {
            min_i = Math.min(min_i, nums[j]);
            for (int k = j + 1; k < nums.length; k++) {
                if (nums[k] < nums[j] && min_i < nums[k]) return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        min_i = inf
        for j in range(len(nums) - 1):
            min_i = min(min_i, nums[j])
            for k in range(j + 1, len(nums)):
                if min_i < nums[k] < nums[j]:
                    return True
        return False
```

</details>

<br>

## Approach 3: Searching Intervals

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<pair<int, int>> intervals;
        size_t min_point_after_last_peak_index = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            // if we encounter a falling edge, then element i - 1 is a peak
            if (nums[i] < nums[i - 1]) {
                // make sure the peak occurs after the rising edge's minimum
                if (min_point_after_last_peak_index < i - 1) {
                    // nums[min_point_after_last_peak_index...(i-1)] is a valid
                    // rising peak
                    intervals.push_back(
                        {nums[min_point_after_last_peak_index], nums[i - 1]});
                }
                // the current element is the minimum for the next rising peak
                min_point_after_last_peak_index = i;
            }
            for (auto interval : intervals) {
                if (nums[i] > interval.first and nums[i] < interval.second) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean find132pattern(int[] nums) {
        List<int[]> intervals = new ArrayList<>();
        int i = 1, s = 0;
        while (i < nums.length) {
            if (nums[i] < nums[i - 1]) {
                if (s < i - 1) intervals.add(
                    new int[] { nums[s], nums[i - 1] }
                );
                s = i;
            }
            for (int[] a : intervals) if (
                nums[i] > a[0] && nums[i] < a[1]
            ) return true;
            i++;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        intervals = []
        i = 1
        min_point_after_last_peak_index = 0
        for i in range(len(nums)):
            # if we encounter a falling edge, then element i - 1 is a peak
            if nums[i] < nums[i - 1]:
                # make sure the peak occurs after the rising edge's minimum
                if min_point_after_last_peak_index < i - 1:
                    # nums[min_point_after_last_peak_index...(i-1)] is a valid rising peak
                    intervals.append(
                        (nums[min_point_after_last_peak_index], nums[i - 1])
                    )
                # the current element is the minimum for the next rising peak
                min_point_after_last_peak_index = i
            for interval in intervals:
                if interval[0] < nums[i] < interval[1]:
                    return True
        return False
```

</details>

<br>

## Approach 4: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        stack<int> stk;
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            min_array[i] = min(min_array[i - 1], nums[i]);
        }
        for (size_t j = nums.size() - 1; j > 0; j--) {
            if (nums[j] <= min_array[j]) {
                continue;
            }
            while (!stk.empty() and stk.top() <= min_array[j]) {
                stk.pop();
            }
            if (!stk.empty() and stk.top() < nums[j]) {
                return true;
            }
            stk.push(nums[j]);
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean find132pattern(int[] nums) {
        if (nums.length < 3) return false;
        Stack<Integer> stack = new Stack<>();
        int[] min = new int[nums.length];
        min[0] = nums[0];
        for (int i = 1; i < nums.length; i++) min[i] = Math.min(
            min[i - 1],
            nums[i]
        );
        for (int j = nums.length - 1; j >= 0; j--) {
            if (nums[j] > min[j]) {
                while (!stack.isEmpty() && stack.peek() <= min[j]) stack.pop();
                if (!stack.isEmpty() && stack.peek() < nums[j]) return true;
                stack.push(nums[j]);
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        stack = []
        min_array = [-1] * len(nums)
        min_array[0] = nums[0]
        for i in range(1, len(nums)):
            min_array[i] = min(min_array[i - 1], nums[i])

        for j in range(len(nums) - 1, -1, -1):
            if nums[j] <= min_array[j]:
                continue
            while stack and stack[-1] <= min_array[j]:
                stack.pop()
            if stack and stack[-1] < nums[j]:
                return True
            stack.append(nums[j])
        return False
```

</details>

<br>

## Approach 5: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            min_array[i] = min(min_array[i - 1], nums[i]);
        }
        int k = nums.size();
        for (size_t j = nums.size() - 1; j > 0; j--) {
            if (nums[j] <= min_array[j]) {
                continue;
            }
            auto it =
                lower_bound(nums.begin() + k, nums.end(), min_array[j] + 1);
            k = it - nums.begin();
            if (k < nums.size() and nums[k] < nums[j]) {
                return true;
            }
            nums[--k] = nums[j];
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean find132pattern(int[] nums) {
        if (nums.length < 3) return false;
        int[] min = new int[nums.length];
        min[0] = nums[0];
        for (int i = 1; i < nums.length; i++) min[i] = Math.min(
            min[i - 1],
            nums[i]
        );
        for (int j = nums.length - 1, k = nums.length; j >= 0; j--) {
            if (nums[j] > min[j]) {
                k = Arrays.binarySearch(nums, k, nums.length, min[j] + 1);
                if (k < 0) k = -1 - k;
                if (k < nums.length && nums[k] < nums[j]) return true;
                nums[--k] = nums[j];
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        min_array = [-1] * len(nums)
        min_array[0] = nums[0]
        for i in range(1, len(nums)):
            min_array[i] = min(min_array[i - 1], nums[i])

        k = len(nums)
        for j in range(len(nums) - 1, -1, -1):
            if nums[j] <= min_array[j]:
                continue
            k = bisect_left(nums, min_array[j] + 1, k, len(nums))
            if k < len(nums) and nums[k] < nums[j]:
                return True
            k -= 1
            nums[k] = nums[j]
        return False
```

</details>

<br>

## Approach 6: Using Array as a Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            min_array[i] = min(min_array[i - 1], nums[i]);
        }

        for (size_t j = nums.size() - 1, k = nums.size(); j > 0; j--) {
            if (nums[j] <= min_array[j]) {
                continue;
            }
            while (k < nums.size() and nums[k] <= min_array[j]) {
                k++;
            }
            if (k < nums.size() and nums[k] < nums[j]) {
                return true;
            }
            nums[--k] = nums[j];
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean find132pattern(int[] nums) {
        if (nums.length < 3) return false;
        int[] min = new int[nums.length];
        min[0] = nums[0];
        for (int i = 1; i < nums.length; i++) min[i] = Math.min(
            min[i - 1],
            nums[i]
        );
        for (int j = nums.length - 1, k = nums.length; j >= 0; j--) {
            if (nums[j] > min[j]) {
                while (k < nums.length && nums[k] <= min[j]) k++;
                if (k < nums.length && nums[k] < nums[j]) return true;
                nums[--k] = nums[j];
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        min_array = [-1] * len(nums)
        min_array[0] = nums[0]
        for i in range(1, len(nums)):
            min_array[i] = min(min_array[i - 1], nums[i])

        k = len(nums)
        for j in range(len(nums) - 1, -1, -1):
            if nums[j] <= min_array[j]:
                continue
            while k < len(nums) and nums[k] <= min_array[j]:
                k += 1
            if k < len(nums) and nums[k] < nums[j]:
                return True
            k -= 1
            nums[k] = nums[j]
        return False
```

</details>
