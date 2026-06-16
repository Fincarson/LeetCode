# 2425. Bitwise XOR of All Pairings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/bitwise-xor-of-all-pairings/)  
`Array` `Bit Manipulation` `Brainteaser`

**Problem Link:** [LeetCode 2425 - Bitwise XOR of All Pairings](https://leetcode.com/problems/bitwise-xor-of-all-pairings/)

## Problem

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. Let there be another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.

### Example 1

```text
Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.
```

### Example 2

```text
Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 105
- 0 <= nums1[i], nums2[j] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2425. Bitwise XOR of All Pairings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Map | C++, Java, Python3 |
| Space Optimized Bit Manipulation | C++, Java, Python3 |

## Approach 1: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Get lengths of arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // Map to store frequency of each number
        unordered_map<int, long> freq;

        // Add frequencies for nums1 elements
        // Each element appears len2 times in final result
        for (int num : nums1) {
            freq[num] += len2;
        }

        // Add frequencies for nums2 elements
        // Each element appears len1 times in final result
        for (int num : nums2) {
            freq[num] += len1;
        }

        // XOR numbers that appear odd number of times
        int ans = 0;
        for (auto& [num, count] : freq) {
            if (count % 2 == 1) {
                ans ^= num;
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

    public int xorAllNums(int[] nums1, int[] nums2) {
        // Get lengths of arrays
        int len1 = nums1.length;
        int len2 = nums2.length;

        // Map to store frequency of each number
        Map<Integer, Integer> freq = new HashMap<>();

        // Add frequencies for nums1 elements
        // Each element appears n2 times in final result
        for (int num : nums1) {
            freq.put(num, freq.getOrDefault(num, 0) + len2);
        }

        // Add frequencies for nums2 elements
        // Each element appears n1 times in final result
        for (int num : nums2) {
            freq.put(num, freq.getOrDefault(num, 0) + len1);
        }

        // XOR numbers that appear odd number of times
        int ans = 0;
        for (int num : freq.keySet()) {
            if (freq.get(num) % 2 == 1) {
                ans ^= num;
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
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        # Get lengths of arrays
        len1, len2 = len(nums1), len(nums2)

        # Dictionary to store frequency of each number
        freq = {}

        # Add frequencies for nums1 elements
        # Each element appears n2 times in final result
        for num in nums1:
            freq[num] = freq.get(num, 0) + len2

        # Add frequencies for nums2 elements
        # Each element appears n1 times in final result
        for num in nums2:
            freq[num] = freq.get(num, 0) + len1

        # XOR numbers that appear odd number of times
        ans = 0
        for num in freq:
            if freq[num] % 2:
                ans ^= num

        return ans
```

</details>

<br>

## Approach 2: Space Optimized Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Initialize XOR results for both arrays
        int xor1 = 0;
        int xor2 = 0;

        // Get lengths of both arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // If nums2 length is odd, each element in nums1 appears odd times in
        // final result
        if (len2 % 2 != 0) {
            for (int num : nums1) {
                xor1 ^= num;
            }
        }

        // If nums1 length is odd, each element in nums2 appears odd times in
        // final result
        if (len1 % 2 != 0) {
            for (int num : nums2) {
                xor2 ^= num;
            }
        }

        // Return XOR of both results
        return xor1 ^ xor2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int xorAllNums(int[] nums1, int[] nums2) {
        // Initialize XOR results for both arrays
        int xor1 = 0;
        int xor2 = 0;

        // Get lengths of both arrays
        int len1 = nums1.length;
        int len2 = nums2.length;

        // If nums2 length is odd, each element in nums1 appears odd times in final result
        if (len2 % 2 != 0) {
            for (int num : nums1) {
                xor1 ^= num;
            }
        }

        // If nums1 length is odd, each element in nums2 appears odd times in final result
        if (len1 % 2 != 0) {
            for (int num : nums2) {
                xor2 ^= num;
            }
        }

        // Return XOR of both results
        return xor1 ^ xor2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        # Initialize XOR results for both arrays
        xor1, xor2 = 0, 0

        # Get lengths of both arrays
        len1, len2 = len(nums1), len(nums2)

        # If nums2 length is odd, each element in nums1 appears odd times in final result
        if len2 % 2:
            for num in nums1:
                xor1 ^= num

        # If nums1 length is odd, each element in nums2 appears odd times in final result
        if len1 % 2:
            for num in nums2:
                xor2 ^= num

        # Return XOR of both results
        return xor1 ^ xor2
```

</details>
