# 2618. Check if Object Instance of Class

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/check-if-object-instance-of-class/)  

**Problem Link:** [LeetCode 2618 - Check if Object Instance of Class](https://leetcode.com/problems/check-if-object-instance-of-class/)

## Problem

Write a function that checks if a given value is an instance of a given class or superclass. For this problem, an object is considered an instance of a given class if that object has access to that class's methods.

There are no constraints on the data types that can be passed to the function. For example, the value or the class could be undefined.

### Example 1

```text
Input: func = () => checkIfInstanceOf(new Date(), Date)
Output: true
Explanation: The object returned by the Date constructor is, by definition, an instance of Date.
```

### Example 2

```text
Input: func = () => { class Animal {}; class Dog extends Animal {}; return checkIfInstanceOf(new Dog(), Animal); }
Output: true
Explanation:
class Animal {};
class Dog extends Animal {};
checkIfInstanceOf(new Dog(), Animal); // true

Dog is a subclass of Animal. Therefore, a Dog object is an instance of both Dog and Animal.
```

### Example 3

```text
Input: func = () => checkIfInstanceOf(Date, Date)
Output: false
Explanation: A date constructor cannot logically be an instance of itself.
```

### Example 4

```text
Input: func = () => checkIfInstanceOf(5, Number)
Output: true
Explanation: 5 is a Number. Note that the "instanceof" keyword would return false. However, it is still considered an instance of Number because it accesses the Number methods. For example "toFixed()".
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2618. Check if Object Instance of Class

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterating Through Prototype Chain | JavaScript, TypeScript |
| Built-in instanceof method | JavaScript, TypeScript |
| Iterating Through Prototype Chain With Generator Function | JavaScript, TypeScript |

## Approach 1: Iterating Through Prototype Chain

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var checkIfInstanceOf = function (obj, classFunction) {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  let currPotentialPrototype = Object.getPrototypeOf(obj);

  while (currPotentialPrototype !== null) {
    if (currPotentialPrototype === classFunction.prototype) return true;
    currPotentialPrototype = Object.getPrototypeOf(currPotentialPrototype);
  }

  return false;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function checkIfInstanceOf(obj: any, classFunction: any): boolean {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  let currPotentialPrototype = Object.getPrototypeOf(obj);

  while (currPotentialPrototype !== null) {
    if (currPotentialPrototype === (classFunction as Function).prototype)
      return true;
    currPotentialPrototype = Object.getPrototypeOf(currPotentialPrototype);
  }

  return false;
};
```

</details>

<br>

## Approach 2: Built-in instanceof method

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var checkIfInstanceOf = function (obj, classFunction) {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  let inputObj = obj;
  if (typeof obj !== "object") {
    inputObj = Object(obj); // Make sure it's an object so instanceof has direct access to the constructor function
  }
  return inputObj instanceof classFunction;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function checkIfInstanceOf(obj: any, classFunction: any): boolean {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  let inputObj = obj;
  if (typeof obj !== "object") {
    inputObj = Object(obj); // Make sure it's an object so instanceof has direct access to the constructor function
  }
  return inputObj instanceof classFunction;
};
```

</details>

<br>

## Approach 3: Iterating Through Prototype Chain With Generator Function

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function* prototypeGenerator(obj) {
  let currPrototype = Object.getPrototypeOf(obj);
  while (currPrototype !== null) {
    yield currPrototype;
    currPrototype = Object.getPrototypeOf(currPrototype);
  }
}

var checkIfInstanceOf = function (obj, classFunction) {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  for (const prototype of prototypeGenerator(obj)) {
    if (prototype === classFunction.prototype) return true;
  }

  return false;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function* prototypeGenerator(obj: any): Generator<any, void, unknown> {
  let currPrototype = Object.getPrototypeOf(obj);
  while (currPrototype !== null) {
    yield currPrototype;
    currPrototype = Object.getPrototypeOf(currPrototype);
  }
}

function checkIfInstanceOf(obj: any, classFunction: any): boolean {
  if (obj === null || obj === undefined || typeof classFunction !== "function")
    return false;

  for (const prototype of prototypeGenerator(obj)) {
    if (prototype === (classFunction as Function).prototype) return true;
  }

  return false;
}
```

</details>
