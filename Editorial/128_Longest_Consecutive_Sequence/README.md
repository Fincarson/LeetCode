# 128. Longest Consecutive Sequence

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-consecutive-sequence/)  
`Array` `Hash Table` `Union-Find`

**Problem Link:** [LeetCode 128 - Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)

## Problem

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

### Example 1

```text
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

### Example 2

```text
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

### Example 3

```text
Input: nums = [1,0,1,2]
Output: 3
```

## Constraints

- 0 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Three Consecutive Integers That Sum to a Given Number](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Consecutive Floors Without Special Floors](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Length of the Longest Alphabetical Continuous Substring](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Maximum Number of Elements in Subset](https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 128. Longest Consecutive Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| HashSet and Intelligent Sequence Building | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool arrayContains(int* arr, int num, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}
int longestConsecutive(int* nums, int numsSize) {
    int longestStreak = 0;
    for (int i = 0; i < numsSize; i++) {
        int currentNum = nums[i];
        int currentStreak = 1;
        while (arrayContains(nums, currentNum + 1, numsSize)) {
            currentNum += 1;
            currentStreak += 1;
        }
        longestStreak =
            longestStreak > currentStreak ? longestStreak : currentStreak;
    }
    return longestStreak;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool arrayContains(vector<int>& arr, int num) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0;
        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;
            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
        return longestStreak;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private bool ArrayContains(int[] arr, int num) {
        for (int i = 0; i < arr.Length; i++) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }

    public int LongestConsecutive(int[] nums) {
        int longestStreak = 0;
        for (int i = 0; i < nums.Length; i++) {
            int currentNum = nums[i];
            int currentStreak = 1;
            while (ArrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = Math.Max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func arrayContains(arr []int, num int) bool {
    for i := 0; i < len(arr); i++ {
        if arr[i] == num {
            return true
        }
    }
    return false
}

func longestConsecutive(nums []int) int {
    longestStreak := 0
    for _, num := range nums {
        currentNum := num
        currentStreak := 1
        for arrayContains(nums, currentNum+1) {
            currentNum += 1
            currentStreak += 1
        }
        if currentStreak > longestStreak {
            longestStreak = currentStreak
        }
    }
    return longestStreak
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean arrayContains(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }

    public int longestConsecutive(int[] nums) {
        int longestStreak = 0;

        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;

            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = Math.max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestConsecutive = function (nums) {
    let longestStreak = 0;
    for (let num of nums) {
        let currentNum = num;
        let currentStreak = 1;
        while (nums.includes(currentNum + 1)) {
            currentNum += 1;
            currentStreak += 1;
        }
        longestStreak = Math.max(longestStreak, currentStreak);
    }
    return longestStreak;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest_streak = 0

        for num in nums:
            current_num = num
            current_streak = 1

            while current_num + 1 in nums:
                current_num += 1
                current_streak += 1

            longest_streak = max(longest_streak, current_streak)

        return longest_streak
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestConsecutive(nums: number[]): number {
    let longestStreak = 0;
    for (let num of nums) {
        let currentNum = num;
        let currentStreak = 1;
        while (nums.includes(currentNum + 1)) {
            currentNum += 1;
            currentStreak += 1;
        }
        longestStreak = Math.max(longestStreak, currentStreak);
    }
    return longestStreak;
}
```

</details>

<br>

## Approach 2: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int longestConsecutive(int *nums, int numsSize) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int longestStreak = 1;
    int currentStreak = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak += 1;
            } else {
                longestStreak = longestStreak > currentStreak ? longestStreak
                                                              : currentStreak;
                currentStreak = 1;
            }
        }
    }
    return longestStreak > currentStreak ? longestStreak : currentStreak;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longestStreak = 1;
        int currentStreak = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak += 1;
                } else {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }
        return max(longestStreak, currentStreak);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LongestConsecutive(int[] nums) {
        if (nums.Length == 0) {
            return 0;
        }

        Array.Sort(nums);
        int longestStreak = 1;
        int currentStreak = 1;
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak += 1;
                } else {
                    longestStreak = Math.Max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return Math.Max(longestStreak, currentStreak);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestConsecutive(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    sort.Ints(nums)
    longestStreak := 1
    currentStreak := 1
    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[i-1] {
            if nums[i] == nums[i-1]+1 {
                currentStreak += 1
            } else {
                longestStreak = max(longestStreak, currentStreak)
                currentStreak = 1
            }
        }
    }
    return max(longestStreak, currentStreak)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        Arrays.sort(nums);

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak += 1;
                } else {
                    longestStreak = Math.max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return Math.max(longestStreak, currentStreak);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestConsecutive = function (nums) {
    if (nums.length == 0) {
        return 0;
    }
    nums.sort((a, b) => a - b);
    let longestStreak = 1;
    let currentStreak = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] != nums[i - 1]) {
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak += 1;
            } else {
                longestStreak = Math.max(longestStreak, currentStreak);
                currentStreak = 1;
            }
        }
    }
    return Math.max(longestStreak, currentStreak);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        nums.sort()

        longest_streak = 1
        current_streak = 1

        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                if nums[i] == nums[i - 1] + 1:
                    current_streak += 1
                else:
                    longest_streak = max(longest_streak, current_streak)
                    current_streak = 1

        return max(longest_streak, current_streak)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestConsecutive(nums: number[]): number {
    if (nums.length == 0) {
        return 0;
    }
    nums.sort((a, b) => a - b);
    let longestStreak = 1;
    let currentStreak = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] != nums[i - 1]) {
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak += 1;
            } else {
                longestStreak = Math.max(longestStreak, currentStreak);
                currentStreak = 1;
            }
        }
    }
    return Math.max(longestStreak, currentStreak);
}
```

</details>

<br>

## Approach 3: HashSet and Intelligent Sequence Building

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Define the structure for the hash table to represent the set
typedef struct {
    int key;            // the key here is the number itself
    UT_hash_handle hh;  // makes this structure hashable
} IntHash;

// Function to add a number to the hash set
void add_to_set(IntHash **s, int num) {
    IntHash *element;
    HASH_FIND_INT(*s, &num, element);
    if (element == NULL) {
        element = (IntHash *)malloc(sizeof(IntHash));
        element->key = num;
        HASH_ADD_INT(*s, key, element);
    }
}

// Function to check if a number exists in the set
int set_contains(IntHash *s, int num) {
    IntHash *element;
    HASH_FIND_INT(s, &num, element);
    return element != NULL;
}

// Function to find the longest consecutive sequence
int longestConsecutive(int *nums, int numsSize) {
    IntHash *num_set = NULL;

    // Insert all numbers into the set
    for (int i = 0; i < numsSize; i++) {
        add_to_set(&num_set, nums[i]);
    }

    int longestStreak = 0;

    // Iterate over all numbers in the set
    for (IntHash *it = num_set; it != NULL; it = it->hh.next) {
        int num = it->key;
        // Start a new sequence if there's no preceding element
        if (!set_contains(num_set, num - 1)) {
            int currentNum = num;
            int currentStreak = 1;
            // Continue the sequence while consecutive elements are found
            while (set_contains(num_set, currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }
            // Update the longest streak found
            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
        }
    }

    // Clean up the hash table
    IntHash *current_item, *tmp;
    HASH_ITER(hh, num_set, current_item, tmp) {
        HASH_DEL(num_set,
                 current_item);  // delete it (num_set advances to next)
        free(current_item);      // free it
    }
    return longestStreak;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> num_set = new HashSet<int>(nums);
        int longestStreak = 0;
        foreach (int num in num_set) {
            if (!num_set.Contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.Contains(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.Max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestConsecutive(nums []int) int {
    num_set := make(map[int]bool)
    for _, num := range nums {
        num_set[num] = true
    }
    longestStreak := 0
    for num := range num_set {
        if _, exists := num_set[num-1]; !exists {
            currentNum := num
            currentStreak := 1
            for exists := num_set[currentNum+1]; exists; exists = num_set[currentNum+1] {
                currentNum++
                currentStreak++
            }
            if currentStreak > longestStreak {
                longestStreak = currentStreak
            }
        }
    }
    return longestStreak
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<Integer>();
        for (int num : nums) {
            num_set.add(num);
        }

        int longestStreak = 0;

        for (int num : num_set) {
            if (!num_set.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.contains(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestConsecutive = function (nums) {
    let num_set = new Set(nums);
    let longestStreak = 0;
    for (let num of num_set) {
        if (!num_set.has(num - 1)) {
            let currentNum = num;
            let currentStreak = 1;
            while (num_set.has(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = Math.max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestConsecutive(nums: number[]): number {
    let num_set: Set<number> = new Set(nums);
    let longestStreak: number = 0;
    for (let num of num_set) {
        if (!num_set.has(num - 1)) {
            let currentNum: number = num;
            let currentStreak: number = 1;
            while (num_set.has(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = Math.max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}
```

</details>
