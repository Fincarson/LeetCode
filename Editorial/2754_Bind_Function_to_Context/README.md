# 2754. Bind Function to Context

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/bind-function-to-context/)  

**Problem Link:** [LeetCode 2754 - Bind Function to Context](https://leetcode.com/problems/bind-function-to-context/)

## Problem

Enhance all functions to have the bindPolyfill method. When bindPolyfill is called with a passed object obj, that object becomes the this context for the function.

For example, if you had the code:

```text
function f() {
  console.log('My context is ' + this.ctx);
}
f();
```

The output would be "My context is undefined". However, if you bound the function:

```text
function f() {
  console.log('My context is ' + this.ctx);
}
const boundFunc = f.boundPolyfill({ "ctx": "My Object" })
boundFunc();
```

The output should be "My context is My Object".

You may assume that a single non-null object will be passed to the bindPolyfill method.

Please solve it without the built-in Function.bind method.

### Example 1

```text
Input:
fn = function f(multiplier) {
  return this.x * multiplier;
}
obj = {"x": 10}
inputs = [5]
Output: 50
Explanation:
const boundFunc = f.bindPolyfill({"x": 10});
boundFunc(5); // 50
A multiplier of 5 is passed as a parameter.
The context is set to {"x": 10}.
Multiplying those two numbers yields 50.
```

### Example 2

```text
Input:
fn = function speak() {
  return "My name is " + this.name;
}
obj = {"name": "Kathy"}
inputs = []
Output: "My name is Kathy"
Explanation:
const boundFunc = f.bindPolyfill({"name": "Kathy"});
boundFunc(); // "My name is Kathy"
```

## Constraints

- obj is a non-null object
- 0 <= inputs.length <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2754. Bind Function to Context

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Leveraging Symbols for Context Preservation | JavaScript, TypeScript |
| The `apply`/`call` Methods | JavaScript, TypeScript |

## Approach 1: Leveraging Symbols for Context Preservation

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

Function.prototype.bindPolyfill = function(obj) {
  const sym = Symbol()  // Create a unique symbol
  obj[sym] = this       // Assign the function to the symbol property of obj

  return (...args) => {     // Return a new function
    return obj[sym](...args)  // Invoke the original function, which is now a method on the object
  }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript

type Fn = (...args: any[]) => any;

declare global {
    interface Function {
        bindPolyfill(obj: Record<string | symbol, any>): Fn;
    }
}

Function.prototype.bindPolyfill = function(this: Function, obj: Record<string | symbol, any>): Fn {
    const sym = Symbol();  // Create a unique symbol
    obj[sym] = this;       // Assign the function to the symbol property of obj

    return (...args: any[]) => {     // Return a new function
        return obj[sym](...args);   // Invoke the original function, which is now a method on the object
    }
}
```

</details>

<br>

## Approach 2: The `apply`/`call` Methods

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

Function.prototype.bindPolyfill = function(obj) {
  const self = this;  // Reference to the original function using closure

  return function(...args) {     // Return a new function
    return self.apply(obj, args);  // Invoke original function with obj context using apply
  }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript

type Fn = (...args: any[]) => any;

declare global {
    interface Function {
        bindPolyfill(obj: Record<string | symbol, any>): Fn;
    }
}

Function.prototype.bindPolyfill = function(this: Function, obj: Record<string | symbol, any>): Fn {
    const self = this;  // Reference to the original function using closure

    return function(...args: any[]) {     // Return a new function
        return self.apply(obj, args);  // Invoke original function with obj context using apply
    }
}
```

</details>
