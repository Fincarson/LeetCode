# 442. Find All Duplicates in an Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-all-duplicates-in-an-array/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 442 - Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

## Problem

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

### Example 1

```text
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

### Example 2

```text
Input: nums = [1,1,2]
Output: [1]
```

### Example 3

```text
Input: nums = [1]
Output: []
```

## Constraints

- n == nums.length
- 1 <= n <= 105
- 1 <= nums[i] <= n
- Each element in nums appears once or twice.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum of Distances](https://leetcode.com/problems/sum-of-distances/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [The Two Sneaky Numbers of Digitville](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 442. Find All Duplicates in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java |
| Sort and Compare Adjacent Elements | C++, Java |
| Store Seen Elements in a Set / Map | C++, Java |
| Cycle Sort | C++, Java |
| Mark Visited Elements in the Input Array Itself | C++, Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    ans.push_back(nums[i]);
                    break;
                }
            }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == nums[i]) {
                    ans.add(nums[i]);
                    break;
                }
            }
        }

        return ans;
    }
}
```

</details>

<br>

## Approach 2: Sort and Compare Adjacent Elements

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
 public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1]) {
                ans.push_back(nums[i]);
                i++;        // skip over next element
            }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();

        Arrays.sort(nums);

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                ans.add(nums[i]);
                i++;        // skip over next element
            }
        }

        return ans;
    }
}
```

</details>

<br>

## Approach 3: Store Seen Elements in a Set / Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
 public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> seen;

        for (auto& num : nums) {
            if (seen.count(num) > 0)
                ans.push_back(num);
            else
                seen.insert(num);
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        Set<Integer> seen = new HashSet<>();

        for (int num : nums) {
            if (seen.contains(num)) {
                ans.add(num);
            } else {
                seen.add(num);
            }
        }

        return ans;
    }
}
```

</details>

<br>

## Approach 4: Cycle Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        // Use cycle sort to place elements
        // at corresponding index to value
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] != nums[correctIdx]) {
                swap(nums[i], nums[correctIdx]);
            } else {
                i++;
            }
        }

        // Any elements not at the index that corresponds to their value are duplicates
        vector<int> duplicates;
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                duplicates.push_back(nums[i]);
            }
        }

        return duplicates;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;

        // Use cycle sort to place elements
        // at corresponding index to value
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] != nums[correctIdx]) {
                swap(nums, i, correctIdx);
            } else {
				i++;
			}
        }

        // Any elements not at the index that corresponds to their value are duplicates
        List<Integer> duplicates = new ArrayList<>();
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                duplicates.add(nums[i]);
            }
        }

        return duplicates;
    }

    // Swaps two elements in nums
    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```

</details>

<br>

## Approach 5: Mark Visited Elements in the Input Array Itself

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
 public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (auto num : nums)
            nums[abs(num) - 1] *= -1;

        for (auto num : nums)
            if (nums[abs(num) - 1] > 0) {
                ans.push_back(abs(num));
                nums[abs(num) - 1] *= -1;
            }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();

        for (int num : nums) {
            nums[Math.abs(num) - 1] *= -1;
        }

        for (int num : nums) {
            if (nums[Math.abs(num) - 1] > 0) {
                ans.add(Math.abs(num));
                nums[Math.abs(num) - 1] *= -1;
            }
        }

        return ans;
    }
}
```

</details>
