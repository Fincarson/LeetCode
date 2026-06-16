# 170. Two Sum III - Data structure design

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)  
`Array` `Hash Table` `Two Pointers` `Design` `Data Stream`

**Problem Link:** [LeetCode 170 - Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/)

## Problem

Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.

Implement the TwoSum class:

- TwoSum() Initializes the TwoSum object, with an empty array initially.
- void add(int number) Adds number to the data structure.
- boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.

### Example 1

```text
Input
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
Output
[null, null, null, null, true, false]

Explanation
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --> [1]
twoSum.add(3);   // [1] --> [1,3]
twoSum.add(5);   // [1,3] --> [1,3,5]
twoSum.find(4);  // 1 + 3 = 4, return true
twoSum.find(7);  // No two integers sum up to 7, return false
```

## Constraints

- -105 <= number <= 105
- -231 <= value <= 231 - 1
- At most 104 calls will be made to add and find.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Unique Word Abbreviation](https://leetcode.com/problems/unique-word-abbreviation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 170. Two Sum III - Data structure design

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorted List | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| HashTable | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sorted List

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} Count;

typedef struct {
    Count *counts;
} TwoSum;

TwoSum *twoSumCreate() {
    TwoSum *obj = (TwoSum *)malloc(sizeof(TwoSum));
    obj->counts = NULL;
    return obj;
}

void twoSumAdd(TwoSum *obj, int number) {
    Count *count;
    HASH_FIND_INT(obj->counts, &number, count);
    if (count == NULL) {
        count = (Count *)malloc(sizeof(Count));
        count->key = number;
        count->count = 1;
        HASH_ADD_INT(obj->counts, key, count);
    } else {
        count->count++;
    }
}

bool twoSumFind(TwoSum *obj, long value) {
    Count *count, *tmp;
    HASH_ITER(hh, obj->counts, count, tmp) {
        long complement = value - count->key;
        Count *complementCount;
        if (complement < INT_MIN || complement > INT_MAX) {
            continue;
        }
        HASH_FIND_INT(obj->counts, &complement, complementCount);
        if (complementCount) {
            if (complement != count->key || complementCount->count > 1) {
                return true;
            }
        }
    }
    return false;
}

void twoSumFree(TwoSum *obj) {
    Count *currentCount, *tmp;
    HASH_ITER(hh, obj->counts, currentCount, tmp) {
        HASH_DEL(obj->counts, currentCount);
        free(currentCount);
    }
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class TwoSum {
private:
    std::vector<int> nums;
    bool is_sorted;

public:
    TwoSum() : is_sorted(false) {}

    void add(int number) {
        nums.push_back(number);
        is_sorted = false;
    }

    bool find(int value) {
        if (!is_sorted) {
            std::sort(nums.begin(), nums.end());
            is_sorted = true;
        }

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = nums[low] + nums[high];

            if (sum < value) {
                low += 1;
            } else if (sum > value) {
                high -= 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class TwoSum {
    private List<int> nums;
    private bool is_sorted;

    /** Initialize your data structure here. */
    public TwoSum() {
        this.nums = new List<int>();
        this.is_sorted = false;
    }

    /** Add the number to an internal data structure.. */
    public void Add(int number) {
        this.nums.Add(number);
        this.is_sorted = false;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public bool Find(int value) {
        if (!this.is_sorted) {
            this.nums.Sort();
            this.is_sorted = true;
        }

        int low = 0, high = this.nums.Count - 1;
        while (low < high) {
            int twosum = this.nums[low] + this.nums[high];
            if (twosum < value)
                low += 1;
            else if (twosum > value)
                high -= 1;
            else
                return true;
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TwoSum struct {
    nums      []int
    is_sorted bool
}

func Constructor() TwoSum {
    return TwoSum{nums: []int{}, is_sorted: false}
}

func (this *TwoSum) Add(number int) {
    this.nums = append(this.nums, number)
    this.is_sorted = false
}

func (this *TwoSum) Find(value int) bool {
    if !this.is_sorted {
        sort.Ints(this.nums)
        this.is_sorted = true
    }
    low, high := 0, len(this.nums)-1
    for low < high {
        var twosum int = this.nums[low] + this.nums[high]
        if twosum < value {
            low += 1
        } else if twosum > value {
            high -= 1
        } else {
            return true
        }
    }
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.Collections;

class TwoSum {
    private ArrayList<Integer> nums;
    private boolean is_sorted;

    /** Initialize your data structure here. */
    public TwoSum() {
        this.nums = new ArrayList<Integer>();
        this.is_sorted = false;
    }

    /** Add the number to an internal data structure.. */
    public void add(int number) {
        this.nums.add(number);
        this.is_sorted = false;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        if (!this.is_sorted) {
            Collections.sort(this.nums);
            this.is_sorted = true;
        }
        int low = 0, high = this.nums.size() - 1;
        while (low < high) {
            int twosum = this.nums.get(low) + this.nums.get(high);
            if (twosum < value) low += 1;
            else if (twosum > value) high -= 1;
            else return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class TwoSum {
    constructor() {
        this.nums = [];
        this.is_sorted = false;
    }

    add(number) {
        this.nums.push(number);
        this.is_sorted = false;
    }

    find(value) {
        if (!this.is_sorted) {
            this.nums.sort((a, b) => a - b);
            this.is_sorted = true;
        }

        let low = 0,
            high = this.nums.length - 1;
        while (low < high) {
            let twosum = this.nums[low] + this.nums[high];
            if (twosum < value) low += 1;
            else if (twosum > value) high -= 1;
            else return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TwoSum(object):

    def __init__(self) -> None:
        """
        Initialize your data structure here.
        """
        self.nums = []
        self.is_sorted = False

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        # Inserting while maintaining the ascending order.
        # for index, num in enumerate(self.nums):
        #     if number <= num:
        #         self.nums.insert(index, number)
        #         return
        ## larger than any number
        # self.nums.append(number)

        self.nums.append(number)
        self.is_sorted = False

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        if not self.is_sorted:
            self.nums.sort()
            self.is_sorted = True

        low, high = 0, len(self.nums) - 1
        while low < high:
            currSum = self.nums[low] + self.nums[high]
            if currSum < value:
                low += 1
            elif currSum > value:
                high -= 1
            else:  # currSum == value
                return True

        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class TwoSum {
    private nums: number[];
    private is_sorted: boolean;

    constructor() {
        this.nums = [];
        this.is_sorted = false;
    }

    add(number: number) {
        this.nums.push(number);
        this.is_sorted = false;
    }

    find(value: number) {
        if (!this.is_sorted) {
            this.nums.sort((a, b) => a - b);
            this.is_sorted = true;
        }
        let low = 0,
            high = this.nums.length - 1;
        while (low < high) {
            let twosum = this.nums[low] + this.nums[high];
            if (twosum < value) low += 1;
            else if (twosum > value) high -= 1;
            else return true;
        }
        return false;
    }
}
```

</details>

<br>

## Approach 2: HashTable

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int number;
    int count;
    UT_hash_handle hh;
} NumberCount;

typedef struct {
    NumberCount* num_counts;
} TwoSum;

TwoSum* twoSumCreate() {
    TwoSum* obj = (TwoSum*)malloc(sizeof(TwoSum));
    obj->num_counts = NULL;
    return obj;
}

void twoSumAdd(TwoSum* obj, int number) {
    NumberCount* nc;
    HASH_FIND_INT(obj->num_counts, &number, nc);
    if (nc == NULL) {
        nc = (NumberCount*)malloc(sizeof(NumberCount));
        nc->number = number;
        nc->count = 0;
        HASH_ADD_INT(obj->num_counts, number, nc);
    }
    nc->count++;
}

bool twoSumFind(TwoSum* obj, int value) {
    for (NumberCount* e = obj->num_counts; e != NULL; e = e->hh.next) {
        long complement = (long)value - e->number;
        if (complement != (int)complement) continue;
        NumberCount* comp;
        HASH_FIND_INT(obj->num_counts, &complement, comp);
        if (comp != NULL) {
            if (comp->number == e->number && e->count > 1) {
                return true;
            } else if (comp->number != e->number)
                return true;
        }
    }
    return false;
}

void twoSumFree(TwoSum* obj) {
    NumberCount *cur_elt, *tmp;
    HASH_ITER(hh, obj->num_counts, cur_elt, tmp) {
        HASH_DEL(obj->num_counts, cur_elt);
        free(cur_elt);
    }
    free(obj);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class TwoSum {
private:
    unordered_map<long long, int> num_counts;

public:
    /** Initialize your data structure here. */
    TwoSum() {}

    /** Add the number to an internal data structure.. */
    void add(int number) {
        if (num_counts.find(number) != num_counts.end())
            num_counts[number]++;
        else
            num_counts[number] = 1;
    }

    /** Find if there exists any pair of numbers which sum is equal to the
     * value. */
    bool find(int value) {
        for (const auto &entry : num_counts) {
            long long complement = static_cast<long long>(value) - entry.first;
            if (complement != entry.first) {
                if (num_counts.find(complement) != num_counts.end())
                    return true;
            } else {
                if (entry.second > 1) return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class TwoSum {
    private Dictionary<int, int> num_counts;

    /** Initialize your data structure here. */
    public TwoSum() {
        this.num_counts = new Dictionary<int, int>();
    }

    /** Add the number to an internal data structure. */
    public void Add(int number) {
        if (this.num_counts.ContainsKey(number))
            this.num_counts[number] += 1;
        else
            this.num_counts.Add(number, 1);
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public bool Find(int value) {
        foreach (KeyValuePair<int, int> entry in this.num_counts) {
            int complement = value - entry.Key;
            if (complement != entry.Key) {
                if (this.num_counts.ContainsKey(complement))
                    return true;
            } else {
                if (entry.Value > 1)
                    return true;
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TwoSum struct {
    num_counts map[int]int
}

/** Initialize your data structure here. */
func Constructor() TwoSum {
    return TwoSum{num_counts: make(map[int]int)}
}

/** Add the number to an internal data structure..
**/
func (this *TwoSum) Add(number int) {
    if _, ok := this.num_counts[number]; ok {
        this.num_counts[number]++
    } else {
        this.num_counts[number] = 1
    }
}

/** Find if there exists any pair of numbers which sum is equal to the value. */
func (this *TwoSum) Find(value int) bool {
    for num := range this.num_counts {
        complement := value - num
        if complement != num {
            if _, ok := this.num_counts[complement]; ok {
                return true
            }
        } else {
            if this.num_counts[num] > 1 {
                return true
            }
        }
    }
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.HashMap;

class TwoSum {
    private HashMap<Integer, Integer> num_counts;

    /** Initialize your data structure here. */
    public TwoSum() {
        this.num_counts = new HashMap<Integer, Integer>();
    }

    /** Add the number to an internal data structure.. */
    public void add(int number) {
        if (this.num_counts.containsKey(number)) this.num_counts.replace(
                number,
                this.num_counts.get(number) + 1
            );
        else this.num_counts.put(number, 1);
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for (Map.Entry<Integer, Integer> entry : this.num_counts.entrySet()) {
            int complement = value - entry.getKey();
            if (complement != entry.getKey()) {
                if (this.num_counts.containsKey(complement)) return true;
            } else {
                if (entry.getValue() > 1) return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const TwoSum = function () {
    this.num_counts = {};
};

/**
 * Add the number to an internal data structure.
 * @param {number} number
 * @return {void}
 */
TwoSum.prototype.add = function (number) {
    if (number in this.num_counts) this.num_counts[number]++;
    else this.num_counts[number] = 1;
};

/**
 * Find if there exists any pair of numbers which sum is equal to the value.
 * @param {number} value
 * @return {boolean}
 */
TwoSum.prototype.find = function (value) {
    for (let num in this.num_counts) {
        let complement = value - num;
        if (complement != num) {
            if (complement in this.num_counts) return true;
        } else {
            if (this.num_counts[num] > 1) return true;
        }
    }
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TwoSum(object):

    def __init__(self) -> None:
        """
        Initialize your data structure here.
        """
        self.num_counts = {}

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        if number in self.num_counts:
            self.num_counts[number] += 1
        else:
            self.num_counts[number] = 1

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        for num in self.num_counts.keys():
            comple = value - num
            if num != comple:
                if comple in self.num_counts:
                    return True
            elif self.num_counts[num] > 1:
                return True

        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class TwoSum {
    num_counts: { [key: number]: number };

    constructor() {
        this.num_counts = {};
    }

    add(number: number): void {
        if (number in this.num_counts) this.num_counts[number]++;
        else this.num_counts[number] = 1;
    }

    find(value: number): boolean {
        for (let num in this.num_counts) {
            const complement = value - Number(num);
            if (complement != Number(num)) {
                if (complement in this.num_counts) return true;
            } else {
                if (this.num_counts[Number(num)] > 1) return true;
            }
        }
        return false;
    }
}
```

</details>
