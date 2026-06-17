# 2794. Create Object from Two Arrays

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/create-object-from-two-arrays/)  

**Problem Link:** [LeetCode 2794 - Create Object from Two Arrays](https://leetcode.com/problems/create-object-from-two-arrays/)

## Problem

Given two arrays keysArr and valuesArr, return a new object obj. Each key-value pair in obj should come from keysArr[i] and valuesArr[i].

If a duplicate key exists at a previous index, that key-value should be excluded. In other words, only the first key should be added to the object.

If the key is not a string, it should be converted into a string by calling String() on it.

### Example 1

```text
Input: keysArr = ["a", "b", "c"], valuesArr = [1, 2, 3]
Output: {"a": 1, "b": 2, "c": 3}
Explanation: The keys "a", "b", and "c" are paired with the values 1, 2, and 3 respectively.
```

### Example 2

```text
Input: keysArr = ["1", 1, false], valuesArr = [4, 5, 6]
Output: {"1": 4, "false": 6}
Explanation: First, all the elements in keysArr are converted into strings. We can see there are two occurrences of "1". The value associated with the first occurrence of "1" is used: 4.
```

### Example 3

```text
Input: keysArr = [], valuesArr = []
Output: {}
Explanation: There are no keys so an empty object is returned.
```

## Constraints

- keysArr and valuesArr are valid JSON arrays
- 2 <= JSON.stringify(keysArr).length, JSON.stringify(valuesArr).length <= 5 * 105
- keysArr.length === valuesArr.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2794. Create Object from Two Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using loop | JavaScript, TypeScript |
| Using built-in method hasOwnProperty() | JavaScript, TypeScript |

## Approach 1: Using loop

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} keysArr
 * @param {Array} valuesArr
 * @return {Object}
 */
var createObject = function(keysArr, valuesArr) {
    const obj = {};
    keysArr.forEach((key, index) => {
        if (!(key in obj)) {
            obj[key] = valuesArr[index];
        }
    });
    return obj;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function createObject(keysArr: (string | number | boolean)[], valuesArr: any[]): Record<string, any> {
    const obj: Record<string, any> = {};

    keysArr.forEach((key, index) => {
        // Convert non-string keys to strings
        if (typeof key !== 'string') {
            key = String(key);
        }

        if(!(key in obj)) {
            obj[key] = valuesArr[index];
        }
    });

    return obj;
}
```

</details>

<br>

## Approach 2: Using built-in method hasOwnProperty()

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} keysArr
 * @param {Array} valuesArr
 * @return {Object}
 */
var createObject = function(keysArr, valuesArr) {
    const obj = {};
    for (const i in keysArr) {
        if (!obj.hasOwnProperty(keysArr[i])) {
            obj[keysArr[i]] = valuesArr[i];
        }
    }
    return obj;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function createObject(keysArr: string[], valuesArr: any[]): Record<string, any> {
    const obj: Record<string, any> = {};
    for (const i in keysArr) {
        if (!obj.hasOwnProperty(keysArr[i])) {
            obj[keysArr[i]] = valuesArr[i];
        }
    }
    return obj;
}
```

</details>
