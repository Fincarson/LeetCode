# 1442. Count Triplets That Can Form Two Arrays of Equal XOR

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)  
`Array` `Hash Table` `Math` `Bit Manipulation` `Prefix Sum`

**Problem Link:** [LeetCode 1442 - Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)

## Problem

Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

- a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
- b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

### Example 1

```text
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
```

### Example 2

```text
Input: arr = [1,1,1,1,1]
Output: 10
```

## Constraints

- 1 <= arr.length <= 300
- 1 <= arr[i] <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find The Original Array of Prefix Xor](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1442. Count Triplets That Can Form Two Arrays of Equal XOR

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force With Prefix | C++, Java, Python3 |
| Nested Prefix **XOR** | C++, Java, Python3 |
| Two Pass Prefix **XOR** | C++, Java, Python3 |
| One Pass Prefix **XOR** | C++, Java, Python3 |

## Approach 1: Brute Force With Prefix

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;

        // Iterate over each possible starting index i
        for (int start = 0; start < arr.size() - 1; ++start) {
            // Initialize XOR value for the subarray from start to mid-1
            int xorA = 0;

            // Iterate over each possible middle index j
            for (int mid = start + 1; mid < arr.size(); ++mid) {
                // Update xorA to include arr[mid - 1]
                xorA ^= arr[mid - 1];

                // Initialize XOR value for the subarray from mid to end
                int xorB = 0;

                // Iterate over each possible ending index k (starting from mid)
                for (int end = mid; end < arr.size(); ++end) {
                    // Update xorB to include arr[end]
                    xorB ^= arr[end];

                    // found a valid triplet (start, mid, end)
                    if (xorA == xorB) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countTriplets(int[] arr) {
        int count = 0;

        // Iterate over each possible starting index i
        for (int start = 0; start < arr.length - 1; ++start) {
            // Initialize XOR value for the subarray from start to mid-1
            int xorA = 0;

            // Iterate over each possible middle index j
            for (int mid = start + 1; mid < arr.length; ++mid) {
                // Update xorA to include arr[mid - 1]
                xorA ^= arr[mid - 1];

                // Initialize XOR value for the subarray from mid to end
                int xorB = 0;

                // Iterate over each possible ending index k (starting from mid)
                for (int end = mid; end < arr.length; ++end) {
                    // Update xorB to include arr[end]
                    xorB ^= arr[end];

                    // found a valid triplet (start, mid, end)
                    if (xorA == xorB) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        count = 0

        # Iterate over each possible starting index i
        for start in range(len(arr) - 1):
            # Initialize XOR value for the subarray from start to mid-1
            xor_A = 0

            # Iterate over each possible middle index j
            for mid in range(start + 1, len(arr)):
                # Update xor_A to include arr[mid - 1]
                xor_A ^= arr[mid - 1]

                # Initialize XOR value for the subarray from mid to end
                xor_B = 0

                # Iterate over each possible ending index k (starting from mid)
                for end in range(mid, len(arr)):
                    # Update xor_B to include arr[end]
                    xor_B ^= arr[end]

                    # found a valid triplet (start, mid, end)
                    if xor_A == xor_B:
                        count += 1

        return count
```

</details>

<br>

## Approach 2: Nested Prefix **XOR**

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(arr.begin(), arr.end());
        prefixXOR.insert(prefixXOR.begin(), 0);
        int size = prefixXOR.size();

        // Perform XOR on consecutive elements in the modified array
        for (int i = 1; i < size; ++i) prefixXOR[i] ^= prefixXOR[i - 1];

        int count = 0;

        // Iterate through the prefix XOR array to count triplets
        for (int start = 0; start < size; ++start) {
            for (int end = start + 1; end < size; ++end) {
                if (prefixXOR[start] == prefixXOR[end]) {
                    // Increment the result by the count of valid triplets
                    count += end - start - 1;
                }
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int countTriplets(int[] arr) {
        int[] prefixXOR = new int[arr.length + 1];
        prefixXOR[0] = 0;
        System.arraycopy(arr, 0, prefixXOR, 1, arr.length);
        int size = prefixXOR.length;

        // Perform XOR on consecutive elements in the modified array
        for (int i = 1; i < size; i++) {
            prefixXOR[i] ^= prefixXOR[i - 1];
        }

        int count = 0;

        // Iterate through the modified array to count triplets
        for (int start = 0; start < size; start++) {
            for (int end = start + 1; end < size; end++) {
                if (prefixXOR[start] == prefixXOR[end]) {
                    // Increment the result by the count of valid triplets
                    count += end - start - 1;
                }
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        prefix_XOR = [0] + arr[:]
        size = len(prefix_XOR)

        # Perform XOR on consecutive elements in the modified array
        for i in range(1, size):
            prefix_XOR[i] ^= prefix_XOR[i - 1]

        count = 0

        # Iterate through the modified array to count triplets
        for start in range(size):
            for end in range(start + 1, size):
                if prefix_XOR[start] == prefix_XOR[end]:
                    # Increment the result by the count of valid triplets
                    count += end - start - 1

        return count
```

</details>

<br>

## Approach 3: Two Pass Prefix **XOR**

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXOR(arr.begin(), arr.end());
        prefixXOR.insert(prefixXOR.begin(), 0);
        int size = prefixXOR.size();
        int count = 0;

        // Performing XOR operation on the array elements
        for (int i = 1; i < size; ++i) prefixXOR[i] ^= prefixXOR[i - 1];

        // Maps to store counts and totals of XOR values encountered
        unordered_map<int, int> countMap, totalMap;

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating contribution of current element to the result
            count +=
                countMap[prefixXOR[i]]++ * (i - 1) - totalMap[prefixXOR[i]];

            // Updating total count of current XOR value
            totalMap[prefixXOR[i]] += i;
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countTriplets(int[] arr) {
        int[] prefixXOR = new int[arr.length + 1];
        prefixXOR[0] = 0;
        System.arraycopy(arr, 0, prefixXOR, 1, arr.length);
        int size = prefixXOR.length;
        int count = 0;

        // Performing XOR operation on the array elements
        for (int i = 1; i < size; ++i) prefixXOR[i] ^= prefixXOR[i - 1];

        // Maps to store counts and totals of XOR values encountered
        HashMap<Integer, Integer> countMap = new HashMap<>();
        HashMap<Integer, Integer> totalMap = new HashMap<>();

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating contribution of current element to the result
            count +=
            countMap.getOrDefault(prefixXOR[i], 0) * (i - 1) -
            totalMap.getOrDefault(prefixXOR[i], 0);

            // Updating total count of current XOR value
            totalMap.put(
                prefixXOR[i],
                totalMap.getOrDefault(prefixXOR[i], 0) + i
            );
            countMap.put(
                prefixXOR[i],
                countMap.getOrDefault(prefixXOR[i], 0) + 1
            );
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        prefix_XOR = [0] + arr
        size = len(prefix_XOR)
        count = 0

        # Performing XOR operation on the array elements
        for i in range(1, size):
            prefix_XOR[i] ^= prefix_XOR[i - 1]

        # Dictionaries to store counts and totals of XOR values encountered
        count_map = defaultdict(int)
        total_map = defaultdict(int)

        # Iterating through the array
        for i in range(size):
            # Calculating contribution of current element to the result
            count += (
                count_map[prefix_XOR[i]] * (i - 1) - total_map[prefix_XOR[i]]
            )

            # Updating total count of current XOR value
            total_map[prefix_XOR[i]] += i
            count_map[prefix_XOR[i]] += 1

        return count
```

</details>

<br>

## Approach 4: One Pass Prefix **XOR**

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        int count = 0;
        int prefix = 0;

        // Maps to store counts and totals of XOR values encountered
        unordered_map<int, int> countMap = {{0, 1}}, totalMap;

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating XOR prefix
            prefix ^= arr[i];

            // Calculating contribution of current element to the result
            count += countMap[prefix]++ * i - totalMap[prefix];

            // Updating total count of current XOR value
            totalMap[prefix] += i + 1;
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countTriplets(int[] arr) {
        int size = arr.length;
        int count = 0;
        int prefix = 0;

        // Maps to store counts and totals of XOR values encountered
        Map<Integer, Integer> countMap = new HashMap<>();
        countMap.put(0, 1);
        Map<Integer, Integer> totalMap = new HashMap<>();

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating XOR prefix
            prefix ^= arr[i];

            // Calculating contribution of current element to the result
            count +=
            countMap.getOrDefault(prefix, 0) * i -
            totalMap.getOrDefault(prefix, 0);

            // Updating total count of current XOR value
            totalMap.put(prefix, totalMap.getOrDefault(prefix, 0) + i + 1);
            countMap.put(prefix, countMap.getOrDefault(prefix, 0) + 1);
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        size = len(arr)
        count = 0
        prefix = 0

        # Dictionaries to store counts and totals of XOR values encountered
        count_map = defaultdict(int)
        count_map[0] = 1
        total_map = defaultdict(int)

        # Iterating through the array
        for i in range(size):
            # Calculating XOR prefix
            prefix ^= arr[i]

            # Calculating contribution of current element to the result
            count += count_map[prefix] * i - total_map[prefix]

            # Updating total count of current XOR value
            total_map[prefix] += i + 1
            count_map[prefix] += 1

        return count
```

</details>
