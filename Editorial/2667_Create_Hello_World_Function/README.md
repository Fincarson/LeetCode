# 2667. Create Hello World Function

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/create-hello-world-function/)  

**Problem Link:** [LeetCode 2667 - Create Hello World Function](https://leetcode.com/problems/create-hello-world-function/)

## Problem

### Example 1

```text
Input: args = []
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f(); // "Hello World"

The function returned by createHelloWorld should always return "Hello World".
```

### Example 2

```text
Input: args = [{},null,42]
Output: "Hello World"
Explanation:
const f = createHelloWorld();
f({}, null, 42); // "Hello World"

Any arguments could be passed to the function but it should still always return "Hello World".
```

## Constraints

- 0 <= args.length <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2667. Create Hello World Function

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | JavaScript, TypeScript |

## Solution

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var createHelloWorld = function() {
    return function() {
        return "Hello World";
    }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var createHelloWorld = function() {
    return function(): string {
        return "Hello World";
    }
};
```

</details>
