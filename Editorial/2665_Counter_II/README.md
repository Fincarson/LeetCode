# 2665. Counter II

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/counter-ii/)  

**Problem Link:** [LeetCode 2665 - Counter II](https://leetcode.com/problems/counter-ii/)

## Problem

Write a function createCounter. It should accept an initial integer init. It should return an object with three functions.

The three functions are:

- increment() increases the current value by 1 and then returns it.
- decrement() reduces the current value by 1 and then returns it.
- reset() sets the current value to init and then returns it.

### Example 1

```text
Input: init = 5, calls = ["increment","reset","decrement"]
Output: [6,5,4]
Explanation:
const counter = createCounter(5);
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4
```

### Example 2

```text
Input: init = 0, calls = ["increment","increment","decrement","reset","reset"]
Output: [1,2,1,0,0]
Explanation:
const counter = createCounter(0);
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.reset(); // 0
counter.reset(); // 0
```

## Constraints

- -1000 <= init <= 1000
- 0 <= calls.length <= 1000
- calls[i] is one of "increment", "decrement" and "reset"

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Counter](https://leetcode.com/problems/counter/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2665. Counter II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Closure | JavaScript, TypeScript |
| Closure with Shortened Syntax | JavaScript, TypeScript |
| Closure with Separately Created Functions | JavaScript, TypeScript |
| Class | JavaScript, TypeScript |
| Closure with Proxy | JavaScript, TypeScript |

## Approach 1: Closure

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(init) {
  let currentCount = init;
  return {
    increment: function() {
       currentCount += 1;
       return currentCount;
    },
    decrement: function() {
       currentCount -= 1;
       return currentCount;
    },
    reset: function() {
       currentCount = init;
       return currentCount;
    },
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createCounter = function(init: number) {
  let currentCount = init;
  return {
    increment: function() {
       currentCount += 1;
       return currentCount;
    },
    decrement: function() {
       currentCount -= 1;
       return currentCount;
    },
    reset: function() {
       currentCount = init;
       return currentCount;
    },
  }
};
```

</details>

<br>

## Approach 2: Closure with Shortened Syntax

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(init) {
  let currentCount = init;
  return {
    increment: () => ++currentCount,
    decrement: () => --currentCount,
    reset: () => (currentCount = init),
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createCounter = function(init: number) {
  let currentCount = init;
  return {
    increment: () => ++currentCount,
    decrement: () => --currentCount,
    reset: () => (currentCount = init),
  }
};
```

</details>

<br>

## Approach 3: Closure with Separately Created Functions

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(init) {
  let currentCount = init;

  function increment() {
    return ++currentCount;
  }

  function decrement() {
      return --currentCount;
  }

  function reset() {
      return (currentCount = init);
  }

  return { increment, decrement, reset };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createCounter = function(init: number) {
  let currentCount = init;

  function increment() {
    return ++currentCount;
  }

  function decrement() {
      return --currentCount;
  }

  function reset() {
      return (currentCount = init);
  }

  return { increment, decrement, reset };
};
```

</details>

<br>

## Approach 4: Class

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Counter {
  constructor(init) {
    this.init = init;
    this.currentCount = init;
  }

  increment() {
    this.currentCount += 1;
    return this.currentCount;
  }

  decrement() {
    this.currentCount -= 1;
    return this.currentCount;
  }

  reset() {
    this.currentCount = this.init;
    return this.currentCount;
  }
}


var createCounter = function(init) {
  return new Counter(init);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Counter {
  init: number;
  currentCount: number;
  constructor(init) {
    this.init = init;
    this.currentCount = init;
  }

  increment() {
    this.currentCount += 1;
    return this.currentCount;
  }

  decrement() {
    this.currentCount -= 1;
    return this.currentCount;
  }

  reset() {
    this.currentCount = this.init;
    return this.currentCount;
  }
}


var createCounter = function(init: number) {
  return new Counter(init);
};
```

</details>

<br>

## Approach 5: Closure with Proxy

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createCounter = function(init) {
  let currentCount = init;
  return new Proxy({}, {
    get: (target, key) => {
      switch(key) {
        case "increment":
          return () => ++currentCount;
        case "decrement":
          return () => --currentCount;
        case "reset":
          return () => (currentCount = init);
        default:
          throw Error("Unexpected Method")
      }
    },
  });
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createCounter = function(init: number) {
  let currentCount = init;
  return new Proxy({}, {
    get: (target, key) => {
      switch(key) {
        case "increment":
          return () => ++currentCount;
        case "decrement":
          return () => --currentCount;
        case "reset":
          return () => (currentCount = init);
        default:
          throw Error("Unexpected Method")
      }
    },
  });
};
```

</details>
