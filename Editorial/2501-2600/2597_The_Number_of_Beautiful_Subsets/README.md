# 2597. The Number of Beautiful Subsets

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/the-number-of-beautiful-subsets/)  
`Array` `Hash Table` `Math` `Dynamic Programming` `Backtracking` `Sorting` `Combinatorics`

**Problem Link:** [LeetCode 2597 - The Number of Beautiful Subsets](https://leetcode.com/problems/the-number-of-beautiful-subsets/)

## Problem

You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

### Example 1

```text
Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
```

### Example 2

```text
Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
```

## Constraints

- 1 <= nums.length <= 18
- 1 <= nums[i], k <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Construct the Lexicographically Largest Valid Sequence](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2597. The Number of Beautiful Subsets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Bitset | C++, Java, Python3 |
| Recursion with Backtracking | C++, Java, Python3 |
| Optimised Recursion (Deriving Recurrence Relation) | C++, Java, Python3 |
| Dynamic Programming - Memoization | C++, Java, Python3 |
| Dynamic Programming - Iterative | C++, Java, Python3 |
| Dynamic Programming - Optimized Iterative | C++, Java, Python3 |

## Approach 1: Using Bitset

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return countBeautifulSubsets(nums, k, 0, 0);
    }

private:
    int countBeautifulSubsets(vector<int>& nums, int difference, int index,
                              int mask) {
        // Base case: Return 1 if mask is greater than 0 (non-empty subset)
        if (index == nums.size()) return mask > 0 ? 1 : 0;

        // Flag to check if the current subset is beautiful
        bool isBeautiful = true;

        // Check if the current number forms a beautiful pair with any previous
        // number in the subset
        for (int j = 0; j < index && isBeautiful; ++j) {
            isBeautiful = ((1 << j) & mask) == 0 ||
                          abs(nums[j] - nums[index]) != difference;
        }

        // Recursively calculate beautiful subsets including and excluding the
        // current number
        int skip = countBeautifulSubsets(nums, difference, index + 1, mask);
        int take;
        if (isBeautiful) {
            take = countBeautifulSubsets(nums, difference, index + 1,
                                         mask + (1 << index));
        } else {
            take = 0;
        }

        return skip + take;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int beautifulSubsets(int[] nums, int k) {
        return countBeautifulSubsets(nums, k, 0, 0);
    }

    private int countBeautifulSubsets(
        int[] nums,
        int difference,
        int index,
        int mask
    ) {
        // Base case: Return 1 if mask is greater than 0 (non-empty subset)
        if (index == nums.length) return mask > 0 ? 1 : 0;

        // Flag to check if the current subset is beautiful
        boolean isBeautiful = true;

        // Check if the current number forms a beautiful pair with any previous number
        // in the subset
        for (int j = 0; j < index && isBeautiful; ++j) {
            isBeautiful = ((1 << j) & mask) == 0 ||
            Math.abs(nums[j] - nums[index]) != difference;
        }

        // Recursively calculate beautiful subsets including and excluding the current
        // number
        int skip = countBeautifulSubsets(nums, difference, index + 1, mask);
        int take;
        if (isBeautiful) {
            take = countBeautifulSubsets(
                nums,
                difference,
                index + 1,
                mask + (1 << index)
            );
        } else {
            take = 0;
        }

        return skip + take;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def beautifulSubsets(self, nums, k):
        return self._count_beautiful_subsets(nums, k, 0, 0)

    def _count_beautiful_subsets(self, nums, difference, index, mask):
        # Base case: Return 1 if mask is greater than 0 (non-empty subset)
        if index == len(nums):
            return 1 if mask > 0 else 0

        # Flag to check if the current subset is beautiful
        is_beautiful = True

        # Check if the current number forms a beautiful pair with any
        # previous number in the subset
        for j in range(index):
            if ((1 << j) & mask) == 0 or abs(
                nums[j] - nums[index]
            ) != difference:
                continue
            else:
                is_beautiful = False
                break

        # Recursively calculate beautiful subsets including and excluding
        # the current number
        skip = self._count_beautiful_subsets(nums, difference, index + 1, mask)
        take = (
            self._count_beautiful_subsets(
                nums, difference, index + 1, mask + (1 << index)
            )
            if is_beautiful
            else 0
        )

        return skip + take
```

</details>

<br>

## Approach 2: Recursion with Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // Frequency map to track elements
        unordered_map<int, int> freqMap;
        // Sort nums array
        sort(nums.begin(), nums.end());
        return countBeautifulSubsets(nums, k, freqMap, 0) - 1;
    }

private:
    int countBeautifulSubsets(vector<int>& nums, int difference,
                              unordered_map<int, int>& freqMap, int i) {
        // Base case: Return 1 for a subset of size 1
        if (i == nums.size()) {
            return 1;
        }
        // Count subsets where nums[i] is not taken
        int totalCount = countBeautifulSubsets(nums, difference, freqMap,
                                               i + 1);  // nums[i] not taken

        // If nums[i] can be taken without violating the condition
        if (!freqMap[nums[i] - difference]) {
            freqMap[nums[i]]++;
            // Recursively count subsets where nums[i] is taken
            totalCount += countBeautifulSubsets(nums, difference, freqMap,
                                                i + 1);  // nums[i] taken
            freqMap[nums[i]]--;
        }

        return totalCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int beautifulSubsets(int[] nums, int k) {
        // Frequency map to track elements
        Map<Integer, Integer> freqMap = new HashMap<>();
        // Sort nums array
        Arrays.sort(nums);
        return countBeautifulSubsets(nums, k, freqMap, 0) - 1;
    }

    private int countBeautifulSubsets(
        int[] nums,
        int difference,
        Map<Integer, Integer> freqMap,
        int i
    ) {
        // Base case: Return 1 for a subset of size 1
        if (i == nums.length) {
            return 1;
        }
        // Count subsets where nums[i] is not taken
        int totalCount = countBeautifulSubsets(
            nums,
            difference,
            freqMap,
            i + 1
        );

        // If nums[i] can be taken without violating the condition
        if (!freqMap.containsKey(nums[i] - difference)) {
            freqMap.put(nums[i], freqMap.getOrDefault(nums[i], 0) + 1); // Mark nums[i] as taken

            // Recursively count subsets where nums[i] is taken
            totalCount +=
            countBeautifulSubsets(nums, difference, freqMap, i + 1);
            freqMap.put(nums[i], freqMap.get(nums[i]) - 1); // Backtrack: mark nums[i] as not taken

            // Remove nums[i] from freqMap if its count becomes 0
            if (freqMap.get(nums[i]) == 0) {
                freqMap.remove(nums[i]);
            }
        }

        return totalCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def beautifulSubsets(self, nums, k):
        # Frequency map to track elements
        freq_map = defaultdict(int)
        # Sort nums array
        nums.sort()
        return self._count_beautiful_subsets(nums, k, freq_map, 0) - 1

    def _count_beautiful_subsets(self, nums, difference, freq_map, i):
        # Base case: Return 1 for a subset of size 1
        if i == len(nums):
            return 1

        # Count subsets where nums[i] is not taken
        total_count = self._count_beautiful_subsets(
            nums, difference, freq_map, i + 1
        )

        # If nums[i] can be taken without violating the condition
        if nums[i] - difference not in freq_map:
            freq_map[nums[i]] += 1  # Mark nums[i] as taken

            # Recursively count subsets where nums[i] is taken
            total_count += self._count_beautiful_subsets(
                nums, difference, freq_map, i + 1
            )
            freq_map[nums[i]] -= 1  # Backtrack: mark nums[i] as not taken

            # Remove nums[i] from freq_map if its count becomes 0
            if freq_map[nums[i]] == 0:
                del freq_map[nums[i]]

        return total_count
```

</details>

<br>

## Approach 3: Optimised Recursion (Deriving Recurrence Relation)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;
        map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }

        // Calculate subsets for each remainder group
        for (auto& fr : freqMap) {
            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            totalCount *= countBeautifulSubsets(subsets, subsets.size(), k, 0);
        }

        return totalCount - 1;
    }

private:
    int countBeautifulSubsets(vector<pair<int, int>>& subsets, int numSubsets,
                              int difference, int i) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // Calculate subsets where the current subset is not taken
        int skip =
            countBeautifulSubsets(subsets, numSubsets, difference, i + 1);
        // Calculate subsets where the current subset is taken
        int take = (1 << subsets[i].second) - 1;

        // If next number has a 'difference', calculate subsets; otherwise, move
        // to next
        if (i + 1 < numSubsets &&
            subsets[i + 1].first - subsets[i].first == difference) {
            take *=
                countBeautifulSubsets(subsets, numSubsets, difference, i + 2);
        } else {
            take *=
                countBeautifulSubsets(subsets, numSubsets, difference, i + 1);
        }

        return skip + take;  // Return total count of subsets
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int beautifulSubsets(int[] nums, int k) {
        int totalCount = 1;
        Map<Integer, Map<Integer, Integer>> freqMap = new TreeMap<>();

        // Calculate frequencies based on remainder
        for (int num : nums) {
            Map<Integer, Integer> fr = freqMap.getOrDefault(
                num % k,
                new TreeMap<>()
            );
            fr.put(num, fr.getOrDefault(num, 0) + 1);
            freqMap.put(num % k, fr);
        }

        // Calculate subsets for each remainder group
        for (Map.Entry<
            Integer,
            Map<Integer, Integer>
        > entry : freqMap.entrySet()) {
            ArrayList<Pair<Integer, Integer>> subsets = new ArrayList<
                Pair<Integer, Integer>
            >(entry.getValue().entrySet().size());
            for (Map.Entry<Integer, Integer> subsetEntry : entry
                .getValue()
                .entrySet()) {
                subsets.add(
                    new Pair<>(subsetEntry.getKey(), subsetEntry.getValue())
                );
            }
            totalCount *= countBeautifulSubsets(subsets, subsets.size(), k, 0);
        }

        return totalCount - 1;
    }

    private int countBeautifulSubsets(
        ArrayList<Pair<Integer, Integer>> subsets,
        int numSubsets,
        int difference,
        int i
    ) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // Calculate subsets where the current subset is not taken
        int skip = countBeautifulSubsets(
            subsets,
            numSubsets,
            difference,
            i + 1
        );
        // Calculate subsets where the current subset is taken
        int take = (1 << subsets.get(i).getValue()) - 1;

        // If next number has a 'difference', calculate subsets; otherwise, move
        // to next
        if (
            i + 1 < numSubsets &&
            subsets.get(i + 1).getKey() - subsets.get(i).getKey() == difference
        ) {
            take *=
            countBeautifulSubsets(subsets, numSubsets, difference, i + 2);
        } else {
            take *=
            countBeautifulSubsets(subsets, numSubsets, difference, i + 1);
        }

        return skip + take; // Return total count of subsets
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        total_count = 1
        freq_map = defaultdict(lambda: defaultdict(int))

        # Calculate frequencies based on remainder
        for x in nums:
            freq_map[x % k][x] += 1

        # Calculate subsets for each remainder group
        for fr in freq_map.values():
            subsets = sorted(fr.items())
            total_count *= self._count_beautiful_subsets(
                subsets, len(subsets), k, 0
            )

        return total_count - 1  # Subtract 1 for the empty subset

    def _count_beautiful_subsets(self, subsets, num_subsets, difference, i):
        # Base case: Return 1 for a subset of size 1
        if i == num_subsets:
            return 1

        # Calculate subsets where the current subset is not taken
        skip = self._count_beautiful_subsets(
            subsets, num_subsets, difference, i + 1
        )

        # Calculate subsets where the current subset is taken
        take = (1 << subsets[i][1]) - 1

        # If next number has a 'difference', calculate subsets; otherwise, move to next
        if (
            i + 1 < num_subsets
            and subsets[i + 1][0] - subsets[i][0] == difference
        ):
            take *= self._count_beautiful_subsets(
                subsets, num_subsets, difference, i + 2
            )
        else:
            take *= self._count_beautiful_subsets(
                subsets, num_subsets, difference, i + 1
            )

        return skip + take  # Return total count of subsets
```

</details>

<br>

## Approach 4: Dynamic Programming - Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;
        map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }

        // Calculate subsets for each remainder group
        for (auto& fr : freqMap) {
            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            // Store counts of subsets for memoization
            vector<int> counts(subsets.size(), -1);
            totalCount *=
                countBeautifulSubsets(subsets, subsets.size(), k, 0, counts);
        }
        return totalCount - 1;
    }

private:
    int countBeautifulSubsets(vector<pair<int, int>>& subsets, int numSubsets,
                              int difference, int i, vector<int>& counts) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // If the count is already calculated, return it
        if (counts[i] != -1) {
            return counts[i];
        }

        // Calculate subsets where the current subset is not taken
        int skip = countBeautifulSubsets(subsets, numSubsets, difference, i + 1,
                                         counts);

        // Calculate subsets where the current subset is taken
        int take = (1 << subsets[i].second) - 1;  // take the current subset

        // If the next number has a difference of 'difference', calculate
        // subsets accordingly
        if (i + 1 < numSubsets &&
            subsets[i + 1].first - subsets[i].first == difference) {
            take *= countBeautifulSubsets(subsets, numSubsets, difference,
                                          i + 2, counts);
        } else {
            take *= countBeautifulSubsets(subsets, numSubsets, difference,
                                          i + 1, counts);
        }

        return counts[i] =
                   skip + take;  // Store and return total count of subsets
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int beautifulSubsets(int[] nums, int k) {
        int totalCount = 1;
        Map<Integer, Map<Integer, Integer>> freqMap = new TreeMap<>();

        // Calculate frequencies based on remainder
        for (int num : nums) {
            int remainder = num % k;
            Map<Integer, Integer> fr = freqMap.getOrDefault(
                remainder,
                new TreeMap<>()
            );
            fr.put(num, fr.getOrDefault(num, 0) + 1);
            freqMap.put(remainder, fr);
        }

        // Calculate subsets for each remainder group
        for (Map.Entry<
            Integer,
            Map<Integer, Integer>
        > entry : freqMap.entrySet()) {
            List<Pair<Integer, Integer>> subsets = new ArrayList<>();
            for (Map.Entry<Integer, Integer> subset : entry
                .getValue()
                .entrySet()) {
                subsets.add(new Pair<>(subset.getKey(), subset.getValue()));
            }
            int[] counts = new int[subsets.size()]; // Store counts of subsets for memoization
            Arrays.fill(counts, -1);
            totalCount *=
            countBeautifulSubsets(subsets, subsets.size(), k, 0, counts);
        }
        return totalCount - 1;
    }

    private int countBeautifulSubsets(
        List<Pair<Integer, Integer>> subsets,
        int numSubsets,
        int difference,
        int i,
        int[] counts
    ) {
        // Base case: Return 1 for a subset of size 1
        if (i == numSubsets) {
            return 1;
        }

        // If the count is already calculated, return it
        if (counts[i] != -1) {
            return counts[i];
        }

        // Calculate subsets where the current subset is not taken
        int skip = countBeautifulSubsets(
            subsets,
            numSubsets,
            difference,
            i + 1,
            counts
        );

        // Calculate subsets where the current subset is taken
        int take = (1 << subsets.get(i).getValue()) - 1; // take the current subset

        // If the next number has a difference of 'difference',
        // calculate subsets accordingly
        if (
            i + 1 < numSubsets &&
            subsets.get(i + 1).getKey() - subsets.get(i).getKey() == difference
        ) {
            take *=
            countBeautifulSubsets(
                subsets,
                numSubsets,
                difference,
                i + 2,
                counts
            );
        } else {
            take *=
            countBeautifulSubsets(
                subsets,
                numSubsets,
                difference,
                i + 1,
                counts
            );
        }

        return counts[i] = skip + take; // Store and return total count of subsets
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def beautifulSubsets(self, nums: List[int], k) -> int:
        total_count = 1
        freq_map = defaultdict(lambda: defaultdict(int))

        # Calculate frequencies based on remainder
        for x in nums:
            freq_map[x % k][x] += 1

        # Calculate subsets for each remainder group
        for fr in freq_map.values():
            s = sorted(fr.items())
            counts = [-1] * len(s)  # Store counts of subsets for memoization
            total_count *= self._count_beautiful_subsets(s, k, 0, counts)

        return total_count - 1  # Subtract 1 for the empty subset

    def _count_beautiful_subsets(
        self,
        subsets: List[List[int]],
        difference: int,
        i: int,
        counts: List[int],
    ) -> int:
        # Base case: Return 1 for a subset of size 1
        if i == len(subsets):
            return 1

        # If the count is already calculated, return it
        if counts[i] != -1:
            return counts[i]

        # Calculate subsets where the current subset is not taken
        skip = self._count_beautiful_subsets(subsets, difference, i + 1, counts)

        # Calculate subsets where the current subset is taken
        take = (1 << subsets[i][1]) - 1

        # If the next number has a difference of 'difference',
        # calculate subsets accordingly
        if (
            i + 1 < len(subsets)
            and subsets[i + 1][0] - subsets[i][0] == difference
        ):
            take *= self._count_beautiful_subsets(
                subsets, difference, i + 2, counts
            )
        else:
            take *= self._count_beautiful_subsets(
                subsets, difference, i + 1, counts
            )

        counts[i] = skip + take  # Store and return total count of subsets
        return counts[i]
```

</details>

<br>

## Approach 5: Dynamic Programming - Iterative

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;

        map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }

        // Iterate through each remainder group
        for (auto& fr : freqMap) {
            int n =
                fr.second.size();  // Number of elements in the current group

            vector<pair<int, int>> subsets(fr.second.begin(), fr.second.end());
            vector<int> counts(n + 1);  // Array to store counts of subsets
            counts[n] = 1;              // Initialize count for the last subset

            // Calculate counts for each subset starting from the second last
            for (int i = n - 1; i >= 0; i--) {
                // Count of subsets skipping the current subset
                int skip = counts[i + 1];

                // Count of subsets including the current subset
                int take = (1 << subsets[i].second) - 1;

                // If next number has a 'difference', calculate subsets;
                // otherwise, move to next
                if (i + 1 < n && subsets[i + 1].first - subsets[i].first == k) {
                    take *= counts[i + 2];
                } else {
                    take *= counts[i + 1];
                }

                // Store the total count for the current subset
                counts[i] = skip + take;
            }

            totalCount *= counts[0];
        }

        return totalCount - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int beautifulSubsets(int[] nums, int k) {
        int totalCount = 1;

        Map<Integer, Map<Integer, Integer>> freqMap = new TreeMap<>();

        // Calculate frequencies based on remainder
        for (int num : nums) {
            int remainder = num % k;
            freqMap
                .computeIfAbsent(remainder, x -> new TreeMap<>())
                .merge(num, 1, Integer::sum);
        }

        // Iterate through each remainder group
        for (Map.Entry<
            Integer,
            Map<Integer, Integer>
        > entry : freqMap.entrySet()) {
            int n = entry.getValue().size(); // Number of elements in the current group

            List<Map.Entry<Integer, Integer>> subsets = new ArrayList<>(
                entry.getValue().entrySet()
            );

            int[] counts = new int[n + 1]; // Array to store counts of subsets

            counts[n] = 1; // Initialize count for the last subset

            // Calculate counts for each subset starting from the second last
            for (int i = n - 1; i >= 0; i--) {
                // Count of subsets skipping the current subset
                int skip = counts[i + 1];

                // Count of subsets including the current subset
                int take = (1 << subsets.get(i).getValue()) - 1;

                // If next number has a 'difference',
                // calculate subsets; otherwise, move to next
                if (
                    i + 1 < n &&
                    subsets.get(i + 1).getKey() - subsets.get(i).getKey() == k
                ) {
                    take *= counts[i + 2];
                } else {
                    take *= counts[i + 1];
                }

                // Store the total count for the current subset
                counts[i] = skip + take;
            }

            totalCount *= counts[0];
        }

        return totalCount - 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        total_count = 1

        freq_map = defaultdict(dict)

        # Calculate frequencies based on remainder
        for num in nums:
            remainder = num % k
            freq_map[remainder][num] = freq_map[remainder].get(num, 0) + 1

        # Iterate through each remainder group
        for fr in freq_map.values():
            n = len(fr)  # Number of elements in the current group

            subsets = sorted(fr.items())
            counts = [0] * (n + 1)  # Array to store counts of subsets
            counts[n] = 1  # Initialize count for the last subset

            # Calculate counts for each subset starting from the second last
            for i in range(n - 1, -1, -1):

                # Count of subsets skipping the current subset
                skip = counts[i + 1]
                # Count of subsets including the current subset
                take = 2 ** subsets[i][1] - 1

                # If next number has a 'difference',
                # calculate subsets; otherwise, move to next
                if i + 1 < n and subsets[i + 1][0] - subsets[i][0] == k:
                    take *= counts[i + 2]
                else:
                    take *= counts[i + 1]

                # Store the total count for the current subset
                counts[i] = skip + take

            total_count *= counts[0]

        return total_count - 1
```

</details>

<br>

## Approach 6: Dynamic Programming - Optimized Iterative

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int totalCount = 1;
        map<int, map<int, int>> freqMap;

        // Calculate frequencies based on remainder
        for (int& num : nums) {
            freqMap[num % k][num]++;
        }

        // Iterate through each remainder group
        for (auto& fr : freqMap) {
            int prevNum = -k, prev2, prev1 = 1, curr;

            // Iterate through each number in the current remainder group
            for (auto& [num, freq] : fr.second) {
                // Count of subsets skipping the current number
                int skip = prev1;

                // Count of subsets including the current number
                // Check if the current number and the previous number
                // form a beautiful pair
                int take;
                if (num - prevNum == k) {
                    take = ((1 << freq) - 1) * prev2;
                } else {
                    take = ((1 << freq) - 1) * prev1;
                }

                // Store the total count for the current number
                curr = skip + take;
                prev2 = prev1;
                prev1 = curr;
                prevNum = num;
            }
            totalCount *= curr;
        }
        return totalCount - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int beautifulSubsets(int[] nums, int k) {
        int totalCount = 1;
        Map<Integer, Map<Integer, Integer>> freqMap = new TreeMap<>();

        // Calculate frequencies based on remainder
        for (int num : nums) {
            Map<Integer, Integer> fr = freqMap.getOrDefault(
                num % k,
                new TreeMap<>()
            );
            fr.put(num, fr.getOrDefault(num, 0) + 1);
            freqMap.put(num % k, fr);
        }

        // Iterate through each remainder group
        for (Map.Entry<
            Integer,
            Map<Integer, Integer>
        > entry : freqMap.entrySet()) {
            int prevNum = -k, prev2 = 0, prev1 = 1, curr = 1;

            // Iterate through each number in the current remainder group
            for (Map.Entry<Integer, Integer> freqEntry : entry
                .getValue()
                .entrySet()) {
                int num = freqEntry.getKey();
                int freq = freqEntry.getValue();
                // Count of subsets skipping the current number
                int skip = prev1;

                // Count of subsets including the current number
                // Check if the current number and the previous number
                // form a beautiful pair
                int take;
                if (num - prevNum == k) {
                    take = ((1 << freq) - 1) * prev2;
                } else {
                    take = ((1 << freq) - 1) * prev1;
                }

                curr = skip + take; // Store the total count for the current number
                prev2 = prev1;
                prev1 = curr;
                prevNum = num;
            }
            totalCount *= curr;
        }
        return totalCount - 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        total_count = 1
        freq_map = defaultdict(dict)

        # Calculate frequencies based on remainder
        for num in nums:
            freq_map[num % k][num] = freq_map[num % k].get(num, 0) + 1

        # Iterate through each remainder group
        for fr in freq_map.values():
            prev_num, curr, prev1, prev2 = -k, 1, 1, 0

            # Iterate through each number in the current remainder group
            for num, freq in sorted(fr.items()):
                # Count of subsets skipping the current number
                skip = prev1

                # Count of subsets including the current number
                # Check if the current number and the previous number
                # form a beautiful pair
                if num - prev_num == k:
                    take = ((1 << freq) - 1) * prev2
                else:
                    take = ((1 << freq) - 1) * prev1

                # Store the total count for the current number
                curr = skip + take
                prev2, prev1 = prev1, curr
                prev_num = num
            total_count *= curr
        return total_count - 1
```

</details>
