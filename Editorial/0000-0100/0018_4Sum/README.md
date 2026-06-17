# 18. 4Sum

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/4sum/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 18 - 4Sum](https://leetcode.com/problems/4sum/)

## Problem

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

### Example 1

```text
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

### Example 2

```text
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```

## Constraints

- 1 <= nums.length <= 200
- -109 <= nums[i] <= 109
- -109 <= target <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [3Sum](https://leetcode.com/problems/3sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [4Sum II](https://leetcode.com/problems/4sum-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Special Quadruplets](https://leetcode.com/problems/count-special-quadruplets/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 18. 4Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hash Set | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start,
                             int k) {
        vector<vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset :
                     kSum(nums, static_cast<long long>(target) - nums[i], i + 1,
                          k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset),
                                      end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;

        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target ||
                       (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({nums[lo++], nums[hi--]});
            }
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        Array.Sort(nums);
        return KSum(nums, target, 0, 4);
    }

    public IList<IList<int>> KSum(int[] nums, long target, int start, int k) {
        List<IList<int>> res = new List<IList<int>>();
        if (start == nums.Length) {
            return res;
        }

        long average_value = target / k;
        if (nums[start] > average_value ||
            average_value > nums[nums.Length - 1]) {
            return res;
        }

        if (k == 2) {
            return TwoSum(nums, target, start);
        }

        for (int i = start; i < nums.Length; i++) {
            if (i == start || nums[i - 1] != nums[i]) {
                foreach (var subset in KSum(nums, target - nums[i], i + 1,
                                            k - 1)) {
                    var list = new List<int> { nums[i] };
                    list.AddRange(subset);
                    res.Add(list);
                }
            }
        }

        return res;
    }

    public IList<IList<int>> TwoSum(int[] nums, long target, int start) {
        List<IList<int>> res = new List<IList<int>>();
        int lo = start, hi = nums.Length - 1;
        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target ||
                       (hi < nums.Length - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.Add(new List<int> { nums[lo++], nums[hi--] });
            }
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    return kSum(nums, target, 0, 4)
}

func kSum(nums []int, target int, start int, k int) [][]int {
    res := [][]int{}
    // If we have run out of numbers to add, return res.
    if start == len(nums) {
        return res
    }
    // There are k remaining values to add to the sum. The
    // average of these values is at least target / k.
    average_value := target / k
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest
    // value in nums is smaller than target / k.
    if nums[start] > average_value || average_value > nums[len(nums)-1] {
        return res
    }
    if k == 2 {
        return twoSum(nums, target, start)
    }
    for i := start; i < len(nums); i++ {
        if i == start || nums[i-1] != nums[i] {
            for _, subset := range kSum(nums, target-nums[i], i+1, k-1) {
                res = append(res, append([]int{nums[i]}, subset...))
            }
        }
    }
    return res
}

func twoSum(nums []int, target int, start int) [][]int {
    res := [][]int{}
    lo := start
    hi := len(nums) - 1
    for lo < hi {
        curr_sum := nums[lo] + nums[hi]
        if curr_sum < target || (lo > start && nums[lo] == nums[lo-1]) {
            lo++
        } else if curr_sum > target || (hi < len(nums)-1 && nums[hi] == nums[hi+1]) {
            hi--
        } else {
            res = append(res, []int{nums[lo], nums[hi]})
            lo++
            hi--
        }
    }
    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        return kSum(nums, target, 0, 4);
    }

    public List<List<Integer>> kSum(int[] nums, long target, int start, int k) {
        List<List<Integer>> res = new ArrayList<>();

        // If we have run out of numbers to add, return res.
        if (start == nums.length) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (
            nums[start] > average_value || average_value > nums[nums.length - 1]
        ) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.length; ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (List<Integer> subset : kSum(
                    nums,
                    target - nums[i],
                    i + 1,
                    k - 1
                )) {
                    res.add(new ArrayList<>(Arrays.asList(nums[i])));
                    res.get(res.size() - 1).addAll(subset);
                }
            }
        }

        return res;
    }

    public List<List<Integer>> twoSum(int[] nums, long target, int start) {
        List<List<Integer>> res = new ArrayList<>();
        int lo = start, hi = nums.length - 1;

        while (lo < hi) {
            int currSum = nums[lo] + nums[hi];
            if (currSum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (
                currSum > target ||
                (hi < nums.length - 1 && nums[hi] == nums[hi + 1])
            ) {
                --hi;
            } else {
                res.add(Arrays.asList(nums[lo++], nums[hi--]));
            }
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var fourSum = function (nums, target) {
    nums.sort((a, b) => a - b);
    return kSum(nums, target, 0, 4);
};
function kSum(nums, target, start, k) {
    let res = [];
    // If we have run out of numbers to add, return res.
    if (start === nums.length) {
        return res;
    }
    // There are k remaining values to add to the sum. The
    // average of these values is at least target / k.
    let average_value = target / k;
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest
    // value in nums is smaller than target / k.
    if (nums[start] > average_value || average_value > nums[nums.length - 1]) {
        return res;
    }
    if (k === 2) {
        return twoSum(nums, target, start);
    }
    for (let i = start; i < nums.length; i++) {
        if (i === start || nums[i - 1] !== nums[i]) {
            for (let subset of kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push([nums[i], ...subset]);
            }
        }
    }
    return res;
}
function twoSum(nums, target, start) {
    let res = [];
    let lo = start,
        hi = nums.length - 1;
    while (lo < hi) {
        let curr_sum = nums[lo] + nums[hi];
        if (curr_sum < target || (lo > start && nums[lo] === nums[lo - 1])) {
            ++lo;
        } else if (
            curr_sum > target ||
            (hi < nums.length - 1 && nums[hi] === nums[hi + 1])
        ) {
            --hi;
        } else {
            res.push([nums[lo++], nums[hi--]]);
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            res = []

            # If we have run out of numbers to add, return res.
            if not nums:
                return res

            # There are k remaining values to add to the sum. The
            # average of these values is at least target // k.
            average_value = target // k

            # We cannot obtain a sum of target if the smallest value
            # in nums is greater than target // k or if the largest
            # value in nums is smaller than target // k.
            if average_value < nums[0] or nums[-1] < average_value:
                return res

            if k == 2:
                return twoSum(nums, target)

            for i in range(len(nums)):
                if i == 0 or nums[i - 1] != nums[i]:
                    for subset in kSum(nums[i + 1 :], target - nums[i], k - 1):
                        res.append([nums[i]] + subset)

            return res

        def twoSum(nums: List[int], target: int) -> List[List[int]]:
            res = []
            lo, hi = 0, len(nums) - 1

            while lo < hi:
                curr_sum = nums[lo] + nums[hi]
                if curr_sum < target or (lo > 0 and nums[lo] == nums[lo - 1]):
                    lo += 1
                elif curr_sum > target or (
                    hi < len(nums) - 1 and nums[hi] == nums[hi + 1]
                ):
                    hi -= 1
                else:
                    res.append([nums[lo], nums[hi]])
                    lo += 1
                    hi -= 1

            return res

        nums.sort()
        return kSum(nums, target, 4)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function fourSum(nums: number[], target: number): number[][] {
    nums.sort((a, b) => a - b);
    return kSum(nums, target, 0, 4);
}
function kSum(
    nums: number[],
    target: number,
    start: number,
    k: number,
): number[][] {
    let res: number[][] = [];
    // If we have run out of numbers to add, return res.
    if (start === nums.length) {
        return res;
    }
    // There are k remaining values to add to the sum. The
    // average of these values is at least target / k.
    let average_value = target / k;
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest
    // value in nums is smaller than target / k.
    if (nums[start] > average_value || average_value > nums[nums.length - 1]) {
        return res;
    }
    if (k === 2) {
        return twoSum(nums, target, start);
    }
    for (let i = start; i < nums.length; i++) {
        if (i === start || nums[i - 1] !== nums[i]) {
            for (let subset of kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push([nums[i], ...subset]);
            }
        }
    }
    return res;
}
function twoSum(nums: number[], target: number, start: number): number[][] {
    let res: number[][] = [];
    let lo: number = start,
        hi: number = nums.length - 1;
    while (lo < hi) {
        let curr_sum: number = nums[lo] + nums[hi];
        if (curr_sum < target || (lo > start && nums[lo] === nums[lo - 1])) {
            ++lo;
        } else if (
            curr_sum > target ||
            (hi < nums.length - 1 && nums[hi] === nums[hi + 1])
        ) {
            --hi;
        } else {
            res.push([nums[lo++], nums[hi--]]);
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start,
                             int k) {
        vector<vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset :
                     kSum(nums, static_cast<long>(target) - nums[i], i + 1,
                          k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset),
                                      end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        unordered_set<long long> s;

        for (int i = start; i < nums.size(); ++i) {
            if (res.empty() || res.back()[1] != nums[i]) {
                if (s.count(target - nums[i])) {
                    res.push_back({int(target - nums[i]), nums[i]});
                }
            }
            s.insert(nums[i]);
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        Array.Sort(nums);
        return kSum(nums, target, 0, 4);
    }

    private IList<IList<int>> kSum(int[] nums, long target, int start, int k) {
        List<IList<int>> res = new List<IList<int>>();
        if (start == nums.Length) {
            return res;
        }

        long averageValue = target / k;
        if (nums[start] > averageValue ||
            averageValue > nums[nums.Length - 1]) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.Length; ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                foreach (List<int> subset in kSum(nums, target - nums[i], i + 1,
                                                  k - 1)) {
                    List<int> temp = new List<int> { nums[i] };
                    temp.AddRange(subset);
                    res.Add(temp);
                }
            }
        }

        return res;
    }

    public IList<IList<int>> twoSum(int[] nums, long target, int start) {
        List<IList<int>> res = new List<IList<int>>();
        HashSet<long> s = new HashSet<long>();
        for (int i = start; i < nums.Length; ++i) {
            if (res.Count == 0 || res[res.Count - 1][1] != nums[i]) {
                if (s.Contains(target - nums[i])) {
                    res.Add(new List<int> { (int)target - nums[i], nums[i] });
                }
            }

            s.Add(nums[i]);
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    return kSum(nums, target, 0, 4)
}

func twoSum(nums []int, target int, start int) [][]int {
    res := make([][]int, 0)
    s := make(map[int]bool)
    for i := start; i < len(nums); i++ {
        if len(res) == 0 || res[len(res)-1][1] != nums[i] {
            if s[target-nums[i]] {
                res = append(res, []int{target - nums[i], nums[i]})
            }
        }
        s[nums[i]] = true
    }
    return res
}

func kSum(nums []int, target int, start int, k int) [][]int {
    res := make([][]int, 0)
    // If we have run out of numbers to add, return res.
    if start == len(nums) {
        return res
    }
    // There are k remaining values to add to the sum. The
    // average of these values is at least target / k.
    average_value := target / k
    // We cannot obtain a sum of target if the smallest value
    // in nums is greater than target / k or if the largest
    // value in nums is smaller than target / k.
    if nums[start] > average_value || average_value > nums[len(nums)-1] {
        return res
    }
    if k == 2 {
        return twoSum(nums, target, start)
    }
    for i := start; i < len(nums); i++ {
        if i == start || nums[i-1] != nums[i] {
            for _, subset := range kSum(nums, target-nums[i], i+1, k-1) {
                res = append(res, append([]int{nums[i]}, subset...))
            }
        }
    }
    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        return kSum(nums, target, 0, 4);
    }

    public List<List<Integer>> kSum(int[] nums, long target, int start, int k) {
        List<List<Integer>> res = new ArrayList<>();

        // If we have run out of numbers to add, return res.
        if (start == nums.length) {
            return res;
        }

        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (
            nums[start] > average_value || average_value > nums[nums.length - 1]
        ) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.length; ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (List<Integer> subset : kSum(
                    nums,
                    target - nums[i],
                    i + 1,
                    k - 1
                )) {
                    res.add(new ArrayList<>(Arrays.asList(nums[i])));
                    res.get(res.size() - 1).addAll(subset);
                }
            }
        }

        return res;
    }

    public List<List<Integer>> twoSum(int[] nums, long target, int start) {
        List<List<Integer>> res = new ArrayList<>();
        Set<Long> s = new HashSet<>();

        for (int i = start; i < nums.length; ++i) {
            if (res.isEmpty() || res.get(res.size() - 1).get(1) != nums[i]) {
                if (s.contains(target - nums[i])) {
                    res.add(Arrays.asList((int) target - nums[i], nums[i]));
                }
            }
            s.add((long) nums[i]);
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const fourSum = function (nums, target) {
    function twoSum(start, target) {
        let res = [];
        let s = new Set();
        for (let i = start; i < nums.length; i++) {
            if (res.length == 0 || res[res.length - 1][1] != nums[i]) {
                if (s.has(target - nums[i])) {
                    res.push([target - nums[i], nums[i]]);
                }
            }
            s.add(nums[i]);
        }
        return res;
    }
    function kSum(start, target, k) {
        let res = [];
        // If we have run out of numbers to add, return res.
        if (start === nums.length) {
            return res;
        }
        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        let averageValue = Math.floor(target / k);
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (
            nums[start] > averageValue ||
            averageValue > nums[nums.length - 1]
        ) {
            return res;
        }
        if (k === 2) {
            return twoSum(start, target);
        }
        for (let i = start; i < nums.length; i++) {
            if (i === start || nums[i - 1] !== nums[i]) {
                kSum(i + 1, target - nums[i], k - 1).forEach((set) => {
                    res.push([nums[i]].concat(set));
                });
            }
        }
        return res;
    }
    nums.sort((a, b) => a - b);
    return kSum(0, target, 4);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            res = []

            # If we have run out of numbers to add, return res.
            if not nums:
                return res

            # There are k remaining values to add to the sum. The
            # average of these values is at least target // k.
            average_value = target // k

            # We cannot obtain a sum of target if the smallest value
            # in nums is greater than target // k or if the largest
            # value in nums is smaller than target // k.
            if average_value < nums[0] or nums[-1] < average_value:
                return res

            if k == 2:
                return twoSum(nums, target)

            for i in range(len(nums)):
                if i == 0 or nums[i - 1] != nums[i]:
                    for subset in kSum(nums[i + 1 :], target - nums[i], k - 1):
                        res.append([nums[i]] + subset)

            return res

        def twoSum(nums: List[int], target: int) -> List[List[int]]:
            res = []
            s = set()

            for i in range(len(nums)):
                if len(res) == 0 or res[-1][1] != nums[i]:
                    if target - nums[i] in s:
                        res.append([target - nums[i], nums[i]])
                s.add(nums[i])

            return res

        nums.sort()
        return kSum(nums, target, 4)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function fourSum(nums: number[], target: number): number[][] {
    function twoSum(start: number, target: number): number[][] {
        let res = [];
        let s = new Set<number>();
        for (let i = start; i < nums.length; i++) {
            if (res.length == 0 || res[res.length - 1][1] != nums[i]) {
                if (s.has(target - nums[i])) {
                    res.push([target - nums[i], nums[i]]);
                }
            }
            s.add(nums[i]);
        }
        return res;
    }
    function kSum(start: number, target: number, k: number): number[][] {
        let res = [];
        // If we have run out of numbers to add, return res.
        if (start === nums.length) {
            return res;
        }
        // There are k remaining values to add to the sum. The
        // average of these values is at least target / k.
        let averageValue = Math.floor(target / k);
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (
            nums[start] > averageValue ||
            averageValue > nums[nums.length - 1]
        ) {
            return res;
        }
        if (k === 2) {
            return twoSum(start, target);
        }
        for (let i = start; i < nums.length; i++) {
            if (i === start || nums[i - 1] !== nums[i]) {
                kSum(i + 1, target - nums[i], k - 1).forEach((set) => {
                    res.push([nums[i]].concat(set));
                });
            }
        }
        return res;
    }
    nums.sort((a, b) => a - b);
    return kSum(0, target, 4);
}
```

</details>
