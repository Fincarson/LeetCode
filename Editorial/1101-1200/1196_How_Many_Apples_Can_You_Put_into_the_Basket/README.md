# 1196. How Many Apples Can You Put into the Basket

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1196 - How Many Apples Can You Put into the Basket](https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/)

## Problem

You have some apples and a basket that can carry up to 5000 units of weight.

Given an integer array weight where weight[i] is the weight of the ith apple, return the maximum number of apples you can put in the basket.

### Example 1

```text
Input: weight = [100,200,150,1000]
Output: 4
Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.
```

### Example 2

```text
Input: weight = [900,950,800,1000,700,800]
Output: 5
Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.
```

## Constraints

- 1 <= weight.length <= 103
- 1 <= weight[i] <= 103

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1196. How Many Apples Can You Put into the Basket

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | Java, Python3 |
| Min-Heap | Java, Python3 |
| Counting Sort | Java, Python3 |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxNumberOfApples(int[] arr) {
        Arrays.sort(arr);
        int apples = 0, units = 0;
        for (int i = 0; i < arr.length && units + arr[i] <= 5000; i++) {
            apples++;
            units += arr[i];
        }
        return apples;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr.sort()
        apples = units = 0

        for weight in arr:
            units += weight
            if units > 5000:
                break

            apples += 1
        return apples
```

</details>

<br>

## Approach 2: Min-Heap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxNumberOfApples(int[] arr) {
        List<Integer> list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        Queue<Integer> heap = new PriorityQueue<>(list);

        int apples = 0, units = 0;

        while (!heap.isEmpty() && units + heap.peek() <= 5000) {
            units += heap.remove();
            apples += 1;
        }
        return apples;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        heapq.heapify(arr)
        apples = units = 0

        # note that arr[0] always represents the smallest
        # element in the min-heap
        while arr and units + arr[0] <= 5000:
            units += heapq.heappop(arr)
            apples += 1
        return apples
```

</details>

<br>

## Approach 3: Counting Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxNumberOfApples(int[] arr) {
        // initialize the counts to store all elements
        int size = -1;
        for (Integer weight: arr) {
            size = Math.max(size, weight);
        }
        int[] counts = new int[size + 1];
        for (Integer weight: arr) {
            counts[weight]++;
        }

        int apples = 0, units = 0;
        for (int i = 0; i < size + 1; i++) {
            // if we have apples of i units of weight
            if (counts[i] != 0) {
                // we need to make sure that:
                // 1. we do not take more apples than those provided
                // 2. we do not exceed 5000 units of weight
                int take = Math.min(counts[i], (5000 - units) / i);

                if (take == 0) {
                    break;
                }
                units += take * i;
                apples += take;

            }
        }
        return apples;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        # initialize the counts to store all elements
        size = max(arr) + 1
        counts = [0] * size
        for weight in arr:
            counts[weight] += 1

        apples = units = 0
        for i in range(size):
            # if we have apples of i units of weight
            if counts[i] != 0:
                # we need to make sure that:
                # 1. we do not take more apples than those provided
                # 2. we do not exceed 5000 units of weight
                take = min(counts[i], (5000 - units) // i)
                if take == 0:
                    break

                apples += take
                units += take * i
        return apples
```

</details>
