# 740. Delete and Earn

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/delete-and-earn/)  
`Array` `Hash Table` `Dynamic Programming`

**Problem Link:** [LeetCode 740 - Delete and Earn](https://leetcode.com/problems/delete-and-earn/)

## Problem

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

- Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.

### Example 1

```text
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
```

### Example 2

```text
Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
```

## Constraints

- 1 <= nums.length <= 2 * 104
- 1 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 740. Delete and Earn

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | Java, Python3 |
| Bottom-Up Dynamic Programming | Java, Python3 |
| Space Optimized Bottom-Up Dynamic Programming | Java, Python3 |
| Iterate Over Elements | Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<Integer, Integer> points = new HashMap<>();
    private HashMap<Integer, Integer> cache = new HashMap<>();
    
    private int maxPoints(int num) {
        // Check for base cases
        if (num == 0) {
            return 0;
        }
        
        if (num == 1) {
            return points.getOrDefault(1, 0);
        }
        
        if (cache.containsKey(num)) {
            return cache.get(num);
        }
        
        // Apply recurrence relation
        int gain = points.getOrDefault(num, 0);
        cache.put(num, Math.max(maxPoints(num - 1), maxPoints(num - 2) + gain));
        return cache.get(num);
    }
    
    public int deleteAndEarn(int[] nums) {
        int maxNumber = 0;
        
        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points.put(num, points.getOrDefault(num, 0) + num);
            maxNumber = Math.max(maxNumber, num);
        }
        
        return maxPoints(maxNumber);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points = defaultdict(int)
        max_number = 0
        # Precompute how many points we gain from taking an element
        for num in nums:
            points[num] += num
            max_number = max(max_number, num)

        @cache
        def max_points(num):
            # Check for base cases
            if num == 0:
                return 0
            if num == 1:
                return points[1]
            
            # Apply recurrence relation
            return max(max_points(num - 1), max_points(num - 2) + points[num])
        
        return max_points(max_number)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int deleteAndEarn(int[] nums) {
        HashMap<Integer, Integer> points = new HashMap<>();
        int maxNumber = 0;
        
        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points.put(num, points.getOrDefault(num, 0) + num);
            maxNumber = Math.max(maxNumber, num);
        }
        
        // Declare our array along with base cases
        int[] maxPoints = new int[maxNumber + 1];
        maxPoints[1] = points.getOrDefault(1, 0);
        
        for (int num = 2; num < maxPoints.length; num++) {
            // Apply recurrence relation
            int gain = points.getOrDefault(num, 0);
            maxPoints[num] = Math.max(maxPoints[num - 1], maxPoints[num - 2] + gain);
        }
        
        return maxPoints[maxNumber];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points = defaultdict(int)
        max_number = 0
        # Precompute how many points we gain from taking an element
        for num in nums:
            points[num] += num
            max_number = max(max_number, num)

        # Declare our array along with base cases
        max_points = [0] * (max_number + 1)
        max_points[1] = points[1]

        for num in range(2, len(max_points)):
            # Apply recurrence relation
            max_points[num] = max(max_points[num - 1], max_points[num - 2] + points[num])
        
        return max_points[max_number]
```

</details>

<br>

## Approach 3: Space Optimized Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int deleteAndEarn(int[] nums) {
        int maxNumber = 0;
        HashMap<Integer, Integer> points = new HashMap<>();
        
        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points.put(num, points.getOrDefault(num, 0) + num);
            maxNumber = Math.max(maxNumber, num);
        }
        
        // Base cases
        int twoBack = 0;
        int oneBack = points.getOrDefault(1, 0);
        
        for (int num = 2; num <= maxNumber; num++) {
            int temp = oneBack;
            oneBack = Math.max(oneBack, twoBack + points.getOrDefault(num, 0));
            twoBack = temp;
        }
        
        return oneBack;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points = {}
        max_number = 0
        # Precompute how many points we gain from taking an element
        for num in nums:
            points[num] = points.get(num, 0) + num
            max_number = max(max_number, num)
        
        # Base cases
        two_back = 0
        one_back = points.get(1, 0)
        
        for num in range(2, max_number + 1):
            two_back, one_back = one_back, max(one_back, two_back + points.get(num, 0))

        return one_back
```

</details>

<br>

## Approach 4: Iterate Over Elements

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int deleteAndEarn(int[] nums) {
        HashMap<Integer, Integer> points = new HashMap<>();
        
        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points.put(num, points.getOrDefault(num, 0) + num);
        }
        
        List<Integer> elements = new ArrayList<Integer>(points.keySet());
        Collections.sort(elements);
        
        // Base cases
        int twoBack = 0;
        int oneBack = points.get(elements.get(0));
        
        for (int i = 1; i < elements.size(); i++) {
            int currentElement = elements.get(i);
            int temp = oneBack;
            if (currentElement == elements.get(i - 1) + 1) {
                // The 2 elements are adjacent, cannot take both - apply normal recurrence
                oneBack = Math.max(oneBack, twoBack + points.get(currentElement));
            } else {
                // Otherwise, we don't need to worry about adjacent deletions
                oneBack += points.get(currentElement);
            }

            twoBack = temp;
        }
        
        return oneBack;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points = defaultdict(int)
        # Precompute how many points we gain from taking an element
        for num in nums:
            points[num] += num
            
        elements = sorted(points.keys())
        two_back = 0
        one_back = points[elements[0]]
        
        for i in range(1, len(elements)):
            current_element = elements[i]
            if current_element == elements[i - 1] + 1:
                # The 2 elements are adjacent, cannot take both - apply normal recurrence
                two_back, one_back = one_back, max(one_back, two_back + points[current_element])
            else:
                # Otherwise, we don't need to worry about adjacent deletions
                two_back, one_back = one_back, one_back + points[current_element]

        return one_back
```

</details>
