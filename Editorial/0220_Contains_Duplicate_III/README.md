# 220. Contains Duplicate III

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/contains-duplicate-iii/)  
`Array` `Sliding Window` `Sorting` `Bucket Sort` `Ordered Set`

**Problem Link:** [LeetCode 220 - Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/)

## Problem

You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

- i != j,
- abs(i - j) <= indexDiff.
- abs(nums[i] - nums[j]) <= valueDiff, and

Return true if such pair exists or false otherwise.

### Example 1

```text
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
```

### Example 2

```text
Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
```

## Constraints

- 2 <= nums.length <= 105
- -109 <= nums[i] <= 109
- 1 <= indexDiff <= nums.length
- 0 <= valueDiff <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 220. Contains Duplicate III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Naive Linear Search) [Time Limit Exceeded] | C++, Java, Python3 |
| Approach #2 (Binary Search Tree) [Accepted] | C++, Java, Python3 |
| Approach #3 (Buckets) [Accepted] | C++, Java, Python3 |

## Approach #1 (Naive Linear Search) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = max(i - k, 0); j < i; ++j) {
                if (abs((long long)nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        for (int i = 0; i < nums.length; ++i) {
            for (int j = Math.max(i - k, 0); j < i; ++j) {
                if (Math.abs((long) nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def containsNearbyAlmostDuplicate(
        self, nums: List[int], k: int, t: int
    ) -> bool:
        for i in range(len(nums)):
            for j in range(max(i - k, 0), i):
                if abs(nums[i] - nums[j]) <= t:
                    return True
        return False
```

</details>

<br>

## Approach #2 (Binary Search Tree) [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            // Find the successor of current element
            auto s = set.lower_bound(nums[i]);
            if (s != set.end() && *s <= nums[i] + t) return true;

            // Find the predecessor of current element
            if (s != set.begin()) {
                auto g = prev(s);
                if (nums[i] <= *g + t) return true;
            }

            set.insert(nums[i]);
            if (set.size() > k) {
                set.erase(nums[i - k]);
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < nums.length; ++i) {
            // Find the successor of current element
            Integer s = set.ceiling(nums[i]);
            if (s != null && (long) s <= nums[i] + t) return true;

            // Find the predecessor of current element
            Integer g = set.floor(nums[i]);
            if (g != null && nums[i] <= (long) g + t) return true;

            set.add(nums[i]);
            if (set.size() > k) {
                set.remove(nums[i - k]);
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedList


class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        set_ = SortedList()
        for i in range(len(nums)):
            # Find the successor of current element
            idx = set_.bisect_left(nums[i])
            if idx != len(set_) and set_[idx] <= nums[i] + t:
                return True

            # Find the predecessor of current element
            if idx > 0 and nums[i] <= set_[idx - 1] + t:
                return True

            set_.add(nums[i])
            if len(set_) > k:
                set_.remove(nums[i - k])

        return False
```

</details>

<br>

## Approach #3 (Buckets) [Accepted]

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Get the ID of the bucket from element value x and bucket width w
    // This function handles floor division correctly for both positive and
    // negative numbers.
    long getID(long x, long w) { return x < 0 ? (x + 1) / w - 1 : x / w; }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        unordered_map<long, long> buckets;
        long w = (long)t + 1;
        for (int i = 0; i < nums.size(); ++i) {
            long bucket = getID(nums[i], w);
            // Check if current bucket is empty, each bucket may contain at most
            // one element
            if (buckets.count(bucket)) return true;
            // Check the neighbor buckets for almost duplicate
            if (buckets.count(bucket - 1) &&
                abs(nums[i] - buckets[bucket - 1]) < w)
                return true;
            if (buckets.count(bucket + 1) &&
                abs(nums[i] - buckets[bucket + 1]) < w)
                return true;
            // Now bucket is empty and no almost duplicate in neighbor buckets
            buckets[bucket] = (long)nums[i];
            if (i >= k) {
                buckets.erase(getID(nums[i - k], w));
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Get the ID of the bucket from element value x and bucket width w
    // Java's division `/` rounds towards zero, but we need floor division for correct bucketing.
    private long getID(long x, long w) {
        return Math.floorDiv(x, w);
    }

    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (t < 0) return false;
        Map<Long, Long> buckets = new HashMap<>();
        long w = (long) t + 1;
        for (int i = 0; i < nums.length; ++i) {
            long bucket = getID(nums[i], w);
            // check if current bucket is empty, each bucket may contain at most one element
            if (buckets.containsKey(bucket)) return true;
            // check the neighbor buckets for almost duplicate
            if (
                buckets.containsKey(bucket - 1) &&
                Math.abs(nums[i] - buckets.get(bucket - 1)) < w
            ) return true;
            if (
                buckets.containsKey(bucket + 1) &&
                Math.abs(nums[i] - buckets.get(bucket + 1)) < w
            ) return true;
            // now bucket is empty and no almost duplicate in neighbor buckets
            buckets.put(bucket, (long) nums[i]);
            if (i >= k) buckets.remove(getID(nums[i - k], w));
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Get the ID of the bucket from element value x and bucket width w
    # Division '/' in Python with '//' performs floor division, which is necessary for correct bucketing.
    def getID(self, x, w):
        return (
            x // w
        )  # Floor division to handle both positive and negative integers correctly

    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if t < 0:
            return False
        buckets = {}
        w = t + 1  # Increment by 1 to handle the range correctly
        for i in range(len(nums)):
            bucket = self.getID(nums[i], w)
            # Check if current bucket is empty, each bucket may contain at most one element
            if bucket in buckets:
                return True
            # Check the neighbor buckets for almost duplicates
            if bucket - 1 in buckets and abs(nums[i] - buckets[bucket - 1]) < w:
                return True
            if bucket + 1 in buckets and abs(nums[i] - buckets[bucket + 1]) < w:
                return True
            # Now bucket is empty and no almost duplicates in neighbor buckets
            buckets[bucket] = nums[i]
            if i >= k:
                del buckets[self.getID(nums[i - k], w)]
        return False
```

</details>
