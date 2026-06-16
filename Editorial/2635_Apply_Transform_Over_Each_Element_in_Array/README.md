# 2635. Apply Transform Over Each Element in Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/apply-transform-over-each-element-in-array/)  

**Problem Link:** [LeetCode 2635 - Apply Transform Over Each Element in Array](https://leetcode.com/problems/apply-transform-over-each-element-in-array/)

## Problem

Given an integer array arr and a mapping function fn, return a new array with a transformation applied to each element.

The returned array should be created such that returnedArray[i] = fn(arr[i], i).

Please solve it without the built-in Array.map method.

### Example 1

```text
Input: arr = [1,2,3], fn = function plusone(n) { return n + 1; }
Output: [2,3,4]
Explanation:
const newArray = map(arr, plusone); // [2,3,4]
The function increases each value in the array by one.
```

### Example 2

```text
Input: arr = [1,2,3], fn = function plusI(n, i) { return n + i; }
Output: [1,3,5]
Explanation: The function increases each value by the index it resides in.
```

### Example 3

```text
Input: arr = [10,20,30], fn = function constant() { return 42; }
Output: [42,42,42]
Explanation: The function always returns 42.
```

## Constraints

- 0 <= arr.length <= 1000
- -109 <= arr[i] <= 109
- fn returns an integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Group By](https://leetcode.com/problems/group-by/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Filter Elements from Array](https://leetcode.com/problems/filter-elements-from-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Array Reduce Transformation](https://leetcode.com/problems/array-reduce-transformation/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2635. Apply Transform Over Each Element in Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Write Values onto Initially Empty Array | JavaScript, TypeScript |
| For...in Loop | JavaScript, TypeScript |
| Push Values onto Array | JavaScript, TypeScript |
| Preallocate Memory | JavaScript, TypeScript |
| 32 Bit Integer Array | JavaScript, TypeScript |
| In-Memory Transformation | JavaScript, TypeScript |

## Approach 1: Write Values onto Initially Empty Array

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var map = function(arr, fn) {
    const newArr = [];
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const newArr: number[] = [];
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};
```

</details>

<br>

## Approach 2: For...in Loop

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var map = function(arr, fn) {
    const newArr = new Array(arr.length);
    for (const i in arr) {
        newArr[i] = fn(arr[i], Number(i));
    }
    return newArr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const newArr: number[] = new Array(arr.length);
    for (const i in arr) {
        newArr[i] = fn(arr[i], Number(i));
    }
    return newArr;
};
```

</details>

<br>

## Approach 3: Push Values onto Array

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var map = function(arr, fn) {
    const newArr = [];
    for (let i = 0; i < arr.length; ++i) {
        newArr.push(fn(arr[i], i));
    }
    return newArr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const newArr: number[] = [];
    for (let i = 0; i < arr.length; ++i) {
        newArr.push(fn(arr[i], i));
    }
    return newArr;
};
```

</details>

<br>

## Approach 4: Preallocate Memory

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var map = function(arr, fn) {
    const newArr = new Array(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const newArr = new Array<number>(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};
```

</details>

<br>

## Approach 5: 32 Bit Integer Array

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var map = function(arr, fn) {
    const newArr = new Int32Array(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const newArr = new Int32Array(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr as unknown as number[];
};
```

</details>

<br>

## Approach 6: In-Memory Transformation

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var map = function(arr, fn) {
    for (let i = 0; i < arr.length; ++i) {
        arr[i] = fn(arr[i], i);
    }
    return arr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    for (let i = 0; i < arr.length; ++i) {
        arr[i] = fn(arr[i], i);
    }
    return arr;
};
```

</details>
