# 2048. Next Greater Numerically Balanced Number

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/next-greater-numerically-balanced-number/)  
`Hash Table` `Math` `Backtracking` `Counting` `Enumeration`

**Problem Link:** [LeetCode 2048 - Next Greater Numerically Balanced Number](https://leetcode.com/problems/next-greater-numerically-balanced-number/)

## Problem

An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly greater than n.

### Example 1

```text
Input: n = 1
Output: 22
Explanation:
22 is numerically balanced since:
- The digit 2 occurs 2 times.
It is also the smallest numerically balanced number strictly greater than 1.
```

### Example 2

```text
Input: n = 1000
Output: 1333
Explanation:
1333 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 1000.
Note that 1022 cannot be the answer because 0 appeared more than 0 times.
```

### Example 3

```text
Input: n = 3000
Output: 3133
Explanation:
3133 is numerically balanced since:
- The digit 1 occurs 1 time.
- The digit 3 occurs 3 times.
It is also the smallest numerically balanced number strictly greater than 3000.
```

## Constraints

- 0 <= n <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Width of Columns of a Grid](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2048. Next Greater Numerically Balanced Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration | C, C++, C#, Go, Java, JavaScript, Python3 |
| Lookup Table + Binary Search | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach 1: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int isBalance(int x) {
    int count[10] = {0};
    while (x > 0) {
        count[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0 && count[i] != i) {
            return 0;
        }
    }
    return 1;
}

int nextBeautifulNumber(int n) {
    for (int i = n + 1; i <= 1224444; i++) {
        if (isBalance(i)) {
            return i;
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
    bool isBalance(int x) {
        vector<int> count(10);
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; ++d) {
            if (count[d] > 0 && count[d] != d) {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; ++i) {
            if (isBalance(i)) {
                return i;
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
    public int NextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            if (IsBalance(i)) {
                return i;
            }
        }
        return -1;
    }

    private bool IsBalance(int x) {
        int[] count = new int[10];
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (count[i] > 0 && count[i] != i) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isBalance(x int) bool {
	count := make([]int, 10)
	for x > 0 {
		count[x%10]++
		x /= 10
	}
	for i := 0; i < 10; i++ {
		if count[i] > 0 && count[i] != i {
			return false
		}
	}
	return true
}

func nextBeautifulNumber(n int) int {
	for i := n + 1; i <= 1224444; i++ {
		if isBalance(i) {
			return i
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

    public int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; ++i) {
            if (isBalance(i)) {
                return i;
            }
        }
        return -1;
    }

    private boolean isBalance(int x) {
        int[] count = new int[10];
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; ++d) {
            if (count[d] > 0 && count[d] != d) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function isBalance(x) {
    const count = new Array(10).fill(0);
    while (x > 0) {
        count[x % 10]++;
        x = Math.floor(x / 10);
    }
    for (let d = 0; d < 10; d++) {
        if (count[d] > 0 && count[d] != d) {
            return false;
        }
    }
    return true;
}

var nextBeautifulNumber = function (n) {
    for (let i = n + 1; i <= 1224444; i++) {
        if (isBalance(i)) {
            return i;
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        for i in range(n + 1, 1224445):
            count = Counter(str(i))
            if all(count[d] == int(d) for d in count):
                return i
```

</details>

<br>

## Approach 2: Lookup Table + Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
const int balance[] = {
    1,      22,     122,    212,    221,    333,    1333,   3133,   3313,
    3331,   4444,   14444,  22333,  23233,  23323,  23332,  32233,  32323,
    32332,  33223,  33232,  33322,  41444,  44144,  44414,  44441,  55555,
    122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232,
    133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313,
    223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123,
    233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442,
    312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332,
    322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321,
    331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321,
    333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424,
    442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551,
    666666, 1224444};

int nextBeautifulNumber(int n) {
    int left = 0, right = sizeof(balance) / sizeof(balance[0]) - 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (balance[mid] <= n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return balance[left];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const vector<int> balance{
        1,      22,     122,    212,    221,    333,    1333,   3133,   3313,
        3331,   4444,   14444,  22333,  23233,  23323,  23332,  32233,  32323,
        32332,  33223,  33232,  33322,  41444,  44144,  44414,  44441,  55555,
        122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232,
        133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313,
        223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123,
        233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442,
        312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332,
        322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321,
        331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321,
        333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424,
        442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551,
        666666, 1224444};

    int nextBeautifulNumber(int n) {
        return *upper_bound(balance.begin(), balance.end(), n);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private static int[] balance = new int[] {
        1,      22,     122,    212,    221,    333,    1333,   3133,   3313,
        3331,   4444,   14444,  22333,  23233,  23323,  23332,  32233,  32323,
        32332,  33223,  33232,  33322,  41444,  44144,  44414,  44441,  55555,
        122333, 123233, 123323, 123332, 132233, 132323, 132332, 133223, 133232,
        133322, 155555, 212333, 213233, 213323, 213332, 221333, 223133, 223313,
        223331, 224444, 231233, 231323, 231332, 232133, 232313, 232331, 233123,
        233132, 233213, 233231, 233312, 233321, 242444, 244244, 244424, 244442,
        312233, 312323, 312332, 313223, 313232, 313322, 321233, 321323, 321332,
        322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312, 323321,
        331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321,
        333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424,
        442442, 444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551,
        666666, 1224444
    };

    public int NextBeautifulNumber(int n) {
        int i = Array.BinarySearch(balance, n + 1);
        if (i < 0) {
            i = -i - 1;
        }
        return balance[i];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
var balance = []int{
	1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444,
	14444, 22333, 23233, 23323, 23332, 32233, 32323, 32332,
	33223, 33232, 33322, 41444, 44144, 44414, 44441, 55555,
	122333, 123233, 123323, 123332, 132233, 132323, 132332,
	133223, 133232, 133322, 155555, 212333, 213233, 213323,
	213332, 221333, 223133, 223313, 223331, 224444, 231233,
	231323, 231332, 232133, 232313, 232331, 233123, 233132,
	233213, 233231, 233312, 233321, 242444, 244244, 244424,
	244442, 312233, 312323, 312332, 313223, 313232, 313322,
	321233, 321323, 321332, 322133, 322313, 322331, 323123,
	323132, 323213, 323231, 323312, 323321, 331223, 331232,
	331322, 332123, 332132, 332213, 332231, 332312, 332321,
	333122, 333212, 333221, 422444, 424244, 424424, 424442,
	442244, 442424, 442442, 444224, 444242, 444422, 515555,
	551555, 555155, 555515, 555551, 666666, 1224444,
}

func nextBeautifulNumber(n int) int {
	return balance[sort.SearchInts(balance, n+1)]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int[] balance = new int[] {
        1,
        22,
        122,
        212,
        221,
        333,
        1333,
        3133,
        3313,
        3331,
        4444,
        14444,
        22333,
        23233,
        23323,
        23332,
        32233,
        32323,
        32332,
        33223,
        33232,
        33322,
        41444,
        44144,
        44414,
        44441,
        55555,
        122333,
        123233,
        123323,
        123332,
        132233,
        132323,
        132332,
        133223,
        133232,
        133322,
        155555,
        212333,
        213233,
        213323,
        213332,
        221333,
        223133,
        223313,
        223331,
        224444,
        231233,
        231323,
        231332,
        232133,
        232313,
        232331,
        233123,
        233132,
        233213,
        233231,
        233312,
        233321,
        242444,
        244244,
        244424,
        244442,
        312233,
        312323,
        312332,
        313223,
        313232,
        313322,
        321233,
        321323,
        321332,
        322133,
        322313,
        322331,
        323123,
        323132,
        323213,
        323231,
        323312,
        323321,
        331223,
        331232,
        331322,
        332123,
        332132,
        332213,
        332231,
        332312,
        332321,
        333122,
        333212,
        333221,
        422444,
        424244,
        424424,
        424442,
        442244,
        442424,
        442442,
        444224,
        444242,
        444422,
        515555,
        551555,
        555155,
        555515,
        555551,
        666666,
        1224444,
    };

    public int nextBeautifulNumber(int n) {
        int i = Arrays.binarySearch(balance, n + 1);
        if (i < 0) {
            i = -i - 1;
        }
        return balance[i];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const balance = [
    1, 22, 122, 212, 221, 333, 1333, 3133, 3313, 3331, 4444, 14444, 22333,
    23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 33322, 41444, 44144,
    44414, 44441, 55555, 122333, 123233, 123323, 123332, 132233, 132323, 132332,
    133223, 133232, 133322, 155555, 212333, 213233, 213323, 213332, 221333,
    223133, 223313, 223331, 224444, 231233, 231323, 231332, 232133, 232313,
    232331, 233123, 233132, 233213, 233231, 233312, 233321, 242444, 244244,
    244424, 244442, 312233, 312323, 312332, 313223, 313232, 313322, 321233,
    321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213, 323231,
    323312, 323321, 331223, 331232, 331322, 332123, 332132, 332213, 332231,
    332312, 332321, 333122, 333212, 333221, 422444, 424244, 424424, 424442,
    442244, 442424, 442442, 444224, 444242, 444422, 515555, 551555, 555155,
    555515, 555551, 666666, 1224444,
];

var nextBeautifulNumber = function (n) {
    let left = 0,
        right = balance.length - 1;
    while (left < right) {
        let mid = (left + right) >> 1;
        if (balance[mid] <= n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return balance[left];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
balance = [
    1,
    22,
    122,
    212,
    221,
    333,
    1333,
    3133,
    3313,
    3331,
    4444,
    14444,
    22333,
    23233,
    23323,
    23332,
    32233,
    32323,
    32332,
    33223,
    33232,
    33322,
    41444,
    44144,
    44414,
    44441,
    55555,
    122333,
    123233,
    123323,
    123332,
    132233,
    132323,
    132332,
    133223,
    133232,
    133322,
    155555,
    212333,
    213233,
    213323,
    213332,
    221333,
    223133,
    223313,
    223331,
    224444,
    231233,
    231323,
    231332,
    232133,
    232313,
    232331,
    233123,
    233132,
    233213,
    233231,
    233312,
    233321,
    242444,
    244244,
    244424,
    244442,
    312233,
    312323,
    312332,
    313223,
    313232,
    313322,
    321233,
    321323,
    321332,
    322133,
    322313,
    322331,
    323123,
    323132,
    323213,
    323231,
    323312,
    323321,
    331223,
    331232,
    331322,
    332123,
    332132,
    332213,
    332231,
    332312,
    332321,
    333122,
    333212,
    333221,
    422444,
    424244,
    424424,
    424442,
    442244,
    442424,
    442442,
    444224,
    444242,
    444422,
    515555,
    551555,
    555155,
    555515,
    555551,
    666666,
    1224444,
]


class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        return balance[bisect_right(balance, n)]
```

</details>
