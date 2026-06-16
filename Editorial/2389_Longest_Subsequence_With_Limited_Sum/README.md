# 2389. Longest Subsequence With Limited Sum

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/longest-subsequence-with-limited-sum/)  
`Array` `Binary Search` `Greedy` `Sorting` `Prefix Sum`

**Problem Link:** [LeetCode 2389 - Longest Subsequence With Limited Sum](https://leetcode.com/problems/longest-subsequence-with-limited-sum/)

## Problem

You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```text
Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
```

### Example 2

```text
Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.
```

## Constraints

- n == nums.length
- m == queries.length
- 1 <= n, m <= 1000
- 1 <= nums[i], queries[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2389. Longest Subsequence With Limited Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort and Count. | C++, Java, Python3 |
| Prefix Sum + Binary Search | C++, Java, Python3 |

## Approach 1: Sort and Count.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // Sort 'nums'
        sort(nums.begin(), nums.end());
        
        // For each query, collect numbers from lowest to highest.
        // If their sum exceeds the limit 'query', move on to the next query.
        vector<int> ans;
        for (auto query : queries) {
            int count = 0;
            for (auto num : nums) {
                if (query >= num) {
                    query -= num;
                    count++;
                }
                else {
                    break;
                }
            }
            ans.push_back(count);
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
    public int[] answerQueries(int[] nums, int[] queries) {
        // Sort 'nums'
        Arrays.sort(nums);
        int n = nums.length, m = queries.length;
        int answer[] = new int[m];
        
        // For each query, collect numbers from lowest to highest.
        // If their sum exceeds the limit 'query', move on to the next query.
        for (int i = 0; i < m; ++i) {
            int count = 0;
            int query = queries[i];
            for (int num : nums) {
                if (query >= num) {
                    count++;
                    query -= num;
                }
                else
                    break;
            }
            answer[i] = count;
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        # Sort 'nums'
        nums.sort()
        ans = []

        # For each query, collect numbers from lowest to highest.
        # If their sum exceeds the limit 'query', move on to the next query.
        for query in queries:
            count = 0
            for num in nums:
                if query >= num:
                    query -= num
                    count += 1
                else:
                    break
            ans.append(count)
        
        return ans
```

</details>

<br>

## Approach 2: Prefix Sum + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // Get the prefix sum array of the sorted 'nums'.
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        
        // For each query, find its insertion index to the prefix sum array.
        vector<int> answer;
        for (auto query : queries) {
            int index = upper_bound(nums.begin(), nums.end(), query) - nums.begin();
            answer.push_back(index);
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        // Get the prefix sum array of the sorted 'nums'.
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; ++i)
            nums[i] += nums[i - 1];
        
        // For each query, find its insertion index to the prefix sum array.
        int n = queries.length;
        int answer[] = new int[n];
        for (int i = 0; i < n; ++i) {
            int index = binarySearch(nums, queries[i]);
            answer[i] = index;
        }
        
        return answer;
    }
    
    int binarySearch(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid + 1;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return nums[left] > target ? left : left + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        # Get the prefix sum array of the sorted 'nums'.
        nums.sort()
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        
        answer = []
        
        # For each query, find its insertion index to the prefix sum array.
        for query in queries:
            index = bisect.bisect_right(nums, query)
            answer.append(index)
            
        return answer
```

</details>
