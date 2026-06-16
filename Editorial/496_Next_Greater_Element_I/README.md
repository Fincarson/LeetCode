# 496. Next Greater Element I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/next-greater-element-i/)  
`Array` `Hash Table` `Stack` `Monotonic Stack`

**Problem Link:** [LeetCode 496 - Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)

## Problem

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

### Example 1

```text
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
```

### Example 2

```text
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
```

## Constraints

- 1 <= nums1.length <= nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 104
- All integers in nums1 and nums2 are unique.
- All the integers of nums1 also appear in nums2.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sum of Total Strength of Wizards](https://leetcode.com/problems/sum-of-total-strength-of-wizards/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Next Greater Element IV](https://leetcode.com/problems/next-greater-element-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Remove Nodes From Linked List](https://leetcode.com/problems/remove-nodes-from-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Missing Integer Greater Than Sequential Prefix Sum](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 496. Next Greater Element I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Better Brute Force | C++, Java, Python3 |
| Using Stack | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            bool found = false;
            for (int j = 0; j < nums2.size(); j++) {
                if (found && nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }

                if (nums2[j] == nums1[i]) {
                    found = true;
                }
            }
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length];
        int j;

        for (int i = 0; i < nums1.length; i++) {
            boolean found = false;
            for (j = 0; j < nums2.length; j++) {
                if (found && nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }

                if (nums2[j] == nums1[i]) {
                    found = true;
                }
            }
            if (j == nums2.length) {
                res[i] = -1;
            }
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python3
class Solution:
    def nextGreaterElement(self, nums1, nums2):
        res = [-1] * len(nums1)
        for i, num1 in enumerate(nums1):
            found = False
            for j, num2 in enumerate(nums2):
                if found and num2 > num1:
                    res[i] = num2
                    break

                if num2 == num1:
                    found = True

        return res
```

</details>

<br>

## Approach 2: Better Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums2.size(); i++) {
            hash[nums2[i]] = i;
        }

        vector<int> res(nums1.size());
        int j;
        for (int i = 0; i < nums1.size(); i++) {
            for (j = hash[nums1[i]] + 1; j < nums2.size(); j++) {
                if (nums1[i] < nums2[j]) {
                    res[i] = nums2[j];
                    break;
                }
            }
            if (j == nums2.size()) {
                res[i] = -1;
            }
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            hash.put(nums2[i], i);
        }

        int[] res = new int[nums1.length];
        int j;

        for (int i = 0; i < nums1.length; i++) {
            for (j = hash.get(nums1[i]) + 1; j < nums2.length; j++) {
                if (nums1[i] < nums2[j]) {
                    res[i] = nums2[j];
                    break;
                }
            }
            if (j == nums2.length) {
                res[i] = -1;
            }
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nextGreaterElement(
        self, nums1: List[int], nums2: List[int]
    ) -> List[int]:
        hash_table = {num: i for i, num in enumerate(nums2)}

        res = [0] * len(nums1)
        for i, num in enumerate(nums1):
            j = hash_table[num] + 1
            while j < len(nums2):
                if num < nums2[j]:
                    res[i] = nums2[j]
                    break
                j += 1
            else:
                res[i] = -1

        return res
```

</details>

<br>

## Approach 3: Using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> hashmap;

        for (int num : nums2) {
            while (!stack.empty() && num > stack.top()) {
                hashmap[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }

        while (!stack.empty()) {
            hashmap[stack.top()] = -1;
            stack.pop();
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(hashmap[num]);
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> stack = new Stack<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums2.length; i++) {
            while (!stack.empty() && nums2[i] > stack.peek()) map.put(
                stack.pop(),
                nums2[i]
            );
            stack.push(nums2[i]);
        }

        while (!stack.empty()) map.put(stack.pop(), -1);

        int[] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            res[i] = map.get(nums1[i]);
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nextGreaterElement(self, nums1, nums2):
        stack = []
        hashmap = {}

        for num in nums2:
            while stack and num > stack[-1]:
                hashmap[stack.pop()] = num
            stack.append(num)

        return [hashmap.get(i, -1) for i in nums1]
```

</details>
