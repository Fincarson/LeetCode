# 3074. Apple Redistribution into Boxes

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/apple-redistribution-into-boxes/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 3074 - Apple Redistribution into Boxes](https://leetcode.com/problems/apple-redistribution-into-boxes/)

## Problem

You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

### Example 1

```text
Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
```

### Example 2

```text
Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.
```

## Constraints

- 1 <= n == apple.length <= 50
- 1 <= m == capacity.length <= 50
- 1 <= apple[i], capacity[i] <= 50
- The input is generated such that it's possible to redistribute packs of apples into boxes.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3074. Apple Redistribution into Boxes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)b - *(int*)a); }

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int sum = 0;
    for (int i = 0; i < appleSize; i++) {
        sum += apple[i];
    }

    qsort(capacity, capacitySize, sizeof(int), compare);
    int need = 0;
    while (sum > 0) {
        sum -= capacity[need];
        need += 1;
    }

    return need;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());

        int need = 0;
        while (sum > 0) {
            sum -= capacity[need];
            need += 1;
        }

        return need;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumBoxes(int[] apple, int[] capacity) {
        int sum = apple.Sum();
        Array.Sort(capacity);
        Array.Reverse(capacity);

        int need = 0;
        while (sum > 0) {
            sum -= capacity[need];
            need += 1;
        }

        return need;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumBoxes(apple []int, capacity []int) int {
	sum := 0
	for _, a := range apple {
		sum += a
	}

	sort.Sort(sort.Reverse(sort.IntSlice(capacity)))
	need := 0
	for sum > 0 {
		sum -= capacity[need]
		need++
	}

	return need
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumBoxes(int[] apple, int[] capacity) {
        int sum = 0;
        for (int a : apple) {
            sum += a;
        }

        Integer[] capArray = new Integer[capacity.length];
        for (int i = 0; i < capacity.length; i++) {
            capArray[i] = capacity[i];
        }

        Arrays.sort(capArray, Collections.reverseOrder());

        int need = 0;
        while (sum > 0) {
            sum -= capArray[need];
            need += 1;
        }

        return need;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumBoxes = function (apple, capacity) {
    let sum = apple.reduce((a, b) => a + b, 0);

    capacity.sort((a, b) => b - a);

    let need = 0;
    while (sum > 0) {
        sum -= capacity[need];
        need += 1;
    }

    return need;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total_apples = sum(apple)
        capacity.sort(reverse=True)

        need = 0
        while total_apples > 0:
            total_apples -= capacity[need]
            need += 1

        return need
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumBoxes(apple: number[], capacity: number[]): number {
    let sum = apple.reduce((a, b) => a + b, 0);

    capacity.sort((a, b) => b - a);

    let need = 0;
    while (sum > 0) {
        sum -= capacity[need];
        need += 1;
    }

    return need;
}
```

</details>
