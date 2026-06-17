# 2703. Return Length of Arguments Passed

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/return-length-of-arguments-passed/)  

**Problem Link:** [LeetCode 2703 - Return Length of Arguments Passed](https://leetcode.com/problems/return-length-of-arguments-passed/)

## Problem

### Example 1

```text
Input: args = [5]
Output: 1
Explanation:
argumentsLength(5); // 1

One value was passed to the function so it should return 1.
```

### Example 2

```text
Input: args = [{}, null, "3"]
Output: 3
Explanation:
argumentsLength({}, null, "3"); // 3

Three values were passed to the function so it should return 3.
```

## Constraints

- args is a valid JSON array
- 0 <= args.length <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2703. Return Length of Arguments Passed

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using argument object | JavaScript, TypeScript |
| Using rest parameter | JavaScript, TypeScript |

## Approach 1: Using argument object

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var argumentsLength = function(...args) {
    return arguments.length;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function argumentsLength(...args: any[]): number {
    return arguments.length;
};
```

</details>

<br>

## Approach 2: Using rest parameter

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var argumentsLength = function(...args) {
    return args.length
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function argumentsLength(...args: any[]): number {
    return args.length;
};
```

</details>
