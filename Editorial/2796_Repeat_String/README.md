# 2796. Repeat String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/repeat-string/)  

**Problem Link:** [LeetCode 2796 - Repeat String](https://leetcode.com/problems/repeat-string/)

## Problem

Write code that enhances all strings such that you can call the string.replicate(x) method on any string and it will return repeated string x times.

Try to implement it without using the built-in method string.repeat.

### Example 1

```text
Input: str = "hello", times = 2
Output: "hellohello"
Explanation: "hello" is repeated 2 times
```

### Example 2

```text
Input: str = "code", times = 3
Output: "codecodecode"
Explanation: "code" is repeated 3 times
```

### Example 3

```text
Input: str = "js", times = 1
Output: "js"
Explanation: "js" is repeated 1 time
```

## Constraints

- 1 <= times <= 105
- 1 <= str.length <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2796. Repeat String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Solution | JavaScript, TypeScript |
| Iterative Solution | JavaScript, TypeScript |
| Using array.join method | JavaScript, TypeScript |

## Approach 1: Recursive Solution

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
String.prototype.replicate = function(times) {
    if (times === 0) {
        return "";
    }
    //Here "this" refers to the string object on which the method is called
    return this + this.replicate(times - 1);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface String {
        replicate(times: number): string;
    }
}

String.prototype.replicate = function(times: number) {
    if (times === 0) {
        return "";
    }
    //Here "this" refers to the string object on which the method is called
    return this + this.replicate(times - 1);
};
```

</details>

<br>

## Approach 2: Iterative Solution

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
String.prototype.replicate = function(times) {
    let result = "";
    for (let i = 0; i < times; i++) {
        result += this;
    }
    return result;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface String {
        replicate(times: number): string;
    }
}

String.prototype.replicate = function(times: number) {
    let result = "";
    for (let i = 0; i < times; i++) {
        result += this;
    }
    return result;
};
```

</details>

<br>

## Approach 3: Using array.join method

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
String.prototype.replicate = function(times) {
    const result = [];
    for (let i = 0; i < times; i++) {
        result.push(this);
    }

    return result.join('');
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
 declare global {
    interface String {
        replicate(times: number): string;
    }
}

String.prototype.replicate = function(times: number): string {
    const result: string[] = [];
    for (let i = 0; i < times; i++) {
        result.push(this);
    }

    return result.join('');
};
```

</details>
