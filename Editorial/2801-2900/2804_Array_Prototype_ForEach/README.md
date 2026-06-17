# 2804. Array Prototype ForEach

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/array-prototype-foreach/)  

**Problem Link:** [LeetCode 2804 - Array Prototype ForEach](https://leetcode.com/problems/array-prototype-foreach/)

## Problem

Write your version of method forEach that enhances all arrays such that you can call the array.forEach(callback, context) method on any array and it will execute callback on each element of the array. Method forEach should not return anything.

callback accepts the following arguments:

- currentValue - represents the current element being processed in the array. It is the value of the element in the current iteration.
- index - represents the index of the current element being processed in the array.
- array - represents the array itself, allowing access to the entire array within the callback function.

The context is the object that should be passed as the function context parameter to the callback function, ensuring that the this keyword within the callback function refers to this context object.

Try to implement it without using the built-in array methods.

### Example 1

```text
Input:
arr = [1,2,3],
callback = (val, i, arr) => arr[i] = val * 2,
context = {"context":true}
Output: [2,4,6]
Explanation:
arr.forEach(callback, context)
console.log(arr) // [2,4,6]

The callback is executed on each element of the array.
```

### Example 2

```text
Input:
arr = [true, true, false, false],
callback = (val, i, arr) => arr[i] = this,
context = {"context": false}
Output: [{"context":false},{"context":false},{"context":false},{"context":false}]
Explanation:
arr.forEach(callback, context)
console.log(arr) // [{"context":false},{"context":false},{"context":false},{"context":false}]

The callback is executed on each element of the array with the right context.
```

### Example 3

```text
Input:
arr = [true, true, false, false],
callback = (val, i, arr) => arr[i] = !val,
context = {"context": 5}
Output: [false,false,true,true]
```

## Constraints

- arr is a valid JSON array
- context is a valid JSON object
- fn is a function
- 0 <= arr.length <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2804. Array Prototype ForEach

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using call | JavaScript, TypeScript |
| Recursive approach | JavaScript, TypeScript |

## Approach 1: Using call

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.forEach = function(callback, context) {
    for (let i = 0; i < this.length; i++) {
        callback.call(context, this[i], i, this)
    }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
Array.prototype.forEach = function(callback: Function, context: any): void {
    for (let i = 0; i < this.length; i++) {
        callback.call(context, this[i], i, this);
    }
};
```

</details>

<br>

## Approach 2: Recursive approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.forEach = function(callback, context) {
    //To maintain a reference to the original array when inside the inner function
    const self = this;
    function forEachRecursive(index) {
        if (index === self.length) {
            return;
        }
        callback.call(context, self[index], index, self);
        forEachRecursive(index + 1);
    }

    forEachRecursive(0);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
Array.prototype.forEach = function(callback: Function, context: any): void {
    //To maintain a reference to the original array when inside the inner function
    const self = this;
    function forEachRecursive(index: number): void {
        if (index === self.length) {
            return;
        }
        callback.call(context, self[index], index, self);
        forEachRecursive(index + 1);
    }

    forEachRecursive(0);
};
```

</details>
