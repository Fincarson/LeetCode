# 57. Insert Interval

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/insert-interval/)  
`Array`

**Problem Link:** [LeetCode 57 - Insert Interval](https://leetcode.com/problems/insert-interval/)

## Problem

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

### Example 1

```text
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

### Example 2

```text
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

## Constraints

- 0 <= intervals.length <= 104
- intervals[i].length == 2
- 0 <= starti <= endi <= 105
- intervals is sorted by starti in ascending order.
- newInterval.length == 2
- 0 <= start <= end <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Range Module](https://leetcode.com/problems/range-module/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 57. Insert Interval

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Linear Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize, int* returnSize,
             int** returnColumnSizes) {
    *returnSize = 0;
    int i = 0, j = 0;
    int** res = malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));

    // Case 1: No overlapping before merging intervals
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        res[j] = intervals[i++];
        (*returnColumnSizes)[j++] = 2;
    }

    // Case 2: Overlapping and merging intervals
    while (i < intervalsSize && newInterval[1] >= intervals[i][0]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }
    res[j] = newInterval;
    (*returnColumnSizes)[j++] = 2;

    // Case 3: No overlapping after merging newInterval
    while (i < intervalsSize) {
        res[j] = intervals[i++];
        (*returnColumnSizes)[j++] = 2;
    }
    *returnSize = j;

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        // Case 1: no overlapping case before the merge intervals
        // Compare ending point of intervals to starting point of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Case 2: overlapping case and merging of intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Case 3: no overlapping of intervals after newinterval being merged
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        int n = intervals.Length, i = 0;
        List<int[]> res = new List<int[]>();

        // Case 1: No overlapping before merging intervals
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.Add(intervals[i]);
            i++;
        }

        // Case 2: Overlapping and merging intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = Math.Min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.Max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.Add(newInterval);

        // Case 3: No overlapping after merging newInterval
        while (i < n) {
            res.Add(intervals[i]);
            i++;
        }

        return res.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func insert(intervals [][]int, newInterval []int) [][]int {
    n := len(intervals)
    i := 0
    res := make([][]int, 0)

    // Case 1: No overlapping before merging intervals
    for i < n && intervals[i][1] < newInterval[0] {
        res = append(res, intervals[i])
        i++
    }

    // Case 2: Overlapping and merging intervals
    for i < n && newInterval[1] >= intervals[i][0] {
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        i++
    }
    res = append(res, newInterval)

    // Case 3: No overlapping after merging newInterval
    for i < n {
        res = append(res, intervals[i])
        i++
    }

    return res
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length, i = 0;
        List<int[]> res = new ArrayList<>();

        // Case 1: No overlapping before merging intervals
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.add(intervals[i]);
            i++;
        }

        // Case 2: Overlapping and merging intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.add(newInterval);

        // Case 3: No overlapping after merging newInterval
        while (i < n) {
            res.add(intervals[i]);
            i++;
        }

        // Convert List to array
        return res.toArray(new int[res.size()][]);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var insert = function (intervals, newInterval) {
    let n = intervals.length,
        i = 0,
        res = [];

    // Case 1: No overlapping before merging intervals
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push(intervals[i]);
        i++;
    }

    // Case 2: Overlapping and merging intervals
    while (i < n && newInterval[1] >= intervals[i][0]) {
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push(newInterval);

    // Case 3: No overlapping after merging newInterval
    while (i < n) {
        res.push(intervals[i]);
        i++;
    }

    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        n = len(intervals)
        i = 0
        res = []

        # Case 1: No overlapping before merging intervals
        while i < n and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1

        # Case 2: Overlapping and merging intervals
        while i < n and newInterval[1] >= intervals[i][0]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
        res.append(newInterval)

        # Case 3: No overlapping after merging newInterval
        while i < n:
            res.append(intervals[i])
            i += 1

        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function insert(intervals: number[][], newInterval: number[]): number[][] {
    let n = intervals.length,
        i = 0,
        res = [];

    // Case 1: No overlapping before merging intervals
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push(intervals[i]);
        i++;
    }

    // Case 2: Overlapping and merging intervals
    while (i < n && newInterval[1] >= intervals[i][0]) {
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push(newInterval);

    // Case 3: No overlapping after merging newInterval
    while (i < n) {
        res.push(intervals[i]);
        i++;
    }

    return res;
}
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// struct for list node
typedef struct list_node {
    int interval[2];
    struct list_node* next;
} list_node;

int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize, int* returnSize,
             int** returnColumnSizes) {
    // If the intervals vector is empty, return a vector containing the
    // newInterval
    if (intervalsSize == 0) {
        *returnSize = 1, *returnColumnSizes = malloc(sizeof(int));
        **returnColumnSizes = 2;
        int** ans = malloc(sizeof(int*));
        *ans = malloc(2 * sizeof(int));
        memcpy(*ans, newInterval, 2 * sizeof(int));
        return ans;
    }

    int n = intervalsSize;
    int target = newInterval[0];
    int left = 0, right = n - 1;

    // Binary search to find the position to insert newInterval
    while (left <= right) {
        int mid = (left + right) / 2;
        if (intervals[mid][0] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Insert newInterval at the found position
    list_node* head = NULL;
    list_node** next_ptr = &head;
    for (int i = 0; i < left; ++i) {
        *next_ptr = malloc(sizeof(list_node));
        (*next_ptr)->next = NULL;
        memcpy((*next_ptr)->interval, intervals[i], 2 * sizeof(int));
        next_ptr = &((*next_ptr)->next);
    }
    *next_ptr = malloc(sizeof(list_node));
    (*next_ptr)->next = NULL;
    memcpy((*next_ptr)->interval, newInterval, 2 * sizeof(int));
    next_ptr = &((*next_ptr)->next);
    for (int i = left; i < n; ++i) {
        *next_ptr = malloc(sizeof(list_node));
        (*next_ptr)->next = NULL;
        memcpy((*next_ptr)->interval, intervals[i], 2 * sizeof(int));
        next_ptr = &((*next_ptr)->next);
    }

    // Merge overlapping intervals
    int** res_data = malloc(1001 * sizeof(int*));
    int* res_sizes = malloc(1001 * sizeof(int));
    int res_size = 0;
    for (list_node* node = head; node != NULL; node = node->next) {
        int* interval = node->interval;
        // If res is empty or there is no overlap, add the interval to the
        // result
        if (res_size == 0 || res_data[res_size - 1][1] < interval[0]) {
            res_data[res_size] = malloc(2 * sizeof(int));
            memcpy(res_data[res_size], interval, 2 * sizeof(int));
            res_sizes[res_size] = 2;
            ++res_size;
            // If there is an overlap, merge the intervals by updating the end
            // of the last interval in res
        } else {
            res_data[res_size - 1][1] =
                (res_data[res_size - 1][1] < interval[1])
                    ? interval[1]
                    : res_data[res_size - 1][1];
        }
    }
    *returnSize = res_size, *returnColumnSizes = res_sizes;

    return res_data;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        // If the intervals vector is empty, return a vector containing the
        // newInterval
        if (intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int target = newInterval[0];
        int left = 0, right = n - 1;

        // Binary search to find the position to insert newInterval
        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Insert newInterval at the found position
        intervals.insert(intervals.begin() + left, newInterval);

        // Merge overlapping intervals
        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            // If res is empty or there is no overlap, add the interval to the
            // result
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
                // If there is an overlap, merge the intervals by updating the
                // end of the last interval in res
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        // If the intervals vector is empty, return a vector containing the
        // newInterval
        if (intervals.Length == 0) {
            return new int[][] { newInterval };
        }

        int n = intervals.Length;
        int target = newInterval[0];
        int left = 0, right = n - 1;

        // Binary search to find the position to insert newInterval
        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Insert newInterval at the found position
        List<int[]> result = new List<int[]>();
        for (int i = 0; i < left; i++) {
            result.Add(intervals[i]);
        }

        result.Add(newInterval);
        for (int i = left; i < n; i++) {
            result.Add(intervals[i]);
        }

        // Merge overlapping intervals
        List<int[]> merged = new List<int[]>();
        foreach (int[] interval in result) {
            // If res is empty or there is no overlap, add the interval to the
            // result
            if (merged.Count == 0 ||
                merged[merged.Count - 1][1] < interval[0]) {
                merged.Add(interval);
                // If there is an overlap, merge the intervals by updating the
                // end of the last interval in res
            } else {
                merged[merged.Count - 1][1] =
                    Math.Max(merged[merged.Count - 1][1], interval[1]);
            }
        }

        return merged.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func insert(intervals [][]int, newInterval []int) [][]int {
    // If the intervals vector is empty, return a vector containing the newInterval
    if len(intervals) == 0 {
        return [][]int{newInterval}
    }

    n := len(intervals)
    target := newInterval[0]
    left, right := 0, n-1

    // Binary search to find the position to insert newInterval
    for left <= right {
        mid := (left + right) / 2
        if intervals[mid][0] < target {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    // Insert newInterval at the found position
    result := make([][]int, 0)
    result = append(result, intervals[:left]...)
    result = append(result, newInterval)
    result = append(result, intervals[left:]...)

    // Merge overlapping intervals
    res := make([][]int, 0)
    for _, interval := range result {
        // If res is empty or there is no overlap, add the interval to the result
        if len(res) == 0 || res[len(res)-1][1] < interval[0] {
            res = append(res, interval)
            // If there is an overlap, merge the intervals by updating the end of the last interval in res
        } else {
            if res[len(res)-1][1] < interval[1] {
                res[len(res)-1][1] = interval[1]
            }
        }
    }

    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        // If the intervals vector is empty, return a vector containing the newInterval
        if (intervals.length == 0) {
            return new int[][] { newInterval };
        }

        int n = intervals.length;
        int target = newInterval[0];
        int left = 0, right = n - 1;

        // Binary search to find the position to insert newInterval
        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Insert newInterval at the found position
        List<int[]> result = new ArrayList<>();
        for (int i = 0; i < left; i++) {
            result.add(intervals[i]);
        }
        result.add(newInterval);
        for (int i = left; i < n; i++) {
            result.add(intervals[i]);
        }

        // Merge overlapping intervals
        List<int[]> merged = new ArrayList<>();
        for (int[] interval : result) {
            // If res is empty or there is no overlap, add the interval to the result
            if (
                merged.isEmpty() ||
                merged.get(merged.size() - 1)[1] < interval[0]
            ) {
                merged.add(interval);
                // If there is an overlap, merge the intervals by updating the end of the last interval in res
            } else {
                merged.get(merged.size() - 1)[1] = Math.max(
                    merged.get(merged.size() - 1)[1],
                    interval[1]
                );
            }
        }

        return merged.toArray(new int[0][]);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var insert = function (intervals, newInterval) {
    // If the intervals vector is empty, return an array containing the newInterval
    if (intervals.length === 0) {
        return [newInterval];
    }

    let n = intervals.length;
    let target = newInterval[0];
    let left = 0,
        right = n - 1;

    // Binary search to find the position to insert newInterval
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (intervals[mid][0] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Insert newInterval at the found position
    intervals.splice(left, 0, newInterval);

    // Merge overlapping intervals
    let res = [];
    for (let interval of intervals) {
        // If res is empty or there is no overlap, add the interval to the result
        if (res.length === 0 || res[res.length - 1][1] < interval[0]) {
            res.push(interval);
            // If there is an overlap, merge the intervals by updating the end of the last interval in res
        } else {
            res[res.length - 1][1] = Math.max(
                res[res.length - 1][1],
                interval[1],
            );
        }
    }

    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        # If the intervals vector is empty, return a vector containing the newInterval
        if not intervals:
            return [newInterval]

        n = len(intervals)
        target = newInterval[0]
        left, right = 0, n - 1

        # Binary search to find the position to insert newInterval
        while left <= right:
            mid = (left + right) // 2
            if intervals[mid][0] < target:
                left = mid + 1
            else:
                right = mid - 1

        # Insert newInterval at the found position
        intervals.insert(left, newInterval)

        # Merge overlapping intervals
        res = []
        for interval in intervals:
            # If res is empty or there is no overlap, add the interval to the result
            if not res or res[-1][1] < interval[0]:
                res.append(interval)
            # If there is an overlap, merge the intervals by updating the end of the last interval in res
            else:
                res[-1][1] = max(res[-1][1], interval[1])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function insert(intervals: number[][], newInterval: number[]): number[][] {
    // If the intervals vector is empty, return a list containing the newInterval
    if (intervals.length === 0) {
        return [newInterval];
    }

    let n = intervals.length;
    let target = newInterval[0];
    let left = 0,
        right = n - 1;

    // Binary search to find the position to insert newInterval
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (intervals[mid][0] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Insert newInterval at the found position
    intervals.splice(left, 0, newInterval);

    // Merge overlapping intervals
    let res: number[][] = [];
    for (let interval of intervals) {
        // If res is empty or there is no overlap, add the interval to the result
        if (res.length === 0 || res[res.length - 1][1] < interval[0]) {
            res.push(interval);
            // If there is an overlap, merge the intervals by updating the end of the last interval in res
        } else {
            res[res.length - 1][1] = Math.max(
                res[res.length - 1][1],
                interval[1],
            );
        }
    }
    return res;
}
```

</details>
