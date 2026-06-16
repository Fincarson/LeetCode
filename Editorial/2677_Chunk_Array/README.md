# 2677. Chunk Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/chunk-array/)  

**Problem Link:** [LeetCode 2677 - Chunk Array](https://leetcode.com/problems/chunk-array/)

## Problem

Given an array arr and a chunk size size, return a chunked array.

A chunked array contains the original elements in arr, but consists of subarrays each of length size. The length of the last subarray may be less than size if arr.length is not evenly divisible by size.

Please solve it without using lodash's _.chunk function.

### Example 1

```text
Input: arr = [1,2,3,4,5], size = 1
Output: [[1],[2],[3],[4],[5]]
Explanation: The arr has been split into subarrays each with 1 element.
```

### Example 2

```text
Input: arr = [1,9,6,3,2], size = 3
Output: [[1,9,6],[3,2]]
Explanation: The arr has been split into subarrays with 3 elements. However, only two elements are left for the 2nd subarray.
```

### Example 3

```text
Input: arr = [8,5,3,2,6], size = 6
Output: [[8,5,3,2,6]]
Explanation: Size is greater than arr.length thus all elements are in the first subarray.
```

### Example 4

```text
Input: arr = [], size = 1
Output: []
Explanation: There are no elements to be chunked so an empty array is returned.
```

## Constraints

- arr is a string representing the array.
- 2 <= arr.length <= 105
- 1 <= size <= arr.length + 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2677. Chunk Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Brute Force | JavaScript, TypeScript |
| Using Slicing | JavaScript, TypeScript |
| Using Splice and Slice | JavaScript, TypeScript |
| Using Reduce | JavaScript, TypeScript |
| Using Push | JavaScript, TypeScript |
| Using Ceiling | JavaScript, TypeScript |

## Approach 1: Using Brute Force

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  const chunkedArray = [];
  let index = 0;
  
  while (index < arr.length) {
    let count = size;
    const temp = [];
    
    while (count-- > 0 && index < arr.length) {
      temp.push(arr[index]);
      index++;
    }
    
    chunkedArray.push(temp);
  }
  
  return chunkedArray;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function chunk(arr: any[], size: number): any[][] {
  const chunkedArray: any[][] = [];
  let index = 0;

  while (index < arr.length) {
    let count = size;
    const temp: any[] = [];

    while (count-- > 0 && index < arr.length) {
      temp.push(arr[index]);
      index++;
    }

    chunkedArray.push(temp);
  }

  return chunkedArray;
}
```

</details>

<br>

## Approach 2: Using Slicing

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  const chunkedArray = [];
  let index = 0;
  
  while (index < arr.length) {
    chunkedArray.push(arr.slice(index, index + size));
    index += size;
  }
  
  return chunkedArray;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
function chunk(arr: any[], size: number): any[][] {
  const chunkedArray: any[][] = [];
  let index = 0;

  while (index < arr.length) {
    chunkedArray.push(arr.slice(index, index + size));
    index += size;
  }

  return chunkedArray;
}
```

</details>

<br>

## Approach 3: Using Splice and Slice

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  let chunkedArray = [[]];
  let temp = [];
  
  for (let i = 0; i < arr.length; i = i + size) {
    for (let j = 0; j < size; j++) {
      temp[j] = arr[j + i];
      if (j + i === arr.length) {
        temp.splice(j);
        break;
      }
    }
    chunkedArray = [...chunkedArray, [...temp]];
  }
  
  return chunkedArray.slice(1);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
function chunk(arr: any[], size: number): any[][] {
  let chunkedArray: any[][] = [[]];
  let temp: any[] = [];

  for (let i = 0; i < arr.length; i = i + size) {
    for (let j = 0; j < size; j++) {
      temp[j] = arr[j + i];
      if (j + i === arr.length) {
        temp.splice(j);
        break;
      }
    }
    chunkedArray = [...chunkedArray, [...temp]];
  }

  return chunkedArray.slice(1);
}
```

</details>

<br>

## Approach 4: Using Reduce

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  return arr.reduce((chunkedArray, element) => {
    const lastChunk = chunkedArray[chunkedArray.length - 1];
    if (!lastChunk || lastChunk.length === size) {
      chunkedArray.push([element]);
    } else {
      lastChunk.push(element);
    }
    return chunkedArray;
  }, []);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
function chunk(arr: any[], size: number): any[][] {
  return arr.reduce((chunkedArray: any[][], element: any) => {
    const lastChunk = chunkedArray[chunkedArray.length - 1];
    if (!lastChunk || lastChunk.length === size) {
      chunkedArray.push([element]);
    } else {
      lastChunk.push(element);
    }
    return chunkedArray;
  }, []);
}
```

</details>

<br>

## Approach 5: Using Push

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  const result = [];
  let currentChunk = [];

  for (const element of arr) {
    if (currentChunk.length === size) {
      result.push(currentChunk);
      currentChunk = [];
    }
    currentChunk.push(element);
  }

  if (currentChunk.length) result.push(currentChunk);
  return result;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
function chunk(arr: any[], size: number): any[][] {
  const result: any[][] = [];
  let currentChunk: any[] = [];

  for (const element of arr) {
    if (currentChunk.length === size) {
      result.push(currentChunk);
      currentChunk = [];
    }
    currentChunk.push(element);
  }

  if (currentChunk.length) result.push(currentChunk);
  return result;
}
```

</details>

<br>

## Approach 6: Using Ceiling

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  return Array.from({ length: Math.ceil(arr.length / size) }, function(_, index) {
    return arr.slice(index * size, index * size + size);
  });
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
function chunk(arr: any[], size: number): any[][] {
  return Array.from({ length: Math.ceil(arr.length / size) }, function(_: any, index: number) {
    return arr.slice(index * size, index * size + size);
  });
}
```

</details>
