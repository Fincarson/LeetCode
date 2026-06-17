# 2775. Undefined to Null

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/undefined-to-null/)  

**Problem Link:** [LeetCode 2775 - Undefined to Null](https://leetcode.com/problems/undefined-to-null/)

## Problem

Given a deeply nested object or array obj, return the object obj with any undefined values replaced by null.

undefined values are handled differently than null values when objects are converted to a JSON string using JSON.stringify(). This function helps ensure serialized data is free of unexpected errors.

### Example 1

```text
Input: obj = {"a": undefined, "b": 3}
Output: {"a": null, "b": 3}
Explanation: The value for obj.a has been changed from undefined to null
```

### Example 2

```text
Input: obj = {"a": undefined, "b": ["a", undefined]}
Output: {"a": null,"b": ["a", null]}
Explanation: The values for obj.a and obj.b[1] have been changed from undefined to null
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

# Editorial - 2775. Undefined to Null

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Approach | JavaScript, TypeScript |
| Recursive Approach | JavaScript, TypeScript |

## Approach 1: Iterative Approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {object} obj
 * @return {object}
 */
var undefinedToNull = function(obj) {
    const stack = [obj];

    while (stack.length > 0) {
        const current = stack.pop();

        if (Array.isArray(current)) {
            for (let i = 0; i < current.length; i++) {
                if (current[i] === undefined) {
                    current[i] = null;
                } else if (typeof current[i] === 'object') {
                    stack.push(current[i]);
                }
            }
        } else if (typeof current === 'object' && current !== null) {
            for (const key in current) {
                if (current[key] === undefined) {
                    current[key] = null;
                } else if (typeof current[key] === 'object') {
                    stack.push(current[key]);
                }
            }
        }
    }

    return obj;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Value = undefined | null | boolean | number | string | Value[] | { [key: string]: Value };

type Obj1 = Record<string, Value> | Value[];
type Obj2 = Record<string, JSONValue> | JSONValue[];

function undefinedToNull(obj: Obj1): Obj2 {
    const stack: Value[] = [obj];

    while (stack.length > 0) {
        const current = stack.pop();

        if (Array.isArray(current)) {
            for (let i = 0; i < current.length; i++) {
                if (current[i] === undefined) {
                    current[i] = null;
                } else if (typeof current[i] === 'object' && current[i] !== null) {
                    stack.push(current[i] as Value);
                }
            }
        } else if (typeof current === 'object' && current !== null) {
            for (const key in current) {
                if (current[key] === undefined) {
                    current[key] = null;
                } else if (typeof current[key] === 'object' && current[key] !== null) {
                    stack.push(current[key] as Value);
                }
            }
        }
    }

    return obj as Obj2;
}
```

</details>

<br>

## Approach 2: Recursive Approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var undefinedToNull = function(obj) {
    if (typeof obj !== 'object' || obj === null) {
        return obj !== undefined ? obj : null;
    }

    if (Array.isArray(obj)) {
        return obj.map(item => undefinedToNull(item));
    }
    
    const newObj = {};
    
    for (const key in obj) {
        newObj[key] = undefinedToNull(obj[key]);
    }

    return newObj;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Value = undefined | null | boolean | number | string | Value[] | { [key: string]: Value };

type Obj1 = Record<string, Value> | Value[];
type Obj2 = Record<string, JSONValue> | JSONValue[];

function undefinedToNull(obj: Obj1): Obj2 {
    if (typeof obj !== 'object' || obj === null) {
        return obj !== undefined ? obj : null;
    }

    if (Array.isArray(obj)) {
        return obj.map(item => undefinedToNull(item as Value[]));
    }

    const newObj: Record<string, JSONValue> = {};

    for (const key in obj) {
        newObj[key] = undefinedToNull(obj[key] as Value[]) ;
    }

    return newObj;
}
```

</details>
