# 1146. Snapshot Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/snapshot-array/)  
`Array` `Hash Table` `Binary Search` `Design`

**Problem Link:** [LeetCode 1146 - Snapshot Array](https://leetcode.com/problems/snapshot-array/)

## Problem

Implement a SnapshotArray that supports the following interface:

- SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
- void set(index, val) sets the element at the given index to be equal to val.
- int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
- int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

### Example 1

```text
Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation:
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
```

## Constraints

- 1 <= length <= 5 * 104
- 0 <= index < length
- 0 <= val <= 109
- 0 <= snap_id < (the total number of times we call snap())
- At most 5 * 104 calls will be made to set, snap, and get.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1146. Snapshot Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Binary Search | C++, Java, Python3 |

## Approach: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SnapshotArray {
public:
    int snapId;
    vector<vector<pair<int, int>>> historyRecords;
    SnapshotArray(int length) {
        snapId = 0;
        historyRecords.resize(length);
        for (int i = 0; i < length; ++i) {
            historyRecords[i].push_back(make_pair(0, 0));
        }
    }
    
    void set(int index, int val) {
        historyRecords[index].push_back(make_pair(snapId, val));
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(historyRecords[index].begin(), historyRecords[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SnapshotArray {
    int snapId = 0;
    TreeMap<Integer, Integer>[] historyRecords;
    
    public SnapshotArray(int length) {
        historyRecords = new TreeMap[length];
        for (int i = 0; i < length; i++) {
            historyRecords[i] = new TreeMap<Integer, Integer>();
            historyRecords[i].put(0, 0);
        }
    }

    public void set(int index, int val) {
        historyRecords[index].put(snapId, val);
    }

    public int snap() {
        return snapId++;
    }

    public int get(int index, int snapId) {
        return historyRecords[index].floorEntry(snapId).getValue();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class SnapshotArray:

    def __init__(self, length: int):
        self.id = 0
        self.history_records = [[[0, 0]] for _ in range(length)]
        
    def set(self, index: int, val: int) -> None:
        self.history_records[index].append([self.id, val])

    def snap(self) -> int:
        self.id += 1
        return self.id - 1

    def get(self, index: int, snap_id: int) -> int:
        snap_index = bisect.bisect_right(self.history_records[index], [snap_id, 10 ** 9])
        return self.history_records[index][snap_index - 1][1]
```

</details>
