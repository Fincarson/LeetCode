# 2727. Is Object Empty

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/is-object-empty/)  

**Problem Link:** [LeetCode 2727 - Is Object Empty](https://leetcode.com/problems/is-object-empty/)

## Problem

Given an object or an array, return if it is empty.

- An empty object contains no key-value pairs.
- An empty array contains no elements.

You may assume the object or array is the output of JSON.parse.

### Example 1

```text
Input: obj = {"x": 5, "y": 42}
Output: false
Explanation: The object has 2 key-value pairs so it is not empty.
```

### Example 2

```text
Input: obj = {}
Output: true
Explanation: The object doesn't have any key-value pairs so it is empty.
```

### Example 3

```text
Input: obj = [null, false, 0]
Output: false
Explanation: The array has 3 elements so it is not empty.
```

## Constraints

- obj is a valid JSON object or array
- 2 <= JSON.stringify(obj).length <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2727. Is Object Empty

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using JSON.stringify | JavaScript, TypeScript |
| Using Object.keys | JavaScript, TypeScript |
| Using loop | JavaScript, TypeScript |

## Approach 1: Using JSON.stringify

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isEmpty = function(obj) {
    if (JSON.stringify(obj).length <= 2) return true
    else return false
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isEmpty(obj: Record<string, any> | any[]): boolean {
  if (JSON.stringify(obj).length <= 2) {
    return true;
  } else {
    return false;
  }
}
```

</details>

<br>

## Approach 2: Using Object.keys

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isEmpty = function(obj) {
  return Object.keys(obj).length === 0
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isEmpty(obj: Record<string, any> | any[]): boolean {
  return Object.keys(obj).length === 0;
}
```

</details>

<br>

## Approach 3: Using loop

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isEmpty = function(obj) {
    for (const _ in obj) return false;
    return true;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isEmpty(obj: Record<string, any> | any[]): boolean {
  for (const _ in obj) {
    return false;
  }
  return true;
}
```

</details>
