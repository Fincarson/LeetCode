# 347. Top K Frequent Elements

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/top-k-frequent-elements/)  
`Array` `Hash Table` `Divide and Conquer` `Sorting` `Heap (Priority Queue)` `Bucket Sort` `Counting` `Quickselect`

**Problem Link:** [LeetCode 347 - Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

## Problem

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- k is in the range [1, the number of unique elements in the array].
- It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Frequency](https://leetcode.com/problems/word-frequency/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sort Features by Popularity](https://leetcode.com/problems/sort-features-by-popularity/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sender With Largest Word Count](https://leetcode.com/problems/sender-with-largest-word-count/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Linked List Frequency](https://leetcode.com/problems/linked-list-frequency/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 347. Top K Frequent Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Heap | C++, Java, Python3 |
| Quickselect (Hoare's selection algorithm) | C++, Java, Python3 |

## Approach 1: Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // O(1) time
        if (k == nums.size()) {
            return nums;
        }

        // 1. Build hash map: element and how often it appears
        // O(N) time
        unordered_map<int, int> count_map;
        for (int n : nums) {
            count_map[n] += 1;
        }

        //Initialise a heap with the most frequent elements at the top
        auto comp = [&count_map](int n1, int n2) { return count_map[n1] > count_map[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        // 2. Keep k top frequent elements in the heap
        // O(N log k) < O(N log N) time
        for (pair<int, int> p : count_map) {
            heap.push(p.first);
            if (heap.size() > k) heap.pop();
        }

        // 3. Build an output array
        // O(k log k) time
        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--) {
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        // O(1) time
        if (k == nums.length) {
            return nums;
        }
        
        // 1. Build hash map: character and how often it appears
        // O(N) time
        Map<Integer, Integer> count = new HashMap();
        for (int n: nums) {
          count.put(n, count.getOrDefault(n, 0) + 1);
        }

        // init heap 'the less frequent element first'
        Queue<Integer> heap = new PriorityQueue<>(
            (n1, n2) -> count.get(n1) - count.get(n2));

        // 2. Keep k top frequent elements in the heap
        // O(N log k) < O(N log N) time
        for (int n: count.keySet()) {
          heap.add(n);
          if (heap.size() > k) heap.poll();    
        }

        // 3. Build an output array
        // O(k log k) time
        int[] top = new int[k];
        for(int i = k - 1; i >= 0; --i) {
            top[i] = heap.poll();
        }
        return top;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]: 
        # O(1) time 
        if k == len(nums):
            return nums
        
        # 1. Build hash map: character and how often it appears
        # O(N) time
        count = Counter(nums)   
        # 2-3. Build heap of top k frequent elements and
        # convert it into an output array
        # O(N log k) time
        return heapq.nlargest(k, count.keys(), key=count.get)
```

</details>

<br>

## Approach 2: Quickselect (Hoare's selection algorithm)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int partition(int left, int right, int pivot_index) {
    int pivot_frequency = count_map[unique[pivot_index]];
    // 1. Move the pivot to the end
    swap(unique[pivot_index], unique[right]);

    // 2. Move all less frequent elements to the left
    int store_index = left;
    for (int i = left; i <= right; i++) {
        if (count_map[unique[i]] < pivot_frequency) {
            swap(unique[store_index], unique[i]);
            store_index += 1;
        }
    }

    // 3. Move the pivot to its final place
    swap(unique[right], unique[store_index]);

    return store_index;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int partition(int left, int right, int pivot_index) {
    int pivot_frequency = count.get(unique[pivot_index]);
    // 1. Move the pivot to the end
    swap(pivot_index, right);
    int store_index = left;

    // 2. Move all less frequent elements to the left
    for (int i = left; i <= right; i++) {
        if (count.get(unique[i]) < pivot_frequency) {
            swap(store_index, i);
            store_index++;
        }
    }

    // 3. Move the pivot to its final place
    swap(store_index, right);

    return store_index;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def partition(left, right, pivot_index) -> int:
    pivot_frequency = count[unique[pivot_index]]
    # 1. Move the pivot to the end
    unique[pivot_index], unique[right] = unique[right], unique[pivot_index]  
    
    # 2. Move all less frequent elements to the left
    store_index = left
    for i in range(left, right):
        if count[unique[i]] < pivot_frequency:
            unique[store_index], unique[i] = unique[i], unique[store_index]
            store_index += 1

    # 3. Move the pivot to its final place
    unique[right], unique[store_index] = unique[store_index], unique[right]  
    
    return store_index
```

</details>
