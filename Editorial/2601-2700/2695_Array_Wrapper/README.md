# 2695. Array Wrapper

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/array-wrapper/)  

**Problem Link:** [LeetCode 2695 - Array Wrapper](https://leetcode.com/problems/array-wrapper/)

## Problem

Create a class ArrayWrapper that accepts an array of integers in its constructor. This class should have two features:

- When two instances of this class are added together with the + operator, the resulting value is the sum of all the elements in both arrays.
- When the String() function is called on the instance, it will return a comma separated string surrounded by brackets. For example, [1,2,3].

### Example 1

```text
Input: nums = [[1,2],[3,4]], operation = "Add"
Output: 10
Explanation:
const obj1 = new ArrayWrapper([1,2]);
const obj2 = new ArrayWrapper([3,4]);
obj1 + obj2; // 10
```

### Example 2

```text
Input: nums = [[23,98,42,70]], operation = "String"
Output: "[23,98,42,70]"
Explanation:
const obj = new ArrayWrapper([23,98,42,70]);
String(obj); // "[23,98,42,70]"
```

### Example 3

```text
Input: nums = [[],[]], operation = "Add"
Output: 0
Explanation:
const obj1 = new ArrayWrapper([]);
const obj2 = new ArrayWrapper([]);
obj1 + obj2; // 0
```

## Constraints

- 0 <= nums.length <= 1000
- 0 <= nums[i] <= 1000
- Note: nums is the array passed to the constructor

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2695. Array Wrapper

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Implementing valueOf and toString methods in ArrayWrapper class | JavaScript, TypeScript |

## Approach 1:  Implementing valueOf and toString methods in ArrayWrapper class

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

var ArrayWrapper = function(nums) {
    this.nums = nums;
};

ArrayWrapper.prototype.valueOf = function() {
    return this.nums.reduce((a, b) => a + b, 0);
}

ArrayWrapper.prototype.toString = function() {
    return "[" + this.nums.join(',') + "]";
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
interface ArrayWrapper {
    nums: number[];
    valueOf: () => number;
    toString: () => string;
}

function ArrayWrapper(this: ArrayWrapper, nums: number[]) {
    this.nums = nums;
}

ArrayWrapper.prototype.valueOf = function(this: ArrayWrapper): number {
    return this.nums.reduce((a, b) => a + b, 0);
}

ArrayWrapper.prototype.toString = function(this: ArrayWrapper): string {
    return "[" + this.nums.join(',') + "]";
}
```

</details>
