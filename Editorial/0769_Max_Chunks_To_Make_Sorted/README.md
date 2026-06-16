# 769. Max Chunks To Make Sorted

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/max-chunks-to-make-sorted/)  
`Array` `Stack` `Greedy` `Sorting` `Monotonic Stack`

**Problem Link:** [LeetCode 769 - Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted/)

## Problem

You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

### Example 1

```text
Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
```

### Example 2

```text
Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
```

## Constraints

- n == arr.length
- 1 <= n <= 10
- 0 <= arr[i] < n
- All the elements of arr are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Chunks To Make Sorted II](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 769. Max Chunks To Make Sorted

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| PrefixMax and SuffixMin Arrays | C++, Java, Python3 |
| Prefix Sums | C++, Java, Python3 |
| Monotonic Increasing Stack | C++, Java, Python3 |
| Maximum Element | C++, Java, Python3 |

## Approach 1: PrefixMax and SuffixMin Arrays

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax = arr;
        vector<int> suffixMin = arr;

        // Fill the prefixMax array
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }

        // Fill the suffixMin array in reverse order
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n; i++) {
            // A new chunk can be created
            if (i == 0 || suffixMin[i] > prefixMax[i - 1]) chunks++;
        }

        return chunks;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int[] prefixMax = arr.clone();
        int[] suffixMin = arr.clone();

        // Fill the prefixMax array
        for (int i = 1; i < n; i++) {
            prefixMax[i] = Math.max(prefixMax[i - 1], prefixMax[i]);
        }

        // Fill the suffixMin array in reverse order
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = Math.min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n; i++) {
            // A new chunk can be created
            if (i == 0 || suffixMin[i] > prefixMax[i - 1]) {
                chunks++;
            }
        }

        return chunks;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxChunksToSorted(self, arr):
        n = len(arr)
        prefix_max = arr[:]
        suffix_min = arr[:]

        # Fill the prefix_max array
        for i in range(1, n):
            prefix_max[i] = max(prefix_max[i - 1], prefix_max[i])

        # Fill the suffix_min array in reverse order
        for i in range(n - 2, -1, -1):
            suffix_min[i] = min(suffix_min[i + 1], suffix_min[i])

        chunks = 0
        for i in range(n):
            # A new chunk can be created
            if i == 0 or suffix_min[i] > prefix_max[i - 1]:
                chunks += 1

        return chunks
```

</details>

<br>

## Approach 2: Prefix Sums

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update prefix sum of `arr`
            prefixSum += arr[i];
            // Update prefix sum of the sorted array
            sortedPrefixSum += i;

            // If the two sums are equal, the two prefixes contain the same
            // elements; a chunk can be formed
            if (prefixSum == sortedPrefixSum) {
                chunks++;
            }
        }
        return chunks;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update prefix sum of `arr`
            prefixSum += arr[i];
            // Update prefix sum of the sorted array
            sortedPrefixSum += i;

            // If the two sums are equal, the two prefixes contain the same elements; a chunk can be formed
            if (prefixSum == sortedPrefixSum) {
                chunks++;
            }
        }
        return chunks;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxChunksToSorted(self, arr: list[int]) -> int:
        n = len(arr)
        chunks = 0
        prefix_sum = 0
        sorted_prefix_sum = 0

        # Iterate over the array
        for i in range(n):
            # Update prefix sum of `arr`
            prefix_sum += arr[i]
            # Update prefix sum of the sorted array
            sorted_prefix_sum += i

            # If the two sums are equal, the two prefixes contain the same elements; a chunk can be formed
            if prefix_sum == sorted_prefix_sum:
                chunks += 1

        return chunks
```

</details>

<br>

## Approach 3: Monotonic Increasing Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        // Stack to store the maximum elements of each chunk
        stack<int> monotonicStack;
        for (int i = 0; i < n; i++) {
            // Case 1: Current element is larger, starts a new chunk
            if (monotonicStack.empty() || arr[i] > monotonicStack.top()) {
                monotonicStack.push(arr[i]);
            } else {
                // Case 2: Merge chunks
                int maxElement = monotonicStack.top();
                while (!monotonicStack.empty() &&
                       arr[i] < monotonicStack.top()) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        // Stack to store the maximum elements of each chunk
        Stack<Integer> monotonicStack = new Stack<>();

        for (int i = 0; i < n; i++) {
            // Case 1: Current element is larger, starts a new chunk
            if (monotonicStack.isEmpty() || arr[i] > monotonicStack.peek()) {
                monotonicStack.push(arr[i]);
            } else {
                // Case 2: Merge chunks
                int maxElement = monotonicStack.peek();
                while (
                    !monotonicStack.isEmpty() && arr[i] < monotonicStack.peek()
                ) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxChunksToSorted(self, arr):
        n = len(arr)
        # Deque to store the maximum elements of each chunk
        stack = deque()

        for i in range(n):
            # Case 1: Current element is larger, starts a new chunk
            if not stack or arr[i] > stack[-1]:
                stack.append(arr[i])
            else:
                # Case 2: Merge chunks
                max_element = stack[-1]
                while stack and arr[i] < stack[-1]:
                    stack.pop()
                stack.append(max_element)

        return len(stack)
```

</details>

<br>

## Approach 4: Maximum Element

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, maxElement = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update maxElement
            maxElement = max(maxElement, arr[i]);

            if (maxElement == i) {
                // All values in range [0, i] belong to the prefix arr[0:i];
                // a new chunk can be formed
                chunks++;
            }
        }

        return chunks;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int chunks = 0, maxElement = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update maxElement
            maxElement = Math.max(maxElement, arr[i]);

            if (maxElement == i) {
                // All values in range [0, i] belong to the prefix arr[0:i]; a new chunk can be formed
                chunks++;
            }
        }

        return chunks;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxChunksToSorted(self, arr):
        n = len(arr)
        chunks = 0
        max_element = 0

        # Iterate over the array
        for i in range(n):
            # Update max_element
            max_element = max(max_element, arr[i])

            if max_element == i:
                # All values in range [0, i] belong to the prefix arr[0:i]; a chunk can be formed
                chunks += 1

        return chunks
```

</details>
