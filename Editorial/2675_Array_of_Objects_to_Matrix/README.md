# 2675. Array of Objects to Matrix

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/array-of-objects-to-matrix/)  

**Problem Link:** [LeetCode 2675 - Array of Objects to Matrix](https://leetcode.com/problems/array-of-objects-to-matrix/)

## Problem

Write a function that converts an array of objects arr into a matrix m.

arr is an array of objects or arrays. Each item in the array can be deeply nested with child arrays and child objects. It can also contain numbers, strings, booleans, and null values.

The first row m should be the column names. If there is no nesting, the column names are the unique keys within the objects. If there is nesting, the column names are the respective paths in the object separated by ".".

Each of the remaining rows corresponds to an object in arr. Each value in the matrix corresponds to a value in an object. If a given object doesn't contain a value for a given column, the cell should contain an empty string "".

The columns in the matrix should be in lexographically ascending order.

### Example 1

```text
Input:
arr = [
  {"b": 1, "a": 2},
  {"b": 3, "a": 4}
]
Output:
[
  ["a", "b"],
  [2, 1],
  [4, 3]
]

Explanation:
There are two unique column names in the two objects: "a" and "b".
"a" corresponds with [2, 4].
"b" coresponds with [1, 3].
```

### Example 2

```text
Input:
arr = [
  {"a": 1, "b": 2},
  {"c": 3, "d": 4},
  {}
]
Output:
[
  ["a", "b", "c", "d"],
  [1, 2, "", ""],
  ["", "", 3, 4],
  ["", "", "", ""]
]

Explanation:
There are 4 unique column names: "a", "b", "c", "d".
The first object has values associated with "a" and "b".
The second object has values associated with "c" and "d".
The third object has no keys, so it is just a row of empty strings.
```

### Example 3

```text
Input:
arr = [
  {"a": {"b": 1, "c": 2}},
  {"a": {"b": 3, "d": 4}}
]
Output:
[
  ["a.b", "a.c", "a.d"],
  [1, 2, ""],
  [3, "", 4]
]

Explanation:
In this example, the objects are nested. The keys represent the full path to each value separated by periods.
There are three paths: "a.b", "a.c", "a.d".
```

### Example 4

```text
Input:
arr = [
  [{"a": null}],
  [{"b": true}],
  [{"c": "x"}]
]
Output:
[
  ["0.a", "0.b", "0.c"],
  [null, "", ""],
  ["", true, ""],
  ["", "", "x"]
]

Explanation:
Arrays are also considered objects with their keys being their indices.
Each array has one element so the keys are "0.a", "0.b", and "0.c".
```

### Example 5

```text
Input:
arr = [
  {},
  {},
  {},
]
Output:
[
  [],
  [],
  [],
  []
]

Explanation:
There are no keys so every row is an empty array.
```

## Constraints

- arr is a valid JSON array
- 1 <= arr.length <= 1000
- unique keys <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [JSON Deep Equal](https://leetcode.com/problems/json-deep-equal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Convert Object to JSON String](https://leetcode.com/problems/convert-object-to-json-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2675. Array of Objects to Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Approach | JavaScript, TypeScript |
| Selective Iterative Approach with Map: | JavaScript, TypeScript |
| Stack Approach | JavaScript |
| Backtracking Approach | JavaScript |
| Using Generator Function | JavaScript |

## Approach 1: Recursive Approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @return {Matrix}
 */
var jsonToMatrix = function (arr) {
  const isObject = x => (x !== null && typeof x === 'object')

  const getKeys = (object) => {
    if (!isObject(object)) return [''];
    const result = [];
    for (const key of Object.keys(object)) {
      const childKeys = getKeys(object[key]);
      for (const childKey of childKeys) {
        result.push(childKey ? `${key}.${childKey}` : key);
      }
    }  
    return result;
  }

  const keysSet = arr.reduce((acc, curr) => {
  getKeys(curr).forEach((k) => acc.add(k));
  return acc;
  }, new Set());

  const keys = Array.from(keysSet).sort();

  const getValue = (obj, path) => {
    const paths = path.split('.')
    let i = 0;
    let value = obj
    while (i < paths.length) {
      if (!isObject(value)) break;
      value = value[paths[i++]]
    }
    if (i < paths.length || isObject(value) || value === undefined) return ''
    return value
  }

  const matrix = [keys]
  arr.forEach(obj => {
    matrix.push(keys.map(key => getValue(obj, key)))
  })

  return matrix
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jsonToMatrix(arr: any[]): (string | number | boolean | null)[][] {
  const isObject = (x: any): x is object => (x !== null && typeof x === 'object');

  const getKeys = (arg: any): string[] => {
    if (!isObject(arg)) return [''];
    return Object.keys(arg).reduce((acc: string[], curr: string) => {
      return (acc.push(...getKeys(arg[curr]).map((x: string) => x ? `${curr}.${x}` : curr)), acc);
    }, []);
  };

  const keys: string[] = [...arr.reduce((acc: Set<string>, curr: any) => {
    getKeys(curr).forEach((k: string) => acc.add(k));
    return acc;
  }, new Set<string>())].sort();

  const getValue = (obj: any, path: string): string | number | boolean | null => {
    const paths: string[] = path.split('.');
    let i = 0;
    let value: any = obj;
    while (i < paths.length) {
      if (!isObject(value)) break;
      value = value[paths[i++]];
    }
    if (i < paths.length || isObject(value) || value === undefined) return '';
    return value;
  };

  const matrix: (string | number | boolean | null)[][] = [keys];
  arr.forEach((obj: any) => {
    matrix.push(keys.map((key: string) => getValue(obj, key)));
  });

  return matrix;
}
```

</details>

<br>

## Approach 2: Selective Iterative Approach with Map:

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @return {Matrix}
 */
var jsonToMatrix = function (arr) {
  const isObject = elem => elem instanceof Object

  const getSub = (obj) => {
    const map = new Map()

    const setMap = (elem, preKey) => {
      if (!isObject(elem)) {
        map.set(preKey, elem)
        return
      }

      const subMap = getSub(elem)
      for (const entry of subMap.entries()) {
        const symbol = `${preKey}.${entry[0]}`
        map.set(symbol, entry[1])
      }
    }

    if (Array.isArray(obj)) {
      for (let i = 0; i < obj.length; i++) {
        setMap(obj[i], `${i}`)
      }
    } else {
      for (const key of Object.keys(obj)) {
        setMap(obj[key], key)
      }
    }

    return map
  }

  const map = getSub(arr)
  const set = new Set()

  for (const key of map.keys()) {
    const i = key.indexOf('.')
    const symbol = key.slice(i + 1)
    set.add(symbol)
  }

  const keys = [...set].sort((a, b) => a < b ? -1 : 1)
  const len = arr.length
  const matrix = [keys]

  for (let i = 1; i <= len; i++) {
    if (keys.length === 0) {
      matrix[i] = []
      continue
    }

    for (let j = 0; j < keys.length; j++) {
      const key = `${i - 1}.${keys[j]}`
      if (!matrix[i]) {
        matrix[i] = []
      }
      matrix[i][j] = map.has(key) ? map.get(key) : ""
    }
  }

  return matrix
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jsonToMatrix(arr: any[]): (string | number | boolean | null)[][] {
  const isObject = (elem: any): boolean => elem instanceof Object;

  const getSub = (obj: any): Map<string, any> => {
    const map = new Map<string, any>();

    const setMap = (elem: any, preKey: string) => {
      if (!isObject(elem)) {
        map.set(preKey, elem);
        return;
      }

      const subMap = getSub(elem);
      for (const entry of subMap.entries()) {
        const symbol = `${preKey}.${entry[0]}`;
        map.set(symbol, entry[1]);
      }
    };

    if (Array.isArray(obj)) {
      for (let i = 0; i < obj.length; i++) {
        setMap(obj[i], `${i}`);
      }
    } else {
      for (const key of Object.keys(obj)) {
        setMap(obj[key], key);
      }
    }

    return map;
  };

  const map = getSub(arr);
  const set = new Set<string>();

  for (const key of map.keys()) {
    const i = key.indexOf('.');
    const symbol = key.slice(i + 1);
    set.add(symbol);
  }

  const keys = [...set].sort((a, b) => a < b ? -1 : 1);
  const len = arr.length;
  const matrix: (string | number | boolean | null)[][] = [keys];

  for (let i = 1; i <= len; i++) {
    if (keys.length === 0) {
      matrix[i] = [];
      continue;
    }

    for (let j = 0; j < keys.length; j++) {
      const key = `${i - 1}.${keys[j]}`;
      if (!matrix[i]) {
        matrix[i] = [];
      }
      matrix[i][j] = map.has(key) ? map.get(key) : "";
    }
  }

  return matrix;
}
```

</details>

<br>

## Approach 3: Stack Approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @return {Matrix}
 */
var jsonToMatrix = function (arr) {
  const colMap = new Map()
  const res = [[]]

  const sortCols = (matrix) => {
  // Copy the column names from the first row of the matrix and sort them using localeCompare
  const sortedColNames = matrix[0].slice().sort((a, b) => a.localeCompare(b));

  // Create a new sorted matrix based on the sorted column names
  const sortedMatrix = matrix.map((row) => {
    const sortedRow = [];
    for (let i = 0; i < sortedColNames.length; i++) {
      const colIndex = matrix[0].indexOf(sortedColNames[i]);
      sortedRow.push(row[colIndex]);
    }
    return sortedRow;
  });

  return sortedMatrix;
  };


  for (let i = 0; i < arr.length; i++) {
    const stack = [[arr[i], []]]
    res.push(Array(colMap.size).fill(""))

    while (stack.length > 0) {
      const [front, path] = stack.pop()

      if (typeof front === "object" && front !== null) {
        const keys = Object.keys(front)

        for (let j = keys.length - 1; j >= 0; j--) {
          stack.push([front[keys[j]], path.concat(keys[j])])
        }
      } else if (Array.isArray(front)) {
        for (let j = front.length - 1; j >= 0; j--) {
          stack.push([front[j], path.concat(j)])
        }
      } else {
        let pathStr = path.join('.')

        if (!colMap.has(pathStr)) {
          res[0].push(pathStr)
          colMap.set(pathStr, res[0].length - 1)

          for (let j = 1; j < res.length; j++) {
            res[j][res[0].length - 1] = ""
          }
        }

        let j = colMap.get(pathStr)
        res[i + 1][j] = front
      }
    }
  }

  return sortCols(res)
};
```

</details>

<br>

## Approach 4: Backtracking Approach

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @return {Matrix}
 */
const flattenBacktracking = (ele, path, object, columns) => {
  if (ele != null && typeof ele == "object") {
    Object.entries(ele).forEach(([key, value]) =>
      flattenBacktracking(value, path + (path ? "." : "") + key, object, columns)
    )
  } else {
    object[path] = ele
    columns.add(path)
  }
  return object
}
var jsonToMatrix = function (arr) {
  const matrix = []
  const columns = new Set()

  arr = arr.map((ele) => flattenBacktracking(ele, "", {}, columns))
  matrix.push([...columns].sort())

  const columnsIdx = matrix[0].reduce(
    (acc, cur, idx) => ((acc[cur] = idx), acc),
    {}
  )

  arr.forEach((ele) => {
    matrix.push(Array(columns.size).fill(""))
    Object.entries(ele).forEach(([key, value]) => (matrix.at(-1)[columnsIdx[key]] = value))
  })

  return matrix
};
```

</details>

<br>

## Approach 5: Using Generator Function

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr
 * @return {Matrix}
 */
function* getNestedColumn(obj, prefixes = []) {
    if (obj != null && Array.isArray(obj)) {
        for (let key = 0; key < obj.length; key += 1) {
            prefixes.push(key);
            yield* getNestedColumn(obj[key], prefixes);
            prefixes.pop()
        }
    } else if (obj != null && typeof obj === 'object') {
        for (const key of Object.keys(obj)) {
            prefixes.push(key);
            yield* getNestedColumn(obj[key], prefixes);
            prefixes.pop()
        }  
    } else if (prefixes.length > 0) {
        yield [prefixes.join('.'), obj];
    }
}

var jsonToMatrix = function(arr) {
    const output = new Array(arr.length + 1).fill(null).map(() => []);
    const rows = new Array(arr.length).fill(null).map(() => new Map());
    const uniqueColumns = new Set();
    for (let row = 0; row < arr.length; row += 1) {
        for (const [key, value] of getNestedColumn(arr[row])) {
            rows[row].set(key, value);
            uniqueColumns.add(key);
        }
    }

    const columns = [...uniqueColumns].sort();
    output[0] = columns;
    for (let row = 0; row < arr.length; row += 1) {
        for (const col of columns) {
            if (rows[row].has(col)) {
                output[row + 1].push(rows[row].get(col))
            } else {
                output[row + 1].push('')
            }
        }
    }

    return output;
};
```

</details>
