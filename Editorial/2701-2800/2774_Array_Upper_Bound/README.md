# 2774. Array Upper Bound

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/array-upper-bound/)  

**Problem Link:** [LeetCode 2774 - Array Upper Bound](https://leetcode.com/problems/array-upper-bound/)

## Problem

Write code that enhances all arrays such that you can call the upperBound() method on any array and it will return the last index of a given target number. nums is a sorted ascending array of numbers that may contain duplicates. If the target number is not found in the array, return -1.

### Example 1

```text
Input: nums = [3,4,5], target = 5
Output: 2
Explanation: Last index of target value is 2
```

### Example 2

```text
Input: nums = [1,4,5], target = 2
Output: -1
Explanation: Because there is no digit 2 in the array, return -1.
```

### Example 3

```text
Input: nums = [3,4,6,6,6,6,7], target = 6
Output: 5
Explanation: Last index of target value is 5
```

## Constraints

- 1 <= nums.length <= 104
- -104 <= nums[i], target <= 104
- nums is sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Array Prototype Last](https://leetcode.com/problems/array-prototype-last/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Group By](https://leetcode.com/problems/group-by/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Snail Traversal](https://leetcode.com/problems/snail-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2774. Array Upper Bound

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Search/Brute Force | JavaScript, TypeScript |
| Binary Search | JavaScript, TypeScript |
| Using Built-in method | JavaScript, TypeScript |

## Approach 1: Linear Search/Brute Force

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/** 
 * @param {number} target
 * @return {number}
 */
Array.prototype.upperBound = function(target) {
    let result = -1;
    this.forEach((val, ind)=> {
        if(val === target){
            result = ind;
        }
    })
    return result;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function(target: number): number {
    let result = -1;
    this.forEach((val, ind) => {
        if (val === target) {
            result = ind;
        }
    });
    return result;
};
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/** 
 * @param {number} target
 * @return {number}
 */
Array.prototype.upperBound = function(target) {
    let left = 0;
    let right = this.length - 1;
    let result = -1; // Target not found

    while (left <= right) {
        const mid = left + ((right - left) >> 1);

        if (this[mid] === target) {
            result = mid;
            left = mid + 1; // Continue searching in the right half for the last occurrence
        } else if (this[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function(target: number): number {
    let left = 0;
    let right = this.length - 1;
    let result = -1; // Target not found

    while (left <= right) {
        const mid = left + ((right - left) >> 1);

        if (this[mid] === target) {
            result = mid;
            left = mid + 1; // Continue searching in the right half for the last occurrence
        } else if (this[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
};
```

</details>

<br>

## Approach 3: Using Built-in method

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/** 
 * @param {number} target
 * @return {number}
 */
Array.prototype.upperBound = function(target) {
    return this.lastIndexOf(target)
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function(target: number): number {
    return this.lastIndexOf(target);
};
```

</details>
