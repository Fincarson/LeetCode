# 1282. Group the People Given the Group Size They Belong To

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)  
`Array` `Hash Table` `Greedy`

**Problem Link:** [LeetCode 1282 - Group the People Given the Group Size They Belong To](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)

## Problem

There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

### Example 1

```text
Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation:
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
```

### Example 2

```text
Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]
```

## Constraints

- groupSizes.length == n
- 1 <= n <= 500
- 1 <= groupSizes[i] <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rabbits in Forest](https://leetcode.com/problems/rabbits-in-forest/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Groups With Increasing Length](https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1282. Group the People Given the Group Size They Belong To

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C++, Java |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        
        // A map from group size to the list of indices that are there in the group.
        vector<int> szToGroup[groupSizes.size() + 1];
        for (int i = 0; i < groupSizes.size(); i++) {
            szToGroup[groupSizes[i]].push_back(i);
            
            // When the list size equals the group size, empty it and store it in the answer.
            if (szToGroup[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(szToGroup[groupSizes[i]]);
                szToGroup[groupSizes[i]].clear();
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
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> ans = new ArrayList<>();
        
        // A map from group size to the list of indices that are there in the group.
        Map<Integer, List<Integer>> szToGroup = new HashMap<>();
        for (int i = 0; i < groupSizes.length; i++) {
            if (!szToGroup.containsKey(groupSizes[i])) {
                szToGroup.put(groupSizes[i], new ArrayList<>());
            }
            
            List<Integer> group = szToGroup.get(groupSizes[i]);
            group.add(i);

            // When the list size equals the group size, empty it and store it in the answer.
            if (group.size() == groupSizes[i]) {
                ans.add(group);
                szToGroup.remove(groupSizes[i]);
            }
        }

        return ans;
    }
}
```

</details>
