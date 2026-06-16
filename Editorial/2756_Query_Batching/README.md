# 2756. Query Batching

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/query-batching/)  

**Problem Link:** [LeetCode 2756 - Query Batching](https://leetcode.com/problems/query-batching/)

## Problem

Batching multiple small queries into a single large query can be a useful optimization. Write a class QueryBatcher that implements this functionality.

The constructor should accept two parameters:

- An asynchronous function queryMultiple which accepts an array of string keys input. It will resolve with an array of values that is the same length as the input array. Each index corresponds to the value associated with input[i]. You can assume the promise will never reject.
- A throttle time in milliseconds t.

The class has a single method.

- async getValue(key). Accepts a single string key and resolves with a single string value. The keys passed to this function should eventually get passed to the queryMultiple function. queryMultiple should never be called consecutively within t milliseconds. The first time getValue is called, queryMultiple should immediately be called with that single key. If after t milliseconds, getValue had been called again, all the passed keys should be passed to queryMultiple and ultimately returned. You can assume every key passed to this method is unique.

The following diagram illustrates how the throttling algorithm works. Each rectangle represents 100ms. The throttle time is 400ms.

### Example 1

```text
Input:
queryMultiple = async function(keys) {
  return keys.map(key => key + '!');
}
t = 100
calls = [
 {"key": "a", "time": 10},
 {"key": "b", "time": 20},
 {"key": "c", "time": 30}
]
Output: [
 {"resolved": "a!", "time": 10},
 {"resolved": "b!", "time": 110},
 {"resolved": "c!", "time": 110}
]
Explanation:
const batcher = new QueryBatcher(queryMultiple, 100);
setTimeout(() => batcher.getValue('a'), 10); // "a!" at t=10ms
setTimeout(() => batcher.getValue('b'), 20); // "b!" at t=110ms
setTimeout(() => batcher.getValue('c'), 30); // "c!" at t=110ms

queryMultiple simply adds an "!" to the key
At t=10ms, getValue('a') is called, queryMultiple(['a']) is immediately called and the result is immediately returned.
At t=20ms, getValue('b') is called but the query is queued
At t=30ms, getValue('c') is called but the query is queued.
At t=110ms, queryMultiple(['a', 'b']) is called and the results are immediately returned.
```

### Example 2

```text
Input:
queryMultiple = async function(keys) {
  await new Promise(res => setTimeout(res, 100));
  return keys.map(key => key + '!');
}
t = 100
calls = [
 {"key": "a", "time": 10},
 {"key": "b", "time": 20},
 {"key": "c", "time": 30}
]
Output: [
  {"resolved": "a!", "time": 110},
  {"resolved": "b!", "time": 210},
  {"resolved": "c!", "time": 210}
]
Explanation:
This example is the same as example 1 except there is a 100ms delay in queryMultiple. The results are the same except the promises resolve 100ms later.
```

### Example 3

```text
Input:
queryMultiple = async function(keys) {
  await new Promise(res => setTimeout(res, keys.length * 100));
  return keys.map(key => key + '!');
}
t = 100
calls = [
  {"key": "a", "time": 10},
  {"key": "b", "time": 20},
  {"key": "c", "time": 30},
  {"key": "d", "time": 40},
  {"key": "e", "time": 250}
  {"key": "f", "time": 300}
]
Output: [
  {"resolved":"a!","time":110},
  {"resolved":"e!","time":350},
  {"resolved":"b!","time":410},
  {"resolved":"c!","time":410},
  {"resolved":"d!","time":410},
  {"resolved":"f!","time":450}
]
Explanation:
queryMultiple(['a']) is called at t=10ms, it is resolved at t=110ms
queryMultiple(['b', 'c', 'd']) is called at t=110ms, it is resolved at 410ms
queryMultiple(['e']) is called at t=250ms, it is resolved at 350ms
queryMultiple(['f']) is called at t=350ms, it is resolved at 450ms
```

## Constraints

- 0 <= t <= 1000
- 0 <= calls.length <= 10
- 1 <= key.length <= 100
- All keys are unique

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2756. Query Batching

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Batching Queries with Throttle Time | JavaScript, TypeScript |

## Approach 1: Batching Queries with Throttle Time

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var QueryBatcher = function(queryMultiple, t) {
  this.queryMultiple = queryMultiple;
  this.t = t;
  this.isAvailable = true;  // Flag to indicate if the batcher can immediately process a query
  this.stashed = [];  // Temporary storage for queries arriving during a throttle time
};

QueryBatcher.prototype.getValue = function(key) {
  return new Promise((resolve) => {
    if (this.isAvailable) {
      this.isAvailable = false;
      this.queryMultiple([key]).then(results => resolve(results[0]));
      this.cooldown();  // Start the throttle time
      return;
    }
    // If the batcher is not available, stash the query for later processing
    this.stashed.push({ key, resolve });
  });
};

QueryBatcher.prototype.cooldown = function() {
  setTimeout(() => {
    // If no stashed queries exist after the throttle time, set the batcher as available
    if (this.stashed.length === 0) {
      this.isAvailable = true;
      return;
    }

    // Prepare the stashed keys for batching and keep the resolve functions for later
    const keysToQuery = this.stashed.map(item => item.key);
    const resolvers = this.stashed.map(item => item.resolve);

    // Clear the stashed queries as they are about to be processed
    this.stashed = [];

    // Process the batched queries and return results to the respective callers
    this.queryMultiple(keysToQuery)
      .then(results => {
        resolvers.forEach((resolve, idx) => {
          resolve(results[idx]);
        });
      });

    // Start another cooldown for the next batch
    this.cooldown();
  }, this.t);
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript

type QueryMultiple = (keys: string[]) => Promise<string[]>;

class QueryBatcher {
    private queryMultiple: QueryMultiple;
    private t: number;
    private isAvailable: boolean;
    private stashed: Array<{ key: string, resolve: (value: string) => void }>;

    constructor(queryMultiple: QueryMultiple, t: number) {
        this.queryMultiple = queryMultiple;
        this.t = t;
        this.isAvailable = true;  // Flag to indicate if the batcher can immediately process a query
        this.stashed = [];  // Temporary storage for queries arriving during a throttle time
    }

    async getValue(key: string): Promise<string> {
        return new Promise((resolve) => {
            if (this.isAvailable) {
                // If the batcher is available, process the query immediately
                this.isAvailable = false;
                this.queryMultiple([key]).then(results => resolve(results[0]));
                this.cooldown();  // Start the throttle time
                return;
            }
            // If the batcher is not available, stash the query for later processing
            this.stashed.push({ key, resolve });
        });
    }

    private cooldown(): void {
        setTimeout(() => {
            // If no stashed queries exist after the throttle time, set the batcher as available
            if (this.stashed.length === 0) {
                this.isAvailable = true;
                return;
            }

            // Prepare the stashed keys for batching and keep the resolve functions for later
            const keysToQuery = this.stashed.map(item => item.key);
            const resolvers = this.stashed.map(item => item.resolve);

            // Clear the stashed queries as they are about to be processed
            this.stashed = [];

            // Process the batched queries and return results to the respective callers
            this.queryMultiple(keysToQuery)
                .then(results => {
                    resolvers.forEach((resolve, idx) => {
                        resolve(results[idx]);
                    });
                });

            // Start another cooldown for the next batch
            this.cooldown();
        }, this.t);
    }
}
```

</details>
