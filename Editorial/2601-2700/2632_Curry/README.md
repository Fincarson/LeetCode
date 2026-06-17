# 2632. Curry

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/curry/)  

**Problem Link:** [LeetCode 2632 - Curry](https://leetcode.com/problems/curry/)

## Problem

Given a function fn, return a curried version of that function.

A curried function is a function that accepts fewer or an equal number of parameters as the original function and returns either another curried function or the same value the original function would have returned.

In practical terms, if you called the original function like sum(1,2,3), you would call the curried version like csum(1)(2)(3), csum(1)(2,3), csum(1,2)(3), or csum(1,2,3). All these methods of calling the curried function should return the same value as the original.

### Example 1

```text
Input:
fn = function sum(a, b, c) { return a + b + c; }
inputs = [[1],[2],[3]]
Output: 6
Explanation:
The code being executed is:
const curriedSum = curry(fn);
curriedSum(1)(2)(3) === 6;
curriedSum(1)(2)(3) should return the same value as sum(1, 2, 3).
```

### Example 2

```text
Input:
fn = function sum(a, b, c) { return a + b + c; }
inputs = [[1,2],[3]]
Output: 6
Explanation:
curriedSum(1, 2)(3) should return the same value as sum(1, 2, 3).
```

### Example 3

```text
Input:
fn = function sum(a, b, c) { return a + b + c; }
inputs = [[],[],[1,2,3]]
Output: 6
Explanation:
You should be able to pass the parameters in any way, including all at once or none at all.
curriedSum()()(1, 2, 3) should return the same value as sum(1, 2, 3).
```

### Example 4

```text
Input:
fn = function life() { return 42; }
inputs = [[]]
Output: 42
Explanation:
currying a function that accepts zero parameters should effectively do nothing.
curriedLife() === 42
```

## Constraints

- 1 <= inputs.length <= 1000
- 0 <= inputs[i][j] <= 105
- 0 <= fn.length <= 1000
- inputs.flat().length == fn.length
- function parameters explicitly defined
- If fn.length > 0 then the last array in inputs is not empty
- If fn.length === 0 then inputs.length === 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Memoize](https://leetcode.com/problems/memoize/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Memoize II](https://leetcode.com/problems/memoize-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2632. Curry

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Currying with Recursive Function Calls | JavaScript, TypeScript |
| Currying with the Built-in Bind Method | JavaScript, TypeScript |

## Approach 1: Currying with Recursive Function Calls

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var curry = function(fn) {
   return function curried(...args) {
      if(args.length >= fn.length) {
         return fn(...args);
      }

      return (...nextArgs) => curried(...args, ...nextArgs);
   };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function curry(fn: Function): Function {
   return function curried(...args: any[]): any {
      if (args.length >= fn.length) {
         return fn(...args);
      }

      return (...nextArgs: any[]): any => curried(...args, ...nextArgs);
   }
};
```

</details>

<br>

## Approach 2:  Currying with the Built-in Bind Method

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var curry = function (fn) {
  return function curried(...args) {
    if (args.length >= fn.length) {
      return fn.apply(this, args);
    }

    return curried.bind(this, ...args);
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function curry(fn: Function): Function {
    return function curried(...args: any[]): any {
        if (args.length >= fn.length) {
            return fn.apply(this, args);
        }

        return curried.bind(this, ...args);
    };
}
```

</details>
