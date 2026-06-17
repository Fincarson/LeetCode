# 2776. Convert Callback Based Function to Promise Based Function

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/convert-callback-based-function-to-promise-based-function/)  

**Problem Link:** [LeetCode 2776 - Convert Callback Based Function to Promise Based Function](https://leetcode.com/problems/convert-callback-based-function-to-promise-based-function/)

## Problem

Write a function that accepts another function fn and converts the callback-based function into a promise-based function.

The function fn takes a callback as its first argument, along with any additional arguments args passed as separate inputs.

The promisify function returns a new function that should return a promise. The promise should resolve with the argument passed as the first parameter of the callback when the callback is invoked without error, and reject with the error when the callback is called with an error as the second argument.

The following is an example of a function that could be passed into promisify.

```text
function sum(callback, a, b) {
  if (a < 0 || b < 0) {
    const err = Error('a and b must be positive');
    callback(undefined, err);
  } else {
    callback(a + b);
  }
}
```

This is the equivalent code based on promises:

```text
async function sum(a, b) {
  if (a < 0 || b < 0) {
    throw Error('a and b must be positive');
  } else {
    return a + b;
  }
}
```

### Example 1

```text
Input:
fn = (callback, a, b, c) => {
    callback(a * b * c);
}
args = [1, 2, 3]
Output: {"resolved": 6}
Explanation:
const asyncFunc = promisify(fn);
asyncFunc(1, 2, 3).then(console.log); // 6

fn is called with a callback as the first argument and args as the rest. The promise based version of fn resolves a value of 6 when called with (1, 2, 3).
```

### Example 2

```text
Input:
fn = (callback, a, b, c) => {
    callback(a * b * c, "Promise Rejected");
}
args = [4, 5, 6]
Output: {"rejected": "Promise Rejected"}
Explanation:
const asyncFunc = promisify(fn);
asyncFunc(4, 5, 6).catch(console.log); // "Promise Rejected"

fn is called with a callback as the first argument and args as the rest. As the second argument, the callback accepts an error message, so when fn is called, the promise is rejected with a error message provided in the callback. Note that it did not matter what was passed as the first argument into the callback.
```

## Constraints

- 1 <= args.length <= 100
- 0 <= args[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2776. Convert Callback Based Function to Promise Based Function

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Transforming Callbacks to Promises | JavaScript, TypeScript |

## Approach 1: Transforming Callbacks to Promises

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

var promisify = function(fn) {
  return function(...args) {
    return new Promise((resolve, reject) => {
      function callback(result, error) {
        // If error, reject the Promise 
        if(error) {
          reject(error);
        // If no error, resolve the Promise
        } else {
          resolve(result);
        }
      }

      fn(callback, ...args);
    });
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript

type CallbackFn = (
    next: (data: number, error?: string) => void,
    ...args: number[]
) => void

type Promisified = (...args: number[]) => Promise<number>

function promisify(fn: CallbackFn): Promisified {
    return function(...args: number[]): Promise<number> {
        return new Promise((resolve, reject) => {
            function callback(result: number, error?: string) {
                // If error, reject the Promise
                if (error) {
                    reject(error);
                // If no error, resolve the Promise
                } else {
                    resolve(result);
                }
            }

            fn(callback, ...args);
        });
    };
}
```

</details>
