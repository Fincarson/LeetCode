# 2620. Counter

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/counter/)  

**Problem Link:** [LeetCode 2620 - Counter](https://leetcode.com/problems/counter/)

## Problem

Given an integer n, return a counter function. This counter function initially returns n and then returns 1 more than the previous value every subsequent time it is called (n, n + 1, n + 2, etc).

### Example 1

```text
Input:
n = 10
["call","call","call"]
Output: [10,11,12]
Explanation:
counter() = 10 // The first time counter() is called, it returns n.
counter() = 11 // Returns 1 more than the previous time.
counter() = 12 // Returns 1 more than the previous time.
```

### Example 2

```text
Input:
n = -2
["call","call","call","call","call"]
Output: [-2,-1,0,1,2]
Explanation: counter() initially returns -2. Then increases after each sebsequent call.
```

## Constraints

- -1000 <= n <= 1000
- 0 <= calls.length <= 1000
- calls[i] === "call"

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Memoize](https://leetcode.com/problems/memoize/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Function Composition](https://leetcode.com/problems/function-composition/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Counter II](https://leetcode.com/problems/counter-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2620. Counter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Increment Then Return | JavaScript, TypeScript |
| Postfix Increment Syntax | JavaScript, TypeScript |
| Prefix Decrement and Increment Syntax | JavaScript, TypeScript |
| Postfix Increment Syntax With Arrow Function | JavaScript, TypeScript |

## Approach 1: Increment Then Return

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(n) {
  let currentCount = n - 1;
  return function() {
    currentCount += 1;
    return currentCount;      
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createCounter = function(n: number) {
  let currentCount = n - 1;
  return function() {
    currentCount += 1;
    return currentCount;      
  };
};
```

</details>

<br>

## Approach 2: Postfix Increment Syntax

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(n) {
  return function() {
    return n++;      
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createCounter = function(n: number) {
  return function() {
    return n++;      
  };
};
```

</details>

<br>

## Approach 3: Prefix Decrement and Increment Syntax

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(n) {
  --n;
  return function() {
    return ++n;      
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createCounter = function(n: number) {
  --n;
  return function() {
    return ++n;      
  };
};
```

</details>

<br>

## Approach 4: Postfix Increment Syntax With Arrow Function

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(n) {
  return () => { return n++; };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function createCounter(n: number): () => number {
    return function () {
        return n++;
    }
}
```

</details>
