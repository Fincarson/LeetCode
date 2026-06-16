# 179. Largest Number

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/largest-number/)  
`Array` `String` `Greedy` `Sorting`

**Problem Link:** [LeetCode 179 - Largest Number](https://leetcode.com/problems/largest-number/)

## Problem

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

### Example 1

```text
Input: nums = [10,2]
Output: "210"
```

### Example 2

```text
Input: nums = [3,30,34,5,9]
Output: "9534330"
```

## Constraints

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Smallest Value of the Rearranged Number](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Key of the Numbers](https://leetcode.com/problems/find-the-key-of-the-numbers/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 179. Largest Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Built-in Function | C++, Java, Python3 |
| Quick Sort | C++, Java, Python3 |
| Merge Sort | C++, Java, Python3 |
| HeapSort | C++, Java, Python3 |
| TimSort | C++, Java, Python3 |

## Approach 1: Using Built-in Function

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numStrings;
        // Convert each integer to a string
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }

        // Sort strings based on concatenated values
        sort(numStrings.begin(), numStrings.end(),
             [](string &a, string &b) { return a + b > b + a; });

        // Handle the case where the largest number is zero
        if (numStrings[0] == "0") return "0";

        // Concatenate sorted strings to form the largest number
        string largestNum;
        for (string &numStr : numStrings) {
            largestNum += numStr;
        }

        return largestNum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String largestNumber(int[] nums) {
        // Convert each integer to a string
        String[] numStrings = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numStrings[i] = Integer.toString(nums[i]);
        }

        // Sort strings based on concatenated values
        Arrays.sort(numStrings, (a, b) -> (b + a).compareTo(a + b));

        // Handle the case where the largest number is zero
        if (numStrings[0].equals("0")) {
            return "0";
        }

        // Concatenate sorted strings to form the largest number
        StringBuilder largestNum = new StringBuilder();
        for (String numStr : numStrings) {
            largestNum.append(numStr);
        }

        return largestNum.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Convert each integer to a string
        num_strings = [str(num) for num in nums]

        # Sort strings based on concatenated values
        num_strings.sort(key=lambda a: a * 10, reverse=True)

        # Handle the case where the largest number is zero
        if num_strings[0] == "0":
            return "0"

        # Concatenate sorted strings to form the largest number
        return "".join(num_strings)
```

</details>

<br>

## Approach 2: Quick Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using Quick Sort
        quickSort(nums, 0, nums.size() - 1);
        // Concatenate sorted numbers to form the largest number
        string largestNum;
        for (int num : nums) {
            largestNum += to_string(num);
        }
        // Handle the case where the largest number is zero
        return largestNum[0] == '0' ? "0" : largestNum;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        // Base case: if the range has one or no elements, it is already sorted
        if (left >= right) return;
        // Partition the array and get the pivot index
        int pivotIndex = partition(nums, left, right);
        // Recursively sort the sub-arrays
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int lowIndex = left;
        // Rearrange elements so that those greater than the pivot are on the
        // left
        for (int i = left; i < right; ++i) {
            if (compare(nums[i], pivot)) {
                swap(nums[i], nums[lowIndex]);
                ++lowIndex;
            }
        }
        // Place the pivot in its correct position
        swap(nums[lowIndex], nums[right]);
        return lowIndex;
    }

    bool compare(int firstNum, int secondNum) {
        // Compare concatenated strings to decide the order
        return to_string(firstNum) + to_string(secondNum) >
               to_string(secondNum) + to_string(firstNum);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String largestNumber(int[] nums) {
        // Sort the numbers using Quick Sort
        quickSort(nums, 0, nums.length - 1);
        // Concatenate sorted numbers to form the largest number
        StringBuilder largestNum = new StringBuilder();
        for (int num : nums) {
            largestNum.append(num);
        }
        // Handle the case where the largest number is zero
        return largestNum.charAt(0) == '0' ? "0" : largestNum.toString();
    }

    private void quickSort(int[] nums, int left, int right) {
        // Base case: if the range has one or no elements, it is already sorted
        if (left >= right) return;
        // Partition the array and get the pivot index
        int pivotIndex = partition(nums, left, right);
        // Recursively sort the sub-arrays
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }

    private int partition(int[] nums, int left, int right) {
        int pivot = nums[right];
        int lowIndex = left;
        // Rearrange elements so that those greater than the pivot are on the left
        for (int i = left; i < right; ++i) {
            if (compare(nums[i], pivot)) {
                swap(nums, i, lowIndex);
                ++lowIndex;
            }
        }
        // Place the pivot in its correct position
        swap(nums, lowIndex, right);
        return lowIndex;
    }

    private boolean compare(int firstNum, int secondNum) {
        // Compare concatenated strings to decide the order
        String str1 = String.valueOf(firstNum) + String.valueOf(secondNum);
        String str2 = String.valueOf(secondNum) + String.valueOf(firstNum);
        return str1.compareTo(str2) > 0;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Sort the numbers using Quick Sort
        self._quick_sort(nums, 0, len(nums) - 1)
        # Concatenate sorted numbers to form the largest number
        largest_num = "".join(map(str, nums))
        # Handle the case where the largest number is zero
        return "0" if largest_num[0] == "0" else largest_num

    def _quick_sort(self, nums: List[int], left: int, right: int) -> None:
        # Base case: if the range has one or no elements, it is already sorted
        if left >= right:
            return

        # Partition the array and get the pivot index
        pivot_index = self._partition(nums, left, right)

        # Recursively sort the sub-arrays
        self._quick_sort(nums, left, pivot_index - 1)
        self._quick_sort(nums, pivot_index + 1, right)

    def _partition(self, nums: List[int], left: int, right: int) -> int:
        pivot = nums[right]
        low_index = left

        # Rearrange elements so that those greater than the pivot are on the left
        for i in range(left, right):
            if self._compare(nums[i], pivot):
                nums[i], nums[low_index] = nums[low_index], nums[i]
                low_index += 1

        # Place the pivot in its correct position
        nums[low_index], nums[right] = nums[right], nums[low_index]
        return low_index

    def _compare(self, first_num: int, second_num: int) -> bool:
        # Compare concatenated strings to decide the order
        return str(first_num) + str(second_num) > str(second_num) + str(
            first_num
        )
```

</details>

<br>

## Approach 3: Merge Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using Merge Sort
        nums = mergeSort(nums, 0, nums.size() - 1);
        // Concatenate sorted numbers to form the largest number
        string largestNum;
        for (int num : nums) {
            largestNum += to_string(num);
        }
        // Handle the case where the largest number is zero
        return largestNum[0] == '0' ? "0" : largestNum;
    }

private:
    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        // Base case: a single element is already sorted
        if (left >= right) return {nums[left]};
        int mid = left + (right - left) / 2;
        // Recursively sort the left and right halves
        vector<int> leftHalf = mergeSort(nums, left, mid);
        vector<int> rightHalf = mergeSort(nums, mid + 1, right);
        // Merge the sorted halves
        return merge(leftHalf, rightHalf);
    }

    vector<int> merge(vector<int>& leftHalf, vector<int>& rightHalf) {
        vector<int> sortedNums;
        int leftIndex = 0, rightIndex = 0;
        // Merge the two halves based on custom comparison
        while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size()) {
            if (compare(leftHalf[leftIndex], rightHalf[rightIndex])) {
                sortedNums.push_back(leftHalf[leftIndex++]);
            } else {
                sortedNums.push_back(rightHalf[rightIndex++]);
            }
        }
        // Append remaining elements from left half
        while (leftIndex < leftHalf.size())
            sortedNums.push_back(leftHalf[leftIndex++]);
        // Append remaining elements from right half
        while (rightIndex < rightHalf.size())
            sortedNums.push_back(rightHalf[rightIndex++]);
        return sortedNums;
    }

    bool compare(int firstNum, int secondNum) {
        // Compare concatenated strings to decide the order
        return to_string(firstNum) + to_string(secondNum) >
               to_string(secondNum) + to_string(firstNum);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String largestNumber(int[] nums) {
        // Sort the numbers using Merge Sort
        List<Integer> sortedNums = mergeSort(nums, 0, nums.length - 1);
        // Concatenate sorted numbers to form the largest number
        StringBuilder largestNum = new StringBuilder();
        for (int num : sortedNums) {
            largestNum.append(num);
        }
        // Handle the case where the largest number is zero
        return largestNum.charAt(0) == '0' ? "0" : largestNum.toString();
    }

    private List<Integer> mergeSort(int[] nums, int left, int right) {
        // Base case: a single element is already sorted
        if (left >= right) return List.of(nums[left]);
        int mid = left + (right - left) / 2;
        // Recursively sort the left and right halves
        List<Integer> leftHalf = mergeSort(nums, left, mid);
        List<Integer> rightHalf = mergeSort(nums, mid + 1, right);
        // Merge the sorted halves
        return merge(leftHalf, rightHalf);
    }

    private List<Integer> merge(
        List<Integer> leftHalf,
        List<Integer> rightHalf
    ) {
        List<Integer> sortedNums = new ArrayList<>();
        int leftIndex = 0, rightIndex = 0;
        // Merge the two halves based on custom comparison
        while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size()) {
            if (compare(leftHalf.get(leftIndex), rightHalf.get(rightIndex))) {
                sortedNums.add(leftHalf.get(leftIndex++));
            } else {
                sortedNums.add(rightHalf.get(rightIndex++));
            }
        }
        // Append remaining elements from left half
        while (leftIndex < leftHalf.size()) sortedNums.add(
            leftHalf.get(leftIndex++)
        );
        // Append remaining elements from right half
        while (rightIndex < rightHalf.size()) sortedNums.add(
            rightHalf.get(rightIndex++)
        );
        return sortedNums;
    }

    private boolean compare(int firstNum, int secondNum) {
        // Compare concatenated strings to decide the order
        String s1 = String.valueOf(firstNum) + String.valueOf(secondNum);
        String s2 = String.valueOf(secondNum) + String.valueOf(firstNum);
        return s1.compareTo(s2) > 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Sort the numbers using Merge Sort
        sorted_nums = self._merge_sort(nums, 0, len(nums) - 1)
        # Concatenate sorted numbers to form the largest number
        largest_num = "".join(map(str, sorted_nums))
        # Handle the case where the largest number is zero
        return "0" if largest_num[0] == "0" else largest_num

    def _merge_sort(self, nums: List[int], left: int, right: int) -> List[int]:
        # Base case: a single element is already sorted
        if left >= right:
            return [nums[left]]
        mid = left + (right - left) // 2

        # Recursively sort the left and right halves
        left_half = self._merge_sort(nums, left, mid)
        right_half = self._merge_sort(nums, mid + 1, right)

        # Merge the sorted halves
        return self._merge(left_half, right_half)

    def _merge(self, left_half: List[int], right_half: List[int]) -> List[int]:
        sorted_nums = []
        left_index, right_index = 0, 0

        # Merge the two halves based on custom comparison
        while left_index < len(left_half) and right_index < len(right_half):
            if self._compare(left_half[left_index], right_half[right_index]):
                sorted_nums.append(left_half[left_index])
                left_index += 1
            else:
                sorted_nums.append(right_half[right_index])
                right_index += 1

        # Append remaining elements from left half
        sorted_nums.extend(left_half[left_index:])

        # Append remaining elements from right half
        sorted_nums.extend(right_half[right_index:])
        return sorted_nums

    def _compare(self, first_num: int, second_num: int) -> bool:
        # Compare concatenated strings to decide the order
        return str(first_num) + str(second_num) > str(second_num) + str(
            first_num
        )
```

</details>

<br>

## Approach 4: HeapSort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Priority queue to order numbers using the custom comparison
        // function
        priority_queue<string, vector<string>, decltype(&Solution::compare)>
            maxHeap(&Solution::compare);

        int totalLength = 0;

        // Convert integers to strings and push them into the priority queue
        for (const int num : nums) {
            string strNum = to_string(num);
            totalLength += strNum.size();
            maxHeap.push(strNum);
        }

        // Build the result string from the priority queue
        string result;
        result.reserve(totalLength);  // Reserve space for efficiency
        while (!maxHeap.empty()) {
            result += maxHeap.top();
            maxHeap.pop();
        }

        // Handle edge case where the result might be "000...0"
        if (result.empty() || result[0] == '0') {
            return "0";
        }

        return result;
    }

private:
    // Private helper function to compare two strings
    static bool compare(const string& first, const string& second) {
        return (first + second) < (second + first);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String largestNumber(int[] nums) {
        // Priority queue to order numbers using the custom comparison function
        PriorityQueue<String> maxHeap = new PriorityQueue<>(
            new Comparator<String>() {
                @Override
                public int compare(String first, String second) {
                    return (second + first).compareTo(first + second);
                }
            }
        );

        int totalLength = 0;

        // Convert integers to strings and push them into the priority queue
        for (int num : nums) {
            String strNum = Integer.toString(num);
            totalLength += strNum.length();
            maxHeap.offer(strNum);
        }

        // Build the result string from the priority queue
        StringBuilder result = new StringBuilder(totalLength);
        while (!maxHeap.isEmpty()) {
            result.append(maxHeap.poll());
        }

        // Handle edge case where the result might be "000...0"
        return result.charAt(0) == '0' ? "0" : result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Edge case: if all numbers are zero, return "0"
        if not any(nums):
            return "0"

        # Custom comparison function for heapq (simulating the comparator in Java)
        class LargerStrComparator(str):
            def __lt__(self, other):
                # Custom comparison: return True if self+other > other+self
                return self + other > other + self

        # Priority queue (min-heap), but we push elements using a custom comparator
        heap = []
        for num in nums:
            heapq.heappush(heap, LargerStrComparator(str(num)))

        # Build the result string by popping from the heap
        result = []
        while heap:
            result.append(heapq.heappop(heap))

        # Concatenate and return the result
        largest_num = "".join(result)

        # Handle case where all elements are "0"
        return "0" if largest_num[0] == "0" else largest_num
```

</details>

<br>

## Approach 5: TimSort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using Tim Sort
        timSort(nums);
        // Concatenate sorted numbers to form the largest number
        string largestNum;
        for (int num : nums) {
            largestNum += to_string(num);
        }
        // Handle the case where the largest number is zero
        return largestNum[0] == '0' ? "0" : largestNum;
    }

private:
    const int RUN = 32;

    void insertionSort(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; ++i) {
            int temp = nums[i];
            int j = i - 1;
            while (j >= left && compare(temp, nums[j])) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = temp;
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> leftArr(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightArr(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size()) {
            if (compare(leftArr[i], rightArr[j])) {
                nums[k++] = leftArr[i++];
            } else {
                nums[k++] = rightArr[j++];
            }
        }
        while (i < leftArr.size()) nums[k++] = leftArr[i++];
        while (j < rightArr.size()) nums[k++] = rightArr[j++];
    }

    void timSort(vector<int>& nums) {
        int n = nums.size();
        // Sort small runs with insertion sort
        for (int i = 0; i < n; i += RUN) {
            insertionSort(nums, i, min(i + RUN - 1, n - 1));
        }
        // Merge sorted runs
        for (int size = RUN; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = min(left + 2 * size - 1, n - 1);
                if (mid < right) {
                    merge(nums, left, mid, right);
                }
            }
        }
    }

    bool compare(int firstNum, int secondNum) {
        return to_string(firstNum) + to_string(secondNum) >
               to_string(secondNum) + to_string(firstNum);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int RUN = 32;

    public String largestNumber(int[] nums) {
        // Convert int array to Integer array for custom sorting
        Integer[] numsArray = Arrays.stream(nums)
            .boxed()
            .toArray(Integer[]::new);
        // Sort the numbers using custom Tim Sort
        timSort(numsArray);
        // Concatenate sorted numbers to form the largest number
        StringBuilder largestNum = new StringBuilder();
        for (int num : numsArray) {
            largestNum.append(num);
        }
        // Handle the case where the largest number is zero
        return largestNum.charAt(0) == '0' ? "0" : largestNum.toString();
    }

    private void insertionSort(Integer[] nums, int left, int right) {
        for (int i = left + 1; i <= right; ++i) {
            int temp = nums[i];
            int j = i - 1;
            while (j >= left && compare(temp, nums[j])) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = temp;
        }
    }

    private void merge(Integer[] nums, int left, int mid, int right) {
        Integer[] leftArr = Arrays.copyOfRange(nums, left, mid + 1);
        Integer[] rightArr = Arrays.copyOfRange(nums, mid + 1, right + 1);

        int i = 0, j = 0, k = left;
        while (i < leftArr.length && j < rightArr.length) {
            if (compare(leftArr[i], rightArr[j])) {
                nums[k++] = leftArr[i++];
            } else {
                nums[k++] = rightArr[j++];
            }
        }
        while (i < leftArr.length) nums[k++] = leftArr[i++];
        while (j < rightArr.length) nums[k++] = rightArr[j++];
    }

    private void timSort(Integer[] nums) {
        int n = nums.length;
        // Sort small runs with insertion sort
        for (int i = 0; i < n; i += RUN) {
            insertionSort(nums, i, Math.min(i + RUN - 1, n - 1));
        }
        // Merge sorted runs
        for (int size = RUN; size < n; size *= 2) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min(left + 2 * size - 1, n - 1);
                if (mid < right) {
                    merge(nums, left, mid, right);
                }
            }
        }
    }

    private boolean compare(int firstNum, int secondNum) {
        String firstStr = Integer.toString(firstNum);
        String secondStr = Integer.toString(secondNum);
        return (firstStr + secondStr).compareTo(secondStr + firstStr) > 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    RUN = 32

    def largestNumber(self, nums: List[int]) -> str:
        # Sort the numbers using custom Tim Sort
        self.tim_sort(nums)
        # Concatenate sorted numbers to form the largest number
        largest_num = "".join(map(str, nums))
        # Handle the case where the largest number is zero
        return "0" if largest_num[0] == "0" else largest_num

    def insertion_sort(self, nums: List[int], left: int, right: int):
        for i in range(left + 1, right + 1):
            temp = nums[i]
            j = i - 1
            while j >= left and self.compare(temp, nums[j]):
                nums[j + 1] = nums[j]
                j -= 1
            nums[j + 1] = temp

    def merge(self, nums: List[int], left: int, mid: int, right: int):
        left_arr = nums[left : mid + 1]
        right_arr = nums[mid + 1 : right + 1]

        i, j, k = 0, 0, left
        while i < len(left_arr) and j < len(right_arr):
            if self.compare(left_arr[i], right_arr[j]):
                nums[k] = left_arr[i]
                i += 1
            else:
                nums[k] = right_arr[j]
                j += 1
            k += 1
        nums[k : right + 1] = left_arr[i:] + right_arr[j:]

    def tim_sort(self, nums: List[int]):
        n = len(nums)
        # Sort small runs with insertion sort
        for i in range(0, n, self.RUN):
            self.insertion_sort(nums, i, min(i + self.RUN - 1, n - 1))
        # Merge sorted runs
        size = self.RUN
        while size < n:
            for left in range(0, n, 2 * size):
                mid = left + size - 1
                right = min(left + 2 * size - 1, n - 1)
                if mid < right:
                    self.merge(nums, left, mid, right)
            size *= 2

    def compare(self, first_num: int, second_num: int) -> bool:
        return str(first_num) + str(second_num) > str(second_num) + str(
            first_num
        )
```

</details>
