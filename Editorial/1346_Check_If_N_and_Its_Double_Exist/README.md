# 1346. Check If N and Its Double Exist

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-if-n-and-its-double-exist/)  
`Array` `Hash Table` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 1346 - Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist/)

## Problem

Given an array arr of integers, check if there exist two indices i and j such that :

- i != j
- 0 <= i, j < arr.length
- arr[i] == 2 * arr[j]

### Example 1

```text
Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
```

### Example 2

```text
Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
```

## Constraints

- 2 <= arr.length <= 500
- -103 <= arr[i] <= 103

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1346. Check If N and Its Double Exist

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Set Lookup | C++, Java, Python3 |
| Sorting + Binary Search | C++, Java, Python3 |
| Frequency Hash Map | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Step 1: Iterate through all pairs of indices
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                // Step 2: Check the conditions
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        // No valid pair found
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkIfExist(int[] arr) {
        // Step 1: Iterate through all pairs of indices
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                // Step 2: Check the conditions
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        // No valid pair found
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        # Step 1: Iterate through all pairs of indices
        for i in range(len(arr)):
            for j in range(len(arr)):
                # Step 2: Check the conditions
                if i != j and arr[i] == 2 * arr[j]:
                    return True
        # No valid pair found
        return False
```

</details>

<br>

## Approach 2: Set Lookup

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int num : arr) {
            // Check if 2 * num or num / 2 exists in the set
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }
        // No valid pair found
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkIfExist(int[] arr) {
        Set<Integer> seen = new HashSet<>();

        for (int num : arr) {
            // Check if 2 * num or num / 2 exists in the set
            if (
                seen.contains(2 * num) ||
                (num % 2 == 0 && seen.contains(num / 2))
            ) {
                return true;
            }
            // Add the current number to the set
            seen.add(num);
        }
        // No valid pair found
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        for num in arr:
            # Check if 2 * num or num / 2 exists in the set
            if 2 * num in seen or (num % 2 == 0 and num // 2 in seen):
                return True
            # Add the current number to the set
            seen.add(num)
        # No valid pair found
        return False
```

</details>

<br>

## Approach 3: Sorting + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            // Step 2: Calculate the target (double of current number)
            int target = 2 * arr[i];
            // Step 3: Custom binary search for the target
            int index = customBinarySearch(arr, target);
            // If the target exists and is not the same index
            if (index >= 0 && index != i) {
                return true;
            }
        }
        // No valid pair found
        return false;
    }

private:
    int customBinarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            // Avoid potential overflow
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Target not found
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean checkIfExist(int[] arr) {
        // Step 1: Sort the array
        Arrays.sort(arr);

        for (int i = 0; i < arr.length; i++) {
            // Step 2: Calculate the target (double of current number)
            int target = 2 * arr[i];
            // Step 3: Custom binary search for the target
            int index = customBinarySearch(arr, target);
            // If the target exists and is not the same index
            if (index >= 0 && index != i) {
                return true;
            }
        }
        // No valid pair found
        return false;
    }

    //Implementation of binary search
    private int customBinarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            // Avoid potential overflow
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Target not found
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        # Step 1: Sort the array
        arr.sort()

        for i in range(len(arr)):
            # Step 2: Calculate the target (double of current number)
            target = 2 * arr[i]
            # Step 3: Custom binary search for the target
            index = self._custom_binary_search(arr, target)
            # If the target exists and is not the same index
            if index >= 0 and index != i:
                return True
        # No valid pair found
        return False

    def _custom_binary_search(self, arr: List[int], target: int) -> int:
        left, right = 0, len(arr) - 1

        while left <= right:
            # Avoid potential overflow
            mid = left + (right - left) // 2

            if arr[mid] == target:
                return mid
            elif arr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return -1  # Target not found
```

</details>

<br>

## Approach 4: Frequency Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;

        // Count occurrences of each number
        for (int num : arr) {
            map[num]++;
        }

        for (int num : arr) {
            // Check for double
            if (num != 0 && map.find(2 * num) != map.end()) {
                return true;
            }
            // Handle zero case (ensure there are at least two zeros)
            if (num == 0 && map[num] > 1) {
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

    public boolean checkIfExist(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : arr) {
            // Count occurrences of each number
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int num : arr) {
            // Check for double
            if (num != 0 && map.containsKey(2 * num)) {
                return true;
            }
            // Handle zero case (ensure there are at least two zeros)
            if (num == 0 && map.get(num) > 1) {
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
    def checkIfExist(self, arr: List[int]) -> bool:
        count = {}

        # Count occurrences of each number
        for num in arr:
            count[num] = count.get(num, 0) + 1

        for num in arr:
            # Check for double
            if num != 0 and 2 * num in count:
                return True
            # Handle zero case (ensure there are at least two zeros)
            if num == 0 and count[num] > 1:
                return True

        return False
```

</details>
