# 2634. Filter Elements from Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/filter-elements-from-array/)  

**Problem Link:** [LeetCode 2634 - Filter Elements from Array](https://leetcode.com/problems/filter-elements-from-array/)

## Problem

Given an integer array arr and a filtering function fn, return a filtered array filteredArr.

The fn function takes one or two arguments:

- arr[i] - number from the arr
- i - index of arr[i]

filteredArr should only contain the elements from the arr for which the expression fn(arr[i], i) evaluates to a truthy value. A truthy value is a value where Boolean(value) returns true.

Please solve it without the built-in Array.filter method.

### Example 1

```text
Input: arr = [0,10,20,30], fn = function greaterThan10(n) { return n > 10; }
Output: [20,30]
Explanation:
const newArray = filter(arr, fn); // [20, 30]
The function filters out values that are not greater than 10
```

### Example 2

```text
Input: arr = [1,2,3], fn = function firstIndex(n, i) { return i === 0; }
Output: [1]
Explanation:
fn can also accept the index of each element
In this case, the function removes elements not at index 0
```

### Example 3

```text
Input: arr = [-2,-1,0,1,2], fn = function plusOne(n) { return n + 1 }
Output: [-2,0,1,2]
Explanation:
Falsey values such as 0 should be filtered out
```

## Constraints

- 0 <= arr.length <= 1000
- -109 <= arr[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Group By](https://leetcode.com/problems/group-by/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Apply Transform Over Each Element in Array](https://leetcode.com/problems/apply-transform-over-each-element-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Array Reduce Transformation](https://leetcode.com/problems/array-reduce-transformation/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2634. Filter Elements from Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Push Values onto New Array | JavaScript, TypeScript |
| For...in Loop | JavaScript, TypeScript |
| Preallocate Memory | JavaScript, TypeScript |
| Perform Operations In-Place | JavaScript, TypeScript |
| Standard Library | JavaScript, TypeScript |

## Approach 1: Push Values onto New Array

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var filter = function(arr, fn) {
    const newArr = [];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const newArr: number[] = [];
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            newArr.push(arr[i]);
        }
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
var filter = function(arr, fn) {
    const newArr = [];
    for (const stringIndex in arr) {
        const i = Number(stringIndex);
        if (fn(arr[i], i)) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const newArr: number[] = [];
    for (const stringIndex in arr) {
        const i = Number(stringIndex);
        if (fn(arr[i], i)) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
};
```

</details>

<br>

## Approach 3: Preallocate Memory

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var filter = function(arr, fn) {
    let size = 0;
    const newArr = new Array(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            newArr[size] = arr[i];
            size++;
        }
    }
    // Ensure new array is of length size
    while (newArr.length > size) {
        newArr.pop();
    }
    return newArr
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let size = 0;
    const newArr: number[] = new Array(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            newArr[size] = arr[i];
            size++;
        }
    }
    // Ensure new array is of length size
    while (newArr.length > size) {
        newArr.pop();
    }
    return newArr
};
```

</details>

<br>

## Approach 4: Perform Operations In-Place

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var filter = function(arr, fn) {
    let size = 0;
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            arr[size] = arr[i];
            size++;
        }
    }
    // Ensure array is of length size
    while (arr.length > size) {
        arr.pop();
    }
    return arr
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let size = 0;
    for (let i = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            arr[size] = arr[i];
            size++;
        }
    }
    // Ensure array is of length size
    while (arr.length > size) {
        arr.pop();
    }
    return arr
};
```

</details>

<br>

## Approach 5: Standard Library

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var filter = function(arr, fn) {
    return arr.filter(fn);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    return arr.filter(fn);
};
```

</details>
