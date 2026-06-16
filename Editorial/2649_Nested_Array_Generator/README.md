# 2649. Nested Array Generator

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/nested-array-generator/)  

**Problem Link:** [LeetCode 2649 - Nested Array Generator](https://leetcode.com/problems/nested-array-generator/)

## Problem

Given a multi-dimensional array of integers, return a generator object which yields integers in the same order as inorder traversal.

A multi-dimensional array is a recursive data structure that contains both integers and other multi-dimensional arrays.

inorder traversal iterates over each array from left to right, yielding any integers it encounters or applying inorder traversal to any arrays it encounters.

### Example 1

```text
Input: arr = [[[6]],[1,3],[]]
Output: [6,1,3]
Explanation:
const generator = inorderTraversal(arr);
generator.next().value; // 6
generator.next().value; // 1
generator.next().value; // 3
generator.next().done; // true
```

### Example 2

```text
Input: arr = []
Output: []
Explanation: There are no integers so the generator doesn't yield anything.
```

## Constraints

- 0 <= arr.flat().length <= 105
- 0 <= arr.flat()[i] <= 105
- maxNestingDepth <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Flatten Deeply Nested Array](https://leetcode.com/problems/flatten-deeply-nested-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Generate Fibonacci Sequence](https://leetcode.com/problems/generate-fibonacci-sequence/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Design Cancellable Function](https://leetcode.com/problems/design-cancellable-function/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2649. Nested Array Generator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Solution | JavaScript, TypeScript |
| Iterative Solution Using Stack | JavaScript, TypeScript |
| Using Flat Method | JavaScript, TypeScript |

## Approach 1: Recursive Solution

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* (arr) {
    if (!Array.isArray(arr)) {
        yield arr
        return
    }

    for (let i = 0; i < arr.length; i++) {
        yield* inorderTraversal(arr[i])
    }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
  if (!Array.isArray(arr)) {
    yield arr;
    return;
  }

  for (let i = 0; i < arr.length; i++) {
    yield* inorderTraversal(arr[i] as MultidimensionalArray);
  }
}
```

</details>

<br>

## Approach 2: Iterative Solution Using Stack

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var inorderTraversal = function* (arr) {
  const stack = [arr];
  
  while (stack.length > 0) {
    const current = stack.pop();

    if (!Array.isArray(current)) {
      yield current;
      continue;
    }

    for (let i = current.length - 1; i >= 0; i--) {
      stack.push(current[i]);
    }
  }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
  const stack: MultidimensionalArray[] = [arr];

  while (stack.length > 0) {
    const current = stack.pop();

    if (!Array.isArray(current)) {
      yield current;
      continue;
    }

    for (let i = current.length - 1; i >= 0; i--) {
      stack.push(current[i] as MultidimensionalArray);
    }
  }
}
```

</details>

<br>

## Approach 3: Using Flat Method

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
  yield* arr.flat(Infinity);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type MultidimensionalArray = (MultidimensionalArray | number)[];

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
  yield* (arr.flat(Infinity) as unknown as Generator<number, void, unknown>);
}
```

</details>
