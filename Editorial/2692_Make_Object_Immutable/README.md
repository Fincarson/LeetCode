# 2692. Make Object Immutable

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/make-object-immutable/)  

**Problem Link:** [LeetCode 2692 - Make Object Immutable](https://leetcode.com/problems/make-object-immutable/)

## Problem

Write a function that takes an object obj and returns a new immutable version of this object.

An immutable object is an object that can't be altered and will throw an error if any attempt is made to alter it.

There are three types of error messages that can be produced from this new object.

- Attempting to modify a key on the object will result in this error message: `Error Modifying: ${key}`.
- Attempting to modify an index on an array will result in this error message: `Error Modifying Index: ${index}`.
- Attempting to call a method that mutates an array will result in this error message: `Error Calling Method: ${methodName}`. You may assume the only methods that can mutate an array are ['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse'].

obj is a valid JSON object or array, meaning it is the output of JSON.parse().

Note that a string literal should be thrown, not an Error.

### Example 1

```text
Input:
obj = {
  "x": 5
}
fn = (obj) => {
  obj.x = 5;
  return obj.x;
}
Output: {"value": null, "error": "Error Modifying: x"}
Explanation: Attempting to modify a key on an object resuts in a thrown error. Note that it doesn't matter that the value was set to the same value as it was before.
```

### Example 2

```text
Input:
obj = [1, 2, 3]
fn = (arr) => {
  arr[1] = {};
  return arr[2];
}
Output: {"value": null, "error": "Error Modifying Index: 1"}
Explanation: Attempting to modify an array results in a thrown error.
```

### Example 3

```text
Input:
obj = {
  "arr": [1, 2, 3]
}
fn = (obj) => {
  obj.arr.push(4);
  return 42;
}
Output: { "value": null, "error": "Error Calling Method: push"}
Explanation: Calling a method that can result in a mutation results in a thrown error.
```

### Example 4

```text
Input:
obj = {
  "x": 2,
  "y": 2
}
fn = (obj) => {
  return Object.keys(obj);
}
Output: {"value": ["x", "y"], "error": null}
Explanation: No mutations were attempted so the function returns as normal.
```

## Constraints

- obj is a valid JSON object or array
- 2 <= JSON.stringify(obj).length <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Infinite Method Object](https://leetcode.com/problems/infinite-method-object/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Immutability Helper](https://leetcode.com/problems/immutability-helper/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2692. Make Object Immutable

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using JavaScript Proxies to Make Objects and Arrays Immutable | JavaScript, TypeScript |
| Combined Conditions in Proxy Handler | JavaScript, TypeScript |

## Approach 1: Using JavaScript Proxies to Make Objects and Arrays Immutable

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var makeImmutable = function(obj) {
  // Define the methods that we want to block on our immutable object
  const methods = new Set(['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse'])

  // Depth-first search function to traverse and handle different types of elements in the object
  function dfs(obj) {
    // If the object is null, we just return it directly
    if(obj === null) return null

    // Handle function types separately to block mutating methods
    if(typeof obj === 'function') {
      return new Proxy(obj, {
        apply(func, thisArg, argumentList) {
          // Block the execution of certain methods
          if(methods.has(func.name)) {
            throw `Error Calling Method: ${func.name}`
          }
          return func.apply(thisArg, argumentList)
        }
      })
    }

    // Handle array types
    if(Array.isArray(obj)) {
      return  new Proxy(obj, {
        set(_, prop) {
          // Block the modification of the array
          throw `Error Modifying Index: ${prop}`
        },
        get(obj, prop) {
          // Continue the depth-first search for each element in the array
          return dfs(obj[prop])
        },
        apply(func, thisArg, argumentList) {
          // Block the execution of certain methods
          if(methods.has(func.name)) {
            throw `Error Calling Method: ${func.name}`
          }
          return func.apply(thisArg, argumentList)
        }
      })
    }

    // If it's not an object, we don't need to do anything special with it, so we return it directly
    if(typeof obj !== 'object') return obj

    // Handle object types
    return new Proxy(obj, {
      set(_, prop) {
        // Block the modification of the object
        throw `Error Modifying: ${prop}`
      },
      get(obj, prop) {
        // Continue the depth-first search for each property of the object
        return dfs(obj[prop])
      }
    })
  }

  // Start the depth-first search on the initial object
  return dfs(obj)
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Obj = Array<any> | Record<string, any>;

const makeImmutable = (obj: Obj): Obj => {
    // Define the methods that we want to block on our immutable object
    const methods = new Set(['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse']);

    // Depth-first search function to traverse and handle different types of elements in the object
    function dfs(obj: Obj): Obj {
        // If the object is null, we just return it directly
        if(obj === null) return null;

        // Handle function types separately to block mutating methods
        if(typeof obj === 'function') {
            return new Proxy(obj, {
                apply(func: Function, thisArg: any, argumentList: any[]) {
                    // Block the execution of certain methods
                    if(methods.has(func.name)) {
                        throw `Error Calling Method: ${func.name}`;
                    }
                    return func.apply(thisArg, argumentList);
                }
            });
        }

        // Handle array types
        if(Array.isArray(obj)) {
            return  new Proxy(obj, {
                set(_: Obj, prop: string | number | symbol) {
                    // Block the modification of the array
                    throw `Error Modifying Index: ${prop.toString()}`;
                },
                get(obj: Obj, prop: string | number | symbol) {
                    // Continue the depth-first search for each element in the array
                    return dfs(obj[prop as keyof typeof obj]);
                }
            });
        }

        // If it's not an object, we don't need to do anything special with it, so we return it directly
        if(typeof obj !== 'object') return obj;

        // Handle object types
        return new Proxy(obj, {
            set(_: Obj, prop: string | number | symbol) {
                // Block the modification of the object
                throw `Error Modifying: ${prop.toString()}`;
            },
            get(obj: Obj, prop: string | number | symbol) {
                // Continue the depth-first search for each property of the object
                return dfs(obj[prop as keyof typeof obj]);
            }
        });
    }

    // Start the depth-first search on the initial object
    return dfs(obj);
};
```

</details>

<br>

## Approach 2: Combined Conditions in Proxy Handler

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var makeImmutable = function(obj) {
  // Define a set of methods that mutate the object or array.
  const methods = new Set(['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse']);

  // Define the proxy handler object.
  const handler = {
    // 'set' trap throws an error when an attempt is made to modify a property.
    set : function(target, prop) {
      throw Array.isArray(target) ? `Error Modifying Index: ${prop}` : `Error Modifying: ${prop}`;
    },

    // 'get' trap creates a new proxy for nested objects or functions,
    // while returning primitive values and 'prototype' property as is.
    get : function(target, prop) {
      const condition =
        // 'prototype' property is returned as is to avoid potential issues with inheritance.
        prop === 'prototype' ||
        // If property is null, return as is.
        target[prop] === null ||
        // If property is not an object or function, return as is.
        typeof target[prop] !== 'object' &&
        typeof target[prop] !== 'function';

      // If the condition is true, return the property as is, else create a new Proxy.
      return condition ? target[prop] : new Proxy(target[prop], this);
    },

    // 'apply' trap throws an error when a mutating method is called.
    apply : function(target, thisArg, argumentsList) {
      if(methods.has(target.name))
        throw `Error Calling Method: ${target.name}`
      return target.apply(thisArg, argumentsList);
    }
  }

  // Return a new Proxy with the defined handler.
  return new Proxy(obj, handler);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type RecursiveHandler = {
    set: <T extends object>(target: T, prop: string | symbol, value: unknown) => boolean;
    get: <T extends object>(target: T, prop: string | symbol) => unknown;
    apply: <T extends Function>(target: T, thisArg: any, argArray?: any) => unknown;
};

const makeImmutable = <T extends object | Function>(obj: T): T => {
    // Create a set of mutating array methods
    const methods = new Set(['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse']);

    const handler: RecursiveHandler = {
        // 'set' trap prevents modifications of the object properties
        set(target, prop, value) {
            throw Array.isArray(target) ? `Error Modifying Index: ${String(prop)}` : `Error Modifying: ${String(prop)}`;
        },

        // 'get' trap returns object properties or creates new proxies for nested objects or functions
        get(target, prop) {
            // If the property is 'prototype', null, or not an object/function, return it directly
            // We exclude 'prototype' to avoid potential issues with inheritance
            // Objects and functions are wrapped in a new proxy to preserve immutability at all depths
            const condition = prop === 'prototype'  ||
                target[prop as keyof typeof target] === null ||
                typeof target[prop as keyof typeof target] !== 'object' &&
                typeof target[prop as keyof typeof target] !== 'function';
            return condition ? target[prop as keyof typeof target] : new Proxy(target[prop as keyof typeof target], this);
        },

        // 'apply' trap prevents call of mutating methods and apply function calls
        apply(target, thisArg, argumentsList) {
            if (methods.has((target as any).name))
                throw `Error Calling Method: ${(target as any).name}`
            return target.apply(thisArg, argumentsList);
        }
    }

    // Return a new proxy with the defined handler
    return new Proxy(obj, handler) as T;
};
```

</details>
