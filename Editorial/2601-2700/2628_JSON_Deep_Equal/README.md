# 2628. JSON Deep Equal

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/json-deep-equal/)  

**Problem Link:** [LeetCode 2628 - JSON Deep Equal](https://leetcode.com/problems/json-deep-equal/)

## Problem

Given two values o1 and o2, return a boolean value indicating whether two values, o1 and o2, are deeply equal.

For two values to be deeply equal, the following conditions must be met:

- If both values are primitive types, they are deeply equal if they pass the === equality check.
- If both values are arrays, they are deeply equal if they have the same elements in the same order, and each element is also deeply equal according to these conditions.
- If both values are objects, they are deeply equal if they have the same keys, and the associated values for each key are also deeply equal according to these conditions.

You may assume both values are the output of JSON.parse. In other words, they are valid JSON.

Please solve it without using lodash's _.isEqual() function

### Example 1

```text
Input: o1 = {"x":1,"y":2}, o2 = {"x":1,"y":2}
Output: true
Explanation: The keys and values match exactly.
```

### Example 2

```text
Input: o1 = {"y":2,"x":1}, o2 = {"x":1,"y":2}
Output: true
Explanation: Although the keys are in a different order, they still match exactly.
```

### Example 3

```text
Input: o1 = {"x":null,"L":[1,2,3]}, o2 = {"x":null,"L":["1","2","3"]}
Output: false
Explanation: The array of numbers is different from the array of strings.
```

### Example 4

```text
Input: o1 = true, o2 = false
Output: false
Explanation: true !== false
```

## Constraints

- 1 <= JSON.stringify(o1).length <= 105
- 1 <= JSON.stringify(o2).length <= 105
- maxNestingDepth <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Convert Object to JSON String](https://leetcode.com/problems/convert-object-to-json-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Flatten Deeply Nested Array](https://leetcode.com/problems/flatten-deeply-nested-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Array of Objects to Matrix](https://leetcode.com/problems/array-of-objects-to-matrix/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Differences Between Two Objects](https://leetcode.com/problems/differences-between-two-objects/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2628. JSON Deep Equal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Comparative Recursion: | JavaScript, TypeScript |
| Iterative Solution: | JavaScript, TypeScript |
| Using JSON.stringify and Sorting: | JavaScript, TypeScript |

## Approach 1: Comparative Recursion:

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    if (o1 === o2) return true;
    if (o1 === null || o2 === null) return false;
    if (String(o1) !== String(o2)) return false;

    if (typeof o1 !== 'object') {
        return o1 === o2;
    }

    if (Array.isArray(o1)) {
        if (o1.length !== o2.length) return false;

        for (let i = 0; i < o1.length; i++) {
            if (!areDeeplyEqual(o1[i], o2[i])) return false;
        }

        return true;
    }

    if (Object.keys(o1).length !== Object.keys(o2).length) return false;

    for (const key in o1) {
        if (!areDeeplyEqual(o1[key], o2[key])) return false;
    }

    return true;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function areDeeplyEqual(o1: any, o2: any): boolean {
    if (o1 === o2) return true;
    if (o1 === null || o2 === null) return false;
    if (String(o1) !== String(o2)) return false;

    if (typeof o1 !== 'object') {
        return o1 === o2;
    }

    if (Array.isArray(o1)) {
        if (o1.length !== o2.length) return false;

        for (let i = 0; i < o1.length; i++) {
            if (!areDeeplyEqual(o1[i], o2[i])) return false;
        }

        return true;
    }

    if (Object.keys(o1).length !== Object.keys(o2).length) return false;

    for (const key in o1) {
        if (!areDeeplyEqual(o1[key], o2[key])) return false;
    }

    return true;
}
```

</details>

<br>

## Approach 2: Iterative Solution:

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
function areDeeplyEqual(o1, o2) {
  if (o1 === o2) return true;
  if (o1 === null || o2 === null) return false;
  
  var objs = [[o1, o2]];
  
  while (objs.length) {
    [o1, o2] = objs.pop();

    if (o1 === o2) continue;
    if (typeof o1 !== 'object' || typeof o2 !== 'object') return false;
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;

    const keys1 = Object.keys(o1);
    const keys2 = Object.keys(o2);

    if (keys1.length !== keys2.length) return false;
    for (const key of keys1) {
      if (!(key in o2)) return false;
      objs.push([o1[key], o2[key]]);
    }
  }

  return true;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function areDeeplyEqual(o1: any, o2: any): boolean {
  if (o1 === o2) return true;
  if (o1 === null || o2 === null) return false;

  const objs: [any, any][] = [[o1, o2]];
  
  while (objs.length) {
    [o1, o2] = objs.pop()!;

    if (o1 === o2) continue;
    if (typeof o1 !== 'object' || typeof o2 !== 'object') return false;
    if (Array.isArray(o1) !== Array.isArray(o2)) return false;

    const keys1 = Object.keys(o1);
    const keys2 = Object.keys(o2);

    if (keys1.length !== keys2.length) return false;
    for (const key of keys1) {
      if (!(key in o2)) return false;
      objs.push([o1[key], o2[key]]);
    }
  }

  return true;
}
```

</details>

<br>

## Approach 3: Using JSON.stringify and Sorting:

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
function helper(key, value) {
    if (value && typeof value === "object" && !Array.isArray(value))
        return Object.fromEntries(Object.entries(value).sort());
    else
        return value;
}

var areDeeplyEqual = function(o1, o2) {
    const stringifiedO1 = JSON.stringify(o1, helper);
    const stringifiedO2 = JSON.stringify(o2, helper);

    return stringifiedO1 === stringifiedO2;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function helper(key: string, value: any): any {
  if (value && typeof value === "object" && !Array.isArray(value)) 
    return Object.fromEntries(Object.entries(value).sort());
   else
    return value;
}

function areDeeplyEqual(o1: any, o2: any): boolean {
  const stringifiedO1 = JSON.stringify(o1, helper);
  const stringifiedO2 = JSON.stringify(o2, helper);

  return stringifiedO1 === stringifiedO2;
}
```

</details>
