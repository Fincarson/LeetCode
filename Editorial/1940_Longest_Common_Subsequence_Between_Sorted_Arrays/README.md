# 1940. Longest Common Subsequence Between Sorted Arrays

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 1940 - Longest Common Subsequence Between Sorted Arrays](https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/)

## Problem

Given an array of integer arrays arrays where each arrays[i] is sorted in strictly increasing order, return an integer array representing the longest common subsequence among all the arrays.

A subsequence is a sequence that can be derived from another sequence by deleting some elements (possibly none) without changing the order of the remaining elements.

### Example 1

```text
Input: arrays = [[1,3,4],
                 [1,4,7,9]]
Output: [1,4]
Explanation: The longest common subsequence in the two arrays is [1,4].
```

### Example 2

```text
Input: arrays = [[2,3,6,8],
                 [1,2,3,5,6,7,10],
                 [2,3,4,6,9]]
Output: [2,3,6]
Explanation: The longest common subsequence in all three arrays is [2,3,6].
```

### Example 3

```text
Input: arrays = [[1,2,3,4,5],
                 [6,7,8]]
Output: []
Explanation: There is no common subsequence between the two arrays.
```

## Constraints

- 2 <= arrays.length <= 100
- 1 <= arrays[i].length <= 100
- 1 <= arrays[i][j] <= 100
- arrays[i] is sorted in strictly increasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1940. Longest Common Subsequence Between Sorted Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Map | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> longestCommonSubsequence(const vector<vector<int>>& arrays) {
        unordered_map<int, int> frequencies;
        vector<int> longestCommonSubseq;

        // Count the frequency of each number across all arrays
        for (const auto& array : arrays) {
            for (int num : array) {
                frequencies[num] += 1;
                // If the number appears in all arrays, add it to the result
                if (frequencies[num] == arrays.size()) {
                    longestCommonSubseq.push_back(num);
                }
            }
        }

        return longestCommonSubseq;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        Map<Integer, Integer> frequencies = new HashMap<>();
        List<Integer> longestCommonSubseq = new ArrayList<>();

        // Count the frequency of each number across all arrays
        for (int[] array : arrays) {
            for (int num : array) {
                frequencies.put(num, frequencies.getOrDefault(num, 0) + 1);
                // If the number appears in all arrays, add it to the result
                if (frequencies.get(num) == arrays.length) {
                    longestCommonSubseq.add(num);
                }
            }
        }

        return longestCommonSubseq;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        frequencies = defaultdict(int)
        longest_common_subseq = []

        # Count the frequency of each number across all arrays
        for array in arrays:
            for num in array:
                frequencies[num] += 1
                # Num is in all of the arrays
                if frequencies[num] == len(arrays):
                    longest_common_subseq.append(num)

        return longest_common_subseq
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
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> longestCommonSubseq = arrays[0];

        // Iterate through the rest of the arrays and
        // If the common subsequence is empty, return immediately
        // Else update the longest common subsequence
        for (int i = 1; i < arrays.size(); i++) {
            if (longestCommonSubseq.empty()) {
                return longestCommonSubseq;
            }
            longestCommonSubseq = longestSeq(longestCommonSubseq, arrays[i]);
        }

        return longestCommonSubseq;
    }

private:
    vector<int> longestSeq(vector<int>& nums1, vector<int>& nums2) {
        vector<int> longestCommonSeq;
        int first = 0;
        int second = 0;

        // Traverse through both arrays with two pointers
        // Increment the pointer with a smaller value at that index
        // When the values are equal, add to the longest common subsequence
        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                longestCommonSeq.push_back(nums1[first]);
                first++;
                second++;
            }
        }
        return longestCommonSeq;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        List<Integer> longestCommonSubseq = new ArrayList<>();
        for (int num : arrays[0]) {
            longestCommonSubseq.add(num);
        }

        // Iterate through the rest of the arrays and
        // If the common subsequence is empty, return immediately
        // Else update the longest common subsequence
        for (int i = 1; i < arrays.length; i++) {
            if (longestCommonSubseq.isEmpty()) {
                return longestCommonSubseq;
            }
            longestCommonSubseq = longestSeq(longestCommonSubseq, arrays[i]);
        }

        return longestCommonSubseq;
    }

    private List<Integer> longestSeq(List<Integer> nums1, int[] nums2) {
        List<Integer> longestCommonSeq = new ArrayList<>();
        int first = 0;
        int second = 0;

        // Traverse through both arrays with two pointers
        // Increment the pointer with a smaller value at that index
        // When the values are equal, add to the longest common subsequence
        while (first < nums1.size() && second < nums2.length) {
            if (nums1.get(first) < nums2[second]) {
                first++;
            } else if (nums1.get(first) > nums2[second]) {
                second++;
            } else {
                longestCommonSeq.add(nums1.get(first));
                first++;
                second++;
            }
        }
        return longestCommonSeq;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:

        def longest_seq(nums1, nums2):
            longest_common_seq = []
            first = 0
            second = 0

            # Traverse through both arrays with two pointers
            # Increment the pointer with a smaller value at that index
            # When the values are equal, add to the longest common subsequence
            while first < len(nums1) and second < len(nums2):
                if nums1[first] < nums2[second]:
                    first += 1
                elif nums1[first] > nums2[second]:
                    second += 1
                else:
                    longest_common_seq.append(nums1[first])
                    first += 1
                    second += 1

            return longest_common_seq

        # Iterate through the rest of the arrays and
        # If the common subsequence is empty, return immediately
        # Else update the longest common subsequence
        longest_common_subseq = arrays[0]
        for i in range(1, len(arrays)):
            if len(longest_common_subseq) == 0:
                return longest_common_subseq
            longest_common_subseq = longest_seq(
                longest_common_subseq, arrays[i]
            )

        return longest_common_subseq
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
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> shortestArray = arrays[0];
        for (const auto& array : arrays) {
            if (array.size() < shortestArray.size()) {
                shortestArray = array;
            }
        }

        vector<int> longestCommonSubseq(shortestArray.begin(),
                                        shortestArray.end());

        for (const auto& array : arrays) {
            // There are no elements that are common to all of the arrays
            if (longestCommonSubseq.empty()) {
                return longestCommonSubseq;
            }

            // Remove any elements from the longest common subsequence
            // that are not in current array
            vector<int> uncommon;
            for (int num : longestCommonSubseq) {
                if (!binarySearch(num, array)) {
                    uncommon.push_back(num);
                }
            }
            for (int num : uncommon) {
                longestCommonSubseq.erase(
                    remove(longestCommonSubseq.begin(),
                           longestCommonSubseq.end(), num),
                    longestCommonSubseq.end());
            }
        }

        return longestCommonSubseq;
    }

private:
    bool binarySearch(int target, const vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> longestCommonSubsequence(int[][] arrays) {
        int[] shortestArray = arrays[0];
        for (int[] array : arrays) {
            if (array.length < shortestArray.length) {
                shortestArray = array;
            }
        }

        List<Integer> longestCommonSubseq = new ArrayList<>();
        for (int num : shortestArray) {
            longestCommonSubseq.add(num);
        }

        for (int[] array : arrays) {
            // There are no elements that are common to all of the arrays
            if (longestCommonSubseq.isEmpty()) {
                return longestCommonSubseq;
            }

            // Remove any elements from the longest common subsequence
            // that are not in current array
            List<Integer> uncommon = new ArrayList<>();
            for (Integer num : longestCommonSubseq) {
                if (!binarySearch(num, array)) uncommon.add(num);
            }
            for (Integer num : uncommon) {
                longestCommonSubseq.remove(num);
            }
        }

        return longestCommonSubseq;
    }

    private boolean binarySearch(int target, int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:

        def binary_search(target, nums):
            left = 0
            right = len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    return True
            return False

        shortestArray = arrays[0]
        for array in arrays:
            if len(array) < len(shortestArray):
                shortestArray = array

        longest_common_subseq = shortestArray

        for array in arrays:
            # There are no elements that are common to all of the arrays
            if len(longest_common_subseq) == 0:
                return longest_common_subseq
            uncommon = []

            # Remove any elements from the longest common subsequence
            # that are not in current array
            for num in longest_common_subseq:
                if not binary_search(num, array):
                    uncommon.append(num)
            for num in uncommon:
                longest_common_subseq.remove(num)

        return longest_common_subseq
```

</details>
