# 2948. Make Lexicographically Smallest Array by Swapping Elements

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)  
`Array` `Union-Find` `Sorting`

**Problem Link:** [LeetCode 2948 - Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)

## Problem

You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

### Example 1

```text
Input: nums = [1,5,3,9,8], limit = 2
Output: [1,3,5,8,9]
Explanation: Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
We cannot obtain a lexicographically smaller array by applying any more operations.
Note that it may be possible to get the same result by doing different operations.
```

### Example 2

```text
Input: nums = [1,7,6,18,2,1], limit = 3
Output: [1,6,7,18,1,2]
Explanation: Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
We cannot obtain a lexicographically smaller array by applying any more operations.
```

### Example 3

```text
Input: nums = [1,7,28,19,10], limit = 3
Output: [1,7,28,19,10]
Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= limit <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2948. Make Lexicographically Smallest Array by Swapping Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting + Grouping | C++, Java, Python3 |

## Approach: Sorting + Grouping

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));

        for (int i = 1; i < nums.size(); i++) {
            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                // new group
                currGroup++;
            }

            // assign current element to group
            numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));

            // add element to sorted group list
            if (groupToList.find(currGroup) == groupToList.end()) {
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        // iterate through input and overwrite each element with the next
        // element in its corresponding group
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int[] numsSorted = new int[nums.length];
        for (int i = 0; i < nums.length; i++) numsSorted[i] = nums[i];
        Arrays.sort(numsSorted);

        int currGroup = 0;
        HashMap<Integer, Integer> numToGroup = new HashMap<>();
        numToGroup.put(numsSorted[0], currGroup);

        HashMap<Integer, LinkedList<Integer>> groupToList = new HashMap<>();
        groupToList.put(
            currGroup,
            new LinkedList<Integer>(Arrays.asList(numsSorted[0]))
        );

        for (int i = 1; i < nums.length; i++) {
            if (Math.abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                // new group
                currGroup++;
            }

            // assign current element to group
            numToGroup.put(numsSorted[i], currGroup);

            // add element to sorted group list
            if (!groupToList.containsKey(currGroup)) {
                groupToList.put(currGroup, new LinkedList<Integer>());
            }
            groupToList.get(currGroup).add(numsSorted[i]);
        }

        // iterate through input and overwrite each element with the next element in its corresponding group
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int group = numToGroup.get(num);
            nums[i] = groupToList.get(group).pop();
        }

        return nums;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        nums_sorted = sorted(nums)

        curr_group = 0
        num_to_group = {}
        num_to_group[nums_sorted[0]] = curr_group

        group_to_list = {}
        group_to_list[curr_group] = deque([nums_sorted[0]])

        for i in range(1, len(nums)):
            if abs(nums_sorted[i] - nums_sorted[i - 1]) > limit:
                # new group
                curr_group += 1

            # assign current element to group
            num_to_group[nums_sorted[i]] = curr_group

            # add element to sorted group deque
            if curr_group not in group_to_list:
                group_to_list[curr_group] = deque()
            group_to_list[curr_group].append(nums_sorted[i])

        # iterate through input and overwrite each element with the next element in its corresponding group
        for i in range(len(nums)):
            num = nums[i]
            group = num_to_group[num]
            nums[i] = group_to_list[group].popleft()

        return nums
```

</details>
