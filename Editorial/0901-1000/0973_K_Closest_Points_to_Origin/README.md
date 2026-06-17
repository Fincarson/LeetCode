# 973. K Closest Points to Origin

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/k-closest-points-to-origin/)  
`Array` `Math` `Divide and Conquer` `Geometry` `Sorting` `Heap (Priority Queue)` `Quickselect`

**Problem Link:** [LeetCode 973 - K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)

## Problem

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., Ã¢Ë†Å¡(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

### Example 1

```text
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
```

### Example 2

```text
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
```

## Constraints

- 1 <= k <= points.length <= 104
- -104 <= xi, yi <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Nearest Point That Has the Same X or Y Coordinate](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Rectangles to Cover Points](https://leetcode.com/problems/minimum-rectangles-to-cover-points/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [K-th Nearest Obstacle Queries](https://leetcode.com/problems/k-th-nearest-obstacle-queries/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 973. K Closest Points to Origin

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort with Custom Comparator | C++, Java, JavaScript, Python3 |
| Max Heap or Max Priority Queue | C++, Java, JavaScript, Python3 |
| Binary Search | C++, Java, JavaScript, Python3 |
| QuickSelect | C++, Java, JavaScript, Python3 |

## Approach 1: Sort with Custom Comparator

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Sort the vector with a custom lambda comparator function
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            return squaredDistance(a) < squaredDistance(b);
        });
        
        // Return the first k elements of the sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // Sort the array with a custom lambda comparator function
        Arrays.sort(points, (a, b) -> squaredDistance(a) - squaredDistance(b));
        
        // Return the first k elements of the sorted array
        return Arrays.copyOf(points, k);
    }
    
    private int squaredDistance(int[] point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kClosest = function(points, k) {
    // Sort the array with a custom lambda comparator function
    points.sort((a, b) => squaredDistance(a) - squaredDistance(b))
    
    // Return the first k elements of the sorted array
    return points.slice(0, k)
};

// Calculate and return the squared Euclidean distance
const squaredDistance = ([x, y]) => x ** 2 + y ** 2
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Sort the list with a custom comparator function
        points.sort(key=self.squared_distance)
        
        # Return the first k elements of the sorted list
        return points[:k]
    
    def squared_distance(self, point: List[int]) -> int:
        """Calculate and return the squared Euclidean distance."""
        return point[0] ** 2 + point[1] ** 2
```

</details>

<br>

## Approach 2: Max Heap or Max Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        for (int i = 0 ; i < points.size(); i++) {
            pair<int, int> entry = {squaredDistance(points[i]), i};
            if (maxPQ.size() < k) {
                // Fill the max PQ up to k points
                maxPQ.push(entry);
            } else if (entry.first < maxPQ.top().first) {
                // If the max PQ is full and a closer point is found,
                // discard the farthest point and add this one
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }
        
        // Return all points stored in the max PQ
        vector<vector<int>> answer;
        while (!maxPQ.empty()) {
            int entryIndex = maxPQ.top().second;
            maxPQ.pop();
            answer.push_back(points[entryIndex]);
        }
        return answer;
    }

private:
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // Use a lambda comparator to sort the PQ by farthest distance
        Queue<int[]> maxPQ = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < points.length; i++) {
            int[] entry = {squaredDistance(points[i]), i};
            if (maxPQ.size() < k) {
                // Fill the max PQ up to k points
                maxPQ.add(entry);
            } else if (entry[0] < maxPQ.peek()[0]) {
                // If the max PQ is full and a closer point is found,
                // discard the farthest point and add this one
                maxPQ.poll();
                maxPQ.add(entry);
            }
        }
        
        // Return all points stored in the max PQ
        int[][] answer = new int[k][2];
        for (int i = 0; i < k; i++) {
            int entryIndex = maxPQ.poll()[1];
            answer[i] = points[entryIndex];
        }
        return answer;
    }
    
    private int squaredDistance(int[] point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kClosest = function(points, k) {
    let maxPQ = new MaxPriorityQueue()
    for (let point of points) {
        let dist = squaredDistance(point)
        if (maxPQ.size() < k) {
            // Fill the max PQ up to k points
            maxPQ.enqueue(point, dist)
        } else if (dist < maxPQ.front().priority) {
            // If the max PQ is full and a closer point is found,
            // discard the farthest point and add this one
            maxPQ.dequeue()
            maxPQ.enqueue(point, dist)
        }
    }
    
    // Return all points stored in the max PQ
    return maxPQ.toArray().map(el => el.element)
};

// Calculate and return the squared Euclidean distance
const squaredDistance = ([x,y]) => x ** 2 + y ** 2
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Since heap is sorted in increasing order,
        # negate the distance to simulate max heap
        # and fill the heap with the first k elements of points
        heap = [(-self.squared_distance(points[i]), i) for i in range(k)]
        heapq.heapify(heap)
        for i in range(k, len(points)):
            dist = -self.squared_distance(points[i])
            if dist > heap[0][0]:
                # If this point is closer than the kth farthest,
                # discard the farthest point and add this one
                heapq.heappushpop(heap, (dist, i))
        
        # Return all points stored in the max heap
        return [points[i] for (_, i) in heap]
    
    def squared_distance(self, point: List[int]) -> int:
        """Calculate and return the squared Euclidean distance."""
        return point[0] ** 2 + point[1] ** 2
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Precompute the Euclidean distance for each point,
        // define the initial binary search range,
        // and create a reference list of point indices
        vector<double> distances;
        vector<int> remaining;
        double low = 0, high = 0;
        for (int i = 0; i < points.size(); i++) {
            distances.push_back(euclideanDistance(points[i]));
            high = max(high, distances[i]);
            remaining.push_back(i);
        }
                
        // Perform a binary search of the distances
        // to find the k closest points
        vector<int> closest;
        while (k) {
            double mid = low + (high - low) / 2;
            vector<vector<int>> result = splitDistances(remaining, distances, mid);
            vector<int>& closer = result[0];
            vector<int>& farther = result[1];
            if (closer.size() > k) {
                // If more than k points are in the closer distances
                // then discard the farther points and continue
                remaining.swap(closer);
                high = mid;
            } else {
                // Add the closer points to the answer array and keep
                // searching the farther distances for the remaining points
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                low = mid;
            }
        }
        
        // Return the k closest points using the reference indices
        vector<vector<int>> answer;
        for (int index : closest) {
            answer.push_back(points[index]);
        }
        return answer;
    }
    
private:
    vector<vector<int>> splitDistances(vector<int>& remaining, vector<double>& distances,
                                       double mid) {
        // Split the distances around the midpoint
        // and return them in separate vectors
        vector<vector<int>> result(2);
        vector<int> &closer = result[0], &farther = result[1];
        for (int index : remaining) {
            if (distances[index] <= mid) {
                closer.push_back(index);
            } else {
                farther.push_back(index);
            }
        }
        return result;
    } 
    
    double euclideanDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // Precompute the Euclidean distance for each point,
        // define the initial binary search range,
        // and create a reference list of point indices
        double[] distances = new double[points.length];
        double low = 0, high = 0;
        List<Integer> remaining = new ArrayList<>();
        for (int i = 0; i < points.length; i++) {
            distances[i] = euclideanDistance(points[i]);
            high = Math.max(high, distances[i]);
            remaining.add(i);
        }

        // Perform a binary search of the distances
        // to find the k closest points
        List<Integer> closest = new ArrayList<>();
        while (k > 0) {
            double mid = low + (high - low) / 2;
            List<List<Integer>> result = splitDistances(remaining, distances, mid);
            List<Integer> closer = result.get(0), farther = result.get(1);
            if (closer.size() > k) {
                // If more than k points are in the closer distances
                // then discard the farther points and continue
                remaining = closer;
                high = mid;
            } else {
                // Add the closer points to the answer array and keep
                // searching the farther distances for the remaining points
                k -= closer.size();
                closest.addAll(closer);
                remaining = farther;
                low = mid;
            }
        }
        
        // Return the k closest points using the reference indices
        k = closest.size();
        int[][] answer = new int[k][2];
        for (int i = 0; i < k; i++) {
            answer[i] = points[closest.get(i)];
        }
        return answer;
    };
    
    private List<List<Integer>> splitDistances(List<Integer> remaining, double[] distances,
                                               double mid) {
        // Split the distances around the midpoint
        // and return them in separate lists
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> closer = new ArrayList<>();
        List<Integer> farther = new ArrayList<>();
        result.add(closer);
        result.add(farther);
        for (int point : remaining) {
            if (distances[point] <= mid) {
                closer.add(point);
            } else {
                farther.add(point);
            }
        }
        return result;
    }
    
    private double euclideanDistance(int[] point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kClosest = function(points, k) {
    // Precompute the Euclidean distance for each point
    let distances = points.map(euclideanDistance)
    // Create a reference array of point indices
    let remaining = points.map((_, i) => i)
    // Define the initial binary search range
    let low = 0, high = Math.max(...distances)
    
    // Perform a binary search of the distances
    // to find the k closest points
    let closest = []
    while (k) {
        let mid = low + (high - low) / 2
        let [closer, farther] = splitDistances(remaining, distances, mid)
        if (closer.length > k) {
            // If more than k points are in the closer distances
            // then discard the farther points and continue
            remaining = closer
            high = mid
        } else {
            // Add the closer points to the answer array and keep
            // searching the farther distances for the remaining points
            k -= closer.length
            closest.push(...closer)
            remaining = farther
            low = mid
        }
    }
    
    // Return the k closest points using the reference indices
    return closest.map(i => points[i])
};

var splitDistances = function(remaining, distances, mid) {
    // Split the distances around the midpoint
    // and return them in separate arrays
    let closer = [], farther = []
    for (let index of remaining) {
        if (distances[index] <= mid) {
            closer.push(index)
        } else {
            farther.push(index)
        }
    }
    return [closer, farther]
};

// Calculate and return the squared Euclidean distance
const euclideanDistance = ([x,y]) => x ** 2 + y ** 2
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # Precompute the Euclidean distance for each point
        distances = [self.euclidean_distance(point) for point in points]
        # Create a reference list of point indices
        remaining = [i for i in range(len(points))]
        # Define the initial binary search range
        low, high = 0, max(distances)
        
        # Perform a binary search of the distances
        # to find the k closest points
        closest = []
        while k:
            mid = (low + high) / 2
            closer, farther = self.split_distances(remaining, distances, mid)
            if len(closer) > k:
                # If more than k points are in the closer distances
                # then discard the farther points and continue
                remaining = closer
                high = mid
            else:
                # Add the closer points to the answer array and keep
                # searching the farther distances for the remaining points
                k -= len(closer)
                closest.extend(closer)
                remaining = farther
                low = mid
                
        # Return the k closest points using the reference indices
        return [points[i] for i in closest]

    def split_distances(self, remaining: List[int], distances: List[float],
                        mid: int) -> List[List[int]]:
        """Split the distances around the midpoint
        and return them in separate lists."""
        closer, farther = [], []
        for index in remaining:
            if distances[index] <= mid:
                closer.append(index)
            else:
                farther.append(index)
        return [closer, farther]

    def euclidean_distance(self, point: List[int]) -> float:
        """Calculate and return the squared Euclidean distance."""
        return point[0] ** 2 + point[1] ** 2
```

</details>

<br>

## Approach 4: QuickSelect

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
private:
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivotIndex = points.size();
        while (pivotIndex != k) {
            // Repeatedly partition the vector
            // while narrowing in on the kth element
            pivotIndex = partition(points, left, right);
            if (pivotIndex < k) {
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        // Return the first k elements of the partially sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    };

    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int>& pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (squaredDistance(points[left]) >= pivotDist) {
                points[left].swap(points[right]);
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (squaredDistance(points[left]) < pivotDist)
            left++;
        return left;
    };

    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        // Choose a pivot element of the vector
        return points[left + (right - left) / 2];
    }
    
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] kClosest(int[][] points, int k) {
        return quickSelect(points, k);
    }
    
    private int[][] quickSelect(int[][] points, int k) {
        int left = 0, right = points.length - 1;
        int pivotIndex = points.length;
        while (pivotIndex != k) {
            // Repeatedly partition the array
            // while narrowing in on the kth element
            pivotIndex = partition(points, left, right);
            if (pivotIndex < k) {
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        // Return the first k elements of the partially sorted array
        return Arrays.copyOf(points, k);
    }

    private int partition(int[][] points, int left, int right) {
        int[] pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (squaredDistance(points[left]) >= pivotDist) {
                int[] temp = points[left];
                points[left] = points[right];
                points[right] = temp; 
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (squaredDistance(points[left]) < pivotDist)
            left++;
        return left;
    }

    private int[] choosePivot(int[][] points, int left, int right) {
        // Choose a pivot element of the array
        return points[left + (right - left) / 2];
    }
    
    private int squaredDistance(int[] point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var kClosest = function(points, k) {
    return quickSelect(points, k)
};

var quickSelect = function(points, k) {
    let left = 0, right = points.length - 1
    let pivotIndex = points.length
    while (pivotIndex !== k) {
        // Repeatedly partition the array
        // while narrowing in on the kth element
        pivotIndex = partition(points, left, right)
        if (pivotIndex < k) {
            left = pivotIndex
        } else {
            right = pivotIndex - 1
        }
    }
    
    // Return the first k elements of the partially sorted array
    return points.slice(0, k)
};

var partition = function(points, left, right) {
    let pivot = choosePivot(points, left, right)
    let pivotDist = squaredDistance(pivot)
    while (left < right) {
        // Iterate through the range and swap elements to make sure
        // that all points closer than the pivot are to the left
        if (squaredDistance(points[left]) >= pivotDist) {
           [points[left], points[right]] = [points[right], points[left]]
            right--
        } else {
            left++
        }
    }
    
    // Ensure the left pointer is just past the end of
    // the left range then return it as the new pivotIndex
    if (squaredDistance(points[left]) < pivotDist)
        left++
    return left
};

// Choose a pivot element of the array
const choosePivot = (points, left, right) => points[left + ((right - left) >> 1)]

// Calculate and return the squared Euclidean distance
const squaredDistance = ([x,y]) => x ** 2 + y ** 2
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        return self.quick_select(points, k)
    
    def quick_select(self, points: List[List[int]], k: int) -> List[List[int]]:
        """Perform the QuickSelect algorithm on the list"""
        left, right = 0, len(points) - 1
        pivot_index = len(points)
        while pivot_index != k:
            # Repeatedly partition the list
            # while narrowing in on the kth element
            pivot_index = self.partition(points, left, right)
            if pivot_index < k:
                left = pivot_index
            else:
                right = pivot_index - 1
        
        # Return the first k elements of the partially sorted list
        return points[:k]
    
    def partition(self, points: List[List[int]], left: int, right: int) -> int:
        """Partition the list around the pivot value"""
        pivot = self.choose_pivot(points, left, right)
        pivot_dist = self.squared_distance(pivot)
        while left < right:
            # Iterate through the range and swap elements to make sure
            # that all points closer than the pivot are to the left
            if self.squared_distance(points[left]) >= pivot_dist:
                points[left], points[right] = points[right], points[left]
                right -= 1
            else:
                left += 1
        
        # Ensure the left pointer is just past the end of
        # the left range then return it as the new pivotIndex
        if self.squared_distance(points[left]) < pivot_dist:
            left += 1
        return left
    
    def choose_pivot(self, points: List[List[int]], left: int, right: int) -> List[int]:
        """Choose a pivot element of the list"""
        return points[left + (right - left) // 2]
    
    def squared_distance(self, point: List[int]) -> int:
        """Calculate and return the squared Euclidean distance."""
        return point[0] ** 2 + point[1] ** 2
```

</details>
