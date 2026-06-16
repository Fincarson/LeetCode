# 90. Subsets II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/subsets-ii/)  
`Array` `Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 90 - Subsets II](https://leetcode.com/problems/subsets-ii/)

## Problem

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

### Example 1

```text
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

### Example 2

```text
Input: nums = [0]
Output: [[],[0]]
```

## Constraints

- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subsets](https://leetcode.com/problems/subsets/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Array Given Subset Sums](https://leetcode.com/problems/find-array-given-subset-sums/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 90. Subsets II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Bitmasking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Cascading (Iterative) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Bitmasking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Structure for hash table to store previously seen sets
struct seen_set {
    char *hashcode;
    UT_hash_handle hh;
};
// The qsort comparator function
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
void generate_hashcode(char *hashcode, int *currentSubset,
                       int currentSubsetSize) {
    for (int i = 0; i < currentSubsetSize; i++) {
        char buffer[50];
        sprintf(buffer, "%d,", currentSubset[i]);
        strcat(hashcode, buffer);
    }
}
int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes) {
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);
    struct seen_set *seen = NULL;
    int **subsets = (int **)malloc(sizeof(int *) * pow(2, numsSize));
    int maxNumberOfSubsets = pow(2, numsSize);
    *returnSize = 0;
    int *currentSubsetSizes = (int *)malloc(sizeof(int) * pow(2, numsSize));
    for (int subsetIndex = 0; subsetIndex < maxNumberOfSubsets; subsetIndex++) {
        int *currentSubset = (int *)calloc(numsSize, sizeof(int));
        int currentSubsetSize = 0;
        char *hashcode = (char *)calloc(numsSize * 50, sizeof(char));
        for (int j = 0; j < numsSize; j++) {
            int isSet = (1 << j) & subsetIndex;
            if (isSet != 0) {
                currentSubset[currentSubsetSize++] = nums[j];
            }
        }
        generate_hashcode(hashcode, currentSubset, currentSubsetSize);
        // Search if the hashcode exists in the hash table
        struct seen_set *s;
        HASH_FIND_STR(seen, hashcode, s);
        if (s == NULL) {
            // If not found, add this subset in the result and also in the hash
            // map
            subsets[*returnSize] = currentSubset;
            currentSubsetSizes[*returnSize] = currentSubsetSize;
            struct seen_set *newSet =
                (struct seen_set *)malloc(sizeof(struct seen_set));
            newSet->hashcode = hashcode;
            HASH_ADD_KEYPTR(hh, seen, newSet->hashcode,
                            strlen(newSet->hashcode), newSet);
            (*returnSize)++;
        } else {
            // If the subset is found in hash map, we've seen this set before,
            // free the memory
            free(currentSubset);
            free(hashcode);
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = currentSubsetSizes[i];
    }
    free(currentSubsetSizes);
    return subsets;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        // Sort the generated subset. This will help to identify duplicates.
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;

        int maxNumberOfSubsets = pow(2, n);
        // To store the previously seen sets.
        unordered_set<string> seen;

        for (int subsetIndex = 0; subsetIndex < maxNumberOfSubsets;
             subsetIndex++) {
            // Append subset corresponding to that bitmask.
            vector<int> currentSubset;
            string hashcode = "";
            for (int j = 0; j < n; j++) {
                // Generate the bitmask
                int mask = 1 << j;
                int isSet = mask & subsetIndex;
                if (isSet != 0) {
                    currentSubset.push_back(nums[j]);
                    // Generate the hashcode by creating a comma separated
                    // string of numbers in the currentSubset.
                    hashcode.append(to_string(nums[j]) + ",");
                }
            }

            if (seen.find(hashcode) == seen.end()) {
                subsets.push_back(currentSubset);
                seen.insert(hashcode);
            }
        }

        return subsets;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        IList<IList<int>> subsets = new List<IList<int>>();
        int n = nums.Length;
        // Sort the generated subset. This will help to identify duplicates.
        Array.Sort(nums);
        int maxNumberOfSubsets = (int)Math.Pow(2, n);
        // To store the previously seen sets.
        HashSet<string> seen = new HashSet<string>();
        for (int subsetIndex = 0; subsetIndex < maxNumberOfSubsets;
             subsetIndex++) {
            // Append subset corresponding to that bitmask.
            List<int> currentSubset = new List<int>();
            StringBuilder hashcode = new StringBuilder();
            for (int j = 0; j < n; j++) {
                // Generate the bitmask
                int mask = 1 << j;
                int isSet = mask & subsetIndex;
                if (isSet != 0) {
                    currentSubset.Add(nums[j]);
                    // Generate the hashcode by creating a comma separated
                    // string of numbers in the currentSubset.
                    hashcode.Append(nums[j]).Append(",");
                }
            }

            if (!seen.Contains(hashcode.ToString())) {
                seen.Add(hashcode.ToString());
                subsets.Add(currentSubset);
            }
        }

        return subsets;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func subsetsWithDup(nums []int) [][]int {
    n := len(nums)
    // Sort the generated subset. This will help to identify duplicates.
    sort.Ints(nums)
    subsets := make([][]int, 0)
    maxNumberOfSubsets := 1 << n
    // To store the previously seen sets.
    seen := make(map[string]bool)
    for subsetIndex := 0; subsetIndex < maxNumberOfSubsets; subsetIndex++ {
        // Append subset corresponding to that bitmask.
        currentSubset := make([]int, 0)
        hashcode := ""
        for j := 0; j < n; j++ {
            // Generate the bitmask
            mask := 1 << j
            isSet := mask & subsetIndex
            if isSet != 0 {
                currentSubset = append(currentSubset, nums[j])
                // Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                hashcode += strconv.Itoa(nums[j]) + ","
            }
        }
        if _, ok := seen[hashcode]; !ok {
            subsets = append(subsets, currentSubset)
            seen[hashcode] = true
        }
    }
    return subsets
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> subsets = new ArrayList();
        int n = nums.length;

        // Sort the generated subset. This will help to identify duplicates.
        Arrays.sort(nums);

        int maxNumberOfSubsets = (int) Math.pow(2, n);
        // To store the previously seen sets.
        Set<String> seen = new HashSet<>();

        for (
            int subsetIndex = 0;
            subsetIndex < maxNumberOfSubsets;
            subsetIndex++
        ) {
            // Append subset corresponding to that bitmask.
            List<Integer> currentSubset = new ArrayList();
            StringBuilder hashcode = new StringBuilder();
            for (int j = 0; j < n; j++) {
                // Generate the bitmask
                int mask = 1 << j;
                int isSet = mask & subsetIndex;
                if (isSet != 0) {
                    currentSubset.add(nums[j]);
                    // Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                    hashcode.append(nums[j]).append(",");
                }
            }
            if (!seen.contains(hashcode.toString())) {
                seen.add(hashcode.toString());
                subsets.add(currentSubset);
            }
        }

        return subsets;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var subsetsWithDup = function (nums) {
    var n = nums.length;
    // Sort the generated subset. This will help to identify duplicates.
    nums.sort();
    var subsets = [];
    var seen = new Set(); // To store the previously seen sets.
    var maxNumberOfSubsets = Math.pow(2, n);
    for (var subsetIndex = 0; subsetIndex < maxNumberOfSubsets; subsetIndex++) {
        // Append subset corresponding to that bitmask.
        var currentSubset = [];
        var hashcode = "";
        for (var j = 0; j < n; j++) {
            // Generate the bitmask
            var mask = 1 << j;
            var isSet = mask & subsetIndex;
            if (isSet != 0) {
                currentSubset.push(nums[j]);
                // Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                hashcode += nums[j] + ",";
            }
        }
        if (!seen.has(hashcode)) {
            subsets.push(currentSubset);
            seen.add(hashcode);
        }
    }
    return subsets;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsetsWithDup(self, nums):
        n = len(nums)
        # Sort the generated subset. This will help to identify duplicates.
        nums.sort()
        maxNumberOfSubsets = 2**n
        # To store the previously seen sets.
        seen = set()
        subsets = []
        for subsetIndex in range(maxNumberOfSubsets):
            # Append subset corresponding to that bitmask.
            currentSubset = []
            hashcode = ""
            for j in range(n):
                # Generate the bitmask
                mask = 2**j
                isSet = mask & subsetIndex
                if isSet != 0:
                    currentSubset.append(nums[j])
                    # Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                    hashcode += str(nums[j]) + ","
            if hashcode not in seen:
                subsets.append(currentSubset)
                seen.add(hashcode)
        return subsets
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var subsetsWithDup = function (nums: number[]): number[][] {
    var n: number = nums.length;
    nums.sort((a: number, b: number): number => a - b);
    var subsets: number[][] = [];
    var seen: Set<string> = new Set();
    var maxNumberOfSubsets: number = Math.pow(2, n);
    for (var subsetIndex = 0; subsetIndex < maxNumberOfSubsets; subsetIndex++) {
        var currentSubset: number[] = [];
        var hashcode: string = "";
        for (var j = 0; j < n; j++) {
            var mask: number = 1 << j;
            var isSet: number = mask & subsetIndex;
            if (isSet != 0) {
                currentSubset.push(nums[j]);
                hashcode += nums[j] + ",";
            }
        }
        if (!seen.has(hashcode)) {
            subsets.push(currentSubset);
            seen.add(hashcode);
        }
    }
    return subsets;
};
```

</details>

<br>

## Approach 2: Cascading (Iterative)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = 5000;
    int **subsets = malloc(capacity * sizeof(int *));
    int *firstSubset = malloc(0);
    subsets[0] = firstSubset;
    *returnColumnSizes = malloc(capacity * sizeof(int));
    (*returnColumnSizes)[0] = 0;
    *returnSize = 1;
    int subsetSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int startingIndex = (i >= 1 && nums[i] == nums[i - 1]) ? subsetSize : 0;
        // subsetSize refers to the size of the subset in the previous step.
        // This value also indicates the starting index of the subsets generated
        // in this step.
        subsetSize = *returnSize;
        for (int j = startingIndex; j < subsetSize; j++) {
            int *currentSubset =
                malloc(((*returnColumnSizes)[j] + 1) * sizeof(int));
            memcpy(currentSubset, subsets[j],
                   (*returnColumnSizes)[j] * sizeof(int));
            currentSubset[(*returnColumnSizes)[j]] = nums[i];
            if (*returnSize >= capacity) {
                capacity *= 2;
                subsets = realloc(subsets, capacity * sizeof(int *));
                *returnColumnSizes =
                    realloc(*returnColumnSizes, capacity * sizeof(int));
            }
            subsets[*returnSize] = currentSubset;
            (*returnColumnSizes)[*returnSize] = (*returnColumnSizes)[j] + 1;
            (*returnSize)++;
        }
    }
    return subsets;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets = {{}};

        int subsetSize = 0;

        for (int i = 0; i < nums.size(); i++) {
            int startingIndex =
                (i >= 1 && nums[i] == nums[i - 1]) ? subsetSize : 0;
            // subsetSize refers to the size of the subset in the previous step.
            // This value also indicates the starting index of the subsets
            // generated in this step.
            subsetSize = subsets.size();
            for (int j = startingIndex; j < subsetSize; j++) {
                vector<int> currentSubset = subsets[j];
                currentSubset.push_back(nums[i]);
                subsets.push_back(currentSubset);
            }
        }
        return subsets;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        Array.Sort(nums);
        List<IList<int>> subsets = new List<IList<int>>();
        subsets.Add(new List<int>());
        int subsetSize = 0;
        for (int i = 0; i < nums.Length; i++) {
            // subsetSize refers to the size of the subset in the previous step.
            // This value also indicates the starting index of the subsets
            // generated in this step.
            int startingIndex =
                (i >= 1 && nums[i] == nums[i - 1]) ? subsetSize : 0;
            subsetSize = subsets.Count;
            for (int j = startingIndex; j < subsetSize; j++) {
                List<int> currentSubset = new List<int>(subsets[j]);
                currentSubset.Add(nums[i]);
                subsets.Add(currentSubset);
            }
        }

        return subsets;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func subsetsWithDup(nums []int) [][]int {
    sort.Ints(nums)
    subsets := make([][]int, 1)
    subsetSize := 0
    for i := range nums {
        startingIndex := 0
        if i >= 1 && nums[i] == nums[i-1] {
            startingIndex = subsetSize
        }
        // subsetSize refers to the size of the subset in the previous step.
        // This value also indicates the starting index of the subsets generated in this step.
        subsetSize = len(subsets)
        for j := startingIndex; j < subsetSize; j++ {
            currentSubset := make([]int, len(subsets[j]))
            copy(currentSubset, subsets[j])
            currentSubset = append(currentSubset, nums[i])
            subsets = append(subsets, currentSubset)
        }
    }
    return subsets
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> subsets = new ArrayList<>();
        subsets.add(new ArrayList<Integer>());

        int subsetSize = 0;

        for (int i = 0; i < nums.length; i++) {
            int startingIndex = (i >= 1 && nums[i] == nums[i - 1])
                ? subsetSize
                : 0;
            // subsetSize refers to the size of the subset in the previous step. This value also indicates the starting index of the subsets generated in this step.
            subsetSize = subsets.size();
            for (int j = startingIndex; j < subsetSize; j++) {
                List<Integer> currentSubset = new ArrayList<>(subsets.get(j));
                currentSubset.add(nums[i]);
                subsets.add(currentSubset);
            }
        }
        return subsets;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var subsetsWithDup = function (nums) {
    nums.sort((a, b) => a - b);
    let subsets = [[]];
    let subsetSize = 0;
    for (let i = 0; i < nums.length; i++) {
        // subsetSize refers to the size of the subset in the previous step.
        // This value also indicates the starting index of the subsets generated in this step.
        let startingIndex = i >= 1 && nums[i] == nums[i - 1] ? subsetSize : 0;
        subsetSize = subsets.length;
        for (let j = startingIndex; j < subsetSize; j++) {
            let currentSubset = [...subsets[j]];
            currentSubset.push(nums[i]);
            subsets.push(currentSubset);
        }
    }
    return subsets;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        subsets = [[]]
        subsetSize = 0
        for i in range(len(nums)):
            # subsetSize refers to the size of the subset in the previous step.
            # This value also indicates the starting index of the subsets generated in this step.
            startingIndex = (
                subsetSize if i >= 1 and nums[i] == nums[i - 1] else 0
            )
            subsetSize = len(subsets)
            for j in range(startingIndex, subsetSize):
                currentSubset = list(subsets[j])
                currentSubset.append(nums[i])
                subsets.append(currentSubset)
        return subsets
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function subsetsWithDup(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    let subsets: number[][] = [[]];
    let subsetSize = 0;
    for (let i = 0; i < nums.length; i++) {
        // subsetSize refers to the size of the subset in the previous step.
        // This value also indicates the starting index of the subsets generated in this step.
        let startingIndex = i >= 1 && nums[i] == nums[i - 1] ? subsetSize : 0;
        subsetSize = subsets.length;
        for (let j = startingIndex; j < subsetSize; j++) {
            let currentSubset = [...subsets[j]];
            currentSubset.push(nums[i]);
            subsets.push(currentSubset);
        }
    }
    return subsets;
}
```

</details>

<br>

## Approach 3: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* nums;
    int count;
} Vector;
void vector_init(Vector* vector) {
    vector->nums = NULL;
    vector->count = 0;
}
void vector_append(Vector* vector, int num) {
    vector->nums = realloc(vector->nums, sizeof(int) * (vector->count + 1));
    vector->nums[vector->count] = num;
    vector->count++;
}
void vector_remove_last(Vector* vector) {
    vector->count--;
    vector->nums = realloc(vector->nums, sizeof(int) * vector->count);
}
typedef struct {
    Vector* vectors;
    int count;
} Vectors;
void vectors_init(Vectors* vectors) {
    vectors->vectors = NULL;
    vectors->count = 0;
}
void vectors_append(Vectors* vectors, Vector* vector) {
    vectors->vectors =
        realloc(vectors->vectors, sizeof(Vector) * (vectors->count + 1));
    vectors->vectors[vectors->count] = *vector;
    vectors->vectors[vectors->count].nums =
        (vector->count > 0) ? malloc(vector->count * sizeof(int)) : NULL;
    if (vector->count > 0) {
        memcpy(vectors->vectors[vectors->count].nums, vector->nums,
               vector->count * sizeof(int));
    }
    vectors->count++;
}
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void subsetsWithDupHelper(Vectors* subsets, Vector* currentSubset, int* nums,
                          int numsSize, int index) {
    vectors_append(subsets, currentSubset);
    for (int i = index; i < numsSize; i++) {
        if (i != index && nums[i] == nums[i - 1]) {
            continue;
        }
        vector_append(currentSubset, nums[i]);
        subsetsWithDupHelper(subsets, currentSubset, nums, numsSize, i + 1);
        vector_remove_last(currentSubset);
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize,
                     int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    Vectors subsets;
    vectors_init(&subsets);
    Vector currentSubset;
    vector_init(&currentSubset);
    subsetsWithDupHelper(&subsets, &currentSubset, nums, numsSize, 0);
    free(currentSubset.nums);
    *returnSize = subsets.count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * subsets.count);
    int** result = (int**)malloc(sizeof(int*) * subsets.count);
    for (int i = 0; i < subsets.count; i++) {
        (*returnColumnSizes)[i] = subsets.vectors[i].count;
        result[i] = (subsets.vectors[i].count > 0)
                        ? (int*)malloc(sizeof(int) * subsets.vectors[i].count)
                        : NULL;
        for (int j = 0; j < subsets.vectors[i].count; j++) {
            result[i][j] = subsets.vectors[i].nums[j];
        }
        free(subsets.vectors[i].nums);
    }
    free(subsets.vectors);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(subsets, currentSubset, nums, 0);
        return subsets;
    }

private:
    void subsetsWithDupHelper(vector<vector<int>>& subsets,
                              vector<int>& currentSubset, vector<int>& nums,
                              int index) {
        // Add the subset formed so far to the subsets list.
        subsets.push_back(currentSubset);

        for (int i = index; i < nums.size(); i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push_back(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.pop_back();
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        Array.Sort(nums);
        IList<IList<int>> subsets = new List<IList<int>>();
        IList<int> currentSubset = new List<int>();
        SubsetsWithDupHelper(subsets, currentSubset, nums, 0);
        return subsets;
    }

    private void SubsetsWithDupHelper(IList<IList<int>> subsets,
                                      IList<int> currentSubset, int[] nums,
                                      int index) {
        // Add the subset formed so far to the subsets list.
        subsets.Add(new List<int>(currentSubset));
        for (int i = index; i < nums.Length; i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }

            currentSubset.Add(nums[i]);
            SubsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.RemoveAt(currentSubset.Count - 1);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func subsetsWithDup(nums []int) [][]int {
    sort.Ints(nums)
    subsets := [][]int{}
    currentSubset := []int{}
    subsetsWithDupHelper(&subsets, currentSubset, nums, 0)
    return subsets
}

func subsetsWithDupHelper(
    subsets *[][]int,
    currentSubset []int,
    nums []int,
    index int,
) {
    copyCurrentSubset := make([]int, len(currentSubset))
    copy(copyCurrentSubset, currentSubset)
    *subsets = append(*subsets, copyCurrentSubset)
    for i := index; i < len(nums); i++ {
        if i != index && nums[i] == nums[i-1] {
            continue
        }
        currentSubset = append(currentSubset, nums[i])
        subsetsWithDupHelper(subsets, currentSubset, nums, i+1)
        currentSubset = currentSubset[:len(currentSubset)-1]
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> currentSubset = new ArrayList<>();

        subsetsWithDupHelper(subsets, currentSubset, nums, 0);
        return subsets;
    }

    private void subsetsWithDupHelper(
        List<List<Integer>> subsets,
        List<Integer> currentSubset,
        int[] nums,
        int index
    ) {
        // Add the subset formed so far to the subsets list.
        subsets.add(new ArrayList<>(currentSubset));

        for (int i = index; i < nums.length; i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.add(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.remove(currentSubset.size() - 1);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var subsetsWithDup = function (nums) {
    nums.sort((a, b) => a - b);
    const subsets = [];
    const currentSubset = [];
    (function subsetsWithDupHelper(subsets, currentSubset, nums, index) {
        // Add the subset formed so far to the subsets list.
        subsets.push([...currentSubset]);
        for (let i = index; i < nums.length; i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.pop();
        }
    })(subsets, currentSubset, nums, 0);
    return subsets;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        subsets = []
        currentSubset = []
        self.subsetsWithDupHelper(subsets, currentSubset, nums, 0)
        return subsets

    def subsetsWithDupHelper(self, subsets, currentSubset, nums, index):
        # Add the subset formed so far to the subsets list.
        subsets.append(list(currentSubset))
        for i in range(index, len(nums)):
            # If the current element is a duplicate, ignore.
            if i != index and nums[i] == nums[i - 1]:
                continue
            currentSubset.append(nums[i])
            self.subsetsWithDupHelper(subsets, currentSubset, nums, i + 1)
            currentSubset.pop()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function subsetsWithDup(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    const subsets: number[][] = [];
    const currentSubset: number[] = [];
    (function subsetsWithDupHelper(
        subsets: number[][],
        currentSubset: number[],
        nums: number[],
        index: number,
    ) {
        // Add the subset formed so far to the subsets list.
        subsets.push([...currentSubset]);
        for (let i = index; i < nums.length; i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.pop();
        }
    })(subsets, currentSubset, nums, 0);
    return subsets;
}
```

</details>
