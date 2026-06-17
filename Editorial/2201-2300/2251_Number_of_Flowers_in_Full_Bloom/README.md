# 2251. Number of Flowers in Full Bloom

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-flowers-in-full-bloom/)  
`Array` `Hash Table` `Binary Search` `Sorting` `Prefix Sum` `Ordered Set`

**Problem Link:** [LeetCode 2251 - Number of Flowers in Full Bloom](https://leetcode.com/problems/number-of-flowers-in-full-bloom/)

## Problem

You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

### Example 1

```text
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
```

### Example 2

```text
Input: flowers = [[1,10],[3,3]], people = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
```

## Constraints

- 1 <= flowers.length <= 5 * 104
- flowers[i].length == 2
- 1 <= starti <= endi <= 109
- 1 <= people.length <= 5 * 104
- 1 <= people[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2251. Number of Flowers in Full Bloom

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Heap/Priority Queue | C++, Java, Python3 |
| Difference Array + Binary Search | C++, Java, Python3 |
| Simpler Binary Search | C++, Java, Python3 |

## Approach 1: Heap/Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> sortedPeople(people.begin(), people.end());
        sort(sortedPeople.begin(), sortedPeople.end());
        
        sort(flowers.begin(), flowers.end());
        unordered_map<int, int> dic;
        priority_queue<int, vector<int>, greater<int>> heap;
        
        int i = 0;
        for (int person : sortedPeople) {
            while (i < flowers.size() && flowers[i][0] <= person) {
                heap.push(flowers[i][1]);
                i++;
            }
            
            while (!heap.empty() && heap.top() < person) {
                heap.pop();
            }
            
            dic[person] = heap.size();
        }
        
        vector<int> ans;
        for (int person : people) {
            ans.push_back(dic[person]);
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
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        int[] sortedPeople = Arrays.copyOf(people, people.length);
        Arrays.sort(sortedPeople);
        
        Arrays.sort(flowers, (a, b) -> Arrays.compare(a, b));
        Map<Integer, Integer> dic = new HashMap();
        PriorityQueue<Integer> heap = new PriorityQueue();
        
        int i = 0;
        for (int person : sortedPeople) {
            while (i < flowers.length && flowers[i][0] <= person) {
                heap.add(flowers[i][1]);
                i++;
            }
            
            while (!heap.isEmpty() && heap.peek() < person) {
                heap.remove();
            }
            
            dic.put(person, heap.size());
        }
        
        int[] ans = new int[people.length];
        for (int j = 0; j < people.length; j++) {
            ans[j] = dic.get(people[j]);
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
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        flowers.sort()
        sorted_people = sorted(people)
        dic = {}
        heap = []
        
        i = 0
        for person in sorted_people:
            while i < len(flowers) and flowers[i][0] <= person:
                heapq.heappush(heap, flowers[i][1])
                i += 1
            
            while heap and heap[0] < person:
                heapq.heappop(heap)
            
            dic[person] = len(heap)

        return [dic[x] for x in people]
```

</details>

<br>

## Approach 2: Difference Array + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> difference;
        difference[0] = 0;
        
        for (vector<int>& flower : flowers) {
            difference[flower[0]]++;
            difference[flower[1] + 1]--;
        }
        
        vector<int> positions;
        vector<int> prefix;
        int curr = 0;
        for (auto& pair : difference) {
            positions.push_back(pair.first);
            curr += pair.second;
            prefix.push_back(curr);
        }
        
        vector<int> ans;
        for (int person : people) {
            int i = upper_bound(positions.begin(), positions.end(), person) - positions.begin() - 1;
            ans.push_back(prefix[i]);
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
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        TreeMap<Integer, Integer> difference = new TreeMap<>();
        difference.put(0, 0);
        
        for (int[] flower : flowers) {
            int start = flower[0];
            int end = flower[1] + 1;
            
            difference.put(start, difference.getOrDefault(start, 0) + 1);
            difference.put(end, difference.getOrDefault(end, 0) - 1);
        }
        
        List<Integer> positions = new ArrayList();
        List<Integer> prefix = new ArrayList();
        int curr = 0;
        
        for (int key : difference.keySet()) {
            positions.add(key);
            curr += difference.get(key);
            prefix.add(curr);
        }
        
        int[] ans = new int[people.length];
        for (int j = 0; j < people.length; j++) {
            int i = binarySearch(positions, people[j]) - 1;
            ans[j] = prefix.get(i);
        }
        
        return ans;
    }
    
    public int binarySearch(List<Integer> arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (target < arr.get(mid)) {
                right = mid;
            } else {
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
from sortedcontainers import SortedDict

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        difference = SortedDict({0: 0})
        for start, end in flowers:
            difference[start] = difference.get(start, 0) + 1
            difference[end + 1] = difference.get(end + 1, 0) - 1
        
        positions = []
        prefix = []
        curr = 0
        for key, val in difference.items():
            positions.append(key)
            curr += val
            prefix.append(curr)

        ans = []
        for person in people:
            i = bisect_right(positions, person) - 1
            ans.append(prefix[i])
        
        return ans
```

</details>

<br>

## Approach 3: Simpler Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        
        for (vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> ans;
        
        for (int person : people) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.push_back(i - j);
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
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        List<Integer> starts = new ArrayList();
        List<Integer> ends = new ArrayList();
        
        for (int[] flower: flowers) {
            starts.add(flower[0]);
            ends.add(flower[1] + 1);
        }
        
        Collections.sort(starts);
        Collections.sort(ends);
        int[] ans = new int[people.length];
        
        for (int index = 0; index < people.length; index++) {
            int person = people[index];
            int i = binarySearch(starts, person);
            int j = binarySearch(ends, person);
            ans[index] = i - j;
        }
        
        return ans;
    }
    
    public int binarySearch(List<Integer> arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (target < arr.get(mid)) {
                right = mid;
            } else {
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
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        starts = []
        ends = []
        
        for start, end in flowers:
            starts.append(start)
            ends.append(end + 1)
            
        starts.sort()
        ends.sort()
        ans = []

        for person in people:
            i = bisect_right(starts, person)
            j = bisect_right(ends, person)
            ans.append(i - j)
        
        return ans
```

</details>
