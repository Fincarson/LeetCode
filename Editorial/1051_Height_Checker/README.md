# 1051. Height Checker

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/height-checker/)  
`Array` `Sorting` `Counting Sort`

**Problem Link:** [LeetCode 1051 - Height Checker](https://leetcode.com/problems/height-checker/)

## Problem

A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].

### Example 1

```text
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
```

### Example 2

```text
Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
```

### Example 3

```text
Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
```

## Constraints

- 1 <= heights.length <= 100
- 1 <= heights[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1051. Height Checker

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bubble Sort | C++, Java, Python3 |
| Merge Sort | C++, Java, Python3 |
| Heap Sort | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |
| Radix Sort | C++, Java, Python3 |

## Approach 1: Bubble Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Function to perform bubble sort on the input array.
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        // Loop through the array for bubble sort passes.
        for (int i = 0; i < n - 1; ++i) {
            // Inner loop to compare and swap elements.
            for (int j = 0; j < n - i - 1; ++j) {
                // Compare and swap if elements are in the wrong order.
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        // Sort the array using bubble sort.
        vector<int> sortedHeights = heights;
        bubbleSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.size(); ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Function to perform bubble sort on the input array.
    private void bubbleSort(int[] arr) {
        int n = arr.length;
        // Loop through the array for bubble sort passes.
        for (int i = 0; i < n - 1; ++i) {
            // Inner loop to compare and swap elements.
            for (int j = 0; j < n - i - 1; ++j) {
                // Compare and swap if elements are in the wrong order.
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public int heightChecker(int[] heights) {
        // Sort the array using bubble sort.
        int[] sortedHeights = heights.clone();
        bubbleSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.length; ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        # Function to perform bubble sort on the input array.
        def bubble_sort():
            n = len(sorted_heights)
            # Loop through the array for bubble sort passes.
            for i in range(n - 1):
                # Inner loop to compare and swap elements.
                for j in range(n - i - 1):
                    # Compare and swap if elements are in the wrong order.
                    if sorted_heights[j] > sorted_heights[j + 1]:
                        sorted_heights[j], sorted_heights[j + 1] = (
                            sorted_heights[j + 1],
                            sorted_heights[j],
                        )

        # Sort the array using bubble sort.
        sorted_heights = heights[:]
        bubble_sort()

        count = 0
        # Loop through the original and sorted arrays.
        for i in range(len(sorted_heights)):
            # Increment count if elements at the same index differ.
            if heights[i] != sorted_heights[i]:
                count += 1
        # Return the total count of differing elements.
        return count
```

</details>

<br>

## Approach 2: Merge Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Function to merge two sub-arrays in sorted order.
    void merge(vector<int>& arr, int left, int mid, int right,
               vector<int>& tempArr) {
        // Calculate the start and sizes of two halves.
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Copy elements of both halves into a temporary array.
        for (int i = 0; i < n1; i++) {
            tempArr[start1 + i] = arr[start1 + i];
        }
        for (int i = 0; i < n2; i++) {
            tempArr[start2 + i] = arr[start2 + i];
        }

        // Merge the sub-arrays in 'tempArr' back into the original array
        // 'arr' in sorted order.
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (tempArr[start1 + i] <= tempArr[start2 + j]) {
                arr[k] = tempArr[start1 + i];
                i += 1;
            } else {
                arr[k] = tempArr[start2 + j];
                j += 1;
            }
            k += 1;
        }

        // Copy remaining elements
        while (i < n1) {
            arr[k] = tempArr[start1 + i];
            i += 1;
            k += 1;
        }
        while (j < n2) {
            arr[k] = tempArr[start2 + j];
            j += 1;
            k += 1;
        }
    }

    // Recursive function to sort an array using merge sort.
    void mergeSort(vector<int>& arr, int left, int right,
                   vector<int>& tempArr) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        // Sort first and second halves recursively.
        mergeSort(arr, left, mid, tempArr);
        mergeSort(arr, mid + 1, right, tempArr);
        // Merge the sorted halves.
        merge(arr, left, mid, right, tempArr);
    }

public:
    int heightChecker(vector<int>& heights) {
        // Sort the array using merge sort.
        vector<int> sortedHeights = heights;
        vector<int> tempArray(heights.size());
        mergeSort(sortedHeights, 0, sortedHeights.size() - 1, tempArray);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.size(); ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Function to merge two sub-arrays in sorted order.
    private void merge(int[] arr, int left, int mid, int right, int[] tempArr) {
        // Calculate the start and sizes of two halves.
        int start1 = left;
        int start2 = mid + 1;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Copy elements of both halves into a temporary array.
        for (int i = 0; i < n1; i++) {
            tempArr[start1 + i] = arr[start1 + i];
        }
        for (int i = 0; i < n2; i++) {
            tempArr[start2 + i] = arr[start2 + i];
        }

        // Merge the sub-arrays in 'tempArr' back into the original array 'arr' in
        // sorted order.
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (tempArr[start1 + i] <= tempArr[start2 + j]) {
                arr[k] = tempArr[start1 + i];
                i += 1;
            } else {
                arr[k] = tempArr[start2 + j];
                j += 1;
            }
            k += 1;
        }

        // Copy remaining elements
        while (i < n1) {
            arr[k] = tempArr[start1 + i];
            i += 1;
            k += 1;
        }
        while (j < n2) {
            arr[k] = tempArr[start2 + j];
            j += 1;
            k += 1;
        }
    }

    // Recursive function to sort an array using merge sort.
    private void mergeSort(int[] arr, int left, int right, int[] tempArr) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        // Sort first and second halves recursively.
        mergeSort(arr, left, mid, tempArr);
        mergeSort(arr, mid + 1, right, tempArr);
        // Merge the sorted halves.
        merge(arr, left, mid, right, tempArr);
    }

    public int heightChecker(int[] heights) {
        // Sort the array using merge sort.
        int[] sortedHeights = heights.clone();
        int[] tempArray = new int[heights.length];
        mergeSort(sortedHeights, 0, sortedHeights.length - 1, tempArray);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.length; ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Function to merge two sub-arrays in sorted order.
    def merge(self, arr, left, mid, right, temp_arr):
        # Calculate the start and sizes of two halves.
        start1 = left
        start2 = mid + 1
        n1 = mid - left + 1
        n2 = right - mid

        # Copy elements of both halves into a temporary array.
        for i in range(n1):
            temp_arr[start1 + i] = arr[start1 + i]
        for i in range(n2):
            temp_arr[start2 + i] = arr[start2 + i]

        # Merge the sub-arrays in 'temp_arr' back into the original array 'arr' in sorted order.
        i, j, k = 0, 0, left
        while i < n1 and j < n2:
            if temp_arr[start1 + i] <= temp_arr[start2 + j]:
                arr[k] = temp_arr[start1 + i]
                i += 1
            else:
                arr[k] = temp_arr[start2 + j]
                j += 1
            k += 1

        # Copy remaining elements
        while i < n1:
            arr[k] = temp_arr[start1 + i]
            i += 1
            k += 1
        while j < n2:
            arr[k] = temp_arr[start2 + j]
            j += 1
            k += 1

    # Recursive function to sort an array using merge sort.
    def merge_sort(self, arr, left, right, temp_arr):
        if left >= right:
            return
        mid = (left + right) // 2
        # Sort first and second halves recursively.
        self.merge_sort(arr, left, mid, temp_arr)
        self.merge_sort(arr, mid + 1, right, temp_arr)
        # Merge the sorted halves.
        self.merge(arr, left, mid, right, temp_arr)

    def heightChecker(self, heights: List[int]) -> int:
        # Sort the array using merge sort.
        sorted_heights = heights[:]
        temp_arr = [0] * len(heights)
        self.merge_sort(sorted_heights, 0, len(sorted_heights) - 1, temp_arr)

        count = 0
        # Loop through the original and sorted arrays.
        for i in range(len(sorted_heights)):
            # Increment count if elements at the same index differ.
            if heights[i] != sorted_heights[i]:
                count += 1
        # Return the total count of differing elements.
        return count
```

</details>

<br>

## Approach 3: Heap Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Function to max heapify a subtree (in top-down order) rooted at index i.
    void heapify(vector<int>& arr, int n, int i) {
        // Initialize largest as root 'i'.
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If the left child is larger than the root.
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If the right child is larger than the largest so far.
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root swap root with the largest element
        // Recursively heapify the affected sub-tree (i.e. move down).
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();
        // Build heap; heapify all elements except leaf nodes, in bottom-up
        // order.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Traverse elements one by one, to move the current root to the end,
        // and
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            // call max heapify on the reduced array.
            heapify(arr, i, 0);
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        // Sort the array using heap sort.
        vector<int> sortedHeights = heights;
        heapSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.size(); ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Function to max heapify a subtree (in top-down order) rooted at index i.
    private void heapify(int[] arr, int n, int i) {
        // Initialize largest as root 'i'.
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If the left child is larger than the root.
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If the right child is larger than the largest so far.
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root swap root with the largest element
        // Recursively heapify the affected sub-tree (i.e. move down).
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(arr, n, largest);
        }
    }

    private void heapSort(int[] arr) {
        int n = arr.length;
        // Build heap; heapify all elements except leaf nodes, in bottom-up order.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Traverse elements one by one, to move the current root to the end, and
        for (int i = n - 1; i >= 0; i--) {
            int swap = arr[0];
            arr[0] = arr[i];
            arr[i] = swap;
            // call max heapify on the reduced array.
            heapify(arr, i, 0);
        }
    }

    public int heightChecker(int[] heights) {
        // Sort the array using heap sort.
        int[] sortedHeights = heights.clone();
        heapSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.length; ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Function to max heapify a subtree (in top-down order) rooted at index i.
    def heapify(self, arr, n, i):
        # Initialize largest as root 'i'.
        largest, left, right = i, 2 * i + 1, 2 * i + 2

        # If the left child is larger than the root.
        if left < n and arr[left] > arr[largest]:
            largest = left

        # If the right child is larger than the largest so far.
        if right < n and arr[right] > arr[largest]:
            largest = right

        # If largest is not root swap root with the largest element
        # Recursively heapify the affected sub-tree (i.e. move down).
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            self.heapify(arr, n, largest)

    def heap_sort(self, arr):
        n = len(arr)
        # Build heap; heapify all elements except leaf nodes, in bottom-up order.
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(arr, n, i)

        # Traverse elements one by one, to move the current root to the end, and
        for i in range(n - 1, 0, -1):
            arr[0], arr[i] = arr[i], arr[0]
            # call max heapify on the reduced array.
            self.heapify(arr, i, 0)

    def heightChecker(self, heights: List[int]) -> int:
        # Sort the array using heap sort.
        sorted_heights = heights[:]
        self.heap_sort(sorted_heights)

        count = 0
        # Loop through the original and sorted arrays.
        for i in range(len(sorted_heights)):
            # Increment count if elements at the same index differ.
            if heights[i] != sorted_heights[i]:
                count += 1
        # Return the total count of differing elements.
        return count
```

</details>

<br>

## Approach 4: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    void countingSort(vector<int>& arr) {
        // Create the counting hash map.
        unordered_map<int, int> counts;
        // Find the minimum and maximum values in the array.
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        // Update element's count in the hash map.
        for (auto& val : arr) {
            counts[val]++;
        }

        int index = 0;
        // Place each element in its correct position in the array.
        for (int val = minVal; val <= maxVal; ++val) {
            // Append all 'val's together if they exist.
            while (counts[val] > 0) {
                arr[index] = val;
                index += 1;
                counts[val] -= 1;
            }
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        // Sort the array using counting sort.
        vector<int> sortedHeights = heights;
        countingSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.size(); ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private void countingSort(int[] arr) {
        // Create the counting hash map.
        Map<Integer, Integer> counts = new HashMap<>();
        // Find the minimum and maximum values in the array.
        int minVal = Arrays.stream(arr).min().getAsInt();
        int maxVal = Arrays.stream(arr).max().getAsInt();

        // Update element's count in the hash map.
        for (int val : arr) {
            counts.put(val, counts.getOrDefault(val, 0) + 1);
        }

        int index = 0;
        // Place each element in its correct position in the array.
        for (int val = minVal; val <= maxVal; ++val) {
            // Append all 'val's together if they exist.
            while (counts.getOrDefault(val, 0) > 0) {
                arr[index] = val;
                index += 1;
                counts.put(val, counts.get(val) - 1);
            }
        }
    }

    public int heightChecker(int[] heights) {
        // Sort the array using counting sort.
        int[] sortedHeights = heights.clone();
        countingSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.length; ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def counting_sort(self, arr):
        # Create the counting hash map.
        counts = {}
        # Find the minimum and maximum values in the array.
        min_val, max_val = min(arr), max(arr)

        # Update element's count in the hash map.
        for val in arr:
            if val in counts:
                counts[val] += 1
            else:
                counts[val] = 1

        index = 0
        # Place each element in its correct position in the array.
        for val in range(min_val, max_val + 1):
            # Append all 'val's together if they exist.
            while counts.get(val, 0) > 0:
                arr[index] = val
                index += 1
                counts[val] -= 1

    def heightChecker(self, heights: List[int]) -> int:
        # Sort the array using counting sort.
        sorted_heights = heights[:]
        self.counting_sort(sorted_heights)

        count = 0
        # Loop through the original and sorted arrays.
        for i in range(len(sorted_heights)):
            # Increment count if elements at the same index differ.
            if heights[i] != sorted_heights[i]:
                count += 1
        # Return the total count of differing elements.
        return count
```

</details>

<br>

## Approach 5: Radix Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Bucket sort function for each place value digit.
    void bucketSort(vector<int>& arr, int placeValue) {
        vector<vector<int>> buckets(10, vector<int>());
        // Store the respective number based on its digit.
        for (int& val : arr) {
            int digit = abs(val) / placeValue;
            digit = digit % 10;
            buckets[digit].push_back(val);
        }

        // Overwrite 'arr' in sorted order of current place digits.
        int index = 0;
        for (int digit = 0; digit < 10; ++digit) {
            for (int& val : buckets[digit]) {
                arr[index] = val;
                index++;
            }
        }
    }

    // Radix sort function.
    void radixSort(vector<int>& arr) {
        // Find the absolute maximum element to find max number of digits.
        int maxElement = arr[0];
        for (int& val : arr) {
            maxElement = max(abs(val), maxElement);
        }
        int maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++digit) {
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        // Sort the array using radix sort.
        vector<int> sortedHeights = heights;
        radixSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.size(); ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Bucket sort function for each place value digit.
    private void bucketSort(int[] arr, int placeValue) {
        List<List<Integer>> buckets = new ArrayList<>(10);
        for (int i = 0; i < 10; i++) {
            buckets.add(new ArrayList<>());
        }

        // Store the respective number based on its digit.
        for (int val : arr) {
            int digit = Math.abs(val) / placeValue;
            digit = digit % 10;
            buckets.get(digit).add(val);
        }

        // Overwrite 'arr' in sorted order of current place digits.
        int index = 0;
        for (int digit = 0; digit < 10; ++digit) {
            for (int val : buckets.get(digit)) {
                arr[index] = val;
                index++;
            }
        }
    }

    // Radix sort function.
    private void radixSort(int[] arr) {
        // Find the absolute maximum element to find max number of digits.
        int maxElement = Arrays.stream(arr).map(Math::abs).max().getAsInt();
        int maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++digit) {
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }
    }

    public int heightChecker(int[] heights) {
        // Sort the array using radix sort.
        int[] sortedHeights = heights.clone();
        radixSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.length; ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Bucket sort function for each place value digit.
    def bucket_sort(self, arr, place_value):
        buckets = [[] for _ in range(10)]

        # Store the respective number based on its digit.
        for val in arr:
            digit = abs(val) // place_value
            digit = digit % 10
            buckets[digit].append(val)

        # Overwrite 'arr' in sorted order of current place digits.
        index = 0
        for digit in range(10):
            for val in buckets[digit]:
                arr[index] = val
                index += 1

    # Radix sort function.
    def radix_sort(self, arr):
        # Find the absolute maximum element to find max number of digits.
        max_element, max_digits = max(abs(val) for val in arr), 0
        while max_element > 0:
            max_digits += 1
            max_element //= 10

        # Radix sort, least significant digit place to most significant.
        place_value = 1
        for _ in range(max_digits):
            self.bucket_sort(arr, place_value)
            place_value *= 10

    def heightChecker(self, heights: List[int]) -> int:
        # Sort the array using radix sort.
        sorted_heights = heights[:]
        self.radix_sort(sorted_heights)

        count = 0
        # Loop through the original and sorted arrays.
        for i in range(len(sorted_heights)):
            # Increment count if elements at the same index differ.
            if heights[i] != sorted_heights[i]:
                count += 1
        # Return the total count of differing elements.
        return count
```

</details>
