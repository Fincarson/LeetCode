# 2622. Cache With Time Limit

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/cache-with-time-limit/)  

**Problem Link:** [LeetCode 2622 - Cache With Time Limit](https://leetcode.com/problems/cache-with-time-limit/)

## Problem

Write a class that allows getting and setting key-value pairs, however a time until expiration is associated with each key.

The class has three public methods:

set(key, value, duration): accepts an integer key, an integer value, and a duration in milliseconds. Once the duration has elapsed, the key should be inaccessible. The method should return true if the same un-expired key already exists and false otherwise. Both the value and duration should be overwritten if the key already exists.

get(key): if an un-expired key exists, it should return the associated value. Otherwise it should return -1.

count(): returns the count of un-expired keys.

### Example 1

```text
Input:
actions = ["TimeLimitedCache", "set", "get", "count", "get"]
values = [[], [1, 42, 100], [1], [], [1]]
timeDelays = [0, 0, 50, 50, 150]
Output: [null, false, 42, 1, -1]
Explanation:
At t=0, the cache is constructed.
At t=0, a key-value pair (1: 42) is added with a time limit of 100ms. The value doesn't exist so false is returned.
At t=50, key=1 is requested and the value of 42 is returned.
At t=50, count() is called and there is one active key in the cache.
At t=100, key=1 expires.
At t=150, get(1) is called but -1 is returned because the cache is empty.
```

### Example 2

```text
Input:
actions = ["TimeLimitedCache", "set", "set", "get", "get", "get", "count"]
values = [[], [1, 42, 50], [1, 50, 100], [1], [1], [1], []]
timeDelays = [0, 0, 40, 50, 120, 200, 250]
Output: [null, false, true, 50, 50, -1, 0]
Explanation:
At t=0, the cache is constructed.
At t=0, a key-value pair (1: 42) is added with a time limit of 50ms. The value doesn't exist so false is returned.
At t=40, a key-value pair (1: 50) is added with a time limit of 100ms. A non-expired value already existed so true is returned and the old value was overwritten.
At t=50, get(1) is called which returned 50.
At t=120, get(1) is called which returned 50.
At t=140, key=1 expires.
At t=200, get(1) is called but the cache is empty so -1 is returned.
At t=250, count() returns 0 because the cache is empty.
```

## Constraints

- 0 <= key, value <= 109
- 0 <= duration <= 1000
- 1 <= actions.length <= 100
- actions.length === values.length
- actions.length === timeDelays.length
- 0 <= timeDelays[i] <= 1450
- actions[i] is one of "TimeLimitedCache", "set", "get" and "count"
- First action is always "TimeLimitedCache" and must be executed immediately, with a 0-millisecond delay

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Debounce](https://leetcode.com/problems/debounce/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Promise Time Limit](https://leetcode.com/problems/promise-time-limit/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Promise Pool](https://leetcode.com/problems/promise-pool/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2622. Cache With Time Limit

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| setTimeout + clearTimeout + Class Syntax | JavaScript, TypeScript |
| setTimeout + clearTimeout + Function Syntax | JavaScript, TypeScript |
| Maintain Expiration Times | JavaScript, TypeScript |
| Maintain Expiration Times + Priority Queue | JavaScript, TypeScript |

## Approach 1: setTimeout + clearTimeout + Class Syntax

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class TimeLimitedCache {
  cache = new Map();

  set(key, value, duration) {
    const valueInCache = this.cache.get(key);
    if (valueInCache) {
      clearTimeout(valueInCache.timeout);
    }
    const timeout = setTimeout(() => this.cache.delete(key), duration);
    this.cache.set(key, { value, timeout });
    return Boolean(valueInCache);
  }

  get(key) {
    return this.cache.has(key) ? this.cache.get(key).value : -1;
  }

  count() {
    return this.cache.size;
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type MapEntry = { value: number, timeout: NodeJS.Timeout };

class TimeLimitedCache {
  cache = new Map<number, MapEntry>();

  set(key: number, value: number, duration: number) {
    const valueInCache = this.cache.get(key);
    if (valueInCache) {
      clearTimeout(valueInCache.timeout);
    }
    const timeout = setTimeout(() => this.cache.delete(key), duration);
    this.cache.set(key, { value, timeout });
    return Boolean(valueInCache);
  }

  get(key: number) {
    return this.cache.has(key) ? this.cache.get(key).value : -1;
  }

  count() {
    return this.cache.size;
  }
};
```

</details>

<br>

## Approach 2: setTimeout + clearTimeout + Function Syntax

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function TimeLimitedCache() {
  this.cache = new Map();
}

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const valueInCache = this.cache.get(key);
    if (valueInCache) {
      clearTimeout(valueInCache.timeout);
    }
    const timeout = setTimeout(() => this.cache.delete(key), duration);
    this.cache.set(key, { value, timeout });
    return Boolean(valueInCache);
}

TimeLimitedCache.prototype.get = function(key) {
    return this.cache.has(key) ? this.cache.get(key).value : -1;
}

TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Note that function syntax does not play well with type safety
 * use classes instead
 */
function TimeLimitedCache() {
  this.cache = new Map();
}

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const valueInCache = this.cache.get(key);
    if (valueInCache) {
      clearTimeout(valueInCache.timeout);
    }
    const timeout = setTimeout(() => this.cache.delete(key), duration);
    this.cache.set(key, { value, timeout });
    return Boolean(valueInCache);
}

TimeLimitedCache.prototype.get = function(key) {
    return this.cache.has(key) ? this.cache.get(key).value : -1;
}

TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
}
```

</details>

<br>

## Approach 3: Maintain Expiration Times

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class TimeLimitedCache {
  cache = {};

  set(key, value, duration) {
    const hasUnexpiredValue = key in this.cache && Date.now() < this.cache[key].expiration;
    this.cache[key] = { value, expiration: Date.now() + duration };
    return hasUnexpiredValue;
  }

  get(key) {
    if (this.cache[key] === undefined) return -1;
    if (Date.now() > this.cache[key].expiration) return -1;
    return this.cache[key].value;
  }

  count() {
    let count = 0;
    for (const entry of Object.values(this.cache)) {
        if (Date.now() < entry.expiration) {
            count += 1;
        }
    }
    return count;
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Entry = { value: number, expiration: number };

class TimeLimitedCache {
  cache: Record<string, Entry> = {};

  set(key: number, value: number, duration: number) {
    const hasUnexpiredValue = key in this.cache && Date.now() < this.cache[key].expiration;
    this.cache[key] = { value, expiration: Date.now() + duration };
    return hasUnexpiredValue;
  }

  get(key: number) {
    if (this.cache[key] === undefined) return -1;
    if (Date.now() > this.cache[key].expiration) return -1;
    return this.cache[key].value;
  }

  count() {
    let count = 0;
    for (const entry of Object.values(this.cache)) {
        if (Date.now() < entry.expiration) {
            count += 1;
        }
    }
    return count;
  }
};
```

</details>

<br>

## Approach 4: Maintain Expiration Times + Priority Queue

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class TimeLimitedCache {
  cache = {};
  queue = new MinPriorityQueue();
  size = 0;

  handleExpiredData() {
    const now = Date.now();
    while (this.queue.size() > 0 && this.queue.front().priority < now) {
      const entry = this.queue.dequeue().element;
      if (!entry.overwritten) {
        delete this.cache[entry.key];
        this.size -= 1;
      }
    }
  };

  set(key, value, duration) {
    this.handleExpiredData();
    const hasVal = key in this.cache
    if (hasVal) {
      this.cache[key].overwritten = true
    } else {
      this.size += 1;
    }
    const expiration = Date.now() + duration;
    const entry = { key, value, expiration, overwritten: false }
    this.cache[key] = entry
    this.queue.enqueue(entry, expiration);
    return hasVal;
  }

  get(key) {
    this.handleExpiredData();
    if (this.cache[key] === undefined) return -1;
    return this.cache[key].value;
  }

  count() {
    this.handleExpiredData();
    return this.size;
  }
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
type Entry = {
  key: number,
  value: number,
  expiration: number,
  overwritten: boolean,
};

class TimeLimitedCache {
  cache: Record<string, Entry> = {};
  queue = new MinPriorityQueue();
  size = 0;

  handleExpiredData() {
    const now = Date.now();
    while (this.queue.size() > 0 && this.queue.front().priority < now) {
      const entry = this.queue.dequeue().element;
      if (!entry.overwritten) {
        delete this.cache[entry.key];
        this.size -= 1;
      }
    }
  };

  set(key: number, value: number, duration: number) {
    this.handleExpiredData();
    const hasVal = key in this.cache
    if (hasVal) {
      this.cache[key].overwritten = true
    } else {
      this.size += 1;
    }
    const expiration = Date.now() + duration;
    const entry: Entry = { key, value, expiration, overwritten: false }
    this.cache[key] = entry
    this.queue.enqueue(entry, expiration);
    return hasVal;
  }

  get(key: number) {
    this.handleExpiredData();
    if (this.cache[key] === undefined) return -1;
    return this.cache[key].value;
  }

  count() {
    this.handleExpiredData();
    return this.size;
  }
};
```

</details>
