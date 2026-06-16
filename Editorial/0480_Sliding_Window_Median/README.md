# 480. Sliding Window Median

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/sliding-window-median/)  
`Array` `Hash Table` `Sliding Window` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 480 - Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)

## Problem

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

- For examples, if arr = [2,3,4], the median is 3.
- For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.

You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

### Example 1

```text
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation:
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
```

### Example 2

```text
Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
```

## Constraints

- 1 <= k <= nums.length <= 105
- -231 <= nums[i] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Operations to Make Median of Array Equal to K](https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 480. Sliding Window Median

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simple Sorting | C++, Python |
| Two Heaps (Lazy Removal) | C++ |
| Two Multisets | C++ |
| Multiset and Two Pointers | C++ |

## Approach 1: Simple Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;

    for (int i = 0; i + k <= nums.size(); i++) {
        vector<int> window(nums.begin() + i, nums.begin() + i + k);

        sort(window.begin(), window.end());

        if (k & 1)
            medians.push_back(window[k / 2]);
        else
            medians.push_back((double)(window[k / 2 - 1] + (double)window[k / 2]) / 2.0);
    }

    return medians;
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def medianSlidingWindow(self, nums, k):
    medians, window = [], []

    for i in xrange(len(nums)):

        # Find position where outgoing element should be removed from
        if i >= k:
          # window.remove(nums[i-k])        # this works too
          window.pop(bisect.bisect(window, nums[i - k]) - 1)

        # Maintain the sorted invariant while inserting incoming element
        bisect.insort(window, nums[i])

        # Find the medians
        if i >= k - 1:
          medians.append(float((window[k / 2]
            if k & 1 > 0
            else(window[k / 2 - 1] + window[k / 2]) * 0.5)))

    return medians
```

</details>

<br>

## Approach 2: Two Heaps (Lazy Removal)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;
    unordered_map<int, int> hash_table;
    priority_queue<int> lo;                                 // max heap
    priority_queue<int, vector<int>, greater<int> > hi;     // min heap

    int i = 0;      // index of current incoming element being processed

    // initialize the heaps
    while (i < k)
        lo.push(nums[i++]);
    for (int j = 0; j < k / 2; j++) {
        hi.push(lo.top());
        lo.pop();
    }

    while (true) {
        // get median of current window
        medians.push_back(k & 1 ? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);

        if (i >= nums.size())
            break;                          // break if all elements processed

        int out_num = nums[i - k],          // outgoing element
            in_num = nums[i++],             // incoming element
            balance = 0;                    // balance factor

        // number `out_num` exits window
        balance += (out_num <= lo.top() ? -1 : 1);
        hash_table[out_num]++;

        // number `in_num` enters window
        if (!lo.empty() && in_num <= lo.top()) {
            balance++;
            lo.push(in_num);
        }
        else {
            balance--;
            hi.push(in_num);
        }

        // re-balance heaps
        if (balance < 0) {                  // `lo` needs more valid elements
            lo.push(hi.top());
            hi.pop();
            balance++;
        }
        if (balance > 0) {                  // `hi` needs more valid elements
            hi.push(lo.top());
            lo.pop();
            balance--;
        }

        // remove invalid numbers that should be discarded from heap tops
        while (hash_table[lo.top()]) {
            hash_table[lo.top()]--;
            lo.pop();
        }
        while (!hi.empty() && hash_table[hi.top()]) {
            hash_table[hi.top()]--;
            hi.pop();
        }
    }

    return medians;
}
```

</details>

<br>

## Approach 3: Two Multisets

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;
    multiset<int> lo, hi;

    for (int i = 0; i < nums.size(); i++) {
        //remove outgoing element
        if (i >= k) {
            if (nums[i - k] <= *lo.rbegin())
                lo.erase(lo.find(nums[i - k]));
            else
                hi.erase(hi.find(nums[i - k]));
        }

        // insert incoming element
        lo.insert(nums[i]);

        // balance the sets
        hi.insert(*lo.rbegin());
        lo.erase(prev(lo.end()));

        if (lo.size() < hi.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }

        // get median
        if (i >= k - 1) {
            medians.push_back(k & 1 ? *lo.rbegin() : ((double)(*lo.rbegin()) + (double)(*hi.begin())) * 0.5);
        }
    }

    return medians;
}
```

</details>

<br>

## Approach 4: Multiset and Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;
    multiset<int> window(nums.begin(), nums.begin() + k);

    auto mid = next(window.begin(), k / 2);

    for (int i = k;; i++) {

        // Push the current median
        medians.push_back(((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5);

        // If all done, break
        if (i == nums.size())
            break;

        // Insert incoming element
        window.insert(nums[i]);
        if (nums[i] < *mid)
            mid--;                  // same as mid = prev(mid)

        // Remove outgoing element
        if (nums[i - k] <= *mid)
            mid++;                  // same as mid = next(mid)

        window.erase(window.lower_bound(nums[i - k]));
    }

    return medians;
}
```

</details>
