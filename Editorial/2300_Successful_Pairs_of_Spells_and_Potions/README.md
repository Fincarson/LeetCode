# 2300. Successful Pairs of Spells and Potions

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/)  
`Array` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 2300 - Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/)

## Problem

You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

### Example 1

```text
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.
```

### Example 2

```text
Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
Thus, [2,0,2] is returned.
```

## Constraints

- n == spells.length
- m == potions.length
- 1 <= n, m <= 105
- 1 <= spells[i], potions[i] <= 105
- 1 <= success <= 1010

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Subsequence With Limited Sum](https://leetcode.com/problems/longest-subsequence-with-limited-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2300. Successful Pairs of Spells and Potions

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting + Binary Search | C++, Java, JavaScript, Python3, TypeScript |
| Sorting + Two Pointers | C++, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sorting + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort the potions array in increasing order.
        sort(potions.begin(), potions.end());
        vector<int> answer;
        
        int m = potions.size();
        int maxPotion = potions[m - 1];
        
        for (auto& spell : spells) {
            // Minimum value of potion whose product with current spell  
            // will be at least success or more.
            long long minPotion = ceil((1.0 * success) / spell);
            // Check if we don't have any potion which can be used.
            if (minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            // We can use the found potion, and all potion in its right 
            // (as the right potions are greater than the found potion).
            auto index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            answer.push_back(m - index);
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
    // Our implementation of lower bound method using binary search.
    private int lowerBound(int[] arr, int key) {
        int lo = 0;
        int hi = arr.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < key) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        // Sort the potions array in increasing order.
        Arrays.sort(potions);
        int[] answer = new int[spells.length];

        int m = potions.length;
        int maxPotion = potions[m - 1];

        for (int i = 0; i < spells.length; i++) {
            int spell = spells[i];
            // Minimum value of potion whose product with current spell  
            // will be at least success or more.
            long minPotion = (long) Math.ceil((1.0 * success) / spell);
            // Check if we don't have any potion which can be used.
            if (minPotion > maxPotion) {
                answer[i] = 0;
                continue;
            }
            // We can use the found potion, and all potion in its right 
            // (as the right potions are greater than the found potion).
            int index = lowerBound(potions, (int) minPotion);
            answer[i] = m - index;
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var successfulPairs = function(spells, potions, success) {
    // Sort the potions array in increasing order.
    potions.sort((a, b) => a - b);
    const answer = [];

    const m = potions.length;
    const maxPotion = potions[m - 1];

    for (const spell of spells) {
        // Minimum value of potion whose product with current spell
        // will be at least success or more.
        const minPotion = Math.ceil(success / spell);
        // Check if we don't have any potion which can be used.
        if (minPotion > maxPotion) {
            answer.push(0);
            continue;
        }
        // We can use the found potion, and all potion in its right
        // (as the right potions are greater than the found potion).
        const index = lowerBound(potions, minPotion);
        answer.push(m - index);
    }

    return answer;
};

// Returns the lower bound of 'key' in the sorted array 'arr'.
function lowerBound(arr, key) {
    let low = 0, high = arr.length;
    while (low < high) {
        const mid = Math.floor((low + high) / 2);
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        # Sort the potions array in increasing order.
        potions.sort()
        answer = []

        m = len(potions)
        maxPotion = potions[m - 1]

        for spell in spells:
            # Minimum value of potion whose product with current spell
            # will be at least success or more.
            minPotion = (success + spell - 1) // spell
            # Check if we don't have any potion which can be used.
            if minPotion > maxPotion:
                answer.append(0)
                continue
            # We can use the found potion, and all potion in its right
            # (as the right potions are greater than the found potion).
            index = bisect.bisect_left(potions, minPotion)
            answer.append(m - index)

        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function successfulPairs(spells: number[], potions: number[], success: number): number[] {
    // Sort the potions array in increasing order.
    potions.sort((a, b) => a - b);
    const answer: number[] = [];

    const m = potions.length;
    const maxPotion = potions[m - 1];

    for (const spell of spells) {
        // Minimum value of potion whose product with current spell
        // will be at least success or more.
        const minPotion = Math.ceil(success / spell);
        // Check if we don't have any potion which can be used.
        if (minPotion > maxPotion) {
            answer.push(0);
            continue;
        }
        // We can use the found potion, and all potion in its right
        // (as the right potions are greater than the found potion).
        const index = lowerBound(potions, minPotion);
        answer.push(m - index);
    }

    return answer;
};

// Returns the lower bound of 'key' in the sorted array 'arr'.
function lowerBound(arr: number[], key: number): number {
    let low = 0, high = arr.length;
    while (low < high) {
        const mid = Math.floor((low + high) / 2);
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
```

</details>

<br>

## Approach 2: Sorting + Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> sortedSpells;
        for (int i = 0; i< spells.size(); ++i) {
            sortedSpells.push_back({ spells[i], i });
        }

        // Sort the 'spells with index' and 'potions' array in increasing order.
        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> answer(spells.size());
        int m = potions.size();
        int potionIndex = m - 1;
        
        // For each 'spell' find the respective 'minPotion' index.
        for (const auto& [spell, index] : sortedSpells) {
            while (potionIndex >= 0 && (long long) spell * potions[potionIndex] >= success) {
                potionIndex -= 1;
            }
            answer[index] = m - (potionIndex + 1);
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
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        
        // Create an array of pairs containing spell and its original index
        int[][] sortedSpells = new int[n][2];
        for (int i = 0; i < n; i++) {
            sortedSpells[i][0] = spells[i];
            sortedSpells[i][1] = i;
        }
        
        // Sort the 'spells with index' and 'potions' array in increasing order
        Arrays.sort(sortedSpells, (a, b) -> Integer.compare(a[0], b[0]));
        Arrays.sort(potions);
        
        // For each 'spell' find the respective 'minPotion' index
        int[] answer = new int[n];
        int potionIndex = m - 1;

        for (int[] sortedSpell : sortedSpells) {
            int spell = sortedSpell[0];
            int index = sortedSpell[1];
            
            while (potionIndex >= 0 && (long) spell * potions[potionIndex] >= success) {
                potionIndex -= 1;
            }
            answer[index] = m - (potionIndex + 1);
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var successfulPairs = function(spells, potions, success) {
    let sortedSpells = [];
    for (let i = 0; i < spells.length; ++i) {
        sortedSpells.push([spells[i], i]);
    }

    // Sort the 'spells with index' and 'potions' array in increasing order.
    sortedSpells.sort((a, b) => a[0] - b[0]);
    potions.sort((a, b) => a - b);

    let answer = new Array(spells.length).fill(0);
    let m = potions.length;
    let potionIndex = m - 1;
    
    // For each 'spell' find the respective 'minPotion' index.
    for (const [spell, index] of sortedSpells) {
        while (potionIndex >= 0 && (spell * potions[potionIndex]) >= success) {
            potionIndex -= 1;
        }
        answer[index] = m - (potionIndex + 1);
    }
    
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        sortedSpells = [(spell, index) for index, spell in enumerate(spells)]

        # Sort the 'spells with index' and 'potions' array in increasing order.
        sortedSpells.sort()
        potions.sort()

        answer = [0] * len(spells)
        m = len(potions)
        potionIndex = m - 1
        
        # For each 'spell' find the respective 'minPotion' index.
        for spell, index in sortedSpells:
            while potionIndex >= 0 and (spell * potions[potionIndex]) >= success:
                potionIndex -= 1
            answer[index] = m - (potionIndex + 1)
        
        return answer
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function successfulPairs(spells: number[], potions: number[], success: number): number[] {
    const sortedSpells: [number, number][] = spells.map((spell, i) => [spell, i]);

    // Sort the 'spells with index' and 'potions' array in increasing order.
    sortedSpells.sort((a, b) => a[0] - b[0]);
    potions.sort((a, b) => a - b);

    const answer: number[] = new Array(spells.length);
    let m = potions.length;
    let potionIndex = m - 1;

    // For each 'spell' find the respective 'minPotion' index.
    for (const [spell, index] of sortedSpells) {
        while (potionIndex >= 0 && spell * potions[potionIndex] >= success) {
            potionIndex -= 1;
        }
        answer[index] = m - (potionIndex + 1);
    }

    return answer;
};
```

</details>
