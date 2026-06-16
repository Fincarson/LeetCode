# 2666. Allow One Function Call

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/allow-one-function-call/)  

**Problem Link:** [LeetCode 2666 - Allow One Function Call](https://leetcode.com/problems/allow-one-function-call/)

## Problem

Given a function fn, return a new function that is identical to the original function except that it ensures fn is called at most once.

- The first time the returned function is called, it should return the same result as fn.
- Every subsequent time it is called, it should return undefined.

### Example 1

```text
Input: fn = (a,b,c) => (a + b + c), calls = [[1,2,3],[2,3,6]]
Output: [{"calls":1,"value":6}]
Explanation:
const onceFn = once(fn);
onceFn(1, 2, 3); // 6
onceFn(2, 3, 6); // undefined, fn was not called
```

### Example 2

```text
Input: fn = (a,b,c) => (a * b * c), calls = [[5,7,4],[2,3,6],[4,6,8]]
Output: [{"calls":1,"value":140}]
Explanation:
const onceFn = once(fn);
onceFn(5, 7, 4); // 140
onceFn(2, 3, 6); // undefined, fn was not called
onceFn(4, 6, 8); // undefined, fn was not called
```

## Constraints

- calls is a valid JSON array
- 1 <= calls.length <= 10
- 1 <= calls[i].length <= 100
- 2 <= JSON.stringify(calls).length <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2666. Allow One Function Call

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Rest Syntax | JavaScript, TypeScript |
| Implicitly Return Undefined | JavaScript, TypeScript |
| Bind Function to a Context | JavaScript, TypeScript |

## Approach 1: Rest Syntax

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var once = function(fn) {
  let hasBeenCalled = false;
  return function(...args){
    if (hasBeenCalled) {
      return undefined;
    } else {
      hasBeenCalled = true;
      return fn(...args);
    }
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function once<T extends (...args: any[]) => any>(fn: T): 
 ((...args: Parameters<T>) => ReturnType<T> | undefined) {
  let hasBeenCalled = false;
  return function(...args){
    if (hasBeenCalled) {
      return undefined;
    } else {
      hasBeenCalled = true;
      return fn(...args);
    }
  }
}
```

</details>

<br>

## Approach 2: Implicitly Return Undefined

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var once = function(fn) {
  let hasBeenCalled = false;
  return function(...args){
    if (!hasBeenCalled) {
      hasBeenCalled = true;
      return fn(...args);
    }
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function once<T extends (...args: any[]) => any>(fn: T): 
 ((...args: Parameters<T>) => ReturnType<T> | undefined) {
  let hasBeenCalled = false;
  return function(...args){
    if (!hasBeenCalled) {
      hasBeenCalled = true;
      return fn(...args);
    }
  }
}
```

</details>

<br>

## Approach 3: Bind Function to a Context

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var once = function(fn) {
  let hasBeenCalled = false;
  return function(...args){
    if (!hasBeenCalled) {
      hasBeenCalled = true;
      return fn.apply(this, args);
    }
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function once<T extends (...args: any[]) => any>(fn: T): 
 ((...args: Parameters<T>) => ReturnType<T> | undefined) {
  let hasBeenCalled = false;
  return function(...args){
    if (!hasBeenCalled) {
      hasBeenCalled = true;
      return fn.apply(this, args);
    }
  }
}
```

</details>
