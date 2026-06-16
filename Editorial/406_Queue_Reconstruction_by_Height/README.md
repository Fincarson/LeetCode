# 406. Queue Reconstruction by Height

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/queue-reconstruction-by-height/)  
`Array` `Binary Indexed Tree` `Segment Tree` `Sorting`

**Problem Link:** [LeetCode 406 - Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/)

## Problem

You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

### Example 1

```text
Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
```

### Example 2

```text
Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
```

## Constraints

- 1 <= people.length <= 2000
- 0 <= hi <= 106
- 0 <= ki < people.length
- It is guaranteed that the queue can be reconstructed.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Reward Top K Students](https://leetcode.com/problems/reward-top-k-students/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 406. Queue Reconstruction by Height

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | Java, Python |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int[][] reconstructQueue(int[][] people) {
    Arrays.sort(people, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        // if the heights are equal, compare k-values
        return o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0];
      }
    });

    List<int[]> output = new LinkedList<>();
    for(int[] p : people){
      output.add(p[1], p);
    }

    int n = people.length;
    return output.toArray(new int[n][2]);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key = lambda x: (-x[0], x[1]))
        output = []
        for p in people:
            output.insert(p[1], p)
        return output
```

</details>
