# 703. Kth Largest Element in a Stream

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/kth-largest-element-in-a-stream/)  
`Tree` `Design` `Binary Search Tree` `Heap (Priority Queue)` `Binary Tree` `Data Stream`

**Problem Link:** [LeetCode 703 - Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

## Problem

You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

- KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
- int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

### Example 1

### Example 2

## Constraints

- 0 <= nums.length <= 104
- 1 <= k <= nums.length + 1
- -104 <= nums[i] <= 104
- -104 <= val <= 104
- At most 104 calls will be made to add.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Finding MK Average](https://leetcode.com/problems/finding-mk-average/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Sequentially Ordinal Rank Tracker](https://leetcode.com/problems/sequentially-ordinal-rank-tracker/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 703. Kth Largest Element in a Stream

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Maintain Sorted List | C++, Java, Python3 |
| Heap | C++, Java, Python3 |

## Approach 1: Maintain Sorted List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class KthLargest {
public:
    vector<int> stream;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            stream.push_back(num);
        }
        sort(stream.begin(), stream.end());
    }

    int add(int val) {
        int index = getIndex(val);
        // Add val to correct position
        stream.insert(stream.begin() + index, val);
        return stream[stream.size() - k];
    }

private:
    int getIndex(int val) {
        int left = 0;
        int right = stream.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midValue = stream[mid];
            if (midValue == val) return mid;
            if (midValue > val) {
                // Go to left half
                right = mid - 1;
            } else {
                // Go to right half
                left = mid + 1;
            }
        }
        return left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class KthLargest {

    List<Integer> stream;
    int k;

    public KthLargest(int k, int[] nums) {
        stream = new ArrayList<Integer>(nums.length);
        this.k = k;

        for (int num : nums) {
            stream.add(num);
        }

        Collections.sort(stream);
    }

    public int add(int val) {
        int index = getIndex(val);
        // Add val to correct position
        stream.add(index, val);
        return stream.get(stream.size() - k);
    }

    private int getIndex(int val) {
        int left = 0;
        int right = stream.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midElement = stream.get(mid);
            if (midElement == val) return mid;
            if (midElement > val) {
                // Go to left half
                right = mid - 1;
            } else {
                // Go to right half
                left = mid + 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.stream = nums
        self.stream.sort()

    def add(self, val: int) -> int:
        index = self.getIndex(val)
        # Add val to correct position
        self.stream.insert(index, val)
        return self.stream[-self.k]

    def getIndex(self, val: int) -> int:
        left, right = 0, len(self.stream) - 1
        while left <= right:
            mid = (left + right) // 2
            mid_element = self.stream[mid]
            if mid_element == val:
                return mid
            # Go to left half
            elif mid_element > val:
                right = mid - 1
            # Go to right half
            else:
                left = mid + 1
        return left
```

</details>

<br>

## Approach 2: Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        // Add to our minHeap if we haven't processed k elements yet
        // or if val is greater than the top element (the k-th largest)
        if (minHeap.size() < k || minHeap.top() < val) {
            minHeap.push(val);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class KthLargest {

    PriorityQueue<Integer> minHeap;
    int k;

    public KthLargest(int k, int[] nums) {
        minHeap = new PriorityQueue<>();
        this.k = k;

        for (int num : nums) {
            add(num);
        }
    }

    public int add(int val) {
        // Add to our minHeap if we haven't processed k elements yet
        // or if val is greater than the top element (the k-th largest)
        if (minHeap.size() < k || minHeap.peek() < val) {
            minHeap.add(val);
            if (minHeap.size() > k) {
                minHeap.remove();
            }
        }
        return minHeap.peek();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.min_heap = []
        self.k = k

        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        # Add to our min_heap if we haven't processed k elements yet
        # or if val is greater than the top element (the k-th largest)
        if len(self.min_heap) < self.k or self.min_heap[0] < val:
            heapq.heappush(self.min_heap, val)
            if len(self.min_heap) > self.k:
                heapq.heappop(self.min_heap)
        return self.min_heap[0]
```

</details>
