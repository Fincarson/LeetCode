# 215. Kth Largest Element in an Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/kth-largest-element-in-an-array/)  
`Array` `Divide and Conquer` `Sorting` `Heap (Priority Queue)` `Quickselect`

**Problem Link:** [LeetCode 215 - Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## Problem

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

### Example 1

```text
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

### Example 2

```text
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

## Constraints

- 1 <= k <= nums.length <= 105
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Kth Largest Integer in the Array](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [K Highest Ranked Items Within a Price Range](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 215. Kth Largest Element in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | C++, Java, Python3 |
| Min-Heap | C++, Java, Python3 |
| Quickselect | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        // Can't sort int[] in descending order in Java;
        // Sort ascending and then return the kth element from the end
        return nums[nums.length - k];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthLargest(self, nums, k):
        nums.sort(reverse=True)
        return nums[k - 1]
```

</details>

<br>

## Approach 2: Min-Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int num: nums) {
            heap.push(-num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        return -heap.top();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int num: nums) {
            heap.add(num);
            if (heap.size() > k) {
                heap.remove();
            }
        }
        
        return heap.peek();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthLargest(self, nums, k):
        heap = []
        for num in nums:
            heapq.heappush(heap, num)
            if len(heap) > k:
                heapq.heappop(heap)
        
        return heap[0]
```

</details>

<br>

## Approach 3: Quickselect

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
    
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        
        vector<int> left;
        vector<int> mid;
        vector<int> right;
        
        for (int num: nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        
        if (k <= left.size()) {
            return quickSelect(left, k);
        }
        
        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }
        
        return pivot;
        
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        List<Integer> list = new ArrayList<>();
        for (int num: nums) {
            list.add(num);
        }
        
        return quickSelect(list, k);
    }
    
    public int quickSelect(List<Integer> nums, int k) {
        int pivotIndex = new Random().nextInt(nums.size());
        int pivot = nums.get(pivotIndex);
        
        List<Integer> left = new ArrayList<>();
        List<Integer> mid = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        
        for (int num: nums) {
            if (num > pivot) {
                left.add(num);
            } else if (num < pivot) {
                right.add(num);
            } else {
                mid.add(num);
            }
        }
        
        if (k <= left.size()) {
            return quickSelect(left, k);
        }
        
        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }
        
        return pivot;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findKthLargest(self, nums, k):
        def quick_select(nums, k):
            pivot = random.choice(nums)
            left, mid, right = [], [], []

            for num in nums:
                if num > pivot:
                    left.append(num)
                elif num < pivot:
                    right.append(num)
                else:
                    mid.append(num)
            
            if k <= len(left):
                return quick_select(left, k)
            
            if len(left) + len(mid) < k:
                return quick_select(right, k - len(left) - len(mid))
            
            return pivot
        
        return quick_select(nums, k)
```

</details>

<br>

## Approach 4: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        
        for (int num: nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }
        
        vector<int> count(maxValue - minValue + 1);
        for (int num: nums) {
            count[num - minValue]++;
        }
        
        int remain = k;
        for (int num = count.size() - 1; num >= 0; num--) {
            remain -= count[num];
            if (remain <= 0) {
                return num + minValue;
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
    public int findKthLargest(int[] nums, int k) {
        int minValue = Integer.MAX_VALUE;
        int maxValue = Integer.MIN_VALUE;
        
        for (int num: nums) {
            minValue = Math.min(minValue, num);
            maxValue = Math.max(maxValue, num);
        }
        
        int[] count = new int[maxValue - minValue + 1];
        for (int num: nums) {
            count[num - minValue]++;
        }
        
        int remain = k;
        for (int num = count.length - 1; num >= 0; num--) {
            remain -= count[num];
            if (remain <= 0) {
                return num + minValue;
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
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_value = min(nums)
        max_value = max(nums)
        count = [0] * (max_value - min_value + 1)

        for num in nums:
            count[num - min_value] += 1
        
        remain = k
        for num in range(len(count) -1, -1, -1):
            remain -= count[num]
            if remain <= 0:
                return num + min_value

        return -1
```

</details>
