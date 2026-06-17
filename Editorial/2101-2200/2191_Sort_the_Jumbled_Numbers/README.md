# 2191. Sort the Jumbled Numbers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sort-the-jumbled-numbers/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 2191 - Sort the Jumbled Numbers](https://leetcode.com/problems/sort-the-jumbled-numbers/)

## Problem

You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

- Elements with the same mapped values should appear in the same relative order as in the input.
- The elements of nums should only be sorted based on their mapped values and not be replaced by them.

### Example 1

```text
Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation:
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
```

### Example 2

```text
Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
```

## Constraints

- mapping.length == 10
- 0 <= mapping[i] <= 9
- All the values of mapping[i] are unique.
- 1 <= nums.length <= 3 * 104
- 0 <= nums[i] < 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2191. Sort the Jumbled Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Conversion using strings and Sorting | C++, Java, Python3 |
| Conversion without using strings and Sorting | C++, Java, Python3 |

## Approach 1: Conversion using strings and Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            // Convert current value to string
            string number = to_string(nums[i]);
            string formed = "";
            for (int j = 0; j < number.size(); ++j) {
                formed = formed + (to_string(mapping[number[j] - '0']));
            }
            // Store the mapped value.
            int mappedValue = stoi(formed);
            // Push a pair consisting of mapped value and original value;s
            // index.
            storePairs.push_back({mappedValue, i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
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

    public int[] sortJumbled(int[] mapping, int[] nums) {
        ArrayList<Integer[]> storePairs = new ArrayList<>();

        for (int i = 0; i < nums.length; ++i) {
            // Convert current value to string
            String number = Integer.toString(nums[i]);
            String formed = "";
            for (int j = 0; j < number.length(); ++j) {
                formed = formed +
                Integer.toString(mapping[number.charAt(j) - '0']);
            }
            // Store the mapped value.
            int mappedValue = Integer.parseInt(formed);
            // Push a pair consisting of mapped value and original value's index.
            storePairs.add(new Integer[] { mappedValue, i });
        }

        // Sort the array in non-decreasing order by the first value (default).
        Collections.sort(
            storePairs,
            new Comparator<Integer[]>() {
                @Override
                public int compare(Integer[] o1, Integer[] o2) {
                    return o1[0].compareTo(o2[0]);
                }
            }
        );

        int[] answer = new int[nums.length];
        for (int i = 0; i < storePairs.size(); i++) {
            answer[i] = nums[storePairs.get(i)[1]];
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortJumbled(self, mapping, nums):
        store_pairs = []

        for i in range(len(nums)):
            # Convert current value to string
            number = str(nums[i])
            formed = ""
            for j in range(len(number)):
                formed = formed + str(mapping[int(number[j])])
            # Store the mapped value.
            mapped_value = int(formed)
            # Push a pair consisting of mapped value and original value's index.
            store_pairs.append((mapped_value, i))

        # Sort the array in non-decreasing order by the first value (default).
        store_pairs.sort()
        answer = []
        for pair in store_pairs:
            answer.append(nums[pair[1]])
        return answer
```

</details>

<br>

## Approach 2: Conversion without using strings and Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            int mappedValue = 0;
            int temp = nums[i];
            // Start making changes from the units place.
            int place = 1;
            // If the value initially is 0, return mapping[0] and index.
            if (temp == 0) {
                storePairs.push_back({mapping[0], i});
                continue;
            }
            // Repeat the process for units, tenths, hundredths.. places.
            while (temp != 0) {
                mappedValue = place * mapping[temp % 10] + mappedValue;
                place *= 10;
                temp /= 10;
            }
            storePairs.push_back({mappedValue, i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[] sortJumbled(int[] mapping, int[] nums) {
        List<int[]> storePairs = new ArrayList<int[]>();

        for (int i = 0; i < nums.length; i++) {
            int mappedValue = 0;
            int temp = nums[i];
            int place = 1;

            if (temp == 0) {
                storePairs.add(new int[] { mapping[0], i });
                continue;
            }
            while (temp != 0) {
                mappedValue = place * mapping[temp % 10] + mappedValue;
                place *= 10;
                temp /= 10;
            }
            storePairs.add(new int[] { mappedValue, i });
        }

        Collections.sort(storePairs, (a, b) -> a[0] - b[0]);

        int[] answer = new int[nums.length];
        for (int i = 0; i < storePairs.size(); i++) {
            answer[i] = nums[storePairs.get(i)[1]];
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        store_pairs = []

        for i in range(len(nums)):
            mapped_value = 0
            temp = nums[i]

            # Start making changes from the units place.
            place = 1
            # If the value initially is 0, return mapping[0] and index.
            if temp == 0:
                store_pairs.append((mapping[0], i))
                continue
            # Repeat the process for units, tenths, hundredths.. places.
            while temp != 0:
                mapped_value = place * mapping[temp % 10] + mapped_value
                place *= 10
                temp //= 10
            store_pairs.append((mapped_value, i))

        # Sort the array in non-decreasing order by the first value (default).
        store_pairs.sort()
        answer = [nums[pair[1]] for pair in store_pairs]

        return answer
```

</details>
