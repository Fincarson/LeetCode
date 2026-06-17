# 319. Bulb Switcher

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/bulb-switcher/)  
`Math` `Brainteaser`

**Problem Link:** [LeetCode 319 - Bulb Switcher](https://leetcode.com/problems/bulb-switcher/)

## Problem

There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

### Example 1

```text
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off].
So you should return 1 because there is only one bulb is on.
```

### Example 2

```text
Input: n = 0
Output: 0
```

### Example 3

```text
Input: n = 1
Output: 1
```

## Constraints

- 0 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bulb Switcher II](https://leetcode.com/problems/bulb-switcher-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Times Binary String Is Prefix-Aligned](https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Pivot Integer](https://leetcode.com/problems/find-the-pivot-integer/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 319. Bulb Switcher

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Math | C, C++, Java, JavaScript, Python3, TypeScript |

## Approach 1: Math

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int bulbSwitch(int n){
    return sqrt(n);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int bulbSwitch(int n) {
        return (int) Math.sqrt(n);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var bulbSwitch = function(n) {
    return Math.floor(Math.sqrt(n));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(sqrt(n))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function bulbSwitch(n: number): number {
    return Math.floor(Math.sqrt(n));
};
```

</details>
