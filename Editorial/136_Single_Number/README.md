# 136. Single Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/single-number/)  
`Array` `Bit Manipulation`

**Problem Link:** [LeetCode 136 - Single Number](https://leetcode.com/problems/single-number/)

## Problem

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 3 * 104
- -3 * 104 <= nums[i] <= 3 * 104
- Each element in the array appears twice except for one element which appears only once.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Single Number II](https://leetcode.com/problems/single-number-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Single Number III](https://leetcode.com/problems/single-number-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Missing Number](https://leetcode.com/problems/missing-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Difference](https://leetcode.com/problems/find-the-difference/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the XOR of Numbers Which Appear Twice](https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 136. Single Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| List operation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Math | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bit Manipulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: List operation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int singleNumber(int* nums, int numsSize) {
    int* no_duplicate_list = (int*)malloc(numsSize * sizeof(int));
    if (no_duplicate_list == NULL) {
        return -1;
    }
    memset(no_duplicate_list, 0, numsSize * sizeof(int));
    int no_duplicate_list_size = 0;
    for (int i = 0; i < numsSize; ++i) {
        int found = 0;
        for (int j = 0; j < no_duplicate_list_size; ++j) {
            if (nums[i] == no_duplicate_list[j]) {
                found = 1;
                memmove(&no_duplicate_list[j], &no_duplicate_list[j + 1],
                        (no_duplicate_list_size - j - 1) * sizeof(int));
                --no_duplicate_list_size;
                break;
            }
        }
        if (!found) {
            no_duplicate_list[no_duplicate_list_size++] = nums[i];
        }
    }
    int result = no_duplicate_list[0];
    free(no_duplicate_list);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> no_duplicate_list;
        for (int i : nums) {
            if (find(no_duplicate_list.begin(), no_duplicate_list.end(), i) ==
                no_duplicate_list.end()) {
                no_duplicate_list.push_back(i);
            } else {
                no_duplicate_list.erase(remove(no_duplicate_list.begin(),
                                               no_duplicate_list.end(), i));
            }
        }
        return no_duplicate_list[0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        List<int> no_duplicate_list = new List<int>();
        foreach (int i in nums) {
            if (!no_duplicate_list.Contains(i)) {
                no_duplicate_list.Add(i);
            } else {
                no_duplicate_list.Remove(i);
            }
        }

        return no_duplicate_list[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    no_duplicate_list := []int{}
    for _, i := range nums {
        found := false
        for j, x := range no_duplicate_list {
            if i == x {
                found = true
                no_duplicate_list = append(
                    no_duplicate_list[:j],
                    no_duplicate_list[j+1:]...)
                break
            }
        }
        if !found {
            no_duplicate_list = append(no_duplicate_list, i)
        }
    }
    return no_duplicate_list[0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        List<Integer> no_duplicate_list = new ArrayList<>();

        for (int i : nums) {
            if (!no_duplicate_list.contains(i)) {
                no_duplicate_list.add(i);
            } else {
                no_duplicate_list.remove(new Integer(i));
            }
        }
        return no_duplicate_list.get(0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    var no_duplicate_list = [];
    for (var i of nums) {
        if (!no_duplicate_list.includes(i)) {
            no_duplicate_list.push(i);
        } else {
            no_duplicate_list.splice(no_duplicate_list.indexOf(i), 1);
        }
    }
    return no_duplicate_list[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def singleNumber(self, nums: List[int]) -> int:
        no_duplicate_list = []
        for i in nums:
            if i not in no_duplicate_list:
                no_duplicate_list.append(i)
            else:
                no_duplicate_list.remove(i)
        return no_duplicate_list.pop()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    let no_duplicate_list: number[] = [];
    for (let i of nums) {
        if (!no_duplicate_list.includes(i)) {
            no_duplicate_list.push(i);
        } else {
            no_duplicate_list.splice(no_duplicate_list.indexOf(i), 1);
        }
    }
    return no_duplicate_list[0];
}
```

</details>

<br>

## Approach 2: Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct hashTable {
    int num;
    int count;
    UT_hash_handle hh;
};
int singleNumber(int* nums, int numsSize) {
    struct hashTable* hashTable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(hashTable, nums + i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->num = nums[i];
            tmp->count = 1;
            HASH_ADD_INT(hashTable, num, tmp);
        } else {
            tmp->count++;
        }
    }
    int ans;
    struct hashTable* iter;
    for (iter = hashTable; iter != NULL;
         iter = (struct hashTable*)(iter->hh.next)) {
        if (iter->count == 1) {
            ans = iter->num;
            break;
        }
    }
    struct hashTable *cur, *tmp;
    HASH_ITER(hh, hashTable, cur, tmp) {
        HASH_DEL(hashTable, cur);
        free(cur);
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int num : nums) {
            hash_table[num]++;
        }
        for (int num : nums) {
            if (hash_table[num] == 1) {
                return num;
            }
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
    public int SingleNumber(int[] nums) {
        var hashTable = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (hashTable.ContainsKey(num)) {
                hashTable[num]++;
            } else {
                hashTable[num] = 1;
            }
        }

        foreach (int num in nums) {
            if (hashTable[num] == 1) {
                return num;
            }
        }

        return 0;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    hash_table := make(map[int]int)
    for _, num := range nums {
        hash_table[num]++
    }
    for _, num := range nums {
        if hash_table[num] == 1 {
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
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> hash_table = new HashMap<>();

        for (int i : nums) {
            hash_table.put(i, hash_table.getOrDefault(i, 0) + 1);
        }
        for (int i : nums) {
            if (hash_table.get(i) == 1) {
                return i;
            }
        }
        return 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    let hash_table = {};
    for (let num of nums) {
        if (hash_table[num]) {
            hash_table[num]++;
        } else {
            hash_table[num] = 1;
        }
    }
    for (let num of nums) {
        if (hash_table[num] == 1) {
            return num;
        }
    }
    return 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_table = defaultdict(int)
        for i in nums:
            hash_table[i] += 1

        for i in hash_table:
            if hash_table[i] == 1:
                return i
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    let hash_table: { [key: number]: number } = {};
    for (let num of nums) {
        if (hash_table[num]) {
            hash_table[num]++;
        } else {
            hash_table[num] = 1;
        }
    }
    for (let num of nums) {
        if (hash_table[num] == 1) {
            return num;
        }
    }
    return 0;
}
```

</details>

<br>

## Approach 3: Math

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int singleNumber(int *nums, int numsSize) {
    int sumOfSet = 0, sumOfNums = 0;
    // uthash set
    struct hash_set {
        int id;
        UT_hash_handle hh;
    };
    struct hash_set *mySet = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hash_set *s;
        HASH_FIND_INT(mySet, &nums[i], s);
        if (s == NULL) {
            s = (struct hash_set *)malloc(sizeof *s);
            s->id = nums[i];
            HASH_ADD_INT(mySet, id, s);
            sumOfSet += s->id;
        }
        sumOfNums += nums[i];
    }
    return 2 * sumOfSet - sumOfNums;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sumOfSet = 0, sumOfNums = 0;
        set<int> setNums;
        for (int num : nums) {
            if (setNums.count(num) == 0) {
                setNums.insert(num);
                sumOfSet += num;
            }
            sumOfNums += num;
        }
        return 2 * sumOfSet - sumOfNums;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        int sumOfSet = 0, sumOfNums = 0;
        HashSet<int> set = new HashSet<int>();
        for (int i = 0; i < nums.Length; i++) {
            if (!set.Contains(nums[i])) {
                set.Add(nums[i]);
                sumOfSet += nums[i];
            }

            sumOfNums += nums[i];
        }

        return 2 * sumOfSet - sumOfNums;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func singleNumber(nums []int) int {
    set := make(map[int]bool)
    sumOfSet, sumOfNums := 0, 0
    for _, num := range nums {
        if !set[num] {
            set[num] = true
            sumOfSet += num
        }
        sumOfNums += num
    }
    return 2*sumOfSet - sumOfNums
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        int sumOfSet = 0, sumOfNums = 0;
        Set<Integer> set = new HashSet();

        for (int num : nums) {
            if (!set.contains(num)) {
                set.add(num);
                sumOfSet += num;
            }
            sumOfNums += num;
        }
        return 2 * sumOfSet - sumOfNums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var singleNumber = function (nums) {
    let setSum = 0,
        numsSum = 0;
    const set = new Set();
    for (const num of nums) {
        if (!set.has(num)) {
            set.add(num);
            setSum += num;
        }
        numsSum += num;
    }
    return 2 * setSum - numsSum;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def singleNumber(self, nums: List[int]) -> int:
        return 2 * sum(set(nums)) - sum(nums)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function singleNumber(nums: number[]): number {
    let setSum = 0,
        numsSum = 0;
    const set = new Set<number>();
    for (const num of nums) {
        if (!set.has(num)) {
            set.add(num);
            setSum += num;
        }
        numsSum += num;
    }
    return 2 * setSum - numsSum;
}
```

</details>

<br>

## Approach 4: Bit Manipulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
int singleNumber(int* nums, int numsSize) {
    int a = 0;
    for (int i = 0; i < numsSize; i++) {
        a ^= nums[i];
    }
    return a;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int i : nums) {
            a ^= i;
        }
        return a;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public int SingleNumber(int[] nums) {
        int a = 0;
        foreach (int i in nums) {
            a ^= i;
        }

        return a;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func singleNumber(nums []int) int {
    a := 0
    for _, i := range nums {
        a ^= i
    }
    return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int singleNumber(int[] nums) {
        int a = 0;
        for (int i : nums) {
            a ^= i;
        }
        return a;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var singleNumber = function (nums) {
    let a = 0;
    for (let i of nums) {
        a ^= i;
    }
    return a;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def singleNumber(self, nums: List[int]) -> int:
        a = 0
        for i in nums:
            a ^= i
        return a
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
function singleNumber(nums: number[]): number {
    let a = 0;
    for (let i of nums) {
        a ^= i;
    }
    return a;
}
```

</details>
