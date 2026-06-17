# 470. Implement Rand10() Using Rand7()

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/implement-rand10-using-rand7/)  
`Math` `Rejection Sampling` `Randomized` `Probability and Statistics`

**Problem Link:** [LeetCode 470 - Implement Rand10() Using Rand7()](https://leetcode.com/problems/implement-rand10-using-rand7/)

## Problem

Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.

Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument passed to rand10().

### Example 1

```text
Input: n = 1
Output: [2]
```

### Example 2

```text
Input: n = 2
Output: [2,8]
```

### Example 3

```text
Input: n = 3
Output: [3,8,10]
```

## Constraints

- 1 <= n <= 105

Follow up:

- What is the expected value for the number of calls to rand7() function?
- Could you minimize the number of calls to rand7()?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 470. Implement Rand10() Using Rand7()

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Rejection Sampling | C++, Java |
| Utilizing out-of-range samples | C++, Java |

## Approach 1: Rejection Sampling

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution extends SolBase {
    public int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
}
```

</details>

<br>

## Approach 2: Utilizing out-of-range samples

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40)
                return 1 + (idx - 1) % 10;
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60)
                return 1 + (idx - 1) % 10;
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20)
                return 1 + (idx - 1) % 10;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution extends SolBase {
    public int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40)
                return 1 + (idx - 1) % 10;
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60)
                return 1 + (idx - 1) % 10;
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20)
                return 1 + (idx - 1) % 10;
        }
    }
}
```

</details>
