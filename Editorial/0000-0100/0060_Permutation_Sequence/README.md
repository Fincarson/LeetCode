# 60. Permutation Sequence

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/permutation-sequence/)  
`Math` `Recursion`

**Problem Link:** [LeetCode 60 - Permutation Sequence](https://leetcode.com/problems/permutation-sequence/)

## Problem

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

Given n and k, return the kth permutation sequence.

### Example 1

```text
Input: n = 3, k = 3
Output: "213"
```

### Example 2

```text
Input: n = 4, k = 9
Output: "2314"
```

### Example 3

```text
Input: n = 3, k = 1
Output: "123"
```

## Constraints

- 1 <= n <= 9
- 1 <= k <= n!

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Permutation](https://leetcode.com/problems/next-permutation/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Permutations](https://leetcode.com/problems/permutations/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 60. Permutation Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Factorial Number System | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Factorial Number System

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *getPermutation(int n, int k) {
    int factorials[n];                            // Factorial system bases
    char *nums = malloc((n + 1) * sizeof(char));  // Numbers
    nums[n] = '\0';                               // Null terminate the string
    int i;
    factorials[0] = 1;  // Generate factorial system bases 0!, 1!, ..., (n - 1)!
    nums[0] = '1';      // Generate numbers 1, 2, ..., n
    for (i = 1; i < n; ++i) {
        factorials[i] = factorials[i - 1] * i;
        nums[i] = (i + 1) + '0';
    }
    --k;  // Fit k in the interval 0 ... (n! - 1)
    // Compute the factorial representation of k
    char *result = malloc((n + 1) * sizeof(char));
    result[n] = '\0';  // Null terminate the string
    for (int j = n - 1, i = 0; j > -1; --j, i++) {
        int idx = k / factorials[j];
        k -= idx * factorials[j];
        result[i] = nums[idx];
        // Remove the element at index idx from nums
        memmove(&nums[idx], &nums[idx + 1], j - idx);
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
    string getPermutation(int n, int k) {
        vector<int> factorials(n);  // Factorial system bases
        vector<char> nums;          // Numbers
        factorials[0] =
            1;  // Generate factorial system bases 0!, 1!, ..., (n - 1)!
        nums.push_back('1');  // Generate numbers 1, 2, ..., n
        for (int i = 1; i < n; ++i) {
            factorials[i] = factorials[i - 1] * i;
            nums.push_back(char(i + 1 + '0'));
        }
        --k;  // Fit k in the interval 0 ... (n! - 1)
        // Compute the factorial representation of k
        string result = "";
        for (int i = n - 1; i > -1; --i) {
            int idx = k / factorials[i];
            k -= idx * factorials[i];
            result += nums[idx];
            nums.erase(nums.begin() + idx);
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
    public string GetPermutation(int n, int k) {
        int[] factorials = new int[n];               // Factorial system bases
        List<char> nums = new List<char>() { '1' };  // Numbers
        factorials[0] =
            1;  // Generate factorial system bases 0!, 1!, ..., (n - 1)!
        for (int i = 1; i < n; ++i) {
            // Generate nums 1, 2, ..., n
            factorials[i] = factorials[i - 1] * i;
            nums.Add((char)(i + 1 + '0'));
        }

        // Fit k in the interval 0 ... (n! - 1)
        k--;
        // Compute the factorial representation of k
        StringBuilder result = new StringBuilder();
        for (int i = n - 1; i > -1; --i) {
            int idx = k / factorials[i];
            k -= idx * factorials[i];
            result.Append(nums[idx]);
            nums.RemoveAt(idx);
        }

        return result.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getPermutation(n int, k int) string {
    factorials := make([]int, n) // Factorial system bases
    nums := make([]string, n)    // Numbers
    // Generate factorial system bases 0!, 1!, ..., (n - 1)!
    // Generate nums 1, 2, ..., n
    factorials[0] = 1
    nums[0] = "1"
    for i := 1; i < n; i++ {
        factorials[i] = factorials[i-1] * i
        nums[i] = strconv.Itoa(i + 1)
    }
    // Fit k in the interval 0 ... (n! - 1)
    k = k - 1
    // Compute the factorial representation of k
    var output strings.Builder
    for i := n - 1; i > -1; i-- {
        idx := k / factorials[i]
        k -= idx * factorials[i]
        output.WriteString(nums[idx])
        nums = append(nums[:idx], nums[idx+1:]...)
    }
    return output.String()
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String getPermutation(int n, int k) {
        int[] factorials = new int[n];
        List<Integer> nums = new ArrayList() {
            {
                add(1);
            }
        };

        factorials[0] = 1;
        for (int i = 1; i < n; ++i) {
            // Generate factorial system bases 0!, 1!, ..., (n - 1)!
            factorials[i] = factorials[i - 1] * i;

            // Generate nums 1, 2, ..., n
            nums.add(i + 1);
        }

        // fit k in the interval 0 ... (n! - 1)
        --k;

        // Compute the factorial representation of k
        StringBuilder sb = new StringBuilder();
        for (int i = n - 1; i > -1; --i) {
            int idx = k / factorials[i];
            k -= idx * factorials[i];

            sb.append(nums.get(idx));
            nums.remove(idx);
        }
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getPermutation = function (n, k) {
    let factorials = new Array(n); // Factorial system bases
    let nums = ["1"]; // Numbers
    // Generate factorial system bases 0!, 1!, ..., (n - 1)!
    // Generate nums 1, 2, ..., n
    factorials[0] = 1;
    for (let i = 1; i < n; ++i) {
        factorials[i] = factorials[i - 1] * i;
        nums.push((i + 1).toString());
    }
    // Fit k in the interval 0 ... (n! - 1)
    --k;
    // Compute the factorial representation of k
    let output = "";
    for (let i = n - 1; i > -1; --i) {
        let idx = Math.floor(k / factorials[i]);
        k -= idx * factorials[i];
        output += nums[idx];
        nums.splice(idx, 1);
    }
    return output;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        factorials, nums = [1], ["1"]
        for i in range(1, n):
            # generate factorial system bases 0!, 1!, ..., (n - 1)!
            factorials.append(factorials[i - 1] * i)
            # generate nums 1, 2, ..., n
            nums.append(str(i + 1))

        # Fit k in the interval 0 ... (n! - 1)
        k -= 1

        # Compute the factorial representation of k
        output = []
        for i in range(n - 1, -1, -1):
            idx = k // factorials[i]
            k -= idx * factorials[i]

            output.append(nums[idx])
            del nums[idx]

        return "".join(output)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getPermutation(n: number, k: number): string {
    let factorials = new Array(n); // Factorial system bases
    let nums = ["1"]; // Numbers
    // Generate factorial system bases 0!, 1!, ..., (n - 1)!
    // Generate nums 1, 2, ..., n
    factorials[0] = 1;
    for (let i = 1; i < n; ++i) {
        factorials[i] = factorials[i - 1] * i;
        nums.push((i + 1).toString());
    }
    // fit k in the interval 0 ... (n! - 1)
    --k;
    // Compute the factorial representation of k
    let output = "";
    for (let i = n - 1; i > -1; --i) {
        let idx = Math.floor(k / factorials[i]);
        k -= idx * factorials[i];
        output += nums[idx];
        nums.splice(idx, 1);
    }
    return output;
}
```

</details>
