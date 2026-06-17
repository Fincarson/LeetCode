# 849. Maximize Distance to Closest Person

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximize-distance-to-closest-person/)  
`Array`

**Problem Link:** [LeetCode 849 - Maximize Distance to Closest Person](https://leetcode.com/problems/maximize-distance-to-closest-person/)

## Problem

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to the closest person.

### Example 1

```text
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
```

### Example 2

```text
Input: seats = [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
```

### Example 3

```text
Input: seats = [0,1]
Output: 1
```

## Constraints

- 2 <= seats.length <= 2 * 104
- seats[i] is 0 or 1.
- At least one seat is empty.
- At least one seat is occupied.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Exam Room](https://leetcode.com/problems/exam-room/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Task Scheduler II](https://leetcode.com/problems/task-scheduler-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 849. Maximize Distance to Closest Person

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Next Array [Accepted] | Java, Python |
| Approach #2: Two Pointer [Accepted] | Java, Python |
| Approach #3: Group by Zero [Accepted] | Java, Python |

## Approach #1: Next Array [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int N = seats.length;
        int[] left = new int[N], right = new int[N];
        Arrays.fill(left, N);
        Arrays.fill(right, N);

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) left[i] = 0;
            else if (i > 0) left[i] = left[i-1] + 1;
        }

        for (int i = N-1; i >= 0; --i) {
            if (seats[i] == 1) right[i] = 0;
            else if (i < N-1) right[i] = right[i+1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < N; ++i)
            if (seats[i] == 0)
                ans = Math.max(ans, Math.min(left[i], right[i]));
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxDistToClosest(self, seats):
        N = len(seats)
        left, right = [N] * N, [N] * N

        for i in xrange(N):
            if seats[i] == 1: left[i] = 0
            elif i > 0: left[i] = left[i-1] + 1

        for i in xrange(N-1, -1, -1):
            if seats[i] == 1: right[i] = 0
            elif i < N-1: right[i] = right[i+1] + 1

        return max(min(left[i], right[i])
                   for i, seat in enumerate(seats) if not seat)
```

</details>

<br>

## Approach #2: Two Pointer [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int N = seats.length;
        int prev = -1, future = 0;
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                prev = i;
            } else {
                while (future < N && seats[future] == 0 || future < i)
                    future++;

                int left = prev == -1 ? N : i - prev;
                int right = future == N ? N : future - i;
                ans = Math.max(ans, Math.min(left, right));
            }
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
    def maxDistToClosest(self, seats):
        people = (i for i, seat in enumerate(seats) if seat)
        prev, future = None, next(people)

        ans = 0
        for i, seat in enumerate(seats):
            if seat:
                prev = i
            else:
                while future is not None and future < i:
                    future = next(people, None)

                left = float('inf') if prev is None else i - prev
                right = float('inf') if future is None else future - i
                ans = max(ans, min(left, right))

        return ans
```

</details>

<br>

## Approach #3: Group by Zero [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int N = seats.length;
        int K = 0; //current longest group of empty seats
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                K = 0;
            } else {
                K++;
                ans = Math.max(ans, (K + 1) / 2);
            }
        }

        for (int i = 0; i < N; ++i)  if (seats[i] == 1) {
            ans = Math.max(ans, i);
            break;
        }

        for (int i = N-1; i >= 0; --i)  if (seats[i] == 1) {
            ans = Math.max(ans, N - 1 - i);
            break;
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
    def maxDistToClosest(self, seats):
        ans = seats.index(1)
        seats.reverse()
        ans = max(ans,seats.index(1))
        for seat, group in itertools.groupby(seats):
            if not seat:
                K = len(list(group))
                ans = max(ans, (K+1)/2)

        return ans
```

</details>
