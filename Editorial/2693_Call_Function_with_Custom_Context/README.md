# 2693. Call Function with Custom Context

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/call-function-with-custom-context/)  

**Problem Link:** [LeetCode 2693 - Call Function with Custom Context](https://leetcode.com/problems/call-function-with-custom-context/)

## Problem

Enhance all functions to have the callPolyfill method. The method accepts an object obj as its first parameter and any number of additional arguments. The obj becomes the this context for the function. The additional arguments are passed to the function (that the callPolyfill method belongs on).

For example if you had the function:

```text
function tax(price, taxRate) {
  const totalCost = price * (1 + taxRate);
  console.log(`The cost of ${this.item} is ${totalCost}`);
}
```

Calling this function like tax(10, 0.1) will log "The cost of undefined is 11". This is because the this context was not defined.

However, calling the function like tax.callPolyfill({item: "salad"}, 10, 0.1) will log "The cost of salad is 11". The this context was appropriately set, and the function logged an appropriate output.

Please solve this without using the built-in Function.call method.

### Example 1

```text
Input:
fn = function add(b) {
  return this.a + b;
}
args = [{"a": 5}, 7]
Output: 12
Explanation:
fn.callPolyfill({"a": 5}, 7); // 12
callPolyfill sets the "this" context to {"a": 5}. 7 is passed as an argument.
```

### Example 2

```text
Input:
fn = function tax(price, taxRate) {
 return `The cost of the ${this.item} is ${price * taxRate}`;
}
args = [{"item": "burger"}, 10, 1.1]
Output: "The cost of the burger is 11"
Explanation: callPolyfill sets the "this" context to {"item": "burger"}. 10 and 1.1 are passed as additional arguments.
```

## Constraints

- typeof args[0] == 'object' and args[0] != null
- 1 <= args.length <= 100
- 2 <= JSON.stringify(args[0]).length <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2693. Call Function with Custom Context

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Object | JavaScript, TypeScript |
| Using Symbol | JavaScript |
| Using Bind | JavaScript, TypeScript |
| Using apply | JavaScript, TypeScript |

## Approach 1: Using Object

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Function.prototype.callPolyfill = function(context, ...args) {
  Object.defineProperty(context, 'fn', {
    value: this,
    enumerable: false,
  });

  return context.fn(...args);
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global { 
    interface Function {
      callPolyfill(context: Record<any, any>, ...args: any[]): any;
	}
}

Function.prototype.callPolyfill = function(context: Record<any, any>, ...args: any[]): any {
  Object.defineProperty(context, 'fn', {
    value: this,
    enumerable: false,
  });

  return context.fn(...args);
};

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```

</details>

<br>

## Approach 2: Using Symbol

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function (context, ...args) {
  const uniqueSymbol = Symbol();
  context[uniqueSymbol] = this;
  const result = context[uniqueSymbol](...args);
  delete context[uniqueSymbol];

  return result;
};

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```

</details>

<br>

## Approach 3: Using Bind

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function(context, ...args) {
    return this.bind(context)(...args)
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global { 
    interface Function {
      callPolyfill(context: Record<any, any>, ...args: any[]): any;
	}
}

Function.prototype.callPolyfill = function(context: Record<any, any>, ...args: any[]): any {
  return this.bind(context)(...args);
};
/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```

</details>

<br>

## Approach 4: Using apply

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function(context, ...args) {
    return this.apply(context, args);
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global { 
    interface Function {
      callPolyfill(context: Record<any, any>, ...args: any[]): any;
	}
}

Function.prototype.callPolyfill = function(context: Record<any, any>, ...args: any[]): any {
  return this.apply(context, args);
};
/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
```

</details>
