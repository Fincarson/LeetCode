# 2690. Infinite Method Object

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/infinite-method-object/)  

**Problem Link:** [LeetCode 2690 - Infinite Method Object](https://leetcode.com/problems/infinite-method-object/)

## Problem

Write a function that returns an infinite-method object.

An infinite-method object is defined as an object that allows you to call any method and it will always return the name of the method.

For example, if you execute obj.abc123(), it will return "abc123".

### Example 1

```text
Input: method = "abc123"
Output: "abc123"
Explanation:
const obj = createInfiniteObject();
obj['abc123'](); // "abc123"
The returned string should always match the method name.
```

### Example 2

```text
Input: method = ".-qw73n|^2It"
Output: ".-qw73n|^2It"
Explanation: The returned string should always match the method name.
```

## Constraints

- 0 <= method.length <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Immutability Helper](https://leetcode.com/problems/immutability-helper/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Make Object Immutable](https://leetcode.com/problems/make-object-immutable/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2690. Infinite Method Object

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using JavaScript Proxies | JavaScript, TypeScript |

## Approach 1: Using JavaScript Proxies

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function createInfiniteObject() {
  return new Proxy({}, {
    get: function(target, propKey) {
      return function() {
        return String(propKey);
      };
    }
  });
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function createInfiniteObject(): Record<string, () => string> {
  return new Proxy({}, {
    get: function(target: object, propKey: string | symbol): () => string {
      return function(): string {
        return String(propKey);
      };
    }
  });
}
```

</details>
