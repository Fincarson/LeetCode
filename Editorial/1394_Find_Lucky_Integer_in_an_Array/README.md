# 1394. Find Lucky Integer in an Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-lucky-integer-in-an-array/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 1394 - Find Lucky Integer in an Array](https://leetcode.com/problems/find-lucky-integer-in-an-array/)

## Problem

Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

### Example 1

```text
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
```

### Example 2

```text
Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
```

### Example 3

```text
Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
```

## Constraints

- 1 <= arr.length <= 500
- 1 <= arr[i] <= 500

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1394. Find Lucky Integer in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python |
| Sorting | Java, Python |
| Counter | Java, Python |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int findLucky(int[] arr) {
    int maxLuckyNumber = -1;
    for (int num : arr) {
        int occurencesOfNum = countOccurences(arr, num);
        //  If num is a lucky number, and is the biggest lucky number so far.
        if (occurencesOfNum == num && num > maxLuckyNumber) {
            maxLuckyNumber = num;
        }
    }
    return maxLuckyNumber;
}

private int countOccurences(int[] arr, int candidateNum) {
    int count = 0;
    for (int num : arr) {
        if (num == candidateNum) {
            count++;
        }
    }
    return count;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def findLucky(self, arr: List[int]) -> int:
    max_lucky_number = -1
    for num in arr:
        # Note that arr.count(num) has a cost of $$O(n)$$.
        # It works the same as the algorithm we defined in pseudocode.
        occurences_of_num = arr.count(num)
        # If num is a lucky number, and is the biggest lucky number so far.
        if num == occurences_of_num and num > max_lucky_number:
            max_lucky_number = num
    return max_lucky_number
```

</details>

<br>

## Approach 2: Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int findLucky(int[] arr) {
    Arrays.sort(arr);
    int currentStreak = 0;
    // In Java, it's best to just go backwards, as we can't
    // trivially reverse-sort an Array of primitives. 
    // We could also have used the Stream API to box the ints and then
    // sort using a library comparator.
    for (int i = arr.length - 1; i >= 0; i--) {
        currentStreak++;
        // If this is the last element in the current streak (as the next is
        // different, or we're at the start of the array).
        if (i == 0 || arr[i] != arr[i - 1]) {
            // If this is a lucky number
            if (currentStreak == arr[i]) {
                return currentStreak;
            }
            currentStreak = 0;
        }
    }
    return -1;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def findLucky(self, arr: List[int]) -> int:
    arr.sort(reverse=True)
    current_streak = 0
    for i in range(len(arr)):
        current_streak += 1
        # If this is the last element in the current streak (as the next is
        # different, or we're at the end of the array).
        if i == len(arr) - 1 or arr[i] != arr[i + 1]:
            # If this is a lucky number
            if arr[i] == current_streak:
                return arr[i]
            current_streak = 0
    return -1
```

</details>

<br>

## Approach 3: Counter

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int findLucky(int[] arr) {
        
    // Use a HashMap to count how many times each num
    // appears in arr.
    Map<Integer, Integer> counts = new HashMap<>();
    for (Integer num : arr) {
        counts.put(num, counts.getOrDefault(num, 0) + 1);
    }
    
    int largestLuckyNumber = -1;
    // Iterate over the key/ value pairs of the dictionary.
    for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
        // If this is a lucky number
        if (entry.getKey().equals(entry.getValue())) {
            // Keep the largest out of this lucky number and our current largest.
            largestLuckyNumber = Math.max(largestLuckyNumber, entry.getKey());
        }
    }
    
    return largestLuckyNumber;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def findLucky(self, arr: List[int]) -> int:
    # We can simply pass the input array into the Counter constructor,
    # and it will convert it into a dictionary of num -> count.
    counts = collections.Counter(arr)
    largest_lucky_number = -1
    # Check each num -> count pair in the dictionary.
    for num, count in counts.items():
        # If this is a lucky number
        if num == count:
            # Keep the largest out of this lucky number and our current largest.
            largest_lucky_number = max(largest_lucky_number, num)
    return largest_lucky_number
```

</details>
