# 350. Intersection of Two Arrays II

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)  
`Array` `Hash Table` `Two Pointers` `Binary Search` `Sorting`

**Problem Link:** [LeetCode 350 - Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## Problem

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

### Example 1

```text
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

### Example 2

```text
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

Follow up:

- What if the given array is already sorted? How would you optimize your algorithm?
- What if nums1's size is small compared to nums2's size? Which algorithm is better?
- What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find Common Characters](https://leetcode.com/problems/find-common-characters/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Choose Numbers From Two Arrays in Range](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Common Value](https://leetcode.com/problems/minimum-common-value/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 350. Intersection of Two Arrays II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Map | C++, Java |
| Sort | C++, Java |
| Built-in Intersection | C++ |

## Approach 1: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> m;
    for (auto n : nums1) {
        ++m[n];
    }
    int k = 0;
    for (auto n : nums2) {
        auto it = m.find(n);
        if (it != end(m) && --it->second >= 0) {
            nums1[k++] = n;
        }
    }
    return vector(begin(nums1), begin(nums1) + k);
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int[] intersect(int[] nums1, int[] nums2) {
    if (nums1.length > nums2.length) {
        return intersect(nums2, nums1);
    }
    HashMap<Integer, Integer> m = new HashMap<>();
    for (int n : nums1) {
        m.put(n, m.getOrDefault(n, 0) + 1);
    }
    int k = 0;
    for (int n : nums2) {
        int cnt = m.getOrDefault(n, 0);
        if (cnt > 0) {
            nums1[k++] = n;
            m.put(n, cnt - 1);
        }
    }
    return Arrays.copyOfRange(nums1, 0, k);
}
```

</details>

<br>

## Approach 2: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    int i = 0, j = 0, k = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            nums1[k++] = nums1[i++];
            ++j;
        }
    }
    return vector<int>(begin(nums1), begin(nums1) + k);
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public int[] intersect(int[] nums1, int[] nums2) {
    Arrays.sort(nums1);
    Arrays.sort(nums2);
    int i = 0, j = 0, k = 0;
    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            nums1[k++] = nums1[i++];
            ++j;
        }
    }
    return Arrays.copyOfRange(nums1, 0, k);
}
```

</details>

<br>

## Approach 3: Built-in Intersection

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    nums1.erase(set_intersection(begin(nums1), end(nums1),
        begin(nums2), end(nums2), begin(nums1)), end(nums1));
    return nums1;
}
```

</details>
