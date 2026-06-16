# 1248. Count Number of Nice Subarrays

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-number-of-nice-subarrays/)  
`Array` `Hash Table` `Math` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 1248 - Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/)

## Problem

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

### Example 1

```text
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```

### Example 2

```text
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
```

### Example 3

```text
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
```

## Constraints

- 1 <= nums.length <= 50000
- 1 <= nums[i] <= 10^5
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [K Divisible Elements Subarrays](https://leetcode.com/problems/k-divisible-elements-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Ways to Split Array Into Good Subarrays](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count of Interesting Subarrays](https://leetcode.com/problems/count-of-interesting-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1248. Count Number of Nice Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashing | C++, Java, Python3 |
| Sliding Window using Queue | C++, Java, Python3 |
| Sliding Window (Space Optimisation of queue-based approach) | C++, Java, Python3 |
| Sliding Window (subarray sum at most k) | C++, Java, Python3 |

## Approach 1: Hashing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int currSum = 0, subarrays = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[currSum] = 1;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i] % 2;
            // Find subarrays with sum k ending at i.
            if (prefixSum.find(currSum - k) != prefixSum.end()) {
                subarrays = subarrays + prefixSum[currSum - k];
            }
            // Increment the current prefix sum in hashmap.
            prefixSum[currSum]++;
        }

        return subarrays;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfSubarrays(int[] nums, int k) {
        int currSum = 0, subarrays = 0;
        Map<Integer, Integer> prefixSum = new HashMap<>();
        prefixSum.put(currSum, 1);

        for (int i = 0; i < nums.length; i++) {
            currSum += nums[i] % 2;
            // Find subarrays with sum k ending at i
            if (prefixSum.containsKey(currSum - k)) {
                subarrays = subarrays + prefixSum.get(currSum - k);
            }
            // Increment the current prefix sum in hashmap
            prefixSum.put(currSum, prefixSum.getOrDefault(currSum, 0) + 1);
        }

        return subarrays;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        curr_sum = 0
        subarrays = 0
        prefix_sum = {curr_sum: 1}

        for i in range(len(nums)):
            curr_sum += nums[i] % 2
            # Find subarrays with sum k ending at i
            if curr_sum - k in prefix_sum:
                subarrays = subarrays + prefix_sum[curr_sum - k]
            # Increment the current prefix sum in hashmap
            prefix_sum[curr_sum] = prefix_sum.get(curr_sum, 0) + 1

        return subarrays
```

</details>

<br>

## Approach 2: Sliding Window using Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        queue<int> oddIndices;
        int subarrays = 0, lastPopped = -1, initialGap = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If element is odd, push it in queue.
            if (nums[i] % 2 == 1) {
                oddIndices.push(i);
            }
            // If queue size exceeds k, perform pop operation.
            if (oddIndices.size() > k) {
                lastPopped = oddIndices.front();
                oddIndices.pop();
            }
            // If there are exactly k odd numbers,
            // add the number of even numbers in the
            // beginning of the subarray to the result.
            if (oddIndices.size() == k) {
                initialGap = oddIndices.front() - lastPopped;
                subarrays += initialGap;
            }
        }

        return subarrays;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfSubarrays(int[] nums, int k) {
        Queue<Integer> oddIndices = new LinkedList<>();
        int subarrays = 0;
        int lastPopped = -1;
        int initialGap = 0;

        for (int i = 0; i < nums.length; i++) {
            // If element is odd, append its index to the list.
            if (nums[i] % 2 == 1) {
                oddIndices.offer(i);
            }
            // If the number of odd numbers exceeds k, remove the first odd index.
            if (oddIndices.size() > k) {
                lastPopped = oddIndices.poll();
            }
            // If there are exactly k odd numbers, add the number of even numbers
            // in the beginning of the subarray to the result.
            if (oddIndices.size() == k) {
                initialGap = oddIndices.element() - lastPopped;
                subarrays += initialGap;
            }
        }

        return subarrays;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        odd_indices = deque()
        subarrays = 0
        last_popped = -1
        initial_gap = 0

        for i in range(len(nums)):
            # If element is odd, append its index to the deque.
            if nums[i] % 2 == 1:
                odd_indices.append(i)
            # If the number of odd numbers exceeds k, remove the first odd index.
            if len(odd_indices) > k:
                last_popped = odd_indices.popleft()
            # If there are exactly k odd numbers, add the number of even numbers
            # in the beginning of the subarray to the result.
            if len(odd_indices) == k:
                initial_gap = odd_indices[0] - last_popped
                subarrays += initial_gap

        return subarrays
```

</details>

<br>

## Approach 3: Sliding Window (Space Optimisation of queue-based approach)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int subarrays = 0, initialGap = 0, qsize = 0, start = 0;
        for (int end = 0; end < nums.size(); end++) {
            // If current element is odd, increment qsize by 1.
            if (nums[end] % 2 == 1) {
                qsize++;
            }
            // If qsize is k, calculate initialGap and add it in the answer.
            if (qsize == k) {
                initialGap = 0;
                // Calculate the number of even elements in the beginning of
                // subarray.
                while (qsize == k) {
                    qsize -= nums[start] % 2;
                    initialGap++;
                    start++;
                }
            }
            subarrays += initialGap;
        }

        return subarrays;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfSubarrays(int[] nums, int k) {
        int subarrays = 0, initialGap = 0, qsize = 0, start = 0;
        for (int end = 0; end < nums.length; end++) {
            // If current element is odd, increment qsize by 1.
            if (nums[end] % 2 == 1) {
                qsize++;
            }
            // If qsize is k, calculate initialGap and add it in the answer.
            if (qsize == k) {
                initialGap = 0;
                // Calculate the number of even elements in the beginning of
                // subarray.
                while (qsize == k) {
                    qsize -= nums[start] % 2;
                    initialGap++;
                    start++;
                }
            }
            subarrays += initialGap;
        }
        return subarrays;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        subarrays = 0
        initial_gap = 0
        qsize = 0
        start = 0
        for end in range(len(nums)):
            # If current element is odd, increment qsize by 1.
            if nums[end] % 2 == 1:
                qsize += 1
            if qsize == k:
                initial_gap = 0
                # Calculate the number of even elements in the beginning of
                # subarray.
                while qsize == k:
                    qsize -= nums[start] % 2
                    initial_gap += 1
                    start += 1
            subarrays += initial_gap
        return subarrays
```

</details>

<br>

## Approach 4: Sliding Window (subarray sum at most k)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int windowSize = 0, subarrays = 0, start = 0;

        for (int end = 0; end < nums.size(); end++) {
            windowSize += nums[end] % 2;
            // Find the first index start where the window has exactly k odd
            // elements.
            while (windowSize > k) {
                windowSize -= nums[start] % 2;
                start++;
            }
            // Increment number of subarrays with end - start + 1.
            subarrays += end - start + 1;
        }

        return subarrays;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfSubarrays(int[] nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    private int atMost(int[] nums, int k) {
        int windowSize = 0, subarrays = 0, start = 0;

        for (int end = 0; end < nums.length; end++) {
            windowSize += nums[end] % 2;
            // Find the first index start where the window has exactly k odd elements.
            while (windowSize > k) {
                windowSize -= nums[start] % 2;
                start++;
            }
            // Increment number of subarrays with end - start + 1.
            subarrays += end - start + 1;
        }

        return subarrays;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        return self.atMost(nums, k) - self.atMost(nums, k - 1)

    def atMost(self, nums: List[int], k: int) -> int:
        window_size, subarrays, start = 0, 0, 0
        for end in range(len(nums)):
            window_size += nums[end] % 2
            # Find the first index start where the window has exactly k odd elements.
            while window_size > k:
                window_size -= nums[start] % 2
                start += 1
            # Increment number of subarrays with end - start + 1.
            subarrays += end - start + 1
        return subarrays
```

</details>
