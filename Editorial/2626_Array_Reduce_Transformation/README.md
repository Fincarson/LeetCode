# 2626. Array Reduce Transformation

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/array-reduce-transformation/)  

**Problem Link:** [LeetCode 2626 - Array Reduce Transformation](https://leetcode.com/problems/array-reduce-transformation/)

## Problem

Given an integer array nums, a reducer function fn, and an initial value init, return the final result obtained by executing the fn function on each element of the array, sequentially, passing in the return value from the calculation on the preceding element.

This result is achieved through the following operations: val = fn(init, nums[0]), val = fn(val, nums[1]), val = fn(val, nums[2]), ... until every element in the array has been processed. The ultimate value of val is then returned.

If the length of the array is 0, the function should return init.

Please solve it without using the built-in Array.reduce method.

### Example 1

```text
Input:
nums = [1,2,3,4]
fn = function sum(accum, curr) { return accum + curr; }
init = 0
Output: 10
Explanation:
initially, the value is init=0.
(0) + nums[0] = 1
(1) + nums[1] = 3
(3) + nums[2] = 6
(6) + nums[3] = 10
The final answer is 10.
```

### Example 2

```text
Input:
nums = [1,2,3,4]
fn = function sum(accum, curr) { return accum + curr * curr; }
init = 100
Output: 130
Explanation:
initially, the value is init=100.
(100) + nums[0] * nums[0] = 101
(101) + nums[1] * nums[1] = 105
(105) + nums[2] * nums[2] = 114
(114) + nums[3] * nums[3] = 130
The final answer is 130.
```

### Example 3

```text
Input:
nums = []
fn = function sum(accum, curr) { return 0; }
init = 25
Output: 25
Explanation: For empty arrays, the answer is always init.
```

## Constraints

- 0 <= nums.length <= 1000
- 0 <= nums[i] <= 1000
- 0 <= init <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Group By](https://leetcode.com/problems/group-by/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Filter Elements from Array](https://leetcode.com/problems/filter-elements-from-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Apply Transform Over Each Element in Array](https://leetcode.com/problems/apply-transform-over-each-element-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2626. Array Reduce Transformation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| For...of Loop | JavaScript, TypeScript |
| Array.forEach Loop | JavaScript, TypeScript |
| For...in Loop | JavaScript, TypeScript |

## Approach 1: For...of Loop

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reduce = function(arr, fn, initialVal) {
  let accumulator = initialVal;
  for (const element of arr) {
      accumulator = fn(accumulator, element);
  }
  return accumulator;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (accum: number, curr: number) => number

function reduce(arr: number[], fn: Fn, initialVal: number): number {
  let accumulator = initialVal;
  for (const element of arr) {
      accumulator = fn(accumulator, element);
  }
  return accumulator;
};
```

</details>

<br>

## Approach 2: Array.forEach Loop

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reduce = function(arr, fn, initialVal) {
  let accumulator = initialVal;
  arr.forEach((element) => {
    accumulator = fn(accumulator, element);
  });
  return accumulator;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (accum: number, curr: number) => number

function reduce(arr: number[], fn: Fn, initialVal: number): number {
  let accumulator = initialVal;
  arr.forEach((element) => {
    accumulator = fn(accumulator, element);
  });
  return accumulator;
};
```

</details>

<br>

## Approach 3: For...in Loop

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reduce = function(arr, fn, initialVal) {
  let accumulator = initialVal;
  for (const index in arr) {
    accumulator = fn(accumulator, arr[index]);
  } 
  return accumulator;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (accum: number, curr: number) => number

function reduce(arr: number[], fn: Fn, initialVal: number): number {
  let accumulator = initialVal;
  for (const index in arr) {
    accumulator = fn(accumulator, arr[index]);
  } 
  return accumulator;
};
```

</details>
