# 1231. Divide Chocolate

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/divide-chocolate/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1231 - Divide Chocolate](https://leetcode.com/problems/divide-chocolate/)

## Problem

You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 pieces using k cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

### Example 1

```text
Input: sweetness = [1,2,3,4,5,6,7,8,9], k = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
```

### Example 2

```text
Input: sweetness = [5,6,7,8,9,1,2,3,4], k = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.
```

### Example 3

```text
Input: sweetness = [1,2,2,1,2,2,1,2,2], k = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
```

## Constraints

- 0 <= k < sweetness.length <= 104
- 1 <= sweetness[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1231. Divide Chocolate

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search + Greedy | C++, Java, JavaScript, Python3 |

## Approach 1: Binary Search + Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        // Initialize the left and right boundaries.
        // left = 1 and right = total sweetness / number of people.
        int numberOfPeople = k + 1;
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0) / numberOfPeople;
        
        while (left < right) { 
            // Get the middle index between left and right boundary indexes.
            // cur_sweetness stands for the total sweetness for the current person.
            // people_with_chocolate stands for the number of people that have 
            // a piece of chocolate of sweetness greater than or equal to mid.  
            int mid = (left + right + 1) / 2;
            int curSweetness = 0;
            int peopleWithChocolate = 0;
            
            // Start assigning chunks to the current people,.
            for (int s : sweetness) {
                curSweetness += s;
                
                // When the total sweetness from him is no less than mid, meaning we 
                // have done with him and move on to assigning chunks to the next people.
                if (curSweetness >= mid) {
                    peopleWithChocolate += 1;
                    curSweetness = 0;
                }
            }
            
            // Check if we successfully give everyone a piece of chocolate with sweetness
            // no less than mid, and eliminate the search space by half.
            if (peopleWithChocolate >= numberOfPeople) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        // Once the left and right boundaries coincide, we find the target value,
        // that is, the maximum possible sweetness we can get.
        return right;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximizeSweetness(int[] sweetness, int k) {
        // Initialize the left and right boundaries.
        // left = 1 and right = total sweetness / number of people.
        int numberOfPeople = k + 1;
        int left = Arrays.stream(sweetness).min().getAsInt();
        int right = Arrays.stream(sweetness).sum() / numberOfPeople;

        while (left < right) {
            // Get the middle index between left and right boundary indexes.
            // cur_sweetness stands for the total sweetness for the current person.
            // people_with_chocolate stands for the number of people that have 
            // a piece of chocolate of sweetness greater than or equal to mid.  
            int mid = (left + right + 1) / 2;
            int curSweetness = 0;
            int peopleWithChocolate = 0;
            
            // Start assigning chunks to the current people,.
            for (int s : sweetness) {
                curSweetness += s;
                
                // If the total sweetness for him is no less than mid, meaning we 
                // have done with him and should move on to assigning chunks to the next people.
                if (curSweetness >= mid) {
                    peopleWithChocolate += 1;
                    curSweetness = 0;
                }
            }
            
            // Check if we successfully give everyone a piece of chocolate with sweetness
            // no less than mid, and eliminate the search space by half.
            if (peopleWithChocolate >= numberOfPeople) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        // Once the left and right boundaries coincide, we find the target value,
        // that is, the maximum possible sweetness we can get.
        return right;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximizeSweetness = function(sweetness, k) {
    // Initialize the left and right boundaries.
    // left = 1 and right = total sweetness / number of people.
    let numberOfPeople = k + 1;
    let left = Math.min(...sweetness);
    let right = Math.floor(sweetness.reduce((x, y) => x + y) / numberOfPeople);
    
    while (left < right) {
        // Get the middle index between left and right boundary indexes.
        // cur_sweetness stands for the total sweetness for the current person.
        // people_with_chocolate stands for the number of people that have 
        // a piece of chocolate of sweetness greater than or equal to mid.  
        const mid = Math.floor((left + right + 1) / 2);
        let curSweetness = 0;
        let peopleWithChocolate = 0;
        
        // Start assigning chunks to the current people.
        for (const s of sweetness) {
            curSweetness += s;
            
            // If the total sweetness for him is no less than mid, meaning we 
            // have done with him and should move on to assigning chunks to the next people.
            if (curSweetness >= mid) {
                peopleWithChocolate += 1;
                curSweetness = 0;
            }
        }
        
        // Check if we successfully give everyone a piece of chocolate with sweetness
        // no less than mid, and eliminate the search space by half.
        if (peopleWithChocolate >= numberOfPeople) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    // Once the left and right boundaries concide, we find the target value,
    // that is, the maximum possible sweetness I can get.
    return right;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximizeSweetness(self, sweetness: List[int], k: int) -> int:
        # Initialize the left and right boundaries.
        # left = 1 and right = (total sweetness) / (number of people).
        number_of_people = k + 1
        left = min(sweetness)
        right = sum(sweetness) // number_of_people
        
        while left < right:
            # Get the middle index between left and right boundary indexes.
            # cur_sweetness stands for the total sweetness for the current person.
            # people_with_chocolate stands for the number of people that have 
            # a piece of chocolate of sweetness greater than or equal to mid.  
            mid = (left + right + 1) // 2
            cur_sweetness = 0
            people_with_chocolate = 0
            
            # Start assigning chunks to the current person.
            for s in sweetness:
                cur_sweetness += s
                
                # If the total sweetness is no less than mid, this means we can break off
                # the current piece and move on to assigning chunks to the next person.
                if cur_sweetness >= mid:
                    people_with_chocolate += 1
                    cur_sweetness = 0

            if people_with_chocolate >= k + 1:
                left = mid
            else:
                right = mid - 1
                
        return right
```

</details>
