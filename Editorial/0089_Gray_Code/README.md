# 89. Gray Code

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/gray-code/)  
`Math` `Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 89 - Gray Code](https://leetcode.com/problems/gray-code/)

## Problem

An n-bit gray code sequence is a sequence of 2n integers where:

- Every integer is in the inclusive range [0, 2n - 1],
- The first integer is 0,
- An integer appears no more than once in the sequence,
- The binary representation of every pair of adjacent integers differs by exactly one bit, and
- The binary representation of the first and last integers differs by exactly one bit.

Given an integer n, return any valid n-bit gray code sequence.

### Example 1

```text
Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
```

### Example 2

```text
Input: n = 1
Output: [0,1]
```

## Constraints

- 1 <= n <= 16

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [1-bit and 2-bit Characters](https://leetcode.com/problems/1-bit-and-2-bit-characters/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 89. Gray Code

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursion 2 | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iteration with a single loop | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Define the struct for uthash
typedef struct {
    int id;
    UT_hash_handle hh;
} Record;
int grayCodeHelper(int *res, int n, int *idx, Record **records);
int *grayCode(int n, int *returnSize) {
    *returnSize = 1 << n;
    int *res = malloc((*returnSize) * sizeof(*res));
    memset(res, 0, (*returnSize) * sizeof(*res));
    Record *records = NULL;
    Record *tmp = malloc(sizeof(*tmp));
    tmp->id = 0;
    HASH_ADD_INT(records, id, tmp);
    int start_idx = 1;
    grayCodeHelper(res, n, &start_idx, &records);
    // Clean up the hash table
    while (records) {
        tmp = records;
        HASH_DEL(records, tmp);
        free(tmp);
    }
    return res;
}
int grayCodeHelper(int *res, int n, int *idx, Record **records) {
    if (*idx == 1 << n) return 1;
    int current = res[*idx - 1];
    for (int i = 0; i < n; i++) {
        int next = current ^ (1 << i);
        Record *tmp;
        HASH_FIND_INT(*records, &next, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(*tmp));
            tmp->id = next;
            HASH_ADD_INT(*records, id, tmp);
            res[*idx] = next;
            (*idx)++;
            if (grayCodeHelper(res, n, idx, records)) return 1;
            HASH_DEL(*records, tmp);
            free(tmp);
            (*idx)--;
        }
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
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        // Keeps track of the numbers present in the current sequence.
        unordered_set<int> isPresent;
        // All Gray code sequence starts with 0
        isPresent.insert(0);
        grayCodeHelper(result, n, isPresent);
        return result;
    }

private:
    bool grayCodeHelper(vector<int> &result, int n,
                        unordered_set<int> &isPresent) {
        if (result.size() == (1 << n)) return true;

        int current = result[result.size() - 1];
        for (int i = 0; i < n; i++) {
            int next = current ^ (1 << i);
            if (isPresent.find(next) == isPresent.end()) {
                isPresent.insert(next);
                result.push_back(next);
                // If valid sequence found no need to search any further
                if (grayCodeHelper(result, n, isPresent)) return true;
                // If no valid sequence found delete the last added number and
                // continue the search.
                isPresent.erase(next);
                result.pop_back();
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
using System.Threading;

public class Solution {
    private List<int> result;
    private HashSet<int> isPresent;

    public List<int> GrayCode(int n) {
        result = new List<int> { 0 };
        // Keeps track of the numbers present in the current sequence.
        // All Gray code sequence starts with 0
        isPresent = new HashSet<int> { 0 };

        // Create a new thread with increased stack size
        Thread thread = new Thread(() => GrayCodeHelper(0, n),
                                   1024 * 1024 * 10);  // 10 MB stack
        thread.Start();
        thread.Join();  // Wait for the thread to complete

        return result;
    }

    private bool GrayCodeHelper(int current, int n) {
        if (result.Count == (1 << n))
            return true;

        for (int i = 0; i < n; i++) {
            int next = current ^ (1 << i);
            if (!isPresent.Contains(next)) {
                isPresent.Add(next);
                result.Add(next);
                if (GrayCodeHelper(next, n))
                    return true;  // Early exit on success

                // If no valid sequence found, backtrack
                isPresent.Remove(next);
                result.RemoveAt(result.Count - 1);
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func grayCode(n int) []int {
    seen := map[int]bool{0: true}
    res := []int{0}
    var helper func(n int, seen map[int]bool) bool
    helper = func(n int, seen map[int]bool) bool {
        if len(res) == 1<<n {
            return true
        }
        curr := res[len(res)-1]
        for i := 0; i < n; i++ {
            next := curr ^ (1 << i)
            if seen[next] == false {
                seen[next] = true
                res = append(res, next)
                if helper(n, seen) {
                    return true
                }
                seen[next] = false
                res = res[:len(res)-1]
            }
        }
        return false
    }
    helper(n, seen)
    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        result.add(0);
        // Keeps track of the numbers present in the current sequence.
        Set<Integer> isPresent = new HashSet<>();
        // All Gray code sequence starts with 0
        isPresent.add(0);
        grayCodeHelper(result, n, isPresent);
        return result;
    }

    private boolean grayCodeHelper(
        List<Integer> result,
        int n,
        Set<Integer> isPresent
    ) {
        if (result.size() == (1 << n)) return true;

        int current = result.get(result.size() - 1);
        for (int i = 0; i < n; i++) {
            int next = current ^ (1 << i);
            if (!isPresent.contains(next)) {
                isPresent.add(next);
                result.add(next);
                // If valid sequence found no need to search any further
                if (grayCodeHelper(result, n, isPresent)) return true;
                // If no valid sequence found delete the last added number and continue the search.
                isPresent.remove(next);
                result.remove(result.size() - 1);
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var grayCode = function (n) {
    const res = [0];
    const seen = new Set(res);
    const helper = (n, res, seen) => {
        if (res.length === Math.pow(2, n)) {
            return true;
        }
        const curr = res[res.length - 1];
        for (let i = 0; i < n; i++) {
            const next = curr ^ (1 << i);
            if (!seen.has(next)) {
                seen.add(next);
                res.push(next);
                if (helper(n, res, seen)) return true;
                seen.delete(next);
                res.pop();
            }
        }
        return false;
    };
    helper(n, res, seen);
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def grayCode(self, n: int):
        result = [0]
        isPresent = {0}
        self.grayCodeHelper(result, n, isPresent)
        return result

    def grayCodeHelper(self, result, n, isPresent):
        if len(result) == (1 << n):
            return True
        current = result[-1]
        for i in range(n):
            nextNum = current ^ (1 << i)
            if nextNum not in isPresent:
                isPresent.add(nextNum)
                result.append(nextNum)
                if self.grayCodeHelper(result, n, isPresent):
                    return True
                isPresent.remove(nextNum)
                result.pop()
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function grayCode(n: number): number[] {
    const res: number[] = [0];
    const seen = new Set(res);
    const helper = (n: number, res: number[], seen: Set<Number>) => {
        if (res.length === Math.pow(2, n)) {
            return true;
        }
        const curr = res[res.length - 1];
        for (let i = 0; i < n; i++) {
            const next = curr ^ (1 << i);
            if (!seen.has(next)) {
                seen.add(next);
                res.push(next);
                if (helper(n, res, seen)) return true;
                seen.delete(next);
                res.pop();
            }
        }
        return false;
    };
    helper(n, res, seen);
    return res;
}
```

</details>

<br>

## Approach 2: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void grayCodeHelper(int* result, int* resultSize, int n);
int* grayCode(int n, int* returnSize) {
    int* result = (int*)malloc((1 << n) * sizeof(int));
    *returnSize = 0;
    grayCodeHelper(result, returnSize, n);
    return result;
}
void grayCodeHelper(int* result, int* resultSize, int n) {
    if (n == 0) {
        result[(*resultSize)++] = 0;
        return;
    }
    // derive the n bits sequence from the (n - 1) bits sequence.
    grayCodeHelper(result, resultSize, n - 1);
    int currentSequenceLength = *resultSize;
    // Set the bit at position n - 1 (0 indexed) and assign it to mask.
    int mask = 1 << (n - 1);
    for (int i = currentSequenceLength - 1; i >= 0; i--) {
        // mask is used to set the (n - 1)th bit from the LSB of all the numbers
        // present in the current sequence.
        result[(*resultSize)++] = result[i] | mask;
    }
    return;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        grayCodeHelper(result, n);

        return result;
    }

    void grayCodeHelper(vector<int>& result, int n) {
        if (n == 0) {
            result.push_back(0);
            return;
        }
        // we derive the n bits sequence from the (n - 1) bits sequence.
        grayCodeHelper(result, n - 1);
        int currentSequenceLength = result.size();
        // Set the bit at position n - 1 (0 indexed) and assign it to mask.
        int mask = 1 << (n - 1);
        for (int i = currentSequenceLength - 1; i >= 0; i--) {
            // mask is used to set the (n - 1)th bit from the LSB of all the
            // numbers present in the current sequence.
            result.push_back(result[i] | mask);
        }
        return;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    List<int> result = new List<int>();

    public IList<int> GrayCode(int n) {
        GrayCodeHelper(n);
        return result;
    }

    void GrayCodeHelper(int n) {
        if (n == 0) {
            result.Add(0);
            return;
        }

        // derive the n bits sequence from the (n - 1) bits sequence.
        GrayCodeHelper(n - 1);
        int currentSequenceLength = result.Count;
        // Set the bit at position n - 1 (0 indexed) and assign it to mask.
        int mask = 1 << (n - 1);
        for (int i = currentSequenceLength - 1; i >= 0; i--) {
            // mask is used to set the (n - 1)th bit from the LSB of all the
            // numbers present in the current sequence.
            result.Add(result[i] | mask);
        }

        return;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func grayCode(n int) []int {
    var result []int
    grayCodeHelper(&result, n)
    return result
}

func grayCodeHelper(result *[]int, n int) {
    if n == 0 {
        *result = append(*result, 0)
        return
    }
    // derive the n bits sequence from the (n - 1) bits sequence.
    grayCodeHelper(result, n-1)
    currentSequenceLength := len(*result)
    // Set the bit at position n - 1 (0 indexed) and assign it to mask.
    mask := 1 << (n - 1)
    for i := currentSequenceLength - 1; i >= 0; i-- {
        // mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
        *result = append(*result, (*result)[i]|mask)
    }
    return
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        grayCodeHelper(result, n);
        return result;
    }

    private void grayCodeHelper(List<Integer> result, int n) {
        if (n == 0) {
            result.add(0);
            return;
        }
        // we derive the n bits sequence from the (n - 1) bits sequence.
        grayCodeHelper(result, n - 1);
        int currentSequenceLength = result.size();
        // Set the bit at position n - 1 (0 indexed) and assign it to mask.
        int mask = 1 << (n - 1);
        for (int i = currentSequenceLength - 1; i >= 0; i--) {
            // mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
            result.add(result.get(i) | mask);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var grayCode = function (n) {
    let result = [];
    grayCodeHelper(result, n);
    return result;
    function grayCodeHelper(result, n) {
        if (n === 0) {
            result.push(0);
            return;
        }
        // derive the n bits sequence from the (n - 1) bits sequence.
        grayCodeHelper(result, n - 1);
        let currentSequenceLength = result.length;
        // Set the bit at position n - 1 (0 indexed) and assign it to mask.
        let mask = 1 << (n - 1);
        for (let i = currentSequenceLength - 1; i >= 0; i--) {
            // mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
            result.push(result[i] | mask);
        }
        return;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        result = []
        self.grayCodeHelper(result, n)
        return result

    def grayCodeHelper(self, result: List[int], n: int):
        if n == 0:
            result.append(0)
            return
        # derive the n bits sequence from the (n - 1) bits sequence.
        self.grayCodeHelper(result, n - 1)
        currentSequenceLength = len(result)
        # Set the bit at position n - 1 (0 indexed) and assign it to mask.
        mask = 1 << (n - 1)
        for i in range(currentSequenceLength - 1, -1, -1):
            # mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
            result.append(result[i] | mask)
        return
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function grayCode(n: number): number[] {
    let result: number[] = [];
    grayCodeHelper(result, n);
    return result;
    function grayCodeHelper(result: number[], n: number) {
        if (n == 0) {
            result.push(0);
            return;
        }
        // derive the n bits sequence from the (n - 1) bits sequence.
        grayCodeHelper(result, n - 1);
        let currentSequenceLength = result.length;
        // Set the bit at position n - 1 (0 indexed) and assign it to mask.
        let mask = 1 << (n - 1);
        for (let i = currentSequenceLength - 1; i >= 0; i--) {
            // mask is used to set the (n - 1)th bit from the LSB of all the numbers present in the current sequence.
            result.push(result[i] | mask);
        }
        return;
    }
}
```

</details>

<br>

## Approach 3: Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* grayCode(int n, int* returnSize) {
    int resultSize = 1;
    for (int i = 0; i < n; i++) {
        resultSize *= 2;
    }
    *returnSize = resultSize;
    int* result = (int*)malloc(sizeof(int) * resultSize);
    result[0] = 0;
    int length = 1;
    for (int i = 1; i <= n; i++) {
        int mask = 1 << (i - 1);
        for (int j = length - 1; j >= 0; j--) {
            result[length++] = mask + result[j];
        }
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);

        for (int i = 1; i <= n; i++) {
            int previousSequenceLength = result.size();
            int mask = 1 << (i - 1);
            for (int j = previousSequenceLength - 1; j >= 0; j--) {
                result.push_back(mask + result[j]);
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<int> GrayCode(int n) {
        IList<int> result = new List<int>();
        result.Add(0);
        for (int i = 1; i <= n; i++) {
            int previousSequenceLength = result.Count;
            int mask = 1 << (i - 1);
            for (int j = previousSequenceLength - 1; j >= 0; j--) {
                result.Add(mask + result[j]);
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func grayCode(n int) []int {
    result := []int{0}
    for i := 1; i <= n; i++ {
        previousSequenceLength := len(result)
        mask := 1 << (i - 1)
        for j := previousSequenceLength - 1; j >= 0; j-- {
            result = append(result, mask+result[j])
        }
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        result.add(0);

        for (int i = 1; i <= n; i++) {
            int previousSequenceLength = result.size();
            int mask = 1 << (i - 1);
            for (int j = previousSequenceLength - 1; j >= 0; j--) {
                result.add(mask + result.get(j));
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var grayCode = function (n) {
    let result = [0];
    for (let i = 1; i <= n; i++) {
        let previousSequenceLength = result.length;
        let mask = 1 << (i - 1);
        for (let j = previousSequenceLength - 1; j >= 0; j--) {
            result.push(mask + result[j]);
        }
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def grayCode(self, n):
        result = [0]
        for i in range(1, n + 1):
            previousSequenceLength = len(result)
            mask = 1 << (i - 1)
            for j in range(previousSequenceLength - 1, -1, -1):
                result.append(mask + result[j])
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function grayCode(n: number): number[] {
    let result: number[] = [0];
    for (let i = 1; i <= n; i++) {
        let previousSequenceLength = result.length;
        let mask = 1 << (i - 1);
        for (let j = previousSequenceLength - 1; j >= 0; j--) {
            result.push(mask + result[j]);
        }
    }
    return result;
}
```

</details>

<br>

## Approach 4: Recursion 2

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int nextNum = 0;
void grayCodeHelper(int* result, int* size, int n) {
    if (n == 0) {
        result[*size] = nextNum;
        (*size)++;
        return;
    }
    grayCodeHelper(result, size, n - 1);
    nextNum = nextNum ^ (1 << (n - 1));
    grayCodeHelper(result, size, n - 1);
}
int* grayCode(int n, int* returnSize) {
    int max = 1 << n;
    int* result = (int*)malloc(sizeof(int) * max);
    *returnSize = 0;
    nextNum = 0;
    grayCodeHelper(result, returnSize, n);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        grayCodeHelper(result, n);
        return result;
    }

private:
    int nextNum = 0;

    void grayCodeHelper(vector<int> &result, int n) {
        if (n == 0) {
            result.push_back(nextNum);
            return;
        }
        grayCodeHelper(result, n - 1);
        // Flip the bit at (n - 1)th position from right
        nextNum = nextNum ^ (1 << (n - 1));
        grayCodeHelper(result, n - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int nextNum = 0;

    public IList<int> GrayCode(int n) {
        List<int> result = new List<int>();
        GrayCodeHelper(result, n);
        return result;
    }

    private void GrayCodeHelper(List<int> result, int n) {
        if (n == 0) {
            result.Add(this.nextNum);
            return;
        }

        GrayCodeHelper(result, n - 1);
        // Flip the bit at (n - 1)th position from right
        this.nextNum = this.nextNum ^ (1 << (n - 1));
        GrayCodeHelper(result, n - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
var nextNum int

func grayCode(n int) []int {
    var result []int
    nextNum = 0
    grayCodeHelper(&result, n)
    return result
}

func grayCodeHelper(result *[]int, n int) {
    if n == 0 {
        *result = append(*result, nextNum)
        return
    }
    grayCodeHelper(result, n-1)
    // Flip the bit at (n - 1)th position from right
    nextNum = nextNum ^ (1 << (n - 1))
    grayCodeHelper(result, n-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int nextNum = 0;

    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        grayCodeHelper(result, n);
        return result;
    }

    private void grayCodeHelper(List<Integer> result, int n) {
        if (n == 0) {
            result.add(nextNum);
            return;
        }
        grayCodeHelper(result, n - 1);
        // Flip the bit at (n - 1)th position from right
        nextNum = nextNum ^ (1 << (n - 1));
        grayCodeHelper(result, n - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let nextNum = 0;
var grayCode = function (n) {
    let result = [];
    grayCodeHelper(result, n);
    nextNum = 0; // reset global variable
    return result;
};
let grayCodeHelper = function (result, n) {
    if (n == 0) {
        result.push(nextNum);
        return;
    }
    grayCodeHelper(result, n - 1);
    // Flip the bit at (n - 1)th position from right
    nextNum = nextNum ^ (1 << (n - 1));
    grayCodeHelper(result, n - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.nextNum = 0

    def grayCode(self, n):
        self.result = []
        self.grayCodeHelper(n)
        return self.result

    def grayCodeHelper(self, n):
        if n == 0:
            self.result.append(self.nextNum)
            return
        self.grayCodeHelper(n - 1)
        # Flip the bit at (n - 1)th position from right
        self.nextNum = self.nextNum ^ (1 << (n - 1))
        self.grayCodeHelper(n - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
let nextNum = 0;
function grayCode(n: number): number[] {
    let result: number[] = [];
    grayCodeHelper(result, n);
    nextNum = 0; //reset global variable after all recursions
    return result;
}
let grayCodeHelper = function (result: number[], n: number): void {
    if (n == 0) {
        result.push(nextNum);
        return;
    }
    grayCodeHelper(result, n - 1);
    // Flip the bit at (n - 1)th position from right
    nextNum = nextNum ^ (1 << (n - 1));
    grayCodeHelper(result, n - 1);
};
```

</details>

<br>

## Approach 5: Iteration with a single loop

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* grayCode(int n, int* returnSize) {
    // there are 2 ^ n numbers in the Gray code sequence.
    int sequenceLength = 1 << n;
    *returnSize = sequenceLength;
    int* result = (int*)malloc(sizeof(int) * sequenceLength);
    for (int i = 0; i < sequenceLength; i++) {
        int num = i ^ i >> 1;
        result[i] = num;
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        // there are 2 ^ n numbers in the Gray code sequence.
        int sequenceLength = 1 << n;
        for (int i = 0; i < sequenceLength; i++) {
            int num = i ^ i >> 1;
            result.push_back(num);
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<int> GrayCode(int n) {
        IList<int> result = new List<int>();
        // there are 2 ^ n numbers in the Gray code sequence.
        int sequenceLength = 1 << n;
        for (int i = 0; i < sequenceLength; i++) {
            int num = i ^ i >> 1;
            result.Add(num);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func grayCode(n int) []int {
    result := make([]int, 0)
    // there are 2 ^ n numbers in the Gray code sequence.
    sequenceLength := 1 << n
    for i := 0; i < sequenceLength; i++ {
        num := i ^ i>>1
        result = append(result, num)
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        // there are 2 ^ n numbers in the Gray code sequence.
        int sequenceLength = 1 << n;
        for (int i = 0; i < sequenceLength; i++) {
            int num = i ^ (i >> 1);
            result.add(num);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var grayCode = function (n) {
    let result = [];
    // there are 2 ^ n numbers in the Gray code sequence.
    let sequenceLength = 1 << n;
    for (let i = 0; i < sequenceLength; i++) {
        let num = i ^ (i >> 1);
        result.push(num);
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def grayCode(self, n: int):
        result = []
        # there are 2 ^ n numbers in the Gray code sequence.
        sequenceLength = 1 << n
        for i in range(sequenceLength):
            num = i ^ i >> 1
            result.append(num)
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function grayCode(n: number): number[] {
    let result = [];
    // there are 2 ^ n numbers in the Gray code sequence.
    let sequenceLength = 1 << n;
    for (let i = 0; i < sequenceLength; i++) {
        let num = i ^ (i >> 1);
        result.push(num);
    }
    return result;
}
```

</details>
