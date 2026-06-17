# 1424. Diagonal Traverse II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/diagonal-traverse-ii/)  
`Array` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1424 - Diagonal Traverse II](https://leetcode.com/problems/diagonal-traverse-ii/)

## Problem

Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

### Example 1

```text
Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
```

### Example 2

```text
Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i].length <= 105
- 1 <= sum(nums[i].length) <= 105
- 1 <= nums[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1424. Diagonal Traverse II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Group Elements by the Sum of Row and Column Indices | C++, Java, Python3 |
| Breadth First Search | C++, Java, Python3 |

## Approach 1: Group Elements by the Sum of Row and Column Indices

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> groups;
        for (int row = nums.size() - 1; row >= 0; row--) {
            for (int col = 0; col < nums[row].size(); col++) {
                int diagonal = row + col;
                groups[diagonal].push_back(nums[row][col]);
            }
        }
        
        vector<int> ans;
        int curr = 0;
        
        while (groups.find(curr) != groups.end()) {
            for (int num : groups[curr]) {
                ans.push_back(num);
            }
            
            curr++;
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
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        Map<Integer, List<Integer>> groups = new HashMap();
        int n = 0;
        for (int row = nums.size() - 1; row >= 0; row--) {
            for (int col = 0; col < nums.get(row).size(); col++) {
                int diagonal = row + col;
                if (!groups.containsKey(diagonal)) {
                    groups.put(diagonal, new ArrayList<Integer>());
                }
                
                groups.get(diagonal).add(nums.get(row).get(col));
                n++;
            }
        }
        
        int[] ans = new int[n];
        int i = 0;
        int curr = 0;
        
        while (groups.containsKey(curr)) {
            for (int num : groups.get(curr)) {
                ans[i] = num;
                i++;
            }
            
            curr++;
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
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        groups = defaultdict(list)
        for row in range(len(nums) - 1, -1, -1):
            for col in range(len(nums[row])):
                diagonal = row + col
                groups[diagonal].append(nums[row][col])
                
        ans = []
        curr = 0
        
        while curr in groups:
            ans.extend(groups[curr])
            curr += 1

        return ans
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<int> ans;
        
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            ans.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                queue.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                queue.push({row, col + 1});
            }
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
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        Queue<Pair<Integer, Integer>> queue = new LinkedList();
        queue.offer(new Pair(0, 0));
        List<Integer> ans = new ArrayList();
        
        while (!queue.isEmpty()) {
            Pair<Integer, Integer> p = queue.poll();
            int row = p.getKey();
            int col = p.getValue();
            ans.add(nums.get(row).get(col));
            
            if (col == 0 && row + 1 < nums.size()) {
                queue.offer(new Pair(row + 1, col));
            }
            
            if (col + 1 < nums.get(row).size()) {
                queue.offer(new Pair(row, col + 1));
            }
        }
        
        // Java needs conversion
        int[] result = new int[ans.size()];
        int i = 0;
        for (int num : ans) {
            result[i] = num;
            i++;
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        queue = deque([(0, 0)])
        ans = []
        
        while queue:
            row, col = queue.popleft()
            ans.append(nums[row][col])
            
            if col == 0 and row + 1 < len(nums):
                queue.append((row + 1, col))
                
            if col + 1 < len(nums[row]):
                queue.append((row, col + 1))
        
        return ans
```

</details>
