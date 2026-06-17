# 1338. Reduce Array Size to The Half

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reduce-array-size-to-the-half/)  
`Array` `Hash Table` `Greedy` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1338 - Reduce Array Size to The Half](https://leetcode.com/problems/reduce-array-size-to-the-half/)

## Problem

You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

### Example 1

```text
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
```

### Example 2

```text
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
```

## Constraints

- 2 <= arr.length <= 105
- arr.length is even.
- 1 <= arr[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1338. Reduce Array Size to The Half

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | Java, JavaScript, Python |
| Hashing/ Counting | Java, JavaScript, Python |
| Hashing and Bucket Sort | Java, JavaScript, Python |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minSetSize(int[] arr) {
        
        // Sort the input numbers.
        Arrays.sort(arr);
        
        // Make the List of Counts
        List<Integer> counts = new ArrayList<>();
        int currentRun = 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i - 1]) {
                currentRun += 1;
                continue;
            }
            counts.add(currentRun);
            currentRun = 1;
        }
        counts.add(currentRun);
        
        Collections.sort(counts);
        Collections.reverse(counts);
        
        // Remove numbers until at least half are removed.
        int numbersRemovedFromArr = 0;
        int setSize = 0;
        for (int count : counts) {
            numbersRemovedFromArr += count;
            setSize += 1;   
            if (numbersRemovedFromArr >= arr.length / 2) {
                break;
            }
        }
        
        return setSize;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minSetSize = function(arr) {
    arr.sort((a, b) => a - b);

    const counts = [];
    let currentRun = 1;

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] === arr[i - 1]) {
            currentRun += 1;
            continue;
        }
        counts.push(currentRun);
        currentRun = 1;
    }

    counts.push(currentRun);

    // Reverse sort counts
    counts.sort((a, b) => b - a);

    let numberOfItemsRemovedFromArr = 0;
    let setSize = 0;

    for (const count of counts) {
        numberOfItemsRemovedFromArr += count;
        setSize += 1;
        if (numberOfItemsRemovedFromArr >= arr.length / 2) {
            break;
        }
    }

    return setSize;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def minSetSize(self, arr: List[int]) -> int:
        
    # Sort the input numbers.
    arr.sort()

    # Generate the counts array.
    counts = []
    current_run = 1
    for i in range(1, len(arr)):
        if arr[i] == arr[i - 1]:
            current_run += 1
            continue
        counts.append(current_run)
        current_run = 1
    counts.append(current_run)

    # Reverse sort the counts.
    counts.sort(reverse=True)

    # Remove numbers until at least half are removed.
    numbers_removed_from_arr = 0
    set_size = 0
    for count in counts:
        numbers_removed_from_arr += count
        set_size += 1
        if (numbers_removed_from_arr >= len(arr) // 2):
            break
    
    return set_size
```

</details>

<br>

## Approach 2: Hashing/ Counting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minSetSize(int[] arr) {
        
        // Do the counting with a HashMap.
        Map<Integer, Integer> countsMap = new HashMap<>();
        for (int num : arr) {
            if (!countsMap.containsKey(num)) {
                countsMap.put(num, 1);
                continue;
            }
            countsMap.put(num, countsMap.get(num) + 1);
        }
        
        // Reverse sort a list of the Map values.
        List<Integer> counts = new ArrayList<>(countsMap.values());
        Collections.sort(counts);
        Collections.reverse(counts);
        
        // Remove numbers until at least half are removed.
        int numbersRemovedFromArr = 0;
        int setSize = 0;
        for (int count : counts) {
            numbersRemovedFromArr += count;
            setSize += 1;   
            if (numbersRemovedFromArr >= arr.length / 2) {
                break;
            }
        }
        
        return setSize;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Counter {
    static from(array) {
        const counter = new Counter();
        for (const item of array) {
            counter.add(item);
        }
        return counter;
    }

    _counts = new Map();

    add(item) {
        if (!this._counts.has(item)) {
            this._counts.set(item, 0);
        }
        this._counts.set(item, this._counts.get(item) + 1);
    }

    values() {
        return this._counts.values();
    }
}

/**
 * @param {number[]} arr
 * @return {number}
 */
var minSetSize = function(arr) {
    const counter = Counter.from(arr);

    const counts = Array.from(counter.values())
        .sort((a, b) => b - a); // Largest to smallest

    let numberOfItemsRemovedFromArr = 0;
    let setSize = 0;
    
    for (const count of counts) {
        numberOfItemsRemovedFromArr += count;
        setSize += 1;
        if (numberOfItemsRemovedFromArr >= arr.length / 2) {
            break;
        }
    }
    
    return setSize;
};
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def minSetSize(self, arr: List[int]) -> int:
        
    # In Python, we can use the built-in Counter class.
    counts = collections.Counter(arr)

    # Extract the counts in reverse-sorted order.
    # most_common gives (number, count) pairs, reverse sorted on count.
    counts = [count for number, count in counts.most_common()]

    # Remove numbers until at least half are removed.
    total_removed = 0
    set_size = 0
    for count in counts:
        total_removed += count
        set_size += 1
        if (total_removed >= len(arr) // 2):
            break
    
    return set_size
```

</details>

<br>

## Approach 3: Hashing and Bucket Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minSetSize(int[] arr) {
        
        Map<Integer, Integer> counts = new HashMap<>();
        int maxCount = 0;
        for (int num : arr) {
            if (!counts.containsKey(num)) {
                counts.put(num, 0);
            }
            int newCount = counts.get(num) + 1;
            counts.put(num, newCount);
            maxCount = Math.max(maxCount, newCount);
        }
        
        // Put the counts into buckets.
        int[] buckets = new int[maxCount + 1];
        for (int count : counts.values()) {
            buckets[count]++;
        }


        // Determine setSize.
        int setSize = 0;
        int numbersToRemoveFromArr = arr.length / 2;
        int bucket = maxCount;
        while (numbersToRemoveFromArr > 0) {
            int maxNeededFromBucket = numbersToRemoveFromArr / bucket;
            if (numbersToRemoveFromArr % bucket != 0) {
                maxNeededFromBucket++;
            }
            int setSizeIncrease = Math.min(buckets[bucket], maxNeededFromBucket);
            setSize += setSizeIncrease;
            numbersToRemoveFromArr -= setSizeIncrease * bucket;
            bucket--;
        }
        return setSize;        
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript

// written by @jamesernator (James Browning)

class Counter {
    _counts = new Map();

    add(item) {
        if (!this._counts.has(item)) {
            this._counts.set(item, 0);
        }
        this._counts.set(item, this._counts.get(item) + 1);
        return this._counts.get(item);
    }

    values() {
        return this._counts.values();
    }
}

var minSetSize = function(arr) {
    const counts = new Counter();
        
    let maxCount = 0;
    for (const value of arr) {
        const newCount = counts.add(value);
        maxCount = Math.max(newCount, maxCount);
    }
    
    if (maxCount > arr.length / 2) {
        return 1;
    }

    // Allocate an array of size maxCount + 1, pre-filling each value to 0
    const buckets = Array.from({ length: maxCount + 1 }, () => 0);

    for (const count of counts.values()) {
        buckets[count] += 1;
    }

    let setSize = 0;
    let numberToRemove = Math.floor(arr.length / 2);
    let currentBucket = maxCount;

    while (numberToRemove > 0) {
        const numberWantedFromCurrentBucket = Math.ceil(numberToRemove / currentBucket);
        const setSizeIncrease = Math.min(buckets[currentBucket], numberWantedFromCurrentBucket);
        setSize += setSizeIncrease;
        numberToRemove -= setSizeIncrease * currentBucket;
        currentBucket -= 1;
    }

    return setSize;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def minSetSize(self, arr: List[int]) -> int:
        
    # In Python, we can use the built-in Counter class.
    counts = collections.Counter(arr)
    max_value = max(counts.values())
            
    # Put the counts into buckets.
    buckets = [0] * (max_value + 1)
    
    for count in counts.values():
        buckets[count] += 1
        
    # Determine set_size.
    set_size = 0
    arr_numbers_to_remove = len(arr) // 2
    bucket = max_value
    while arr_numbers_to_remove > 0:
        max_needed_from_bucket = math.ceil(arr_numbers_to_remove / bucket)
        set_size_increase = min(buckets[bucket], max_needed_from_bucket)
        set_size += set_size_increase
        arr_numbers_to_remove -= set_size_increase * bucket
        bucket -= 1
        
    return set_size
```

</details>
