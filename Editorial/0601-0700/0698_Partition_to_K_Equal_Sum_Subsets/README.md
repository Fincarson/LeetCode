# 698. Partition to K Equal Sum Subsets

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)  
`Array` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Memoization` `Bitmask`

**Problem Link:** [LeetCode 698 - Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)

## Problem

Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

### Example 1

```text
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

### Example 2

```text
Input: nums = [1,2,3,4], k = 3
Output: false
```

## Constraints

- 1 <= k <= nums.length <= 16
- 1 <= nums[i] <= 104
- The frequency of each element is in the range [1, 4].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Ways to Partition an Array](https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Rows Covered by Columns](https://leetcode.com/problems/maximum-rows-covered-by-columns/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Product of Two Integers With No Common Bits](https://leetcode.com/problems/maximum-product-of-two-integers-with-no-common-bits/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 698. Partition to K Equal Sum Subsets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Naive Backtracking | C++, Java, JavaScript, Python3 |
| Optimized Backtracking | C++, Java, JavaScript, Python3 |
| Backtracking plus Memoization | C++, Java, JavaScript, Python3 |
| Backtracking plus Memoization with Bitmasking | C++, Java, JavaScript, Python3 |
| Tabulation plus Bitmasking | C++, Java, JavaScript, Python3 |

## Approach 1: Naive Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool backtrack(vector<int>& arr, int count, int currSum, int k, int targetSum, vector<bool>& taken) {
        int n = arr.size();
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // Current subset sum exceeds target sum, no need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
      
        // When current subset sum reaches target sum then one subset is made.
        // Increment count and reset current subset sum to 0.
        if (currSum == targetSum) {
            return backtrack(arr, count + 1, 0, k, targetSum, taken);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = 0; j < n; ++j) {
            if (!taken[j]) {
                // Include this element in current subset.
                taken[j] = true;
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, count, currSum + arr[j], k, targetSum, taken)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = false;
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        int targetSum = totalArraySum / k;
        vector<bool> taken(n, false);
      
        return backtrack(arr, 0, 0, k, targetSum, taken);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean backtrack(int[] arr, int count, int currSum, int k, int targetSum, boolean[] taken) {
        int n = arr.length;
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // Current subset sum exceeds target sum, no need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
      
        // When current subset sum reaches target sum then one subset is made.
        // Increment count and reset current subset sum to 0.
        if (currSum == targetSum) {
            return backtrack(arr, count + 1, 0, k, targetSum, taken);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = 0; j < n; ++j) {
            if (!taken[j]) {
                // Include this element in current subset.
                taken[j] = true;
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, count, currSum + arr[j], k, targetSum, taken)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = false;
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return false;
    }
  
    public boolean canPartitionKSubsets(int[] arr, int k) {
        int totalArraySum = 0;
        int n = arr.length;
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        int targetSum = totalArraySum / k;
        boolean[] taken = new boolean[n];
      
        return backtrack(arr, 0, 0, k, targetSum, taken);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

let backtrack = (arr, count, currSum, k, targetSum, taken) => {
    let n = arr.length;

    // We made k - 1 subsets with target sum and last subset will also have target sum.
    if (count == k - 1) { 
        return true;
    }

    // Current subset sum exceeds target sum, no need to proceed further.
    if (currSum > targetSum) { 
        return false;
    }

    // When current subset sum reaches target sum then one subset is made.
    // Increment count and reset current subset sum to 0.
    if (currSum == targetSum) {
        return backtrack(arr, count + 1, 0, k, targetSum, taken);
    }

    // Try not picked elements to make some combinations.
    for (let j = 0; j < n; ++j) {
        if (!taken[j]) {
            // Include this element in current subset.
            taken[j] = true;

            // If using current jth element in this subset leads to make all valid subsets.
            if (backtrack(arr, count, currSum + arr[j], k, targetSum, taken)) {
                return true;
            }

            // Backtrack step.
            taken[j] = false;
        }
    } 

    // We were not able to make a valid combination after picking each element from the array,
    // hence we can't make k subsets.
    return false;
};

let canPartitionKSubsets = (arr, k) => {
    let totalArraySum = 0;
    let n = arr.length;

    for (let i = 0; i < n; ++i) {
         totalArraySum += arr[i];
    }
    
    // If total sum not divisible by k, we can't make subsets.
    if (totalArraySum % k != 0) { 
        return false;
    }

    let targetSum = totalArraySum / k;
    let taken = new Array(n).fill(false);

    return backtrack(arr, 0, 0, k, targetSum, taken);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartitionKSubsets(self, arr: List[int], k: int) -> bool:
        total_array_sum = sum(arr)
        n = len(arr)

        # If the total sum is not divisible by k, we can't make subsets.
        if total_array_sum % k != 0:
            return False

        target_sum = total_array_sum // k
        taken = [False] * n
        
        def backtrack(count: int, curr_sum: int) -> bool:
            n = len(arr)

            # We made k - 1 subsets with target sum and the last subset will also have target sum.
            if count == k - 1:
                return True

            # Current subset-sum exceeds target sum, no need to proceed further.
            if curr_sum > target_sum:
                return False

            # When current subset sum reaches target sum then one subset is made.
            # Increment count and reset current subset sum to 0.
            if curr_sum == target_sum:
                return backtrack(count + 1, 0)

            # Try not picked elements to make some combinations.
            for j in range(n):
                if not taken[j]:
                    # Include this element in current subset.
                    taken[j] = True

                    # If using current jth element in this subset leads to make all valid subsets.
                    if backtrack(count, curr_sum + arr[j]):
                        return True

                    # Backtrack step.
                    taken[j] = False

            # We were not able to make a valid combination after picking 
            # each element from the array, hence we can't make k subsets.
            return False

        return backtrack(0, 0)
```

</details>

<br>

## Approach 2: Optimized Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool backtrack(vector<int>& arr, int index, int count, int currSum, int k, 
                   int targetSum, vector<bool>& taken) {
                       
        int n = arr.size();
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            return backtrack(arr, 0, count + 1, 0, k, targetSum, taken);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (!taken[j]) {
                // Include this element in current subset.
                taken[j] = true;
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = false;
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }

        // Sort in decreasing order.
        sort(arr.begin(), arr.end(), greater<int>());
      
        int targetSum = totalArraySum / k;
        vector<bool> taken(n, false);
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean backtrack(int[] arr, int index, int count, int currSum, int k, 
                              int targetSum, boolean[] taken) {

        int n = arr.length;
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            return backtrack(arr, 0, count + 1, 0, k, targetSum, taken);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (!taken[j]) {
                // Include this element in current subset.
                taken[j] = true;
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = false;
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return false;
    }
    
    void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) { 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  
    public boolean canPartitionKSubsets(int[] arr, int k) {
        int totalArraySum = 0;
        int n = arr.length;
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        Arrays.sort(arr);
        reverse(arr);
        
        int targetSum = totalArraySum / k;
        boolean[] taken = new boolean[n];
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

let backtrack = (arr, index, count, currSum, k, targetSum, taken) => {
    let n = arr.length;
      
    // We made k - 1 subsets with target sum and last subset will also have target sum.
    if (count == k - 1) { 
        return true;
    }

    // No need to proceed further.
    if (currSum > targetSum) { 
        return false;
    }

    // When curr sum reaches target then one subset is made.
    // Increment count and reset current sum.
    if (currSum == targetSum) {
        return backtrack(arr, 0, count + 1, 0, k, targetSum, taken);
    }

    // Try not picked elements to make some combinations.
    for (let j = index; j < n; ++j) {
        if (!taken[j]) {
            // Include this element in current subset.
            taken[j] = true;

            // If using current jth element in this subset leads to make all valid subsets.
            if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken)) {
                return true;
            }

            // Backtrack step.
            taken[j] = false;
        }
    } 

    // We were not able to make a valid combination after picking each element from the array,
    // hence we can't make k subsets.
    return false;
};

let canPartitionKSubsets = (arr, k) => {
    let totalArraySum = 0;
    let n = arr.length;

    for (let i = 0; i < n; ++i) {
         totalArraySum += arr[i];
    }

    // If total sum not divisible by k, we can't make subsets.
    if (totalArraySum % k != 0) { 
        return false;
    }

    // Sort in decreasing order.
    arr.sort(function (a, b) { 
        return b - a; 
    });

    let targetSum = totalArraySum / k;
    let taken = new Array(n).fill(false);

    return backtrack(arr, 0, 0, 0, k, targetSum, taken);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartitionKSubsets(self, arr: List[int], k: int) -> bool:
        n = len(arr)
    
        # If the total sum is not divisible by k, we can't make subsets.
        total_array_sum = sum(arr)
        if total_array_sum % k != 0:
            return False
        target_sum = total_array_sum // k

        # Sort in decreasing order.
        arr.sort(reverse=True)

        taken = [False] * n
        
        def backtrack(index, count, curr_sum):
            n = len(arr)
      
            # We made k - 1 subsets with target_sum and the last subset must also have target_sum.
            if count == k - 1:
                return True
            
            # No need to proceed further.
            if curr_sum > target_sum:
                return False
                
            # When curr sum reaches target then one subset is made.
            # Increment count and reset current sum.
            if curr_sum == target_sum:
                return backtrack(0, count + 1, 0)
                
            # Try not picked elements to make some combinations.
            for j in range(index, n):
                if not taken[j]:
                    # Include this element in current subset.
                    taken[j] = True
                    
                    # If using current jth element in this subset leads to make all valid subsets.
                    if backtrack(j + 1, count, curr_sum + arr[j]):
                        return True
        
                    # Backtrack step.
                    taken[j] = False
    
            # We were not able to make a valid combination after picking 
            # each element from the array, hence we can't make k subsets.
            return False
        
        return backtrack(0, 0, 0)
```

</details>

<br>

## Approach 3: Backtracking plus Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool backtrack(vector<int>& arr, int index, int count, int currSum, int k, 
                   int targetSum, string& taken, unordered_map<string, bool>& memo) {

        int n = arr.size();
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
        
        // If we have already computed the current combination.
        if (memo.find(taken) != memo.end()) {
            return memo[taken];
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            return memo[taken] = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, memo);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (taken[j] == '0') {
                // Include this element in current subset.
                taken[j] = '1';
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, memo)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = '0';
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return memo[taken] = false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        sort(arr.begin(), arr.end(), greater<int>());
        
        int targetSum = totalArraySum / k;
        
        // String to represent taken array.
        string taken(n, '0');
        
        // Memoize the ans using taken element's string as key.
        unordered_map<string, bool> memo;
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken, memo);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean backtrack(int[] arr, int index, int count, int currSum, int k, 
                              int targetSum, char[] taken, HashMap<String, Boolean> memo) {

        int n = arr.length;
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
        
        String takenStr = new String(taken);
        
        // If we have already computed the current combination.
        if (memo.containsKey(takenStr)) {
            return memo.get(takenStr);
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            boolean ans = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, memo);
            memo.put(takenStr, ans);
            return ans;
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (taken[j] == '0') {
                // Include this element in current subset.
                taken[j] = '1';
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, memo)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = '0';
            }
        } 
      
        // We were not able to make a valid combination after picking each element from array,
        // hence we can't make k subsets.
        memo.put(takenStr, false);
        return false;
    }
    
    void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) { 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  
    public boolean canPartitionKSubsets(int[] arr, int k) {
        int totalArraySum = 0;
        int n = arr.length;
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        Arrays.sort(arr);
        reverse(arr);
        
        int targetSum = totalArraySum / k;
        
        char[] taken = new char[n];
        for(int i = 0; i < n; ++i) {
            taken[i] = '0';
        }
        
        // Memoize the ans using taken element's string as key.
        HashMap<String, Boolean> memo = new HashMap<>();
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken, memo);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */


let backtrack = (arr, index, count, currSum, k, targetSum, taken, memo) => {
    let n = arr.length;
      
    // We made k - 1 subsets with target sum and last subset will also have target sum.
    if (count == k - 1) { 
        return true;
    }

    // No need to proceed further.
    if (currSum > targetSum) { 
        return false;
    }
    
    // If we have already computed the current combination.
    if (memo[taken] != null) {
        return memo[taken];
    }

    // When curr sum reaches target then one subset is made.
    // Increment count and reset current sum.
    if (currSum == targetSum) {
        return memo[taken] = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, memo);
    }

    // Try not picked elements to make some combinations.
    for (let j = index; j < n; ++j) {
        if (!taken[j]) {
            // Include this element in current subset.
            taken[j] = true;

            // If using current jth element in this subset leads to make all valid subsets.
            if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, memo)) {
                return memo[taken] = true;
            }

            // Backtrack step.
            taken[j] = false;
        }
    } 

    // We were not able to make a valid combination after picking each element from the array,
    // hence we can't make k subsets.
    return memo[taken] = false;
};

let canPartitionKSubsets = (arr, k) => {
    let totalArraySum = 0;
    let n = arr.length;

    for (let i = 0; i < n; ++i) {
         totalArraySum += arr[i];
    }

    // If total sum not divisible by k, we can't make subsets.
    if (totalArraySum % k != 0) { 
        return false;
    }

    // Sort in decreasing order.
    arr.sort(function (a, b) { 
        return b - a; 
    });

    let targetSum = totalArraySum / k;
    let taken = new Array(n).fill(false);
    
    let memo = {};

    return backtrack(arr, 0, 0, 0, k, targetSum, taken, memo);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartitionKSubsets(self, arr: List[int], k: int) -> bool:
        n = len(arr)
    
        total_array_sum = sum(arr)
        
        # If the total sum is not divisible by k, we can't make subsets.
        if total_array_sum % k != 0:
            return False

        target_sum = total_array_sum // k

        # Sort in decreasing order.
        arr.sort(reverse=True)

        taken = ['0'] * n
        
        memo = {}
        
        def backtrack(index, count, curr_sum):
            n = len(arr)
            
            taken_str = ''.join(taken)
      
            # We made k - 1 subsets with target sum and the last subset will also have target sum.
            if count == k - 1:
                return True
            
            # No need to proceed further.
            if curr_sum > target_sum:
                return False
            
            # If we have already computed the current combination.
            if taken_str in memo:
                return memo[taken_str]
            
            # When curr sum reaches target then one subset is made.
            # Increment count and reset current sum.
            if curr_sum == target_sum:
                memo[taken_str] = backtrack(0, count + 1, 0)
                return memo[taken_str]
            
            # Try not picked elements to make some combinations.
            for j in range(index, n):
                if taken[j] == '0':
                    # Include this element in current subset.
                    taken[j] = '1'
                    # If using current jth element in this subset leads to make all valid subsets.
                    if backtrack(j + 1, count, curr_sum + arr[j]):
                        return True
                    # Backtrack step.
                    taken[j] = '0'
                    
            # We were not able to make a valid combination after picking 
            # each element from the array, hence we can't make k subsets.
            memo[taken_str] = False
            return memo[taken_str] 
        
        return backtrack(0, 0, 0)
```

</details>

<br>

## Approach 4: Backtracking plus Memoization with Bitmasking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool backtrack(vector<int>& arr, int index, int count, int currSum, int k, 
                   int targetSum, int& mask, unordered_map<int, bool>& memo) {

        int n = arr.size();
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
      
        // If we have already computed the current combination.
        if (memo.count(mask)) {
            return memo[mask];
        }
        
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            return memo[mask] = backtrack(arr, 0, count + 1, 0, k, targetSum, mask, memo);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (((mask >> j) & 1) == 0) {
                // Include this element in current subset.
                mask = (mask | (1 << j));
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, mask, memo)) {
                    return memo[mask] = true;
                }
                
                // Backtrack step.
                mask = (mask ^ (1 << j));
            }
        } 
      
        // We were not able to make a valid combination after picking each element from array, 
        // hence we can't make k subsets.
        return memo[mask] = false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        sort(arr.begin(), arr.end(), greater<int>());
        
        int targetSum = totalArraySum / k;
        int mask = 0;
        
        unordered_map<int, bool> memo;
            
        return backtrack(arr, 0, 0, 0, k, targetSum, mask, memo);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean backtrack(int[] arr, int index, int count, int currSum, int k, 
                              int targetSum, Integer mask, HashMap<Integer, Boolean> memo) {
                                  
        int n = arr.length;
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
        
        // If we have already computed the current combination.
        if (memo.containsKey(mask)) {
            return memo.get(mask);
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            boolean ans = backtrack(arr, 0, count + 1, 0, k, targetSum, mask, memo);
            memo.put(mask, ans);
            return ans;
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (((mask >> j) & 1) == 0) {
                // Include this element in current subset.
                mask = (mask | (1 << j));
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, mask, memo)) {
                    return true;
                }
                
                // Backtrack step.
                mask = (mask ^ (1 << j));
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        memo.put(mask, false);
        return false;
    }
    
    void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) { 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  
    public boolean canPartitionKSubsets(int[] arr, int k) {
        int totalArraySum = 0;
        int n = arr.length;
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        Arrays.sort(arr);
        reverse(arr);
        
        int targetSum = totalArraySum / k;
        Integer mask = 0;
        
        // Memoize the ans using taken element's string as key.
        HashMap<Integer, Boolean> memo = new HashMap<>();
      
        return backtrack(arr, 0, 0, 0, k, targetSum, mask, memo);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */


let backtrack = (arr, index, count, currSum, k, targetSum, mask, memo) => {
    let n = arr.length;
      
    // We made k - 1 subsets with target sum and last subset will also have target sum.
    if (count == k - 1) { 
        return true;
    }

    // No need to proceed further.
    if (currSum > targetSum) { 
        return false;
    }
    
    if (memo[mask] != null) {
        return memo[mask];
    }

    // When curr sum reaches target then one subset is made.
    // Increment count and reset current sum.
    if (currSum == targetSum) {
        return memo[mask] = backtrack(arr, 0, count + 1, 0, k, targetSum, mask, memo);
    }

    // Try not picked elements to make some combinations.
    for (let j = index; j < n; ++j) {
        if (((mask >> j) & 1) == 0) {
            // Include this element in current subset.
            mask = (mask | (1 << j));

            // If using current jth element in this subset leads to make all valid subsets.
            if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, mask, memo)) {
                return true;
            }

            // Backtrack step.
            mask = (mask ^ (1 << j));
        }
    } 

    // We were not able to make a valid combination after picking each element from the array,
    // hence we can't make k subsets.
    return memo[mask] = false;
};

let canPartitionKSubsets = (arr, k) => {
    let totalArraySum = 0;
    let n = arr.length;

    for (let i = 0; i < n; ++i) {
         totalArraySum += arr[i];
    }

    // If total sum not divisible by k, we can't make subsets.
    if (totalArraySum % k != 0) { 
        return false;
    }

    // Sort in decreasing order.
    arr.sort(function (a, b) { 
        return b - a; 
    });

    let targetSum = totalArraySum / k;
    let taken = 0;
    
    let memo = {};

    return backtrack(arr, 0, 0, 0, k, targetSum, taken, memo);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartitionKSubsets(self, arr: List[int], k: int) -> bool:
        n = len(arr)
    
        # If the total sum is not divisible by k, we can't make subsets.
        total_array_sum = sum(arr)
        if total_array_sum % k != 0:
            return False
        target_sum = total_array_sum // k

        # Sort in decreasing order.
        arr.sort(reverse=True)

        mask = 0
        
        memo = {}
        
        def backtrack(index, count, curr_sum):
            nonlocal mask
            n = len(arr)
            
            # We made k - 1 subsets with target sum and the last subset will also have target sum.
            if count == k - 1:
                return True
            
            # No need to proceed further.
            if curr_sum > target_sum:
                return False
            
            # If we have already computed the current combination.
            if mask in memo:
                return memo[mask]
            
            # When curr sum reaches target then one subset is made.
            # Increment count and reset current sum.
            if curr_sum == target_sum:
                memo[mask] = backtrack(0, count + 1, 0)
                return memo[mask]

            # Try not picked elements to make some combinations.
            for j in range(index, n):
                if ((mask >> j) & 1) == 0:
                    # Include this element in current subset.
                    mask = (mask | (1 << j))

                    # If using current jth element in this subset leads to make all valid subsets.
                    if backtrack(j + 1, count, curr_sum + arr[j]):
                        return True

                    # Backtrack step.
                    mask = (mask ^ (1 << j))

            # We were not able to make a valid combination after picking 
            # each element from the array, hence we can't make k subsets.
            memo[mask] = False
            return memo[mask] 

        return backtrack(0, 0, 0)
```

</details>

<br>

## Approach 5: Tabulation plus Bitmasking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
            totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        int targetSum = totalArraySum / k;
        
        vector<int> subsetSum((1 << n), -1);
        // Initially only one state is valid, i.e don't pick anything.
        subsetSum[0] = 0;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            // If the current state has not been reached earlier.
            if (subsetSum[mask] == -1) continue;  
            
            for (int i = 0; i < n; i++) {
                // If the number arr[i] was not picked earlier, and arr[i] + subsetSum[mask]
                // is not greater than the targetSum then add arr[i] to the subset
                // sum at subsetSum[mask] and store the result at subsetSum[mask | (1 << i)].
                if (!(mask & (1 << i)) && subsetSum[mask] + arr[i] <= targetSum) { 
                    subsetSum[mask | (1 << i)] = (subsetSum[mask] + arr[i]) % targetSum;
                }
                
            }

            if(subsetSum[(1 << n) - 1] == 0) { 
                return true;
            }
        }

        return subsetSum[(1 << n) - 1] == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canPartitionKSubsets(int[] arr, int k) {
        int totalArraySum = 0;
        int n = arr.length;
        
        for (int i = 0; i < n; ++i) {
            totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        int targetSum = totalArraySum / k;
        
        int[] subsetSum = new int[(1 << n)];
        for (int i = 0; i < (1 << n); ++i) {
            subsetSum[i] = -1;
        }
        // Initially only one state is valid, i.e don't pick anything.
        subsetSum[0] = 0;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            // If the current state has not been reached earlier.
            if (subsetSum[mask] == -1) {
                continue;
            }  
            
            for (int i = 0; i < n; i++) {
                // If the number arr[i] was not picked earlier, and arr[i] + subsetSum[mask]
                // is not greater than the targetSum then add arr[i] to the subset
                // sum at subsetSum[mask] and store the result at subsetSum[mask | (1 << i)].
                if ((mask & (1 << i)) == 0 && subsetSum[mask] + arr[i] <= targetSum) { 
                    subsetSum[mask | (1 << i)] = (subsetSum[mask] + arr[i]) % targetSum;
                }
            }
            
            if (subsetSum[(1 << n) - 1] == 0) {
                return true;
            }
        }
        
        return subsetSum[(1 << n) - 1] == 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

let canPartitionKSubsets = function(arr, k) {
    let totalArraySum = 0;
    let n = arr.length;

    for (let i = 0; i < n; ++i) {
        totalArraySum += arr[i];
    }

    // If total sum not divisible by k, we can't make subsets.
    if (totalArraySum % k != 0) { 
        return false;
    }

    let targetSum = totalArraySum / k;

    let subsetSum = new Array((1 << n)).fill(-1);
    // Initially only one state is valid, i.e don't pick anything
    subsetSum[0] = 0;

    for (let mask = 0; mask < (1 << n); mask++) {
        // If the current state has not been reached earlier.
        if (subsetSum[mask] == -1) {
            continue;
        }  

        for (let i = 0; i < n; i++) {
            // If the number arr[i] was not picked earlier, and arr[i] + subsetSum[mask]
            // is not greater than the targetSum then add arr[i] to the subset
            // sum at subsetSum[mask] and store the result at subsetSum[mask | (1 << i)].
            if ((mask & (1 << i)) == 0 && subsetSum[mask] + arr[i] <= targetSum) { 
                subsetSum[mask | (1 << i)] = (subsetSum[mask] + arr[i]) % targetSum;
            }
        }
        
        if (subsetSum[(1 << n) - 1] == 0) {
            return true;
        }
    }

    return subsetSum[(1 << n) - 1] == 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartitionKSubsets(self, arr: List[int], k: int) -> bool:
        total_array_sum = sum(arr)
        n = len(arr)
        
        # If the total sum is not divisible by k, we can't make subsets.
        if total_array_sum % k != 0:
            return False

        target_sum = total_array_sum // k

        subsetSum = [-1] * (1 << n)
        # Initially only one state is valid, i.e don't pick anything
        subsetSum[0] = 0

        for mask in range(1 << n):
            # If the current state has not been reached earlier.
            if subsetSum[mask] == -1: 
                continue

            for i in range(n):
                # If the number arr[i] was not picked earlier, and arr[i] + subsetSum[mask]
                # is not greater than the targetSum then add arr[i] to the subset
                # sum at subsetSum[mask] and store the result at subsetSum[mask | (1 << i)].
                if (mask & (1 << i)) == 0 and subsetSum[mask] + arr[i] <= target_sum: 
                    subsetSum[mask | (1 << i)] = (subsetSum[mask] + arr[i]) % target_sum
                
            if subsetSum[-1] == 0: 
                return True
        
        return subsetSum[-1] == 0
```

</details>
