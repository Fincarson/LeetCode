# 2418. Sort the People

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/sort-the-people/)  
`Array` `Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 2418 - Sort the People](https://leetcode.com/problems/sort-the-people/)

## Problem

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

### Example 1

```text
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
```

### Example 2

```text
Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
```

## Constraints

- n == names.length == heights.length
- 1 <= n <= 103
- 1 <= names[i].length <= 20
- 1 <= heights[i] <= 105
- names[i] consists of lower and upper case English letters.
- All the values of heights are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sort the Students by Their Kth Score](https://leetcode.com/problems/sort-the-students-by-their-kth-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2418. Sort the People

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Map | C++, Java, Python3 |
| Sorted Map | C++, Java, Python3 |
| Sort Permutation | C++, Java, Python3 |
| Quick Sort | C++, Java, Python3 |
| Merge Sort | C++, Java, Python3 |

## Approach 1: Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int number_of_people = names.size();

        // Create a map to store height-name pairs
        unordered_map<int, string> height_to_name_map;

        // Populate the map with height as key and name as value
        for (int i = 0; i < number_of_people; i++) {
            height_to_name_map[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end());

        vector<string> sorted_names(number_of_people);

        // Populate sorted_names vector in descending order of height
        for (int i = number_of_people - 1; i >= 0; i--) {
            sorted_names[number_of_people - i - 1] =
                height_to_name_map[heights[i]];
        }

        return sorted_names;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        int numberOfPeople = names.length;

        // Create a map to store height-name pairs
        Map<Integer, String> heightToNameMap = new HashMap<>();

        // Populate the map with height as key and name as value
        for (int i = 0; i < numberOfPeople; i++) {
            heightToNameMap.put(heights[i], names[i]);
        }

        Arrays.sort(heights);

        String[] sortedNames = new String[numberOfPeople];

        // Populate sortedNames array in descending order of height
        for (int i = numberOfPeople - 1; i >= 0; i--) {
            sortedNames[numberOfPeople - i - 1] = heightToNameMap.get(
                heights[i]
            );
        }

        return sortedNames;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        number_of_people = len(names)

        # Create a dictionary to store height-name pairs
        height_to_name_map = dict(zip(heights, names))

        sorted_heights = sorted(heights, reverse=True)

        # Create a list of sorted names based on descending heights
        sorted_names = [height_to_name_map[height] for height in sorted_heights]

        return sorted_names
```

</details>

<br>

## Approach 2: Sorted Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int numberOfPeople = names.size();

        // Create a map to store height-name pairs (automatically sorted by
        // height)
        map<int, string> heightToNameMap;

        // Populate the map with height as key and name as value
        for (int i = 0; i < numberOfPeople; i++) {
            heightToNameMap[heights[i]] = names[i];
        }

        vector<string> sortedNames(numberOfPeople);

        // Index for filling sortedNames vector from end to start
        int currentIndex = numberOfPeople - 1;

        // Iterate through the map (sorted by height in ascending order)
        // and fill the sortedNames vector from end to start
        for (const auto& pair : heightToNameMap) {
            sortedNames[currentIndex] = pair.second;
            currentIndex--;
        }

        return sortedNames;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        int numberOfPeople = names.length;

        // Create a TreeMap to store height-name pairs (automatically sorted by height)
        TreeMap<Integer, String> heightToNameMap = new TreeMap<>();

        // Populate the map with height as key and name as value
        for (int i = 0; i < numberOfPeople; i++) {
            heightToNameMap.put(heights[i], names[i]);
        }

        String[] sortedNames = new String[numberOfPeople];

        // Index for filling sortedNames array from end to start
        int currentIndex = numberOfPeople - 1;

        // Iterate through the map (sorted by height in ascending order)
        // and fill the sortedNames array from end to start
        for (int height : heightToNameMap.keySet()) {
            sortedNames[currentIndex] = heightToNameMap.get(height);
            currentIndex--;
        }

        return sortedNames;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        number_of_people = len(names)

        height_to_name_map = OrderedDict()

        # Populate the OrderedDict with height as key and name as value
        for height, name in zip(heights, names):
            height_to_name_map[height] = name

        # Sort the OrderedDict by height in descending order
        height_to_name_map = OrderedDict(
            sorted(height_to_name_map.items(), reverse=True)
        )

        # Create a list of sorted names based on descending heights
        sorted_names = list(height_to_name_map.values())

        return sorted_names
```

</details>

<br>

## Approach 3: Sort Permutation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names,
                              const vector<int>& heights) {
        int numberOfPeople = names.size();

        // Create a permutation vector to store sorted indices
        vector<int> sortedIndices(numberOfPeople);
        iota(begin(sortedIndices), end(sortedIndices), 0);

        // Sort indices based on heights in descending order
        sort(begin(sortedIndices), end(sortedIndices),
             [&heights](int a, int b) { return heights[a] > heights[b]; });

        // Prepare the result vector to store sorted names
        vector<string> sortedNames;
        sortedNames.reserve(numberOfPeople);

        // Apply the sorted indices to rearrange names using a traditional for
        // loop
        for (int i = 0; i < numberOfPeople; i++) {
            sortedNames.push_back(move(names[sortedIndices[i]]));
        }

        return sortedNames;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        int numberOfPeople = names.length;

        // Create an array of indices
        Integer[] sortedIndices = new Integer[numberOfPeople];
        for (int i = 0; i < numberOfPeople; i++) {
            sortedIndices[i] = i;
        }

        // Sort indices based on heights in descending order
        Arrays.sort(sortedIndices, (a, b) -> heights[b] - heights[a]);

        // Apply the sorted indices to rearrange names
        String[] sortedNames = new String[numberOfPeople];
        for (int i = 0; i < numberOfPeople; i++) {
            sortedNames[i] = names[sortedIndices[i]];
        }

        return sortedNames;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        number_of_people = len(names)

        # Create a list of indices and sort them based on heights in descending order
        sorted_indices = sorted(
            range(number_of_people), key=lambda i: heights[i], reverse=True
        )

        # Apply the sorted indices to rearrange names
        sorted_names = [names[i] for i in sorted_indices]

        return sorted_names
```

</details>

<br>

## Approach 4: Quick Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        quickSort(heights, names, 0, heights.size() - 1);
        return names;
    }

private:
    void swap(vector<int>& heights, vector<string>& names, int index1,
              int index2) {
        // Swap heights
        int tempHeight = heights[index1];
        heights[index1] = heights[index2];
        heights[index2] = tempHeight;

        // Swap corresponding names
        string tempName = names[index1];
        names[index1] = names[index2];
        names[index2] = tempName;
    }

    int partition(vector<int>& heights, vector<string>& names, int start,
                  int end) {
        int pivot = heights[end];
        int i = start - 1;

        for (int j = start; j < end; j++) {
            // If current element is greater than or equal to pivot
            if (heights[j] >= pivot) {
                i++;
                swap(heights, names, i, j);
            }
        }
        // Place the pivot in its correct position
        swap(heights, names, i + 1, end);
        return i + 1;
    }

    void quickSort(vector<int>& heights, vector<string>& names, int start,
                   int end) {
        if (start < end) {
            // Find the partition index
            int partitionIndex = partition(heights, names, start, end);

            // Recursively sort the left and right sub-arrays
            quickSort(heights, names, start, partitionIndex - 1);
            quickSort(heights, names, partitionIndex + 1, end);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        quickSort(heights, names, 0, heights.length - 1);
        return names;
    }

    private void swap(int[] heights, String[] names, int index1, int index2) {
        // Swap heights
        int tempHeight = heights[index1];
        heights[index1] = heights[index2];
        heights[index2] = tempHeight;

        // Swap corresponding names
        String tempName = names[index1];
        names[index1] = names[index2];
        names[index2] = tempName;
    }

    private int partition(int[] heights, String[] names, int start, int end) {
        int pivot = heights[end];
        int i = start - 1;

        for (int j = start; j < end; j++) {
            // If current element is greater than or equal to pivot
            if (heights[j] >= pivot) {
                i++;
                swap(heights, names, i, j);
            }
        }
        // Place the pivot in its correct position
        swap(heights, names, i + 1, end);
        return i + 1;
    }

    private void quickSort(int[] heights, String[] names, int start, int end) {
        if (start < end) {
            // Find the partition index
            int partitionIndex = partition(heights, names, start, end);

            // Recursively sort the left and right sub-arrays
            quickSort(heights, names, start, partitionIndex - 1);
            quickSort(heights, names, partitionIndex + 1, end);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        self._quick_sort(heights, names, 0, len(heights) - 1)
        return names

    def _swap(
        self, heights: List[int], names: List[str], index1: int, index2: int
    ):
        # Swap heights
        heights[index1], heights[index2] = heights[index2], heights[index1]

        # Swap corresponding names
        names[index1], names[index2] = names[index2], names[index1]

    def _partition(
        self, heights: List[int], names: List[str], start: int, end: int
    ) -> int:
        pivot = heights[end]
        i = start - 1

        for j in range(start, end):
            # If current element is greater than or equal to pivot
            if heights[j] >= pivot:
                i += 1
                self._swap(heights, names, i, j)

        # Place the pivot in its correct position
        self._swap(heights, names, i + 1, end)
        return i + 1

    def _quick_sort(
        self, heights: List[int], names: List[str], start: int, end: int
    ):
        if start < end:
            # Find the partition index
            partition_index = self._partition(heights, names, start, end)

            # Recursively sort the left and right sub-arrays
            self._quick_sort(heights, names, start, partition_index - 1)
            self._quick_sort(heights, names, partition_index + 1, end)
```

</details>

<br>

## Approach 5: Merge Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        mergeSort(names, heights, 0, heights.size() - 1);
        return names;
    }

private:
    void mergeSort(vector<string>& names, vector<int>& heights, int start,
                   int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(names, heights, start, mid);
            mergeSort(names, heights, mid + 1, end);
            merge(names, heights, start, mid, end);
        }
    }

    void merge(vector<string>& names, vector<int>& heights, int start, int mid,
               int end) {
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        // Create temporary vectors
        vector<int> leftHeights(leftSize);
        vector<int> rightHeights(rightSize);
        vector<string> leftNames(leftSize);
        vector<string> rightNames(rightSize);

        // Copy data to temporary vectors
        for (int i = 0; i < leftSize; i++) {
            leftHeights[i] = heights[start + i];
            leftNames[i] = names[start + i];
        }
        for (int j = 0; j < rightSize; j++) {
            rightHeights[j] = heights[mid + 1 + j];
            rightNames[j] = names[mid + 1 + j];
        }

        // Merge the temporary vectors
        int leftIndex = 0, rightIndex = 0;
        int mergeIndex = start;
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (leftHeights[leftIndex] >=
                rightHeights[rightIndex]) {  // Descending order
                heights[mergeIndex] = leftHeights[leftIndex];
                names[mergeIndex] = leftNames[leftIndex];
                leftIndex++;
            } else {
                heights[mergeIndex] = rightHeights[rightIndex];
                names[mergeIndex] = rightNames[rightIndex];
                rightIndex++;
            }
            mergeIndex++;
        }

        // Copy remaining elements of leftHeights, if any
        while (leftIndex < leftSize) {
            heights[mergeIndex] = leftHeights[leftIndex];
            names[mergeIndex] = leftNames[leftIndex];
            leftIndex++;
            mergeIndex++;
        }

        // Copy remaining elements of rightHeights, if any
        while (rightIndex < rightSize) {
            heights[mergeIndex] = rightHeights[rightIndex];
            names[mergeIndex] = rightNames[rightIndex];
            rightIndex++;
            mergeIndex++;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String[] sortPeople(String[] names, int[] heights) {
        mergeSort(names, heights, 0, heights.length - 1);
        return names;
    }

    private void mergeSort(String[] names, int[] heights, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(names, heights, start, mid);
            mergeSort(names, heights, mid + 1, end);
            merge(names, heights, start, mid, end);
        }
    }

    private void merge(
        String[] names,
        int[] heights,
        int start,
        int mid,
        int end
    ) {
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        // Create temporary arrays
        int[] leftHeights = new int[leftSize];
        int[] rightHeights = new int[rightSize];
        String[] leftNames = new String[leftSize];
        String[] rightNames = new String[rightSize];

        // Copy data to temporary arrays
        for (int i = 0; i < leftSize; i++) {
            leftHeights[i] = heights[start + i];
            leftNames[i] = names[start + i];
        }
        for (int j = 0; j < rightSize; j++) {
            rightHeights[j] = heights[mid + 1 + j];
            rightNames[j] = names[mid + 1 + j];
        }

        // Merge the temporary arrays
        int leftIndex = 0, rightIndex = 0;
        int mergeIndex = start;
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (leftHeights[leftIndex] >= rightHeights[rightIndex]) { // Descending order
                heights[mergeIndex] = leftHeights[leftIndex];
                names[mergeIndex] = leftNames[leftIndex];
                leftIndex++;
            } else {
                heights[mergeIndex] = rightHeights[rightIndex];
                names[mergeIndex] = rightNames[rightIndex];
                rightIndex++;
            }
            mergeIndex++;
        }

        // Copy remaining elements of leftHeights[], if any
        while (leftIndex < leftSize) {
            heights[mergeIndex] = leftHeights[leftIndex];
            names[mergeIndex] = leftNames[leftIndex];
            leftIndex++;
            mergeIndex++;
        }

        // Copy remaining elements of rightHeights[], if any
        while (rightIndex < rightSize) {
            heights[mergeIndex] = rightHeights[rightIndex];
            names[mergeIndex] = rightNames[rightIndex];
            rightIndex++;
            mergeIndex++;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        self._merge_sort(names, heights, 0, len(heights) - 1)
        return names

    def _merge_sort(
        self, names: List[str], heights: List[int], start: int, end: int
    ):
        if start < end:
            mid = start + (end - start) // 2
            self._merge_sort(names, heights, start, mid)
            self._merge_sort(names, heights, mid + 1, end)
            self._merge(names, heights, start, mid, end)

    def _merge(
        self,
        names: List[str],
        heights: List[int],
        start: int,
        mid: int,
        end: int,
    ):
        left_size = mid - start + 1
        right_size = end - mid

        # Create temporary lists
        left_heights = heights[start : start + left_size]
        right_heights = heights[mid + 1 : mid + 1 + right_size]
        left_names = names[start : start + left_size]
        right_names = names[mid + 1 : mid + 1 + right_size]

        # Merge the temporary lists
        left_index, right_index = 0, 0
        merge_index = start
        while left_index < left_size and right_index < right_size:
            if (
                left_heights[left_index] >= right_heights[right_index]
            ):  # Descending order
                heights[merge_index] = left_heights[left_index]
                names[merge_index] = left_names[left_index]
                left_index += 1
            else:
                heights[merge_index] = right_heights[right_index]
                names[merge_index] = right_names[right_index]
                right_index += 1
            merge_index += 1

        # Copy remaining elements of left_heights, if any
        while left_index < left_size:
            heights[merge_index] = left_heights[left_index]
            names[merge_index] = left_names[left_index]
            left_index += 1
            merge_index += 1

        # Copy remaining elements of right_heights, if any
        while right_index < right_size:
            heights[merge_index] = right_heights[right_index]
            names[merge_index] = right_names[right_index]
            right_index += 1
            merge_index += 1
```

</details>
