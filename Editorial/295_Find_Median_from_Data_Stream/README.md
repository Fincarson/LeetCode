# 295. Find Median from Data Stream

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/find-median-from-data-stream/)  
`Two Pointers` `Design` `Sorting` `Heap (Priority Queue)` `Data Stream`

**Problem Link:** [LeetCode 295 - Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

## Problem

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

- For example, for arr = [2,3,4], the median is 3.
- For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

- MedianFinder() initializes the MedianFinder object.
- void addNum(int num) adds the integer num from the data stream to the data structure.
- double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

### Example 1

```text
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

## Constraints

- -105 <= num <= 105
- There will be at least one element in the data structure before calling findMedian.
- At most 5 * 104 calls will be made to addNum and findMedian.

Follow up:

- If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
- If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Finding MK Average](https://leetcode.com/problems/finding-mk-average/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Sequentially Ordinal Rank Tracker](https://leetcode.com/problems/sequentially-ordinal-rank-tracker/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Operations to Make Median of Array Equal to K](https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Make Subarray Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-subarray-elements-equal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Make Elements Within K Subarrays Equal](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 295. Find Median from Data Stream

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simple Sorting | C++ |
| Insertion Sort | C++ |
| Two Heaps | C++ |
| Multiset and Two Pointers | C++ |

## Approach 1: Simple Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MedianFinder {
    vector<int> store;

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        store.push_back(num);
    }

    // Returns the median of current data stream
    double findMedian()
    {
        sort(store.begin(), store.end());

        int n = store.size();
        return (n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5);
    }
};
```

</details>

<br>

## Approach 2: Insertion Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MedianFinder {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};
```

</details>

<br>

## Approach 3: Two Heaps

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
    }
};
```

</details>

<br>

## Approach 4: Multiset and Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder()
        : lo_median(data.end())
        , hi_median(data.end())
    {
    }

    void addNum(int num)
    {
        const size_t n = data.size();   // store previous size

        data.insert(num);               // insert into multiset

        if (!n) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n & 1) {
            // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

            if (num < *lo_median)       // num < lo
                lo_median--;
            else                        // num >= hi
                hi_median++;            // insertion at end of equal range
        }
        else {
            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

            if (num > *lo_median && num < *hi_median) {
                lo_median++;                    // num in between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median)         // num inserted after hi
                lo_median++;
            else                                // num <= lo < hi
                lo_median = --hi_median;        // insertion at end of equal range spoils lo
        }
    }

    double findMedian()
    {
        return ((double) *lo_median + *hi_median) * 0.5;
    }
};
```

</details>
