# 1874. Minimize Product Sum of Two Arrays

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimize-product-sum-of-two-arrays/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1874 - Minimize Product Sum of Two Arrays](https://leetcode.com/problems/minimize-product-sum-of-two-arrays/)

## Problem

The product sum of two equal-length arrays a and b is equal to the sum of a[i] * b[i] for all 0 <= i < a.length (0-indexed).

- For example, if a = [1,2,3,4] and b = [5,2,3,1], the product sum would be 1*5 + 2*2 + 3*3 + 4*1 = 22.

Given two arrays nums1 and nums2 of length n, return the minimum product sum if you are allowed to rearrange the order of the elements in nums1.

### Example 1

```text
Input: nums1 = [5,3,4,2], nums2 = [4,2,2,5]
Output: 40
Explanation: We can rearrange nums1 to become [3,5,4,2]. The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.
```

### Example 2

```text
Input: nums1 = [2,1,4,5,7], nums2 = [3,2,4,8,6]
Output: 65
Explanation: We can rearrange nums1 to become [5,7,4,1,2]. The product sum of [5,7,4,1,2] and [3,2,4,8,6] is 5*3 + 7*2 + 4*4 + 1*8 + 2*6 = 65.
```

## Constraints

- n == nums1.length == nums2.length
- 1 <= n <= 105
- 1 <= nums1[i], nums2[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Choose Numbers From Two Arrays in Range](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1874. Minimize Product Sum of Two Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort both arrays | C++, Java, Python3 |
| PriorityQueue | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |

## Approach 1: Sort both arrays

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        // Sort nums1 in ascending order, and nums2 in
        // descending order.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>());
        
        // Initialize sum as 0.
        int ans = 0;

        // Iterate over two sorted arrays and calculate the 
        // cumulative product sum.
        for (int i = 0; i < nums1.size(); ++i) {
            ans += nums1[i] * nums2[i];
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
    public int minProductSum(int[] nums1, int[] nums2) {
        // Sort nums1 and nums2 in ascending order.
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        // Initialize sum as 0.
        int ans = 0;
        int n = nums2.length;
        
        // Iterate over two sorted arrays and calculate the 
        // cumulative product sum. 
        for (int i = 0; i < n; ++i) {
            // Since we also sort nums2 in ascending order, 
            // we need to iterate over nums2 in reverse order.
            ans += nums1[i] * nums2[n - 1 - i];
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
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        # Sort nums1 in ascending order, and nums2 in
        # descending order.
        nums1.sort()
        nums2.sort(reverse=True)
        
        # Initialize sum as 0.
        ans = 0
        
        # Iterate over two sorted arrays and calculate the 
        # cumulative product sum. 
        for num1, num2 in zip(nums1, nums2):
            ans += num1 * num2

        return ans
```

</details>

<br>

## Approach 2: PriorityQueue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        // Sort nums1 in ascending order.
        sort(nums1.begin(), nums1.end());
        
        // Initialize a PriorityQueue pq as a Max-Heap, and add 
        // every element of nums2 to pq.
        priority_queue<int, vector<int>> pq;      
        for (int num : nums2)
            pq.push(num);
        
        // Initialize the product sum as 0 before the iteration.
        int ans = 0;

        // During the iteration 
        for (int idx = 0; idx < nums2.size(); ++idx) {
            // Add the product of nums[idx] and the maximum element
            // left in pq, remove this element from pq.
            ans += nums1[idx] * pq.top();
            pq.pop();
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
    public int minProductSum(int[] nums1, int[] nums2) {
        // Sort nums1 in ascending order.
        Arrays.sort(nums1);

        // Initialize a PriorityQueue pq as a Max-Heap, and add 
        // every element of nums2 to pq.
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());    
        for (int num : nums2) {
            pq.add(num);
        }
        
        // Initialize the product sum as 0 before the iteration.
        int ans = 0;
        
        // During the iteration
        for (int idx = 0; idx < nums2.length; ++idx) {
            // Add the product of nums[idx] and the maximum element
            // left in pq, remove this element from pq.
            ans += nums1[idx] * pq.poll();
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
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        # Sort nums1 in ascending order.
        nums1.sort()

        # Initialize a PriorityQueue pq as a Max-Heap, and add 
        # every element of nums2 to pq. 
        pq = [-num for num in nums2]       
        heapq.heapify(pq)
        
        # Initialize the product sum as 0 before the iteration.
        ans = 0

        # During the iteration
        for idx in range(len(nums2)):  
            # Add the product of nums[idx] and the maximum element
            # left in pq, remove this element from pq
            ans += nums1[idx] * (-heapq.heappop(pq))

        return ans
```

</details>

<br>

## Approach 3: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        // Initialize counter1 and counter2.
        vector<int> counter1(101), counter2(101);

        // Record the number of occurrence of elements in nums1 and nums2.
        for (int num : nums1)
            counter1[num]++;
        for (int num : nums2)
            counter2[num]++;
        
        // Initialize two pointers p1 = 1, p2 = 100.
        // Stands for counter1[1] and counter2[100], respectively.
        int p1 = 1, p2 = 100, ans = 0;
        int occ;
        
        // While the two pointers are in the valid range.
        while (p1 < 101 && p2 > 0) {
            // If counter1[p1] == 0, meaning there is no element equals p1 in counter1,
            // thus we shall increment p1 by 1.
            while (p1 < 101 && counter1[p1] == 0) 
                p1 += 1;

            // If counter2[p2] == 0, meaning there is no element equals p2 in counter2,
            // thus we shall decrement p2 by 1.
            while (p2 > 0 && counter2[p2] == 0)
                p2 -= 1;

            // If any of the pointer goes beyond the border, we have finished the 
            // iteration, break the loop.
            if (p1 == 101 || p2 == 0)
                break;
            
            // Otherwise, we can make at most min(counter1[p1], counter2[p2]) 
            // pairs {p1, p2} from nums1 and nums2, let's call it occ. 
            // Each pair has product of p1 * p2, thus the cumulative sum is 
            // incresed by occ * p1 * p2. Update counter1[p1] and counter2[p2].
            occ = min(counter1[p1], counter2[p2]);
            ans += occ * p1 * p2;
            counter1[p1] -= occ;
            counter2[p2] -= occ;
        }
        
        // Once we finish the loop, return ans as the product sum.
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minProductSum(int[] nums1, int[] nums2) {
        // Initialize counter1 and counter2.
        int[] counter1 = new int[101], counter2 = new int[101];

        // Record the number of occurrence of elements in nums1 and nums2.
        for (int num : nums1)
            counter1[num]++;
        for (int num : nums2)
            counter2[num]++;
        
        // Initialize two pointers p1 = 1, p2 = 100.
        // Stands for counter1[1] and counter2[100], respectively.
        int p1 = 0, p2 = 100, ans = 0;
        int occ;
        
        // While the two pointers are in the valid range.
        while (p1 < 101 && p2 > 0) {
            // If counter1[p1] == 0, meaning there is no element equals p1 in counter1,
            // thus we shall increment p1 by 1.
            while (p1 < 101 && counter1[p1] == 0) 
                p1 += 1;

            // If counter2[p2] == 0, meaning there is no element equals p2 in counter2,
            // thus we shall decrement p2 by 1.
            while (p2 > 0 && counter2[p2] == 0)
                p2 -= 1;

            // If any of the pointer goes beyond the border, we have finished the 
            // iteration, break the loop.
            if (p1 == 101 || p2 == 0)
                break;

            // Otherwise, we can make at most min(counter1[p1], counter2[p2]) 
            // pairs {p1, p2} from nums1 and nums2, let's call it occ. 
            // Each pair has product of p1 * p2, thus the cumulative sum is 
            // incresed by occ * p1 * p2. Update counter1[p1] and counter2[p2].
            occ = Math.min(counter1[p1], counter2[p2]);
            ans += occ * p1 * p2;
            counter1[p1] -= occ;
            counter2[p2] -= occ;
        }

        // Once we finish the loop, return ans as the product sum.
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        # Initialize counter1 and counter2.
        counter1, counter2 = [0] * 101, [0] * 101

        # Record the number of occurrence of elements in nums1 and nums2.
        for num in nums1:
            counter1[num] += 1
        for num in nums2:
            counter2[num] += 1
        
        # Initialize two pointers p1 = 1, p2 = 100.
        # Stands for counter1[1] and counter2[100], respectively.
        p1, p2 = 1, 100
        ans = 0
        
        # While the two pointers are in the valid range.
        while p1 <= 100 and p2 > 0:

            # If counter1[p1] == 0, meaning there is no element equals p1 in counter1,
            # thus we shall increment p1 by 1.
            while p1 <= 100 and counter1[p1] == 0:
                p1 += 1

            # If counter2[p2] == 0, meaning there is no element equals p2 in counter2,
            # thus we shall decrement p2 by 1.
            while p2 > 0 and counter2[p2] == 0:
                p2 -= 1

            # If any of the pointer goes beyond the border, we have finished the 
            # iteration, break the loop.
            if p1 == 101 or p2 == 0:
                break

            # Otherwise, we can make at most min(counter1[p1], counter2[p2]) 
            # pairs {p1, p2} from nums1 and nums2, let's call it occ. 
            # Each pair has product of p1 * p2, thus the cumulative sum is 
            # incresed by occ * p1 * p2. Update counter1[p1] and counter2[p2].
            occ = min(counter1[p1], counter2[p2])
            ans += occ * p1 * p2
            counter1[p1] -= occ
            counter2[p2] -= occ
        
        # Once we finish the loop, return ans as the product sum.
        return ans
```

</details>
