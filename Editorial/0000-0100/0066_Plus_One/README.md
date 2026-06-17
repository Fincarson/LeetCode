# 66. Plus One

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/plus-one/)  
`Array` `Math`

**Problem Link:** [LeetCode 66 - Plus One](https://leetcode.com/problems/plus-one/)

## Problem

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

### Example 1

```text
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```

### Example 2

```text
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```

### Example 3

```text
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

## Constraints

- 1 <= digits.length <= 100
- 0 <= digits[i] <= 9
- digits does not contain any leading 0's.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Add Binary](https://leetcode.com/problems/add-binary/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Plus One Linked List](https://leetcode.com/problems/plus-one-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Operations to Reduce an Integer to 0](https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 66. Plus One

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Schoolbook Addition with Carry | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Schoolbook Addition with Carry

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int idx = digitsSize - 1; idx >= 0; --idx) {
        if (digits[idx] == 9)
            digits[idx] = 0;
        else {
            digits[idx]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    digits = realloc(digits, (digitsSize + 1) * sizeof(int));
    digits[0] = 1;
    for (int i = 1; i < digitsSize + 1; ++i) digits[i] = 0;
    *returnSize = digitsSize + 1;
    return digits;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // Move along the input array startin tightly from the end
        for (int i = n - 1; i >= 0; --i) {
            // Set all the nines at the end of the array to zeros
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            // Here we have the rightmost not-nine
            else {
                // Increase this rightmost not-nine by 1
                digits[i]++;
                // and the job is done
                return digits;
            }
        }
        // We're here because all the digits are nines
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] PlusOne(int[] digits) {
        int n = digits.Length;
        // Move along the input array starting from the end
        for (int idx = n - 1; idx >= 0; --idx) {
            // Set all the nines at the end of the array to zeros
            if (digits[idx] == 9) {
                digits[idx] = 0;
            }
            // Here we have the rightmost not-nine
            else {
                // Increase this rightmost not-nine by 1
                digits[idx]++;
                // and the job is done
                return digits;
            }
        }

        // We're here because all the digits are nines
        int[] newDigits = new int[n + 1];
        newDigits[0] = 1;
        return newDigits;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func plusOne(digits []int) []int {
    n := len(digits)
    // move along the input array starting from the end
    for i := n - 1; i >= 0; i-- {
        // set all the nines at the end of array to zeros
        if digits[i] == 9 {
            digits[i] = 0
        } else {
            // here we have the rightmost not-nine
            // increase this rightmost not-nine by 1
            digits[i]++
            // and the job is done
            return digits
        }
    }
    // We're here because all the digits are nines
    digits = append([]int{1}, digits...)
    return digits
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        //Move along the input array starting from the end
        for (int idx = n - 1; idx >= 0; --idx) {
            //Set all the nines at the end of the array to zeros
            if (digits[idx] == 9) {
                digits[idx] = 0;
            }
            //Here we have the rightmost not-nine
            else {
                // Increase this rightmost not-nine by 1
                digits[idx]++;

                // and the job is done
                return digits;
            }
        }

        // We're here because all the digits are nines
        digits = new int[n + 1];
        digits[0] = 1;
        return digits;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var plusOne = function (digits) {
    let n = digits.length;
    //move along the input array starting from the end
    for (let i = n - 1; i >= 0; --i) {
        //set all the nines at the end of array to zeros
        if (digits[i] == 9) {
            digits[i] = 0;
        }
        //here we have the rightmost not-nine
        else {
            //Increase this rightmost not-nine by 1
            digits[i]++;
            //and the job is done
            return digits;
        }
    }
    //We're here because all the digits are nines
    digits.unshift(1);
    return digits;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)

        # move along the input array starting from the end
        for i in range(n):
            idx = n - 1 - i

            # Set all the nines at the end of the array to zeros
            if digits[idx] == 9:
                digits[idx] = 0

            # Here we have the rightmost not-nine
            else:
                # Increase this rightmost not-nine by 1
                digits[idx] += 1

                # and the job is done
                return digits

        # We're here because all the digits are nines
        return [1] + digits
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function plusOne(digits: number[]): number[] {
    let n = digits.length;
    //Move along the input array starting from the end
    for (let idx = n - 1; idx >= 0; --idx) {
        //Set all the nines at the end of the array to zeros
        if (digits[idx] == 9) {
            digits[idx] = 0;
        }
        //Here we have the rightmost not-nine
        else {
            //Increase this rightmost not-nine by 1
            digits[idx]++;
            //and the job is done
            return digits;
        }
    }
    //We're here because all the digits are nines
    digits.unshift(1);
    return digits;
}
```

</details>
