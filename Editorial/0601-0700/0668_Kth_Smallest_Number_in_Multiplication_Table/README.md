# 668. Kth Smallest Number in Multiplication Table

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)  
`Math` `Binary Search`

**Problem Link:** [LeetCode 668 - Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)

## Problem

Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

### Example 1

```text
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.
```

### Example 2

```text
Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.
```

## Constraints

- 1 <= m, n <= 3 * 104
- 1 <= k <= m * n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Time to Eat All Grains](https://leetcode.com/problems/minimum-time-to-eat-all-grains/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Kth Smallest Amount With Single Denomination Combination](https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 668. Kth Smallest Number in Multiplication Table

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Memory Limit Exceeded] | Java, Python |
| Approach #2: Next Heap [Time Limit Exceeded] | Java, Python |
| Approach #3: Binary Search [Accepted] | Java, Python |

## Approach #1: Brute Force [Memory Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findKthNumber(int m, int n, int k) {
        int[] table = new int[m*n];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                table[(i - 1) * n + j - 1] = i * j;
            }
        }
        Arrays.sort(table);
        return table[k-1];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findKthNumber(self, m, n, k):
        table = [i*j for i in range(1, m+1) for j in range(1, n+1)]
        table.sort()
        return table[k-1]
```

</details>

<br>

## Approach #2: Next Heap [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findKthNumber(int m, int n, int k) {
        PriorityQueue<Node> heap = new PriorityQueue<Node>(m,
            Comparator.<Node> comparingInt(node -> node.val));

        for (int i = 1; i <= m; i++) {
            heap.offer(new Node(i, i));
        }

        Node node = null;
        for (int i = 0; i < k; i++) {
            node = heap.poll();
            int nxt = node.val + node.root;
            if (nxt <= node.root * n) {
                heap.offer(new Node(nxt, node.root));
            }
        }
        return node.val;
    }
}

class Node {
    int val;
    int root;
    public Node(int v, int r) {
        val = v;
        root = r;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findKthNumber(self, m, n, k):
        heap = [(i, i) for i in range(1, m+1)]
        heapq.heapify(heap)

        for _ in xrange(k):
            val, root = heapq.heappop(heap)
            nxt = val + root
            if nxt <= root * n:
                heapq.heappush(heap, (nxt, root))

        return val
```

</details>

<br>

## Approach #3: Binary Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean enough(int x, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += Math.min(x / i, n);
        }
        return count >= k;
    }

    public int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!enough(mi, m, n, k)) lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findKthNumber(self, m, n, k):
        def enough(x):
            count = 0
            for i in xrange(1, m+1):
                count += min(x // i, n)
            return count >= k

        lo, hi = 1, m * n
        while lo < hi:
            mi = (lo + hi) / 2
            if not enough(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo
```

</details>
