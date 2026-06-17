# 2629. Function Composition

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/function-composition/)  

**Problem Link:** [LeetCode 2629 - Function Composition](https://leetcode.com/problems/function-composition/)

## Problem

Given an array of functions [f1, f2, f3, ..., fn], return a new function fn that is the function composition of the array of functions.

The function composition of [f(x), g(x), h(x)] is fn(x) = f(g(h(x))).

The function composition of an empty list of functions is the identity function f(x) = x.

You may assume each function in the array accepts one integer as input and returns one integer as output.

### Example 1

```text
Input: functions = [x => x + 1, x => x * x, x => 2 * x], x = 4
Output: 65
Explanation:
Evaluating from right to left ...
Starting with x = 4.
2 * (4) = 8
(8) * (8) = 64
(64) + 1 = 65
```

### Example 2

```text
Input: functions = [x => 10 * x, x => 10 * x, x => 10 * x], x = 1
Output: 1000
Explanation:
Evaluating from right to left ...
10 * (1) = 10
10 * (10) = 100
10 * (100) = 1000
```

### Example 3

```text
Input: functions = [], x = 42
Output: 42
Explanation:
The composition of zero functions is the identity function
```

## Constraints

- -1000 <= x <= 1000
- 0 <= functions.length <= 1000
- all functions accept and return a single integer

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Memoize](https://leetcode.com/problems/memoize/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Counter](https://leetcode.com/problems/counter/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2629. Function Composition

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Function Composition using Iteration | JavaScript, TypeScript |
| Function Composition using Array.reduceRight() | TypeScript |

## Approach 1: Function Composition using Iteration

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var compose = function (functions) {
  return function (x) {
    if (functions.length === 0) return x;
    let input = x;

    for (let i = functions.length - 1; i >= 0; i--) {
      const currFunc = functions[i];

      input = currFunc(input);
    }

    return input;
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type F = (x: number) => number;

function compose(functions: F[]): F {
    return function(x: number): number {
        if (functions.length === 0) return x;
        let input = x;

        for (let i = functions.length - 1; i >= 0; i--) {
            const currFunc = functions[i];

            input = currFunc(input);
        }

        return input;
    };
};
```

</details>

<br>

## Approach 2:  Function Composition using Array.reduceRight()

### Implementation

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type F = (x: number) => number;

function compose(functions: F[]): F {
    return (x: number) => functions.reduceRight((acc, f) => f(acc), x);
}
;
```

</details>
