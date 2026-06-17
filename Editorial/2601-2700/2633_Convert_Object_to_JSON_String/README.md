# 2633. Convert Object to JSON String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/convert-object-to-json-string/)  

**Problem Link:** [LeetCode 2633 - Convert Object to JSON String](https://leetcode.com/problems/convert-object-to-json-string/)

## Problem

Given a value, return a valid JSON string of that value. The value can be a string, number, array, object, boolean, or null. The returned string should not include extra spaces. The order of keys should be the same as the order returned by Object.keys().

Please solve it without using the built-in JSON.stringify method.

### Example 1

```text
Input: object = {"y":1,"x":2}
Output: {"y":1,"x":2}
Explanation:
Return the JSON representation.
Note that the order of keys should be the same as the order returned by Object.keys().
```

### Example 2

```text
Input: object = {"a":"str","b":-12,"c":true,"d":null}
Output: {"a":"str","b":-12,"c":true,"d":null}
Explanation:
The primitives of JSON are strings, numbers, booleans, and null.
```

### Example 3

```text
Input: object = {"key":{"a":1,"b":[{},null,"Hello"]}}
Output: {"key":{"a":1,"b":[{},null,"Hello"]}}
Explanation:
Objects and arrays can include other objects and arrays.
```

### Example 4

```text
Input: object = true
Output: true
Explanation:
Primitive types are valid inputs.
```

## Constraints

- value is a valid JSON value
- 1 <= JSON.stringify(object).length <= 105
- maxNestingLevel <= 1000
- all strings contain only alphanumeric characters

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [JSON Deep Equal](https://leetcode.com/problems/json-deep-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Flatten Deeply Nested Array](https://leetcode.com/problems/flatten-deeply-nested-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Array of Objects to Matrix](https://leetcode.com/problems/array-of-objects-to-matrix/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Differences Between Two Objects](https://leetcode.com/problems/differences-between-two-objects/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2633. Convert Object to JSON String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using JSON-like String Concatenation | JavaScript, TypeScript |
| Using Switch Case | JavaScript, TypeScript |
| Using Ternary Operator | JavaScript, TypeScript |

## Approach 1: Using JSON-like String Concatenation

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
  if (object === null) {
    return 'null';
  }

  if (Array.isArray(object)) {
    const elements = object.map((element) => jsonStringify(element));
    return `[${elements.join(',')}]`;
  }

  if (typeof object === 'object') {
    const keys = Object.keys(object);
    const keyValuePairs = keys.map((key) => `"${key}":${jsonStringify(object[key])}`);
    return `{${keyValuePairs.join(',')}}`;
  }

  if (typeof object === 'string') {
    return `"${object}"`;
  }

  return String(object);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jsonStringify(object: any): string {
  if (object === null) {
    return 'null';
  }

  if (Array.isArray(object)) {
    const elements = object.map((element: any) => jsonStringify(element));
    return `[${elements.join(',')}]`;
  }

  if (typeof object === 'object') {
    const keys = Object.keys(object);
    const keyValuePairs = keys.map((key: string) => `"${key}":${jsonStringify(object[key])}`);
    return `{${keyValuePairs.join(',')}}`;
  }

  if (typeof object === 'string') {
    return `"${object}"`;
  }

  return String(object);
}
```

</details>

<br>

## Approach 2: Using Switch Case

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
  switch (typeof object) {
    case 'object':
      if (Array.isArray(object)) {
        const elements = object.map((element) => jsonStringify(element));
        return `[${elements.join(',')}]`;
      } else if (object) {
        const keys = Object.keys(object);
        const keyValuePairs = keys.map((key) => `"${key}":${jsonStringify(object[key])}`);
        return `{${keyValuePairs.join(',')}}`;
      } else {
        return 'null';
      }
    case 'boolean':
    case 'number':
      return `${object}`;
    case 'string':
      return `"${object}"`;
    default:
      return '';
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jsonStringify(object) {
  switch (typeof object) {
    case 'object':
      if (Array.isArray(object)) {
        const elements = object.map((element) => jsonStringify(element));
        return `[${elements.join(',')}]`;
      } else if (object) {
        const keys = Object.keys(object);
        const keyValuePairs = keys.map((key) => `"${key}":${jsonStringify(object[key])}`);
        return `{${keyValuePairs.join(',')}}`;
      } else {
        return 'null';
      }
    case 'boolean':
    case 'number':
      return `${object}`;
    case 'string':
      return `"${object}"`;
    default:
      return '';
  }
}
```

</details>

<br>

## Approach 3: Using Ternary Operator

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    return typeof object === 'string' ? '"' + object + '"' :
        object === null || typeof object !== 'object' ? object :
        Array.isArray(object) ? '[' + object.reduce((acc, x) => acc + jsonStringify(x) + ',', '').slice(0, -1) + ']' :
        '{' + Object.entries(object).reduce((acc, x) => acc + jsonStringify(x[0]) + ':' + jsonStringify(x[1]) + ',', '').slice(0, -1) + '}';
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jsonStringify(object) {
    return typeof object === 'string' ? '"' + object + '"' :
        object === null || typeof object !== 'object' ? object :
        Array.isArray(object) ? '[' + object.reduce((acc, x) => acc + jsonStringify(x) + ',', '').slice(0, -1) + ']' :
        '{' + Object.entries(object).reduce((acc, x) => acc + jsonStringify(x[0]) + ':' + jsonStringify(x[1]) + ',', '').slice(0, -1) + '}';
};
```

</details>
