# 287. Find the Duplicate Number

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-duplicate-number/)  
`Array` `Two Pointers` `Binary Search` `Bit Manipulation`

**Problem Link:** [LeetCode 287 - Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

## Problem

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

### Example 1

```text
Input: nums = [1,3,4,2,2]
Output: 2
```

### Example 2

```text
Input: nums = [3,1,3,4,2]
Output: 3
```

### Example 3

```text
Input: nums = [3,3,3,3,3]
Output: 3
```

## Constraints

- 1 <= n <= 105
- nums.length == n + 1
- 1 <= nums[i] <= n
- All the integers in nums appear only once except for precisely one integer which appears two or more times.

Follow up:

- How can we prove that at least one duplicate number must exist in nums?
- Can you solve the problem in linear runtime complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Single Number](https://leetcode.com/problems/single-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Missing Number](https://leetcode.com/problems/missing-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Set Mismatch](https://leetcode.com/problems/set-mismatch/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 287. Find the Duplicate Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | C++, Java, Python3 |
| Set | C++, Java, Python3 |
| Negative Marking | C++, Java, Python3 |
| Approach 4.1: Array as HashMap (Recursion) | C++, Java, Python3 |
| Approach 4.2: Array as HashMap (Iterative) | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |
| Sum of Set Bits | C++, Java, Python3 |
| Floyd's Tortoise and Hare (Cycle Detection) | C++, Java, Python3 |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1])
                return nums[i];
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                return nums[i]
```

</details>

<br>

## Approach 2: Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto &num : nums) {
            if (seen.count(num))
                return num;
            seen.insert(num);
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<Integer>();
        for (int num : nums) {
            if (seen.contains(num))
                return num;
            seen.add(num);
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        seen = set()
        for num in nums:
            if num in seen:
                return num
            seen.add(num)
```

</details>

<br>

## Approach 3: Negative Marking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        // Restore numbers
        for (auto& num : nums)
            num = abs(num);
        
        return duplicate;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findDuplicate(int[] nums) {
        int duplicate = -1;
        for (int i = 0; i < nums.length; i++) {
            int cur = Math.abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        // Restore numbers
        for (int i = 0; i < nums.length; i++)
            nums[i] = Math.abs(nums[i]);

        return duplicate;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for num in nums:
            cur = abs(num)
            if nums[cur] < 0:
                duplicate = cur
                break
            nums[cur] = -nums[cur]

        # Restore numbers
        for i in range(len(nums)):
            nums[i] = abs(nums[i])

        return duplicate
```

</details>

<br>

## Approach 4.1: Array as HashMap (Recursion)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int store(vector<int>& nums, int cur) {
        if (cur == nums[cur])
            return cur;
        int nxt = nums[cur];
        nums[cur] = cur;
        return store(nums, nxt);
    }
    
    int findDuplicate(vector<int>& nums) {
        return store(nums, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {    
    public int store(int[] nums, int cur) {
        if (cur == nums[cur])
            return cur;
        int nxt = nums[cur];
        nums[cur] = cur;
        return store(nums, nxt);        
    }
    
    public int findDuplicate(int[] nums) {
        return store(nums, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:    
    def findDuplicate(self, nums: List[int]) -> int:
	
        def store(nums: List[int], cur: int) -> int:
            if cur == nums[cur]:
                return cur
            nxt = nums[cur]
            nums[cur] = cur
            return store(nums, nxt)
        
        return store(nums, 0)
```

</details>

<br>

## Approach 4.2: Array as HashMap (Iterative)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findDuplicate(int[] nums) {
        while (nums[0] != nums[nums[0]]) {
            int nxt = nums[nums[0]];
            nums[nums[0]] = nums[0];
            nums[0] = nxt;
        }
        return nums[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        while nums[0] != nums[nums[0]]:
            nums[nums[0]], nums[0] = nums[0], nums[nums[0]]
        return nums[0]
```

</details>

<br>

## Approach 5: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    public:
    
    int findDuplicate(vector<int>& nums) {

        // Lambda function to count how many numbers are less than or equal to 'cur'
        auto small_or_equal = [&](int cur) {
            int count = 0;
            for (auto &num: nums) {
                if (num <= cur)
                    count++;
            }
            return count;
        };
        
        // 'low' and 'high' represent the range of values of the target
        int low = 1, high = nums.size();
        int duplicate = -1;
        while (low <= high) {
            int cur = (low + high) / 2;
            
            if (small_or_equal(cur) > cur) { 
                duplicate = cur;
                high = cur - 1;
            } else {
                low = cur + 1;
            }
        }

        return duplicate;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    public int findDuplicate(int[] nums) {
        // 'low' and 'high' represent the range of values of the target        
        int low = 1, high = nums.length - 1;
        int duplicate = -1;
        
        while (low <= high) {
            int cur = (low + high) / 2;

            // Count how many numbers in 'nums' are less than or equal to 'cur'
            int count = 0;
            for (int num : nums) {
                if (num <= cur)
                    count++;
            }
            
            if (count > cur) {
                duplicate = cur;
                high = cur - 1;
            } else {
                low = cur + 1;
            }
        }
        return duplicate;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # 'low' and 'high' represent the range of values of the target
        low = 1
        high = len(nums) - 1
        
        while low <= high:
            cur = (low + high) // 2
            count = 0

            # Count how many numbers are less than or equal to 'cur'
            count = sum(num <= cur for num in nums)
            if count > cur:
                duplicate = cur
                high = cur - 1
            else:
                low = cur + 1
                
        return duplicate
```

</details>

<br>

## Approach 6: Sum of Set Bits

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    
    // Find the position of the Most Significant Bit in num
    int calcMaxBit(int num) {
        int bits = 0;
        while (num > 0) {
            num /= 2;
            bits++;
        }
        return bits;
    }
    
    int findDuplicate(vector<int>& nums) {
        int duplicate = 0;
        int n = nums.size() - 1;
        int max_num = *max_element(nums.begin(), nums.end());
        int max_bit = calcMaxBit(max_num);
        
        // Iterate over each bit
        for (int bit = 0; bit < max_bit; bit++) {
            int mask = (1 << bit);
            int base_count = 0, nums_count = 0;
            
            for (int i = 0; i <= n; i++) {
                // If bit is set in number (i) then add 1 to base_count
                if (i & mask) {
                    base_count++;
                }
                // If bit is set in nums[i] then add 1 to nums_count
                if (nums[i] & mask) {
                    nums_count++;
                }
            }
            
            // If the current bit is more frequently set in nums than it is in 
            // the range [1, 2, ..., n] then it must also be set in the duplicate number
            if (nums_count > base_count) {
                duplicate |= mask;
            }
        }
        return duplicate;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    // Find the position of the Most Significant Bit in num    
    int calcMaxBit(int num) {
        int bits = 0;
        while (num > 0) {
            num /= 2;
            bits++;
        }
        return bits;
    }

    // Find the largest number in nums
    int findMaxNum(int[] nums) {
        int max_num = 0;
        for (int i = 0; i < nums.length; i++)
            max_num = Math.max(max_num, nums[i]);
        return max_num;
    }
    
    public int findDuplicate(int[] nums) {
        int duplicate = 0;
        int n = nums.length - 1;
        int max_num = findMaxNum(nums);
        int max_bit = calcMaxBit(max_num);
        
        // Iterate over each bit        
        for (int bit = 0; bit < max_bit; bit++) {
            int mask = (1 << bit);
            int base_count = 0, nums_count = 0;

            for (int i = 0; i <= n; i++) {
                // If bit is set in number (i) then add 1 to base_count                
                if ((i & mask) > 0) {
                    base_count++;
                }
                // If bit is set in nums[i] then add 1 to nums_count
                if ((nums[i] & mask) > 0) {
                    nums_count++;
                }
            }

            // If the current bit is more frequently set in nums than it is in 
            // the range [1, 2, ..., n] then it must also be set in the duplicate number
            if (nums_count > base_count) {
                duplicate |= mask;
            }
        }
        return duplicate;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        duplicate = 0
        n = len(nums) - 1
        bits = n.bit_length()
        for bit in range(bits):
            mask = 1 << bit
            base_count = 0
            nums_count = 0
            for i in range(n + 1):
                # If bit is set in number (i) then add 1 to base_count
                if i & mask:
                    base_count += 1
                    
                # If bit is set in nums[i] then add 1 to nums_count
                if nums[i] & mask:
                    nums_count += 1
                    
            # If the current bit is more frequently set in nums than it is in 
            # the range [1, 2, ..., n] then it must also be set in the duplicate number.
            if nums_count - base_count > 0:
                duplicate |= mask
                
        return duplicate
```

</details>

<br>

## Approach 7: Floyd's Tortoise and Hare (Cycle Detection)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findDuplicate(int[] nums) {
        
        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];
        
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDuplicate(self, nums):
        # Find the intersection point of the two runners.
        tortoise = hare = nums[0]
        while True:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            if tortoise == hare:
                break
        
        # Find the "entrance" to the cycle.
        tortoise = nums[0]
        while tortoise != hare:
            tortoise = nums[tortoise]
            hare = nums[hare]
        
        return hare
```

</details>
