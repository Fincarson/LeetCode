# 202. Happy Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/happy-number/)  
`Hash Table` `Math` `Two Pointers`

**Problem Link:** [LeetCode 202 - Happy Number](https://leetcode.com/problems/happy-number/)

## Problem

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
- Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

### Example 1

```text
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

### Example 2

```text
Input: n = 2
Output: false
```

## Constraints

- 1 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Digits](https://leetcode.com/problems/add-digits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Ugly Number](https://leetcode.com/problems/ugly-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Addition to Make Integer Beautiful](https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Value After Replacing With Sum of Prime Factors](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count the Digits That Divide a Number](https://leetcode.com/problems/count-the-digits-that-divide-a-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 202. Happy Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Detect Cycles with a HashSet | C++, Java, Python3 |
| Floyd's Cycle-Finding Algorithm | C++, Java, Python3 |
| Hardcoding the Only Cycle (Advanced) | C++, Java, Python3 |

## Approach 1: Detect Cycles with a HashSet

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            totalSum += digit * digit;
        }
        return totalSum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    public boolean isHappy(int n) {
        Set<Integer> seen = new HashSet<>();
        while (n != 1 && !seen.contains(n)) {
            seen.add(n);
            n = getNext(n);
        }
        return n == 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isHappy(self, n: int) -> bool:

        def get_next(n):
            total_sum = 0
            while n > 0:
                n, digit = divmod(n, 10)
                total_sum += digit**2
            return total_sum

        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = get_next(n)

        return n == 1
```

</details>

<br>

## Approach 2: Floyd's Cycle-Finding Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    bool isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);
        while (fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        return fastRunner == 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    public boolean isHappy(int n) {
        int slowRunner = n;
        int fastRunner = getNext(n);
        while (fastRunner != 1 && slowRunner != fastRunner) {
            slowRunner = getNext(slowRunner);
            fastRunner = getNext(getNext(fastRunner));
        }
        return fastRunner == 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isHappy(self, n: int) -> bool:
        def get_next(number):
            total_sum = 0
            while number > 0:
                number, digit = divmod(number, 10)
                total_sum += digit**2
            return total_sum

        slow_runner = n
        fast_runner = get_next(n)
        while fast_runner != 1 and slow_runner != fast_runner:
            slow_runner = get_next(slow_runner)
            fast_runner = get_next(get_next(fast_runner))
        return fast_runner == 1
```

</details>

<br>

## Approach 3: Hardcoding the Only Cycle (Advanced)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle_members = {4, 16, 37, 58, 89, 145, 42, 20};

        while (n != 1 && cycle_members.find(n) == cycle_members.end()) {
            n = getNext(n);
        }

        return n == 1;
    }

private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static Set<Integer> cycleMembers = new HashSet<>(
        Arrays.asList(4, 16, 37, 58, 89, 145, 42, 20)
    );

    public int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    public boolean isHappy(int n) {
        while (n != 1 && !cycleMembers.contains(n)) {
            n = getNext(n);
        }
        return n == 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isHappy(self, n: int) -> bool:

        cycle_members = {4, 16, 37, 58, 89, 145, 42, 20}

        def get_next(number):
            total_sum = 0
            while number > 0:
                number, digit = divmod(number, 10)
                total_sum += digit**2
            return total_sum

        while n != 1 and n not in cycle_members:
            n = get_next(n)

        return n == 1
```

</details>
