# 2722. Join Two Arrays by ID

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/join-two-arrays-by-id/)  

**Problem Link:** [LeetCode 2722 - Join Two Arrays by ID](https://leetcode.com/problems/join-two-arrays-by-id/)

## Problem

Given two arrays arr1 and arr2, return a new array joinedArray. All the objects in each of the two inputs arrays will contain an id field that has an integer value.

joinedArray is an array formed by merging arr1 and arr2 based on their id key. The length of joinedArray should be the length of unique values of id. The returned array should be sorted in ascending order based on the id key.

If a given id exists in one array but not the other, the single object with that id should be included in the result array without modification.

If two objects share an id, their properties should be merged into a single object:

- If a key only exists in one object, that single key-value pair should be included in the object.
- If a key is included in both objects, the value in the object from arr2 should override the value from arr1.

### Example 1

```text
Input:
arr1 = [
    {"id": 1, "x": 1},
    {"id": 2, "x": 9}
],
arr2 = [
    {"id": 3, "x": 5}
]
Output:
[
    {"id": 1, "x": 1},
    {"id": 2, "x": 9},
    {"id": 3, "x": 5}
]
Explanation: There are no duplicate ids so arr1 is simply concatenated with arr2.
```

### Example 2

```text
Input:
arr1 = [
    {"id": 1, "x": 2, "y": 3},
    {"id": 2, "x": 3, "y": 6}
],
arr2 = [
    {"id": 2, "x": 10, "y": 20},
    {"id": 3, "x": 0, "y": 0}
]
Output:
[
    {"id": 1, "x": 2, "y": 3},
    {"id": 2, "x": 10, "y": 20},
    {"id": 3, "x": 0, "y": 0}
]
Explanation: The two objects with id=1 and id=3 are included in the result array without modifiction. The two objects with id=2 are merged together. The keys from arr2 override the values in arr1.
```

### Example 3

```text
Input:
arr1 = [
    {"id": 1, "b": {"b": 94},"v": [4, 3], "y": 48}
]
arr2 = [
    {"id": 1, "b": {"c": 84}, "v": [1, 3]}
]
Output: [
    {"id": 1, "b": {"c": 84}, "v": [1, 3], "y": 48}
]
Explanation: The two objects with id=1 are merged together. For the keys "b" and "v" the values from arr2 are used. Since the key "y" only exists in arr1, that value is taken form arr1.
```

## Constraints

- arr1 and arr2 are valid JSON arrays
- Each object in arr1 and arr2 has a unique integer id key
- 2 <= JSON.stringify(arr1).length <= 106
- 2 <= JSON.stringify(arr2).length <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2722. Join Two Arrays by ID

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | JavaScript, TypeScript |
| Using Map | JavaScript, TypeScript |
| Using Two pointers | JavaScript, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
  const combinedArray = arr1.concat(arr2);
  const merged = {};

  combinedArray.forEach((obj) => {
    const id = obj.id;
    if (!merged[id]) {
      merged[id] = { ...obj };
    } else {
      merged[id] = { ...merged[id], ...obj };
    }
  });

  return Object.values(merged)
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function join(arr1: any[], arr2: any[]): any[] {
  const combinedArray = arr1.concat(arr2);
  const merged: { [key: number]: any } = {};

  combinedArray.forEach((obj) => {
    const id = obj.id;
    if (!merged[id]) {
      merged[id] = { ...obj };
    } else {
      merged[id] = { ...merged[id], ...obj };
    }
  });

  return Object.values(merged)
}
```

</details>

<br>

## Approach 2: Using Map

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const map = new Map();
    for(const obj of arr1) map.set(obj.id, obj);
    for(const obj of arr2) {
        if(!map.has(obj.id)) map.set(obj.id, obj);
        else {
            const prevObj = map.get(obj.id);
            for(const key of Object.keys(obj)) prevObj[key] = obj[key];
        }
    }
    const res = new Array();
    for(let key of map.keys()) res.push(map.get(key));
    return res.sort((a,b)=>a.id-b.id); 
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function join(arr1: any[], arr2: any[]): any[] {
  const map = new Map<number, any>();

  for (const obj of arr1) {
    map.set(obj.id, obj);
  }

  for (const obj of arr2) {
    if (!map.has(obj.id)) {
      map.set(obj.id, obj);
    } else {
      const prevObj = map.get(obj.id);
      for (const key of Object.keys(obj)) {
        prevObj[key] = obj[key];
      }
    }
  }

  const res: any[] = [];
  for (const key of map.keys()) {
    res.push(map.get(key));
  }

  return res.sort((a, b) => a.id - b.id);
}
```

</details>

<br>

## Approach 3: Using Two pointers

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    arr1.sort((a,b) => a.id - b.id)
    arr2.sort((a,b) => a.id - b.id)
    let i = 0
    let j = 0

    const joinedArray = []

    while(i < arr1.length && j < arr2.length) {

        if(arr1[i].id === arr2[j].id) {
            joinedArray.push({...arr1[i], ...arr2[j]})
            i++
            j++
            continue
        }

        if(arr1[i].id < arr2[j].id) {
            joinedArray.push({...arr1[i]})
            i++
            continue
        }

        joinedArray.push({...arr2[j]})
        j++
    }

    while(i < arr1.length) {
        joinedArray.push({...arr1[i]})
        i++
    }

    while(j < arr2.length) {
        joinedArray.push({...arr2[j]})
        j++
    }

    return joinedArray
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function join(arr1: any[], arr2: any[]): any[] {
  arr1.sort((a, b) => a.id - b.id);
  arr2.sort((a, b) => a.id - b.id);

  let joinedArray: any[] = [];
  let i = 0, j = 0;

  while (i < arr1.length && j < arr2.length) {
    if (arr1[i].id < arr2[j].id) {
      joinedArray.push(arr1[i]);
      i++;
    } else if (arr1[i].id > arr2[j].id) {
      joinedArray.push(arr2[j]);
      j++;
    } else {
      joinedArray.push({ ...arr1[i], ...arr2[j] });
      i++;
      j++;
    }
  }

  while (i < arr1.length) {
    joinedArray.push(arr1[i]);
    i++;
  }

  while (j < arr2.length) {
    joinedArray.push(arr2[j]);
    j++;
  }

  return joinedArray;
}
```

</details>
