# 2094. Finding 3-Digit Even Numbers

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/finding-3-digit-even-numbers/)  
`Array` `Hash Table` `Recursion` `Sorting` `Enumeration`

**Problem Link:** [LeetCode 2094 - Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/)

## Problem

You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

- The integer consists of the concatenation of three elements from digits in any arbitrary order.
- The integer does not have leading zeros.
- The integer is even.

For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

### Example 1

```text
Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array.
Notice that there are no odd integers or integers with leading zeros.
```

### Example 2

```text
Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits.
In this example, the digit 8 is used twice each time in 288, 828, and 882.
```

### Example 3

```text
Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
```

## Constraints

- 3 <= digits.length <= 100
- 0 <= digits[i] <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2094. Finding 3-Digit Even Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumerate the Element Combinations in an Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Traverse All Possible 3-Digit Even Numbers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumerate the Element Combinations in an Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int *findEvenNumbers(int *digits, int digitsSize, int *returnSize) {
    HashItem *nums = NULL;  // Target even set
    int n = digitsSize;
    // Traverse the indices of three digits
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                // Determine whether it meets the condition of the target even
                // number
                if (i == j || j == k || i == k) {
                    continue;
                }
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (num >= 100 && num % 2 == 0) {
                    hashAddItem(&nums, num);
                }
            }
        }
    }

    // Converted to an array sorted in ascending order
    int numsSize = HASH_COUNT(nums);
    *returnSize = numsSize;
    int *res = (int *)malloc(sizeof(int) * numsSize);
    int pos = 0;
    for (HashItem *pEntry = nums; pEntry; pEntry = pEntry->hh.next) {
        res[pos++] = pEntry->key;
    }
    qsort(res, numsSize, sizeof(int), compare);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> nums;  // Target even set
        int n = digits.size();
        // Traverse the indices of three digits
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // Determine whether it meets the condition of the target
                    // even number
                    if (i == j || j == k || i == k) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0) {
                        nums.insert(num);
                    }
                }
            }
        }
        // Converted to an array sorted in ascending order
        vector<int> res;
        for (const int num : nums) {
            res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] FindEvenNumbers(int[] digits) {
        HashSet<int> nums = new HashSet<int>();
        int n = digits.Length;
        // Traverse the indices of three digits
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // Determine whether it meets the condition of the target
                    // even number
                    if (i == j || j == k || i == k) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0) {
                        nums.Add(num);
                    }
                }
            }
        }
        // Converted to an array sorted in ascending order
        List<int> res = nums.ToList();
        res.Sort();
        return res.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findEvenNumbers(digits []int) []int {
	nums := make(map[int]bool)
	n := len(digits)
	// Traverse the indices of three digits
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				// Determine whether it meets the condition of the target even
				// number
				if i == j || j == k || i == k {
					continue
				}
				num := digits[i]*100 + digits[j]*10 + digits[k]
				if num >= 100 && num%2 == 0 {
					nums[num] = true
				}
			}
		}
	}
	// Converted to an array sorted in ascending order
	res := make([]int, 0, len(nums))
	for num := range nums {
		res = append(res, num)
	}
	sort.Ints(res)
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] findEvenNumbers(int[] digits) {
        Set<Integer> nums = new HashSet<>();
        int n = digits.length;
        // Traverse the indices of three digits
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // Determine whether it meets the condition of the target even number
                    if (i == j || j == k || i == k) {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0) {
                        nums.add(num);
                    }
                }
            }
        }
        // Converted to an array sorted in ascending order
        List<Integer> res = new ArrayList<>(nums);
        Collections.sort(res);
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); ++i) {
            result[i] = res.get(i);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findEvenNumbers = function (digits) {
    const nums = new Set();
    const n = digits.length;
    // Traverse the indices of three digits
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < n; ++k) {
                // Determine whether it meets the condition of the target even number
                if (i === j || j === k || i === k) {
                    continue;
                }
                const num = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (num >= 100 && num % 2 === 0) {
                    nums.add(num);
                }
            }
        }
    }
    // Converted to an array sorted in ascending order
    const res = Array.from(nums).sort((a, b) => a - b);
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        nums = set()  # Target even set
        n = len(digits)
        # Traverse the indices of three digits
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    # Determine whether it meets the condition of the target even number
                    if i == j or j == k or i == k:
                        continue
                    num = digits[i] * 100 + digits[j] * 10 + digits[k]
                    if num >= 100 and num % 2 == 0:
                        nums.add(num)
        # Converted to an array sorted in ascending order
        res = sorted(list(nums))
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findEvenNumbers(digits: number[]): number[] {
    const nums = new Set<number>();
    const n = digits.length;
    // Traverse the indices of three digits
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < n; ++k) {
                // Determine whether it meets the condition of the target even number
                if (i === j || j === k || i === k) {
                    continue;
                }
                const num = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (num >= 100 && num % 2 === 0) {
                    nums.add(num);
                }
            }
        }
    }
    // Converted to an array sorted in ascending order
    const res = Array.from(nums).sort((a, b) => a - b);
    return res;
}
```

</details>

<br>

## Approach 2: Traverse All Possible 3-Digit Even Numbers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int *findEvenNumbers(int *digits, int digitsSize, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * 500);  // Target even number array
    HashItem *freq = NULL;  // The frequency of each number in the integer array
    for (int i = 0; i < digitsSize; i++) {
        int digit = digits[i];
        hashSetItem(&freq, digit, hashGetItem(&freq, digit, 0) + 1);
    }
    // Enumerate all three-digit even numbers, maintain the frequency of each
    // digit in the integer, and compare and judge whether it is the target even
    // number
    int pos = 0;
    for (int i = 100; i < 1000; i += 2) {
        int freq1[10] = {0};
        int tmp = i;
        while (tmp) {
            ++freq1[tmp % 10];
            tmp /= 10;
        }
        // Check if the conditions are met
        bool isValid = true;
        for (int j = 0; j < 10; j++) {
            if (freq1[j] == 0) {
                continue;
            }
            if (!hashFindItem(&freq, j) ||
                hashGetItem(&freq, j, 0) < freq1[j]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            res[pos++] = i;
        }
    }
    *returnSize = pos;
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;  // Target even number array
        unordered_map<int, int>
            freq;  // The frequency of each number in the integer array
        for (const int digit : digits) {
            ++freq[digit];
        }
        // Enumerate all three-digit even numbers, maintain the frequency of
        // each digit in the integer, and compare and judge whether it is the
        // target even number
        for (int i = 100; i < 1000; i += 2) {
            unordered_map<int, int> freq1;
            int tmp = i;
            while (tmp) {
                ++freq1[tmp % 10];
                tmp /= 10;
            }
            if (all_of(freq1.begin(), freq1.end(), [&](const auto& x) {
                    return freq[x.first] >= freq1[x.first];
                })) {
                res.push_back(i);
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] FindEvenNumbers(int[] digits) {
        List<int> res = new List<int>();
        Dictionary<int, int> freq = new Dictionary<int, int>();
        // Count the number of occurrences of each number in the integer array
        foreach (int d in digits) {
            freq[d] = freq.ContainsKey(d) ? freq[d] + 1 : 1;
        }
        // Enumerate all three-digit even numbers
        for (int i = 100; i < 1000; i += 2) {
            Dictionary<int, int> freq1 = new Dictionary<int, int>();
            int num = i;
            // Count the frequency of each digit of the current even number
            while (num > 0) {
                int d = num % 10;
                freq1[d] = freq1.ContainsKey(d) ? freq1[d] + 1 : 1;
                num /= 10;
            }
            // Check if the conditions are met
            bool isValid = true;
            foreach (var entry in freq1) {
                if (!freq.ContainsKey(entry.Key) ||
                    freq[entry.Key] < entry.Value) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                res.Add(i);
            }
        }
        return res.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findEvenNumbers(digits []int) []int {
	res := []int{}
	freq := make(map[int]int)
	// Count the number of occurrences of each number in the integer array
	for _, d := range digits {
		freq[d]++
	}
	// Enumerate all three-digit even numbers
	for i := 100; i < 1000; i += 2 {
		freq1 := make(map[int]int)
		num := i
		// Count the frequency of each digit of the current even number
		for num > 0 {
			d := num % 10
			freq1[d]++
			num /= 10
		}
		// Check if the conditions are met
		isValid := true
		for d, count := range freq1 {
			if freq[d] < count {
				isValid = false
				break
			}
		}
		if isValid {
			res = append(res, i)
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] findEvenNumbers(int[] digits) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> freq = new HashMap<>();
        // Count the number of occurrences of each number in the integer array
        for (int d : digits) {
            freq.put(d, freq.getOrDefault(d, 0) + 1);
        }
        // Enumerate all three-digit even numbers
        for (int i = 100; i < 1000; i += 2) {
            Map<Integer, Integer> freq1 = new HashMap<>();
            int num = i;
            // Count the frequency of each digit of the current even number
            while (num > 0) {
                int d = num % 10;
                freq1.put(d, freq1.getOrDefault(d, 0) + 1);
                num /= 10;
            }
            // Check if the conditions are met
            boolean isValid = true;
            for (Map.Entry<Integer, Integer> entry : freq1.entrySet()) {
                if (freq.getOrDefault(entry.getKey(), 0) < entry.getValue()) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                res.add(i);
            }
        }
        // Convert to array
        int[] result = new int[res.size()];
        for (int j = 0; j < res.size(); j++) {
            result[j] = res.get(j);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findEvenNumbers = function (digits) {
    const res = [];
    const freq = new Map();
    // Count the number of occurrences of each number in the integer array
    for (const d of digits) {
        freq.set(d, (freq.get(d) || 0) + 1);
    }
    // Enumerate all three-digit even numbers
    for (let i = 100; i < 1000; i += 2) {
        const freq1 = new Map();
        let num = i;
        // Count the frequency of each digit of the current even number
        while (num > 0) {
            const d = num % 10;
            freq1.set(d, (freq1.get(d) || 0) + 1);
            num = Math.floor(num / 10);
        }
        // Check if the conditions are met
        let isValid = true;
        for (const [d, count] of freq1.entries()) {
            if ((freq.get(d) || 0) < count) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            res.push(i);
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        res = []  # Target even number array
        freq = Counter(
            digits
        )  # The frequency of each number in the integer array
        # Enumerate all three-digit even numbers, maintain the frequency of each digit in the integer, and compare and judge whether it is the target even number
        for i in range(100, 1000, 2):
            freq1 = Counter([int(d) for d in str(i)])
            if all(freq[d] >= freq1[d] for d in freq1.keys()):
                res.append(i)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findEvenNumbers(digits: number[]): number[] {
    const res: number[] = [];
    const freq = new Map<number, number>();
    // Count the number of occurrences of each number in the integer array
    for (const d of digits) {
        freq.set(d, (freq.get(d) || 0) + 1);
    }
    // Enumerate all three-digit even numbers
    for (let i = 100; i < 1000; i += 2) {
        const freq1 = new Map<number, number>();
        let num = i;
        // Count the frequency of each digit of the current even number
        while (num > 0) {
            const d = num % 10;
            freq1.set(d, (freq1.get(d) || 0) + 1);
            num = Math.floor(num / 10);
        }
        // Check if the conditions are met
        let isValid = true;
        for (const [d, count] of freq1.entries()) {
            if ((freq.get(d) || 0) < count) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            res.push(i);
        }
    }
    return res;
}
```

</details>
