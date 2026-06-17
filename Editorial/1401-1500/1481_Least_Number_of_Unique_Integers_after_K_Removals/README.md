# 1481. Least Number of Unique Integers after K Removals

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)  
`Array` `Hash Table` `Greedy` `Sorting` `Counting`

**Problem Link:** [LeetCode 1481 - Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)

## Problem

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

### Example 1

```text
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
```

```text
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
```

## Constraints

- 1 <= arr.length <= 10^5
- 1 <= arr[i] <= 10^9
- 0 <= k <= arr.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Number of Distinct Elements After Operations](https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1481. Least Number of Unique Integers after K Removals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting the Frequencies | C++, Java, Python3 |
| Min-heap | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |

## Approach 1: Sorting the Frequencies

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        // Vector to track all the frequencies
        vector<int> frequencies;
        for (auto it : map) {
            frequencies.push_back(it.second);
        }

        // Sorting the frequencies
        sort(frequencies.begin(), frequencies.end());

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        for (int i = 0; i < frequencies.size(); i++) {
            // Removing frequencies[i] elements which equates to
            // removing one unique element
            elementsRemoved += frequencies[i];

            // If the number of elements removed exceeds k, we'll return
            // the remaining number of unique elements.
            if (elementsRemoved > k) {
                return frequencies.size() - i;
            }
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        // Map to track the frequencies of elements
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        // List to track all the frequencies
        List<Integer> frequencies = new ArrayList<>(map.values());

        // Sorting the frequencies
        Collections.sort(frequencies);

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        for (int i = 0; i < frequencies.size(); i++) {
            // Removing frequencies[i] elements, which equates to
            // removing one unique element
            elementsRemoved += frequencies.get(i);

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size() - i;
            }
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        # Dictionary to track the frequencies of elements
        freq_map = Counter(arr)

        # List to track all the frequencies
        frequencies = list(freq_map.values())

        # Sorting the frequencies
        frequencies.sort()

        # Tracking the number of elements removed
        elements_removed = 0

        for i in range(len(frequencies)):
            # Removing frequencies[i] elements, which equates to
            # removing one unique element
            elements_removed += frequencies[i]

            # If the number of elements removed exceeds k, return
            # the remaining number of unique elements
            if elements_removed > k:
                return len(frequencies) - i

        # We have removed all elements, so no unique integers remain
        # Return 0 in this case
        return 0
```

</details>

<br>

## Approach 2: Min-heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }
        
        // Min heap to track all the frequencies
        priority_queue<int, vector<int>, greater<int> > frequencies;
        for (auto it : map) {
            frequencies.push(it.second);
        }

        // Tracking the number of elements removed
        int elementsRemoved = 0;
        
        // Traversing all frequencies
        while (!frequencies.empty()) {
            // Removing the least frequent element
            elementsRemoved += frequencies.top();

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size();
            }
            frequencies.pop();
        }
        
        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        // Map to track the frequencies of elements
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        // Min heap to track all the frequencies
        PriorityQueue<Integer> frequencies = new PriorityQueue<>(map.values());

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        // Traversing all frequencies
        while (!frequencies.isEmpty()) {
            // Removing the least frequent element
            elementsRemoved += frequencies.peek();

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size();
            }
            frequencies.poll();
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        # Dictionary to track the frequencies of elements
        freq_map = Counter(arr)

        # Min heap to track all the frequencies
        frequencies = list(freq_map.values())
        heapq.heapify(frequencies)

        # Tracking the number of elements removed
        elements_removed = 0

        # Traversing all frequencies
        while frequencies:
            # Removing the least frequent element
            elements_removed += heapq.heappop(frequencies)

            # If the number of elements removed exceeds k, return
            # the remaining number of unique elements
            if elements_removed > k:
                # Add 1 for the remaining element
                return len(frequencies) + 1

        # We have removed all elements, so no unique integers remain
        # Return 0 in this case
        return 0
```

</details>

<br>

## Approach 3: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        int n = arr.size();

        // Array to track the frequencies of frequencies!
        // The maximum possible frequency of any element
        // will be n so we'll initialize this array with size n + 1
        vector<int> countOfFrequencies(n + 1, 0);

        // Popoulating countOfFrequencies array
        for (auto it : map) {
            countOfFrequencies[it.second]++;
        }

        // Variable to track the remaining number of unique elements
        int remainingUniqueElements = map.size();

        // Traversing over all possible frequencies
        for (int i = 1; i <= n; i++) {
            // For each possible frequency i, we'd like to remove as
            // many elements with that frequency as possible.
            // k / i represents the number of maximum possible elements
            // we could remove with k elements left to remove. 
            // countOfFrequencies[i] represents the actual number of elements
            // with frequency i. 
            int numElementsToRemove = min(k / i, countOfFrequencies[i]);

            // Removing maximum possible elements
            k -= (i * numElementsToRemove);

            // numElementsToRemove is the count of unique elements removed
            remainingUniqueElements -= numElementsToRemove;

            // If the number of elements that can be removed is less
            // than the current frequency, we won't be able to remove
            // any more elements with a higher frequency so we can return
            // the remaining number of unique elements
            if (k < i) {
                return remainingUniqueElements;
            }
        }

        // We have traversed all possible frequencies i.e.,
        // removed all elements. Returning 0 in this case.
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        // Map to track the frequencies of elements
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        int n = arr.length;

        // Array to track the frequencies of frequencies
        // The maximum possible frequency of any element
        // will be n, so we'll initialize this array with size n + 1
        int[] countOfFrequencies = new int[n + 1];

        // Populating countOfFrequencies array
        for (int count : map.values()) {
            countOfFrequencies[count]++;
        }

        // Variable to track the remaining number of unique elements
        int remainingUniqueElements = map.size();

        // Traversing over all possible frequencies
        for (int i = 1; i <= n; i++) {
            // For each possible frequency i, we'd like to remove as
            // many elements with that frequency as possible.
            // k / i represents the number of maximum possible elements
            // we could remove with k elements left to remove.
            // countOfFrequencies[i] represents the actual number of elements
            // with frequency i.
            int numElementsToRemove = Math.min(k / i, countOfFrequencies[i]);

            // Removing maximum possible elements
            k -= (i * numElementsToRemove);

            // numElementsToRemove is the count of unique elements removed
            remainingUniqueElements -= numElementsToRemove;

            // If the number of elements that can be removed is less
            // than the current frequency, we won't be able to remove
            // any more elements with a higher frequency so we can return
            // the remaining number of unique elements
            if (k < i) {
                return remainingUniqueElements;
            }
        }

        // We have traversed all possible frequencies i.e.,
        // removed all elements. Returning 0 in this case.
        return 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        # Dictionary to track the frequencies of elements
        map = {}
        for i in arr:
            map[i] = map.get(i, 0) + 1

        n = len(arr)

        # List to track the frequencies of frequencies
        # The maximum possible frequency of any element
        # will be n, so we'll initialize this list with size n + 1
        count_of_frequencies = [0] * (n + 1)

        # Populating count_of_frequencies list
        for count in map.values():
            count_of_frequencies[count] += 1

        # Variable to track the remaining number of unique elements
        remaining_unique_elements = len(map)

        # Traversing over all possible frequencies
        for i in range(1, n + 1):
            # For each possible frequency i, we'd like to remove as
            # many elements with that frequency as possible.
            # k // i represents the number of maximum possible elements
            # we could remove with k elements left to remove.
            # count_of_frequencies[i] represents the actual number of elements
            # with frequency i.
            num_elements_to_remove = min(k // i, count_of_frequencies[i])

            # Removing the maximum possible elements
            k -= (i * num_elements_to_remove)

            # num_elements_to_remove is the count of unique elements removed
            remaining_unique_elements -= num_elements_to_remove

            # If the number of elements that can be removed is less
            # than the current frequency, we won't be able to remove
            # any more elements with a higher frequency so we can return
            # the remaining number of unique elements
            if k < i:
                return remaining_unique_elements

        # We have traversed all possible frequencies i.e.,
        # removed all elements. Returning 0 in this case.
        return 0
```

</details>
