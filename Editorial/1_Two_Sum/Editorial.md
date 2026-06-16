# Editorial - 1. Two Sum

**Problem:** [Problem.md](Problem.md)  
**Recommended Python submission:** [Python3/Solution01.py](Python3/Solution01.py)

## Overview

For every number `nums[i]`, the number needed to complete the pair is `target - nums[i]`.

The whole problem is about how quickly we can answer this question:

> Have we seen the complement, and what was its index?

There are three useful ways to think about it:

| Approach | Time | Space | Idea |
|---|:---:|:---:|---|
| Brute Force | `O(n^2)` | `O(1)` | Try every pair. |
| Two-Pass Hash Table | `O(n)` | `O(n)` | Store all values first, then search for complements. |
| One-Pass Hash Table | `O(n)` | `O(n)` | Search for the complement while building the table. |

## Approach 1: Brute Force

### Intuition

The direct way is to compare each index with every index after it. If `nums[i] + nums[j] == target`, those two indices form the answer.

This is the easiest version to reason about, but it repeats a lot of work because every lookup is done by scanning the array again.

### Algorithm

1. Loop through each index `i`.
2. For each `i`, loop through every later index `j`.
3. If the two numbers add up to `target`, return `[i, j]`.

### Complexity

- Time complexity: `O(n^2)`
- Space complexity: `O(1)`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return malloc(0);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for (int i = 0; i < nums.Length; i++) {
            for (int j = i + 1; j < nums.Length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }

        return new int[] {};
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func twoSum(nums []int, target int) []int {
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            if nums[i]+nums[j] == target {
                return []int{i, j}
            }
        }
    }

    return []int{}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }

        return new int[] {};
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var twoSum = function(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }

    return [];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return []
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function twoSum(nums: number[], target: number): number[] {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }

    return [];
}
```

</details>

## Approach 2: Two-Pass Hash Table

### Intuition

Instead of searching the array every time, store each value with its index in a hash table.

After the table is built, each complement lookup becomes fast. The only careful part is making sure the same element is not used twice.

### Algorithm

1. Create a hash table from number value to index.
2. Loop through `nums` again.
3. For each index `i`, compute `complement = target - nums[i]`.
4. If the complement exists in the table and its index is not `i`, return the two indices.

### Complexity

- Time complexity: `O(n)`
- Space complexity: `O(n)`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            item->value = i;
        } else {
            item = malloc(sizeof(struct hashTable));
            item->key = nums[i];
            item->value = i;
            HASH_ADD_INT(hashTable, key, item);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HASH_FIND_INT(hashTable, &complement, item);
        if (item && item->value != i) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = i;
            result[1] = item->value;
            *returnSize = 2;

            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }

            return result;
        }
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    *returnSize = 0;
    return malloc(0);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
            }
        }

        return {};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.Length; i++) {
            int complement = target - nums[i];
            if (map.ContainsKey(complement) && map[complement] != i) {
                return new int[] { i, map[complement] };
            }
        }

        return new int[] {};
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)

    for i, num := range nums {
        seen[num] = i
    }

    for i, num := range nums {
        complement := target - num
        if j, ok := seen[complement]; ok && j != i {
            return []int{i, j}
        }
    }

    return []int{}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement) && map.get(complement) != i) {
                return new int[] { i, map.get(complement) };
            }
        }

        return new int[] {};
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var twoSum = function(nums, target) {
    const map = new Map();

    for (let i = 0; i < nums.length; i++) {
        map.set(nums[i], i);
    }

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        if (map.has(complement) && map.get(complement) !== i) {
            return [i, map.get(complement)];
        }
    }

    return [];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for i, num in enumerate(nums):
            seen[num] = i

        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen and seen[complement] != i:
                return [i, seen[complement]]

        return []
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function twoSum(nums: number[], target: number): number[] {
    const map = new Map<number, number>();

    for (let i = 0; i < nums.length; i++) {
        map.set(nums[i], i);
    }

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        const complementIndex = map.get(complement);
        if (complementIndex !== undefined && complementIndex !== i) {
            return [i, complementIndex];
        }
    }

    return [];
}
```

</details>

## Approach 3: One-Pass Hash Table

### Intuition

The two-pass version builds the whole table before checking answers. We can do better in practice by checking the complement first, then storing the current number.

At index `i`, the hash table contains only earlier numbers. If `target - nums[i]` is already there, we immediately know the earlier index and the current index.

### Algorithm

1. Start with an empty hash table.
2. For each index `i`, compute `complement = target - nums[i]`.
3. If `complement` is already in the hash table, return its stored index and `i`.
4. Otherwise, store `nums[i]` with index `i`.

### Complexity

- Time complexity: `O(n)`
- Space complexity: `O(n)`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        HASH_FIND_INT(hashTable, &complement, item);

        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;

            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }

            return result;
        }

        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            item->value = i;
        } else {
            item = malloc(sizeof(struct hashTable));
            item->key = nums[i];
            item->value = i;
            HASH_ADD_INT(hashTable, key, item);
        }
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    *returnSize = 0;
    return malloc(0);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> seen = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            int complement = target - nums[i];
            if (seen.ContainsKey(complement)) {
                return new int[] { seen[complement], i };
            }

            seen[nums[i]] = i;
        }

        return new int[] {};
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)

    for i, num := range nums {
        complement := target - num
        if j, ok := seen[complement]; ok {
            return []int{j, i}
        }

        seen[num] = i
    }

    return []int{}
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (seen.containsKey(complement)) {
                return new int[] { seen.get(complement), i };
            }

            seen.put(nums[i], i);
        }

        return new int[] {};
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var twoSum = function(nums, target) {
    const seen = new Map();

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        if (seen.has(complement)) {
            return [seen.get(complement), i];
        }

        seen.set(nums[i], i);
    }

    return [];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]

            seen[num] = i

        return []
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function twoSum(nums: number[], target: number): number[] {
    const seen = new Map<number, number>();

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        const complementIndex = seen.get(complement);
        if (complementIndex !== undefined) {
            return [complementIndex, i];
        }

        seen.set(nums[i], i);
    }

    return [];
}
```

</details>

## Which One Should I Remember?

Use the one-pass hash table in interviews and submissions. It keeps the idea short:

1. Check whether the needed complement was seen earlier.
2. If yes, return the earlier index and current index.
3. If no, store the current number for future checks.

That pattern appears in many array/hash-map problems, so this problem is a good place to memorize it.
