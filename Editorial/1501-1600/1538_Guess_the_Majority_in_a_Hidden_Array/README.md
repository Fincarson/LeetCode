# 1538. Guess the Majority in a Hidden Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/guess-the-majority-in-a-hidden-array/)  
`Array` `Math` `Interactive`

**Problem Link:** [LeetCode 1538 - Guess the Majority in a Hidden Array](https://leetcode.com/problems/guess-the-majority-in-a-hidden-array/)

## Problem

We have an integer array nums, where all the integers in nums are 0 or 1. You will not be given direct access to the array, instead, you will have an API ArrayReader which have the following functions:

- int query(int a, int b, int c, int d): where 0 <= a < b < c < d < ArrayReader.length(). The function returns the distribution of the value of the 4 elements and returns:

		4 : if the values of the 4 elements are the same (0 or 1).
		2 : if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
		0 : if two element have a value equal to 0 and two elements have a value equal to 1.
- int length(): Returns the size of the array.

You are allowed to call query() 2 * n times at most where n is equal to ArrayReader.length().

Return any index of the most frequent value in nums, in case of tie, return -1.

### Example 1

```text
Input: nums = [0,0,1,0,1,1,1,1]
Output: 5
Explanation: The following calls to the API
reader.length() // returns 8 because there are 8 elements in the hidden array.
reader.query(0,1,2,3) // returns 2 this is a query that compares the elements nums[0], nums[1], nums[2], nums[3]
// Three elements have a value equal to 0 and one element has value equal to 1 or viceversa.
reader.query(4,5,6,7) // returns 4 because nums[4], nums[5], nums[6], nums[7] have the same value.
we can infer that the most frequent value is found in the last 4 elements.
Index 2, 4, 6, 7 is also a correct answer.
```

### Example 2

```text
Input: nums = [0,0,1,1,0]
Output: 0
```

### Example 3

```text
Input: nums = [1,0,1,0,1,0,1,0]
Output: -1
```

## Constraints

- 5 <= nums.length <= 105
- 0 <= nums[i] <= 1

Follow up: What is the minimum number of calls needed to find the majority element?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1538. Guess the Majority in a Hidden Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C++, Java, Python3 |

## Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int cntEqual = 1, cntDiffer = 0, indexDiffer = -1;

public:
    int guessMajority(ArrayReader& reader) {
        int n = reader.length(), query0123 = reader.query(0, 1, 2, 3),
            query1234 = reader.query(1, 2, 3, 4);
        function<void(bool, int)> f = [this](bool equal, int i) {
            if (equal) {
                cntEqual++;
            } else {
                cntDiffer++;
                indexDiffer = i;
            }
        };

        f(query1234 == query0123, 4);
        for (int i = 5; i < n; i++) {
            f(reader.query(1, 2, 3, i) == query0123, i);
        }
        f(reader.query(0, 2, 3, 4) == query1234, 1);
        f(reader.query(0, 1, 3, 4) == query1234, 2);
        f(reader.query(0, 1, 2, 4) == query1234, 3);
        return cntEqual > cntDiffer ? 0 : cntDiffer > cntEqual ? indexDiffer : -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int cntEqual = 1, cntDiffer = 0, indexDiffer = -1;

    private void f(boolean equal, int i) {
        if (equal) {
            cntEqual++;
        } else {
            cntDiffer++;
            indexDiffer = i;
        }
    }

    public int guessMajority(ArrayReader reader) {
        int n = reader.length(), query0123 = reader.query(0, 1, 2, 3), query1234 = reader.query(1, 2, 3, 4);
        f(query1234 == query0123, 4);
        for (int i = 5; i < n; i++) {
            f(reader.query(1, 2, 3, i) == query0123, i);
        }
        f(reader.query(0, 2, 3, 4) == query1234, 1);
        f(reader.query(0, 1, 3, 4) == query1234, 2);
        f(reader.query(0, 1, 2, 4) == query1234, 3);
        return cntEqual > cntDiffer ? 0 : cntDiffer > cntEqual ? indexDiffer : -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def guessMajority(self, reader: 'ArrayReader') -> int:
        n = reader.length()
        cnt_equal = 1
        cnt_differ = 0
        index_differ = -1

        def f(equal, i):
            nonlocal cnt_equal, cnt_differ, index_differ
            if equal:
                cnt_equal += 1
            else:
                cnt_differ += 1
                index_differ = i

        query0123 = reader.query(0, 1, 2, 3)
        query1234 = reader.query(1, 2, 3, 4)
        f(reader.query(1, 2, 3, 4) == query0123, 4)
        for i in range(5, n):
            f(reader.query(1, 2, 3, i) == query0123, i)
        f(reader.query(0, 2, 3, 4) == query1234, 1)
        f(reader.query(0, 1, 3, 4) == query1234, 2)
        f(reader.query(0, 1, 2, 4) == query1234, 3)
        return (0 if cnt_equal > cnt_differ else index_differ
                if cnt_differ > cnt_equal else -1)
```

</details>
