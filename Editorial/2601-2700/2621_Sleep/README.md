# 2621. Sleep

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sleep/)  

**Problem Link:** [LeetCode 2621 - Sleep](https://leetcode.com/problems/sleep/)

## Problem

Given a positive integer millis, write an asynchronous function that sleeps for millis milliseconds. It can resolve any value.

Note that minor deviation from millis in the actual sleep duration is acceptable.

### Example 1

```text
Input: millis = 100
Output: 100
Explanation: It should return a promise that resolves after 100ms.
let t = Date.now();
sleep(100).then(() => {
  console.log(Date.now() - t); // 100
});
```

### Example 2

```text
Input: millis = 200
Output: 200
Explanation: It should return a promise that resolves after 200ms.
```

## Constraints

- 1 <= millis <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Promise Time Limit](https://leetcode.com/problems/promise-time-limit/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Promise Pool](https://leetcode.com/problems/promise-pool/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2621. Sleep

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Asynchronous Programming with Promises and setTimeout | JavaScript, TypeScript |
| Asynchronous Programming with Promises and setTimeout without Return | JavaScript, TypeScript |

## Approach 1: Asynchronous Programming with Promises and setTimeout

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
async function sleep(millis) {
  return new Promise(resolve => {
    setTimeout(resolve, millis);
  });
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
async function sleep(millis: number): Promise<void> {
    return new Promise<void>(resolve => {
        setTimeout(resolve, millis);
    });
}
```

</details>

<br>

## Approach 2: Asynchronous Programming with Promises and setTimeout without Return

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
async function sleep(milliseconds) {
	await new Promise(res => setTimeout(res, milliseconds)); 
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
async function sleep(milliseconds: number): Promise<void> {
    await new Promise<void>(resolve => setTimeout(resolve, milliseconds));
}
```

</details>
