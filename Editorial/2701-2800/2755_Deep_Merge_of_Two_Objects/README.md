# 2755. Deep Merge of Two Objects

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/deep-merge-of-two-objects/)  

**Problem Link:** [LeetCode 2755 - Deep Merge of Two Objects](https://leetcode.com/problems/deep-merge-of-two-objects/)

## Problem

Given two values obj1 and obj2, return a deepmerged value.

Values should be deepmerged according to these rules:

- If the two values are objects, the resulting object should have all the keys that exist on either object. If a key belongs to both objects, deepmerge the two associated values. Otherwise, add the key-value pair to the resulting object.
- If the two values are arrays, the resulting array should be the same length as the longer array. Apply the same logic as you would with objects, but treat the indices as keys.
- Otherwise the resulting value is obj2.

You can assume obj1 and obj2 are the output of JSON.parse().

### Example 1

```text
Input: obj1 = {"a": 1, "c": 3}, obj2 = {"a": 2, "b": 2}
Output: {"a": 2, "c": 3, "b": 2}
Explanation: The value of obj1["a"] changed to 2 because if both objects have the same key and their value is not an array or object then we change the obj1 value to the obj2 value. Key "b" with value was added to obj1 as it doesn't exist in obj1.
```

### Example 2

```text
Input: obj1 = [{}, 2, 3], obj2 = [[], 5]
Output: [[], 5, 3]
Explanation: result[0] = obj2[0] because obj1[0] and obj2[0] have different types. result[2] = obj1[2] because obj2[2] does not exist.
```

### Example 3

```text
Input:
obj1 = {"a": 1, "b": {"c": [1 , [2, 7], 5], "d": 2}},
obj2 = {"a": 1, "b": {"c": [6, [6], [9]], "e": 3}}
Output: {"a": 1, "b": {"c": [6, [6, 7], [9]], "d": 2, "e": 3}}
Explanation:
Arrays obj1["b"]["c"] and obj2["b"]["c"] have been merged in way that obj2 values overwrite obj1 values deeply only if they are not arrays or objects.
obj2["b"]["c"] has key "e" that obj1 doesn't have so it's added to obj1.
```

### Example 4

```text
Input: obj1 = true, obj2 = null
Output: null
```

## Constraints

- obj1 and obj2 are valid JSON values
- 1 <= JSON.stringify(obj1).length <= 5 * 105
- 1 <= JSON.stringify(obj2).length <= 5 * 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2755. Deep Merge of Two Objects

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search (DFS) for Deep Merging | JavaScript, TypeScript |

## Approach 1: Depth First Search (DFS) for Deep Merging

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var deepMerge = function(obj1, obj2) {
  function dfs(currNode1, currNode2) {
    // If the first value is not an object or is null, return the second value 
    // as according to the description, the second object overwrites the first
    if (currNode1 === null || typeof currNode1 !== 'object') {
      return currNode2;
    }

    // If currNode1 is an array
    if (Array.isArray(currNode1)) {
      // If currNode2 isn't an array, return currNode2
      if (!Array.isArray(currNode2)) return currNode2;

      // Initialize a new array with the length of the longer of the two arrays
      const newArr = new Array(Math.max(currNode1.length, currNode2.length));

      for (let i = 0; i < currNode1.length; i++) {
        // If the current index exists in currNode1 but not in currNode2,
        // directly copy the value from currNode1 to the merged array
        if (i > currNode2.length - 1) {
          newArr[i] = currNode1[i];
          continue;
        }
        
        // Deep merge common indices
        newArr[i] = dfs(currNode1[i], currNode2[i]);
      }

      // If currNode2 is longer, add the extra elements from currNode2 to newArr
      if (currNode2.length > currNode1.length) {
        for (let i = currNode1.length; i < currNode2.length; i++) {
          newArr[i] = currNode2[i];
        }
      }

      return newArr;
    }

    // If currNode1 is an object but currNode2 isn't, return currNode2
    if (typeof currNode1 === 'object' && (Array.isArray(currNode2) || currNode2 === null || typeof currNode2 !== 'object')) {
      return currNode2;
    }

    // If both currNode1 and currNode2 are objects
    const newObj = {};

    for (const key in currNode1) {
      // If the current key exists in currNode1 but not in currNode2,
      // directly copy the key-value pair from currNode1 to the merged object
      if (!(key in currNode2)) {
        newObj[key] = currNode1[key];
        continue;
      }
      
      // Deep merge common keys
      newObj[key] = dfs(currNode1[key], currNode2[key]);
    }

    // Add keys that only exist in currNode2
    for (const key in currNode2) {
      if (!(key in currNode1)) {
        newObj[key] = currNode2[key];
      }
    }

    return newObj;
  }

  return dfs(obj1, obj2);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };

function deepMerge(obj1: JSONValue, obj2: JSONValue): JSONValue {
    function dfs(currNode1: JSONValue, currNode2: JSONValue): JSONValue {
        // If the first value is not an object or is null, return the second value 
        // as according to the description, the second object overwrites the first
        if (currNode1 === null || typeof currNode1 !== 'object') {
            return currNode2;
        }

        // If currNode1 is an array
        if (Array.isArray(currNode1)) {
            // If currNode2 isn't an array, return currNode2
            if (!Array.isArray(currNode2)) return currNode2;

            // Initialize a new array with the length of the longer of the two arrays
            const newArr: JSONValue[] = new Array(Math.max(currNode1.length, (currNode2 as JSONValue[]).length));

            for (let i = 0; i < currNode1.length; i++) {
                // If the current index exists in currNode1 but not in currNode2,
                // directly copy the value from currNode1 to the merged array
                if (i > (currNode2 as JSONValue[]).length - 1) {
                    newArr[i] = currNode1[i];
                    continue;
                }

                // Deep merge common indices
                newArr[i] = dfs(currNode1[i], (currNode2 as JSONValue[])[i]);
            }

            // If currNode2 is longer, add the extra elements from currNode2 to newArr
            if ((currNode2 as JSONValue[]).length > currNode1.length) {
                for (let i = currNode1.length; i < (currNode2 as JSONValue[]).length; i++) {
                    newArr[i] = (currNode2 as JSONValue[])[i];
                }
            }

            return newArr;
        }

        // If currNode1 is an object but currNode2 isn't, return currNode2
        if (typeof currNode1 === 'object' && (Array.isArray(currNode2) || currNode2 === null || typeof currNode2 !== 'object')) {
            return currNode2;
        }

        // If both currNode1 and currNode2 are objects
        const newObj: { [key: string]: JSONValue } = {};

        for (const key in currNode1 as { [key: string]: JSONValue }) {
            // If the current key exists in currNode1 but not in currNode2,
            // directly copy the key-value pair from currNode1 to the merged object
            if (!(key in (currNode2 as { [key: string]: JSONValue }))) {
                newObj[key] = (currNode1 as { [key: string]: JSONValue })[key];
                continue;
            }

            // Deep merge common keys
            newObj[key] = dfs((currNode1 as { [key: string]: JSONValue })[key], (currNode2 as { [key: string]: JSONValue })[key]);
        }

        for (const key in currNode2 as { [key: string]: JSONValue }) {
            if (!(key in (currNode1 as { [key: string]: JSONValue }))) {
                newObj[key] = (currNode2 as { [key: string]: JSONValue })[key];
            }
        }

        return newObj;
    }

    return dfs(obj1, obj2);
}
```

</details>
