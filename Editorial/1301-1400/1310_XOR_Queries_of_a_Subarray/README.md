# 1310. XOR Queries of a Subarray

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/xor-queries-of-a-subarray/)  
`Array` `Bit Manipulation` `Prefix Sum`

**Problem Link:** [LeetCode 1310 - XOR Queries of a Subarray](https://leetcode.com/problems/xor-queries-of-a-subarray/)

## Problem

You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

### Example 1

```text
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8]
Explanation:
The binary representation of the elements in the array are:
1 = 0001
3 = 0011
4 = 0100
8 = 1000
The XOR values for queries are:
[0,1] = 1 xor 3 = 2
[1,2] = 3 xor 4 = 7
[0,3] = 1 xor 3 xor 4 xor 8 = 14
[3,3] = 8
```

### Example 2

```text
Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
```

## Constraints

- 1 <= arr.length, queries.length <= 3 * 104
- 1 <= arr[i] <= 109
- queries[i].length == 2
- 0 <= lefti <= righti < arr.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1310. XOR Queries of a Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Approach | C++, Java, Python3 |
| Prefix XOR Array | C++, Java, Python3 |
| In place Prefix XOR | C++, Java, Python3 |

## Approach 1: Iterative Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        // Process each query
        for (const auto& q : queries) {
            int xorSum = 0;
            // Calculate XOR for the range [q[0], q[1]]
            for (int i = q[0]; i <= q[1]; i++) {
                xorSum ^= arr[i];
            }
            result.push_back(xorSum);
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] result = new int[queries.length];
        // Process each query
        for (int i = 0; i < queries.length; i++) {
            int xorSum = 0;
            // Calculate XOR for the range [q[0], q[1]]
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                xorSum ^= arr[j];
            }
            result[i] = xorSum;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        result = []
        # Process each query
        for q in queries:
            xor_sum = 0
            # Calculate XOR for the range [q[0], q[1]]
            for i in range(q[0], q[1] + 1):
                xor_sum ^= arr[i]
            result.append(xor_sum)
        return result
```

</details>

<br>

## Approach 2: Prefix XOR Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);

        // Build prefix XOR array
        for (int i = 0; i < n; i++) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        vector<int> result;
        // Process each query using prefix XOR
        for (const auto& q : queries) {
            result.push_back(prefixXOR[q[1] + 1] ^ prefixXOR[q[0]]);
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] prefixXOR = new int[n + 1];

        // Build prefix XOR array
        for (int i = 0; i < n; i++) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        int[] result = new int[queries.length];
        // Process each query using prefix XOR
        for (int i = 0; i < queries.length; i++) {
            result[i] = prefixXOR[queries[i][1] + 1] ^ prefixXOR[queries[i][0]];
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        # Build prefix XOR array
        prefix_xor = [0] * (len(arr) + 1)
        for i in range(len(arr)):
            prefix_xor[i + 1] = prefix_xor[i] ^ arr[i]

        # Store the XOR result for each query in a variable
        result = [prefix_xor[r + 1] ^ prefix_xor[l] for l, r in queries]
        return result
```

</details>

<br>

## Approach 3: In place Prefix XOR

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;

        // Step 1: Convert arr into an in-place prefix XOR array
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i - 1];
        }

        // Step 2: Resolve each query using the prefix XOR array
        for (const auto& q : queries) {
            if (q[0] > 0) {
                result.push_back(arr[q[0] - 1] ^ arr[q[1]]);
            } else {
                result.push_back(arr[q[1]]);
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] xorQueries(int[] arr, int[][] queries) {
        List<Integer> result = new ArrayList<>();

        // Step 1: Convert arr into an in-place prefix XOR array
        for (int i = 1; i < arr.length; ++i) {
            arr[i] ^= arr[i - 1];
        }

        // Step 2: Resolve each query using the prefix XOR array
        for (int[] q : queries) {
            if (q[0] > 0) {
                result.add(arr[q[0] - 1] ^ arr[q[1]]);
            } else {
                result.add(arr[q[1]]);
            }
        }

        return result.stream().mapToInt(i -> i).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def xorQueries(self, arr, queries):
        result = []

        # Step 1: Convert arr into an in-place prefix XOR array
        for i in range(1, len(arr)):
            arr[i] ^= arr[i - 1]

        # Step 2: Resolve each query using the prefix XOR array
        for left, right in queries:
            if left > 0:
                result.append(arr[left - 1] ^ arr[right])
            else:
                result.append(arr[right])

        return result
```

</details>
