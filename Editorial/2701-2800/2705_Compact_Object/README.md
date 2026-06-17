# 2705. Compact Object

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/compact-object/)  

**Problem Link:** [LeetCode 2705 - Compact Object](https://leetcode.com/problems/compact-object/)

## Problem

Given an object or array obj, return a compact object.

A compact object is the same as the original object, except with keys containing falsy values removed. This operation applies to the object and any nested objects. Arrays are considered objects where the indices are keys. A value is considered falsy when Boolean(value) returns false.

You may assume the obj is the output of JSON.parse. In other words, it is valid JSON.

### Example 1

```text
Input: obj = [null, 0, false, 1]
Output: [1]
Explanation: All falsy values have been removed from the array.
```

### Example 2

```text
Input: obj = {"a": null, "b": [false, 1]}
Output: {"b": [1]}
Explanation: obj["a"] and obj["b"][0] had falsy values and were removed.
```

### Example 3

```text
Input: obj = [null, 0, 5, [0], [false, 16]]
Output: [5, [], [16]]
Explanation: obj[0], obj[1], obj[3][0], and obj[4][0] were falsy and removed.
```

## Constraints

- obj is a valid JSON object
- 2 <= JSON.stringify(obj).length <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2705. Compact Object

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Depth-First Search (DFS) | JavaScript, TypeScript |
| Iterative Depth-First Search | JavaScript, TypeScript |

## Approach 1: Recursive Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var compactObject = function(obj) {
  function dfs(obj) {
      if (!obj) return false;
      if (typeof obj !== 'object') return obj;

      if (Array.isArray(obj)) {
          const newArr = [];
          for(let i = 0; i < obj.length; i++) {
              const curr = obj[i];
              const subRes = dfs(curr);

              if(subRes) {
                  newArr.push(subRes);
              }
          }

          return newArr;
      }

      const newObj = {};

      for (const key in obj) {
          const subRes = dfs(obj[key])
          if (subRes) {
              newObj[key] = subRes;
          }
      }

      return newObj;
  }  

  return dfs(obj);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
  function dfs(obj: any): any {
    if (!obj) return false;
    if (typeof obj !== 'object') return obj;

    if (Array.isArray(obj)) {
      const newArr: any[] = [];
      for (let i = 0; i < obj.length; i++) {
        const curr = obj[i];
        const subRes = dfs(curr);

        if (subRes) {
          newArr.push(subRes);
        }
      }

      return newArr;
    }

    const newObj: Obj = {};

    for (const key in obj) {
      const subRes = dfs(obj[key]);
      if (subRes) {
        newObj[key] = subRes;
      }
    }

    return newObj;
  }

  return dfs(obj);
};
```

</details>

<br>

## Approach 2: Iterative Depth-First Search

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function compactObject(obj) {
    const stack = [[obj, Array.isArray(obj) ? [] : {}]];
    let newObj = stack[0][1];

    while (stack.length > 0) {
        const [currObj, newCurrObj] = stack.pop();

        for (const key in currObj) {
            const val = currObj[key];

            if (!val) continue;
            
            if (typeof val !== 'object') {
                Array.isArray(newCurrObj) ? newCurrObj.push(val) : newCurrObj[key] = val;
                continue;
            }

            const newSubObj = Array.isArray(val) ? [] : {};
            Array.isArray(newCurrObj) ? newCurrObj.push(newSubObj) : newCurrObj[key] = newSubObj;
            stack.push([val, newSubObj]);
        }
    }

    return newObj;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Obj = Record<string, any> | any[];

function compactObject(obj: Obj): Obj {
  const stack: [Obj, Obj][] = [[obj, Array.isArray(obj) ? [] : {}]];
  let newObj: Obj = stack[0][1];

  while (stack.length > 0) {
    const [currObj, newCurrObj] = stack.pop()!;

    for (const key in currObj) {
      const val = currObj[key];

      if (!val) continue;

      if (typeof val !== 'object') {
        Array.isArray(newCurrObj) ? newCurrObj.push(val) : newCurrObj[key] = val;
        continue;
      }

      const newSubObj: Obj = Array.isArray(val) ? [] : {};
      Array.isArray(newCurrObj) ? newCurrObj.push(newSubObj) : newCurrObj[key] = newSubObj;
      stack.push([val, newSubObj]);
    }
  }

  return newObj;
};
```

</details>
