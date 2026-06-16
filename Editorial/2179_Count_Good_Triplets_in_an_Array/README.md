# 2179. Count Good Triplets in an Array

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/count-good-triplets-in-an-array/)  
`Array` `Binary Search` `Divide and Conquer` `Binary Indexed Tree` `Segment Tree` `Merge Sort` `Ordered Set`

**Problem Link:** [LeetCode 2179 - Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/)

## Problem

You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

### Example 1

```text
Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation:
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3).
Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
```

### Example 2

```text
Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
```

## Constraints

- n == nums1.length == nums2.length
- 3 <= n <= 105
- 0 <= nums1[i], nums2[i] <= n - 1
- nums1 and nums2 are permutations of [0, 1, ..., n - 1].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Create Sorted Array through Instructions](https://leetcode.com/problems/create-sorted-array-through-instructions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Increasing Quadruplets](https://leetcode.com/problems/count-increasing-quadruplets/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2179. Count Good Triplets in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Indexed Tree | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Indexed Tree

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* tree;
    int size;
} FenwickTree;

FenwickTree* fenwickTreeCreate(int size) {
    FenwickTree* obj = (FenwickTree*)malloc(sizeof(FenwickTree));
    obj->tree = (int*)calloc(size + 1, sizeof(int));
    obj->size = size;
    return obj;
}

void fenwickTreeUpdate(FenwickTree* obj, int index, int delta) {
    index++;
    while (index <= obj->size) {
        obj->tree[index] += delta;
        index += index & -index;
    }
}

int fenwickTreeQuery(FenwickTree* obj, int index) {
    index++;
    int res = 0;
    while (index > 0) {
        res += obj->tree[index];
        index -= index & -index;
    }
    return res;
}

void fenwickTreeFree(FenwickTree* obj) {
    free(obj->tree);
    free(obj);
}

long long goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    int *pos2 = (int*)malloc(n * sizeof(int)),
        *reversedIndexMapping = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pos2[nums2[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        reversedIndexMapping[pos2[nums1[i]]] = i;
    }
    FenwickTree* tree = fenwickTreeCreate(n);
    long long res = 0;
    for (int value = 0; value < n; value++) {
        int pos = reversedIndexMapping[value];
        int left = fenwickTreeQuery(tree, pos);
        fenwickTreeUpdate(tree, pos, 1);
        int right = (n - 1 - pos) - (value - left);
        res += (long long)left * right;
    }
    free(pos2);
    free(reversedIndexMapping);
    fenwickTreeFree(tree);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n), reversedIndexMapping(n);
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reversedIndexMapping[pos2[nums1[i]]] = i;
        }
        FenwickTree tree(n);
        long long res = 0;
        for (int value = 0; value < n; value++) {
            int pos = reversedIndexMapping[value];
            int left = tree.query(pos);
            tree.update(pos, 1);
            int right = (n - 1 - pos) - (value - left);
            res += (long long)left * right;
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class FenwickTree {
    private int[] tree;

    public FenwickTree(int size) {
        tree = new int[size + 1];
    }

    public void Update(int index, int delta) {
        index++;
        while (index < tree.Length) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    public int Query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
}

public class Solution {
    public long GoodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.Length;
        int[] pos2 = new int[n], reversedIndexMapping = new int[n];
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reversedIndexMapping[pos2[nums1[i]]] = i;
        }
        FenwickTree tree = new FenwickTree(n);
        long res = 0;
        for (int value = 0; value < n; value++) {
            int pos = reversedIndexMapping[value];
            int left = tree.Query(pos);
            tree.Update(pos, 1);
            int right = (n - 1 - pos) - (value - left);
            res += (long)left * right;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type FenwickTree struct {
	tree []int
}

func fenwickTree(size int) *FenwickTree {
	return &FenwickTree{tree: make([]int, size+1)}
}

func (ft *FenwickTree) update(index, delta int) {
	index++
	for index < len(ft.tree) {
		ft.tree[index] += delta
		index += index & -index
	}
}

func (ft *FenwickTree) query(index int) int {
	index++
	res := 0
	for index > 0 {
		res += ft.tree[index]
		index -= index & -index
	}
	return res
}

func goodTriplets(nums1 []int, nums2 []int) int64 {
	n := len(nums1)
	pos2, reversedIndexMapping := make([]int, n), make([]int, n)
	for i, num := range nums2 {
		pos2[num] = i
	}

	for i, num := range nums1 {
		reversedIndexMapping[pos2[num]] = i
	}
	tree := fenwickTree(n)
	var res int64
	for value := 0; value < n; value++ {
		pos := reversedIndexMapping[value]
		left := tree.query(pos)
		tree.update(pos, 1)
		right := (n - 1 - pos) - (value - left)
		res += int64(left * right)
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class FenwickTree {

    private int[] tree;

    public FenwickTree(int size) {
        tree = new int[size + 1];
    }

    public void update(int index, int delta) {
        index++;
        while (index < tree.length) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    public int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
}

class Solution {

    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] pos2 = new int[n], reversedIndexMapping = new int[n];
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reversedIndexMapping[pos2[nums1[i]]] = i;
        }
        FenwickTree tree = new FenwickTree(n);
        long res = 0;
        for (int value = 0; value < n; value++) {
            int pos = reversedIndexMapping[value];
            int left = tree.query(pos);
            tree.update(pos, 1);
            int right = (n - 1 - pos) - (value - left);
            res += (long) left * right;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class FenwickTree {
    constructor(size) {
        this.tree = new Array(size + 1).fill(0);
    }

    update(index, delta) {
        index++;
        while (index < this.tree.length) {
            this.tree[index] += delta;
            index += index & -index;
        }
    }

    query(index) {
        index++;
        let res = 0;
        while (index > 0) {
            res += this.tree[index];
            index -= index & -index;
        }
        return res;
    }
}

var goodTriplets = function (nums1, nums2) {
    const n = nums1.length;
    const pos2 = new Array(n),
        reversedIndexMapping = new Array(n);
    for (let i = 0; i < n; i++) {
        pos2[nums2[i]] = i;
    }
    for (let i = 0; i < n; i++) {
        reversedIndexMapping[pos2[nums1[i]]] = i;
    }
    const tree = new FenwickTree(n);
    let res = 0;
    for (let value = 0; value < n; value++) {
        const pos = reversedIndexMapping[value];
        const left = tree.query(pos);
        tree.update(pos, 1);
        const right = n - 1 - pos - (value - left);
        res += left * right;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class FenwickTree:
    def __init__(self, size):
        self.tree = [0] * (size + 1)

    def update(self, index, delta):
        index += 1
        while index <= len(self.tree) - 1:
            self.tree[index] += delta
            index += index & -index

    def query(self, index):
        index += 1
        res = 0
        while index > 0:
            res += self.tree[index]
            index -= index & -index
        return res


class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        pos2, reversedIndexMapping = [0] * n, [0] * n
        for i, num2 in enumerate(nums2):
            pos2[num2] = i
        for i, num1 in enumerate(nums1):
            reversedIndexMapping[pos2[num1]] = i
        tree = FenwickTree(n)
        res = 0
        for value in range(n):
            pos = reversedIndexMapping[value]
            left = tree.query(pos)
            tree.update(pos, 1)
            right = (n - 1 - pos) - (value - left)
            res += left * right
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class FenwickTree {
    private tree: number[];

    constructor(size: number) {
        this.tree = new Array(size + 1).fill(0);
    }

    update(index: number, delta: number): void {
        index++;
        while (index < this.tree.length) {
            this.tree[index] += delta;
            index += index & -index;
        }
    }

    query(index: number): number {
        index++;
        let res = 0;
        while (index > 0) {
            res += this.tree[index];
            index -= index & -index;
        }
        return res;
    }
}

function goodTriplets(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const pos2 = new Array(n),
        reversedIndexMapping = new Array(n);
    for (let i = 0; i < n; i++) {
        pos2[nums2[i]] = i;
    }
    for (let i = 0; i < n; i++) {
        reversedIndexMapping[pos2[nums1[i]]] = i;
    }
    const tree = new FenwickTree(n);
    let res = 0;
    for (let value = 0; value < n; value++) {
        const pos = reversedIndexMapping[value];
        const left = tree.query(pos);
        tree.update(pos, 1);
        const right = n - 1 - pos - (value - left);
        res += left * right;
    }
    return res;
}
```

</details>
