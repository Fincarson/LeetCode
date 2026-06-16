# 2704. To Be Or Not To Be

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/to-be-or-not-to-be/)  

**Problem Link:** [LeetCode 2704 - To Be Or Not To Be](https://leetcode.com/problems/to-be-or-not-to-be/)

## Problem

Write a function expect that helps developers test their code. It should take in any value val and return an object with the following two functions.

- toBe(val) accepts another value and returns true if the two values === each other. If they are not equal, it should throw an error "Not Equal".
- notToBe(val) accepts another value and returns true if the two values !== each other. If they are equal, it should throw an error "Equal".

### Example 1

```text
Input: func = () => expect(5).toBe(5)
Output: {"value": true}
Explanation: 5 === 5 so this expression returns true.
```

### Example 2

```text
Input: func = () => expect(5).toBe(null)
Output: {"error": "Not Equal"}
Explanation: 5 !== null so this expression throw the error "Not Equal".
```

### Example 3

```text
Input: func = () => expect(5).notToBe(null)
Output: {"value": true}
Explanation: 5 !== null so this expression returns true.
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

# Editorial - 2704. To Be Or Not To Be

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Object Factory | JavaScript, TypeScript |

## Approach 1: Object Factory

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var expect = function(val) {
  return {
    toBe: (val2) => {
      if(val !== val2) throw new Error("Not Equal");
      return true;
    },
    notToBe: (val2) => {
      if(val === val2) throw new Error("Equal");
      return true;
    }
  };
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type ToBeOrNotToBe = {
  toBe: (val: any) => boolean;
  notToBe: (val: any) => boolean;
};

const expect = (val: any): ToBeOrNotToBe => {
    return {
        toBe: (val2: any): boolean => {
            if(val !== val2) throw new Error("Not Equal");
            return true;
        },
        notToBe: (val2: any): boolean => {
            if(val === val2) throw new Error("Equal");
            return true;
        }
    };
};
```

</details>
