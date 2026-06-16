# 2723. Add Two Promises

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/add-two-promises/)  

**Problem Link:** [LeetCode 2723 - Add Two Promises](https://leetcode.com/problems/add-two-promises/)

## Problem

### Example 1

```text
Input:
promise1 = new Promise(resolve => setTimeout(() => resolve(2), 20)),
promise2 = new Promise(resolve => setTimeout(() => resolve(5), 60))
Output: 7
Explanation: The two input promises resolve with the values of 2 and 5 respectively. The returned promise should resolve with a value of 2 + 5 = 7. The time the returned promise resolves is not judged for this problem.
```

### Example 2

```text
Input:
promise1 = new Promise(resolve => setTimeout(() => resolve(10), 50)),
promise2 = new Promise(resolve => setTimeout(() => resolve(-12), 30))
Output: -2
Explanation: The two input promises resolve with the values of 10 and -12 respectively. The returned promise should resolve with a value of 10 + -12 = -2.
```

## Constraints

- promise1 and promise2 are promises that resolve with a number

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2723. Add Two Promises

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Promise.all | JavaScript, TypeScript |
| Using Only Await | JavaScript, TypeScript |
| Using Promise.then() | JavaScript, TypeScript |
| Count promises | JavaScript, TypeScript |

## Approach 1: Using Promise.all

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
  try {
    const [res1, res2] = await Promise.all([promise1, promise2]);
    return res1 + res2;
  } catch (error) {
    console.error(error);
    throw error; // Rethrow the error to maintain the behavior of propagating the error to the caller
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
  try {
    const [res1, res2] = await Promise.all([promise1, promise2]);
    return res1 + res2;
  } catch (error) {
    console.error(error);
    throw error; // Rethrow the error to maintain the behavior of propagating the error to the caller
  }
}
```

</details>

<br>

## Approach 2: Using Only Await

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
  try {
    return await promise1 + await promise2;
  } catch (error) {
    console.error(error);
    throw error; // Rethrow the error to maintain the behavior of propagating the error to the caller
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
  try {
    return await promise1 + await promise2;
  } catch (error) {
    console.error(error);
    throw error; // Rethrow the error to maintain the behavior of propagating the error to the caller
  }
}
```

</details>

<br>

## Approach 3: Using Promise.then()

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
  try {
    return promise1.then((val) => promise2.then((val2) => val + val2))
  } catch (error) {
    console.error(error);
    throw error; // Rethrow the error to maintain the behavior of propagating the error to the caller
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
  try {
    return promise1.then((val) => promise2.then((val2) => val + val2))
  } catch (error) {
    console.error(error);
    throw error; // Rethrow the error to maintain the behavior of propagating the error to the caller
  }
}
```

</details>

<br>

## Approach 4: Count promises

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function (promise1, promise2) {
  return new Promise((resolve, reject) => {
    let count = 2;
    let res = 0; 
    
    [promise1, promise2].forEach(async promise => {
      try {
        const subRes = await promise;
        res += subRes;
        count--;

        if (count === 0) {
          resolve(res);
        }
      } catch (err) {
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
async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
  return new Promise<number>((resolve, reject) => {
    let count = 2;
    let res = 0;

    [promise1, promise2].forEach(async (promise) => {
      try {
        const subRes = await promise;
        res += subRes;
        count--;

        if (count === 0) {
          resolve(res);
        }
      } catch (err) {
        reject(err);
      }
    });
  });
}
```

</details>
