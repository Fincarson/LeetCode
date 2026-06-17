# 2803. Factorial Generator

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/factorial-generator/)  

**Problem Link:** [LeetCode 2803 - Factorial Generator](https://leetcode.com/problems/factorial-generator/)

## Problem

Write a generator function that takes an integer n as an argument and returns a generator object which yields the factorial sequence.

The factorial sequence is defined by the relation n! = n * (n-1) * (n-2) * ... * 2 * 1Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹.

The factorial of 0 is defined as 1.

### Example 1

```text
Input: n = 5
Output: [1,2,6,24,120]
Explanation:
const gen = factorial(5)
gen.next().value // 1
gen.next().value // 2
gen.next().value // 6
gen.next().value // 24
gen.next().value // 120
```

### Example 2

```text
Input: n = 2
Output: [1,2]
Explanation:
const gen = factorial(2)
gen.next().value // 1
gen.next().value // 2
```

### Example 3

```text
Input: n = 0
Output: [1]
Explanation:
const gen = factorial(0)
gen.next().value // 1
```

## Constraints

- 0 <= n <= 18

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2803. Factorial Generator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Approach | JavaScript, TypeScript |
| Recursive approach | JavaScript, TypeScript |
| Memoization | JavaScript, TypeScript |

## Approach 1: Iterative Approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function* factorial(n) {
    if (n === 0) {
        yield 1;
    }
    let fact = 1;
    for (let i = 1; i <= n; i++) {
        fact *= i;
        yield fact;
    }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* factorial(n) {
    if (n === 0) {
        yield 1;
    }
    let fact = 1;
    for (let i = 1; i <= n; i++) {
        fact *= i;
        yield fact;
    }
}
```

</details>

<br>

## Approach 2: Recursive approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function* factorial(n) {
    function factorialRecursive(n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorialRecursive(n - 1);
    }
    
    if (n === 0) {
        yield 1;
    } else {
        for (let i = 1; i <= n; i++) {
            yield factorialRecursive(i);
        }
    }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* factorial(n: number): Generator<number> {
    function factorialRecursive(n: number): number {
        if (n <= 1) {
            return 1;
        }
        return n * factorialRecursive(n - 1);
    }

    if (n === 0) {
        yield 1;
    } else {
        for (let i = 1; i <= n; i++) {
            yield factorialRecursive(i);
        }
    }
}
```

</details>

<br>

## Approach 3: Memoization

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function* factorial(n) {
    const memo = new Map(); //memo Map
    
    //Recursive function used for generating factorials
    function factorialRecursive(n) {
        if (memo.has(n)) {
            return memo.get(n);
        }

        let result;
        if (n <= 1) {
            result = 1;
        } else {
            result = n * factorialRecursive(n - 1);
        }

        memo.set(n, result);
        return result;
    }
    
    if (n === 0) {
        yield 1;
    } else {
        for (let i = 1; i <= n; i++) {
            yield factorialRecursive(i);
        }
    }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* factorial(n: number): Generator<number> {
    const memo = new Map<number, number>(); //memo Map

    //Recursive function used for generating factorials
    function factorialRecursive(n: number): number {
        if (memo.has(n)) {
            return memo.get(n) as number;
        }

        let result: number;
        if (n <= 1) {
            result = 1;
        } else {
            result = n * factorialRecursive(n - 1);
        }

        memo.set(n, result);
        return result;
    }
    
    if (n === 0) {
        yield 1;
    } else {
        for (let i = 1; i <= n; i++) {
            yield factorialRecursive(i);
        }
    }
}
```

</details>
