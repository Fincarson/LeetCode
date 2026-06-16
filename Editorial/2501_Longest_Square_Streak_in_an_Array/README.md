# 2501. Longest Square Streak in an Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-square-streak-in-an-array/)  
`Array` `Hash Table` `Binary Search` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 2501 - Longest Square Streak in an Array](https://leetcode.com/problems/longest-square-streak-in-an-array/)

## Problem

You are given an integer array nums. A subsequence of nums is called a square streak if:

- The length of the subsequence is at least 2, and
- after sorting the subsequence, each element (except the first element) is the square of the previous number.

Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```text
Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.
```

### Example 2

```text
Input: nums = [2,3,5,6,7]
Output: -1
Explanation: There is no square streak in nums so return -1.
```

## Constraints

- 2 <= nums.length <= 105
- 2 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2501. Longest Square Streak in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Set | C++, Java, Python3 |
| Map | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());

        // Set to keep track of numbers we've already processed
        set<int> processedNumbers;

        int longestStreak = 0;

        // Iterate through each number in the sorted array
        for (int current : nums) {
            // Skip if we've already processed this number
            if (processedNumbers.find(current) != processedNumbers.end())
                continue;

            int streak = current;
            int streakLength = 1;

            // Continue the streak as long as we can find the square of the
            // current number
            while (true) {
                // Break if the square would be larger than 10^5 (problem
                // constraint)
                if ((long long)streak * (long long)streak > 1e5) break;

                // If we find the square, continue the streak
                if (binarySearch(nums, streak * streak)) {
                    streak *= streak;
                    processedNumbers.insert(streak);
                    streakLength++;
                } else {
                    break;
                }
            }

            // Update the longest streak if necessary
            longestStreak = max(longestStreak, streakLength);
        }

        // Return -1 if no valid streak found, otherwise return the longest
        // streak
        return longestStreak < 2 ? -1 : longestStreak;
    }

private:
    // Binary search helper function to efficiently find a value in the sorted
    // array
    bool binarySearch(vector<int>& nums, int target) {
        if (target < 0) return false;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
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

    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        // Set to keep track of numbers we've already processed
        Set<Integer> processedNumbers = new HashSet<>();
        int longestStreak = 0;

        // Iterate through each number in the sorted array
        for (int current : nums) {
            // Skip if we've already processed this number
            if (processedNumbers.contains(current)) continue;

            int streak = current;
            int streakLength = 1;

            // Continue the streak as long as we can find the square of the current number
            while (true) {
                // Break if the square would be larger than 10^5 (problem constraint)
                if ((long) streak * (long) streak > 1e5) break;
                // If we find the square, continue the streak
                if (binarySearch(nums, streak * streak)) {
                    streak *= streak;
                    processedNumbers.add(streak);
                    streakLength++;
                } else {
                    break;
                }
            }
            // Update the longest streak if necessary
            longestStreak = Math.max(longestStreak, streakLength);
        }

        // Return -1 if no valid streak found, otherwise return the longest streak
        return longestStreak < 2 ? -1 : longestStreak;
    }

    // Binary search helper function to efficiently find a value in the sorted array
    private boolean binarySearch(int[] nums, int target) {
        if (target < 0) return false;

        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
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
    def longestSquareStreak(self, nums: List[int]) -> int:
        # Sort the array in ascending order
        nums.sort()

        # Set to keep track of numbers we've already processed
        processed_numbers = set()

        longest_streak = 0

        # Iterate through each number in the sorted array
        for current in nums:
            # Skip if we've already processed this number
            if current in processed_numbers:
                continue

            streak = current
            streak_length = 1

            # Continue the streak as long as we can find the square of the current number
            while streak * streak <= 10**5:
                if self._binary_search(nums, streak * streak):
                    streak *= streak
                    processed_numbers.add(streak)
                    streak_length += 1
                else:
                    break

            # Update the longest streak if necessary
            longest_streak = max(longest_streak, streak_length)

        # Return -1 if no valid streak found, otherwise return the longest streak
        return longest_streak if longest_streak >= 2 else -1

    # Binary search helper function to efficiently find a value in the sorted array
    def _binary_search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return False
```

</details>

<br>

## Approach 2: Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int longestStreak = 0;

        // Create a set to store all unique numbers from the input array
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

        // Iterate through each number in the input array
        for (int startNumber : nums) {
            int currentStreak = 0;
            long long current = startNumber;

            // Continue the streak as long as we can find the next square in the
            // set
            while (uniqueNumbers.find((int)current) != uniqueNumbers.end()) {
                currentStreak++;

                // Break if the next square would be larger than 10^5 (problem
                // constraint)
                if (current * current > 1e5) break;

                current *= current;
            }

            // Update the longest streak if necessary
            longestStreak = max(longestStreak, currentStreak);
        }

        // Return -1 if no valid streak found, otherwise return the longest
        // streak
        return longestStreak < 2 ? -1 : longestStreak;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestSquareStreak(int[] nums) {
        int longestStreak = 0;

        // Create a Set to store all unique numbers from the input array
        Set<Integer> uniqueNumbers = new HashSet<>();
        for (int num : nums) {
            uniqueNumbers.add(num);
        }

        // Iterate through each number in the input array
        for (int startNumber : nums) {
            int currentStreak = 0;
            long current = startNumber;

            // Continue the streak as long as we can find the next square in the set
            while (uniqueNumbers.contains((int) current)) {
                currentStreak++;

                // Break if the next square would be larger than 10^5 (problem constraint)
                if (current * current > 1e5) break;

                current *= current;
            }

            // Update the longest streak if necessary
            longestStreak = Math.max(longestStreak, currentStreak);
        }

        // Return -1 if no valid streak found, otherwise return the longest streak
        return longestStreak < 2 ? -1 : longestStreak;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        longest_streak = 0

        # Create a set to store all unique numbers from the input array
        unique_numbers = set(nums)

        # Iterate through each number in the input array
        for start_number in nums:
            current_streak = 0
            current = start_number

            # Continue the streak as long as we can find the next square in the set
            while current in unique_numbers:
                current_streak += 1

                # Break if the next square would be larger than 10^5 (problem constraint)
                if current * current > 10**5:
                    break

                current *= current

            # Update the longest streak if necessary
            longest_streak = max(longest_streak, current_streak)

        # Return -1 if no valid streak found, otherwise return the longest streak
        return longest_streak if longest_streak >= 2 else -1
```

</details>

<br>

## Approach 3: Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Map to store the length of square streak for each number
        unordered_map<int, int> streakLengths;

        sort(nums.begin(), nums.end());

        for (int number : nums) {
            int root = (int)sqrt(number);

            // Check if the number is a perfect square and its square root is in
            // the map
            if (root * root == number &&
                streakLengths.find(root) != streakLengths.end()) {
                // If so, extend the streak from its square root
                streakLengths[number] = streakLengths[root] + 1;
            } else {
                // Otherwise, start a new streak
                streakLengths[number] = 1;
            }
        }

        // Find the maximum streak length
        int longestStreak = 0;
        for (auto& [key, streakLength] : streakLengths) {
            longestStreak = max(longestStreak, streakLength);
        }

        // Return -1 if no valid streak found, otherwise return the longest
        // streak
        return longestStreak == 1 ? -1 : longestStreak;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestSquareStreak(int[] nums) {
        // Map to store the length of square streak for each number
        Map<Integer, Integer> streakLengths = new HashMap<>();

        Arrays.sort(nums);

        for (int number : nums) {
            int root = (int) Math.sqrt(number);

            // Check if the number is a perfect square and its square root is in the map
            if (root * root == number && streakLengths.containsKey(root)) {
                // If so, extend the streak from its square root
                streakLengths.put(number, streakLengths.get(root) + 1);
            } else {
                // Otherwise, start a new streak
                streakLengths.put(number, 1);
            }
        }

        // Find the maximum streak length
        int longestStreak = 0;
        for (int streakLength : streakLengths.values()) {
            longestStreak = Math.max(longestStreak, streakLength);
        }

        // Return -1 if no valid streak found, otherwise return the longest streak
        return longestStreak == 1 ? -1 : longestStreak;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        # Dictionary to store the length of square streak for each number
        streak_lengths = {}

        nums.sort()

        for number in nums:
            root = int(number**0.5)

            # Check if the number is a perfect square and its square root is in the dictionary
            if root * root == number and root in streak_lengths:
                # Extend the streak from its square root
                streak_lengths[number] = streak_lengths[root] + 1
            else:
                # Start a new streak
                streak_lengths[number] = 1

        # Find the maximum streak length
        longest_streak = max(streak_lengths.values(), default=0)

        # Return -1 if no valid streak found, otherwise return the longest streak
        return longest_streak if longest_streak > 1 else -1
```

</details>
