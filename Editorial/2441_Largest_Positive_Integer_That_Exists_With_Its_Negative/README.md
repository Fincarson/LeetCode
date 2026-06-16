# 2441. Largest Positive Integer That Exists With Its Negative

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/)  
`Array` `Hash Table` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 2441 - Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/)

## Problem

Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

### Example 1

```text
Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
```

### Example 2

```text
Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
```

### Example 3

```text
Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
```

## Constraints

- 1 <= nums.length <= 1000
- -1000 <= nums[i] <= 1000
- nums[i] != 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2441. Largest Positive Integer That Exists With Its Negative

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |
| Two Pass Hash Set | C++, Java, Python3 |
| One Pass Hash Set | C++, Java, Python3 |
| One Pass Bitset | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        
        for (int i : nums) {
            for (int j : nums) {
                // If there exists a number j such that i is the negative of j
                if (i == -j) {
                    // Update the answer to the maximum of current ans and absolute value of i
                    ans = max(ans, abs(i));
                }
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMaxK(int[] nums) {
        int ans = -1;
        
        for (int i : nums) {
            for (int j : nums) {
                // If there exists a number j such that i is the negative of j
                if (i == -j) {
                    // Update the answer to the maximum of current ans and absolute value of i
                    ans = Math.max(ans, Math.abs(i));
                }
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        ans = -1
        
        for i in nums:
            for j in nums:
                # If there exists a number j such that i is the negative of j
                if i == -j:
                    # Update the answer to the maximum of current ans and absolute value of i
                    ans = max(ans, abs(i))

        return ans
```

</details>

<br>

## Approach 2: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // Sort the input array in ascending order
        sort(begin(nums), end(nums));

        int lo = 0;
        int hi = size(nums) - 1;
        
        while (lo < hi) {

            // If the negation of the element at lo is equal to the element at hi
            if (-nums[lo] == nums[hi]) {
                return nums[hi];
            } 
            
            // If the negation of element at lo is greater than element at hi
            else if (-nums[lo] > nums[hi]) { 
                ++lo;
            }
            
            // If the negation of element at lo is smaller than element at hi
            else { 
                --hi;
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMaxK(int[] nums) {
        // Sort the input array in ascending order
        Arrays.sort(nums);

        int lo = 0;
        int hi = nums.length - 1;
        while (lo < hi) {
            
            // If the negation of the element at lo is equal to the element at hi
            if (-nums[lo] == nums[hi]) {
                return nums[hi];
            }

            // If the negation of element at lo is greater than element at hi
            else if (-nums[lo] > nums[hi]) { 
                ++lo;
            } 
            
            // If the negation of element at lo is smaller than element at hi
            else {
                --hi; 
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        # Sort the input list in ascending order
        nums.sort()

        lo = 0
        hi = len(nums) - 1

        while lo < hi:

            # If the negation of the element at lo is equal to the element at hi
            if -nums[lo] == nums[hi]:
                return nums[hi]

            # If the negation of element at lo is greater than element at hi
            elif -nums[lo] > nums[hi]: 
                lo += 1

            # If the negation of element at lo is smaller than element at hi
            else:
                hi -= 1

        return -1
```

</details>

<br>

## Approach 3: Two Pass Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // Initialize an unordered set to store negative numbers
        unordered_set<int> neg;
        
        // Loop through the numbers and insert negative numbers into the set
        for (int num : nums) {
            if (num < 0)
                neg.insert(num);
        }
        
        int ans = -1;
        
        for (int num : nums) {
            // If current number is greater than ans and its negation exists in the set
            if (num > ans && neg.contains(-num))
                ans = num;
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMaxK(int[] nums) {
        // Initialize a HashSet to store negative numbers
        Set<Integer> neg = new HashSet<>();
        
        // Loop through the numbers and insert negative numbers into the set
        for (int num : nums) {
            if (num < 0)
                neg.add(num);
        }
        
        int ans = -1;
        
        for (int num : nums) {
            // If current number is greater than ans and its negation exists in the set
            if (num > ans && neg.contains(-num))
                ans = num;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        # Initialize a set to store negative numbers
        neg = set()
        
        # Loop through the numbers and insert negative numbers into the set
        for num in nums:
            if num < 0:
                neg.add(num)
        
        ans = -1
        
        for num in nums:
            # If current number is greater than ans and its negation exists in the set
            if num > ans and -num in neg:
                ans = num
        
        return ans
```

</details>

<br>

## Approach 4: One Pass Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        // Set to store seen elements
        unordered_set<int> seen; 

        for (int num : nums) { 
            const int abs_num = abs(num);

            // If the absolute value is greater than current max and its negation is in the set
            if (abs_num > ans && seen.contains(-num)) 
                ans = abs_num;
            seen.insert(num); // Insert current element into the set
        }
        return ans; 
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMaxK(int[] nums) {
        int ans = -1; 

        // A set to store seen numbers
        Set<Integer> seen = new HashSet<>();

        for (int num : nums) { 
            int absNum = Math.abs(num);

            // If the absolute value is greater than the current maximum and its negation is seen
            if (absNum > ans && seen.contains(-num))
                ans = absNum; 
            seen.add(num); // Insert the current number into the set
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        ans = -1

        # A set to store seen numbers
        seen = set()

        for num in nums:
            abs_num = abs(num)

            # If the absolute value is greater than the current maximum and its negation is seen
            if abs_num > ans and -num in seen:
                ans = abs_num
            seen.add(num)  # Insert the current number into the set

        return ans
```

</details>

<br>

## Approach 5: One Pass Bitset

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;

        // Initialize a bitset to keep track of seen numbers
        bitset<2048> seen;

        for (int num : nums) {
            const int abs_num = abs(num);

            // If the absolute value is greater than the current answer
            // and its negation was seen before,
            // update the answer
            if (abs_num > ans && seen[-num + 1024])
                ans = abs_num;
            // Mark the current number as seen
            seen[num + 1024] = true;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMaxK(int[] nums) {
        int ans = -1;

        // Initialize a bitset to keep track of seen numbers
        BitSet seen = new BitSet(2048);

        for (int num : nums) {
            int absNum = Math.abs(num);

            // If the absolute value is greater than the current answer
            // and its negation was seen before,
            // update the answer
            if (absNum > ans && seen.get(-num + 1024))
                ans = absNum;
            // Mark the current number as seen
            seen.set(num + 1024);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        ans = -1

        # Initialize a set to keep track of seen numbers
        seen = set()

        for num in nums:
            abs_num = abs(num)

            # If the absolute value is greater than the current answer
            # and its negation was seen before,
            # update the answer
            if abs_num > ans and -num + 1024 in seen:
                ans = abs_num
            # Mark the current number as seen
            seen.add(num + 1024)

        return ans
```

</details>
