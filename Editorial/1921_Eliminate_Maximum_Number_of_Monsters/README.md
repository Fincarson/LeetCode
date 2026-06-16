# 1921. Eliminate Maximum Number of Monsters

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1921 - Eliminate Maximum Number of Monsters](https://leetcode.com/problems/eliminate-maximum-number-of-monsters/)

## Problem

You are playing a video game where you are defending your city from a group of n monsters. You are given a 0-indexed integer array dist of size n, where dist[i] is the initial distance in kilometers of the ith monster from the city.

The monsters walk toward the city at a constant speed. The speed of each monster is given to you in an integer array speed of size n, where speed[i] is the speed of the ith monster in kilometers per minute.

You have a weapon that, once fully charged, can eliminate a single monster. However, the weapon takes one minute to charge. The weapon is fully charged at the very start.

You lose when any monster reaches your city. If a monster reaches the city at the exact moment the weapon is fully charged, it counts as a loss, and the game ends before you can use your weapon.

Return the maximum number of monsters that you can eliminate before you lose, or n if you can eliminate all the monsters before they reach the city.

### Example 1

```text
Input: dist = [1,3,4], speed = [1,1,1]
Output: 3
Explanation:
In the beginning, the distances of the monsters are [1,3,4]. You eliminate the first monster.
After a minute, the distances of the monsters are [X,2,3]. You eliminate the second monster.
After a minute, the distances of the monsters are [X,X,2]. You eliminate the third monster.
All 3 monsters can be eliminated.
```

### Example 2

```text
Input: dist = [1,1,2,3], speed = [1,1,1,1]
Output: 1
Explanation:
In the beginning, the distances of the monsters are [1,1,2,3]. You eliminate the first monster.
After a minute, the distances of the monsters are [X,0,1,2], so you lose.
You can only eliminate 1 monster.
```

### Example 3

```text
Input: dist = [3,2,4], speed = [5,3,2]
Output: 1
Explanation:
In the beginning, the distances of the monsters are [3,2,4]. You eliminate the first monster.
After a minute, the distances of the monsters are [X,0,2], so you lose.
You can only eliminate 1 monster.
```

## Constraints

- n == dist.length == speed.length
- 1 <= n <= 105
- 1 <= dist[i], speed[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Health to Beat Game](https://leetcode.com/problems/minimum-health-to-beat-game/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Time to Kill All Monsters](https://leetcode.com/problems/minimum-time-to-kill-all-monsters/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1921. Eliminate Maximum Number of Monsters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort By Arrival Time | C++, Java, Python3 |
| Heap | C++, Java, Python3 |

## Approach 1: Sort By Arrival Time

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> arrival;
        for (int i = 0; i < dist.size(); i++) {
            arrival.push_back((float) dist[i] / speed[i]);
        }
        
        sort(arrival.begin(), arrival.end());
        int ans = 0;
        
        for (int i = 0; i < arrival.size(); i++) {
            if (arrival[i] <= i) {
                break;
            }
            
            ans++;
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        double[] arrival = new double[dist.length];
        for (int i = 0; i < dist.length; i++) {
            arrival[i] = (double) dist[i] / speed[i];
        }
        
        Arrays.sort(arrival);
        int ans = 0;
        
        for (int i = 0; i < arrival.length; i++) {
            if (arrival[i] <= i) {
                break;
            }
            
            ans++;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        arrival = []
        for i in range(len(dist)):
            arrival.append(dist[i] / speed[i])
        
        arrival.sort()
        ans = 0

        for i in range(len(arrival)):
            if arrival[i] <= i:
                break
                
            ans += 1

        return ans
```

</details>

<br>

## Approach 2: Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float, vector<float>, greater<float>> heap;
        
        for (int i = 0; i < dist.size(); i++) {
            heap.push((float) dist[i] / speed[i]);
        }

        int ans = 0;
        while (!heap.empty()) {
            if (heap.top() <= ans) {
                break;
            }
            
            ans++;
            heap.pop();
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        PriorityQueue<Double> heap = new PriorityQueue();
        for (int i = 0; i < dist.length; i++) {
            heap.add ((double) dist[i] / speed[i]);
        }
        
        int ans = 0;
        while (!heap.isEmpty()) {
            if (heap.remove() <= ans) {
                break;
            }
            
            ans++;
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
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        heap = []
        for i in range(len(dist)):
            heap.append(dist[i] / speed[i])
            
        heapq.heapify(heap)
        ans = 0
        while heap:
            if heapq.heappop(heap) <= ans:
                break
            
            ans += 1
            
        return ans
```

</details>
