# 2342. Max Sum of a Pair With Equal Sum of Digits

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/)  
`Array` `Hash Table` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2342 - Max Sum of a Pair With Equal Sum of Digits](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/)

## Problem

You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions. If no such pair of indices exists, return -1.

### Example 1

```text
Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
```

### Example 2

```text
Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2342. Max Sum of a Pair With Equal Sum of Digits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Priority Queue | C++, Java, Python3 |
| Store Maximum Value | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Helper function to compute the sum of digits of a number
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> digitSumPairs;

        // Store numbers with their digit sums as pairs
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumPairs.push_back({digitSum, number});
        }

        // Sort based on digit sums, and if equal, by number value
        sort(digitSumPairs.begin(), digitSumPairs.end());

        int maxPairSum = -1;

        // Iterate through the sorted array to find the maximum sum of pairs
        for (int index = 1; index < digitSumPairs.size(); index++) {
            int currentDigitSum = digitSumPairs[index].first;
            int previousDigitSum = digitSumPairs[index - 1].first;

            // If two consecutive numbers have the same digit sum
            if (currentDigitSum == previousDigitSum) {
                int currentSum = digitSumPairs[index].second +
                                 digitSumPairs[index - 1].second;
                maxPairSum = max(maxPairSum, currentSum);
            }
        }

        return maxPairSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Helper function to compute the sum of digits of a number
    private int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

    public int maximumSum(int[] nums) {
        Pair<Integer, Integer>[] digitSumPairs = new Pair[nums.length];

        // Store numbers with their digit sums as pairs
        for (int i = 0; i < nums.length; i++) {
            int digitSum = calculateDigitSum(nums[i]);
            digitSumPairs[i] = new Pair<>(digitSum, nums[i]);
        }

        // Sort based on digit sums, and if equal, by number value
        Arrays.sort(
            digitSumPairs,
            Comparator.comparing(Pair<Integer, Integer>::getKey).thenComparing(
                Pair<Integer, Integer>::getValue
            )
        );

        int maxPairSum = -1;

        // Iterate through the sorted array to find the maximum sum of pairs
        for (int index = 1; index < digitSumPairs.length; index++) {
            int currentDigitSum = digitSumPairs[index].getKey();
            int previousDigitSum = digitSumPairs[index - 1].getKey();

            // If two consecutive numbers have the same digit sum
            if (currentDigitSum == previousDigitSum) {
                int currentSum =
                    digitSumPairs[index].getValue() +
                    digitSumPairs[index - 1].getValue();
                maxPairSum = Math.max(maxPairSum, currentSum);
            }
        }

        return maxPairSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Helper function to compute the sum of digits of a number
    def calculate_digit_sum(self, num):
        digit_sum = 0
        while num > 0:
            digit_sum += num % 10
            num //= 10
        return digit_sum

    def maximumSum(self, nums):
        digit_sum_pairs = []

        # Store numbers with their digit sums as pairs
        for number in nums:
            digit_sum = self.calculate_digit_sum(number)
            digit_sum_pairs.append((digit_sum, number))

        # Sort based on digit sums, and if equal, by number value
        digit_sum_pairs.sort()

        max_pair_sum = -1

        # Iterate through the sorted array to find the maximum sum of pairs
        for index in range(1, len(digit_sum_pairs)):
            current_digit_sum = digit_sum_pairs[index][0]
            previous_digit_sum = digit_sum_pairs[index - 1][0]

            # If two consecutive numbers have the same digit sum
            if current_digit_sum == previous_digit_sum:
                current_sum = (
                    digit_sum_pairs[index][1] + digit_sum_pairs[index - 1][1]
                )
                max_pair_sum = max(max_pair_sum, current_sum)

        return max_pair_sum
```

</details>

<br>

## Approach 2: Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Helper function to compute the sum of digits of a number
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        // Vector to store a min heap for each possible digit sum (0 to 81)
        vector<priority_queue<int, vector<int>, greater<int>>> digitSumGroups(
            82);

        int maxPairSum = -1;

        // Group numbers by their digit sums, maintaining heap size of 2
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumGroups[digitSum].push(number);

            // Keep only the top 2 largest numbers in the heap
            if (digitSumGroups[digitSum].size() > 2) {
                digitSumGroups[digitSum].pop();  // Remove the smallest element
            }
        }

        // Traverse the vector to find the maximum pair sum for each group
        for (auto& minHeap : digitSumGroups) {
            if (minHeap.size() == 2) {
                int first = minHeap.top();
                minHeap.pop();
                int second = minHeap.top();
                maxPairSum = max(maxPairSum, first + second);
            }
        }

        return maxPairSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Helper function to compute the sum of digits of a number
    private int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

    public int maximumSum(int[] nums) {
        // Array to store a min heap for each possible digit sum (0 to 81)
        PriorityQueue<Integer>[] digitSumGroups = new PriorityQueue[82];
        for (int i = 0; i < 82; i++) {
            digitSumGroups[i] = new PriorityQueue<Integer>();
        }

        int maxPairSum = -1;

        // Group numbers by their digit sums, maintaining heap size of 2
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumGroups[digitSum].add(number);

            // Keep only the top 2 largest numbers in the heap
            if (digitSumGroups[digitSum].size() > 2) {
                digitSumGroups[digitSum].poll(); // Remove the smallest element
            }
        }

        // Traverse the vector to find the maximum pair sum for each group
        for (PriorityQueue<Integer> minHeap : digitSumGroups) {
            if (minHeap.size() == 2) {
                int first = minHeap.poll();
                int second = minHeap.poll();
                maxPairSum = Math.max(maxPairSum, first + second);
            }
        }

        return maxPairSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Helper function to compute the sum of digits of a number
    def calculate_digit_sum(self, num):
        digit_sum = 0
        while num > 0:
            digit_sum += num % 10
            num //= 10
        return digit_sum

    def maximumSum(self, nums):
        # List to store a heap for each possible digit sum (0 to 81)
        digit_sum_groups = [[] for _ in range(82)]

        max_pair_sum = -1

        # Group numbers by their digit sums, maintaining heap size of 2
        for number in nums:
            digit_sum = self.calculate_digit_sum(number)
            heapq.heappush(digit_sum_groups[digit_sum], number)

            # Keep only the top 2 largest numbers in the heap
            if len(digit_sum_groups[digit_sum]) > 2:
                heapq.heappop(
                    digit_sum_groups[digit_sum]
                )  # Remove the smallest element

        # Traverse the list to find the maximum pair sum for each group
        for min_heap in digit_sum_groups:
            if len(min_heap) == 2:
                first = heapq.heappop(min_heap)
                second = heapq.heappop(min_heap)
                max_pair_sum = max(max_pair_sum, first + second)

        return max_pair_sum
```

</details>

<br>

## Approach 3: Store Maximum Value

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int result = -1;
        // Array to map digit sums to the largest element with that sum
        // (82 to cover all possible sums from 0 to 81)
        int digitMapping[82] = {};

        for (int element : nums) {
            int digitSum = 0;

            // Calculate the digit sum of the current element
            for (int currValue = element; currValue; currValue /= 10) {
                int currDigit = currValue % 10;
                digitSum += currDigit;
            }

            // Check if there is already an element with the same digit sum
            if (digitMapping[digitSum] > 0) {
                // Update the result if the sum of the current and mapped
                // element is greater
                result = max(result, digitMapping[digitSum] + element);
            }

            // Update the mapping to store the larger of the current or previous
            // element for this digit sum
            digitMapping[digitSum] = max(digitMapping[digitSum], element);
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

    public int maximumSum(int[] nums) {
        int result = -1;
        // Array to map digit sums to the largest element with that sum
        // (82 to cover all possible sums from 0 to 81)
        int[] digitMapping = new int[82];

        for (int element : nums) {
            int digitSum = 0;
            // Calculating digit sum
            for (int currValue = element; currValue != 0; currValue /= 10) {
                int currDigit = currValue % 10;
                digitSum += currDigit;
            }

            // Check if there is already an element with the same digit sum
            if (digitMapping[digitSum] > 0) {
                // Update the result if the sum of the current and mapped element is greater
                result = Math.max(result, digitMapping[digitSum] + element);
            }

            // Update the mapping to store the larger of the current or previous element for this digit sum
            digitMapping[digitSum] = Math.max(digitMapping[digitSum], element);
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
    def maximumSum(self, nums):
        result = -1
        # Array to map digit sums to the largest element with that sum
        # (82 to cover all possible sums from 0 to 81)
        digit_mapping = [0] * 82

        for element in nums:
            digit_sum = 0
            # Calculating digit sum
            temp_element = element
            while temp_element:
                # Extract the last digit and add it to digit sum
                temp_element, curr_digit = divmod(temp_element, 10)
                digit_sum += curr_digit

            # Check if there is already an element with the same digit sum
            if digit_mapping[digit_sum] > 0:
                # Update the result if the sum of the current and mapped element is greater
                result = max(result, digit_mapping[digit_sum] + element)

            # Update the mapping to store the larger of the current or previous element for this digit sum
            digit_mapping[digit_sum] = max(digit_mapping[digit_sum], element)

        return result
```

</details>
