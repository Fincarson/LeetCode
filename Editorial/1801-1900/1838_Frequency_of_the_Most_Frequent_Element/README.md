# 1838. Frequency of the Most Frequent Element

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)  
`Array` `Binary Search` `Greedy` `Sliding Window` `Sorting` `Prefix Sum`

**Problem Link:** [LeetCode 1838 - Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

## Problem

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

### Example 1

```text
Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
```

### Example 2

```text
Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
```

### Example 3

```text
Input: nums = [3,9,6], k = 2
Output: 1
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Apply Operations to Maximize Frequency Score](https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Frequency of an Element After Performing Operations I](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Frequency of an Element After Performing Operations II](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Difference Between Even and Odd Frequency II](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1838. Frequency of the Most Frequent Element

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | C++, Java, Python3 |
| Advanced Sliding Window | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
            
            ans = max(ans, right - left + 1);
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
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int left = 0;
        int ans = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.length; right++) {
            long target = nums[right];
            curr += target;
            
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
            
            ans = Math.max(ans, right - left + 1);
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
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        left = 0
        ans = 0
        curr = 0
        
        for right in range(len(nums)):
            target = nums[right]
            curr += target
            
            while (right - left + 1) * target - curr > k:
                curr -= nums[left]
                left += 1
            
            ans = max(ans, right - left + 1)

        return ans
```

</details>

<br>

## Approach 2: Advanced Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
        }
        
        return nums.size() - left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.length; right++) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
        }
        
        return nums.length - left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        left = 0
        curr = 0
        
        for right in range(len(nums)):
            target = nums[right]
            curr += target
            
            if (right - left + 1) * target - curr > k:
                curr -= nums[left]
                left += 1

        return len(nums) - left
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int check(int i, int k, vector<int>& nums, vector<long>& prefix) {
        int target = nums[i];
        int left = 0;
        int right = i;
        int best = i;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            long count = i - mid + 1;
            long finalSum = count * target;
            int originalSum = prefix[i] - prefix[mid] + nums[mid];
            int operationsRequired = finalSum - originalSum;
            
            if (operationsRequired > k) {
                left = mid + 1;
            } else {
                best = mid;
                right = mid - 1;
            }
        }
        
        return i - best + 1;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<long> prefix;
        prefix.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix.back());
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, check(i, k, nums, prefix));
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
    public int check(int i, int k, int[] nums, long[] prefix) {
        int target = nums[i];
        int left = 0;
        int right = i;
        int best = i;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            long count = i - mid + 1;
            long finalSum = count * target;
            long originalSum = prefix[i] - prefix[mid] + nums[mid];
            long operationsRequired = finalSum - originalSum;
            
            if (operationsRequired > k) {
                left = mid + 1;
            } else {
                best = mid;
                right = mid - 1;
            }
        }
        
        return i - best + 1;
    }
    
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        long[] prefix = new long[nums.length];
        prefix[0] = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans = Math.max(ans, check(i, k, nums, prefix));
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
    def maxFrequency(self, nums: List[int], k: int) -> int:
        def check(i):
            target = nums[i]
            left = 0
            right = i
            best = i
            
            while left <= right:
                mid = (left + right) // 2
                count = i - mid + 1
                final_sum = count * target
                original_sum = prefix[i] - prefix[mid] + nums[mid]
                operations_required = final_sum - original_sum

                if operations_required > k:
                    left = mid + 1
                else:
                    best = mid
                    right = mid - 1
                    
            return i - best + 1
        
        nums.sort()
        prefix = [nums[0]]
        
        for i in range(1, len(nums)):
            prefix.append(nums[i] + prefix[-1])
        
        ans = 0
        for i in range(len(nums)):
            ans = max(ans, check(i))
            
        return ans
```

</details>
