# 2721. Execute Asynchronous Functions in Parallel

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/execute-asynchronous-functions-in-parallel/)  

**Problem Link:** [LeetCode 2721 - Execute Asynchronous Functions in Parallel](https://leetcode.com/problems/execute-asynchronous-functions-in-parallel/)

## Problem

Given an array of asynchronous functions functions, return a new promise promise. Each function in the array accepts no arguments and returns a promise. All the promises should be executed in parallel.

promise resolves:

- When all the promises returned from functions were resolved successfully in parallel. The resolved value of promise should be an array of all the resolved values of promises in the same order as they were in the functions. The promise should resolve when all the asynchronous functions in the array have completed execution in parallel.

promise rejects:

- When any of the promises returned from functions were rejected. promise should also reject with the reason of the first rejection.

Please solve it without using the built-in Promise.all function.

### Example 1

```text
Input: functions = [
  () => new Promise(resolve => setTimeout(() => resolve(5), 200))
]
Output: {"t": 200, "resolved": [5]}
Explanation:
promiseAll(functions).then(console.log); // [5]

The single function was resolved at 200ms with a value of 5.
```

### Example 2

```text
Input: functions = [
    () => new Promise(resolve => setTimeout(() => resolve(1), 200)),
    () => new Promise((resolve, reject) => setTimeout(() => reject("Error"), 100))
]
Output: {"t": 100, "rejected": "Error"}
Explanation: Since one of the promises rejected, the returned promise also rejected with the same error at the same time.
```

### Example 3

```text
Input: functions = [
    () => new Promise(resolve => setTimeout(() => resolve(4), 50)),
    () => new Promise(resolve => setTimeout(() => resolve(10), 150)),
    () => new Promise(resolve => setTimeout(() => resolve(16), 100))
]
Output: {"t": 150, "resolved": [4, 10, 16]}
Explanation: All the promises resolved with a value. The returned promise resolved when the last promise resolved.
```

## Constraints

- functions is an array of functions that returns promises
- 1 <= functions.length <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2721. Execute Asynchronous Functions in Parallel

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Emulate the behavior of Promise.all() | JavaScript, TypeScript |

## Approach 1: Emulate the behavior of Promise.all()

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var promiseAll = async function(functions) {
    return new Promise((resolve,reject) => {
        if(functions.length === 0) {
            resolve([]);
            return;
        }
        
        const res = new Array(functions.length).fill(null);

        let resolvedCount = 0;

        functions.forEach(async (el,idx) => {
            try {
                const subResult = await el();
                res[idx] = subResult;
                resolvedCount++;
                if(resolvedCount=== functions.length) {
                    resolve(res);
                }
            } catch(err) {
                reject(err);
            }
        });
    });
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
  return new Promise<T[]>((resolve, reject) => {
    if(functions.length === 0) {
      resolve([]);
      return;
    }

    const res: T[] = new Array(functions.length).fill(null);

    let resolvedCount = 0;

    functions.forEach(async (el, idx) => {
      try {
        const subResult = await el();
        res[idx] = subResult;
        resolvedCount++;
        if(resolvedCount === functions.length) {
          resolve(res);
        }
      } catch(err) {
        reject(err);
      }
    });
  });
};
```

</details>
