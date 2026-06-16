# 1793. Maximum Score of a Good Subarray

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-score-of-a-good-subarray/)  
`Array` `Two Pointers` `Binary Search` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 1793 - Maximum Score of a Good Subarray](https://leetcode.com/problems/maximum-score-of-a-good-subarray/)

## Problem

You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

### Example 1

```text
Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.
```

### Example 2

```text
Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 2 * 104
- 0 <= k < nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1793. Maximum Score of a Good Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Monotonic Stack | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = solve(nums, k);
        reverse(nums.begin(), nums.end());
        return max(ans, solve(nums, nums.size() - k - 1));
    }
    
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(k, 0);
        int currMin = INT_MAX;
        for (int i = k - 1; i >= 0; i--) {
            currMin = min(currMin, nums[i]);
            left[i] = currMin;
        }
        
        vector<int> right;
        currMin = INT_MAX;
        for (int i = k; i < n; i++) {
            currMin = min(currMin, nums[i]);
            right.push_back(currMin);
        }
        
        int ans = 0;
        for (int j = 0; j < right.size(); j++) {
            currMin = right[j];
            int i = lower_bound(left.begin(), left.end(), currMin) - left.begin();
            int size = (k + j) - i + 1;
            ans = max(ans, currMin * size);
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
    public int maximumScore(int[] nums, int k) {
        int ans = solve(nums, k);
        for (int i = 0; i < nums.length / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[nums.length - i - 1];
            nums[nums.length - i - 1] = temp;
        }
        
        return Math.max(ans, solve(nums, nums.length - k - 1));
    }
    
    public int solve(int[] nums, int k) {
        int n = nums.length;
        int left[] = new int[k];
        int currMin = Integer.MAX_VALUE;
        for (int i = k - 1; i >= 0; i--) {
            currMin = Math.min(currMin, nums[i]);
            left[i] = currMin;
        }
        
        List<Integer> right = new ArrayList();
        currMin = Integer.MAX_VALUE;
        for (int i = k; i < n; i++) {
            currMin = Math.min(currMin, nums[i]);
            right.add(currMin);
        }
        
        int ans = 0;
        for (int j = 0; j < right.size(); j++) {
            currMin = right.get(j);
            int i = binarySearch(left, currMin);
            int size = (k + j) - i + 1;
            ans = Math.max(ans, currMin * size);
        }

        return ans;
    }
    
    public int binarySearch(int[] nums, int num) {
        int left = 0;
        int right = nums.length;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        def solve(nums, k):
            n = len(nums)
            left = [0] * k
            curr_min = inf
            for i in range(k - 1, -1, -1):
                curr_min = min(curr_min, nums[i])
                left[i] = curr_min

            right = []
            curr_min = inf
            for i in range(k, n):
                curr_min = min(curr_min, nums[i])
                right.append(curr_min)

            ans = 0
            for j in range(len(right)):
                curr_min = right[j]
                i = bisect_left(left, curr_min)
                size = (k + j) - i + 1
                ans = max(ans, curr_min * size)
                
            return ans
        
        return max(solve(nums, k), solve(nums[::-1], len(nums) - k - 1))
```

</details>

<br>

## Approach 2: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> stack;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && nums[stack.back()] > nums[i]) {
                left[stack.back()] = i;
                stack.pop_back();
            }
            
            stack.push_back(i);
        }
        
        vector<int> right(n, n);
        stack.clear();
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && nums[stack.back()] > nums[i]) {
                right[stack.back()] = i;
                stack.pop_back();
            }
            
            stack.push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] < k && right[i] > k) {
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
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
    public int maximumScore(int[] nums, int k) {
        int n = nums.length;
        int left[] = new int[n];
        Arrays.fill(left, -1);
        Stack<Integer> stack = new Stack<>();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
                left[stack.pop()] = i;
            }
            
            stack.push(i);
        }
        
        int right[] = new int[n];
        Arrays.fill(right, n);
        stack = new Stack<>();
        
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
                right[stack.pop()] = i;
            }
            
            stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] < k && right[i] > k) {
                ans = Math.max(ans, nums[i] * (right[i] - left[i] - 1));
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
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left = [-1] * n
        stack = []
        
        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] > nums[i]:
                left[stack.pop()] = i
                
            stack.append(i)
            
        right = [n] * n
        stack = []
        for i in range(n):
            while stack and nums[stack[-1]] > nums[i]:
                right[stack.pop()] = i
            
            stack.append(i)

        ans = 0
        for i in range(n):
            if left[i] < k and right[i] > k:
                ans = max(ans, nums[i] * (right[i] - left[i] - 1))
        
        return ans
```

</details>

<br>

## Approach 3: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k;
        int right = k;
        int ans = nums[k];
        int currMin = nums[k];
        
        while (left > 0 || right < n - 1) {
            if ((left > 0 ? nums[left - 1]: 0) < (right < n - 1 ? nums[right + 1] : 0)) {
                right++;
                currMin = min(currMin, nums[right]);
            } else {
                left--;
                currMin = min(currMin, nums[left]);
            }
            
            ans = max(ans, currMin * (right - left + 1));
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
    public int maximumScore(int[] nums, int k) {
        int n = nums.length;
        int left = k;
        int right = k;
        int ans = nums[k];
        int currMin = nums[k];
        
        while (left > 0 || right < n - 1) {
            if ((left > 0 ? nums[left - 1]: 0) < (right < n - 1 ? nums[right + 1] : 0)) {
                right++;
                currMin = Math.min(currMin, nums[right]);
            } else {
                left--;
                currMin = Math.min(currMin, nums[left]);
            }
            
            ans = Math.max(ans, currMin * (right - left + 1));
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
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left = k
        right = k
        ans = nums[k]
        curr_min = nums[k]
        
        while left > 0 or right < n - 1:
            if (nums[left - 1] if left else 0) < (nums[right + 1] if right < n - 1 else 0):
                right += 1
                curr_min = min(curr_min, nums[right])
            else:
                left -= 1
                curr_min = min(curr_min, nums[left])

            ans = max(ans, curr_min * (right - left + 1))
        
        return ans
```

</details>
