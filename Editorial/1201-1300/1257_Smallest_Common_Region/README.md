# 1257. Smallest Common Region

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/smallest-common-region/)  
`Array` `Hash Table` `String` `Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 1257 - Smallest Common Region](https://leetcode.com/problems/smallest-common-region/)

## Problem

You are given some lists of regions where the first region of each list directly contains all other regions in that list.

If a region x contains a region y directly, and region y contains region z directly, then region x is said to contain region z indirectly. Note that region x also indirectly contains all regions indirectly containd in y.

Naturally, if a region x contains (either directly or indirectly) another region y, then x is bigger than or equal to y in size. Also, by definition, a region x contains itself.

Given two regions: region1 and region2, return the smallest region that contains both of them.

It is guaranteed the smallest region exists.

### Example 1

```text
Input:
regions = [["Earth","North America","South America"],
["North America","United States","Canada"],
["United States","New York","Boston"],
["Canada","Ontario","Quebec"],
["South America","Brazil"]],
region1 = "Quebec",
region2 = "New York"
Output: "North America"
```

### Example 2

```text
Input: regions = [["Earth", "North America", "South America"],["North America", "United States", "Canada"],["United States", "New York", "Boston"],["Canada", "Ontario", "Quebec"],["South America", "Brazil"]], region1 = "Canada", region2 = "South America"
Output: "Earth"
```

## Constraints

- 2 <= regions.length <= 104
- 2 <= regions[i].length <= 20
- 1 <= regions[i][j].length, region1.length, region2.length <= 20
- region1 != region2
- regions[i][j], region1, and region2 consist of English letters.
- The input is generated such that there exists a region which contains all the other regions, either directly or indirectly.
- A region cannot be directly contained in more than one region.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1257. Smallest Common Region

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Lowest Common Ancestor of a Generic Tree | C++, Java, Python3 |

## Approach: Lowest Common Ancestor of a Generic Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Function to return an array representing the path from the root node
    // to the current node.
    vector<string> fetchPathForRegion(
        string currNode, unordered_map<string, string>& childParentMap) {
        vector<string> path;
        // Start by adding the current node to the path.
        path.push_back(currNode);

        // Traverse upwards through the tree by finding the parent of the
        // current node. Continue until the root node is reached.
        while (childParentMap.find(currNode) != childParentMap.end()) {
            string parentNode = childParentMap[currNode];
            path.push_back(parentNode);
            currNode = parentNode;
        }
        // Reverse the path so that it starts from the root and
        // ends at the given current node.
        reverse(path.begin(), path.end());
        return path;
    }

public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1,
                              string region2) {
        // Hash map to store (child -> parent) relationships
        // for each region.
        unordered_map<string, string> childParentMap;
        // Populate the 'childParentMap' using the provided 'regions' list.
        for (auto& regionArray : regions) {
            string parentNode = regionArray[0];
            for (int i = 1; i < regionArray.size(); ++i) {
                childParentMap[regionArray[i]] = parentNode;
            }
        }

        // Store the paths from the root node to 'region1' and 'region2'
        // nodes in their respective arrays.
        auto path1 = fetchPathForRegion(region1, childParentMap);
        auto path2 = fetchPathForRegion(region2, childParentMap);

        int i = 0, j = 0;
        string lowestCommonAncestor;
        // Traverse both paths simultaneously until the paths diverge.
        // The last common node is the lowest common ancestor.
        while (i < path1.size() && j < path2.size() && path1[i] == path2[j]) {
            lowestCommonAncestor = path1[i];
            i++;
            j++;
        }

        // Return the lowest common ancestor of 'region1' and 'region2'.
        return lowestCommonAncestor;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Function to return a list representing the path from the root node
    // to the current node.
    private List<String> fetchPathForRegion(
        String currNode,
        Map<String, String> childParentMap
    ) {
        List<String> path = new ArrayList<>();
        // Start by adding the current node to the path.
        path.add(currNode);

        // Traverse upwards through the tree by finding the parent of the
        // current node. Continue until the root node is reached.
        while (childParentMap.containsKey(currNode)) {
            String parentNode = childParentMap.get(currNode);
            path.add(parentNode);
            currNode = parentNode;
        }
        // Reverse the path so that it starts from the root and
        // ends at the given current node.
        Collections.reverse(path);
        return path;
    }

    public String findSmallestRegion(
        List<List<String>> regions,
        String region1,
        String region2
    ) {
        // Map to store (child -> parent) relationships for each region.
        Map<String, String> childParentMap = new HashMap<>();

        // Populate the 'childParentMap' using the provided 'regions' list.
        for (List<String> regionArray : regions) {
            String parentNode = regionArray.get(0);
            for (int i = 1; i < regionArray.size(); i++) {
                childParentMap.put(regionArray.get(i), parentNode);
            }
        }

        // Store the paths from the root node to 'region1' and 'region2'
        // nodes in their respective lists.
        List<String> path1 = fetchPathForRegion(region1, childParentMap);
        List<String> path2 = fetchPathForRegion(region2, childParentMap);

        int i = 0, j = 0;
        String lowestCommonAncestor = "";
        // Traverse both paths simultaneously until the paths diverge.
        // The last common node is the lowest common ancestor.
        while (
            i < path1.size() &&
            j < path2.size() &&
            path1.get(i).equals(path2.get(j))
        ) {
            lowestCommonAncestor = path1.get(i);
            i++;
            j++;
        }

        // Return the lowest common ancestor of 'region1' and 'region2'.
        return lowestCommonAncestor;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Function to return a list representing the path from the root node
    # to the current node.
    def fetch_path_for_region(self, curr_node, child_parent_map):
        path = []
        # Start by adding the current node to the path.
        path.append(curr_node)

        # Traverse upwards through the tree by finding the parent of the
        # current node. Continue until the root node is reached.
        while curr_node in child_parent_map:
            parent_node = child_parent_map[curr_node]
            path.append(parent_node)
            curr_node = parent_node

        # Reverse the path so that it starts from the root and
        # ends at the given current node.
        path.reverse()
        return path

    def findSmallestRegion(
        self, regions: List[List[str]], region1: str, region2: str
    ) -> str:
        # Dictionary to store (child -> parent) relationships for each region.
        child_parent_map = {}

        # Populate the 'child_parent_map' using the provided 'regions' list.
        for region_array in regions:
            parent_node = region_array[0]
            for i in range(1, len(region_array)):
                child_parent_map[region_array[i]] = parent_node

        # Store the paths from the root node to 'region1' and 'region2'
        # nodes in their respective lists.
        path1 = self.fetch_path_for_region(region1, child_parent_map)
        path2 = self.fetch_path_for_region(region2, child_parent_map)

        i, j = 0, 0
        lowest_common_ancestor = ""
        # Traverse both paths simultaneously until the paths diverge.
        # The last common node is the lowest common ancestor.
        while i < len(path1) and j < len(path2) and path1[i] == path2[j]:
            lowest_common_ancestor = path1[i]
            i += 1
            j += 1

        # Return the lowest common ancestor of 'region1' and 'region2'.
        return lowest_common_ancestor
```

</details>
