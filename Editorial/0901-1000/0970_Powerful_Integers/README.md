# 970. Powerful Integers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/powerful-integers/)  
`Hash Table` `Math` `Enumeration`

**Problem Link:** [LeetCode 970 - Powerful Integers](https://leetcode.com/problems/powerful-integers/)

## Problem

Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.

An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.

You may return the answer in any order. In your answer, each value should occur at most once.

### Example 1

```text
Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32
```

### Example 2

```text
Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
```

## Constraints

- 1 <= x, y <= 100
- 0 <= bound <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count the Number of Powerful Integers](https://leetcode.com/problems/count-the-number-of-powerful-integers/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 970. Powerful Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Logartihmic Bounds | Java, Python3 |

## Approach: Logartihmic Bounds

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        
        int a = x == 1 ? bound : (int) (Math.log(bound) / Math.log(x));
        int b = y == 1 ? bound : (int) (Math.log(bound) / Math.log(y));
        
        HashSet<Integer> powerfulIntegers = new HashSet<Integer>();
        
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                
                int value = (int) Math.pow(x, i) + (int) Math.pow(y, j);
                
                if (value <= bound) {
                    powerfulIntegers.add(value);
                }
                
                // No point in considering other powers of "1".
                if (y == 1) {
                    break;
                }
            }
            
            if (x == 1) {
                break;
            }
        }
        
        return new ArrayList<Integer>(powerfulIntegers);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        
        a = bound if x == 1 else int(log(bound, x))
        b = bound if y == 1 else int(log(bound, y))
        
        powerful_integers = set([])
        
        for i in range(a + 1):
            for j in range(b + 1):
                
                value = x**i + y**j
                
                if value <= bound:
                    powerful_integers.add(value)
                    
                if y == 1:
                    break
            
            if x == 1:
                break
                
        return list(powerful_integers)
```

</details>
