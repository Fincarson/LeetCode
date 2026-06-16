# 1122. Relative Sort Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/relative-sort-array/)  
`Array` `Hash Table` `Sorting` `Counting Sort`

**Problem Link:** [LeetCode 1122 - Relative Sort Array](https://leetcode.com/problems/relative-sort-array/)

## Problem

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

### Example 1

```text
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
```

### Example 2

```text
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
```

## Constraints

- 1 <= arr1.length, arr2.length <= 1000
- 0 <= arr1[i], arr2[i] <= 1000
- All the elements of arr2 are distinct.
- Each arr2[i] is in arr1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1122. Relative Sort Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Two Loops and Sorting | C++, Java, Python3 |
| Using Hash Map for Counting and Sorting | C++, Java, Python3 |
| Using Counting Sort | C++, Java, Python3 |

## Approach 1: Using Two Loops and Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        // Traverse through the relative order array
        for (int i = 0; i < arr2.size(); i++) {
            // Traverse through the target array
            for (int j = 0; j < arr1.size(); j++) {
                // If element in target array matches with
                // relative order element
                if (arr1[j] == arr2[i]) {
                    // Add it to the result array
                    result.push_back(arr1[j]);
                    // Mark the element in target array as visited
                    arr1[j] = -1;
                }
            }
        }
        // Sort the remaining elements in the target array
        sort(arr1.begin(), arr1.end());
        // Add the remaining elements to the result array
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != -1) {
                result.push_back(arr1[i]);
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

    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        List<Integer> result = new ArrayList<>();

        // Traverse through the relative order array
        for (int i = 0; i < arr2.length; i++) {
            // Traverse through the target array
            for (int j = 0; j < arr1.length; j++) {
                // If element in target array matches with relative order element
                if (arr1[j] == arr2[i]) {
                    // Add it to the result array
                    result.add(arr1[j]);
                    // Mark the element in target array as visited
                    arr1[j] = -1;
                }
            }
        }

        // Sort the remaining elements in the target array
        Arrays.sort(arr1);
        // Add the remaining elements to the result array
        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != -1) {
                result.add(arr1[i]);
            }
        }

        // Convert ArrayList to array
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        result = []
        # Traverse through the relative order array
        for value in arr2:
            # Traverse through the target array
            for j in range(len(arr1)):
                # Element in target array matches with relative order element
                if arr1[j] == value:
                    # Add it to the result array
                    result.append(arr1[j])
                    # Mark the element in target array as visited
                    arr1[j] = -1
        # Sort the remaining elements in the target array
        arr1.sort()
        # Add the remaining elements to the result array
        for value in arr1:
            if value != -1:
                result.append(value)
        return result
```

</details>

<br>

## Approach 2: Using Hash Map for Counting and Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap;
        vector<int> remaining, result;
        // Initialize count map with relative order elements
        for (int i = 0; i < arr2.size(); i++) {
            countMap[arr2[i]] = 0;
        }
        // Count occurrences of elements in target array
        for (int i = 0; i < arr1.size(); i++) {
            if (countMap.find(arr1[i]) != countMap.end()) {
                countMap[arr1[i]]++;
            } else {
                remaining.push_back(arr1[i]);
            }
        }
        // Sort the remaining elements
        sort(remaining.begin(), remaining.end());
        // Add elements as per relative order
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < countMap[arr2[i]]; j++) {
                result.push_back(arr2[i]);
            }
        }
        // Add remaining elements
        for (int i = 0; i < remaining.size(); i++) {
            result.push_back(remaining[i]);
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

    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer> countMap = new HashMap<>();
        List<Integer> remaining = new ArrayList<>();
        List<Integer> result = new ArrayList<>();

        // Initialize count map with relative order elements
        for (int value : arr2) {
            countMap.put(value, 0);
        }

        // Count occurrences of elements in target array
        for (int value : arr1) {
            if (countMap.containsKey(value)) {
                countMap.put(value, countMap.get(value) + 1);
            } else {
                remaining.add(value);
            }
        }

        // Sort the remaining elements
        Collections.sort(remaining);

        // Add elements as per relative order
        for (int value : arr2) {
            for (int j = 0; j < countMap.get(value); j++) {
                result.add(value);
            }
        }

        // Add remaining elements
        result.addAll(remaining);

        // Convert ArrayList to array
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count_map = {}
        remaining = []
        result = []
        # Initialize count map with relative order elements
        for value in arr2:
            count_map[value] = 0
        # Count occurrences of elements in target array
        for value in arr1:
            if value in count_map:
                count_map[value] += 1
            else:
                remaining.append(value)
        # Sort the remaining elements
        remaining.sort()
        # Add elements as per relative order
        for value in arr2:
            for _ in range(count_map[value]):
                result.append(value)
        # Add remaining elements
        result.extend(remaining)
        return result
```

</details>

<br>

## Approach 3: Using Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxElement + 1);

        // Count occurrences of each element
        for (int element : arr1) {
            count[element]++;
        }

        vector<int> result;
        // Add elements as per relative order
        for (int element : arr2) {
            while (count[element] > 0) {
                result.push_back(element);
                count[element]--;
            }
        }
        // Add remaining elements in ascending order
        for (int num = 0; num <= maxElement; num++) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
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

    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int maxElement = Arrays.stream(arr1).max().orElse(0);
        int[] count = new int[maxElement + 1];

        // Count occurrences of each element
        for (int element : arr1) {
            count[element]++;
        }

        List<Integer> result = new ArrayList<>();
        // Add elements as per relative order
        for (int value : arr2) {
            while (count[value] > 0) {
                result.add(value);
                count[value]--;
            }
        }

        // Add remaining elements in ascending order
        for (int num = 0; num <= maxElement; num++) {
            while (count[num] > 0) {
                result.add(num);
                count[num]--;
            }
        }

        // Convert ArrayList to array
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        max_element = max(arr1)
        count = [0] * (max_element + 1)

        # Count occurrences of each element
        for element in arr1:
            count[element] += 1

        # Add elements as per relative order
        result = []
        for value in arr2:
            while count[value] > 0:
                result.append(value)
                count[value] -= 1

        # Add remaining elements in ascending order
        for num in range(max_element + 1):
            while count[num] > 0:
                result.append(num)
                count[num] -= 1

        return result
```

</details>
