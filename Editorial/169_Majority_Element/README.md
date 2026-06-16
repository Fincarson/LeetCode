# 169. Majority Element

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/majority-element/)  
`Array` `Hash Table` `Divide and Conquer` `Sorting` `Counting`

**Problem Link:** [LeetCode 169 - Majority Element](https://leetcode.com/problems/majority-element/)

## Problem

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

### Example 1

```text
Input: nums = [3,2,3]
Output: 3
```

### Example 2

```text
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

## Constraints

- n == nums.length
- 1 <= n <= 5 * 104
- -109 <= nums[i] <= 109
- The input is generated such that a majority element will exist in the array.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Check If a Number Is Majority Element in a Sorted Array](https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Index of a Valid Split](https://leetcode.com/problems/minimum-index-of-a-valid-split/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Exceed Threshold Value I](https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Most Common Response](https://leetcode.com/problems/find-the-most-common-response/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Valid Pair of Adjacent Digits in String](https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 169. Majority Element

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| HashMap | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bit Manipulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Randomization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Divide and Conquer | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Boyer-Moore Voting Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int majorityElement(int* nums, int numsSize) {
    int majorityCount = numsSize / 2;

    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }

        if (count > majorityCount) {
            return nums[i];
        }
    }

    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2;

        for (int num : nums) {
            int count = 0;
            for (int elem : nums) {
                if (elem == num) {
                    count += 1;
                }
            }

            if (count > majorityCount) {
                return num;
            }
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        int majorityCount = nums.Length / 2;

        foreach (int num in nums) {
            int count = 0;
            foreach (int elem in nums) {
                if (elem == num) {
                    count += 1;
                }
            }

            if (count > majorityCount) {
                return num;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func majorityElement(nums []int) int {
    majorityCount := len(nums) / 2
    for _, num := range nums {
        count := 0
        for _, elem := range nums {
            if elem == num {
                count += 1
            }
        }
        if count > majorityCount {
            return num
        }
    }
    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int majorityElement(int[] nums) {
        int majorityCount = nums.length / 2;

        for (int num : nums) {
            int count = 0;
            for (int elem : nums) {
                if (elem == num) {
                    count += 1;
                }
            }

            if (count > majorityCount) {
                return num;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var majorityElement = function (nums) {
    const majorityCount = Math.floor(nums.length / 2);

    for (let num of nums) {
        let count = 0;
        for (let elem of nums) {
            if (elem === num) {
                count += 1;
            }
        }

        if (count > majorityCount) {
            return num;
        }
    }

    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums) // 2
        for num in nums:
            count = sum(1 for elem in nums if elem == num)
            if count > majority_count:
                return num
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function majorityElement(nums: number[]): number {
    const majorityCount = Math.floor(nums.length / 2);

    for (let num of nums) {
        let count = 0;
        for (let elem of nums) {
            if (elem === num) {
                count += 1;
            }
        }

        if (count > majorityCount) {
            return num;
        }
    }

    return -1;
}
```

</details>

<br>

## Approach 2: HashMap

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hash {
    int key;
    int val;
    UT_hash_handle hh;
};

typedef struct hash hash_t;

int majorityElement(int* nums, int numsSize) {
    hash_t *counts = NULL, *s, *tmp;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(counts, &nums[i], s);
        if (s == NULL) {
            s = (hash_t*)malloc(sizeof *s);
            s->key = nums[i];
            s->val = 1;
            HASH_ADD_INT(counts, key, s);
        } else {
            s->val++;
        }
    }

    int majority = numsSize / 2;
    HASH_ITER(hh, counts, s, tmp) {
        if (s->val > majority) return s->key;
    }
    return 0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            if (counts.find(num) == counts.end()) {
                counts[num] = 1;
            } else {
                counts[num] += 1;
            }
        }

        for (auto entry : counts) {
            if (entry.second > nums.size() / 2) return entry.first;
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Dictionary<int, int> countNums(int[] nums) {
        var counts = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!counts.ContainsKey(num)) {
                counts.Add(num, 1);
            } else {
                counts[num]++;
            }
        }

        return counts;
    }

    public int MajorityElement(int[] nums) {
        var counts = countNums(nums);

        foreach (var count in counts) {
            if (count.Value > nums.Length / 2)
                return count.Key;
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func majorityElement(nums []int) int {
    counts := make(map[int]int)
    for _, num := range nums {
        if _, ok := counts[num]; ok {
            counts[num]++
        } else {
            counts[num] = 1
        }
    }
    for num, count := range counts {
        if count > len(nums)/2 {
            return num
        }
    }
    return 0
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Map<Integer, Integer> countNums(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (!counts.containsKey(num)) {
                counts.put(num, 1);
            } else {
                counts.put(num, counts.get(num) + 1);
            }
        }
        return counts;
    }

    public int majorityElement(int[] nums) {
        Map<Integer, Integer> counts = countNums(nums);

        Map.Entry<Integer, Integer> majorityEntry = null;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (entry.getValue() > nums.length / 2) return entry.getKey();
        }

        return majorityEntry.getKey();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var majorityElement = function (nums) {
    let counts = {};
    for (let num of nums) {
        if (!counts[num]) {
            counts[num] = 1;
        } else {
            counts[num]++;
        }
    }

    for (let num in counts) {
        if (counts[num] > nums.length / 2) return Number(num);
    }
    return 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function majorityElement(nums: number[]): number {
    let counts: { [key: number]: number } = {};
    for (let num of nums) {
        if (counts[num] === undefined) {
            counts[num] = 1;
        } else {
            counts[num]++;
        }
    }

    for (let num in counts) {
        if (counts[num] > nums.length / 2) return Number(num);
    }
    return 0;
}
```

</details>

<br>

## Approach 3: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums[numsSize / 2];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        Array.Sort(nums);
        return nums[nums.Length / 2];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func majorityElement(nums []int) int {
    sort.Ints(nums)
    return nums[len(nums)/2]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var majorityElement = function (nums) {
    nums.sort((a, b) => a - b);
    return nums[Math.floor(nums.length / 2)];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums) // 2]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function majorityElement(nums: number[]): number {
    nums.sort((a, b) => a - b);
    return nums[Math.floor(nums.length / 2)];
}
```

</details>

<br>

## Approach 4: Bit Manipulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int majorityElement(int* nums, int numsSize) {
    int majority_element = 0;

    for (int i = 0; i < 32; i++) {
        unsigned int bit = 1u << i;

        // Count how many numbers have this bit set.
        int bit_count = 0;
        for (int j = 0; j < numsSize; j++) {
            if ((nums[j] & bit) != 0) {
                bit_count++;
            }
        }

        // If this bit is present in more than n / 2 elements
        // then it must be set in the majority element.
        if (bit_count > numsSize / 2) {
            majority_element |= bit;
        }
    }

    return majority_element;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority_element = 0;

        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;

            // Count how many numbers have this bit set.
            int bit_count = 0;
            for (int num : nums) {
                if ((num & bit) != 0) {
                    bit_count++;
                }
            }

            // If this bit is present in more than n / 2 elements
            // then it must be set in the majority element.
            if (bit_count > n / 2) {
                majority_element |= bit;
            }
        }

        return majority_element;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        int n = nums.Length;
        int majority_element = 0;

        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;

            // Count how many numbers have this bit set.
            int bit_count = 0;
            foreach (int num in nums) {
                if ((num & bit) != 0) {
                    bit_count++;
                }
            }

            // If this bit is present in more than n / 2 elements
            // then it must be set in the majority element.
            if (bit_count > n / 2) {
                majority_element |= bit;
            }
        }

        return majority_element;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func majorityElement(nums []int) int {
    var majority_element int32 = 0
    for i := 0; i < 32; i++ {
        bit := int32(1 << i)

        // Count how many numbers have this bit set.
        bit_count := 0
        for _, num := range nums {
            if (int32(num) & bit) != 0 {
                bit_count++
            }
        }

        // If this bit is present in more than n / 2 elements
        // then it must be set in the majority element.
        if bit_count > len(nums)/2 {
            majority_element |= bit
        }
    }

    return int(majority_element)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int majority_element = 0;

        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;

            // Count how many numbers have this bit set.
            int bit_count = 0;
            for (int num : nums) {
                if ((num & bit) != 0) {
                    bit_count++;
                }
            }

            // If this bit is present in more than n / 2 elements
            // then it must be set in the majority element.
            if (bit_count > n / 2) {
                majority_element |= bit;
            }
        }

        return majority_element;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var majorityElement = function (nums) {
    let majority_element = 0;

    for (let i = 0; i < 32; i++) {
        const bit = 1 << i;

        // Count how many numbers have this bit set.
        let bit_count = nums.reduce(
            (count, num) => ((num & bit) != 0 ? count + 1 : count),
            0,
        );

        // If this bit is present in more than n / 2 elements
        // then it must be set in the majority element.
        if (bit_count > nums.length / 2) majority_element |= bit;
    }

    return majority_element;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        majority_element = 0

        bit = 1
        for i in range(31):
            # Count how many numbers have the current bit set.
            bit_count = sum(bool(num & bit) for num in nums)

            # If this bit is present in more than n / 2 elements
            # then it must be set in the majority element.
            if bit_count > n // 2:
                majority_element += bit

            # Shift bit to the left one space. i.e. '00100' << 1 = '01000'
            bit = bit << 1

        # In python 1 << 31 will automatically be considered as positive value
        # so we will count how many numbers are negative to determine if
        # the majority element is negative.
        is_negative = sum(num < 0 for num in nums) > (n // 2)

        # When evaluating a 32-bit signed integer, the values of the 1st through
        # 31st bits are added to the total while the value of the 32nd bit is
        # subtracted from the total. This is because the 32nd bit is responsible
        # for signifying if the number is positive or negative.
        if is_negative:
            majority_element -= bit

        return majority_element
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function majorityElement(nums: number[]): number {
    let majority_element = 0;

    for (let i = 0; i < 32; i++) {
        const bit = 1 << i;

        // Count how many numbers have this bit set.
        let bit_count = nums.reduce(
            (count, num) => ((num & bit) != 0 ? count + 1 : count),
            0,
        );

        // If this bit is present in more than n / 2 elements
        // then it must be set in the majority element.
        if (bit_count > nums.length / 2) majority_element |= bit;
    }

    return majority_element;
}
```

</details>

<br>

## Approach 5: Randomization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countOccurences(int* nums, int num, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

int majorityElement(int* nums, int numsSize) {
    srand(time(0));
    int majorityCount = numsSize / 2;
    while (1) {
        int candidate = nums[rand() % numsSize];
        if (countOccurences(nums, candidate, numsSize) > majorityCount) {
            return candidate;
        }
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2;
        while (true) {
            int candidate = nums[rand() % nums.size()];
            if (countOccurrences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }

private:
    // function to count occurrences of an element
    int countOccurrences(vector<int>& nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        int majorityCount = nums.Length / 2;
        Random rand = new Random();
        while (true) {
            int candidate = nums[rand.Next(0, nums.Length)];
            if (CountOccurrences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }

    // function to count occurrences of an element
    private int CountOccurrences(int[] nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] == num) {
                count++;
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func majorityElement(nums []int) int {
    majorityCount := len(nums) / 2
    rand.Seed(time.Now().UnixNano())
    for {
        candidate := nums[rand.Intn(len(nums))]
        if countOccurences(nums, candidate) > majorityCount {
            return candidate
        }
    }
}

func countOccurences(nums []int, num int) int {
    count := 0
    for _, value := range nums {
        if value == num {
            count++
        }
    }
    return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int randRange(Random rand, int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private int countOccurences(int[] nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    public int majorityElement(int[] nums) {
        Random rand = new Random();

        int majorityCount = nums.length / 2;

        while (true) {
            int candidate = nums[randRange(rand, 0, nums.length)];
            if (countOccurences(nums, candidate) > majorityCount) {
                return candidate;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var majorityElement = function (nums) {
    const majorityCount = Math.floor(nums.length / 2);
    while (true) {
        const candidate = nums[Math.floor(Math.random() * nums.length)];
        const count = nums.reduce(
            (prev, curr) => (curr === candidate ? prev + 1 : prev),
            0,
        );
        if (count > majorityCount) {
            return candidate;
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import random


class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums) // 2
        while True:
            candidate = random.choice(nums)
            if sum(1 for elem in nums if elem == candidate) > majority_count:
                return candidate
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function majorityElement(nums: number[]): number {
    const majorityCount = Math.floor(nums.length / 2);
    while (true) {
        const candidate = nums[Math.floor(Math.random() * nums.length)];
        const count = nums.reduce(
            (prev, curr) => (curr === candidate ? prev + 1 : prev),
            0,
        );
        if (count > majorityCount) {
            return candidate;
        }
    }
}
```

</details>

<br>

## Approach 6: Divide and Conquer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countInRange(int* nums, int num, int lo, int hi) {
    int count = 0;
    for (int i = lo; i <= hi; i++) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

int majorityElementRec(int* nums, int lo, int hi) {
    if (lo == hi) {
        return nums[lo];
    }
    int mid = (hi - lo) / 2 + lo;
    int left = majorityElementRec(nums, lo, mid);
    int right = majorityElementRec(nums, mid + 1, hi);

    if (left == right) {
        return left;
    }
    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);

    return leftCount > rightCount ? left : right;
}

int majorityElement(int* nums, int numsSize) {
    return majorityElementRec(nums, 0, numsSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countInRange(vector<int>& nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    int majorityElementRec(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return nums[lo];
        }

        int mid = (hi - lo) / 2 + lo;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid + 1, hi);

        if (left == right) {
            return left;
        }

        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return leftCount > rightCount ? left : right;
    }

    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int countInRange(int[] nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num) {
                count++;
            }
        }

        return count;
    }

    private int majorityElementRec(int[] nums, int lo, int hi) {
        if (lo == hi) {
            return nums[lo];
        }

        int mid = (hi - lo) / 2 + lo;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid + 1, hi);

        if (left == right) {
            return left;
        }

        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return leftCount > rightCount ? left : right;
    }

    public int MajorityElement(int[] nums) {
        return majorityElementRec(nums, 0, nums.Length - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func majorityElement(nums []int) int {
    var majorityElementRec func(nums []int, lo int, hi int) int
    majorityElementRec = func(nums []int, lo int, hi int) int {
        if lo == hi {
            return nums[lo]
        }

        mid := (hi-lo)/2 + lo
        left := majorityElementRec(nums, lo, mid)
        right := majorityElementRec(nums, mid+1, hi)

        if left == right {
            return left
        }

        leftCount := 0
        rightCount := 0
        for i := lo; i <= hi; i++ {
            if nums[i] == left {
                leftCount++
            }
            if nums[i] == right {
                rightCount++
            }
        }

        if leftCount > rightCount {
            return left
        }

        return right
    }

    return majorityElementRec(nums, 0, len(nums)-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int countInRange(int[] nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    private int majorityElementRec(int[] nums, int lo, int hi) {
        // base case; the only element in an array of size 1 is the majority
        // element.
        if (lo == hi) {
            return nums[lo];
        }

        // recurse on left and right halves of this slice.
        int mid = (hi - lo) / 2 + lo;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid + 1, hi);

        // if the two halves agree on the majority element, return it.
        if (left == right) {
            return left;
        }

        // otherwise, count each element and return the "winner".
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return leftCount > rightCount ? left : right;
    }

    public int majorityElement(int[] nums) {
        return majorityElementRec(nums, 0, nums.length - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var majorityElement = function (nums, lo = 0, hi = null) {
    let majorityElementRec = (lo, hi) => {
        if (lo == hi) {
            return nums[lo];
        }

        let mid = Math.floor((hi - lo) / 2) + lo;
        let left = majorityElementRec(lo, mid);
        let right = majorityElementRec(mid + 1, hi);

        if (left == right) {
            return left;
        }

        let leftCount = 0;
        let rightCount = 0;
        for (let i = lo; i <= hi; i++) {
            if (nums[i] == left) {
                leftCount++;
            }
            if (nums[i] == right) {
                rightCount++;
            }
        }

        return leftCount > rightCount ? left : right;
    };

    return majorityElementRec(0, nums.length - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def majorityElement(self, nums, lo=0, hi=None):
        def majority_element_rec(lo, hi):
            # base case; the only element in an array of size 1 is the majority
            # element.
            if lo == hi:
                return nums[lo]

            # recurse on left and right halves of this slice.
            mid = (hi - lo) // 2 + lo
            left = majority_element_rec(lo, mid)
            right = majority_element_rec(mid + 1, hi)

            # if the two halves agree on the majority element, return it.
            if left == right:
                return left

            # otherwise, count each element and return the "winner".
            left_count = sum(1 for i in range(lo, hi + 1) if nums[i] == left)
            right_count = sum(1 for i in range(lo, hi + 1) if nums[i] == right)

            return left if left_count > right_count else right

        return majority_element_rec(0, len(nums) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function majorityElement(nums: number[], lo = 0, hi = null): number {
    let majorityElementRec = (lo: number, hi: number) => {
        if (lo == hi) {
            return nums[lo];
        }

        let mid = Math.floor((hi - lo) / 2) + lo;
        let left = majorityElementRec(lo, mid);
        let right = majorityElementRec(mid + 1, hi);

        if (left == right) {
            return left;
        }

        let leftCount = 0;
        let rightCount = 0;
        for (let i = lo; i <= hi; i++) {
            if (nums[i] == left) {
                leftCount++;
            }
            if (nums[i] == right) {
                rightCount++;
            }
        }

        return leftCount > rightCount ? left : right;
    };

    return majorityElementRec(0, nums.length - 1);
}
```

</details>

<br>

## Approach 7: Boyer-Moore Voting Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (int& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        int count = 0;
        int? candidate = null;

        foreach (int num in nums) {
            if (count == 0) {
                candidate = num;
            }

            count += (num == candidate) ? 1 : -1;
        }

        return candidate.Value;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func majorityElement(nums []int) int {
    count := 0
    var candidate int

    for _, num := range nums {
        if count == 0 {
            candidate = num
        }
        if num == candidate {
            count += 1
        } else {
            count -= 1
        }
    }

    return candidate
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var majorityElement = function (nums) {
    let count = 0;
    let candidate = null;

    for (let num of nums) {
        if (count == 0) {
            candidate = num;
        }
        count += num == candidate ? 1 : -1;
    }

    return candidate;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1

        return candidate
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function majorityElement(nums: number[]): number {
    let count = 0;
    let candidate: number | null = null;

    for (let num of nums) {
        if (count == 0) {
            candidate = num;
        }
        count += num == candidate ? 1 : -1;
    }

    return candidate as number;
}
```

</details>
