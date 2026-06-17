# 699. Falling Squares

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/falling-squares/)  
`Array` `Segment Tree` `Ordered Set`

**Problem Link:** [LeetCode 699 - Falling Squares](https://leetcode.com/problems/falling-squares/)

## Problem

There are several squares being dropped onto the X-axis of a 2D plane.

You are given a 2D integer array positions where positions[i] = [lefti, sideLengthi] represents the ith square with a side length of sideLengthi that is dropped with its left edge aligned with X-coordinate lefti.

Each square is dropped one at a time from a height above any landed squares. It then falls downward (negative Y direction) until it either lands on the top side of another square or on the X-axis. A square brushing the left/right side of another square does not count as landing on it. Once it lands, it freezes in place and cannot be moved.

After each square is dropped, you must record the height of the current tallest stack of squares.

Return an integer array ans where ans[i] represents the height described above after dropping the ith square.

### Example 1

```text
Input: positions = [[1,2],[2,3],[6,1]]
Output: [2,5,5]
Explanation:
After the first drop, the tallest stack is square 1 with a height of 2.
After the second drop, the tallest stack is squares 1 and 2 with a height of 5.
After the third drop, the tallest stack is still squares 1 and 2 with a height of 5.
Thus, we return an answer of [2, 5, 5].
```

### Example 2

```text
Input: positions = [[100,100],[200,100]]
Output: [100,100]
Explanation:
After the first drop, the tallest stack is square 1 with a height of 100.
After the second drop, the tallest stack is either square 1 or square 2, both with heights of 100.
Thus, we return an answer of [100, 100].
Note that square 2 only brushes the right side of square 1, which does not count as landing on it.
```

## Constraints

- 1 <= positions.length <= 1000
- 1 <= lefti <= 108
- 1 <= sideLengthi <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 699. Falling Squares

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach Framework | Java, Python |
| Offline Propagation | Java, Python |
| Brute Force with Coordinate Compression | Java, Python |
| Block (Square Root) Decomposition | Java, Python |
| Segment Tree with Lazy Propagation | Java, Python |

## Approach Framework

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
Set<Integer> coords = new HashSet();
for (int[] pos: positions) {
    coords.add(pos[0]);
    coords.add(pos[0] + pos[1] - 1);
}
List<Integer> sortedCoords = new ArrayList(coords);
Collections.sort(sortedCoords);

Map<Integer, Integer> index = new HashMap();
int t = 0;
for (int coord: sortedCoords) {
    index.put(coord, t++);
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
coords = set()
for left, size in positions:
    coords.add(left)
    coords.add(left + size - 1)
index = {x: i for i, x in enumerate(sorted(coords))}
```

</details>

<br>

## Approach 1: Offline Propagation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        int[] qans = new int[positions.length];
        for (int i = 0; i < positions.length; i++) {
            int left = positions[i][0];
            int size = positions[i][1];
            int right = left + size;
            qans[i] += size;

            for (int j = i+1; j < positions.length; j++) {
                int left2 = positions[j][0];
                int size2 = positions[j][1];
                int right2 = left2 + size2;
                if (left2 < right && left < right2) { //intersect
                    qans[j] = Math.max(qans[j], qans[i]);
                }
            }
        }

        List<Integer> ans = new ArrayList();
        int cur = -1;
        for (int x: qans) {
            cur = Math.max(cur, x);
            ans.add(cur);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def fallingSquares(self, positions):
        qans = [0] * len(positions)
        for i, (left, size) in enumerate(positions):
            right = left + size
            qans[i] += size
            for j in xrange(i+1, len(positions)):
                left2, size2 = positions[j]
                right2 = left2 + size2
                if left2 < right and left < right2: #intersect
                    qans[j] = max(qans[j], qans[i])

        ans = []
        for x in qans:
            ans.append(max(ans[-1], x) if ans else x)
        return ans
```

</details>

<br>

## Approach 2: Brute Force with Coordinate Compression

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] heights;

    public int query(int L, int R) {
        int ans = 0;
        for (int i = L; i <= R; i++) {
            ans = Math.max(ans, heights[i]);
        }
        return ans;
    }

    public void update(int L, int R, int h) {
        for (int i = L; i <= R; i++) {
            heights[i] = Math.max(heights[i], h);
        }
    }

    public List<Integer> fallingSquares(int[][] positions) {
        //Coordinate Compression
        //HashMap<Integer, Integer> index = ...;
        //int t = ...;

        heights = new int[t];
        int best = 0;
        List<Integer> ans = new ArrayList();

        for (int[] pos: positions) {
            int L = index.get(pos[0]);
            int R = index.get(pos[0] + pos[1] - 1);
            int h = query(L, R) + pos[1];
            update(L, R, h);
            best = Math.max(best, h);
            ans.add(best);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def fallingSquares(self, positions):
        #Coordinate Compression
        #index = ...

        heights = [0] * len(index)
        def query(L, R):
            return max(heights[i] for i in xrange(L, R+1))

        def update(L, R, h):
            for i in xrange(L, R+1):
                heights[i] = max(heights[i], h)

        best = 0
        ans = []
        for left, size in positions:
            L = index[left]
            R = index[left + size - 1]
            h = query(L, R) + size
            update(L, R, h)
            best = max(best, h)
            ans.append(best)

        return ans
```

</details>

<br>

## Approach 3: Block (Square Root) Decomposition

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] heights;
    int[] blocks;
    int[] blocks_read;
    int B;

    public int query(int left, int right) {
        int ans = 0;
        while (left % B > 0 && left <= right) {
            ans = Math.max(ans, heights[left]);
            ans = Math.max(ans, blocks[left / B]);
            left++;
        }
        while (right % B != B - 1 && left <= right) {
            ans = Math.max(ans, heights[right]);
            ans = Math.max(ans, blocks[right / B]);
            right--;
        }
        while (left <= right) {
            ans = Math.max(ans, blocks[left / B]);
            ans = Math.max(ans, blocks_read[left / B]);
            left += B;
        }
        return ans;
    }

    public void update(int left, int right, int h) {
        while (left % B > 0 && left <= right) {
            heights[left] = Math.max(heights[left], h);
            blocks_read[left / B] = Math.max(blocks_read[left / B], h);
            left++;
        }
        while (right % B != B - 1 && left <= right) {
            heights[right] = Math.max(heights[right], h);
            blocks_read[right / B] = Math.max(blocks_read[right / B], h);
            right--;
        }
        while (left <= right) {
            blocks[left / B] = Math.max(blocks[left / B], h);
            left += B;
        }
    }

    public List<Integer> fallingSquares(int[][] positions) {
        //Coordinate Compression
        //HashMap<Integer, Integer> index = ...;
        //int t = ...;

        heights = new int[t];
        B = (int) Math.sqrt(t);
        blocks = new int[B+2];
        blocks_read = new int[B+2];

        int best = 0;
        List<Integer> ans = new ArrayList();

        for (int[] pos: positions) {
            int L = index.get(pos[0]);
            int R = index.get(pos[0] + pos[1] - 1);
            int h = query(L, R) + pos[1];
            update(L, R, h);
            best = Math.max(best, h);
            ans.add(best);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def fallingSquares(self, positions):
        #Coordinate compression
        #index = ...

        W = len(index)
        B = int(W**.5)
        heights = [0] * W
        blocks = [0] * (B+2)
        blocks_read = [0] * (B+2)

        def query(left, right):
            ans = 0
            while left % B and left <= right:
                ans = max(ans, heights[left], blocks[left / B])
                left += 1
            while right % B != B-1 and left <= right:
                ans = max(ans, heights[right], blocks[right / B])
                right -= 1
            while left <= right:
                ans = max(ans, blocks[left / B], blocks_read[left / B])
                left += B
            return ans

        def update(left, right, h):
            while left % B and left <= right:
                heights[left] = max(heights[left], h)
                blocks_read[left / B] = max(blocks_read[left / B], h)
                left += 1
            while right % B != B-1 and left <= right:
                heights[right] = max(heights[right], h)
                blocks_read[right / B] = max(blocks_read[right / B], h)
                right -= 1
            while left <= right:
                blocks[left / B] = max(blocks[left / B], h)
                left += B

        best = 0
        ans = []
        for left, size in positions:
            L = index[left]
            R = index[left + size - 1]
            h = query(L, R) + size
            update(L, R, h)
            best = max(best, h)
            ans.append(best)

        return ans
```

</details>

<br>

## Approach 4: Segment Tree with Lazy Propagation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        //Coordinate Compression
        //HashMap<Integer, Integer> index = ...;

        SegmentTree tree = new SegmentTree(sortedCoords.size());
        int best = 0;
        List<Integer> ans = new ArrayList();

        for (int[] pos: positions) {
            int L = index.get(pos[0]);
            int R = index.get(pos[0] + pos[1] - 1);
            int h = tree.query(L, R) + pos[1];
            tree.update(L, R, h);
            best = Math.max(best, h);
            ans.add(best);
        }
        return ans;
    }
}

class SegmentTree {
    int N, H;
    int[] tree, lazy;

    SegmentTree(int N) {
        this.N = N;
        H = 1;
        while ((1 << H) < N) {
            H++;
        }
        tree = new int[2 * N];
        lazy = new int[N];
    }

    private void apply(int x, int val) {
        tree[x] = Math.max(tree[x], val);
        if (x < N) {
            lazy[x] = Math.max(lazy[x], val);
        }
    }

    private void pull(int x) {
        while (x > 1) {
            x >>= 1;
            tree[x] = Math.max(tree[x * 2], tree[x * 2 + 1]);
            tree[x] = Math.max(tree[x], lazy[x]);
        }
    }

    private void push(int x) {
        for (int h = H; h > 0; h--) {
            int y = x >> h;
            if (lazy[y] > 0) {
                apply(y * 2, lazy[y]);
                apply(y * 2 + 1, lazy[y]);
                lazy[y] = 0;
            }
        }
    }

    public void update(int L, int R, int h) {
        L += N; 
        R += N;
        int L0 = L, R0 = R, ans = 0;
        while (L <= R) {
            if ((L & 1) == 1) {
                apply(L++, h);
            }
            if ((R & 1) == 0) {
                apply(R--, h);
            }
            L >>= 1; 
            R >>= 1;
        }
        pull(L0); 
        pull(R0);
    }

    public int query(int L, int R) {
        L += N; 
        R += N;
        int ans = 0;
        push(L); 
        push(R);
        while (L <= R) {
            if ((L & 1) == 1) {
                ans = Math.max(ans, tree[L++]);
            }
            if ((R & 1) == 0) {
                ans = Math.max(ans, tree[R--]);
            }
            L >>= 1; 
            R >>= 1;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class SegmentTree(object):
    def __init__(self, N, update_fn, query_fn):
        self.N = N
        self.H = 1
        while 1 << self.H < N:
            self.H += 1

        self.update_fn = update_fn
        self.query_fn = query_fn
        self.tree = [0] * (2 * N)
        self.lazy = [0] * N

    def _apply(self, x, val):
        self.tree[x] = self.update_fn(self.tree[x], val)
        if x < self.N:
            self.lazy[x] = self.update_fn(self.lazy[x], val)

    def _pull(self, x):
        while x > 1:
            x /= 2
            self.tree[x] = self.query_fn(self.tree[x*2], self.tree[x*2 + 1])
            self.tree[x] = self.update_fn(self.tree[x], self.lazy[x])

    def _push(self, x):
        for h in xrange(self.H, 0, -1):
            y = x >> h
            if self.lazy[y]:
                self._apply(y * 2, self.lazy[y])
                self._apply(y * 2+ 1, self.lazy[y])
                self.lazy[y] = 0

    def update(self, L, R, h):
        L += self.N
        R += self.N
        L0, R0 = L, R
        while L <= R:
            if L & 1:
                self._apply(L, h)
                L += 1
            if R & 1 == 0:
                self._apply(R, h)
                R -= 1
            L /= 2; R /= 2
        self._pull(L0)
        self._pull(R0)

    def query(self, L, R):
        L += self.N
        R += self.N
        self._push(L); self._push(R)
        ans = 0
        while L <= R:
            if L & 1:
                ans = self.query_fn(ans, self.tree[L])
                L += 1
            if R & 1 == 0:
                ans = self.query_fn(ans, self.tree[R])
                R -= 1
            L /= 2; R /= 2
        return ans

class Solution(object):
    def fallingSquares(self, positions):
        #Coordinate compression
        #index = ...

        tree = SegmentTree(len(index), max, max)
        best = 0
        ans = []
        for left, size in positions:
            L, R = index[left], index[left + size - 1]
            h = tree.query(L, R) + size
            tree.update(L, R, h)
            best = max(best, h)
            ans.append(best)

        return ans
```

</details>
