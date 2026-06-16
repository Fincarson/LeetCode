# 2648. Generate Fibonacci Sequence

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/generate-fibonacci-sequence/)  

**Problem Link:** [LeetCode 2648 - Generate Fibonacci Sequence](https://leetcode.com/problems/generate-fibonacci-sequence/)

## Problem

Write a generator function that returns a generator object which yields the fibonacci sequence.

The fibonacci sequence is defined by the relation Xn = Xn-1 + Xn-2.

The first few numbers of the series are 0, 1, 1, 2, 3, 5, 8, 13.

### Example 1

```text
Input: callCount = 5
Output: [0,1,1,2,3]
Explanation:
const gen = fibGenerator();
gen.next().value; // 0
gen.next().value; // 1
gen.next().value; // 1
gen.next().value; // 2
gen.next().value; // 3
```

### Example 2

```text
Input: callCount = 0
Output: []
Explanation: gen.next() is never called so nothing is outputted
```

## Constraints

- 0 <= callCount <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Nested Array Generator](https://leetcode.com/problems/nested-array-generator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design Cancellable Function](https://leetcode.com/problems/design-cancellable-function/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2648. Generate Fibonacci Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Generator Function for Fibonacci Sequence | JavaScript, TypeScript |
| Recursive Generator Function for Fibonacci Sequence | JavaScript, TypeScript |
| Precomputed Array and Custom Iterator | JavaScript, TypeScript |

## Approach 1: Iterative Generator Function for Fibonacci Sequence

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var fibGenerator = function*() {
    let prev1 = 0;
    let prev2 = 1;

    while(true) {
        yield prev1;
        const temp = prev1;
        prev1 = prev2;
        prev2 += temp;
    }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* fibGenerator(): Generator<number> {
    let prev1 = 0;
    let prev2 = 1;

    while(true) {
        yield prev1;
        const temp = prev1;
        prev1 = prev2;
        prev2 += temp;
    }
};
```

</details>

<br>

## Approach 2: Recursive Generator Function for Fibonacci Sequence

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var fibGenerator = function*(a = 0, b=1) {
    // yield the first number
    yield a;

    // recursively call fibGenerator and yield the entire generator function
    yield* fibGenerator(b, a+b);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* fibGenerator(a = 0, b = 1): Generator<number> {
    yield a;
    yield* fibGenerator(b, a+b);
};
```

</details>

<br>

## Approach 3: Precomputed Array and Custom Iterator

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var fibGenerator = function() {
    // Determine the number of Fibonacci numbers to generate
    const lengthOfSequence = 50;

    const fibonacciSequence = Array(lengthOfSequence).fill(0);

    fibonacciSequence[1] = 1;

    for (let i = 2; i < fibonacciSequence.length; i++) {
        fibonacciSequence[i] = fibonacciSequence[i - 1] + fibonacciSequence[i - 2];
    }

    // Return an iterator for the array
    return fibonacciSequence[Symbol.iterator]();
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const fibGenerator = (): Iterator<number> => {
    // Determine the number of Fibonacci numbers to generate
    const lengthOfSequence: number = 50;

    const fibonacciSequence: number[] = Array(lengthOfSequence).fill(0);

    fibonacciSequence[1] = 1;

    for (let i = 2; i < fibonacciSequence.length; i++) {
        fibonacciSequence[i] = fibonacciSequence[i - 1] + fibonacciSequence[i - 2];
    }

    // Return an iterator for the array
    return fibonacciSequence[Symbol.iterator]();
};
```

</details>
