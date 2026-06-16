# 352. Data Stream as Disjoint Intervals

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)  
`Hash Table` `Binary Search` `Union-Find` `Design` `Data Stream` `Ordered Set`

**Problem Link:** [LeetCode 352 - Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

## Problem

Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

- SummaryRanges() Initializes the object with an empty stream.
- void addNum(int value) Adds the integer value to the stream.
- int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.

### Example 1

```text
Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

Explanation
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
```

## Constraints

- 0 <= value <= 104
- At most 3 * 104 calls will be made to addNum and getIntervals.
- At most 102 calls will be made to getIntervals.

Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Summary Ranges](https://leetcode.com/problems/summary-ranges/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Right Interval](https://leetcode.com/problems/find-right-interval/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Range Module](https://leetcode.com/problems/range-module/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Integers in Intervals](https://leetcode.com/problems/count-integers-in-intervals/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 352. Data Stream as Disjoint Intervals

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Save all values in an ordered set | C++, Java |
| Maintain all the intervals in ordered map | C++, Java |

## Approach 1: Save all values in an ordered set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SummaryRanges {
    set<int> values;

public:
    SummaryRanges() {}

    void addNum(int value) { values.insert(value); }

    vector<vector<int>> getIntervals() {
        if (values.empty()) {
            return {};
        }
        vector<vector<int>> intervals;
        int left = -1, right = -1;
        for (int value : values) {
            if (left < 0) {
                left = right = value;
            } else if (value == right + 1) {
                right = value;
            } else {
                intervals.push_back({left, right});
                left = right = value;
            }
        }
        intervals.push_back({left, right});
        return intervals;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SummaryRanges {
    private Set<Integer> values;

    public SummaryRanges() {
        values = new TreeSet<>();
    }
    
    public void addNum(int value) {
       values.add(value);
    }
    
    public int[][] getIntervals() {
        if (values.isEmpty()) {
            return new int[0][2];
        }
        List<int[]> intervals = new ArrayList<>();
        int left = -1, right = -1;
        for (Integer value : values) {
            if (left < 0) {
                left = right = value;
            } else if (value == right + 1) {
                right = value;
            } else {
                intervals.add(new int[] {left, right});
                left = right = value;
            } 
        }
        intervals.add(new int[] {left, right});
        return intervals.toArray(new int[0][]); 
    }
}
```

</details>

<br>

## Approach 2: Maintain all the intervals in ordered map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class SummaryRanges {
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {
        int left = value, right = value;
        auto small_entry = intervals.upper_bound(value);
        if (small_entry != intervals.begin()) {
            auto max_entry = small_entry;
            --max_entry;
            if (max_entry->second >= value) {
                return;
            }
            if (max_entry->second == value - 1) {
                left = max_entry->first;
            }
        }
        if (small_entry != intervals.end() && small_entry->first == value + 1) {
            right = small_entry->second;
            intervals.erase(small_entry);
        }
        intervals[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
        for (const auto& p : intervals) {
            answer.push_back({p.first, p.second});
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class SummaryRanges {
    private TreeMap<Integer, Integer> intervals;

    public SummaryRanges() {
        intervals = new TreeMap<>(); 
    }
    
    public void addNum(int value) {
        final Map.Entry<Integer, Integer> smallEntry = intervals.floorEntry(value); 
        int left = value, right = value;
        if (smallEntry != null) {
            final int previous = smallEntry.getValue();
            if (previous >= value) {
                return;
            }
            if (previous == value - 1) {
                left = smallEntry.getKey();
            }
        }
        final Map.Entry<Integer, Integer> maxEntry = intervals.higherEntry(value); 
        if (maxEntry != null && maxEntry.getKey() == value + 1) {
            right = maxEntry.getValue();
            intervals.remove(value + 1);
        }
        intervals.put(left, right);
    }
    
    public int[][] getIntervals() {
        final int[][] answer = new int[intervals.size()][2];
        int ind = 0;
        for (Map.Entry<Integer, Integer> entry : intervals.entrySet()) {
            answer[ind][0] = entry.getKey();
            answer[ind++][1] = entry.getValue();
        }
        return answer; 
    }
}
```

</details>
