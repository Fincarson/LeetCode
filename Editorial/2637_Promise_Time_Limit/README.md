# 2637. Promise Time Limit

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/promise-time-limit/)  

**Problem Link:** [LeetCode 2637 - Promise Time Limit](https://leetcode.com/problems/promise-time-limit/)

## Problem

Given an asynchronous function fn and a time t in milliseconds, return a new time limited version of the input function. fn takes arguments provided to the time limited function.

The time limited function should follow these rules:

- If the fn completes within the time limit of t milliseconds, the time limited function should resolve with the result.
- If the execution of the fn exceeds the time limit, the time limited function should reject with the string "Time Limit Exceeded".

### Example 1

```text
Input:
fn = async (n) => {
  await new Promise(res => setTimeout(res, 100));
  return n * n;
}
inputs = [5]
t = 50
Output: {"rejected":"Time Limit Exceeded","time":50}
Explanation:
const limited = timeLimit(fn, t)
const start = performance.now()
let result;
try {
   const res = await limited(...inputs)
   result = {"resolved": res, "time": Math.floor(performance.now() - start)};
} catch (err) {
   result = {"rejected": err, "time": Math.floor(performance.now() - start)};
}
console.log(result) // Output

The provided function is set to resolve after 100ms. However, the time limit is set to 50ms. It rejects at t=50ms because the time limit was reached.
```

### Example 2

```text
Input:
fn = async (n) => {
  await new Promise(res => setTimeout(res, 100));
  return n * n;
}
inputs = [5]
t = 150
Output: {"resolved":25,"time":100}
Explanation:
The function resolved 5 * 5 = 25 at t=100ms. The time limit is never reached.
```

### Example 3

```text
Input:
fn = async (a, b) => {
  await new Promise(res => setTimeout(res, 120));
  return a + b;
}
inputs = [5,10]
t = 150
Output: {"resolved":15,"time":120}
Explanation:
​​​​The function resolved 5 + 10 = 15 at t=120ms. The time limit is never reached.
```

### Example 4

```text
Input:
fn = async () => {
  throw "Error";
}
inputs = []
t = 1000
Output: {"rejected":"Error","time":0}
Explanation:
The function immediately throws an error.
```

## Constraints

- 0 <= inputs.length <= 10
- 0 <= t <= 1000
- fn returns a promise

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sleep](https://leetcode.com/problems/sleep/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Debounce](https://leetcode.com/problems/debounce/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Promise Pool](https://leetcode.com/problems/promise-pool/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Cache With Time Limit](https://leetcode.com/problems/cache-with-time-limit/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Throttle](https://leetcode.com/problems/throttle/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2637. Promise Time Limit

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Call Function Inside New Promise | JavaScript, TypeScript |
| Handle Clearing Timeout | JavaScript, TypeScript |
| Promise Race | JavaScript, TypeScript |
| Async/Await + Clearing Timeout | JavaScript, TypeScript |

## Approach 1: Call Function Inside New Promise

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var timeLimit = function(fn, t) {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args).then(resolve).catch(reject);
    })
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args).then(resolve).catch(reject);
    })
  }
};
```

</details>

<br>

## Approach 2: Handle Clearing Timeout

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var timeLimit = function(fn, t) {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => clearTimeout(timeout));
    })
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => clearTimeout(timeout));
    })
  }
};
```

</details>

<br>

## Approach 3: Promise Race

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var timeLimit = function(fn, t) {
  return async function(...args) {
    const timeLimitPromise = new Promise((resolve, reject) => {
      setTimeout(() => reject("Time Limit Exceeded"), t)
    });
    const returnedPromise = fn(...args);
    return Promise.race([timeLimitPromise, returnedPromise]);
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
  return async function(...args) {
    const timeLimitPromise = new Promise((resolve, reject) => {
      setTimeout(() => reject("Time Limit Exceeded"), t)
    });
    const returnedPromise = fn(...args);
    return Promise.race([timeLimitPromise, returnedPromise]);
  }
};
```

</details>

<br>

## Approach 4: Async/Await + Clearing Timeout

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var timeLimit = function(fn, t) {
  return async function(...args) {
    return new Promise(async (resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);

      try {
        const result = await fn(...args);
        resolve(result);
      } catch(err) {
        reject(err);
      }
      clearTimeout(timeout);
    });
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
  return async function(...args) {
    return new Promise(async (resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);

      try {
        const result = await fn(...args);
        resolve(result);
      } catch(err) {
        reject(err);
      }
      clearTimeout(timeout);
    });
  };
};
```

</details>
