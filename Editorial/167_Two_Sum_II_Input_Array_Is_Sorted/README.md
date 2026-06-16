# 167. Two Sum II - Input Array Is Sorted

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)  
`Array` `Two Pointers` `Binary Search`

**Problem Link:** [LeetCode 167 - Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

## Problem

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

### Example 1

```text
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

### Example 2

```text
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

### Example 3

```text
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

## Constraints

- 2 <= numbers.length <= 3 * 104
- -1000 <= numbers[i] <= 1000
- numbers is sorted in non-decreasing order.
- -1000 <= target <= 1000
- The tests are generated such that there is exactly one solution.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 167. Two Sum II - Input Array Is Sorted

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int low = 0;
    int high = numbersSize - 1;
    *returnSize = 2;
    while (low < high) {
        int sum = numbers[low] + numbers[high];

        if (sum == target) {
            int* result = malloc((*returnSize) * sizeof(int));
            result[0] = low + 1;
            result[1] = high + 1;
            return result;
        } else if (sum < target) {
            low++;
        } else {
            high--;
        }
    }
    // In case there is no solution, return [-1, -1].
    int* result = malloc((*returnSize) * sizeof(int));
    result[0] = -1;
    result[1] = -1;
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];

            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        // In case there is no solution, return {-1, -1}.
        return {-1, -1};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.Length - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return new int[] { low + 1, high + 1 };
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }

        // In case there is no solution, return [-1, -1].
        return new int[] { -1, -1 };
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func twoSum(numbers []int, target int) []int {
    low := 0
    high := len(numbers) - 1
    for low < high {
        sum := numbers[low] + numbers[high]

        if sum == target {
            return []int{low + 1, high + 1}
        } else if sum < target {
            low++
        } else {
            high--
        }
    }
    // In case there is no solution, return [-1, -1].
    return []int{-1, -1}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];

            if (sum == target) {
                return new int[] { low + 1, high + 1 };
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        // In case there is no solution, return {-1, -1}.
        return new int[] { -1, -1 };
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var twoSum = function (numbers, target) {
    let low = 0;
    let high = numbers.length - 1;
    while (low < high) {
        let sum = numbers[low] + numbers[high];

        if (sum == target) {
            return [low + 1, high + 1];
        } else if (sum < target) {
            low++;
        } else {
            high--;
        }
    }
    // In case there is no solution, return [-1, -1].
    return [-1, -1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        low = 0
        high = len(numbers) - 1
        while low < high:
            sum = numbers[low] + numbers[high]

            if sum == target:
                return [low + 1, high + 1]
            elif sum < target:
                low += 1
            else:
                high -= 1
        # In case there is no solution, return [-1, -1].
        return [-1, -1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function twoSum(numbers: number[], target: number): number[] {
    let low = 0;
    let high = numbers.length - 1;
    while (low < high) {
        let sum = numbers[low] + numbers[high];

        if (sum == target) {
            return [low + 1, high + 1];
        } else if (sum < target) {
            low++;
        } else {
            high--;
        }
    }
    // In case there is no solution, return [-1, -1].
    return [-1, -1];
}
```

</details>
