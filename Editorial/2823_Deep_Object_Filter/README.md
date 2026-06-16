# 2823. Deep Object Filter

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/deep-object-filter/)  

**Problem Link:** [LeetCode 2823 - Deep Object Filter](https://leetcode.com/problems/deep-object-filter/)

## Problem

Given an object or an array obj and a function fn, return a filtered object or array filteredObject.

Function deepFilter should perform a deep filter operation on the obj. The deep filter operation should remove properties for which the output of the filter function fn is false, as well as any empty objects or arrays that remain after the keys have been removed.

If the deep filter operation results in an empty object or array, with no remaining properties, deepFilter should return undefined to indicate that there is no valid data left in the filteredObject.

### Example 1

```text
Input:
obj = [-5, -4, -3, -2, -1, 0, 1],
fn = (x) => x > 0
Output: [1]
Explanation: All values that were not greater than 0 were removed.
```

### Example 2

```text
Input:
obj = {"a": 1, "b": "2", "c": 3, "d": "4", "e": 5, "f": 6, "g": {"a": 1}},
fn = (x) => typeof x === "string"
Output: {"b":"2","d":"4"}
Explanation: All keys with values that were not a string were removed. When the object keys were removed during the filtering process, any resulting empty objects were also removed.
```

### Example 3

```text
Input:
obj = [-1, [-1, -1, 5, -1, 10], -1, [-1], [-5]],
fn = (x) => x > 0
Output: [[5,10]]
Explanation: All values that were not greater than 0 were removed. When the values were removed during the filtering process, any resulting empty arrays were also removed.
```

### Example 4

```text
Input:
obj = [[[[5]]]],
fn = (x) => Array.isArray(x)
Output: undefined
```

## Constraints

- fn is a function that returns a boolean value
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

# Editorial - 2823. Deep Object Filter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) Traversal for Deep Filtering | JavaScript, TypeScript |

## Approach 1: Depth-First Search (DFS) Traversal for Deep Filtering

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var deepFilter = function(obj, fn) {
  function dfs(node) {
    if(node === null) {
      if(fn(node)) return node;
      return undefined;
    }
    if(typeof node !== 'object' ) {
      if(fn(node)) return node;
      return undefined;
    }

    if(Array.isArray(node)) {
      const newArr = [];

      for(let i = 0;i < node.length; i++) {
        const curr = node[i];
        const subRes = dfs(curr);

        if(subRes!==undefined) {
          newArr.push(subRes);
        }
      }

      if(newArr.length === 0) {
        return undefined;
      }

      return newArr;
    }

    const newObj = {};
    let isEmpty = true

    for(const key in node) {
      const subRes = dfs(node[key]);
      if(subRes!== undefined) {
        newObj[key] = subRes;
        isEmpty = false
      }
    }

    if(isEmpty) return undefined;

    return newObj;
  }

  return dfs(obj);
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function deepFilter(
    obj: Record<string, any>,
    fn: Function
): Record<string, any> | undefined {
    function dfs(node: any): any {
        if (node === null) {
            if (fn(node)) return node;
            return undefined;
        }
        if (typeof node !== 'object') {
            if (fn(node)) return node;
            return undefined;
        }

        if (Array.isArray(node)) {
            const newArr: any[] = [];

            for (let i = 0; i < node.length; i++) {
                const curr = node[i];
                const subRes = dfs(curr);

                if (subRes !== undefined) {
                    newArr.push(subRes);
                }
            }

            if (newArr.length === 0) {
                return undefined;
            }

            return newArr;
        }

        const newObj: Record<string, any> = {};
        let isEmpty = true;

        for (const key in node) {
            if (Object.prototype.hasOwnProperty.call(node, key)) {
                const subRes = dfs(node[key]);
                if (subRes !== undefined) {
                    newObj[key] = subRes;
                    isEmpty = false;
                }
            }
        }

        if (isEmpty) return undefined;

        return newObj;
    }

    return dfs(obj);
}
```

</details>
