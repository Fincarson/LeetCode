# 659. Split Array into Consecutive Subsequences

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)  
`Array` `Hash Table` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 659 - Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)

## Problem

You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

- Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
- All subsequences have a length of 3 or more.

Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

### Example 1

```text
Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5
```

### Example 2

```text
Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
[1,2,3,3,4,4,5,5] --> 3, 4, 5
```

### Example 3

```text
Input: nums = [1,2,3,4,4,5]
Output: false
Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.
```

## Constraints

- 1 <= nums.length <= 104
- -1000 <= nums[i] <= 1000
- nums is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Divide Array in Sets of K Consecutive Numbers](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 659. Split Array into Consecutive Subsequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy using Heap | C++, Java |
| Greedy using Maps | C++, Java |
| Dynamic Programming | C++, Java |
| Optimal Space | C++, Java |

## Approach 1: Greedy using Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    struct Compare {
        bool operator()(array<int, 2> subsequence1, array<int, 2> subsequence2) {
            if (subsequence1[1] == subsequence2[1]) {
                return (subsequence1[1] - subsequence1[0]) > (subsequence2[1] - subsequence2[0]);
            }
            return subsequence1[1] > subsequence2[1];
        }
    };

    bool isPossible(vector<int> &nums) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, Compare> subsequences;

        for (int num : nums) {
            //Condition 1 - remove non-qualifying subsequences
            while (!subsequences.empty() && subsequences.top()[1] + 1 < num) {
                array<int, 2> currentSubsequence = subsequences.top();
                subsequences.pop();
                int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
                if (subsequenceLength < 3) {
                    return false;
                }
            }
            //Condition 2 - create a new subsequence
            if (subsequences.empty() || subsequences.top()[1] == num) {
                subsequences.push({num, num});
            } else {
                //Condition 3 - add num to an existing subsequence
                array<int, 2> currentSubsequence = subsequences.top();
                subsequences.pop();
                subsequences.push({currentSubsequence[0], num});
            }
        }

        //If any subsequence is of length less than 3 return false
        while (!subsequences.empty()) {
            array<int, 2> currentSubsequence = subsequences.top();
            subsequences.pop();
            int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
            if (subsequenceLength < 3) {
                return false;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPossible(int[] nums) {
        PriorityQueue<int[]> subsequences = new PriorityQueue<>((int[] subsequence1, int[] subsequence2) -> {
            if (subsequence1[1] == subsequence2[1]) {
                return (subsequence1[1] - subsequence1[0]) - (subsequence2[1] - subsequence2[0]);
            }
            return (subsequence1[1] - subsequence2[1]);
        });

        for (int num : nums) {
            // Condition 1 - remove non-qualifying subsequences 
            while (!subsequences.isEmpty() && subsequences.peek()[1] + 1 < num) {
                int[] currentSubsequence = subsequences.poll();
                int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
                if (subsequenceLength < 3) {
                    return false;
                }
            }
            //Condition 2 - create a new subsequence
            if (subsequences.isEmpty() || subsequences.peek()[1] == num) {
                subsequences.add(new int[]{num, num});
            } else {
                // Condition 3 - add num to an existing subsequence
                int[] currentSubsequence = subsequences.poll();
                subsequences.add(new int[]{currentSubsequence[0], num});
            }
        }

        // If any subsequence is of length less than 3, return false
        while (!subsequences.isEmpty()) {
            int[] currentSubsequence = subsequences.poll();
            int subsequenceLength = currentSubsequence[1] - currentSubsequence[0] + 1;
            if (subsequenceLength < 3) {
                return false;
            }
        }

        return true;
    }
}
```

</details>

<br>

## Approach 2: Greedy using Maps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> subsequences;
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        for (int num : nums) {
            //num already part of a valid subsequence.
            if (frequency[num] == 0) {
                continue;
            }
            //If a valid subsequence exists with last element = num - 1.
            if (subsequences[num - 1] > 0) {
                subsequences[num - 1]--;
                subsequences[num]++;
            } else if (frequency[num + 1] > 0 && frequency[num + 2] > 0) {
                // If we want to start a new subsequence, check if num + 1 and num + 2 exists
                // Update the list of subsequences with the newly created subsequence
                subsequences[num + 2]++;
                frequency[num + 1]--;
                frequency[num + 2]--;
            } else {
                // No valid subsequence is possible with num
                return false;
            }
            frequency[num]--;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPossible(int[] nums) {
        Map<Integer, Integer> subsequences = new HashMap<>();
        Map<Integer, Integer> frequency = new HashMap<>();
        for (int num : nums) {
            frequency.put(num, frequency.getOrDefault(num, 0) + 1);
        }
        for (int num : nums) {
            //num already part of a valid subsequence.
            if (frequency.get(num) == 0) {
                continue;
            }
            // If a valid subsequence exists with the last element = num - 1.
            if (subsequences.getOrDefault(num - 1, 0) > 0) {
                subsequences.put(num - 1, subsequences.getOrDefault(num - 1, 0) - 1);
                subsequences.put(num, subsequences.getOrDefault(num, 0) + 1);
            } else if (frequency.getOrDefault(num + 1, 0) > 0 && 
                       frequency.getOrDefault(num + 2, 0) > 0) {
                // If we want to start a new subsequence, check if num + 1 and num + 2 exist.
                // Update the list of subsequences with the newly created subsequence
                subsequences.put(num + 2, subsequences.getOrDefault(num + 2, 0) + 1);
                frequency.put(num + 1, frequency.getOrDefault(num + 1, 0) - 1);
                frequency.put(num + 2, frequency.getOrDefault(num + 2, 0) - 1);
            } else {
                //No valid subsequence is possible with num
                return false;
            }
            frequency.put(num, frequency.get(num) - 1);
        }
        return true;
    }
}
```

</details>

<br>

## Approach 3: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isPossible(vector<int> &nums) {
        int n = nums.size();
        int start = 0;

        for (int i = 1; i < n; i++) {
            // Check the possibility of a valid segment starting at index start and ending at index i - 1.
            if (nums[i] - nums[i - 1] > 1) {
                if (!isSegmentValid(nums, start, i - 1)) {
                    return false;
                }
                // Update the starting index of the next segment.
                start = i;
            }
        }
        // Check for the last segment
        return isSegmentValid(nums, start, n - 1);
    }
    
private:
    bool isSegmentValid(vector<int> &nums, int start, int end) {
        int noOfUniqueNumbers = nums[end] - nums[start] + 1;

        // Count the frequency of each number in the current segment.
        vector<int> frequency(noOfUniqueNumbers);
        
        for (int i = start; i <= end; i++) {
            frequency[nums[i] - nums[start]]++;
        }
        // lengthOneSubsequences[i] holds the count of subsequences of length 1 ending with index i
        vector<int> lengthOneSubsequences(noOfUniqueNumbers);

        // lengthTwoSubsequences[i] holds the count of subsequences of length 2 ending with index i
        vector<int> lengthTwoSubsequences(noOfUniqueNumbers);

        // totalNoOfSubsequences[i] holds the count of all subsequences ending with index i
        vector<int> totalNoOfSubsequences(noOfUniqueNumbers);

        lengthOneSubsequences[0] = totalNoOfSubsequences[0] = frequency[0];

        for (int i = 1; i < noOfUniqueNumbers; i++) {

            // If the frequency[i] is less than the total number of subsequences ending with i - 1,
            // we do not have enough subsequences where we can put i.
            if (frequency[i] < lengthOneSubsequences[i - 1] + lengthTwoSubsequences[i - 1]) {
                return false;
            }
            
            //Total number of subsequences of length 2 can be obtained by adding i 
            //to subsequences of length 1 ending with i - 1.
            lengthTwoSubsequences[i] = lengthOneSubsequences[i - 1];
            
            // For the remaining i valued numbers we can either add them to an existing subsequence
            // or create a new one. We first try to add them to the existing subsequences ending 
            // with i - 1. If there are not enough of such subsequences, we start a new subsequence.
            // The existing subsequences ending with i - 1 are denoted by totalNoOfSubsequences[i - 1];
            lengthOneSubsequences[i] = max(0, frequency[i] - totalNoOfSubsequences[i - 1]);
            totalNoOfSubsequences[i] = frequency[i];
        }

        // If there is no remaining subsequence of length one or two, we can return true. 
        // Otherwise, return false.
        return lengthOneSubsequences[noOfUniqueNumbers - 1] == 0 && 
               lengthTwoSubsequences[noOfUniqueNumbers - 1] == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPossible(int[] nums) {
        int n = nums.length;
        int start = 0;

        for (int i = 1; i < n; i++) {
            // Check the possibility of a valid segment starting at index start and ending at index i - 1.
            if (nums[i] - nums[i - 1] > 1) {
                if (!isSegmentValid(nums, start, i - 1)) {
                    return false;
                }
                // Update the starting index of the next segment.
                start = i;
            }
        }
        // Check for the last segment
        return isSegmentValid(nums, start, n - 1);
    }

    private boolean isSegmentValid(int[] nums, int start, int end) {
        int noOfUniqueNumbers = nums[end] - nums[start] + 1;

        // Count the frequency of each number in the current segment.
        int[] frequency = new int[noOfUniqueNumbers];
        for (int i = start; i <= end; i++) {
            frequency[nums[i] - nums[start]]++;
        }
        // lengthOneSubsequences[i] holds the count of subsequences of length 1 ending with index i
        int[] lengthOneSubsequences = new int[noOfUniqueNumbers];

        // lengthTwoSubsequences[i] holds the count of subsequences of length 2 ending with index i
        int[] lengthTwoSubsequences = new int[noOfUniqueNumbers];

        // totalNoOfSubsequences[i] holds the count of all subsequences ending with index i
        int[] totalNoOfSubsequences = new int[noOfUniqueNumbers];

        lengthOneSubsequences[0] = totalNoOfSubsequences[0] = frequency[0];

        for (int i = 1; i < noOfUniqueNumbers; i++) {
            
            // If the frequency[i] is less than total number of subsequences ending with i - 1,
            // we do not have enough subsequences where we can put i.
            if (frequency[i] < lengthOneSubsequences[i - 1] + lengthTwoSubsequences[i - 1]) {
                return false;
            }
            
            // Total number of subsequences of length 2 can be obtained by adding i
            // to subsequences of length 1 ending with i - 1.
            lengthTwoSubsequences[i] = lengthOneSubsequences[i - 1];
            
            // For the remaining i valued numbers we can either add them to an existing subsequence
            // or create a new one. We first try to add them to the existing subsequences ending 
            // with i - 1. If there are not enough of such subsequences, we start a new subsequence.
            // The existing subsequences ending with i - 1 is denoted by totalNoOfSubsequences[i - 1];
            lengthOneSubsequences[i] = Math.max(0, frequency[i] - totalNoOfSubsequences[i - 1]);
            totalNoOfSubsequences[i] = frequency[i];
        }

        // If there is no remaining subsequence of length one or two, we can return true. 
        // Otherwise, return false.
        return lengthOneSubsequences[noOfUniqueNumbers - 1] == 0 && 
               lengthTwoSubsequences[noOfUniqueNumbers - 1] == 0;
    }

}
```

</details>

<br>

## Approach 4: Optimal Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isPossible(vector<int> &nums) {
        int n = nums.size();
        int start = 0;

        for (int i = 1; i < n; i++) {
            //Check possibility of a valid segment starting at index start and ending at index i - 1.
            if (nums[i] - nums[i - 1] > 1) {
                if (!isSegmentValid(nums, start, i - 1)) {
                    return false;
                }
                //Update the starting index of the next segment.
                start = i;
            }
        }
        //Check for the last segment
        return isSegmentValid(nums, start, n - 1);
    }
    
private:
    bool isSegmentValid(vector<int> &nums, int start, int end) {
        int frequency = 0;

        //lengthOneSubsequences holds count of subsequences of length 1.
        int lengthOneSubsequences = 0;

        //lengthTwoSubsequences holds count of subsequences of length 2.
        int lengthTwoSubsequences = 0;

        //totalNoOfSubsequences holds count of all subsequences.
        int totalNoOfSubsequences = 0;

        for (int i = start; i <= end; i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                frequency++;
            } else if (frequency < lengthOneSubsequences + lengthTwoSubsequences) {
                // If the frequency[i] is less than total number of subsequences ending with i - 1,
                // we do not have enough subsequences where we can put i.
                return false;
            } else {
                // Total number of subsequences of length 2 can be obtained by
                // adding i to subsequences of length 1 ending with i - 1.
                lengthTwoSubsequences = lengthOneSubsequences;
                lengthOneSubsequences = max(0, frequency - totalNoOfSubsequences);
                totalNoOfSubsequences = frequency;
                frequency = 1;
            }
        }
        // For the last element in the segment.
        lengthTwoSubsequences = lengthOneSubsequences;
        lengthOneSubsequences = max(0, frequency - totalNoOfSubsequences);
        // If there is no remaining subsequence of length one or two, we can return true. 
        // Otherwise, return false.
        return lengthOneSubsequences == 0 && lengthTwoSubsequences == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isPossible(int[] nums) {
        int n = nums.length, start = 0;

        for (int i = 1; i < n; i++) {
            // Check the possibility of a valid segment starting at index start and ending at index i - 1.
            if (nums[i] - nums[i - 1] > 1) {
                if (!isSegmentValid(nums, start, i - 1)) {
                    return false;
                }
                // Update the starting index of the next segment.
                start = i;
            }
        }
        //Check for the last segment
        return isSegmentValid(nums, start, n - 1);
    }

    private boolean isSegmentValid(int[] nums, int start, int end) {
        int frequency = 0;

        // lengthOneSubsequences holds the count of subsequences of length 1.
        int lengthOneSubsequences = 0;

        // lengthTwoSubsequences holds the count of subsequences of length 2.
        int lengthTwoSubsequences = 0;

        // totalNoOfSubsequences holds the count of all subsequences.
        int totalNoOfSubsequences = 0;

        for (int i = start; i <= end; i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                frequency++;
            } else if (frequency < lengthOneSubsequences + lengthTwoSubsequences) {
                // If the frequency[i] is less than the total number of subsequences ending with i - 1,
                // we do not have enough subsequences where we can put i.
                return false;
            } else {
                // Total number of subsequences of length 2 can be obtained by 
                // adding i to subsequences of length 1 ending with i - 1.
                lengthTwoSubsequences = lengthOneSubsequences;
                lengthOneSubsequences = Math.max(0, frequency - totalNoOfSubsequences);
                totalNoOfSubsequences = frequency;
                frequency = 1;
            }
        }
        // For the last element in the segment
        lengthTwoSubsequences = lengthOneSubsequences;
        lengthOneSubsequences = Math.max(0, frequency - totalNoOfSubsequences);
        // If there is no remaining subsequence of length one or two, we can return true. 
        // Otherwise, return false.
        return lengthOneSubsequences == 0 && lengthTwoSubsequences == 0;
    }
}
```

</details>
