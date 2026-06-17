# 364. Nested List Weight Sum II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/nested-list-weight-sum-ii/)  
`Stack` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 364 - Nested List Weight Sum II](https://leetcode.com/problems/nested-list-weight-sum-ii/)

## Problem

You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth. Let maxDepth be the maximum depth of any integer.

The weight of an integer is maxDepth - (the depth of the integer) + 1.

Return the sum of each integer in nestedList multiplied by its weight.

### Example 1

```text
Input: nestedList = [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's with a weight of 1, one 2 with a weight of 2.
1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8
```

### Example 2

```text
Input: nestedList = [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1.
1*3 + 4*2 + 6*1 = 17
```

## Constraints

- 1 <= nestedList.length <= 50
- The values of the integers in the nested list is in the range [-100, 100].
- The maximum depth of any integer is less than or equal to 50.
- There are no empty lists.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Nested List Weight Sum](https://leetcode.com/problems/nested-list-weight-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Array Nesting](https://leetcode.com/problems/array-nesting/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 364. Nested List Weight Sum II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Double Pass Depth-First Search (DFS) | C++, Java |
| Single Pass Depth-First Search (DFS) | C++, Java |
| Single Pass Breadth-First Search (BFS) | C++, Java |

## Approach 1: Double Pass Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = findMaxDepth(nestedList);
        return weightedSum(nestedList, 1, maxDepth);
    }
    
    int findMaxDepth(vector<NestedInteger>& list) {
        int maxDepth = 1;
        for (NestedInteger nested : list) {
            if (!nested.isInteger() && nested.getList().size() > 0) {
                maxDepth = max(maxDepth, 1 + findMaxDepth(nested.getList()));
            }
        }
        return maxDepth;
    }
    
    int weightedSum(vector<NestedInteger>& list, int depth, int maxDepth) {
        int answer = 0;
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                answer += nested.getInteger() * (maxDepth - depth + 1);
            } else {
                answer += weightedSum(nested.getList(), depth + 1, maxDepth);
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
    public int depthSumInverse(List<NestedInteger> nestedList) {
        int maxDepth = findMaxDepth(nestedList);
        return weightedSum(nestedList, 1, maxDepth);
    }

    private int findMaxDepth(List<NestedInteger> list) {
        int maxDepth = 1;
        
        for (NestedInteger nested : list) {
            if (!nested.isInteger() && nested.getList().size() > 0) {
                maxDepth = Math.max(maxDepth, 1 + findMaxDepth(nested.getList()));
            }
        }
        
        return maxDepth;
    }
    
    private int weightedSum(List<NestedInteger> list, int depth, int maxDepth) {
        int answer = 0;
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                answer += nested.getInteger() * (maxDepth - depth + 1);
            } else {
                answer += weightedSum(nested.getList(), depth + 1, maxDepth);
            }
        }
        return answer;
    }
}
```

</details>

<br>

## Approach 2: Single Pass Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class WeightedSumTriplet {
public:
    int maxDepth;
    int sumOfElements;
    int sumOfProducts;
    
    WeightedSumTriplet(int maxDepth, int sumOfElements, int sumOfProducts) {
        this->maxDepth = maxDepth;
        this->sumOfElements = sumOfElements;
        this->sumOfProducts = sumOfProducts;
    }
};

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        WeightedSumTriplet weightedSumTriplet = getWeightedSumTriplet(nestedList, 1);
        int maxDepth = weightedSumTriplet.maxDepth;
        int sumOfElements = weightedSumTriplet.sumOfElements;
        int sumOfProducts = weightedSumTriplet.sumOfProducts;
        
        return (maxDepth + 1) * sumOfElements - sumOfProducts;
    }
    
    WeightedSumTriplet getWeightedSumTriplet(vector<NestedInteger>& list, int depth) {
        int sumOfProducts = 0;
        int sumOfElements = 0;
        int maxDepth = 0;
        
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                sumOfProducts += nested.getInteger() * depth;
                sumOfElements += nested.getInteger();
                maxDepth = max(maxDepth, depth);
            } else {
                WeightedSumTriplet result = getWeightedSumTriplet(nested.getList(), depth + 1);
                sumOfProducts += result.sumOfProducts;
                sumOfElements += result.sumOfElements;
                maxDepth = max(maxDepth, result.maxDepth);
            }
        }
        return WeightedSumTriplet(maxDepth, sumOfElements, sumOfProducts);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class WeightedSumTriplet {
    int maxDepth;
    int sumOfElements;
    int sumOfProducts;

    WeightedSumTriplet(int maxDepth, int sumOfElements, int sumOfProducts) {
        this.maxDepth = maxDepth;
        this.sumOfElements = sumOfElements;
        this.sumOfProducts = sumOfProducts;
    }
}

class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        WeightedSumTriplet weightedSumTriplet = getWeightedSumTriplet(nestedList, 1);
        int maxDepth = weightedSumTriplet.maxDepth;
        int sumOfElements = weightedSumTriplet.sumOfElements;
        int sumOfProducts = weightedSumTriplet.sumOfProducts;
        
        return (maxDepth + 1) * sumOfElements - sumOfProducts;
    }

    private WeightedSumTriplet getWeightedSumTriplet(List<NestedInteger> list, int depth) {
        int sumOfProducts = 0;
        int sumOfElements = 0;
        int maxDepth = 0;
        
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                sumOfProducts += nested.getInteger() * depth;
                sumOfElements += nested.getInteger();
                maxDepth = Math.max(maxDepth, depth);
            } else {
                WeightedSumTriplet result = getWeightedSumTriplet(nested.getList(), depth + 1);
                sumOfProducts += result.sumOfProducts;
                sumOfElements += result.sumOfElements;
                maxDepth = Math.max(maxDepth, result.maxDepth);
            }
        }
        
        return new WeightedSumTriplet(maxDepth, sumOfElements, sumOfProducts);
    }
}
```

</details>

<br>

## Approach 3: Single Pass Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> Q;
        for (NestedInteger nested : nestedList) {
            Q.push(nested);
        }

        int depth = 1;
        int maxDepth = 0;
        int sumOfElements = 0;
        int sumOfProducts = 0;

        while (!Q.empty()) {
            int size = Q.size();
            maxDepth = max(maxDepth, depth);
            
            for (int i = 0; i < size; i++) {
                NestedInteger nested = Q.front(); 
                Q.pop();
                
                if (nested.isInteger()) {
                    sumOfElements += nested.getInteger();
                    sumOfProducts += nested.getInteger() * depth;
                } else {
                    for (NestedInteger nestedNextLevel : nested.getList()) {
                        Q.push(nestedNextLevel);
                    }
                }
            }
            depth++;
        }
        return (maxDepth + 1) * sumOfElements - sumOfProducts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        Queue<NestedInteger> Q = new LinkedList<>();
        Q.addAll(nestedList);

        int depth = 1;
        int maxDepth = 0;
        int sumOfElements = 0;
        int sumOfProducts = 0;

        while (!Q.isEmpty()) {
            int size = Q.size();
            maxDepth = Math.max(maxDepth, depth);
            
            for (int i = 0; i < size; i++) {
                NestedInteger nested = Q.poll();
                
                if (nested.isInteger()) {
                    sumOfElements += nested.getInteger();
                    sumOfProducts += nested.getInteger() * depth;
                } else {
                    Q.addAll(nested.getList());
                }
            }
            depth++;
        }
        return (maxDepth + 1) * sumOfElements - sumOfProducts;
    }
}
```

</details>
