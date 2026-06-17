# 2630. Memoize II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/memoize-ii/)  

**Problem Link:** [LeetCode 2630 - Memoize II](https://leetcode.com/problems/memoize-ii/)

## Problem

Given a function fn, return a memoized version of that function.

A memoized function is a function that will never be called twice with the same inputs. Instead it will return a cached value.

fn can be any function and there are no constraints on what type of values it accepts. Inputs are considered identical if they are === to each other.

### Example 1

```text
Input:
getInputs = () => [[2,2],[2,2],[1,2]]
fn = function (a, b) { return a + b; }
Output: [{"val":4,"calls":1},{"val":4,"calls":1},{"val":3,"calls":2}]
Explanation:
const inputs = getInputs();
const memoized = memoize(fn);
for (const arr of inputs) {
  memoized(...arr);
}

For the inputs of (2, 2): 2 + 2 = 4, and it required a call to fn().
For the inputs of (2, 2): 2 + 2 = 4, but those inputs were seen before so no call to fn() was required.
For the inputs of (1, 2): 1 + 2 = 3, and it required another call to fn() for a total of 2.
```

### Example 2

```text
Input:
getInputs = () => [[{},{}],[{},{}],[{},{}]]
fn = function (a, b) { return ({...a, ...b}); }
Output: [{"val":{},"calls":1},{"val":{},"calls":2},{"val":{},"calls":3}]
Explanation:
Merging two empty objects will always result in an empty object. It may seem like there should only be 1 call to fn() because of cache-hits, however none of those objects are === to each other.
```

### Example 3

```text
Input:
getInputs = () => { const o = {}; return [[o,o],[o,o],[o,o]]; }
fn = function (a, b) { return ({...a, ...b}); }
Output: [{"val":{},"calls":1},{"val":{},"calls":1},{"val":{},"calls":1}]
Explanation:
Merging two empty objects will always result in an empty object. The 2nd and 3rd third function calls result in a cache-hit. This is because every object passed in is identical.
```

## Constraints

- 1 <= inputs.length <= 105
- 0 <= inputs.flat().length <= 105
- inputs[i][j] != NaN

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Memoize](https://leetcode.com/problems/memoize/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Curry](https://leetcode.com/problems/curry/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2630. Memoize II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Tree Data Structure (Trie) | JavaScript, TypeScript |
| Convert Array of Inputs into a String | TypeScript |

## Approach 1: Tree Data Structure (Trie)

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class LookupTree {
  map = new Map();

  hasValue = false;

  value = null;

  getValueHelper(path, i) {
    const key = path[i];
    if (i >= path.length) {
      if (this.hasValue) {
        return { value: this.value, success: true };
      } else {
        return { value: undefined, success: false };
      }
    } else {
      if (this.map.has(key)) {
        return this.map.get(key).getValueHelper(path, i + 1);
      } else {
        return { value: undefined, success: false };
      }
    }
  }

  getValue(path) {
    return this.getValueHelper(path, 0);
  }

  setValueHelper(path, i, value) {
    const key = path[i];
    if (i >= path.length) {
      this.value = value;
      this.hasValue = true;
    } else {
      if (!this.map.has(key)) {
        this.map.set(key, new LookupTree());
      }
      return this.map.get(key).setValueHelper(path, i + 1, value);
    }
  }

  setValue(path, value) {
    return this.setValueHelper(path, 0, value);
  }
}

function memoize(func) {
  const tree = new LookupTree();
  const newFunction = (...params) => {
    const cache = tree.getValue(params);
    if (cache.success) {
      return cache.value;
    }
    const result = func(...params);
    tree.setValue(params, result);
    return result;
  };
  return newFunction;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class LookupTree {
  private map = new Map<any, any>();

  private hasValue = false;

  private value: any = null;

  private getValueHelper(path: any, i: number): { value: any; success: boolean } {
    const key = path[i];
    if (i >= path.length) {
      if (this.hasValue) {
        return { value: this.value, success: true };
      } else {
        return { value: undefined, success: false };
      }
    } else {
      if (this.map.has(key)) {
        return this.map.get(key).getValueHelper(path, i + 1);
      } else {
        return { value: undefined, success: false };
      }
    }
  }

  public getValue(path: any[]) {
    return this.getValueHelper(path, 0);
  }

  private setValueHelper(path: any[], i: number, value: any) {
    const key = path[i];
    if (i >= path.length) {
      this.value = value;
      this.hasValue = true;
    } else {
      if (!this.map.has(key)) {
        this.map.set(key, new LookupTree());
      }
      return this.map.get(key).setValueHelper(path, i + 1, value);
    }
  }

  public setValue(path: any[], value: any) {
    return this.setValueHelper(path, 0, value);
  }
}

function memoize<F extends (...params: any[]) => any>(func: F): F {
  const tree = new LookupTree();
  const newFunction = (...params: any[]) => {
    const cache = tree.getValue(params);
    if (cache.success) {
      return cache.value;
    }
    const result = func(...params);
    tree.setValue(params, result);
    return result;
  };
  return newFunction as F;
}
```

</details>

<br>

## Approach 2: Convert Array of Inputs into a String

### Implementation

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Fn = (...params: any) => any

function createKeyGenerator() {
    let count = 0;
    const map = new Map<unknown, number>();
    return function(input: unknown) {
        if (map.has(input)) return map.get(input);
        map.set(input, ++count)
        return count;
    }
}

function memoize(fn: Fn): Fn {
    const keyGenerator = createKeyGenerator();
    const cache = new Map<string, any>();
    return function(...args) {
        const numbers = args.map(keyGenerator);
        const key = numbers.join(',');
        if (cache.has(key)) return cache.get(key);
        const result = fn(...args);
        cache.set(key, result);
        return result;
    }
}
```

</details>
