# 1962. Remove Stones to Minimize the Total

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-stones-to-minimize-the-total/)  
`Array` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1962 - Remove Stones to Minimize the Total](https://leetcode.com/problems/remove-stones-to-minimize-the-total/)

## Problem

You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k. You should apply the following operation exactly k times:

- Choose any piles[i] and remove floor(piles[i] / 2) stones from it.

Notice that you can apply the operation on the same pile more than once.

Return the minimum possible total number of stones remaining after applying the k operations.

floor(x) is the largest integer that is smaller than or equal to x (i.e., rounds x down).

### Example 1

```text
Input: piles = [5,4,9], k = 2
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,5].
- Apply the operation on pile 0. The resulting piles are [3,4,5].
The total number of stones in [3,4,5] is 12.
```

### Example 2

```text
Input: piles = [4,3,6,7], k = 3
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [4,3,3,7].
- Apply the operation on pile 3. The resulting piles are [4,3,3,4].
- Apply the operation on pile 0. The resulting piles are [2,3,3,4].
The total number of stones in [2,3,3,4] is 12.
```

## Constraints

- 1 <= piles.length <= 105
- 1 <= piles[i] <= 104
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Operations to Halve Array Sum](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximal Score After Applying K Operations](https://leetcode.com/problems/maximal-score-after-applying-k-operations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Take Gifts From the Richest Pile](https://leetcode.com/problems/take-gifts-from-the-richest-pile/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1962. Remove Stones to Minimize the Total

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy + Max Heap | C++, Java, Python3 |

## Approach: Greedy + Max Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        
        for (int i = 0; i < k; i++) {
            int curr = heap.top();
            heap.pop();
            int remove = curr / 2;
            totalSum -= remove;
            heap.push(curr - remove);
        }
        
        return totalSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> b - a);
        for (int num: piles) {
            heap.add(num);
        }
        
        for (int i = 0; i < k; i++) {
            int curr = heap.remove();
            int remove = curr / 2;
            heap.add(curr - remove);
        }
        
        int ans = 0;
        for (int num: heap) {
            ans += num;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import heapq

class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        heap = [-num for num in piles]
        heapq.heapify(heap)
        
        for _ in range(k):
            curr = -heapq.heappop(heap)
            remove = curr // 2
            heapq.heappush(heap, -(curr - remove))
        
        return -sum(heap)
```

</details>
