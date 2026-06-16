# 2624. Snail Traversal

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/snail-traversal/)  

**Problem Link:** [LeetCode 2624 - Snail Traversal](https://leetcode.com/problems/snail-traversal/)

## Problem

Write code that enhances all arrays such that you can call the snail(rowsCount, colsCount) method that transforms the 1D array into a 2D array organised in the pattern known as snail traversal order. Invalid input values should output an empty array. If rowsCount * colsCount !== nums.length, the input is considered invalid.

Snail traversal order starts at the top left cell with the first value of the current array. It then moves through the entire first column from top to bottom, followed by moving to the next column on the right and traversing it from bottom to top. This pattern continues, alternating the direction of traversal with each column, until the entire current array is covered. For example, when given the input array [19, 10, 3, 7, 9, 8, 5, 2, 1, 17, 16, 14, 12, 18, 6, 13, 11, 20, 4, 15] with rowsCount = 5 and colsCount = 4, the desired output matrix is shown below. Note that iterating the matrix following the arrows corresponds to the order of numbers in the original array.

### Example 1

```text
Input:
nums = [19, 10, 3, 7, 9, 8, 5, 2, 1, 17, 16, 14, 12, 18, 6, 13, 11, 20, 4, 15]
rowsCount = 5
colsCount = 4
Output:
[
 [19,17,16,15],
 [10,1,14,4],
 [3,2,12,20],
 [7,5,18,11],
 [9,8,6,13]
]
```

### Example 2

```text
Input:
nums = [1,2,3,4]
rowsCount = 1
colsCount = 4
Output: [[1, 2, 3, 4]]
```

### Example 3

```text
Input:
nums = [1,3]
rowsCount = 2
colsCount = 2
Output: []
Explanation: 2 multiplied by 2 is 4, and the original array [1,3] has a length of 2; therefore, the input is invalid.
```

## Constraints

- 0 <= nums.length <= 250
- 1 <= nums[i] <= 1000
- 1 <= rowsCount <= 250
- 1 <= colsCount <= 250

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Array Prototype Last](https://leetcode.com/problems/array-prototype-last/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Group By](https://leetcode.com/problems/group-by/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Array Upper Bound](https://leetcode.com/problems/array-upper-bound/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2624. Snail Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Transformation of Array with Index Reversal | JavaScript, TypeScript |
| Direct Calculation of 2D Array Indices | JavaScript, TypeScript |
| Dual Iteration on Rows and Columns | JavaScript, TypeScript |
| Simulation - Down and Up Movement | JavaScript, TypeScript |

## Approach 1: Iterative Transformation of Array with Index Reversal

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount * colsCount !== this.length) return [];
    const arr = this;

    const res  = new Array(rowsCount).fill(0).map(() => new Array(colsCount).fill(0));
    let isReversed = false;

    for (let i = 0; i < this.length; i++) {
        const row = !isReversed ? i % rowsCount : rowsCount - 1 - (i % rowsCount);
        const col = Math.floor(i / rowsCount);

        res[row][col] = arr[i];
        
        if ((i % rowsCount) === rowsCount - 1) {
            isReversed = !isReversed;
        }
    }

    return res;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
   interface Array<T> {
      snail(rowsCount: number, colsCount: number): T[][];
   }
}

Array.prototype.snail = function<T>(this: T[], rowsCount: number, colsCount: number): T[][] {
   if (rowsCount * colsCount !== this.length) return [];

   const res: T[][] = new Array(rowsCount).fill(0).map(() => new Array(colsCount).fill(0));
   let isReversed = false;

   for (let i = 0; i < this.length; i++) {
      const row = !isReversed ? i % rowsCount :  rowsCount - 1 - (i % rowsCount);
      const col = Math.floor(i / rowsCount);

      res[row][col] = this[i];
      
      if ((i % rowsCount) === rowsCount - 1) {
         isReversed = !isReversed;
      }
   }

   return res;
}
```

</details>

<br>

## Approach 2: Direct Calculation of 2D Array Indices

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.snail = function(rowsCount, colsCount) {
    if (this.length !==  rowsCount * colsCount) return [];
    
    let result = Array(rowsCount).fill(null).map(() => new Array(colsCount).fill(null));
    
    for (let j = 0; j < this.length; j++) {
        const i = Math.floor(j / rowsCount);
        
        if (i % 2 === 0) {
            result[j % rowsCount][i] = this[j];
            continue;
        }
        
        result[rowsCount - j % rowsCount - 1][i] = this[j];
    }
    return result;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
   interface Array<T> {
      snail(rowsCount: number, colsCount: number): T[][];
   }
}

Array.prototype.snail = function<T>(rowsCount: number, colsCount: number): T[][] {
   if (this.length !==  rowsCount * colsCount) return [];
   
   let result = Array(rowsCount).fill(null).map(() => new Array(colsCount).fill(null));
   
   for (let j = 0; j < this.length; j++) {
      const i = Math.floor(j / rowsCount);
      
      if (i % 2 === 0) {
         result[j % rowsCount][i] = this[j];
         continue;
      }
      
      result[rowsCount - j % rowsCount - 1][i] = this[j];
   }
   
   return result;
}
```

</details>

<br>

## Approach 3: Dual Iteration on Rows and Columns

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.snail = function(rowsCount, colsCount) {
  if(rowsCount * colsCount !== this.length) return [];

  const res = new Array(rowsCount).fill(null).map(el => new Array(colsCount).fill(null))

  for (let currRow = 0; currRow < rowsCount; currRow++) {
    for (let currCol = 0; currCol < colsCount; currCol++) {
      if (currCol % 2 === 0) {
        res[currRow][currCol] = this[rowsCount * currCol + currRow]
        continue
      }

      if (currCol % 2 !== 0) {
        res[currRow][currCol] = this[rowsCount * currCol + rowsCount - 1 - currRow]
      }
    }
  }

  return res
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
   interface Array<T> {
      snail(rowsCount: number, colsCount: number): T[][];
   }
}

Array.prototype.snail = function<T>(rowsCount: number, colsCount: number): T[][] {
   if (rowsCount * colsCount !== this.length) return [];

   const res = new Array(rowsCount).fill(null).map(el => new Array(colsCount).fill(null));

   for (let currRow = 0; currRow < rowsCount; currRow++) {
      for (let currCol = 0; currCol < colsCount; currCol++) {
         if (currCol % 2 === 0) {
            res[currRow][currCol] = this[rowsCount * currCol + currRow];
            continue
         }
         
         res[currRow][currCol] = this[rowsCount * currCol + rowsCount - 1 - currRow];
      }
   }

   return res;
}
```

</details>

<br>

## Approach 4: Simulation - Down and Up Movement

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount * colsCount !== this.length) return [];
    
    const res = new Array(rowsCount).fill(null).map(() => new Array(colsCount).fill(null));

    const directions = [[1, 0], [-1, 0]]; // down, up
    let directionIndex = 0;
    let row = 0;
    let col = 0;

    for (let i = 0; i < this.length; i++) {
        res[row][col] = this[i];
        let nextRow = row + directions[directionIndex][0];
        let nextCol = col;

        if (nextRow < 0 || nextRow == rowsCount) {
            directionIndex = (directionIndex + 1) % 2; // change direction
            nextRow = row;
            nextCol = col + 1;
        }

        row = nextRow;
        col = nextCol;
    }

    return res;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
declare global {
   interface Array<T> {
      snail(rowsCount: number, colsCount: number): T[][];
   }
}

Array.prototype.snail = function<T>(rowsCount: number, colsCount: number): T[][] {
   if (rowsCount * colsCount !== this.length) return [];

   const res = new Array(rowsCount).fill(null).map(() => new Array(colsCount).fill(null));

   const directions = [[1, 0], [-1, 0]]; // down, up
   let directionIndex = 0;
   let row = 0, col = 0;

   for (let i = 0; i < this.length; i++) {
      res[row][col] = this[i];
      let nextRow = row + directions[directionIndex][0];
      let nextCol = col;

      if (nextRow < 0 || nextRow === rowsCount) {
         directionIndex = (directionIndex + 1) % 2; // change direction
         nextRow = row;
         nextCol = col + 1;
      }

      row = nextRow;
      col = nextCol;
   }

   return res;
}
```

</details>
