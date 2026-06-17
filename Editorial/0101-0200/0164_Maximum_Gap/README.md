# 164. Maximum Gap

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-gap/)  
`Array` `Sorting` `Bucket Sort` `Radix Sort`

**Problem Link:** [LeetCode 164 - Maximum Gap](https://leetcode.com/problems/maximum-gap/)

## Problem

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

### Example 1

```text
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
```

### Example 2

```text
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Widest Vertical Area Between Two Points Containing No Points](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Maximum Consecutive Floors Without Special Floors](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 164. Maximum Gap

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Comparison Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Radix Sort | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Buckets and The Pigeonhole Principle | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Comparison Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int maximumGap(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 2)  // check if array is empty or small sized
        return 0;

    qsort(nums, numsSize, sizeof(int), cmp);  // sort the array

    int maxGap = 0;

    for (int i = 0; i < numsSize - 1; i++)
        maxGap =
            (nums[i + 1] - nums[i] > maxGap) ? nums[i + 1] - nums[i] : maxGap;

    return maxGap;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() ||
            nums.size() < 2)  // check if array is empty or small sized
            return 0;

        sort(nums.begin(), nums.end());  // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximumGap(int[] nums) {
        if (nums == null ||
            nums.Length < 2) // check if array is empty or small sized
            return 0;

        Array.Sort(nums); // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.Length - 1; i++)
            maxGap = Math.Max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumGap(nums []int) int {
    if len(nums) < 2 { // check if array is small sized
        return 0
    }

    sort.Ints(nums) // sort the array

    maxGap := 0

    for i := 0; i < len(nums)-1; i++ {
        diff := nums[i+1] - nums[i]
        if diff > maxGap {
            maxGap = diff
        }
    }

    return maxGap
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maximumGap(int[] nums) {
        if (
            nums == null || nums.length < 2
        ) return 0; // check if array is empty or small sized

        Arrays.sort(nums); // sort the array

        int maxGap = 0;

        for (int i = 0; i < nums.length - 1; i++) maxGap = Math.max(
            nums[i + 1] - nums[i],
            maxGap
        );

        return maxGap;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumGap = function (nums) {
    if (nums == null || nums.length < 2)
        // check if array is empty or small sized
        return 0;

    nums.sort((a, b) => a - b); // sort the array

    var maxGap = 0;

    for (var i = 0; i < nums.length - 1; i++)
        maxGap = Math.max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumGap(self, nums):
        if (
            nums is None or len(nums) < 2
        ):  # check if array is empty or small sized
            return 0

        nums.sort()  # sort the array

        maxGap = 0

        for i in range(len(nums) - 1):
            maxGap = max(nums[i + 1] - nums[i], maxGap)

        return maxGap
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumGap(nums: number[]): number {
    if (nums == null || nums.length < 2)
        // check if array is empty or small sized
        return 0;

    nums.sort((a, b) => a - b); // sort the array

    var maxGap = 0;

    for (var i = 0; i < nums.length - 1; i++)
        maxGap = Math.max(nums[i + 1] - nums[i], maxGap);

    return maxGap;
}
```

</details>

<br>

## Approach 2: Radix Sort

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maximumGap(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 2) {
        return 0;
    }

    int maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        maxVal = (maxVal > nums[i]) ? maxVal : nums[i];
    }

    long exp = 1;
    int radix = 10;
    int* aux = (int*)malloc(numsSize * sizeof(int));

    while (maxVal / exp > 0) {
        int count[radix];
        memset(count, 0, sizeof(count));

        for (int i = 0; i < numsSize; i++) {
            count[(nums[i] / exp) % 10]++;
        }

        for (int i = 1; i < radix; i++) {
            count[i] += count[i - 1];
        }

        for (int i = numsSize - 1; i >= 0; i--) {
            aux[--count[(nums[i] / exp) % 10]] = nums[i];
        }

        memmove(nums, aux, numsSize * sizeof(int));

        exp *= 10;
    }
    int maxGap = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int diff = nums[i + 1] - nums[i];
        maxGap = (maxGap > diff) ? maxGap : diff;
    }
    return maxGap;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        long exp = 1;   // 1, 10, 100, 1000 ...
        int radix = 10; // base 10 system

        vector<int> aux(nums.size());

        /* LSD Radix Sort */
        while (maxVal / exp > 0) { // Go through all digits from LSD to MSD
            vector<int> count(radix, 0);

            for (int i = 0; i < nums.size(); i++) // Counting sort
                count[(nums[i] / exp) % 10]++;

            for (int i = 1; i < count.size();
                 i++) // you could also use partial_sum()
                count[i] += count[i - 1];

            for (int i = nums.size() - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximumGap(int[] nums) {
        if (nums == null || nums.Length < 2) {
            return 0;
        }

        int maxVal = nums.Max();

        int exp = 1;
        int radix = 10;
        int[] aux = new int[nums.Length];

        while (maxVal / exp > 0) {
            int[] count = new int[radix];

            foreach (int num in nums)
                count[(num / exp) % 10]++;

            for (int i = 1; i < radix; i++)
                count[i] += count[i - 1];

            for (int i = nums.Length - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.Length; i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.Length - 1; i++)
            maxGap = Math.Max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumGap(nums []int) int {
    if nums == nil || len(nums) < 2 {
        return 0
    }

    maxVal := nums[0]
    for _, num := range nums {
        if num > maxVal {
            maxVal = num
        }
    }
    exp := 1
    radix := 10
    aux := make([]int, len(nums))

    for maxVal/exp > 0 {
        count := make([]int, radix)

        for _, num := range nums {
            count[(num/exp)%10]++
        }

        for i := 1; i < radix; i++ {
            count[i] += count[i-1]
        }

        for i := len(nums) - 1; i >= 0; i-- {
            count[(nums[i]/exp)%10]--
            aux[count[(nums[i]/exp)%10]] = nums[i]
        }

        copy(nums, aux)

        exp *= 10
    }

    maxGap := 0
    for i := 0; i < len(nums)-1; i++ {
        tmp := nums[i+1] - nums[i]
        if tmp > maxGap {
            maxGap = tmp
        }
    }
    return maxGap
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) {
            return 0;
        }

        int maxVal = Integer.MIN_VALUE;
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }

        int exp = 1;
        int radix = 10;
        int[] aux = new int[nums.length];

        while (maxVal / exp > 0) {
            int[] count = new int[radix];

            for (int num : nums) {
                count[(num / exp) % 10]++;
            }

            for (int i = 1; i < count.length; i++) {
                count[i] += count[i - 1];
            }

            for (int i = nums.length - 1; i >= 0; i--) {
                aux[--count[(nums[i] / exp) % 10]] = nums[i];
            }

            System.arraycopy(aux, 0, nums, 0, nums.length);

            exp *= 10;
        }
        int maxGap = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            maxGap = Math.max(nums[i + 1] - nums[i], maxGap);
        }
        return maxGap;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumGap = function (nums) {
    if (!nums || nums.length < 2) {
        return 0;
    }

    let maxVal = Math.max(...nums);
    let exp = 1;
    let radix = 10;
    let aux = new Array(nums.length);

    while (Math.floor(maxVal / exp) > 0) {
        let count = new Array(radix).fill(0);

        for (let num of nums) {
            count[Math.floor(num / exp) % 10]++;
        }

        for (let i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        for (let i = nums.length - 1; i >= 0; i--) {
            aux[--count[Math.floor(nums[i] / exp) % 10]] = nums[i];
        }

        for (let i = 0; i < nums.length; i++) nums[i] = aux[i];

        exp *= 10;
    }
    let maxGap = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        maxGap = Math.max(nums[i + 1] - nums[i], maxGap);
    }
    return maxGap;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumGap(self, nums):
        if len(nums) < 2:
            return 0

        maxVal = max(nums)
        exp = 1
        radix = 10
        aux = [0] * len(nums)

        while maxVal // exp > 0:
            count = [0] * radix
            for num in nums:
                count[(num // exp) % 10] += 1
            for i in range(1, radix):
                count[i] += count[i - 1]
            i = len(nums) - 1
            while i >= 0:
                aux[count[(nums[i] // exp) % 10] - 1] = nums[i]
                count[(nums[i] // exp) % 10] -= 1
                i -= 1
            for i in range(len(nums)):
                nums[i] = aux[i]
            exp *= 10

        maxGap = 0
        for i in range(len(nums) - 1):
            maxGap = max(nums[i + 1] - nums[i], maxGap)
        return maxGap
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumGap(nums: number[]): number {
    if (!nums || nums.length < 2) {
        return 0;
    }

    let maxVal = Math.max(...nums);
    let exp = 1;
    let radix = 10;
    let aux = new Array(nums.length);

    while (Math.floor(maxVal / exp) > 0) {
        let count = new Array(radix).fill(0);

        for (let num of nums) {
            count[Math.floor(num / exp) % 10]++;
        }

        for (let i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        for (let i = nums.length - 1; i >= 0; i--) {
            aux[--count[Math.floor(nums[i] / exp) % 10]] = nums[i];
        }

        for (let i = 0; i < nums.length; i++) nums[i] = aux[i];

        exp *= 10;
    }
    let maxGap = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        maxGap = Math.max(nums[i + 1] - nums[i], maxGap);
    }
    return maxGap;
}
```

</details>

<br>

## Approach 3: Buckets and The Pigeonhole Principle

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MIN(i, j) ((i) < (j) ? (i) : (j))
#define MAX(i, j) ((i) > (j) ? (i) : (j))

typedef struct {
    int used;
    int minval;
    int maxval;
} Bucket;

int maximumGap(int* nums, int numsSize) {
    if (!nums || numsSize < 2) return 0;

    int mini = nums[0], maxi = nums[0];
    for (int i = 0; i < numsSize; i++) {
        mini = MIN(mini, nums[i]);
        maxi = MAX(maxi, nums[i]);
    }

    int bucketSize =
        MAX(1, (maxi - mini) / (numsSize - 1));      // bucket size or capacity
    int bucketNum = (maxi - mini) / bucketSize + 1;  // number of buckets
    Bucket* buckets = (Bucket*)malloc(sizeof(Bucket) * bucketNum);
    for (int i = 0; i < bucketNum; i++) {
        buckets[i].used = 0;
        buckets[i].minval = INT_MAX;
        buckets[i].maxval = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int bucketIdx =
            (nums[i] - mini) / bucketSize;  // locating correct bucket
        buckets[bucketIdx].used = 1;
        buckets[bucketIdx].minval = MIN(nums[i], buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = MAX(nums[i], buckets[bucketIdx].maxval);
    }

    int prevBucketMax = mini, maxGap = 0;
    for (int i = 0; i < bucketNum; i++) {
        if (!buckets[i].used) continue;

        maxGap = MAX(maxGap, buckets[i].minval - prevBucketMax);
        prevBucketMax = buckets[i].maxval;
    }

    free(buckets);
    return maxGap;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max();  // same as INT_MAX
    int maxval = numeric_limits<int>::min();  // same as INT_MIN
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2) return 0;

        int mini = *min_element(nums.begin(), nums.end()),
            maxi = *max_element(nums.begin(), nums.end());

        int bucketSize =
            max(1, (maxi - mini) /
                       ((int)nums.size() - 1));  // bucket size or capacity
        int bucketNum = (maxi - mini) / bucketSize + 1;  // number of buckets
        vector<Bucket> buckets(bucketNum);

        for (auto&& num : nums) {
            int bucketIdx =
                (num - mini) / bucketSize;  // locating correct bucket
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
        }

        int prevBucketMax = mini, maxGap = 0;
        for (auto&& bucket : buckets) {
            if (!bucket.used) continue;

            maxGap = max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }

        return maxGap;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public class Bucket {
        public bool used = false;
        public int minval = int.MaxValue;
        public int maxval = int.MinValue;
    }

    public int MaximumGap(int[] nums) {
        if (nums == null || nums.Length < 2)
            return 0;

        int mini = nums.Min(),
            maxi = nums.Max();

        int bucketSize =
            Math.Max(1,
                (maxi - mini) / (nums.Length - 1)); // bucket size or capacity
        int bucketNum = (maxi - mini) / bucketSize + 1; // number of buckets
        Bucket[] buckets = new Bucket[bucketNum];

        foreach (int num in nums) {
            int bucketIdx =
                (num - mini) / bucketSize; // locating correct bucket
            if (buckets[bucketIdx] == null)
                buckets[bucketIdx] = new Bucket();

            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval =
                Math.Min(num, buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval =
                Math.Max(num, buckets[bucketIdx].maxval);
        }

        int prevBucketMax = mini, maxGap = 0;
        foreach (Bucket bucket in buckets) {
            if (bucket == null || !bucket.used)
                continue;

            maxGap = Math.Max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }

        return maxGap;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Bucket struct {
    used           bool
    minval, maxval int
}

func minimum(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func maximum(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func maximumGap(nums []int) int {
    if nums == nil || len(nums) < 2 {
        return 0
    }

    mini, maxi := nums[0], nums[0]
    for _, num := range nums {
        mini = minimum(mini, num)
        maxi = maximum(maxi, num)
    }

    bucketSize := maximum(
        1,
        (maxi-mini)/(len(nums)-1),
    ) // bucket size or capacity
    bucketNum := (maxi-mini)/bucketSize + 1 // number of buckets
    buckets := make([]Bucket, bucketNum)

    for _, num := range nums {
        bucketIdx := (num - mini) / bucketSize // locating correct bucket
        if !buckets[bucketIdx].used {
            buckets[bucketIdx].used = true
            buckets[bucketIdx].minval = num
            buckets[bucketIdx].maxval = num
        } else {
            buckets[bucketIdx].minval = minimum(num, buckets[bucketIdx].minval)
            buckets[bucketIdx].maxval = maximum(num, buckets[bucketIdx].maxval)
        }
    }

    prevBucketMax, maxGap := mini, 0
    for _, bucket := range buckets {
        if !bucket.used {
            continue
        }

        maxGap = maximum(maxGap, bucket.minval-prevBucketMax)
        prevBucketMax = bucket.maxval
    }

    return maxGap
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    static class Bucket {
        public boolean used = false;
        public int minval = Integer.MAX_VALUE;
        public int maxval = Integer.MIN_VALUE;
    }

    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) return 0;

        int mini = Arrays.stream(nums).min().getAsInt(), maxi = Arrays.stream(
            nums
        )
            .max()
            .getAsInt();

        int bucketSize = Math.max(1, (maxi - mini) / (nums.length - 1)); // bucket size or capacity
        int bucketNum = (maxi - mini) / bucketSize + 1; // number of buckets
        Bucket[] buckets = new Bucket[bucketNum];

        for (int num : nums) {
            int bucketIdx = (num - mini) / bucketSize; // locating correct bucket
            if (buckets[bucketIdx] == null) buckets[bucketIdx] = new Bucket();

            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = Math.min(
                num,
                buckets[bucketIdx].minval
            );
            buckets[bucketIdx].maxval = Math.max(
                num,
                buckets[bucketIdx].maxval
            );
        }

        int prevBucketMax = mini, maxGap = 0;
        for (Bucket bucket : buckets) {
            if (bucket == null || !bucket.used) continue;

            maxGap = Math.max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }

        return maxGap;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class Bucket {
    constructor() {
        this.used = false;
        this.minval = Number.MAX_SAFE_INTEGER;
        this.maxval = Number.MIN_SAFE_INTEGER;
    }
}

var maximumGap = function (nums) {
    if (!nums || nums.length < 2) return 0;

    let mini = Math.min(...nums),
        maxi = Math.max(...nums);

    let bucketSize = Math.max(1, Math.floor((maxi - mini) / (nums.length - 1))); // bucket size or capacity
    let bucketNum = Math.floor((maxi - mini) / bucketSize) + 1; // number of buckets
    let buckets = Array.from({ length: bucketNum }, () => new Bucket());

    for (let num of nums) {
        let bucketIdx = Math.floor((num - mini) / bucketSize); // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = Math.min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = Math.max(num, buckets[bucketIdx].maxval);
    }

    let prevBucketMax = mini,
        maxGap = 0;
    for (let bucket of buckets) {
        if (!bucket.used) continue;

        maxGap = Math.max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Bucket:
    def __init__(self):
        self.used = False
        self.minval = float("inf")
        self.maxval = float("-inf")


class Solution:
    def maximumGap(self, nums):
        if len(nums) < 2:
            return 0

        mini, maxi = min(nums), max(nums)

        bucketSize = max(1, (maxi - mini) // (len(nums) - 1))
        bucketNum = (maxi - mini) // bucketSize + 1
        buckets = [Bucket() for _ in range(bucketNum)]

        for num in nums:
            idx = (num - mini) // bucketSize
            buckets[idx].used = True
            buckets[idx].minval = min(num, buckets[idx].minval)
            buckets[idx].maxval = max(num, buckets[idx].maxval)

        prevBucketMax = mini
        maxGap = 0
        for bucket in buckets:
            if not bucket.used:
                continue

            maxGap = max(maxGap, bucket.minval - prevBucketMax)
            prevBucketMax = bucket.maxval

        return maxGap
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class Bucket {
    used: boolean = false;
    minval: number = Number.MAX_SAFE_INTEGER;
    maxval: number = Number.MIN_SAFE_INTEGER;
}

function maximumGap(nums: number[]): number {
    if (!nums || nums.length < 2) return 0;

    let mini: number = Math.min(...nums),
        maxi: number = Math.max(...nums);

    let bucketSize: number = Math.max(
        1,
        Math.floor((maxi - mini) / (nums.length - 1)),
    ); // bucket size or capacity
    let bucketNum: number = Math.floor((maxi - mini) / bucketSize) + 1; // number of buckets
    let buckets: Bucket[] = Array.from(
        { length: bucketNum },
        () => new Bucket(),
    );

    for (let num of nums) {
        let bucketIdx: number = Math.floor((num - mini) / bucketSize); // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = Math.min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = Math.max(num, buckets[bucketIdx].maxval);
    }

    let prevBucketMax: number = mini,
        maxGap: number = 0;
    for (let bucket of buckets) {
        if (!bucket.used) continue;

        maxGap = Math.max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
}
```

</details>
