# 875. Koko Eating Bananas

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/koko-eating-bananas/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 875 - Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

## Problem

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

### Example 1

```text
Input: piles = [3,6,7,11], h = 8
Output: 4
```

### Example 2

```text
Input: piles = [30,11,23,4,20], h = 5
Output: 30
```

### Example 3

```text
Input: piles = [30,11,23,4,20], h = 6
Output: 23
```

## Constraints

- 1 <= piles.length <= 104
- piles.length <= h <= 109
- 1 <= piles[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimize Max Distance to Gas Station](https://leetcode.com/problems/minimize-max-distance-to-gas-station/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Frog Jump II](https://leetcode.com/problems/frog-jump-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Time to Repair Cars](https://leetcode.com/problems/minimum-time-to-repair-cars/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 875. Koko Eating Bananas

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, JavaScript, Python3 |
| Binary Search | C++, Java, JavaScript, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {    
        // Start at an eating speed of 1.
        int speed = 1;

        while (true) {
            // hourSpent stands for the total number of hours that
            // Koko has spent with the current eating speed.
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / speed)
            for (int pile : piles) {
                hourSpent += pile / speed + (pile % speed != 0);
                if (hourSpent > h) {
                    break;
                }
            }

            // Check if Koko can finish all the piles within h hours,
            // If so, return speed. Otherwise, let speed increment by
            // 1 and repeat the previous iteration.
            if (hourSpent <= h) {
                return speed;
            } else {
                speed += 1;
            }            
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        // Start at an eating speed of 1.
        int speed = 1;

        while (true) {
            // hourSpent stands for the total hour Koko spends with 
            // the given eating speed.
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / speed)
            for (int pile : piles) {
                hourSpent += Math.ceil((double) pile / speed);
                if (hourSpent > h) {
                    break;
                }
            }

            // Check if Koko can finish all the piles within h hours,
            // If so, return speed. Otherwise, let speed increment by
            // 1 and repeat the previous iteration.
            if (hourSpent <= h) {
                return speed;
            } else {
                speed += 1;
            }            
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minEatingSpeed = function(piles, h) {
    // Start at an eating speed of 1.
    let speed = 1;

    while (true) {
        // hourSpent stands for the total hour Koko spends with 
        // the given eating speed.
        let hourSpent = 0;

        // Iterate over the piles and calculate hourSpent.
        // We increase the hourSpent by ceil(pile / speed)
        for (const pile of piles) {
            hourSpent += Math.ceil(pile / speed);
        }        
        
        // Check if Koko can finish all the piles within h hours,
        // If so, return speed. Otherwise, let speed increment by
        // 1 and repeat the previous iteration.
        if (hourSpent <= h) {
            return speed;
        } else {
            speed += 1;
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        #Start at an eating speed of 1.
        speed = 1

        while True:
            # hour_spent stands for the total hour Koko spends with 
            # the given eating speed.
            hour_spent = 0

            # Iterate over the piles and calculate hour_spent.
            # We increase the hour_spent by ceil(pile / speed)
            for pile in piles:
                hour_spent += math.ceil(pile / speed)    

            # Check if Koko can finish all the piles within h hours,
            # If so, return speed. Otherwise, let speed increment by
            # 1 and repeat the previous iteration.                
            if hour_spent <= h:
                return speed
            else:
                speed += 1
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     
        // Initalize the left and right boundaries 
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            // Get the middle index between left and right boundary indexes.
            // hourSpent stands for the total hour Koko spends.
            int middle = (left + right) / 2;
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / middle).
            for (int pile : piles) {
                hourSpent += pile / middle + (pile % middle != 0);
            }

            // Check if middle is a workable speed, and cut the search space by half.
            if (hourSpent <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target value,
        // that is, the minimum workable eating speed.
        return right;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        // Initalize the left and right boundaries 
        int left = 1, right = 1;
        for (int pile : piles) {
            right = Math.max(right, pile);
        }

        while (left < right) {
            // Get the middle index between left and right boundary indexes.
            // hourSpent stands for the total hour Koko spends.
            int middle = (left + right) / 2;
            int hourSpent = 0;

            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / middle)
            for (int pile : piles) {
                hourSpent += Math.ceil((double) pile / middle);
            }

            // Check if middle is a workable speed, and cut the search space by half.
            if (hourSpent <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target value,
        // that is, the minimum workable eating speed.
        return right;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minEatingSpeed = function(piles, h) {
    // Initalize the left and right boundaries 
    let left = 1, right = 1;
    for (const pile of piles) {
        right = Math.max(right, pile);
    }

    while (left < right) {
        // Get the middle index between left and right boundary indexes.
        // hourSpent stands for the total hour Koko spends.
        let middle = Math.floor((left + right) / 2);
        let hourSpent = 0;

        // Iterate over the piles and calculate hourSpent.
        // We increase the hourSpent by ceil(pile / middle)
        for (const pile of piles) {
            hourSpent += Math.ceil(pile / middle);
        }

        // Check if middle is a workable speed, and cut the search space by half.
        if (hourSpent <= h) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    // Once the left and right boundaries coincide, we find the target value,
    // that is, the minimum workable eating speed.
    return left;
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:  
        # Initalize the left and right boundaries     
        left = 1
        right = max(piles)
        
        while left < right:
            # Get the middle index between left and right boundary indexes.
            # hour_spent stands for the total hour Koko spends.
            middle = (left + right) // 2            
            hour_spent = 0
            
            # Iterate over the piles and calculate hour_spent.
            # We increase the hour_spent by ceil(pile / middle)
            for pile in piles:
                hour_spent += math.ceil(pile / middle)
            
            # Check if middle is a workable speed, and cut the search space by half.
            if hour_spent <= h:
                right = middle
            else:
                left = middle + 1
        
        # Once the left and right boundaries coincide, we find the target value,
        # that is, the minimum workable eating speed.
        return right
```

</details>
