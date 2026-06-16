# 1762. Buildings With an Ocean View

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/buildings-with-an-ocean-view/)  
`Array` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 1762 - Buildings With an Ocean View](https://leetcode.com/problems/buildings-with-an-ocean-view/)

## Problem

There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

### Example 1

```text
Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
```

### Example 2

```text
Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.
```

### Example 3

```text
Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.
```

## Constraints

- 1 <= heights.length <= 105
- 1 <= heights[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Visible People in a Queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Finding the Number of Visible Mountains](https://leetcode.com/problems/finding-the-number-of-visible-mountains/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1762. Buildings With an Ocean View

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Iteration | C++, Java, JavaScript, Python3 |
| Monotonic Stack | C++, Java, JavaScript, Python3 |
| Monotonic Stack Space Optimization | C++, Java, JavaScript, Python3 |

## Approach 1: Linear Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer;
        
        for (int current = 0; current < n; ++current) {
            // If the current building is taller, 
            // it will block the shorter building's ocean view to its left.
            // So we pop all the shorter buildings that have been added before.
            while (!answer.empty() && heights[answer.back()] <= heights[current]) {
                answer.pop_back();
            }
            answer.push_back(current);
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
    public int[] findBuildings(int[] heights) {
        int n = heights.length;
        List<Integer> list = new ArrayList<>();
        
        for (int current = 0; current < n; ++current) {
            // If the current building is taller, 
            // it will block the shorter building's ocean view to its left.
            // So we pop all the shorter buildings that have been added before.
            while (!list.isEmpty() && heights[list.get(list.size() - 1)] <= heights[current]) {
                list.remove(list.size() - 1);
            }
            list.add(current);
        }
 
        // Push elements from list to answer array.
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let findBuildings = function(heights) {
    let n = heights.length;
    let answer = [];

    for (let current = 0; current < n; ++current) {
        // If the current building is taller, 
        // it will block the shorter building's ocean view to its left.
        // So we pop all the shorter buildings that have been added before.
        while (answer.length && heights[answer[answer.length - 1]] <= heights[current]) {
            answer.pop();
        }
        answer.push(current);
    }

    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        n = len(heights)
        answer = []

        for current in range(n):
            # If the current building is taller, 
            # it will block the shorter building's ocean view to its left.
            # So we pop all the shorter buildings that have been added before.
            while answer and heights[answer[-1]] <= heights[current]:
                answer.pop()
            answer.append(current)
            
        return answer
```

</details>

<br>

## Approach 2: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer;
        stack<int> st;
        
        for (int current = n - 1; current >= 0; --current) {
            // If the building to the right is smaller, we can pop it.
            while (!st.empty() && heights[st.top()] < heights[current]) {
                st.pop();
            }
            
            // If the stack is empty, it means there is no building to the right 
            // that can block the view of the current building.
            if (st.size() == 0) { 
                answer.push_back(current);
            }
            
            // Push the current building in the stack.
            st.push(current);
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findBuildings(int[] heights) {
        int n = heights.length;
        List<Integer> list = new ArrayList<>();
        
        // Monotonically decreasing stack.
        Stack<Integer> stack = new Stack<>();  
        for (int current = n - 1; current >= 0; --current) {
            // If the building to the right is smaller, we can pop it.
            while (!stack.isEmpty() && heights[stack.peek()] < heights[current]) {
                stack.pop();
            }
            
            // If the stack is empty, it means there is no building to the right 
            // that can block the view of the current building.
            if (stack.isEmpty()) { 
                list.add(current);
            }
            
            // Push the current building in the stack.
            stack.push(current);
        }
 
        // Push elements from list to answer array in reverse order.
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) {
            answer[i] = list.get(list.size() - 1 - i);
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let findBuildings = function(heights) {
    let n = heights.length;
    let answer = [];

    // Monotonically decreasing stack.
    let stack = [];

    for (let current = n - 1; current >= 0; --current) {

        // If the building to the right is smaller, we can pop it.
        while (stack.length && heights[stack[stack.length - 1]] < heights[current]) {
            stack.pop();
        }

        // If the stack is empty, it means there is no building to the right 
        // that can block the view of the current building.
        if (stack.length == 0) { 
            answer.push(current);
        }

        //  Push the current building in the stack.
        stack.push(current);
    }

    answer.reverse();
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        n = len(heights)
        answer = []
        
        # Monotonically decreasing stack.
        stack = []
        for current in reversed(range(n)):
            # If the building to the right is smaller, we can pop it.
            while stack and heights[stack[-1]] < heights[current]:
                stack.pop()
            
            # If the stack is empty, it means there is no building to the right 
            # that can block the view of the current building.
            if not stack:
                answer.append(current)
            
            # Push the current building in the stack.
            stack.append(current)
        
        answer.reverse()
        return answer
```

</details>

<br>

## Approach 3: Monotonic Stack Space Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int> answer;
        int maxHeight = -1;
        
        for (int current = n - 1; current >= 0; --current) {
            // If there is no building higher (or equal) than the current one to its right,
            // push it in the answer array.
            if (maxHeight < heights[current]) {
                answer.push_back(current);
                
                // Update the max building till now.
                maxHeight = heights[current];
            }
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findBuildings(int[] heights) {
        int n = heights.length;
        List<Integer> list = new ArrayList<>();
        int maxHeight = -1;
        
        for (int current = n - 1; current >= 0; --current) {
            // If there is no building higher (or equal) than the current one to its right,
            // push it in the list.
            if (maxHeight < heights[current]) {
                list.add(current);
                
                // Update max building till now.
                maxHeight = heights[current];
            }
        }
        
        // Push building indices from list to answer array in reverse order.
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) {
            answer[i] = list.get(list.size() - 1 - i);
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let findBuildings = function(heights) {
    let n = heights.length;
    let answer = [];
    let maxHeight = -1; 
    
    for (let current = n - 1; current >= 0; --current) {
        
        // If there is no building higher (or equal) than the current one to its right,
        // push it in the answer array.
        if (maxHeight < heights[current]) {
            answer.push(current);
            
            // Update max building till now.
            maxHeight = heights[current];
        }
    }
    answer.reverse();
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        n = len(heights)
        answer = []
        max_height = -1
        
        for current in reversed(range(n)):
            # If there is no building higher (or equal) than the current one to its right,
            # push it in the answer array.
            if max_height < heights[current]:
                answer.append(current)
            
                # Update max building till now.
                max_height = heights[current]
        
        answer.reverse()
        return answer
```

</details>
