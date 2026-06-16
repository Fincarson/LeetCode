# 218. The Skyline Problem

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/the-skyline-problem/)  
`Array` `Divide and Conquer` `Binary Indexed Tree` `Segment Tree` `Sweep Line` `Sorting` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 218 - The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)

## Problem

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

- lefti is the x coordinate of the left edge of the ith building.
- righti is the x coordinate of the right edge of the ith building.
- heighti is the height of the ith building.

You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

### Example 1

```text
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
```

### Example 2

```text
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
```

## Constraints

- 1 <= buildings.length <= 104
- 0 <= lefti < righti <= 231 - 1
- 1 <= heighti <= 231 - 1
- buildings is sorted by lefti in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Falling Squares](https://leetcode.com/problems/falling-squares/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 218. The Skyline Problem

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force I | C++, Java, Python3 |
| Brute Force II, Sweep Line | C++, Java, Python3 |
| Sweep Line + Priority Queue | C++, Java, Python3 |
| Sweep Line + Two Priority Queue | C++, Java, Python3 |
| Union Find | C++, Java, Python3 |
| Divide-and-Conquer | C++, Java, Python3 |

## Approach 1: Brute Force I

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public: 
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Sort the unique positions of all the edges.
        set<int> edgeSet;
        for (auto building : buildings) {
            int left = building[0], right = building[1];
            edgeSet.insert(left);
            edgeSet.insert(right);
        }
        vector<int> edges(edgeSet.begin(), edgeSet.end());
        // Use hash table 'edgeIndexMap' to record every {position : index} pairs in edges.
        map<int, int> edgeIndexMap;
        for (int i = 0; i < edges.size(); ++i) {
            edgeIndexMap[edges[i]] = i;
        }
        
        // Use 'heights' to record maximum height at each index.
        vector<int> heights(edges.size());
        
        // Iterate over all the buildings.
        for (auto building : buildings) {
            // Find the indexes of the left and right edges
            // and update the max height within the range [left_idx, right_idx)
            int left = building[0], right = building[1], height = building[2];
            int leftIndex = edgeIndexMap[left], rightIndex = edgeIndexMap[right];
            for (int idx = leftIndex; idx < rightIndex; ++idx) {
                heights[idx] = max(heights[idx], height);
            }
        }
        
        vector<vector<int>> answer;

        // Iterate over 'heights'.
        for (int i = 0; i < heights.size(); ++i) {
            // Add all the positions where the height changes to 'answer'.
            int currHeight = heights[i], currPos = edges[i];
            if (i == 0 || currHeight != heights[i - 1]) {
                answer.push_back({currPos, currHeight});
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        // Sort the unique positions of all the edges.
        SortedSet<Integer> edgeSet = new TreeSet<Integer>();
        for (int[] building : buildings) {
            int left = building[0], right = building[1];
            edgeSet.add(left);
            edgeSet.add(right);
        }
        List<Integer> edges = new ArrayList<Integer>(edgeSet);
        
        // Hast table 'edgeIndexMap' record every {position : index} pairs in edges.
        Map<Integer, Integer> edgeIndexMap = new HashMap<>();
        for (int i = 0; i < edges.size(); ++i) {
            edgeIndexMap.put(edges.get(i), i);
        }

        // Initialize 'heights' to record maximum height at each index.
        int[] heights = new int[edges.size()];

        // Iterate over all the buildings.
        for (int[] building : buildings) {
            // For each building, find the indexes of its left
            // and right edges.
            int left = building[0], right = building[1], height = building[2];
            int leftIndex = edgeIndexMap.get(left), rightIndex = edgeIndexMap.get(right);
            
            // Update the maximum height within the range [left_idx, right_idx)
            for (int idx = leftIndex; idx < rightIndex; ++idx) {
                heights[idx] = Math.max(heights[idx], height);
            }
        }
        
        List<List<Integer>> answer = new ArrayList<>();

        // Iterate over 'heights'.
        for (int i = 0; i < heights.length; ++i) {
            int currHeight = heights[i], currPos = edges.get(i);

            // Add all the positions where the height changes to 'answer'.
            if (answer.isEmpty() || answer.get(answer.size() - 1).get(1) != currHeight) {
                answer.add(Arrays.asList(currPos, currHeight));
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        # Sort the unique positions of all the edges.
        positions = sorted(list(set([x for building in buildings for x in building[:2]])))
        
        # Hast table 'edge_index_map' to record every {position : index} pairs in edges.
        edge_index_map = {x : i for i, x in enumerate(positions)}

        # Initialize 'heights' to record maximum height at each index.
        heights = [0] * len(positions)
        
        # Iterate over all the buildings.
        for left, right, height in buildings:
            # For each building, find the indexes of its left
            # and right edges.
            left_idx = edge_index_map[left]
            right_idx = edge_index_map[right]

            # Update the maximum height within the range [left_idx, right_idx)
            for i in range(left_idx, right_idx):
                heights[i] = max(heights[i], height)

        answer = []

        # Iterate over 'heights'.
        for i in range(len(heights)):
            curr_height = heights[i]
            curr_x = positions[i]

            # Add all the positions where the height changes to 'answer'.
            if not answer or answer[-1][1] != curr_height:
                answer.append([curr_x, curr_height])
        return answer
```

</details>

<br>

## Approach 2: Brute Force II, Sweep Line

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Collect and sort the unique positions of all the edges.
        set<int> edgeSet;
        for (auto building : buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        vector<int> positions(edgeSet.begin(), edgeSet.end());
        
        vector<vector<int>> answer;
            
        // For each position, draw an imaginary vertical line.
        for (auto position : positions) {
            int maxHeight = 0;
            // Check if any buildings intersect with the line at position.
            for (auto building : buildings) {
                int left = building[0], right = building[1], height = building[2];
                
                // Update 'maxHeight' if necessary.
                if (position >= left and position < right) {
                    maxHeight = max(maxHeight, height);
                }
            }
            
            // Add all the positions where the height changes to 'answer'.
            if (answer.empty() || answer[answer.size() - 1][1] != maxHeight) {
                answer.push_back({position, maxHeight});
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        // Collect and sort the unique positions of all the edges.
        SortedSet<Integer> edgeSet = new TreeSet<Integer>();
        for (int[] building : buildings) {
            int left = building[0], right = building[1];
            edgeSet.add(left);
            edgeSet.add(right);
        }
        List<Integer> positions = new ArrayList<Integer>(edgeSet);
        Collections.sort(positions);
        
        // 'answer' for skyline key points.
        List<List<Integer>> answer = new ArrayList<>();
        int maxHeight, left, right, height;
        
        // For each position, draw an imaginary vertical line.
        for (int position : positions) {
            // The current max height.
            maxHeight = 0;
            
            // Iterate over all the buildings:
            for (int[] building : buildings) {
                left = building[0];
                right = building[1];
                height = building[2];
                
                // If the current building intersects with the line,
                // update 'maxHeight'.
                if (left <= position && position < right) {
                    maxHeight = Math.max(maxHeight, height);
                }
            }
            
            // If its the first key point or the height changes, 
            // we add [position, maxHeight] to 'answer'.
            if (answer.isEmpty() || answer.get(answer.size() - 1).get(1) != maxHeight) {
                answer.add(Arrays.asList(position, maxHeight));
            }
        }
        
        // Return 'answer' as the skyline.
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        # Collect and sort the unique positions of all the edges.
        positions = sorted(list(set([x for building in buildings for x in building[:2]])))
        
        # 'answer' for skyline key points
        answer = []
        
        # For each position, draw an imaginary vertical line.
        for position in positions:
            # current max height.
            max_height = 0
            
            # Iterate over all the buildings:
            for left, right, height in buildings:
                # Update 'max_height' if necessary.
                if left <= position < right:
                    max_height = max(max_height, height)
            
            # If its the first key point or the height changes, 
            # we add [position, max_height] to 'answer'.
            if not answer or max_height != answer[-1][1]:
                answer.append([position, max_height])
                
        # Return 'answer' as the skyline.
        return answer
```

</details>

<br>

## Approach 3: Sweep Line + Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Iterate over all buildings, for each building i,
        // add (position, i) to edges.
        vector<vector<int>> edges;
        for (int i = 0; i < buildings.size(); ++i){
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }
        
        // Sort edges by non-decreasing order.
        sort(edges.begin(), edges.end());
        
        // Initailize an empty Priority Queue 'live' to store all the newly added buildings,
        // an empty list 'answer' to store the skyline key points.
        priority_queue<pair<int, int>> live;
        vector<vector<int>> answer;
        int idx = 0;
        
        // Iterate over all the sorted edges.
        while (idx < edges.size()){
            
            // Since we might have multiple edges at same x,
            // Let the 'currX' be the current position.
            int currX = edges[idx][0];
            
            // While we are handling the edges at 'currX':
            while (idx < edges.size() && edges[idx][0] == currX){
                // The index 'b' of this building in 'buildings'
                int b = edges[idx][1];
                
                // If this is a left edge of building 'b', we
                // add (height, right) of building 'b' to 'live'.
                if (buildings[b][0] == currX){
                    int right = buildings[b][1];
                    int height = buildings[b][2];
                    live.push({height, right});
                }
                idx += 1;
            }
            
            // If the tallest live building has been passed,
            // we remove it from 'live'.
            while (!live.empty() && live.top().second <= currX)
                live.pop();
            
            // Get the maximum height from 'live'.
            int currHeight = live.empty() ? 0 : live.top().first;
            
            // If the height changes at 'currX', we add this
            // skyline key point [currX, max_height] to 'answer'.
            if (answer.empty() || answer[answer.size() - 1][1] != currHeight)
                answer.push_back({currX, currHeight});
        }
        
        // Return 'answer' as the skyline.
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        // Iterate over all buildings, for each building i
        // add (position, i) to edges.
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < buildings.length; ++i){
            edges.add(Arrays.asList(buildings[i][0], i));
            edges.add(Arrays.asList(buildings[i][1], i));
        }
        Collections.sort(edges, (a, b) -> {
            return a.get(0) - b.get(0);
        });
        
        // Initailize an empty Priority Queue 'live' to store all the newly 
        // added buildings, an empty list answer to store the skyline key points.
        Queue<List<Integer>> live = new PriorityQueue<>((a, b) -> {
            return b.get(0) - a.get(0);
        });
        List<List<Integer>> answer = new ArrayList<>();
        
        int idx = 0;
        
        // Iterate over all the sorted edges.
        while (idx < edges.size()){
            // Since we might have multiple edges at same x,
            // Let the 'currX' be the current position.
            int currX = edges.get(idx).get(0);
            
            // While we are handling the edges at 'currX':
            while (idx < edges.size() && edges.get(idx).get(0) == currX){
                // The index 'b' of this building in 'buildings'
                int b = edges.get(idx).get(1);
                
                // If this is a left edge of building 'b', we
                // add (height, right) of building 'b' to 'live'.
                if (buildings[b][0] == currX){
                    int right = buildings[b][1];
                    int height = buildings[b][2];
                    live.offer(Arrays.asList(height, right));
                }
                idx += 1;
            }
            
            // If the tallest live building has been passed,
            // we remove it from 'live'.
            while (!live.isEmpty() && live.peek().get(1) <= currX)
                live.poll();
            
            // Get the maximum height from 'live'.
            int currHeight = live.isEmpty() ? 0 : live.peek().get(0);
            
            // If the height changes at this currX, we add this
            // skyline key point [currX, max_height] to 'answer'.
            if (answer.isEmpty() || answer.get(answer.size() - 1).get(1) != currHeight)
                answer.add(Arrays.asList(currX, currHeight));
        }
        
        // Return 'answer' as the skyline.
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        # Iterate over all buildings, for each building i,
        # add (position, i) to edges.
        edges = []
        for i, build in enumerate(buildings):
            edges.append([build[0], i])
            edges.append([build[1], i])

        # Sort edges by non-decreasing order.
        edges.sort()
     
        # Initailize an empty Priority Queue 'live' to store all the 
        # newly added buildings, an empty list answer to store the skyline key points.
        live, answer = [], []
        idx = 0
        
        # Iterate over all the sorted edges.
        while idx < len(edges):
            
            # Since we might have multiple edges at same x,
            # Let the 'curr_x' be the current position.
            curr_x = edges[idx][0]
            
            # While we are handling the edges at 'curr_x':
            while idx < len(edges) and edges[idx][0] == curr_x:
                # The index 'b' of this building in 'buildings'
                b = edges[idx][1]
                
                # If this is a left edge of building 'b', we
                # add (height, right) of building 'b' to 'live'.
                if buildings[b][0] == curr_x:
                    right = buildings[b][1]
                    height = buildings[b][2]
                    heapq.heappush(live, [-height, right])
                    
                # If the tallest live building has been passed,
                # we remove it from 'live'.
                while live and live[0][1] <= curr_x:
                    heapq.heappop(live)
                idx += 1
            
            # Get the maximum height from 'live'.
            max_height = -live[0][0] if live else 0
            
            # If the height changes at this curr_x, we add this
            # skyline key point [curr_x, max_height] to 'answer'.
            if not answer or max_height != answer[-1][1]:
                answer.append([curr_x, max_height])
        
        # Return 'answer' as the skyline.
        return answer
```

</details>

<br>

## Approach 4: Sweep Line + Two Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Iterate over all buildings, for each building i,
        // add (position, i) to 'edges'.
        vector<vector<int>> edges;
        for (int i = 0; i < buildings.size(); ++i){
            edges.push_back({buildings[i][0], buildings[i][2]});
            edges.push_back({buildings[i][1], -buildings[i][2]});
        }
        
        // Sort edges by non-decreasing order.
        sort(edges.begin(), edges.end());
        
        // Initailize twp empty priority queues 'live' and 'past',
        // an empty list 'answer' to store the skyline key points.
        priority_queue<int> live;
        priority_queue<int> past;
        vector<vector<int>> answer;
        
        int idx = 0;

        // Iterate over all the sorted edges.
        while (idx < edges.size()){
            
            // Since we might have multiple edges at same x,
            // Let the 'currX' be the current position.
            int currX = edges[idx][0];
            
            // While we are handling the edges at 'currX':
            while (idx < edges.size() && edges[idx][0] == currX){
                // The height of the current building.
                int height = edges[idx][1];
                
                // If this is a left edge, add `height` to 'live'.
                // Otherwise, add `height` to `past`.
                if (height > 0){
                    live.push(height);
                } else {
                    past.push(-height);
                }
                idx += 1;
            }
            
            // If the tallest live building has been passed,
            // we remove it from 'live'.
            while (!past.empty() && live.top() == past.top()) {
                live.pop();
                past.pop();
            }
            
            // Get the maximum height from 'live'.
            int currHeight = live.empty() ? 0 : live.top();
            
            // If the height changes at 'currX', we add this
            // skyline key point [currX, max_height] to 'answer'.
            if (answer.empty() || answer.back()[1] != currHeight)
                answer.push_back({currX, currHeight});
        }
            
        // Return 'answer' as the skyline.
        return answer;  
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        // Iterate over all buildings, for each building = [left, right, height]
        // add (left, height) and (right, height) to 'edges'.
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < buildings.length; ++i){
            edges.add(Arrays.asList(buildings[i][0], buildings[i][2]));
            edges.add(Arrays.asList(buildings[i][1], -buildings[i][2]));
        }
        Collections.sort(edges, (a, b) -> {
            return a.get(0) - b.get(0);
        });
        
        // Initailize two empty priority queues 'live' and 'past',
        // an empty list 'answer' to store the skyline key points.
        Queue<Integer> live = new PriorityQueue<>((a, b) -> {
            return b - a;
        });
        Queue<Integer> past = new PriorityQueue<>((a, b) -> {
            return b - a;
        });
        List<List<Integer>> answer = new ArrayList<>();
        
        
        int idx = 0;

        // Iterate over all the sorted edges.
        while (idx < edges.size()){
            // Since we might have multiple edges at same x,
            // Let the 'currX' be the current position.
            int currX = edges.get(idx).get(0);
            
            // While we are handling the edges at 'currX':
            while (idx < edges.size() && edges.get(idx).get(0) == currX){
                // The height of the current building.
                int height = edges.get(idx).get(1);
                
                // If this is a left edge, add `height` to 'live'.
                // Otherwise, add `height` to `past`.
                if (height > 0){
                    live.offer(height);
                } else {
                    past.offer(-height);
                }
                idx++;
            }

            // If the tallest live building has been passed,
            // we remove it from 'live'.
            while (!past.isEmpty() && live.peek().equals(past.peek())) {
                live.remove();
                past.remove();
            }
            
            // Get the maximum height from 'live'.
            int currHeight = live.isEmpty() ? 0 : live.peek();

            // If the height changes at 'currX', we add this
            // skyline key point [currX, max_height] to 'answer'.
            if (answer.isEmpty() || answer.get(answer.size() - 1).get(1) != currHeight) {
                answer.add(Arrays.asList(currX, currHeight));
            }   
        }
            
        // Return 'answer' as the skyline.
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        # Iterate over the left and right edges of all the buildings, 
        # If its a left edge, add (left, height) to 'edges'.
        # Otherwise, add (right, -height) to 'edges'.
        edges = []
        for left, right, height in buildings:
            edges.append([left, height])
            edges.append([right, -height])
        edges.sort()
        
        # Initailize two empty priority queues 'live' and 'past' 
        # for the live buildings and the past buildings.
        live, past = [], []
        answer = []
        idx = 0
        
        # Iterate over all the sorted edges.
        while idx < len(edges):
            # Since we might have multiple edges at same x,
            # Let the 'curr_x' be the current position.
            curr_x = edges[idx][0]
            
            # While we are handling the edges at 'curr_x':
            while idx < len(edges) and edges[idx][0] == curr_x:
                height = edges[idx][1]
                
                # If 'height' > 0, meaning a building of height 'height'
                # is live, push 'height' to 'live'. 
                # Otherwise, a building of height 'height' is passed, 
                # push the height to 'past'.
                if height > 0:
                    heapq.heappush(live, -height)
                else:
                    heapq.heappush(past, height)
                idx += 1
            
            # While the top height from 'live' equals to that from 'past',
            # Remove top height from both 'live' and 'past'.
            while past and past[0] == live[0]:
                heapq.heappop(live)
                heapq.heappop(past)
            
            # Get the maximum height from 'live'.
            max_height = -live[0] if live else 0
            
            # If the height changes at 'curr_x', we add this
            # skyline key point [curr_x, max_height] to 'answer'.
            if not answer or answer[-1][1] != max_height:
                answer.append([curr_x, max_height])
                
        # Return 'answer' as the skyline.
        return answer
```

</details>

<br>

## Approach 5: Union Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

// Define the disjoint-set data structure.
class UnionFind {   
    private:
        vector<int> root;
    public:
        UnionFind(int n): root(n) {
            iota(root.begin(), root.end(), 0);
        }
        int find(int x) {
            if (root[x] != x) 
                return find(root[x]);
            return root[x];
        }
        void merge(int x, int y) {
            root[x] = root[y];
        }
};

class Solution {
    public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Sort buildings by descending height.
        sort(buildings.begin(), buildings.end(), [](auto &a, auto &b) {
           return a[2] > b[2]; 
        });
        // Use a set to store the unique positions of all the edges and sort them.
        set<int> edgeSet;
        for (auto building : buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        vector<int> edges(edgeSet.begin(), edgeSet.end());
        int n = edges.size();
        
        // Map together the x value of each edge to its index in `edges`
        unordered_map<int, int> edgeIndexMap;
        for (int i = 0; i < n; ++i) {
            edgeIndexMap[edges[i]] = i;
        }

        // We'll use a disjoint set to allow us to skip past
        // already-updated indexes in `heights`.
        UnionFind edgeUF(n);
        vector<int> heights(n);
        
        // Iterate over all the buildings by descending height.
        for (auto building : buildings) {
            int leftEdge = building[0], rightEdge = building[1];
            int height = building[2];
            
            // Find the left and right starting indexes using `edgeIndexMap`.
            // We should use `find()` to jump forward to the first necessary index.
            int leftIndex = edgeUF.find(edgeIndexMap[leftEdge]);
            int rightIndex = edgeIndexMap[rightEdge];
            while (leftIndex < rightIndex) {
                heights[leftIndex] = height;
                
                // Use `merge()` to create a new shortcut to `rightIndex`.
                edgeUF.merge(leftIndex, rightIndex);
                
                // Then move forward and find the next necessary height to update.
                leftIndex = edgeUF.find(++leftIndex);
            }
        }
        
        // Finally, we just need to iterate over the updated 'heights'
        // and add every skyline key point to 'answer'.
        vector<vector<int>> answer;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || heights[i] != heights[i - 1]) {
                answer.push_back({edges[i], heights[i]});
            }
        }
        return answer;  
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java

// Define the disjoint-set structure.
class UnionFind {
    int[] root;
    public UnionFind(int n) {
        this.root = new int[n];
        for (int i = 0; i < n; ++i)
            root[i] = i;
    }
    public int find(int x) {
        return root[x] == x ? x : (root[x] = find(root[x]));
    }
    public void union(int x, int y) {
        root[x] = root[y];
    }
}
    
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        // Sort the unique positions of all the edges.
        SortedSet<Integer> edgeSet = new TreeSet<>();
        for (int[] building : buildings) {
            edgeSet.add(building[0]);
            edgeSet.add(building[1]);
        }
        Integer[] edges = edgeSet.toArray(new Integer[edgeSet.size()]);
        Arrays.sort(edges);
        
        // Hast table 'edgeIndexMap' record every {position : index} pairs in edges.
        Map<Integer, Integer> edgeIndexMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < edges.length; ++i)
            edgeIndexMap.put(edges[i], i);
        
        // Sort buildings by descending order of heights.
        Arrays.sort(buildings, (a, b) -> b[2] - a[2]);
        
        // Initalize a disjoin set for all indexs, each index's 
        // root is itself. Since there is no building added yet, 
        // the height at each position is 0.
        int n = edges.length;
        UnionFind edgeUF = new UnionFind(n);
        int[] heights = new int[n];
        
        // Iterate over all the buildings by descending height.
        for (int[] building : buildings) {
            int leftEdge = building[0], rightEdge = building[1];
            int height = building[2];
            
            // For current x position, get the corresponding index.
            int leftIndex = edgeIndexMap.get(leftEdge), rightIndex = edgeIndexMap.get(rightEdge);
            
            // While we haven't update the the root of 'left_idx':
            while (leftIndex < rightIndex) {
                // Find the root of left index 'left_idx', that is:
                // The rightmost index having the same height as 'left_idx'.
                leftIndex = edgeUF.find(leftIndex);

                // If left_idx < right_idx, we have to update both the root and height
                // of 'left_idx', and move on to the next index towards 'right_idx'.
                // That is: increment 'left_idx' by 1.
                if (leftIndex < rightIndex) {
                    edgeUF.union(leftIndex, rightIndex);
                    heights[leftIndex] = height;
                    leftIndex++;
                }
            }
        }
        
        // Finally, we just need to iterate over updated heights, and
        // add every skyline key point to 'answer'.
        List<List<Integer>> answer = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || heights[i] != heights[i - 1])
                answer.add(List.of(edges[i], heights[i]));
        }
        return answer; 
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python

# Define the disjoint-set structure.
class UnionFind():
    def __init__(self, N):
        self.root = list(range(N))
    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    def union(self, x, y):
        self.root[x] = self.root[y]
        
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        # Sort the unique positions of all the edges.
        edges = sorted(list(set([x for building in buildings for x in building[:2]])))
        
        # Hast table 'edge_index_map' record every {position : index} pairs in 'edges'.
        edge_index_map = {x:idx for idx, x in enumerate(edges)} 
        
        # Sort buildings by descending order of heights.
        buildings.sort(key=lambda x: -x[2])
        
        # Initalize a disjoin set for all indexs, each index's 
        # root is itself. Since there is no building added yet, 
        # the height at each position is 0.
        n = len(edges)
        edge_UF = UnionFind(n)
        heights = [0] * n
    
        # Iterate over all the buildings by descending height.
        for left_edge, right_edge, height in buildings:
            # For current x position, get the corresponding index.
            left_idx, right_idx = edge_index_map[left_edge], edge_index_map[right_edge]
            
            # While we haven't update the the root of 'left_idx':
            while left_idx < right_idx: 
                # Find the root of left index 'left_idx', that is:
                # The rightmost index having the same height as 'left_idx'.
                left_idx = edge_UF.find(left_idx)

                # If left_idx < right_idx, we have to update both the root and height
                # of left_idx, and move on to the next index towards right_idx.
                # That is: increment left_idx by 1.
                if left_idx < right_idx:
                    edge_UF.union(left_idx, right_idx)
                    heights[left_idx] = height
                    left_idx += 1
                    
        # Finally, we just need to iterate over updated heights, and
        # add every skyline key point to 'answer'.
        answer = []
        for i in range(n):
            if i == 0 or heights[i] != heights[i - 1]:
                answer.append([edges[i], heights[i]])
        return answer
```

</details>

<br>

## Approach 6: Divide-and-Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
using vv = vector<vector<int>>;

class Solution {
public:
    vv getSkyline(vv& buildings) {
        // Pass `buildings` on to the recursive divide-and-conquer function.
        return divideAndConquer(buildings, 0, buildings.size() - 1);
    }
    // Recursively divide buildings and merge the skylines.
    vv divideAndConquer(vv& buildings, int left, int right) {
        // If the given array of buildings contains only 1 building,
        // we can directly return the corresponding skyline.
        if (left == right) {
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
        }

        // Otherwise, recursively divide the buildings and merge the skylines.
        int mid = left + (right - left) / 2;
        vv leftSkyline = divideAndConquer(buildings, left, mid);
        vv rightSkyline = divideAndConquer(buildings, mid + 1, right);
        return mergeSkylines(leftSkyline, rightSkyline);
    }
    
    // Merge two skylines into one.
    vv mergeSkylines(vv& left, vv& right) {
        int leftPos = 0, rightPos = 0;
        int leftPrevHeight = 0, rightPrevHeight = 0;
        int curY = 0, curX = 0;
        vv answer;

        // Process both skylines in order of increasing X value.
        while (leftPos < left.size() && rightPos < right.size()) {
            // For each of the three possible cases,
            // update the current position and previous heights.
            int nextLeftX = left[leftPos][0], nextRightX = right[rightPos][0];
            if (nextLeftX < nextRightX) {
                curX = nextLeftX;
                curY = max(left[leftPos][1], rightPrevHeight);
                leftPrevHeight = left[leftPos++][1];
            } else if (nextLeftX > nextRightX) {
                curX = nextRightX;
                curY = max(right[rightPos][1], leftPrevHeight);
                rightPrevHeight = right[rightPos++][1];
            } else {
                curX = nextLeftX;
                curY = max(left[leftPos][1], right[rightPos][1]);
                leftPrevHeight = left[leftPos++][1];
                rightPrevHeight = right[rightPos++][1];
            }

            // If the height has changed, add the skyline point to our answer.
            if (answer.empty() || curY != answer.back()[1]) {
                answer.push_back({curX, curY});
            }
        }

        // If we have reached the end of one of the skylines,
        // append the other skyline's remaining points to our answer. 
        while (leftPos < left.size()) {
            answer.push_back(left[leftPos++]);
        }
        while (rightPos < right.size()) {
            answer.push_back(right[rightPos++]);
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        // Get the whole skyline from all the input buildings.
        return divideAndConquer(buildings, 0, buildings.length - 1);
    }
    
    public List<List<Integer>> divideAndConquer(int[][] buildings, int left, int right) {
        // If the given array of building contains only 1 building, we can
        // directly return the corresponding skyline.
        if (left == right) {
            List<List<Integer>> answer = new ArrayList<>();
            answer.add(Arrays.asList(buildings[left][0], buildings[left][2]));
            answer.add(Arrays.asList(buildings[left][1], 0));
            return answer;
        }
        
        // Otherwise, we shall recursively divide the buildings and 
        // merge the skylines. Cut the given skyline into two halves, 
        // get skyline from each half and merge them into a single skyline.
        int mid = (right - left)/2 + left;
        List<List<Integer>> leftSkyline = divideAndConquer(buildings, left, mid);
        List<List<Integer>> rightSkyline = divideAndConquer(buildings, mid+1, right);
        
        return mergeSkylines(leftSkyline, rightSkyline);
    }
    
    // Given two skylines: leftSky and rightSky, merge them into one skyline.
    public List<List<Integer>> mergeSkylines(List<List<Integer>> leftSkyline, List<List<Integer>> rightSkyline) {
        // Initalize leftPos=0, rightPos=0 as the pointer of lft_sky and rgt_sky.
        // Since we start from the left ground, thus our current height curY = 0,
        // the previous height from lft_sky and rgt_sky are also 0.
        List<List<Integer>> answer = new ArrayList<>();
        int leftPos = 0, rightPos = 0;
        int leftPrevHeight = 0, rightPrevHeight = 0;
        int curX, curY;

        // Now we start to iterate over both skylines.
        while (leftPos < leftSkyline.size() && rightPos < rightSkyline.size()) {
            int nextLeftX = leftSkyline.get(leftPos).get(0);
            int nextRightX = rightSkyline.get(rightPos).get(0);

            // If we meet lft_sky key point first, our current height 
            // changes to the larger one between height on left skyline 
            // and the previous height on right skyline. Update the 
            // previous height from lft_sky and increment leftPos by 1.
            if (nextLeftX < nextRightX) {
                leftPrevHeight = leftSkyline.get(leftPos).get(1);
                curX = nextLeftX;
                curY = Math.max(leftPrevHeight, rightPrevHeight);
                leftPos++;
            } 
            
            // If we meet rgt_sky key point first, our current height 
            // changes to the larger one between height on right skyline 
            // and the previous height on left skyline. Update the 
            // previous height from rgt_sky and increment rightPos by 1.
            else if (nextLeftX > nextRightX) {
                rightPrevHeight = rightSkyline.get(rightPos).get(1);
                curX = nextRightX;
                curY = Math.max(leftPrevHeight, rightPrevHeight);
                rightPos++;
            } 
            
            // If both skyline key points has same x:
            // Our current height is the larger one, update the 
            // previous height from lft_sky and rgt_sky. 
            // Increment both leftPos and rightPos by 1.
            else {    
                leftPrevHeight = leftSkyline.get(leftPos).get(1);
                rightPrevHeight = rightSkyline.get(rightPos).get(1);
                curX = nextLeftX;
                curY = Math.max(leftPrevHeight, rightPrevHeight);
                leftPos++;
                rightPos++;
            }

            // Discard those key points that has the same height 
            // as the previous one.
            if (answer.isEmpty() || answer.get(answer.size()-1).get(1) != curY){
                answer.add(Arrays.asList(curX, curY));
            }
        }
        
        // If we finish iterating over any skyline, 
        // just append the rest of the other skyline to the merged skyline.
        while(leftPos < leftSkyline.size()) {
            answer.add(leftSkyline.get(leftPos));
            leftPos++;
        }
        
        while(rightPos < rightSkyline.size()) {
            answer.add(rightSkyline.get(rightPos));
            rightPos++;
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getSkyline(self, A: List[List[int]]) -> List[List[int]]:
        n = len(A)
        # If the given array of building contains only 1 or less building, we can
        # directly return a corresponding skyline.
        if n == 0: return []
        if n == 1: return [[A[0][0], A[0][2]], [A[0][1], 0]]

        # Otherwise, we shall recursively divide the buildings and merge the skylines.
        # Cut the given skyline into two halves, get skyline from each half and merge
        # them into a single skyline.
        left_skyline = self.getSkyline(A[: n // 2])
        right_skyline = self.getSkyline(A[n // 2 :])  
        return self.merge_sky(left_skyline, right_skyline)
        
    def merge_sky(self, left_skyline, right_skyline):
        # Initalize left_pos=0, right_pos=0 as the pointer of left_skyline and right_skyline.
        # Since we start from the left ground, thus the previous height from 
        # left_skyline and right_skyline are 0.
        answer = []
        left_pos, right_pos = 0, 0
        left_prev_height, right_prev_height = 0, 0

        # Now we start to iterate over both skylines.
        while left_pos < len(left_skyline) and right_pos < len(right_skyline):
            next_left_x = left_skyline[left_pos][0]
            next_right_x = right_skyline[right_pos][0]
            
            # If we meet left_skyline key point first, our current height changes to the
            # larger one between height on left skyline and the previous height on right
            # skyline. Update the previous height from left_skyline and increment left_pos by 1.
            if next_left_x < next_right_x:
                left_prev_height = left_skyline[left_pos][1]
                cur_x = next_left_x
                cur_y = max(left_prev_height, right_prev_height)
                left_pos += 1
           

            # If we meet right_skyline key point first, our current height changes to the
            # larger one between height on right skyline and the previous height on left
            # skyline. Update the previous height from right_skyline and increment right_pos by 1.
            elif next_left_x > next_right_x:
                right_prev_height = right_skyline[right_pos][1]
                cur_x = next_right_x
                cur_y = max(left_prev_height, right_prev_height)
                right_pos += 1

            # If both skyline key points has same x:
            # Our current height is the larger one, update the previous height
            # from left_skyline and right_skyline. Increment both left_pos and right_pos by 1.
            else:
                left_prev_height = left_skyline[left_pos][1]
                right_prev_height = right_skyline[right_pos][1]
                cur_x = next_left_x
                cur_y = max(left_prev_height, right_prev_height)
                left_pos += 1
                right_pos += 1
            
            # Discard those key points that has the same height as the previous one.
            if not answer or answer[-1][1] != cur_y:
                answer.append([cur_x, cur_y])
        
        # If we finish iterating over any skyline, just append the rest of the other
        # skyline to the merged skyline.
        while left_pos < len(left_skyline):
            answer.append(left_skyline[left_pos])
            left_pos += 1
        while right_pos < len(right_skyline):
            answer.append(right_skyline[right_pos])
            right_pos += 1
        return answer
```

</details>
