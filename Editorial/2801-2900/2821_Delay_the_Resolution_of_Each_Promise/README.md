# 2821. Delay the Resolution of Each Promise

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/delay-the-resolution-of-each-promise/)  

**Problem Link:** [LeetCode 2821 - Delay the Resolution of Each Promise](https://leetcode.com/problems/delay-the-resolution-of-each-promise/)

## Problem

Given an array functions and a number ms, return a new array of functions.

- functions is an array of functions that return promises.
- ms represents the delay duration in milliseconds. It determines the amount of time to wait before resolving or rejecting each promise in the new array.

Each function in the new array should return a promise that resolves or rejects after an additional delay of ms milliseconds, preserving the order of the original functions array.

The delayAll function should ensure that each promise from functions is executed with a delay, forming the new array of functions returning delayed promises.

### Example 1

```text
Input:
functions = [
   () => new Promise((resolve) => setTimeout(resolve, 30))
],
ms = 50
Output: [80]
Explanation: The promise from the array would have resolved after 30 ms, but it was delayed by 50 ms, thus 30 ms + 50 ms = 80 ms.
```

### Example 2

```text
Input:
functions = [
    () => new Promise((resolve) => setTimeout(resolve, 50)),
    () => new Promise((resolve) => setTimeout(resolve, 80))
],
ms = 70
Output: [120,150]
Explanation: The promises from the array would have resolved after 50 ms and 80 ms, but they were delayed by 70 ms, thus 50 ms + 70 ms = 120 ms and 80 ms + 70 ms = 150 ms.
```

### Example 3

```text
Input:
functions = [
    () => new Promise((resolve, reject) => setTimeout(reject, 20)),
    () => new Promise((resolve, reject) => setTimeout(reject, 100))
],
ms = 30
Output: [50,130]
```

## Constraints

- functions is an array of functions that return promises
- 10 <= ms <= 500
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

# Editorial - 2821. Delay the Resolution of Each Promise

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Introducing Delays with Asynchronous Execution | JavaScript, TypeScript |

## Approach 1: Introducing Delays with Asynchronous Execution

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var delayAll = function(functions, ms) {
  const newFunctions = [];

  functions.forEach(el => {
    const newFuncWithPromise = () => {
      return new Promise((resolve, reject) => {
        // Introduce the delay
        setTimeout(() => {
          async function getResult() {
            try {
              // Execute original function
              const res = await el();
              resolve(res);
            } catch(err) {
              reject(err);
            }
          }
          getResult();
        }, ms);
      });
    }

    // Add the new function with the delay to the results
    newFunctions.push(newFuncWithPromise);
  });

  return newFunctions;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function delayAll(functions: Function[], ms: number): Function[] {
    const newFunctions: Function[] = [];

    functions.forEach(el => {
        const newFuncWithPromise: Function = () => {
            return new Promise((resolve, reject) => {
                // Introduce the delay
                setTimeout(async () => {
                    try {
                        // Execute original function
                        const res = await el();
                        resolve(res);
                    } catch(err) {
                        reject(err);
                    }
                }, ms);
            });
        }

        // Add the new function with the delay to the results
        newFunctions.push(newFuncWithPromise);
    });

    return newFunctions;
};
```

</details>
