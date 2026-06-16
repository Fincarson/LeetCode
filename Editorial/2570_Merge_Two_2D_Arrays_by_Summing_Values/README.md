# 2570. Merge Two 2D Arrays by Summing Values

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/)  
`Array` `Hash Table` `Two Pointers`

**Problem Link:** [LeetCode 2570 - Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/)

## Problem

You are given two 2D integer arrays nums1 and nums2.

- nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
- nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.

Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

- Only ids that appear in at least one of the two arrays should be included in the resulting array.
- Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.

Return the resulting array. The returned array must be sorted in ascending order by id.

### Example 1

```text
Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
Output: [[1,6],[2,3],[3,2],[4,6]]
Explanation: The resulting array contains the following:
- id = 1, the value of this id is 2 + 4 = 6.
- id = 2, the value of this id is 3.
- id = 3, the value of this id is 2.
- id = 4, the value of this id is 5 + 1 = 6.
```

### Example 2

```text
Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
Explanation: There are no common ids, so we just include each id with its value in the resulting list.
```

## Constraints

- 1 <= nums1.length, nums2.length <= 200
- nums1[i].length == nums2[j].length == 2
- 1 <= idi, vali <= 1000
- Both arrays contain unique ids.
- Both arrays are in strictly ascending order by id.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Meeting Scheduler](https://leetcode.com/problems/meeting-scheduler/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Merge Similar Items](https://leetcode.com/problems/merge-similar-items/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2570. Merge Two 2D Arrays by Summing Values

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| HashMap | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |

## Approach 1: HashMap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> keyToSum;

        // Copying the array nums1 to the map.
        for (auto nums : nums1) {
            keyToSum[nums[0]] = nums[1];
        }

        // Adding the values to existing keys or create new entries.
        for (auto nums : nums2) {
            keyToSum[nums[0]] += nums[1];
        }

        vector<vector<int>> mergedArray;
        for (auto it : keyToSum) {
            mergedArray.push_back({it.first, it.second});
        }

        return mergedArray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        Map<Integer, Integer> keyToSum = new TreeMap<>();

        // Copying the array nums1 to the map.
        for (int[] nums : nums1) {
            keyToSum.put(nums[0], nums[1]);
        }

        // Adding the values to existing keys or create new entries.
        for (int[] nums : nums2) {
            keyToSum.put(nums[0], keyToSum.getOrDefault(nums[0], 0) + nums[1]);
        }

        List<int[]> mergedList = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : keyToSum.entrySet()) {
            mergedList.add(new int[] { entry.getKey(), entry.getValue() });
        }

        // Convert the mergedList to int[][] array.
        int[][] mergedArray = new int[mergedList.size()][2];
        for (int i = 0; i < mergedList.size(); i++) {
            mergedArray[i] = mergedList.get(i);
        }

        return mergedArray;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mergeArrays(
        self, nums1: List[List[int]], nums2: List[List[int]]
    ) -> List[List[int]]:
        key_to_sum = {}

        # Copying the array nums1 to the map.
        for nums in nums1:
            key_to_sum[nums[0]] = nums[1]

        # Adding the values to existing keys or create new entries.
        for nums in nums2:
            key_to_sum[nums[0]] = key_to_sum.get(nums[0], 0) + nums[1]

        merged_array = []
        for key, value in sorted(key_to_sum.items()):
            merged_array.append([key, value])

        return merged_array
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;

        vector<vector<int>> mergedArray;
        while (ptr1 < N1 && ptr2 < N2) {
            // If the id is same, add the values and insert to the result.
            // Increment both pointers.
            if (nums1[ptr1][0] == nums2[ptr2][0]) {
                mergedArray.push_back(
                    {nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            } else if (nums1[ptr1][0] < nums2[ptr2][0]) {
                // If the id in nums1 is smaller, add it to result and increment
                // the pointer
                mergedArray.push_back(nums1[ptr1]);
                ptr1++;
            } else {
                // If the id in nums2 is smaller, add it to result and increment
                // the pointer
                mergedArray.push_back(nums2[ptr2]);
                ptr2++;
            }
        }

        // If pairs are remaining in the nums1, then add them to the result.
        while (ptr1 < N1) {
            mergedArray.push_back(nums1[ptr1]);
            ptr1++;
        }

        // If pairs are remaining in the nums2, then add them to the result.
        while (ptr2 < N2) {
            mergedArray.push_back(nums2[ptr2]);
            ptr2++;
        }

        return mergedArray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int N1 = nums1.length, N2 = nums2.length;
        int ptr1 = 0, ptr2 = 0;

        List<int[]> mergedArray = new ArrayList<>();
        while (ptr1 < N1 && ptr2 < N2) {
            // If the id is same, add the values and insert to the result.
            // Increment both pointers.
            if (nums1[ptr1][0] == nums2[ptr2][0]) {
                mergedArray.add(
                    new int[] {
                        nums1[ptr1][0],
                        nums1[ptr1][1] + nums2[ptr2][1],
                    }
                );
                ptr1++;
                ptr2++;
            } else if (nums1[ptr1][0] < nums2[ptr2][0]) {
                // If the id in nums1 is smaller, add it to result and increment the pointer
                mergedArray.add(nums1[ptr1]);
                ptr1++;
            } else {
                // If the id in nums2 is smaller, add it to result and increment the pointer
                mergedArray.add(nums2[ptr2]);
                ptr2++;
            }
        }

        // If pairs are remaining in the nums1, then add them to the result.
        while (ptr1 < N1) {
            mergedArray.add(nums1[ptr1]);
            ptr1++;
        }

        // If pairs are remaining in the nums2, then add them to the result.
        while (ptr2 < N2) {
            mergedArray.add(nums2[ptr2]);
            ptr2++;
        }

        // Convert List<int[]> to int[][]
        int[][] result = new int[mergedArray.size()][2];
        for (int i = 0; i < mergedArray.size(); i++) {
            result[i] = mergedArray.get(i);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mergeArrays(
        self, nums1: list[list[int]], nums2: list[list[int]]
    ) -> list[list[int]]:
        N1, N2 = len(nums1), len(nums2)
        ptr1, ptr2 = 0, 0

        merged_array = []
        while ptr1 < N1 and ptr2 < N2:
            # If the id is same, add the values and insert to the result.
            # Increment both pointers.
            if nums1[ptr1][0] == nums2[ptr2][0]:
                merged_array.append(
                    [nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]]
                )
                ptr1 += 1
                ptr2 += 1
            elif nums1[ptr1][0] < nums2[ptr2][0]:
                # If the id in nums1 is smaller, add it to result and increment the pointer
                merged_array.append(nums1[ptr1])
                ptr1 += 1
            else:
                # If the id in nums2 is smaller, add it to result and increment the pointer
                merged_array.append(nums2[ptr2])
                ptr2 += 1

        # If pairs are remaining in the nums1, then add them to the result.
        while ptr1 < N1:
            merged_array.append(nums1[ptr1])
            ptr1 += 1

        # If pairs are remaining in the nums2, then add them to the result.
        while ptr2 < N2:
            merged_array.append(nums2[ptr2])
            ptr2 += 1

        return merged_array
```

</details>
