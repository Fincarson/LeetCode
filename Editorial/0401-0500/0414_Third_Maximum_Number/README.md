# 414. Third Maximum Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/third-maximum-number/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 414 - Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)

## Problem

Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

### Example 1

```text
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
```

### Example 2

```text
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
```

### Example 3

```text
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
```

## Constraints

- 1 <= nums.length <= 104
- -231 <= nums[i] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Neither Minimum nor Maximum](https://leetcode.com/problems/neither-minimum-nor-maximum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 414. Third Maximum Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, JavaScript, Python3 |
| Min Heap Data Structure | C++, Java, Python3 |
| Ordered Set | C++, Java, JavaScript, Python3 |
| 3 Pointers | C++, Java, JavaScript, Python3 |
| 3 Pointers (Follow-Up) | C++, Java, JavaScript, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Sort the array in non-increasing order.
        sort(nums.begin(), nums.end(), greater<int>());
        
        int elemCounted = 1;
        int prevElem = nums[0];
        
        for (int index = 1; index < nums.size(); ++index) {
            // Current element is different from previous.
            if (nums[index] != prevElem) {
                elemCounted += 1;
                prevElem = nums[index];
            }
            
            // If we have counted 3 numbers then return current number.
            if (elemCounted == 3) {
                return nums[index];
            }
        }
        
        // We never counted 3 distinct numbers, return largest number.
        return nums[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int thirdMax(int[] nums) {
        // Sort the array in non-increasing order.
        Arrays.sort(nums);
        
        // Reverse array to make it non-increasing.
        for (int index = 0; index < nums.length / 2; ++index) {
            int temp = nums[index];
            nums[index] = nums[nums.length - 1 - index];
            nums[nums.length - 1 - index] = temp;
        }
        
        int elemCounted = 1;
        int prevElem = nums[0];
        
        for (int index = 1; index < nums.length; ++index) {
            // Current element is different from previous.
            if (nums[index] != prevElem) {
                elemCounted += 1;
                prevElem = nums[index];
            }
            
            // If we have counted 3 numbers then return current number.
            if (elemCounted == 3) {
                return nums[index];
            }
        }
        
        // We never counted 3 distinct numbers, return largest number.
        return nums[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let thirdMax = function(nums) {
    // Sort the array in non-increasing order.
    nums.sort((a, b) => b - a);

    let elemCounted = 1;
    let prevElem = nums[0];

    for (let index = 1; index < nums.length; ++index) {
        // Current element is different from previous.
        if (nums[index] != prevElem) {
            elemCounted += 1;
            prevElem = nums[index];
        }

        // If we have counted 3 numbers then return current number.
        if (elemCounted == 3) {
            return nums[index];
        }
    }

    // We never counted 3 distinct numbers, return largest number.
    return nums[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        # Sort the array.
        nums.sort(reverse = True)
        
        elem_counted = 1
        prev_elem = nums[0]
        
        for index in range(len(nums)):
            # Current element is different from previous.
            if nums[index] != prev_elem:
                elem_counted += 1
                prev_elem = nums[index]
            
            # If we have counted 3 numbers then return current number.
            if elem_counted == 3:
                return nums[index]
        
        # We never counted 3 distinct numbers, return largest number.
        return nums[0]
```

</details>

<br>

## Approach 2: Min Heap Data Structure

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> taken;
        
        for (int index = 0; index < nums.size(); ++index) {
            // If current number was already taken, skip it.
            if (taken.count(nums[index])) {
                continue;
            }
            
            // If min heap already has three numbers in it.
            // Pop the smallest if current number is bigger than it.
            if (minHeap.size() == 3) {
                if (minHeap.top() < nums[index]) {
                    taken.erase(minHeap.top());
                    minHeap.pop();
                    
                    minHeap.push(nums[index]);
                    taken.insert(nums[index]);
                }
            } 
            // If min heap does not have three numbers we can push it.
            else {
                minHeap.push(nums[index]);
                taken.insert(nums[index]);
            }
        }
        
        // 'nums' has only one distinct element it will be the maximum.
        if (minHeap.size() == 1) {
            return minHeap.top();
        }
        // 'nums' has two distinct elements.
        else if (minHeap.size() == 2) {
            int firstNum = minHeap.top();
            minHeap.pop();
            return max(firstNum, minHeap.top());
        }
        
        return minHeap.top();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int thirdMax(int[] nums) {
        PriorityQueue<Integer> minHeap = new PriorityQueue();
        Set<Integer> taken = new HashSet<Integer>();
        
        for (int index = 0; index < nums.length; ++index) {
            // If current number was already taken, skip it.
            if (taken.contains(nums[index])) {
                continue;
            }
            
            // If min heap already has three numbers in it.
            // Pop the smallest if current number is bigger than it.
            if (minHeap.size() == 3) {
                if (minHeap.peek() < nums[index]) {
                    taken.remove(minHeap.poll());
                    
                    minHeap.add(nums[index]);
                    taken.add(nums[index]);
                }
            } 
            // If min heap does not have three numbers we can push it.
            else {
                minHeap.add(nums[index]);
                taken.add(nums[index]);
            }
        }
        
        // 'nums' has only one distinct element it will be the maximum.
        if (minHeap.size() == 1) {
            return minHeap.peek();
        }
        // 'nums' has two distinct elements.
        else if (minHeap.size() == 2) {
            int firstNum = minHeap.poll();
            return Math.max(firstNum, minHeap.peek());
        }
        
        return minHeap.peek();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        min_heap = []
        taken = set()
        
        for index in range(len(nums)):
            # If current number was already taken, skip it.
            if nums[index] in taken:
                continue
            
            # If min heap already has three numbers in it.
            # Pop the smallest if current number is bigger than it.
            if len(min_heap) == 3:
                if min_heap[0] < nums[index]:
                    taken.remove(min_heap[0])
                    heappop(min_heap)
                    
                    heappush(min_heap, nums[index])
                    taken.add(nums[index])
                    
            # If min heap does not have three numbers we can push it.
            else:
                heappush(min_heap, nums[index])
                taken.add(nums[index])
        
        # 'nums' has only one distinct element it will be the maximum.
        if len(min_heap) == 1:
            return min_heap[0]
        
        # 'nums' has two distinct elements.
        elif len(min_heap) == 2:
            first_num = min_heap[0]
            heappop(min_heap)
            return max(first_num, min_heap[0])
        
        return min_heap[0]
```

</details>

<br>

## Approach 3: Ordered Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Sorted set to keep elements in sorted order.
        set<int> sortedNums;
        
        // Iterate on all elements of 'nums' array.
        for (int& num : nums) {
            // Do not insert same element again.
            if (sortedNums.count(num)) {
                continue;
            }
            
            // If sorted set has 3 elements.
            if (sortedNums.size() == 3) {
                // And the smallest element is smaller than current element.
                if (*sortedNums.begin() < num) {
                    // Then remove the smallest element and push the current element.
                    sortedNums.erase(sortedNums.begin());
                    sortedNums.insert(num);
                }
                
            } 
            // Otherwise push the current element of nums array.
            else {
                sortedNums.insert(num);
            }
        }
        
        // If sorted set has three elements return the smallest among those 3.
        if (sortedNums.size() == 3) {
            return *sortedNums.begin();
        }
        
        // Otherwise return the biggest element of nums array.
        return *sortedNums.rbegin();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int thirdMax(int[] nums) {
        // Sorted set to keep elements in sorted order.
        TreeSet<Integer> sortedNums = new TreeSet<Integer>();
        
        // Iterate on all elements of 'nums' array.
        for (int num : nums) {
            // Do not insert same element again.
            if (sortedNums.contains(num)) {
                continue;
            }
            
            // If sorted set has 3 elements.
            if (sortedNums.size() == 3) {
                // And the smallest element is smaller than current element.
                if (sortedNums.first() < num) {
                    // Then remove the smallest element and push the current element.
                    sortedNums.pollFirst();
                    sortedNums.add(num);
                }
                
            } 
            // Otherwise push the current element of nums array.
            else {
                sortedNums.add(num);
            }
        }
        
        // If sorted set has three elements return the smallest among those 3.
        if (sortedNums.size() == 3) {
            return sortedNums.first();
        }
        
        // Otherwise return the biggest element of nums array.
        return sortedNums.last();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let thirdMax = function(nums) {
    // Sorted set to keep elements in sorted order.
    let sortedNums = new Set();
    
    // Iterate on all elements of 'nums' array.
    for (let index in nums) {
        let num = nums[index];
        
        // Do not insert same element again.
        if (sortedNums.has(num)) {
            continue;
        }

        // If sorted set has 3 elements.
        if (sortedNums.size == 3) {
            let [firstElement] = sortedNums;
            
            // And the smallest element is smaller than current element.
            if (firstElement < num) {
                // Then remove the smallest element ans push the current element.
                sortedNums.delete(firstElement);
                sortedNums.add(num);
            }

        } 
        // Otherwise push the current element of nums array.
        else {
            sortedNums.add(num);
        }
        
        // Sort the set, it has at most 3 elements only.
        sortedNums = new Set([...sortedNums].sort((a, b) => a - b));
    }

    // If sorted set has three elements return the smallest among those 3.
    if (sortedNums.size == 3) {
        let [firstElement] = sortedNums;
        return firstElement;
    }

    // Otherwise return the biggest element of nums array.
    let lastElement = Array.from(sortedNums).pop();
    return lastElement;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedSet

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        # Sorted set to keep elements in sorted order.
        sorted_nums = SortedSet()
        
        # Iterate on all elements of 'nums' array.
        for num in nums:
            # Do not insert same element again.
            if num in sorted_nums:
                continue
            
            # If sorted set has 3 elements.
            if len(sorted_nums)== 3:
                # And the smallest element is smaller than current element.
                if sorted_nums[0] < num:
                    # Then remove the smallest element and push the current element.
                    sorted_nums.discard(sorted_nums[0])
                    sorted_nums.add(num)
            # Otherwise push the current element of nums array.
            else:
                sorted_nums.add(num)
        
        # If sorted set has three elements return the smallest among those 3.
        if len(sorted_nums) == 3:
            return sorted_nums[0]
        
        # Otherwise return the biggest element of nums array.
        return sorted_nums[-1]
```

</details>

<br>

## Approach 4: 3 Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Three variables to store maxiumum three numbers till now.
        long long firstMax = numeric_limits<long long>::min();
        long long secondMax = numeric_limits<long long>::min();
        long long thirdMax = numeric_limits<long long>::min();
        
        for (int& num : nums) {
            // This number is already used once, thus we skip it.
            if (firstMax == num || secondMax == num || thirdMax == num) {
                continue;
            }
            
            // If current number is greater than first maximum,
            // It means that this is the greatest number and first maximum and second max
            // will become the next two greater numbers.
            if (firstMax <= num) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            // When current number is greater than second maximum,
            // it means that this is the second greatest number.
            else if (secondMax <= num) {
                thirdMax = secondMax;
                secondMax = num;
            }
            // It is the third greatest number.
            else if (thirdMax <= num) {
                thirdMax = num;
            }
        }
        
        // If third max was never updated, it means we don't have 3 distinct numbers.
        if (thirdMax == numeric_limits<long long>::min()) {
            return firstMax;
        }
        
        return thirdMax;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int thirdMax(int[] nums) {
        // Three variables to store maxiumum three numbers till now.
        long firstMax = Long.MIN_VALUE;
        long secondMax = Long.MIN_VALUE;
        long thirdMax = Long.MIN_VALUE;
        
        for (int num : nums) {
            // This number is already used once, thus we skip it.
            if (firstMax == num || secondMax == num || thirdMax == num) {
                continue;
            }
            
            // If current number is greater than first maximum,
            // It means that this is the greatest number and first maximum and second max
            // will become the next two greater numbers.
            if (firstMax <= num) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            // When current number is greater than second maximum,
            // it means that this is the second greatest number.
            else if (secondMax <= num) {
                thirdMax = secondMax;
                secondMax = num;
            }
            // It is the third greatest number.
            else if (thirdMax <= num) {
                thirdMax = num;
            }
        }
        
        // If third max was never updated, it means we don't have 3 distinct numbers.
        if (thirdMax == Long.MIN_VALUE) {
            int ans = (int) firstMax;
            return ans;
        }
        
        int ans = (int) thirdMax;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let thirdMax = function(nums) {
    // Three variables to store maxiumum three numbers till now.
    let firstMax = Number.MIN_SAFE_INTEGER;
    let secondMax = Number.MIN_SAFE_INTEGER;
    let thirdMax = Number.MIN_SAFE_INTEGER;

    for (let index in nums) {
        let num = nums[index];
        
        // This number is already used once, thus we skip it.
        if (firstMax == num || secondMax == num || thirdMax == num) {
            continue;
        }

        // If current number is greater than first maximum,
        // It means that this is the greatest number and first maximum and second max
        // will become the next two greater numbers.
        if (firstMax <= num) {
            [thirdMax, secondMax, firstMax] = [secondMax, firstMax, num];
        }
        // When current number is greater than second maximum,
        // it means that this is the second greatest number.
        else if (secondMax <= num) {
            [thirdMax, secondMax] = [secondMax, num];
        }
        // It is the third greatest number.
        else if (thirdMax <= num) {
            thirdMax = num;
        }
    }

    // If third max was never updated, it means we don't have 3 distinct numbers.
    if (thirdMax == Number.MIN_SAFE_INTEGER) {
        return firstMax;
    }

    return thirdMax;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        # Three variables to store maxiumum three numbers till now.
        first_max = -inf
        second_max = -inf
        third_max = -inf
    
        for num in nums:
            # This number is already used once, thus we skip it.
            if first_max == num or second_max == num or third_max == num:
                continue
            
            # If current number is greater than first maximum,
            # It means that this is the greatest number and first maximum and second max
            # will become the next two greater numbers.
            if first_max <= num:
                third_max = second_max
                second_max = first_max
                first_max = num
            # When current number is greater than second maximum,
            # it means that this is the second greatest number.
            elif second_max <= num:
                third_max = second_max
                second_max = num
            # It is the third greatest number.
            elif third_max <= num:
                third_max = num
        
        # If third max was never updated, it means we don't have 3 distinct numbers.
        if third_max == -inf:
            return first_max
        
        return third_max
```

</details>

<br>

## Approach 5: 3 Pointers (Follow-Up)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        pair<int, bool> firstMax = {-1, false};
        pair<int, bool> secondMax = {-1, false};
        pair<int, bool> thirdMax = {-1, false};
        
        for (int& num : nums) {
            // If current number is already stored, skip it.
            if ((firstMax.second && firstMax.first == num) || 
                (secondMax.second && secondMax.first == num) || 
                (thirdMax.second && thirdMax.first == num)) {
                continue;
            }
            
            // If we never stored any variable in firstMax
            // or curr num is bigger than firstMax, then curr num is the biggest number.
            if (!firstMax.second || firstMax.first <= num) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = make_pair(num, true);
            }
            // If we never stored any variable in secondMax
            // or curr num is bigger than secondMax, then curr num is 2nd biggest number.
            else if (!secondMax.second || secondMax.first <= num) {
                thirdMax = secondMax;
                secondMax = make_pair(num, true);
            }
            // If we never stored any variable in thirdMax
            // or curr num is bigger than thirdMax, then curr num is 3rd biggest number.
            else if (!thirdMax.second || thirdMax.first <= num) {
                thirdMax = make_pair(num, true);
            }
        }
        
        // If third max was never updated, it means we don't have 3 distinct numbers.
        if (!thirdMax.second) {
            return firstMax.first;
        }
        
        return thirdMax.first;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int thirdMax(int[] nums) {
        Pair<Integer, Boolean> firstMax = new Pair<Integer, Boolean>(-1, false);
        Pair<Integer, Boolean> secondMax = new Pair<Integer, Boolean>(-1, false);
        Pair<Integer, Boolean> thirdMax = new Pair<Integer, Boolean>(-1, false);
        
        for (int num : nums) {
            // If current number is already stored, skip it.
            if ((firstMax.getValue() && firstMax.getKey() == num) || 
                (secondMax.getValue() && secondMax.getKey() == num) || 
                (thirdMax.getValue() && thirdMax.getKey() == num)) {
                continue;
            }
            
            // If we never stored any variable in firstMax
            // or curr num is bigger than firstMax, then curr num is the biggest number.
            if (!firstMax.getValue() || firstMax.getKey() <= num) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = new Pair<Integer, Boolean>(num, true);
            }
            // If we never stored any variable in secondMax
            // or curr num is bigger than secondMax, then curr num is 2nd biggest number.
            else if (!secondMax.getValue() || secondMax.getKey() <= num) {
                thirdMax = secondMax;
                secondMax = new Pair<Integer, Boolean>(num, true);
            }
            // If we never stored any variable in thirdMax
            // or curr num is bigger than thirdMax, then curr num is 3rd biggest number.
            else if (!thirdMax.getValue() || thirdMax.getKey() <= num) {
                thirdMax = new Pair<Integer, Boolean>(num, true);
            }
        }
        
        // If third max was never updated, it means we don't have 3 distinct numbers.
        if (!thirdMax.getValue()) {
            return firstMax.getKey();
        }
        
        return thirdMax.getKey();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let thirdMax = function(nums) {
    let firstMax = [-1, false];
    let secondMax = [-1, false];
    let thirdMax = [-1, false];

    for (let index in nums) {
        let num = nums[index];
        
        // If current number is already stored, skip it.
        if ((firstMax[1] && firstMax[0] == num) || 
            (secondMax[1] && secondMax[0] == num) || 
            (thirdMax[1] && thirdMax[0] == num)) {
            continue;
        }

        // If we never stored any variable in firstMax
        // or curr num is bigger than firstMax, then curr num is the biggest number.
        if (!firstMax[1] || firstMax[0] <= num) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = [num, true];
        }
        // If we never stored any variable in secondMax
        // or curr num is bigger than secondMax, then curr num is 2nd biggest number.
        else if (!secondMax[1] || secondMax[0] <= num) {
            thirdMax = secondMax;
            secondMax = [num, true];
        }
        // If we never stored any variable in thirdMax
        // or curr num is bigger than thirdMax, then curr num is 3rd biggest number.
        else if (!thirdMax[1] || thirdMax[0] <= num) {
            thirdMax = [num, true];
        }
    }

    // If third max was never updated, it means we don't have 3 distinct numbers.
    if (!thirdMax[1]) {
        return firstMax[0];
    }

    return thirdMax[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        firstMax = (-1, False)
        secondMax = (-1, False)
        thirdMax = (-1, False)
        
        for num in nums:
            # If current number is already stored, skip it.
            if (firstMax[1] and firstMax[0] == num) or \
                (secondMax[1] and secondMax[0] == num) or \
                (thirdMax[1] and thirdMax[0] == num):
                continue
            
            # If we never stored any variable in firstMax
            # or curr num is bigger than firstMax, then curr num is the biggest number.
            if not firstMax[1] or firstMax[0] <= num:
                thirdMax = secondMax
                secondMax = firstMax
                firstMax = (num, True)
            # If we never stored any variable in secondMax
            # or curr num is bigger than secondMax, then curr num is 2nd biggest number.
            elif not secondMax[1] or secondMax[0] <= num:
                thirdMax = secondMax
                secondMax = (num, True)
            # If we never stored any variable in thirdMax
            # or curr num is bigger than thirdMax, then curr num is 3rd biggest number.
            elif not thirdMax[1] or thirdMax[0] <= num:
                thirdMax = (num, True)
        
        # If third max was never updated, it means we don't have 3 distinct numbers.
        if not thirdMax[1]:
            return firstMax[0]
        
        return thirdMax[0]
```

</details>
