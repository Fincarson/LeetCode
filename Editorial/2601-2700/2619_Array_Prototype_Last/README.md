# 2619. Array Prototype Last

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/array-prototype-last/)  

**Problem Link:** [LeetCode 2619 - Array Prototype Last](https://leetcode.com/problems/array-prototype-last/)

## Problem

Write code that enhances all arrays such that you can call the array.last() method on any array and it will return the last element. If there are no elements in the array, it should return -1.

You may assume the array is the output of JSON.parse.

### Example 1

```text
Input: nums = [null, {}, 3]
Output: 3
Explanation: Calling nums.last() should return the last element: 3.
```

### Example 2

```text
Input: nums = []
Output: -1
Explanation: Because there are no elements, return -1.
```

## Constraints

- arr is a valid JSON array
- 0 <= arr.length <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Snail Traversal](https://leetcode.com/problems/snail-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Array Upper Bound](https://leetcode.com/problems/array-upper-bound/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2619. Array Prototype Last

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Extending Array Prototype to Include a `.last()` Method | JavaScript, TypeScript |
| Using ES6 Getters | JavaScript, TypeScript |

## Approach 1:  Extending Array Prototype to Include a `.last()` Method

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.last = function() {
  if (this.length === 0) {
    return -1;
  }

  return this[this.length - 1];
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function(): number { 
    if (this.length === 0) {
        return -1;
    }

    return this[this.length - 1];
}
```

</details>

<br>

## Approach 2: Using ES6 Getters

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Object.defineProperty(Array.prototype, 'last', {
  get: function() {
    return () => this.length ? this[this.length - 1] : -1;
  }
});
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Array<T> {
        last(): T | -1;
    }
}
Object.defineProperty(Array.prototype, 'last', {
    get: function() {
        return () => this.length ? this[this.length - 1] : -1;
    },
} as PropertyDescriptor);
```

</details>
