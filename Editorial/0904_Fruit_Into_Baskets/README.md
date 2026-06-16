# 904. Fruit Into Baskets

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/fruit-into-baskets/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 904 - Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)

## Problem

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

- You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

### Example 1

```text
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
```

### Example 2

```text
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
```

### Example 3

```text
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
```

## Constraints

- 1 <= fruits.length <= 105
- 0 <= fruits[i] < fruits.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Fruits Into Baskets II](https://leetcode.com/problems/fruits-into-baskets-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 904. Fruit Into Baskets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Optimized Brute Force | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |
| Sliding Window II | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Maximum number of fruits we can pick
        int maxPicked = 0;
        
        // Iterate over all subarrays (left, right)
        for (int left = 0; left < fruits.size(); ++left) {
            for (int right = 0; right < fruits.size(); ++right) {
                // Use a set to count the type of fruits.
                set<int> basket;
                
                // Iterate over the current subarray.
                for (int currentIndex = left; currentIndex <= right; ++currentIndex) {
                    basket.insert(fruits[currentIndex]);
                }
                
                // If the number of types of fruits in this subarray (types of fruits) 
                // is no larger than 2, this is a valid subarray, update 'maxPicked'.
                if (basket.size() <= 2) {
                    maxPicked = max(maxPicked, right - left + 1);
                }
            }
        }
        
        // Return 'maxPicked' as the maximum length (maximum number of fruits we can pick).
        return maxPicked;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int totalFruit(int[] fruits) {
        // Maximum number of fruits we can pick
        int maxPicked = 0;
        
        // Iterate over all subarrays (left, right)
        for (int left = 0; left < fruits.length; ++left) {
            for (int right = 0; right < fruits.length; ++right) {
                // Use a set to count the type of fruits.
                Set<Integer> basket = new HashSet<>();
                
                // Iterate over the current subarray.
                for (int currentIndex = left; currentIndex <= right; ++currentIndex) {
                    basket.add(fruits[currentIndex]);
                }
                
                // If the number of types of fruits in this subarray (types of fruits) 
                // is no larger than 2, this is a valid subarray, update 'maxPicked'.
                if (basket.size() <= 2) {
                    maxPicked = Math.max(maxPicked, right - left + 1);
                }
            }
        }
        
        // Return 'maxPicked' as the maximum length (maximum number of fruits we can pick).
        return maxPicked;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # Maximum number of fruits we can pick
        max_picked = 0
        
        # Iterate over all subarrays: left index left, right index right.
        for left in range(len(fruits)):
            for right in range(left, len(fruits)):
                # Use a set to count the type of fruits.
                basket = set()
                
                # Iterate over the current subarray (left, right).
                for current_index in range(left, right + 1):
                    basket.add(fruits[current_index])
                    
                # If the number of types of fruits in this subarray (types of fruits) 
                # is no larger than 2, this is a valid subarray, update 'max_picked'.
                if len(basket) <= 2:
                    max_picked = max(max_picked, right - left + 1)
        
        # Return 'max_picked' as the maximum length (maximum number of fruits we can pick).
        return max_picked
```

</details>

<br>

## Approach 2: Optimized Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Maximum number of fruits we can pick
        int maxPicked = 0;
        
        // Iterate over the left index left of subarrays.
        for (int left = 0; left < fruits.size(); ++left) {
            // Empty set to count the type of fruits.
            set<int> basket;
            int right = left;
            
            // Iterate over the right index right of subarrays.
            while (right < fruits.size()) {
                // Early stop. If adding this fruit makes 3 types of fruit,
                // we should stop the inner loop.
                if (basket.find(fruits[right]) == basket.end() && basket.size() == 2)
                    break;
                
                // Otherwise, update the number of this fruit.
                basket.insert(fruits[right]);
                right++;
            }
            
            // Update maxPicked.
            maxPicked = max(maxPicked, right - left);
        }
        
        // Return maxPicked as the maximum length of valid subarray.
        // (maximum number of fruits we can pick).
        return maxPicked;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int totalFruit(int[] fruits) {
        // Maximum number of fruits we can pick
        int maxPicked = 0;
        
        // Iterate over the left index left of subarrays.
        for (int left = 0; left < fruits.length; ++left) {
            // Empty set to count the type of fruits.
            Set<Integer> basket = new HashSet<>();
            int right = left;
            
            // Iterate over the right index right of subarrays.
            while (right < fruits.length) {
                // Early stop. If adding this fruit makes 3 types of fruit,
                // we should stop the inner loop.
                if (!basket.contains(fruits[right]) && basket.size() == 2)
                    break;
                
                // Otherwise, update the number of this fruit.
                basket.add(fruits[right]);
                right++;
            }
            
            // Update maxPicked.
            maxPicked = Math.max(maxPicked, right - left);
        }
        
        // Return maxPicked as the maximum length of valid subarray.
        // (maximum number of fruits we can pick).
        return maxPicked;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # Maximum number of fruits we can pick
        max_picked = 0
        
        # Iterate over the left index left of subarrays.
        for left in range(len(fruits)):
            # Empty set to count the type of fruits.
            basket = set()
            right = left
            
            # Iterate over the right index right of subarrays.
            while right < len(fruits):
                # Early stop. If adding this fruit makes 3 types of fruit,
                # we should stop the inner loop.
                if fruits[right] not in basket and len(basket) == 2:
                    break
                
                # Otherwise, update the number of this fruit.
                basket.add(fruits[right])
                right += 1
            
            # Update max_picked
            max_picked = max(max_picked, right - left)
        
        # Return maxPicked as the maximum length of valid subarray.
        # (maximum number of fruits we can pick).
        return max_picked
```

</details>

<br>

## Approach 3: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Hash map 'basket' to store the types of fruits.
        unordered_map<int, int> basket;
        int left, right;
        
        // Add fruit from the right index (right) of the window.
        for (left = 0, right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            
            // If the current window has more than 2 types of fruit,
            // we remove one fruit from the left index (left) of the window.
            if (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
        }
        
        // Once we finish the iteration, the indexes left and right 
        // stands for the longest valid subarray we encountered.
        return right - left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int totalFruit(int[] fruits) {
        // Hash map 'basket' to store the types of fruits.
        Map<Integer, Integer> basket = new HashMap<>();
        int left = 0, right;
        
        // Add fruit from right side (right) of the window.
        for (right = 0; right < fruits.length; ++right) {
            basket.put(fruits[right], basket.getOrDefault(fruits[right], 0) + 1);
            
            // If the current window has more than 2 types of fruit,
            // we remove one fruit from the left index (left) of the window.
            if (basket.size() > 2) {
                basket.put(fruits[left], basket.get(fruits[left]) - 1);
                if (basket.get(fruits[left]) == 0)
                    basket.remove(fruits[left]);
                left++;
            }
        }
        
        // Once we finish the iteration, the indexes left and right 
        // stands for the longest valid subarray we encountered.
        return right - left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # Hash map 'basket' to store the types of fruits.
        basket = {}
        left = 0
        
        # Add fruit from the right index (right) of the window.
        for right, fruit in enumerate(fruits):
            basket[fruit] = basket.get(fruit, 0) + 1

            # If the current window has more than 2 types of fruit,
            # we remove one fruit from the left index (left) of the window.
            if len(basket) > 2:
                basket[fruits[left]] -= 1

                # If the number of fruits[left] is 0, remove it from the basket.
                if basket[fruits[left]] == 0:
                    del basket[fruits[left]]
                left += 1
        
        # Once we finish the iteration, the indexes left and right 
        # stands for the longest valid subarray we encountered.
        return right - left + 1
```

</details>

<br>

## Approach 4: Sliding Window II

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // We use a hash map 'basket' to store the number of each type of fruit.
        unordered_map<int, int> basket;
        int left = 0, maxPicked = 0;
        
        // Add fruit from the right index (right) of the window.
        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;
            
            // If the current window has more than 2 types of fruit,
            // we remove fruit from the left index (left) of the window,
            // until the window has only 2 types of fruit.
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }
            
            // Update maxPicked.
            maxPicked = max(maxPicked, right - left + 1);
        }
        
        // Return maxPicked as the maximum number of fruits we can collect.
        return maxPicked;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int totalFruit(int[] fruits) {
        // We use a hash map 'basket' to store the number of each type of fruit.
        Map<Integer, Integer> basket = new HashMap<>();
        int left = 0, maxPicked = 0;
        
        // Add fruit from the right index (right) of the window.
        for (int right = 0; right < fruits.length; ++right) {
            basket.put(fruits[right], basket.getOrDefault(fruits[right], 0) + 1);

            // If the current window has more than 2 types of fruit,
            // we remove fruit from the left index (left) of the window,
            // until the window has only 2 types of fruit.
            while (basket.size() > 2) {
                basket.put(fruits[left], basket.get(fruits[left]) - 1);
                if (basket.get(fruits[left]) == 0)
                    basket.remove(fruits[left]);
                left++;
            }
            
            // Update maxPicked.
            maxPicked = Math.max(maxPicked, right - left + 1);
        }
        
        // Return maxPicked as the maximum number of fruits we can collect.
        return maxPicked;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # We use a hash map 'basket' to store the number of each type of fruit.
        basket = {}
        max_picked = 0
        left = 0
        
        # Add fruit from the right index (right) of the window.
        for right in range(len(fruits)):
            basket[fruits[right]] = basket.get(fruits[right], 0) + 1
            
            # If the current window has more than 2 types of fruit,
            # we remove fruit from the left index (left) of the window,
            # until the window has only 2 types of fruit.
            while len(basket) > 2:
                basket[fruits[left]] -= 1
                if basket[fruits[left]] == 0:
                    del basket[fruits[left]]
                left += 1
            
            # Update max_picked.
            max_picked = max(max_picked, right - left + 1)
        
        # Return max_picked as the maximum number of fruits we can collect.
        return max_picked
```

</details>
