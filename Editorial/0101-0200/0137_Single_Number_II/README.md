# 137. Single Number II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/single-number-ii/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 137 - Single Number II](https://leetcode.com/problems/single-number-ii/)

## Problem

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Example 1

```text
Input: nums = [2,2,3,2]
Output: 3
```

### Example 2

```text
Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

## Constraints

- 1 <= nums.length <= 3 * 104
- -231 <= nums[i] <= 231 - 1
- Each element in nums appears exactly three times except for one element which appears once.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Single Number](https://leetcode.com/problems/single-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Single Number III](https://leetcode.com/problems/single-number-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the XOR of Numbers Which Appear Twice](https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 137. Single Number II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hash Map | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bit Manipulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Equation for Bitmask | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Boolean Algebra and Karnaugh Map | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a < *(int*)b) return -1;
    return 0;
}
int singleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i += 3) {
        if (nums[i] == nums[i + 1]) {
            continue;
        } else {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 3) {
            if (nums[i] == nums[i + 1]) {
                continue;
            } else {
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        Array.Sort(nums);
        for (int i = 0; i < nums.Length - 1; i += 3) {
            if (nums[i] == nums[i + 1]) {
                continue;
            } else {
                return nums[i];
            }
        }

        return nums[nums.Length - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    sort.Ints(nums)
    for i := 0; i < len(nums)-1; i += 3 {
        if nums[i] == nums[i+1] {
            continue
        } else {
            return nums[i]
        }
    }
    return nums[len(nums)-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 1; i += 3) {
            if (nums[i] == nums[i + 1]) {
                continue;
            } else {
                return nums[i];
            }
        }

        return nums[nums.length - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    nums.sort();
    for (let i = 0; i < nums.length - 1; i += 3) {
        if (nums[i] == nums[i + 1]) {
            continue;
        } else {
            return nums[i];
        }
    }
    return nums[nums.length - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        nums.sort()

        for i in range(0, len(nums) - 1, 3):
            if nums[i] == nums[i + 1]:
                continue
            else:
                return nums[i]

        return nums[len(nums) - 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    nums.sort();
    for (let i = 0; i < nums.length - 1; i += 3) {
        if (nums[i] == nums[i + 1]) {
            continue;
        } else {
            return nums[i];
        }
    }
    return nums[nums.length - 1];
}
```

</details>

<br>

## Approach 2: Hash Map

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int num;
    int freq;
    UT_hash_handle hh;
} NumFreq;
int singleNumber(int* nums, int numsSize) {
    NumFreq* freq = NULL;
    for (int i = 0; i < numsSize; i++) {
        NumFreq* s;
        HASH_FIND_INT(freq, &nums[i], s);
        if (s == NULL) {
            s = (NumFreq*)malloc(sizeof(NumFreq));
            s->num = nums[i];
            s->freq = 1;
            HASH_ADD_INT(freq, num, s);
        } else {
            s->freq++;
        }
    }
    int loner = 0;
    for (NumFreq* s = freq; s != NULL; s = s->hh.next) {
        if (s->freq == 1) {
            loner = s->num;
            break;
        }
    }
    HASH_CLEAR(hh, freq);
    return loner;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (freq.find(num) == freq.end()) {
                freq[num] = 1;
            } else {
                freq[num]++;
            }
        }

        int loner = 0;
        for (auto entry : freq) {
            if (entry.second == 1) {
                loner = entry.first;
                break;
            }
        }

        return loner;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        Dictionary<int, int> freq = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!freq.ContainsKey(num)) {
                freq[num] = 1;
            } else {
                freq[num]++;
            }
        }

        int loner = 0;
        foreach (KeyValuePair<int, int> entry in freq) {
            if (entry.Value == 1) {
                loner = entry.Key;
                break;
            }
        }

        return loner;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    freq := make(map[int]int)
    for _, num := range nums {
        freq[num]++
    }
    var loner int
    for num, count := range freq {
        if count == 1 {
            loner = num
            break
        }
    }
    return loner
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            if (!freq.containsKey(num)) {
                freq.put(num, 1);
            } else {
                freq.put(num, freq.get(num) + 1);
            }
        }

        int loner = 0;
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            if (entry.getValue() == 1) {
                loner = entry.getKey();
                break;
            }
        }

        return loner;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    let freq = {};
    for (let num of nums) {
        if (freq[num] === undefined) {
            freq[num] = 1;
        } else {
            freq[num]++;
        }
    }

    let loner = 0;
    for (let key in freq) {
        if (freq[key] === 1) {
            loner = key;
            break;
        }
    }

    return loner;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        freq = {}

        for num in nums:
            if num not in freq:
                freq[num] = 1
            else:
                freq[num] += 1

        for key in freq:
            if freq[key] == 1:
                return key
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    let freq: { [key: number]: number } = {};
    for (let num of nums) {
        if (freq[num] === undefined) {
            freq[num] = 1;
        } else {
            freq[num]++;
        }
    }

    let loner = 0;
    for (let key in freq) {
        if (freq[key] === 1) {
            loner = parseInt(key);
            break;
        }
    }

    return loner;
}
```

</details>

<br>

## Approach 3: Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hash {
    int key;
    UT_hash_handle hh;
};
int singleNumber(int* nums, int numsSize) {
    struct hash *unique = NULL, *s;
    long sum = 0, uniqueSum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        HASH_FIND_INT(unique, &nums[i], s);
        if (s == NULL) {
            s = malloc(sizeof(struct hash));
            s->key = nums[i];
            HASH_ADD_INT(unique, key, s);
            uniqueSum += nums[i];
        }
    }
    return (uniqueSum * 3 - sum) / 2;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<long> numsSet;
        long sumNums = 0;
        for (int num : nums) {
            numsSet.insert((long)num);
            sumNums += num;
        }

        long sumSet = 0;
        for (long num : numsSet) {
            sumSet += num;
        }

        return (int)((3 * sumSet - sumNums) / 2);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        long sumNums = 0;
        HashSet<long> numsSet = new HashSet<long>();
        foreach (int num in nums) {
            numsSet.Add((long)num);
            sumNums += num;
        }

        long sumSet = 0;
        foreach (long num in numsSet) {
            sumSet += num;
        }

        return (int)((3 * sumSet - sumNums) / 2);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    unique := map[int]bool{}
    var sum, uniqueSum int
    for _, num := range nums {
        if _, exist := unique[num]; !exist {
            unique[num] = true
            uniqueSum += num
        }
        sum += num
    }
    return (3*uniqueSum - sum) / 2
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        Set<Long> numsSet = new HashSet<>();
        long sumNums = 0;
        for (int num : nums) {
            numsSet.add((long) num);
            sumNums += num;
        }

        long sumSet = 0;
        for (long num : numsSet) {
            sumSet += num;
        }

        return (int) ((3 * sumSet - sumNums) / 2);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    // We convert the integer array to a set to remove duplicates
    let numsSet = new Set(nums);
    let sumNums = nums.reduce((a, b) => a + b, 0);
    // We sum the unique elements in the set
    let sumSet = Array.from(numsSet.values()).reduce((a, b) => a + b, 0);
    // We subtract the original sum from the triple of the unique sum
    // This gives us twice the number that only appears once, so we divide it by 2
    return (3 * sumSet - sumNums) / 2;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return (3 * sum(set(nums)) - sum(nums)) // 2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    let numsSet = new Set(nums);
    let sumNums = nums.reduce((a, b) => a + b, 0);
    let sumSet = Array.from(numsSet.values()).reduce((a, b) => a + b, 0);
    return (3 * sumSet - sumNums) / 2;
}
```

</details>

<br>

## Approach 4: Bit Manipulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int singleNumber(int* nums, int numsSize) {
    // Loner
    long loner = 0;
    // Iterate over all bits
    for (int shift = 0; shift < 32; shift++) {
        int bitSum = 0;
        // For this bit, iterate over all integers
        for (int i = 0; i < numsSize; i++) {
            // Compute the bit of num, and add it to bitSum
            bitSum += (nums[i] >> shift) & 1;
        }
        // Compute the bit of loner and place it
        long lonerBit = bitSum % 3;
        loner = loner | (lonerBit << shift);
    }
    return (int)loner;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Loner
        int loner = 0;
        // Iterate over all bits
        for (int shift = 0; shift < 32; shift++) {
            int bitSum = 0;
            // For this bit, iterate over all integers
            for (auto& num : nums) {
                // Compute the bit of num, and add it to bitSum
                bitSum += (num >> shift) & 1;
            }
            // Compute the bit of loner and place it
            int lonerBit = bitSum % 3;
            loner = loner | (lonerBit << shift);
        }
        return loner;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        // Loner
        int loner = 0;
        // Iterate over all bits
        for (int shift = 0; shift < 32; shift++) {
            int bitSum = 0;
            // For this bit, iterate over all integers
            foreach (int num in nums) {
                // Compute the bit of num, and add it to bitSum
                bitSum += (num >> shift) & 1;
            }

            // Compute the bit of loner and place it
            int lonerBit = bitSum % 3;
            loner = loner | (lonerBit << shift);
        }

        return loner;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    // Loner
    var loner int = 0
    // Iterate over all bits
    for shift := 0; shift < 32; shift++ {
        var bit_sum int = 0
        // For this bit, iterate over all integers
        for _, num := range nums {
            // Compute the bit of num, and add it to bit_sum
            bit_sum += (num >> shift) & 1
        }
        // Compute the bit of loner and place it
        var loner_bit int = bit_sum % 3
        loner = loner | (loner_bit << shift)
    }
    // Do not mistaken sign bit for MSB.
    if loner >= (1 << 31) {
        loner = loner - (1 << 32)
    }
    return loner
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        // Loner
        int loner = 0;

        // Iterate over all bits
        for (int shift = 0; shift < 32; shift++) {
            int bitSum = 0;

            // For this bit, iterate over all integers
            for (int num : nums) {
                // Compute the bit of num, and add it to bitSum
                bitSum += (num >> shift) & 1;
            }

            // Compute the bit of loner and place it
            int lonerBit = bitSum % 3;
            loner = loner | (lonerBit << shift);
        }
        return loner;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    // Loner
    let loner = 0;
    // Iterate over all bits
    for (let shift = 0; shift < 32; shift++) {
        let bit_sum = 0;
        // For this bit, iterate over all integers
        for (let num of nums) {
            // Compute the bit of num, and add it to bit_sum
            bit_sum += (num >> shift) & 1;
        }
        // Compute the bit of loner and place it
        let loner_bit = bit_sum % 3;
        loner |= loner_bit << shift;
    }
    return loner;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        # Loner.
        loner = 0

        # Iterate over all bits
        for shift in range(32):
            bit_sum = 0

            # For this bit, iterate over all integers
            for num in nums:

                # Compute the bit of num, and add it to bit_sum
                bit_sum += (num >> shift) & 1

            # Compute the bit of loner and place it
            loner_bit = bit_sum % 3
            loner = loner | (loner_bit << shift)

        # Do not mistaken sign bit for MSB.
        if loner >= (1 << 31):
            loner = loner - (1 << 32)

        return loner
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    let seenOnce = 0,
        seenTwice = 0;
    for (let num of nums) {
        seenOnce = ~seenTwice & (seenOnce ^ num);
        seenTwice = ~seenOnce & (seenTwice ^ num);
    }
    return seenOnce;
}
```

</details>

<br>

## Approach 5: Equation for Bitmask

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int singleNumber(int* nums, int numsSize) {
    // Initialize seenOnce and seenTwice to 0
    int seenOnce = 0, seenTwice = 0;

    // Iterate through nums
    for (int i = 0; i < numsSize; i++) {
        // Update using derived equations
        seenOnce = (seenOnce ^ nums[i]) & (~seenTwice);
        seenTwice = (seenTwice ^ nums[i]) & (~seenOnce);
    }

    // Return integer which appears exactly once
    return seenOnce;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Initialize seenOnce and seenTwice to 0
        int seenOnce = 0, seenTwice = 0;

        // Iterate through nums
        for (int num : nums) {
            // Update using derived equations
            seenOnce = (seenOnce ^ num) & (~seenTwice);
            seenTwice = (seenTwice ^ num) & (~seenOnce);
        }

        // Return integer which appears exactly once
        return seenOnce;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        // Initialize seenOnce and seenTwice to 0
        int seenOnce = 0, seenTwice = 0;

        // Iterate through nums
        foreach (int num in nums) {
            // Update using derived equations
            seenOnce = (seenOnce ^ num) & (~seenTwice);
            seenTwice = (seenTwice ^ num) & (~seenOnce);
        }

        // Return integer which appears exactly once
        return seenOnce;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    // Initialize seenOnce and seenTwice to 0
    seenOnce, seenTwice := 0, 0

    // Iterate through nums
    for _, num := range nums {
        // Update using derived equations
        seenOnce = (seenOnce ^ num) & (^seenTwice)
        seenTwice = (seenTwice ^ num) & (^seenOnce)
    }

    // Return integer which appears exactly once
    return seenOnce
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        // Initialize seenOnce and seenTwice to 0
        int seenOnce = 0, seenTwice = 0;

        // Iterate through nums
        for (int num : nums) {
            // Update using derived equations
            seenOnce = (seenOnce ^ num) & (~seenTwice);
            seenTwice = (seenTwice ^ num) & (~seenOnce);
        }

        // Return integer which appears exactly once
        return seenOnce;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    // Initialize seenOnce and seenTwice to 0
    let seenOnce = 0,
        seenTwice = 0;

    // Iterate through nums
    for (let num of nums) {
        // Update using derived equations
        seenOnce = (seenOnce ^ num) & ~seenTwice;
        seenTwice = (seenTwice ^ num) & ~seenOnce;
    }

    // Return integer which appears exactly once
    return seenOnce;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        # Initialize seen_once and seen_twice to 0
        seen_once = seen_twice = 0

        # Iterate through nums
        for num in nums:
            # Update using derived equations
            seen_once = (seen_once ^ num) & (~seen_twice)
            seen_twice = (seen_twice ^ num) & (~seen_once)

        # Return integer which appears exactly once
        return seen_once
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    // Initialize seenOnce and seenTwice to 0
    let seenOnce = 0,
        seenTwice = 0;

    // Iterate through nums
    for (let num of nums) {
        // Update using derived equations
        seenOnce = (seenOnce ^ num) & ~seenTwice;
        seenTwice = (seenTwice ^ num) & ~seenOnce;
    }

    // Return integer which appears exactly once
    return seenOnce;
}
```

</details>

<br>

## Approach 6: Boolean Algebra and Karnaugh Map

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int singleNumber(int* nums, int numsSize) {
    // Count (modulo 3) bits
    int msb = 0, lsb = 0;
    // Process Every Num and update count bits
    for (int i = 0; i < numsSize; i++) {
        int new_lsb = (~msb & ~lsb & nums[i]) | (lsb & ~nums[i]);
        int new_msb = (lsb & nums[i]) | (msb & ~nums[i]);
        lsb = new_lsb;
        msb = new_msb;
    }
    // Return lsb as the answer
    return lsb;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int msb = 0, lsb = 0;
        for (int num : nums) {
            int new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
            int new_msb = (lsb & num) | (msb & ~num);
            lsb = new_lsb;
            msb = new_msb;
        }
        return lsb;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        // Count (modulo 3) bits
        int msb = 0, lsb = 0;
        // Process Every Num and update count bits
        foreach (int num in nums) {
            int new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
            int new_msb = (lsb & num) | (msb & ~num);
            lsb = new_lsb;
            msb = new_msb;
        }

        // Return lsb as the answer
        return lsb;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    // Count (modulo 3) bits
    msb, lsb := 0, 0
    // Process Every Num and update count bits
    for _, num := range nums {
        new_lsb := (^msb & ^lsb & num) | (lsb & ^num)
        new_msb := (lsb & num) | (msb & ^num)
        lsb = new_lsb
        msb = new_msb
    }
    // Return lsb as the answer
    return lsb
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        // Count (modulo 3) bits
        int msb = 0, lsb = 0;

        // Process Every Num and update count bits
        for (int num : nums) {
            int new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
            int new_msb = (lsb & num) | (msb & ~num);
            lsb = new_lsb;
            msb = new_msb;
        }

        // Return lsb as answer
        return lsb;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    // Count (modulo 3) bits
    let msb = 0,
        lsb = 0;
    // Process Every Num and update count bits
    for (let num of nums) {
        var new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
        var new_msb = (lsb & num) | (msb & ~num);
        lsb = new_lsb;
        msb = new_msb;
    }
    // Return lsb as the answer
    return lsb;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        # Count (modulo 3) bits
        msb, lsb = 0, 0

        # Process Every Num and update count bits
        for num in nums:
            new_lsb = (~msb & ~lsb & num) | (lsb & ~num)
            new_msb = (lsb & num) | (msb & ~num)
            lsb = new_lsb
            msb = new_msb

        # Return lsb as the answer
        return lsb
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    // Count (modulo 3) bits
    let msb = 0,
        lsb = 0;
    // Process Every Num and update count bits
    for (let num of nums) {
        let new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
        let new_msb = (lsb & num) | (msb & ~num);
        lsb = new_lsb;
        msb = new_msb;
    }
    // Return lsb as the answer
    return lsb;
}
```

</details>
