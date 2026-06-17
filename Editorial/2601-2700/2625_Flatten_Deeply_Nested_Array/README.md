# 2625. Flatten Deeply Nested Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flatten-deeply-nested-array/)  

**Problem Link:** [LeetCode 2625 - Flatten Deeply Nested Array](https://leetcode.com/problems/flatten-deeply-nested-array/)

## Problem

Given a multi-dimensional array arr and a depth n, return a flattened version of that array.

A multi-dimensional array is a recursive data structure that contains integers or other multi-dimensional arrays.

A flattened array is a version of that array with some or all of the sub-arrays removed and replaced with the actual elements in that sub-array. This flattening operation should only be done if the current depth of nesting is less than n. The depth of the elements in the first array are considered to be 0.

Please solve it without the built-in Array.flat method.

### Example 1

```text
Input
arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 0
Output
[1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]

Explanation
Passing a depth of n=0 will always result in the original array. This is because the smallest possible depth of a subarray (0) is not less than n=0. Thus, no subarray should be flattened.
```

### Example 2

```text
Input
arr = [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 1
Output
[1, 2, 3, 4, 5, 6, 7, 8, [9, 10, 11], 12, 13, 14, 15]

Explanation
The subarrays starting with 4, 7, and 13 are all flattened. This is because their depth of 0 is less than 1. However [9, 10, 11] remains unflattened because its depth is 1.
```

### Example 3

```text
Input
arr = [[1, 2, 3], [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]]
n = 2
Output
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

Explanation
The maximum depth of any subarray is 1. Thus, all of them are flattened.
```

## Constraints

- 0 <= count of numbers in arr <= 105
- 0 <= count of subarrays in arr <= 105
- maxDepth <= 1000
- -1000 <= each number <= 1000
- 0 <= n <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [JSON Deep Equal](https://leetcode.com/problems/json-deep-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Convert Object to JSON String](https://leetcode.com/problems/convert-object-to-json-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Nested Array Generator](https://leetcode.com/problems/nested-array-generator/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2625. Flatten Deeply Nested Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive approach | JavaScript, TypeScript |
| Using Iterative Queue | JavaScript, TypeScript |
| Using Iterative Stack | JavaScript, TypeScript |

## Approach 1: Recursive approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    let res = [];
    const flattening = (nums, l) => {
      for (const num of nums) {
        if (Array.isArray(num) && l > 0) {
          flattening(num, l - 1);
        } else {
          res.push(num);
        }
      }
    }

    flattening(arr, n);
    return res;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

const flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    let res: MultiDimensionalArray = [];

    const flattening = (nums: MultiDimensionalArray, l: number) => {
        for (const num of nums) {
            if (Array.isArray(num) && l > 0 && l <= n) {
                flattening(num as MultiDimensionalArray, l - 1);
            } else {
                res.push(num);
            }
        }
    };

    flattening(arr, n);
    return res;
};
```

</details>

<br>

## Approach 2: Using Iterative Queue

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    let nestedArrayElement = true;
    let queue;
    let depth = 0;

    while (nestedArrayElement && depth < n) {
        nestedArrayElement = false;
        queue = [];

        for(let i = 0; i < arr.length; i++) {
            if (Array.isArray(arr[i])) {
                queue.push(...arr[i]);
                nestedArrayElement = true;
            } else {
                queue.push(arr[i]);
            }
        }
        arr = [...queue];
        depth++;
    }
    
    return arr;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

const flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    let nestedArrayElement = true;
    let queue: MultiDimensionalArray;
    let depth = 0;

    while (nestedArrayElement && depth < n) {
        nestedArrayElement = false;
        queue = [];

        for (let i = 0; i < arr.length; i++) {
            if (Array.isArray(arr[i])) {
                queue.push(...arr[i] as MultiDimensionalArray);
                nestedArrayElement = true;
            } else {
                queue.push(arr[i]);
            }
        }
        arr = [...queue];
        depth++;
    }

    return arr;
};
```

</details>

<br>

## Approach 3: Using Iterative Stack

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
	const stack = [...arr.map((item) => [item, n])];
	const res = [];
	
	while (stack.length > 0) {
		const [item, depth] = stack.pop();
		if (Array.isArray(item) && depth > 0) {
			// push back with depth - 1
			stack.push(...item.map((el) => [el, depth - 1]));
		} else {
			res.push(item);
		}
	}

	return res.reverse();
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

const flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    const stack: [MultiDimensionalArray, number][] = arr.map((item) => [item, n] as [MultiDimensionalArray, number]);
    const res: MultiDimensionalArray = [];

    while (stack.length > 0) {
        const [item, depth] = stack.pop()!;
        if (Array.isArray(item) && depth > 0) {
            stack.push(...item.map((el) => [el, depth - 1] as [MultiDimensionalArray, number]));
        } else {
            res.push(item);
        }
    }

    return res.reverse();
};
```

</details>
