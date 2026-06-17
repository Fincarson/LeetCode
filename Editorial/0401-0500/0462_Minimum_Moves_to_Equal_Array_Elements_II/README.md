# 462. Minimum Moves to Equal Array Elements II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)  
`Array` `Math` `Sorting`

**Problem Link:** [LeetCode 462 - Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

## Problem

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

### Example 1

```text
Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
```

### Example 2

```text
Input: nums = [1,10,2,9]
Output: 16
```

## Constraints

- n == nums.length
- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Meeting Point](https://leetcode.com/problems/best-meeting-point/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Removing Minimum Number of Magic Beans](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Operations to Make All Array Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Cost to Make Array Equalindromic](https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Operations to Make Subarray Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-subarray-elements-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Operations to Make Elements Within K Subarrays Equal](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 462. Minimum Moves to Equal Array Elements II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Better Brute Force | Java |
| Using Sorting | Java |
| Using Median and Sorting | Java |
| Without Finding Median | Java |
| Using Quick-Select | Java |
| Using Median of Medians | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves2(int[] nums) {
        long ans = Long.MAX_VALUE;
        int minval = Integer.MAX_VALUE;
        int maxval = Integer.MIN_VALUE;
        for (int num : nums) {
            minval = Math.min(minval, num);
            maxval = Math.max(maxval, num);
        }
        for (int i = minval; i <= maxval; i++) {
            long sum = 0;
            for (int num : nums) {
                sum += Math.abs(num - i);
            }
            ans = Math.min(ans, sum);
        }
        return (int) ans;
    }
}
```

</details>

<br>

## Approach 2: Better Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves2(int[] nums) {
        long min = Integer.MAX_VALUE;
        for (int num : nums) {
            long sum = 0;
            for (int n : nums) {
                sum += Math.abs(n - num);
            }
            min = Math.min(min, sum);
        }
        return (int) min;
    }
}
```

</details>

<br>

## Approach 3: Using Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        long min = Long.MAX_VALUE, sum = 0, total = 0;
        for (int num : nums) {
            total += num;
        }
        for (int i = 0; i < nums.length; i++) {
            long ans = ((long) nums[i] * i - sum) + ((total - sum) - (long) nums[i] * (nums.length - i));
            System.out.println(nums[i] + " " + ans);
            min = Math.min(min, ans);
            sum += nums[i];
        }
        return (int) min;
    }
}
```

</details>

<br>

## Approach 4: Using Median and Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for (int num : nums) {
            sum += Math.abs(nums[nums.length / 2] - num);
        }
        return sum;
    }
}
```

</details>

<br>

## Approach 5: Without Finding Median

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minMoves2(int[] nums) {
        int l = 0, r = nums.length - 1, sum = 0;
        Arrays.sort(nums);
        while (l < r) {
            sum += nums[r] - nums[l];
            l++;
            r--;
        }
        return sum;
    }
}
```

</details>

<br>

## Approach 6: Using Quick-Select

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public void swap(int[] list, int i, int pivot_index) {
        int temp = list[i];
        list[i] = list[pivot_index];
        list[pivot_index] = temp;
    }
    public int partition(int[] list, int left, int right) {
        int pivotValue = list[right];
        int i = left;
        for (int j = left; j <= right; j++) {
            if (list[j] < pivotValue) {
                swap(list, i, j);
                i++;
            }
        }
        swap(list, right, i);
        return i;
    }
    int select(int[] list, int left, int right, int k) {
        if (left == right) {
            return list[left];
        }
        int pivotIndex = partition(list, left, right);
        if (k == pivotIndex) {
            return list[k];
        } else if (k < pivotIndex) {
            return select(list, left, pivotIndex - 1, k);
        } else {
            return select(list, pivotIndex + 1, right, k);
        }
    }
    public int minMoves2(int[] nums) {
        int sum = 0;
        int median = select(nums, 0, nums.length - 1, nums.length / 2);

        for (int num : nums) {
            sum += Math.abs(median - num);
        }
        return sum;
    }
}
```

</details>

<br>

## Approach 7: Using Median of Medians

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public void swap(int[] list, int i, int j) {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
    public int partition(int[] list, int left, int right, int val) {
        int i;
        for (i = left; i < right; i++) {
            if (list[i] == val) {
                break;
            }
        }
        swap(list, i, right);
        int pivotValue = list[right];
        int storeIndex = left;
        for (i = left; i <= right; i++) {
            if (list[i] < pivotValue) {
                swap(list, storeIndex, i);
                storeIndex++;
            }
        }
        swap(list, right, storeIndex);
        return storeIndex;
    }
    int findMedian(int arr[], int l, int len) {
        Arrays.sort(arr, l, l + len);
        return arr[l + len / 2];
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        if (k > 0 && k <= r - l + 1) {
            int n = r - l + 1, i;
            int median[] = new int[(n + 4) / 5];
            for (i = 0; i < n / 5; i++) {
                median[i] = findMedian(arr, l + i * 5, 5);
            }
            if (i * 5 < n) {
                median[i] = findMedian(arr, l + i * 5, n % 5);
                i++;
            }
            int medOfMed = (i == 1) ? median[i - 1]: kthSmallest(median, 0, i - 1, i / 2);

            int pos = partition(arr, l, r, medOfMed);
            if (pos - l == k - 1) {
                return arr[pos];
            }
            if (pos - l > k - 1) {
                return kthSmallest(arr, l, pos - 1, k);
            }
            return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
        }
        return Integer.MAX_VALUE;
    }
    public int minMoves2(int[] nums) {
        int sum = 0;
        int median = kthSmallest(nums, 0, nums.length - 1, nums.length / 2 + 1);
        for (int num : nums) {
            sum += Math.abs(median - num);
        }
        return sum;
    }
}
```

</details>
