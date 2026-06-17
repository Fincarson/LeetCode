# 1331. Rank Transform of an Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/rank-transform-of-an-array/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 1331 - Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array/)

## Problem

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

- Rank is an integer starting from 1.
- The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
- Rank should be as small as possible.

### Example 1

```text
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
```

### Example 2

```text
Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
```

### Example 3

```text
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
```

## Constraints

- 0 <= arr.length <= 105
- -109 <= arr[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rank Transform of a Matrix](https://leetcode.com/problems/rank-transform-of-a-matrix/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1331. Rank Transform of an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting + Hash Map | C++, Java, Python3 |
| Deduplicating with Set | C++, Java, Python3 |
| Ordered Map | C++, Java, Python3 |

## Approach 1: Sorting + Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Store the rank for each number in arr
        map<int, int> numToRank;
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int rank = 1;
        for (int i = 0; i < sortedArr.size(); i++) {
            if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
                rank++;
            }
            numToRank[sortedArr[i]] = rank;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] arrayRankTransform(int[] arr) {
        // Store the rank for each number in arr
        HashMap<Integer, Integer> numToRank = new HashMap<>();
        int[] sortedArr = Arrays.copyOf(arr, arr.length);
        Arrays.sort(sortedArr);
        int rank = 1;
        for (int i = 0; i < sortedArr.length; i++) {
            if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
                rank++;
            }
            numToRank.put(sortedArr[i], rank);
        }
        for (int i = 0; i < arr.length; i++) {
            arr[i] = numToRank.get(arr[i]);
        }
        return arr;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # Store the rank for each number in arr
        num_to_rank = {}
        sorted_arr = sorted(arr)
        rank = 1
        for i in range(len(sorted_arr)):
            if i > 0 and sorted_arr[i] > sorted_arr[i - 1]:
                rank += 1
            num_to_rank[sorted_arr[i]] = rank
        for i in range(len(arr)):
            arr[i] = num_to_rank[arr[i]]
        return arr
```

</details>

<br>

## Approach 2: Deduplicating with Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Store the rank for each number in arr
        unordered_map<int, int> numToRank;
        // Deduplicate and sort arr
        set<int> nums(arr.begin(), arr.end());
        int rank = 1;
        for (auto num : nums) {
            numToRank[num] = rank;
            rank++;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] arrayRankTransform(int[] arr) {
        // Store the rank for each number in arr
        HashMap<Integer, Integer> numToRank = new HashMap<>();
        // Deduplicate and sort arr
        TreeSet<Integer> nums = new TreeSet<>();
        for (int num : arr) nums.add(num);
        int rank = 1;
        for (int num : nums) {
            numToRank.put(num, rank);
            rank++;
        }
        for (int i = 0; i < arr.length; i++) {
            arr[i] = numToRank.get(arr[i]);
        }
        return arr;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # Store the rank for each number in arr
        num_to_rank = {}
        # Deduplicate and sort arr
        nums = sorted(set(arr))
        rank = 1
        for num in nums:
            num_to_rank[num] = rank
            rank += 1
        for i in range(len(arr)):
            arr[i] = num_to_rank[arr[i]]
        return arr
```

</details>

<br>

## Approach 3: Ordered Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Store the rank for each number in arr.
        map<int, vector<int>> numToIndices;

        for (int i = 0; i < arr.size(); i++) {
            numToIndices[arr[i]].push_back(i);
        }

        int rank = 1;
        for (auto& pair : numToIndices) {
            for (int index : pair.second) {
                arr[index] = rank;
            }
            rank++;
        }
        return arr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] arrayRankTransform(int[] arr) {
        // Store the rank for each number in arr
        TreeMap<Integer, List<Integer>> numToIndices = new TreeMap<>();

        for (int i = 0; i < arr.length; i++) {
            if (!numToIndices.containsKey(arr[i])) {
                numToIndices.put(arr[i], new ArrayList<>());
            }
            numToIndices.get(arr[i]).add(i);
        }
        int rank = 1;
        for (int num : numToIndices.keySet()) {
            for (int index : numToIndices.get(num)) {
                arr[index] = rank;
            }
            rank++;
        }
        return arr;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # Store the rank for each number in arr
        num_to_indices = {k: [] for k in sorted(set(arr))}

        for i, num in enumerate(arr):
            num_to_indices[num].append(i)

        rank = 1
        for num in num_to_indices.keys():
            for index in num_to_indices[num]:
                arr[index] = rank
            rank += 1

        return arr
```

</details>
