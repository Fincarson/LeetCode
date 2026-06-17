# 2631. Group By

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/group-by/)  

**Problem Link:** [LeetCode 2631 - Group By](https://leetcode.com/problems/group-by/)

## Problem

Write code that enhances all arrays such that you can call the array.groupBy(fn) method on any array and it will return a grouped version of the array.

A grouped array is an object where each key is the output of fn(arr[i]) and each value is an array containing all items in the original array which generate that key.

The provided callback fn will accept an item in the array and return a string key.

The order of each value list should be the order the items appear in the array. Any order of keys is acceptable.

Please solve it without lodash's _.groupBy function.

### Example 1

```text
Input:
array = [
  {"id":"1"},
  {"id":"1"},
  {"id":"2"}
],
fn = function (item) {
  return item.id;
}
Output:
{
  "1": [{"id": "1"}, {"id": "1"}],
  "2": [{"id": "2"}]
}
Explanation:
Output is from array.groupBy(fn).
The selector function gets the "id" out of each item in the array.
There are two objects with an "id" of 1. Both of those objects are put in the first array.
There is one object with an "id" of 2. That object is put in the second array.
```

### Example 2

```text
Input:
array = [
  [1, 2, 3],
  [1, 3, 5],
  [1, 5, 9]
]
fn = function (list) {
  return String(list[0]);
}
Output:
{
  "1": [[1, 2, 3], [1, 3, 5], [1, 5, 9]]
}
Explanation:
The array can be of any type. In this case, the selector function defines the key as being the first element in the array.
All the arrays have 1 as their first element so they are grouped together.
{
  "1": [[1, 2, 3], [1, 3, 5], [1, 5, 9]]
}
```

### Example 3

```text
Input:
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
fn = function (n) {
  return String(n > 5);
}
Output:
{
  "true": [6, 7, 8, 9, 10],
  "false": [1, 2, 3, 4, 5]
}
Explanation:
The selector function splits the array by whether each number is greater than 5.
```

## Constraints

- 0 <= array.length <= 105
- fn returns a string

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Filter Elements from Array](https://leetcode.com/problems/filter-elements-from-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Apply Transform Over Each Element in Array](https://leetcode.com/problems/apply-transform-over-each-element-in-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Snail Traversal](https://leetcode.com/problems/snail-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Array Reduce Transformation](https://leetcode.com/problems/array-reduce-transformation/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Array Upper Bound](https://leetcode.com/problems/array-upper-bound/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2631. Group By

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| For Loop | JavaScript, TypeScript |
| Reduce | JavaScript, TypeScript |

## Approach 1: For Loop

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.groupBy = function(fn) {
  const returnObject = {};
  for (const item of this) {
    const key = fn(item);
    if (key in returnObject) {
      returnObject[key].push(item);
    } else {
      returnObject[key] = [item];
    }
  }
  return returnObject;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function<T>(fn: (item: T) => string) {
  const returnObject: Record<string, T[]> = {};
  for (const item of this) {
    const key = fn(item);
    if (key in returnObject) {
      returnObject[key].push(item);
    } else {
      returnObject[key] = [item];
    }
  }
  return returnObject;
};
```

</details>

<br>

## Approach 2: Reduce

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.groupBy = function(fn) {
  return this.reduce((accum, item) => {
    const key = fn(item);
    accum[key] ||= [];
    accum[key].push(item);
    return accum;
  }, {});
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function<T>(fn: (item: T) => string) {
  return this.reduce((accum, item) => {
    const key = fn(item);
    accum[key] ||= [];
    accum[key].push(item);
    return accum;
  }, {} as Record<string, T[]>);
};
```

</details>
