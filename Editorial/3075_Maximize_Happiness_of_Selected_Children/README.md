# 3075. Maximize Happiness of Selected Children

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximize-happiness-of-selected-children/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 3075 - Maximize Happiness of Selected Children](https://leetcode.com/problems/maximize-happiness-of-selected-children/)

## Problem

You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

### Example 1

```text
Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: We can pick 2 children in the following way:
- Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
- Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
The sum of the happiness values of the selected children is 3 + 1 = 4.
```

### Example 2

```text
Input: happiness = [1,1,1,1], k = 2
Output: 1
Explanation: We can pick 2 children in the following way:
- Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
- Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
The sum of the happiness values of the selected children is 1 + 0 = 1.
```

### Example 3

```text
Input: happiness = [2,3,4,5], k = 1
Output: 5
Explanation: We can pick 1 child in the following way:
- Pick the child with the happiness value == 5. The happiness value of the remaining children becomes [1,2,3].
The sum of the happiness values of the selected children is 5.
```

## Constraints

- 1 <= n == happiness.length <= 2 * 105
- 1 <= happiness[i] <= 108
- 1 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3075. Maximize Happiness of Selected Children

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort + Greedy | C++, Java, Python3 |
| Max Heap / Priority Queue + Greedy | C++, Java, Python3 |

## Approach 1: Sort + Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long totalHappinessSum = 0;
        int turns = 0;
        
        // Calculate the maximum happiness sum
        for(int i = 0; i < k; i++) {
            // Adjust happiness and ensure it's not negative
            totalHappinessSum += max(happiness[i] - turns, 0);  

            // Increment turns for the next iteration
            turns++; 
        }
        
        return totalHappinessSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int happinessSize = happiness.length;
        
        // Convert the array to an Integer array for sorting in descending order
        Integer[] happinessArray = new Integer[happinessSize];
        for(int i = 0; i < happinessSize; i++) {
            happinessArray[i] = happiness[i];
        }
        
        Arrays.sort(happinessArray, Collections.reverseOrder());

        long totalHappinessSum = 0;
        int turns = 0;
        
        // Calculate the maximum happiness sum
        for(int i = 0; i < k; i++) {
            // Adjust happiness and ensure it's not negative
            totalHappinessSum += Math.max(happinessArray[i] - turns, 0);  

             // Increment turns for the next iteration
            turns++; 
        }
        
        return totalHappinessSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        # Sort in descending order
        happiness.sort(reverse=True)

        total_happiness_sum = 0
        turns = 0

        # Calculate the maximum happiness sum
        for i in range(k):
            # Adjust happiness and ensure it's not negative
            total_happiness_sum += max(happiness[i] - turns, 0)

            # Increment turns for the next iteration
            turns += 1

        return total_happiness_sum
```

</details>

<br>

## Approach 2: Max Heap / Priority Queue + Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Max heap by default
        priority_queue<int> pq; 

        // Push all the happiness values into the priority queue
        for(const auto& h: happiness)
            pq.push(h); 

        long long totalHappinessSum = 0;
        int turns = 0;

        for(int i = 0; i < k; i++) {
            // Add the current highest value to the total happiness sum
            totalHappinessSum += max(pq.top() - turns, 0);

            // Remove the highest value after using it
            pq.pop(); 

            // Increment turns for the next iteration
            turns++; 
        }

        return totalHappinessSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        // Create a max heap using PriorityQueue with a custom comparator
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        // Add all elements to the priority queue
        for (int h : happiness) {
            pq.add(h);
        }

        long totalHappinessSum = 0;
        int turns = 0;

        for (int i = 0; i < k; i++) {
            // Add the current highest value to the total happiness sum and remove it from the max heap 
            totalHappinessSum += Math.max(pq.poll() - turns, 0);

            // Increment turns for the next iteration
            turns++;
        }

        return totalHappinessSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        # Convert the list into a max heap by inverting the happiness values 
        # Python's default heap data structure is a min heap
        max_heap = [-h for h in happiness]
        heapq.heapify(max_heap)
        
        total_happiness_sum = 0
        turns = 0

        for i in range(k):
            # Invert again to get the original value
            total_happiness_sum += max(-heapq.heappop(max_heap) - turns, 0)

            # Increment turns for the next iteration
            turns += 1
            
        return total_happiness_sum
```

</details>
