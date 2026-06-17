# 912. Sort an Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sort-an-array/)  
`Array` `Divide and Conquer` `Sorting` `Heap (Priority Queue)` `Merge Sort` `Bucket Sort` `Radix Sort` `Counting Sort`

**Problem Link:** [LeetCode 912 - Sort an Array](https://leetcode.com/problems/sort-an-array/)

## Problem

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

### Example 1

```text
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
```

### Example 2

```text
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
```

## Constraints

- 1 <= nums.length <= 5 * 104
- -5 * 104 <= nums[i] <= 5 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 912. Sort an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Merge Sort | C++, Java, JavaScript, Python3 |
| Heap Sort | C++, Java, JavaScript, Python3 |
| Counting Sort | C++, Java, JavaScript, Python3 |
| Radix Sort | C++, Java, JavaScript, Python3 |

## Approach 1: Merge Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Function to merge two sub-arrays in sorted order.
    void merge(vector<int> &arr, int left, int mid, int right, vector<int> &tempArr) {
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

        // Merge the sub-arrays 'in tempArray' back into the original array 'arr' in sorted order.
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

    // Recursive function to sort an array using merge sort
    void mergeSort(vector<int> &arr, int left, int right, vector<int> &tempArr) {
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
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temporaryArray(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temporaryArray);
        return nums;
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

        // Merge the sub-arrays 'in tempArray' back into the original array 'arr' in sorted order.
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

    // Recursive function to sort an array using merge sort
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
    
    public int[] sortArray(int[] nums) {
        int[] temporaryArray = new int[nums.length];
        mergeSort(nums, 0, nums.length - 1, temporaryArray);
        return nums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortArray = function(nums) {
    let tempArr = Array(nums.length).fill(0);
    
    // Function to merge two sub-arrays in sorted order.
    let merge = (left, mid, right) => {
        // Calculate the start and sizes of two halves.
        let start1 = left;
        let start2 = mid + 1;
        let n1 = mid - left + 1;
        let n2 = right - mid;
        
        // Copy elements of both halves into a temporary array.
        for (let i = 0; i < n1; i++) {
            tempArr[start1 + i] = nums[start1 + i];
        }
        for (let i = 0; i < n2; i++) {
            tempArr[start2 + i] = nums[start2 + i];
        }

        // Merge the sub-arrays 'in tempArray' back into the original array 'arr' in sorted order.
        let i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (tempArr[start1 + i] <= tempArr[start2 + j]) {
                nums[k] = tempArr[start1 + i];
                i += 1;
            } else {
                nums[k] = tempArr[start2 + j];
                j += 1;
            }
            k += 1;
        }

        // Copy remaining elements
        while (i < n1) {
            nums[k] = tempArr[start1 + i];
            i += 1;
            k += 1;
        }
        while (j < n2) {
            nums[k] = tempArr[start2 + j];
            j += 1;
            k += 1;
        }
    }

    // Recursive function to sort an array using merge sort
    let mergeSort = (left, right) => {
        if (left >= right) {
            return;
        }
        let mid = Math.floor((left + right) / 2);
        // Sort first and second halves recursively.
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        // Merge the sorted halves.
        merge(left, mid, right);
    }
    
    mergeSort(0, nums.length - 1);
    return nums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        temp_arr = [0] * len(nums)
        
        # Function to merge two sub-arrays in sorted order.
        def merge(left: int, mid: int, right: int):
            # Calculate the start and sizes of two halves.
            start1 = left
            start2 = mid + 1
            n1 = mid - left + 1
            n2 = right - mid

            # Copy elements of both halves into a temporary array.
            for i in range(n1):
                temp_arr[start1 + i] = nums[start1 + i]
            for i in range(n2):
                temp_arr[start2 + i] = nums[start2 + i]

            # Merge the sub-arrays 'in tempArray' back into the original array 'arr' in sorted order.
            i, j, k = 0, 0, left
            while i < n1 and j < n2:
                if temp_arr[start1 + i] <= temp_arr[start2 + j]:
                    nums[k] = temp_arr[start1 + i]
                    i += 1
                else:
                    nums[k] = temp_arr[start2 + j]
                    j += 1
                k += 1

            # Copy remaining elements
            while i < n1:
                nums[k] = temp_arr[start1 + i]
                i += 1
                k += 1
            while j < n2:
                nums[k] = temp_arr[start2 + j]
                j += 1
                k += 1

        # Recursive function to sort an array using merge sort
        def merge_sort(left: int, right: int):
            if left >= right:
                return
            mid = (left + right) // 2
            # Sort first and second halves recursively.
            merge_sort(left, mid)
            merge_sort(mid + 1, right)
            # Merge the sorted halves.
            merge(left, mid, right)
    
        merge_sort(0, len(nums) - 1)
        return nums
```

</details>

<br>

## Approach 2: Heap Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Function to heapify a subtree (in top-down order) rooted at index i.
    void heapify(vector<int>& arr, int n, int i) {
        // Initialize largest as root 'i'.
        int largest = i; 
        int left = 2 * i + 1;
        int right = 2 * i + 2; 

        // If left child is larger than root.
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than largest so far.
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root swap root with largest element
        // Recursively heapify the affected sub-tree (i.e. move down).
        if (largest != i) {
            swap(arr[i], arr[largest]); 
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();
        // Build heap; heapify (top-down) all elements except leaf nodes.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Traverse elements one by one, to move current root to end, and
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            // call max heapify on the reduced heap.
            heapify(arr, i, 0);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    
    // Function to heapify a subtree (in top-down order) rooted at index i.
    private void heapify(int[] arr, int n, int i) {
        // Initialize largest as root 'i'.
        int largest = i; 
        int left = 2 * i + 1;
        int right = 2 * i + 2; 

        // If left child is larger than root.
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than largest so far.
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root swap root with largest element
        // Recursively heapify the affected sub-tree (i.e. move down).
        if (largest != i) {
            swap(arr, i, largest); 
            heapify(arr, n, largest);
        }
    }

    private void heapSort(int[] arr) {
        int n = arr.length;
        // Build heap; heapify (top-down) all elements except leaf nodes.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Traverse elements one by one, to move current root to end, and
        for (int i = n - 1; i >= 0; i--) {
            swap(arr, 0, i);
            // call max heapify on the reduced heap.
            heapify(arr, i, 0);
        }
    }

    public int[] sortArray(int[] nums) {
        heapSort(nums);
        return nums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortArray = function(nums) {
    // Function to heapify a subtree (in top-down order) rooted at index i.
    let heapify = (n, i) => {
        // Initialize largest as root 'i'.
        let largest = i; 
        let left = 2 * i + 1;
        let right = 2 * i + 2; 
        // If left child is larger than root.
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        // If right child is larger than largest so far.
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        // If largest is not root swap root with largest element
        // Recursively heapify the affected sub-tree (i.e. move down).
        if (largest != i) {
            [nums[i], nums[largest]] = [nums[largest], nums[i]];
            heapify(n, largest);
        }
    }

    let heapSort = () => {
        let n = nums.length;
        // Build heap; heapify (top-down) all elements except leaf nodes.
        for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
            heapify(n, i);
        }
        // Traverse elements one by one, to move current root to end, and
        for (let i = n - 1; i > 0; i--) {
            [nums[0], nums[i]] = [nums[i], nums[0]];
            // call max heapify on the reduced heap.
            heapify(i, 0);
        }
    }
    
    heapSort();
    return nums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # Function to heapify a subtree (in top-down order) rooted at index i.
        def heapify(n: int, i: int):
            # Initialize largest as root 'i'.
            largest = i;
            left = 2 * i + 1
            right = 2 * i + 2
            # If left child is larger than root.
            if left < n and nums[left] > nums[largest]:
                largest = left
            # If right child is larger than largest so far.
            if right < n and nums[right] > nums[largest]:
                largest = right
            # If largest is not root swap root with largest element
            # Recursively heapify the affected sub-tree (i.e. move down).
            if largest != i:
                nums[i], nums[largest] =  nums[largest], nums[i]
                heapify(n, largest)

        def heap_sort():
            n = len(nums)
            # Build heap; heapify (top-down) all elements except leaf nodes.
            for i in range(n // 2 - 1, -1, -1):
                heapify(n, i)
            # Traverse elements one by one, to move current root to end, and
            for i in range(n - 1, -1, -1):
                nums[0], nums[i] = nums[i], nums[0]
                # call max heapify on the reduced heap.
                heapify(i, 0)

        heap_sort()
        return nums
```

</details>

<br>

## Approach 3: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    void countingSort(vector<int> &arr) {
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
            if (counts.find(val) != counts.end()) {
                while (counts[val] > 0) {
                    arr[index] = val;
                    index += 1;
                    counts[val] -= 1;
                }
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        countingSort(nums);
        return nums;
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
        HashMap<Integer,Integer> counts = new HashMap<>();
        int minVal = arr[0], maxVal = arr[0];
        
        // Find the minimum and maximum values in the array,
        // and update it's count in the hash map.
        for (int i = 0; i < arr.length; i++) {
            minVal = Math.min(minVal, arr[i]);
            maxVal = Math.max(maxVal, arr[i]);
            counts.put(arr[i], counts.getOrDefault(arr[i], 0) + 1);
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

    public int[] sortArray(int[] nums) {
        countingSort(nums);
        return nums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortArray = function(nums) {
    let countingSort = () => {
        // Create the counting hash map.
        let counts = {};
        // Find the minimum and maximum values in the array.
        let minVal = Math.min(...nums); 
        let maxVal = Math.max(...nums); 

        // Update element's count in the hash map.
        nums.forEach(val => { 
            if (counts[val] == undefined) {
                counts[val] = 0;
            }
            counts[val] += 1 
        });
        
        let index = 0;
        // Place each element in its correct position in the array.
        for (let val = minVal; val <= maxVal; val += 1) {
            // Append all 'val's together if they exist.
            while (counts[val] > 0) {
                nums[index] = val;
                index += 1;
                counts[val] -= 1;
            }
        }
    }
    
    countingSort(nums);
    return nums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def counting_sort():
            # Create the counting hash map.
            counts = {}
            # Find the minimum and maximum values in the array.
            minVal, maxVal = min(nums), max(nums)
            # Update element's count in the hash map.
            for val in nums:
                counts[val] = counts.get(val, 0) + 1

            index = 0
            # Place each element in its correct position in the array.
            for val in range(minVal, maxVal + 1, 1):
                # Append all 'val's together if they exist.
                while counts.get(val, 0) > 0:
                    nums[index] = val
                    index += 1
                    counts[val] -= 1

        counting_sort()
        return nums
```

</details>

<br>

## Approach 4: Radix Sort

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

        // Seperate out negatives and reverse them. 
        vector<int> negatives, positives;
        for (int& val : arr) {
            if (val < 0) {
                negatives.push_back(val);
            } else {
                positives.push_back(val);
            }
        }
        reverse(negatives.begin(), negatives.end());
        // Final 'arr' will be 'negative' elements, then 'positive' elements.
        merge(negatives.begin(), negatives.end(), positives.begin(), positives.end(), arr.begin());
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        radixSort(nums);
        return nums;
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
        ArrayList<List<Integer>> buckets = new ArrayList<>(10);
        for (int digit = 0; digit < 10; ++digit) {
            buckets.add(digit, new ArrayList<Integer>());
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
        int maxElement = arr[0];
        for (int val : arr) {
            maxElement = Math.max(Math.abs(val), maxElement);
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

        // Seperate out negatives and reverse them. 
        ArrayList<Integer> negatives = new ArrayList<>();
        ArrayList<Integer> positives = new ArrayList<>();
        for (int val : arr) {
            if (val < 0) {
                negatives.add(val);
            } else {
                positives.add(val);
            }
        }
        Collections.reverse(negatives);

        // Final 'answer' will be 'negative' elements, then 'positive' elements.
        int index = 0;
        for (int val : negatives) {
            arr[index] = val;
            index++;
        }
        for (int val : positives) {
            arr[index] = val;
            index++;
        }
    }

    public int[] sortArray(int[] nums) {
        radixSort(nums);
        return nums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortArray = function(nums) {
    // Counting sort function for each place value digit.
    let countingSort = placeValue => {
        let mapDigits = {};
        // Store the respective number based on it's digit.
        nums.forEach(val => {
            let digit = Math.floor(Math.abs(val) / placeValue);
            digit = digit % 10;
            
            if (mapDigits[digit] == undefined) {
                mapDigits[digit] = [];
            }
            mapDigits[digit].push(val);
        });

        // Overwrite 'nums' in sorted order of current place digits.
        let index = 0;
        for (let digit = 0; digit < 10; ++digit) {
            if (mapDigits[digit] == undefined) { 
                continue; 
            }
            mapDigits[digit].forEach(val => {
                nums[index] = val;
                index++;
            });
        }
    }
    
    // Radix sort function
    let radixSort = () => {
        // Find the absolute maximum element to find max number of digits.
        let maxElement = nums[0];
        nums.forEach(val => {
            maxElement = Math.max(Math.abs(val), maxElement);
        });
        let maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        let placeValue = 1;
        for (let digit = 0; digit < maxDigits; ++digit) {
            countingSort(placeValue);
            placeValue *= 10;
        }

        // Seperate out negatives and reverse them. 
        let negatives = [];
        let positives = [];
        nums.forEach(val => {
            if (val < 0) {
                negatives.push(val);
            } else {
                positives.push(val);
            }
        });
        negatives.reverse();
        // Final 'nums' will be 'negative' elements, then 'positive' elements.
        nums = [...negatives, ...positives];
    }
    
    radixSort(nums);
    return nums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Radix sort function.
    def radix_sort(self, nums: List[int]) -> List[int]:
        # Find the absolute maximum element to find max number of digits.
        max_element = nums[0]
        for val in nums:
            max_element = max(abs(val), max_element)

        max_digits = 0
        while max_element > 0:
            max_digits += 1
            max_element = max_element // 10

        place_value = 1
        
        # Bucket sort function for each place value digit.
        def bucket_sort():
            buckets = [[] for i in range(10)]
            # Store the respective number based on it's digit.
            for val in nums:
                digit = abs(val) / place_value
                digit = int(digit % 10)
                buckets[digit].append(val)

            # Overwrite 'nums' in sorted order of current place digits.
            index = 0
            for digit in range(10):
                for val in buckets[digit]:
                    nums[index] = val
                    index += 1

        # Radix sort, least significant digit place to most significant.      
        for _ in range(max_digits):
            bucket_sort()
            place_value *= 10

        # Seperate out negatives and reverse them. 
        positives = [val for val in nums if val >= 0]
        negatives = [val for val in nums if val < 0]
        negatives.reverse()

        # Final 'arr' will be 'negative' elements, then 'positive' elements.
        return negatives + positives
            
    def sortArray(self, nums: List[int]) -> List[int]:  
        return self.radix_sort(nums)
```

</details>
