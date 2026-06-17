# 3661. Maximum Walls Destroyed by Robots

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-walls-destroyed-by-robots/)  
`Array` `Binary Search` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 3661 - Maximum Walls Destroyed by Robots](https://leetcode.com/problems/maximum-walls-destroyed-by-robots/)

## Problem

- robots[i] is the position of the ith robot.
- distance[i] is the maximum distance the ith robot's bullet can travel.
- walls[j] is the position of the jth wall.

Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.

A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.

Return the maximum number of unique walls that can be destroyed by the robots.

Notes:

- A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
- Robots are not destroyed by bullets.

### Example 1

### Example 2

## Constraints

- 1 <= robots.length == distance.length <= 105
- 1 <= walls.length <= 105
- 1 <= robots[i], walls[j] <= 109
- 1 <= distance[i] <= 105
- All values in robots are unique
- All values in walls are unique

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3661. Maximum Walls Destroyed by Robots

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search + Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers + Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers + Dynamic Programming + Space Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Search + Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int max(int a, int b) { return (a > b) ? a : b; }

int min(int a, int b) { return (a < b) ? a : b; }

int lowerBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upperBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize,
             int* walls, int wallsSize) {
    int n = robotsSize;

    int* left = (int*)calloc(n, sizeof(int));
    int* right = (int*)calloc(n, sizeof(int));
    int* num = (int*)calloc(n, sizeof(int));
    HashItem* robotsToDistance = NULL;
    for (int i = 0; i < n; i++) {
        hashAddItem(&robotsToDistance, robots[i], distance[i]);
    }

    int* sortedRobots = (int*)malloc(n * sizeof(int));
    memcpy(sortedRobots, robots, n * sizeof(int));
    qsort(sortedRobots, n, sizeof(int), cmp);

    int* sortedWalls = (int*)malloc(wallsSize * sizeof(int));
    memcpy(sortedWalls, walls, wallsSize * sizeof(int));
    qsort(sortedWalls, wallsSize, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        int pos1 = upperBound(sortedWalls, wallsSize, sortedRobots[i]);
        int leftPos;
        if (i >= 1) {
            int leftBound =
                max(sortedRobots[i] -
                        hashGetItem(&robotsToDistance, sortedRobots[i], 0),
                    sortedRobots[i - 1] + 1);
            leftPos = lowerBound(sortedWalls, wallsSize, leftBound);
        } else {
            leftPos =
                lowerBound(sortedWalls, wallsSize,
                           sortedRobots[i] - hashGetItem(&robotsToDistance,
                                                         sortedRobots[i], 0));
        }
        left[i] = pos1 - leftPos;

        int rightPos;
        if (i < n - 1) {
            int rightBound =
                min(sortedRobots[i] +
                        hashGetItem(&robotsToDistance, sortedRobots[i], 0),
                    sortedRobots[i + 1] - 1);
            rightPos = upperBound(sortedWalls, wallsSize, rightBound);
        } else {
            rightPos =
                upperBound(sortedWalls, wallsSize,
                           sortedRobots[i] + hashGetItem(&robotsToDistance,
                                                         sortedRobots[i], 0));
        }

        int pos2 = lowerBound(sortedWalls, wallsSize, sortedRobots[i]);
        right[i] = rightPos - pos2;

        if (i == 0) {
            continue;
        }

        int pos3 = lowerBound(sortedWalls, wallsSize, sortedRobots[i - 1]);
        num[i] = pos1 - pos3;
    }

    int subLeft = left[0];
    int subRight = right[0];

    for (int i = 1; i < n; i++) {
        int currentLeft =
            max(subLeft + left[i],
                subRight - right[i - 1] + min(left[i] + right[i - 1], num[i]));
        int currentRight = max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    int result = max(subLeft, subRight);

    free(left);
    free(right);
    free(num);
    free(sortedRobots);
    free(sortedWalls);
    hashFree(&robotsToDistance);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        int pos1, pos2, pos3, leftPos, rightPos;
        vector<int> left(n, 0), right(n, 0), num(n, 0);
        unordered_map<int, int> robotsToDistance;
        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }
        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());
        for (int i = 0; i < n; i++) {
            pos1 = upper_bound(walls.begin(), walls.end(), robots[i]) -
                   walls.begin();
            if (i >= 1) {
                leftPos =
                    lower_bound(walls.begin(), walls.end(),
                                max(robots[i] - robotsToDistance[robots[i]],
                                    robots[i - 1] + 1)) -
                    walls.begin();
            } else {
                leftPos = lower_bound(walls.begin(), walls.end(),
                                      robots[i] - robotsToDistance[robots[i]]) -
                          walls.begin();
            }
            left[i] = pos1 - leftPos;
            if (i < n - 1) {
                rightPos =
                    upper_bound(walls.begin(), walls.end(),
                                min(robots[i] + robotsToDistance[robots[i]],
                                    robots[i + 1] - 1)) -
                    walls.begin();
            } else {
                rightPos =
                    upper_bound(walls.begin(), walls.end(),
                                robots[i] + robotsToDistance[robots[i]]) -
                    walls.begin();
            }
            pos2 = lower_bound(walls.begin(), walls.end(), robots[i]) -
                   walls.begin();
            right[i] = rightPos - pos2;
            if (i == 0) {
                continue;
            }
            pos3 = lower_bound(walls.begin(), walls.end(), robots[i - 1]) -
                   walls.begin();
            num[i] = pos1 - pos3;
        }
        int subLeft, subRight, currentLeft, currentRight;
        subLeft = left[0];
        subRight = right[0];
        for (int i = 1; i < n; i++) {
            currentLeft =
                max(subLeft + left[i], subRight - right[i - 1] +
                                           min(left[i] + right[i - 1], num[i]));
            currentRight = max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }
        return max(subLeft, subRight);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] num = new int[n];
        Dictionary<int, int> robotsToDistance = new Dictionary<int, int>();

        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }

        Array.Sort(robots);
        Array.Sort(walls);

        for (int i = 0; i < n; i++) {
            int pos1 = UpperBound(walls, robots[i]);

            int leftPos;
            if (i >= 1) {
                int leftBound = Math.Max(
                    robots[i] - robotsToDistance[robots[i]], robots[i - 1] + 1);
                leftPos = LowerBound(walls, leftBound);
            } else {
                leftPos =
                    LowerBound(walls, robots[i] - robotsToDistance[robots[i]]);
            }
            left[i] = pos1 - leftPos;

            int rightPos;
            if (i < n - 1) {
                int rightBound = Math.Min(
                    robots[i] + robotsToDistance[robots[i]], robots[i + 1] - 1);
                rightPos = UpperBound(walls, rightBound);
            } else {
                rightPos =
                    UpperBound(walls, robots[i] + robotsToDistance[robots[i]]);
            }
            int pos2 = LowerBound(walls, robots[i]);
            right[i] = rightPos - pos2;

            if (i == 0)
                continue;

            int pos3 = LowerBound(walls, robots[i - 1]);
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0], subRight = right[0];
        for (int i = 1; i < n; i++) {
            int currentLeft =
                Math.Max(subLeft + left[i],
                         subRight - right[i - 1] +
                             Math.Min(left[i] + right[i - 1], num[i]));
            int currentRight =
                Math.Max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }

        return Math.Max(subLeft, subRight);
    }

    private int LowerBound(int[] arr, int target) {
        int left = 0, right = arr.Length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    private int UpperBound(int[] arr, int target) {
        int left = 0, right = arr.Length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxWalls(robots []int, distance []int, walls []int) int {
    n := len(robots)
    left := make([]int, n)
    right := make([]int, n)
    num := make([]int, n)
    robotsToDistance := make(map[int]int)

    for i := 0; i < n; i++ {
        robotsToDistance[robots[i]] = distance[i]
    }

    sort.Ints(robots)
    sort.Ints(walls)

    for i := 0; i < n; i++ {
        pos1 := sort.SearchInts(walls, robots[i]+1)

        var leftPos int
        if i >= 1 {
            leftBound := max(robots[i]-robotsToDistance[robots[i]], robots[i-1]+1)
            leftPos = sort.SearchInts(walls, leftBound)
        } else {
            leftPos = sort.SearchInts(walls, robots[i]-robotsToDistance[robots[i]])
        }
        left[i] = pos1 - leftPos

        var rightPos int
        if i < n-1 {
            rightBound := min(robots[i]+robotsToDistance[robots[i]], robots[i+1]-1)
            rightPos = sort.SearchInts(walls, rightBound+1)
        } else {
            rightPos = sort.SearchInts(walls, robots[i]+robotsToDistance[robots[i]]+1)
        }
        pos2 := sort.SearchInts(walls, robots[i])
        right[i] = rightPos - pos2

        if i == 0 {
            continue
        }
        pos3 := sort.SearchInts(walls, robots[i-1])
        num[i] = pos1 - pos3
    }

    subLeft, subRight := left[0], right[0]
    for i := 1; i < n; i++ {
        currentLeft := max(subLeft+left[i], subRight-right[i-1]+min(left[i]+right[i-1], num[i]))
        currentRight := max(subLeft+right[i], subRight+right[i])
        subLeft, subRight = currentLeft, currentRight
    }

    return max(subLeft, subRight)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] num = new int[n];
        Map<Integer, Integer> robotsToDistance = new HashMap<>();

        for (int i = 0; i < n; i++) {
            robotsToDistance.put(robots[i], distance[i]);
        }

        Arrays.sort(robots);
        Arrays.sort(walls);

        for (int i = 0; i < n; i++) {
            int pos1 = upperBound(walls, robots[i]);

            int leftPos = 0;
            if (i >= 1) {
                int leftBound = Math.max(
                    robots[i] - robotsToDistance.get(robots[i]),
                    robots[i - 1] + 1
                );
                leftPos = lowerBound(walls, leftBound);
            } else {
                leftPos = lowerBound(
                    walls,
                    robots[i] - robotsToDistance.get(robots[i])
                );
            }
            left[i] = pos1 - leftPos;

            int rightPos = 0;
            if (i < n - 1) {
                int rightBound = Math.min(
                    robots[i] + robotsToDistance.get(robots[i]),
                    robots[i + 1] - 1
                );
                rightPos = upperBound(walls, rightBound);
            } else {
                rightPos = upperBound(
                    walls,
                    robots[i] + robotsToDistance.get(robots[i])
                );
            }
            int pos2 = lowerBound(walls, robots[i]);
            right[i] = rightPos - pos2;

            if (i == 0) {
                continue;
            }
            int pos3 = lowerBound(walls, robots[i - 1]);
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0];
        int subRight = right[0];
        for (int i = 1; i < n; i++) {
            int currentLeft = Math.max(
                subLeft + left[i],
                subRight -
                right[i - 1] +
                Math.min(left[i] + right[i - 1], num[i])
            );
            int currentRight = Math.max(
                subLeft + right[i],
                subRight + right[i]
            );
            subLeft = currentLeft;
            subRight = currentRight;
        }

        return Math.max(subLeft, subRight);
    }

    private int lowerBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    private int upperBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function maxWalls(robots, distance, walls) {
    const n = robots.length;
    const left = new Array(n).fill(0);
    const right = new Array(n).fill(0);
    const num = new Array(n).fill(0);
    const robotsToDistance = new Map();

    for (let i = 0; i < n; i++) {
        robotsToDistance.set(robots[i], distance[i]);
    }

    robots.sort((a, b) => a - b);
    walls.sort((a, b) => a - b);

    const lowerBound = (arr, target) => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    const upperBound = (arr, target) => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    for (let i = 0; i < n; i++) {
        const pos1 = upperBound(walls, robots[i]);

        let leftPos;
        if (i >= 1) {
            const leftBound = Math.max(
                robots[i] - robotsToDistance.get(robots[i]),
                robots[i - 1] + 1,
            );
            leftPos = lowerBound(walls, leftBound);
        } else {
            leftPos = lowerBound(
                walls,
                robots[i] - robotsToDistance.get(robots[i]),
            );
        }
        left[i] = pos1 - leftPos;

        let rightPos;
        if (i < n - 1) {
            const rightBound = Math.min(
                robots[i] + robotsToDistance.get(robots[i]),
                robots[i + 1] - 1,
            );
            rightPos = upperBound(walls, rightBound);
        } else {
            rightPos = upperBound(
                walls,
                robots[i] + robotsToDistance.get(robots[i]),
            );
        }
        const pos2 = lowerBound(walls, robots[i]);
        right[i] = rightPos - pos2;

        if (i === 0) continue;

        const pos3 = lowerBound(walls, robots[i - 1]);
        num[i] = pos1 - pos3;
    }

    let subLeft = left[0],
        subRight = right[0];
    for (let i = 1; i < n; i++) {
        const currentLeft = Math.max(
            subLeft + left[i],
            subRight - right[i - 1] + Math.min(left[i] + right[i - 1], num[i]),
        );
        const currentRight = Math.max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    return Math.max(subLeft, subRight);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxWalls(
        self, robots: List[int], distance: List[int], walls: List[int]
    ) -> int:
        n = len(robots)
        left = [0] * n
        right = [0] * n
        num = [0] * n
        robots_to_distance = {}

        for i in range(n):
            robots_to_distance[robots[i]] = distance[i]

        robots.sort()
        walls.sort()

        for i in range(n):
            pos1 = bisect.bisect_right(walls, robots[i])

            if i >= 1:
                left_bound = max(
                    robots[i] - robots_to_distance[robots[i]], robots[i - 1] + 1
                )
                left_pos = bisect.bisect_left(walls, left_bound)
            else:
                left_pos = bisect.bisect_left(
                    walls, robots[i] - robots_to_distance[robots[i]]
                )

            left[i] = pos1 - left_pos

            if i < n - 1:
                right_bound = min(
                    robots[i] + robots_to_distance[robots[i]], robots[i + 1] - 1
                )
                right_pos = bisect.bisect_right(walls, right_bound)
            else:
                right_pos = bisect.bisect_right(
                    walls, robots[i] + robots_to_distance[robots[i]]
                )

            pos2 = bisect.bisect_left(walls, robots[i])
            right[i] = right_pos - pos2

            if i == 0:
                continue

            pos3 = bisect.bisect_left(walls, robots[i - 1])
            num[i] = pos1 - pos3

        sub_left, sub_right = left[0], right[0]
        for i in range(1, n):
            current_left = max(
                sub_left + left[i],
                sub_right - right[i - 1] + min(left[i] + right[i - 1], num[i]),
            )
            current_right = max(sub_left + right[i], sub_right + right[i])
            sub_left, sub_right = current_left, current_right

        return max(sub_left, sub_right)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxWalls(
    robots: number[],
    distance: number[],
    walls: number[],
): number {
    const n = robots.length;
    const left = new Array(n).fill(0);
    const right = new Array(n).fill(0);
    const num = new Array(n).fill(0);
    const robotsToDistance = new Map<number, number>();

    for (let i = 0; i < n; i++) {
        robotsToDistance.set(robots[i], distance[i]);
    }

    robots.sort((a, b) => a - b);
    walls.sort((a, b) => a - b);

    const lowerBound = (arr: number[], target: number): number => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    const upperBound = (arr: number[], target: number): number => {
        let left = 0,
            right = arr.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    };

    for (let i = 0; i < n; i++) {
        const pos1 = upperBound(walls, robots[i]);

        let leftPos: number;
        if (i >= 1) {
            const leftBound = Math.max(
                robots[i] - robotsToDistance.get(robots[i])!,
                robots[i - 1] + 1,
            );
            leftPos = lowerBound(walls, leftBound);
        } else {
            leftPos = lowerBound(
                walls,
                robots[i] - robotsToDistance.get(robots[i])!,
            );
        }
        left[i] = pos1 - leftPos;

        let rightPos: number;
        if (i < n - 1) {
            const rightBound = Math.min(
                robots[i] + robotsToDistance.get(robots[i])!,
                robots[i + 1] - 1,
            );
            rightPos = upperBound(walls, rightBound);
        } else {
            rightPos = upperBound(
                walls,
                robots[i] + robotsToDistance.get(robots[i])!,
            );
        }
        const pos2 = lowerBound(walls, robots[i]);
        right[i] = rightPos - pos2;

        if (i === 0) continue;

        const pos3 = lowerBound(walls, robots[i - 1]);
        num[i] = pos1 - pos3;
    }

    let subLeft = left[0],
        subRight = right[0];
    for (let i = 1; i < n; i++) {
        const currentLeft = Math.max(
            subLeft + left[i],
            subRight - right[i - 1] + Math.min(left[i] + right[i - 1], num[i]),
        );
        const currentRight = Math.max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    return Math.max(subLeft, subRight);
}
```

</details>

<br>

## Approach 2: Two Pointers + Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int maxInt(int a, int b) { return a > b ? a : b; }

int minInt(int a, int b) { return a < b ? a : b; }

int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize,
             int* walls, int wallsSize) {
    int n = robotsSize;
    int* left = (int*)calloc(n, sizeof(int));
    int* right = (int*)calloc(n, sizeof(int));
    int* num = (int*)calloc(n, sizeof(int));

    int* robotsCopy = (int*)malloc(n * sizeof(int));
    memcpy(robotsCopy, robots, n * sizeof(int));

    int* robotsToDistance = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int robotPos = robotsCopy[i];
        for (int j = 0; j < n; j++) {
            if (robots[j] == robotPos) {
                robotsToDistance[i] = distance[j];
                break;
            }
        }
    }

    qsort(robotsCopy, n, sizeof(int), compare);
    qsort(walls, wallsSize, sizeof(int), compare);

    int m = wallsSize;
    int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

    for (int i = 0; i < n; i++) {
        while (rightPtr < m && walls[rightPtr] <= robotsCopy[i]) {
            rightPtr++;
        }
        int pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robotsCopy[i]) {
            curPtr++;
        }
        int pos2 = curPtr;

        int leftBound = robotsCopy[i] - robotsToDistance[i];
        if (i >= 1) {
            leftBound = maxInt(robotsCopy[i] - robotsToDistance[i],
                               robotsCopy[i - 1] + 1);
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        int leftPos = leftPtr;
        left[i] = pos1 - leftPos;

        int rightBound = robotsCopy[i] + robotsToDistance[i];
        if (i < n - 1) {
            rightBound = minInt(robotsCopy[i] + robotsToDistance[i],
                                robotsCopy[i + 1] - 1);
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        int rightPos = rightPtr;
        right[i] = rightPos - pos2;

        if (i == 0) {
            continue;
        }
        while (robotPtr < m && walls[robotPtr] < robotsCopy[i - 1]) {
            robotPtr++;
        }
        int pos3 = robotPtr;
        num[i] = pos1 - pos3;
    }

    int subLeft = left[0], subRight = right[0];
    for (int i = 1; i < n; i++) {
        int currentLeft = maxInt(
            subLeft + left[i],
            subRight - right[i - 1] + minInt(left[i] + right[i - 1], num[i]));
        int currentRight = maxInt(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    int result = maxInt(subLeft, subRight);

    free(left);
    free(right);
    free(num);
    free(robotsCopy);
    free(robotsToDistance);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        vector<int> left(n, 0), right(n, 0), num(n, 0);
        unordered_map<int, int> robotsToDistance;

        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }

        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());

        int m = walls.size();
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        for (int i = 0; i < n; i++) {
            // rightPtr finds the position of the first element greater than
            // robots[i] (corresponding to upper_bound)
            while (rightPtr < m && walls[rightPtr] <= robots[i]) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            // curPtr finds the position of the first element >= robots[i]
            // (corresponding to lower_bound, used for calculating right[i])
            while (curPtr < m && walls[curPtr] < robots[i]) {
                curPtr++;
            }
            int pos2 = curPtr;

            // leftPtr finds the first wall >= the left boundary
            int leftBound = (i >= 1)
                                ? max(robots[i] - robotsToDistance[robots[i]],
                                      robots[i - 1] + 1)
                                : robots[i] - robotsToDistance[robots[i]];
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            left[i] = pos1 - leftPos;

            // Count the number of walls that can be reached on the right side
            // The right boundary needs to consider the overlapping area with
            // the next robot
            int rightBound = (i < n - 1)
                                 ? min(robots[i] + robotsToDistance[robots[i]],
                                       robots[i + 1] - 1)
                                 : robots[i] + robotsToDistance[robots[i]];
            // Find the first wall greater than the right boundary
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            right[i] = rightPos - pos2;

            if (i == 0) {
                continue;
            }
            // robotPtr finds the position of the previous robot
            while (robotPtr < m && walls[robotPtr] < robots[i - 1]) {
                robotPtr++;
            }
            int pos3 = robotPtr;
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0], subRight = right[0];
        for (int i = 1; i < n; i++) {
            int currentLeft =
                max(subLeft + left[i], subRight - right[i - 1] +
                                           min(left[i] + right[i - 1], num[i]));
            int currentRight = max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }
        return max(subLeft, subRight);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] num = new int[n];
        Dictionary<int, int> robotsToDistance = new Dictionary<int, int>();

        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }

        Array.Sort(robots);
        Array.Sort(walls);

        int m = walls.Length;
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        for (int i = 0; i < n; i++) {
            while (rightPtr < m && walls[rightPtr] <= robots[i]) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            while (curPtr < m && walls[curPtr] < robots[i]) {
                curPtr++;
            }
            int pos2 = curPtr;

            int leftBound = robots[i] - robotsToDistance[robots[i]];
            if (i >= 1) {
                leftBound = Math.Max(robots[i] - robotsToDistance[robots[i]],
                                     robots[i - 1] + 1);
            }
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            left[i] = pos1 - leftPos;

            int rightBound = robots[i] + robotsToDistance[robots[i]];
            if (i < n - 1) {
                rightBound = Math.Min(robots[i] + robotsToDistance[robots[i]],
                                      robots[i + 1] - 1);
            }
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            right[i] = rightPos - pos2;

            if (i == 0) {
                continue;
            }
            while (robotPtr < m && walls[robotPtr] < robots[i - 1]) {
                robotPtr++;
            }
            int pos3 = robotPtr;
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0], subRight = right[0];
        for (int i = 1; i < n; i++) {
            int currentLeft =
                Math.Max(subLeft + left[i],
                         subRight - right[i - 1] +
                             Math.Min(left[i] + right[i - 1], num[i]));
            int currentRight =
                Math.Max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }

        return Math.Max(subLeft, subRight);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxWalls(robots []int, distance []int, walls []int) int {
    n := len(robots)
    left := make([]int, n)
    right := make([]int, n)
    num := make([]int, n)
    robotsToDistance := make(map[int]int)

    for i := 0; i < n; i++ {
        robotsToDistance[robots[i]] = distance[i]
    }

    sort.Ints(robots)
    sort.Ints(walls)

    m := len(walls)
    rightPtr, leftPtr, curPtr, robotPtr := 0, 0, 0, 0

    for i := 0; i < n; i++ {
        for rightPtr < m && walls[rightPtr] <= robots[i] {
            rightPtr++
        }
        pos1 := rightPtr

        for curPtr < m && walls[curPtr] < robots[i] {
            curPtr++
        }
        pos2 := curPtr

        leftBound := robots[i] - robotsToDistance[robots[i]]
        if i >= 1 {
            leftBound = max(robots[i]-robotsToDistance[robots[i]], robots[i-1]+1)
        }
        for leftPtr < m && walls[leftPtr] < leftBound {
            leftPtr++
        }
        leftPos := leftPtr
        left[i] = pos1 - leftPos

        rightBound := robots[i] + robotsToDistance[robots[i]]
        if i < n-1 {
            rightBound = min(robots[i]+robotsToDistance[robots[i]], robots[i+1]-1)
        }
        for rightPtr < m && walls[rightPtr] <= rightBound {
            rightPtr++
        }
        rightPos := rightPtr
        right[i] = rightPos - pos2

        if i == 0 {
            continue
        }

        for robotPtr < m && walls[robotPtr] < robots[i-1] {
            robotPtr++
        }
        pos3 := robotPtr
        num[i] = pos1 - pos3
    }

    subLeft, subRight := left[0], right[0]
    for i := 1; i < n; i++ {
        currentLeft := max(subLeft+left[i], subRight-right[i-1]+min(left[i]+right[i-1], num[i]))
        currentRight := max(subLeft+right[i], subRight+right[i])
        subLeft, subRight = currentLeft, currentRight
    }

    return max(subLeft, subRight)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] num = new int[n];
        Map<Integer, Integer> robotsToDistance = new HashMap<>();

        for (int i = 0; i < n; i++) {
            robotsToDistance.put(robots[i], distance[i]);
        }

        Arrays.sort(robots);
        Arrays.sort(walls);

        int m = walls.length;
        int rightPtr = 0;
        int leftPtr = 0;
        int curPtr = 0;
        int robotPtr = 0;

        for (int i = 0; i < n; i++) {
            while (rightPtr < m && walls[rightPtr] <= robots[i]) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            while (curPtr < m && walls[curPtr] < robots[i]) {
                curPtr++;
            }
            int pos2 = curPtr;

            int leftBound = robots[i] - robotsToDistance.get(robots[i]);
            if (i >= 1) {
                leftBound = Math.max(
                    robots[i] - robotsToDistance.get(robots[i]),
                    robots[i - 1] + 1
                );
            }
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            left[i] = pos1 - leftPos;

            int rightBound = robots[i] + robotsToDistance.get(robots[i]);
            if (i < n - 1) {
                rightBound = Math.min(
                    robots[i] + robotsToDistance.get(robots[i]),
                    robots[i + 1] - 1
                );
            }
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            right[i] = rightPos - pos2;

            if (i == 0) {
                continue;
            }
            while (robotPtr < m && walls[robotPtr] < robots[i - 1]) {
                robotPtr++;
            }
            int pos3 = robotPtr;
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0];
        int subRight = right[0];
        for (int i = 1; i < n; i++) {
            int currentLeft = Math.max(
                subLeft + left[i],
                subRight -
                right[i - 1] +
                Math.min(left[i] + right[i - 1], num[i])
            );
            int currentRight = Math.max(
                subLeft + right[i],
                subRight + right[i]
            );
            subLeft = currentLeft;
            subRight = currentRight;
        }

        return Math.max(subLeft, subRight);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function maxWalls(robots, distance, walls) {
    const n = robots.length;
    const left = new Array(n).fill(0);
    const right = new Array(n).fill(0);
    const num = new Array(n).fill(0);
    const robotsToDistance = new Map();

    for (let i = 0; i < n; i++) {
        robotsToDistance.set(robots[i], distance[i]);
    }

    robots.sort((a, b) => a - b);
    walls.sort((a, b) => a - b);

    const m = walls.length;
    let rightPtr = 0,
        leftPtr = 0,
        curPtr = 0,
        robotPtr = 0;

    for (let i = 0; i < n; i++) {
        while (rightPtr < m && walls[rightPtr] <= robots[i]) {
            rightPtr++;
        }
        const pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robots[i]) {
            curPtr++;
        }
        const pos2 = curPtr;

        let leftBound = robots[i] - robotsToDistance.get(robots[i]);
        if (i >= 1) {
            leftBound = Math.max(
                robots[i] - robotsToDistance.get(robots[i]),
                robots[i - 1] + 1,
            );
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        const leftPos = leftPtr;
        left[i] = pos1 - leftPos;

        let rightBound = robots[i] + robotsToDistance.get(robots[i]);
        if (i < n - 1) {
            rightBound = Math.min(
                robots[i] + robotsToDistance.get(robots[i]),
                robots[i + 1] - 1,
            );
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        const rightPos = rightPtr;
        right[i] = rightPos - pos2;

        if (i === 0) {
            continue;
        }
        while (robotPtr < m && walls[robotPtr] < robots[i - 1]) {
            robotPtr++;
        }
        const pos3 = robotPtr;
        num[i] = pos1 - pos3;
    }

    let subLeft = left[0],
        subRight = right[0];
    for (let i = 1; i < n; i++) {
        const currentLeft = Math.max(
            subLeft + left[i],
            subRight - right[i - 1] + Math.min(left[i] + right[i - 1], num[i]),
        );
        const currentRight = Math.max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    return Math.max(subLeft, subRight);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxWalls(
        self, robots: List[int], distance: List[int], walls: List[int]
    ) -> int:
        n = len(robots)
        left = [0] * n
        right = [0] * n
        num = [0] * n
        robots_to_distance = {}

        for i in range(n):
            robots_to_distance[robots[i]] = distance[i]

        robots.sort()
        walls.sort()

        m = len(walls)
        right_ptr = left_ptr = cur_ptr = robot_ptr = 0

        for i in range(n):
            while right_ptr < m and walls[right_ptr] <= robots[i]:
                right_ptr += 1
            pos1 = right_ptr

            while cur_ptr < m and walls[cur_ptr] < robots[i]:
                cur_ptr += 1
            pos2 = cur_ptr

            if i >= 1:
                left_bound = max(
                    robots[i] - robots_to_distance[robots[i]], robots[i - 1] + 1
                )
            else:
                left_bound = robots[i] - robots_to_distance[robots[i]]

            while left_ptr < m and walls[left_ptr] < left_bound:
                left_ptr += 1
            left_pos = left_ptr
            left[i] = pos1 - left_pos

            if i < n - 1:
                right_bound = min(
                    robots[i] + robots_to_distance[robots[i]], robots[i + 1] - 1
                )
            else:
                right_bound = robots[i] + robots_to_distance[robots[i]]

            while right_ptr < m and walls[right_ptr] <= right_bound:
                right_ptr += 1
            right_pos = right_ptr
            right[i] = right_pos - pos2

            if i == 0:
                continue

            while robot_ptr < m and walls[robot_ptr] < robots[i - 1]:
                robot_ptr += 1
            pos3 = robot_ptr
            num[i] = pos1 - pos3

        sub_left, sub_right = left[0], right[0]
        for i in range(1, n):
            current_left = max(
                sub_left + left[i],
                sub_right - right[i - 1] + min(left[i] + right[i - 1], num[i]),
            )
            current_right = max(sub_left + right[i], sub_right + right[i])
            sub_left, sub_right = current_left, current_right

        return max(sub_left, sub_right)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxWalls(
    robots: number[],
    distance: number[],
    walls: number[],
): number {
    const n = robots.length;
    const left = new Array(n).fill(0);
    const right = new Array(n).fill(0);
    const num = new Array(n).fill(0);
    const robotsToDistance = new Map<number, number>();

    for (let i = 0; i < n; i++) {
        robotsToDistance.set(robots[i], distance[i]);
    }

    robots.sort((a, b) => a - b);
    walls.sort((a, b) => a - b);

    const m = walls.length;
    let rightPtr = 0,
        leftPtr = 0,
        curPtr = 0,
        robotPtr = 0;

    for (let i = 0; i < n; i++) {
        while (rightPtr < m && walls[rightPtr] <= robots[i]) {
            rightPtr++;
        }
        const pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robots[i]) {
            curPtr++;
        }
        const pos2 = curPtr;

        let leftBound = robots[i] - robotsToDistance.get(robots[i])!;
        if (i >= 1) {
            leftBound = Math.max(
                robots[i] - robotsToDistance.get(robots[i])!,
                robots[i - 1] + 1,
            );
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        const leftPos = leftPtr;
        left[i] = pos1 - leftPos;

        let rightBound = robots[i] + robotsToDistance.get(robots[i])!;
        if (i < n - 1) {
            rightBound = Math.min(
                robots[i] + robotsToDistance.get(robots[i])!,
                robots[i + 1] - 1,
            );
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        const rightPos = rightPtr;
        right[i] = rightPos - pos2;

        if (i === 0) {
            continue;
        }
        while (robotPtr < m && walls[robotPtr] < robots[i - 1]) {
            robotPtr++;
        }
        const pos3 = robotPtr;
        num[i] = pos1 - pos3;
    }

    let subLeft = left[0],
        subRight = right[0];
    for (let i = 1; i < n; i++) {
        const currentLeft = Math.max(
            subLeft + left[i],
            subRight - right[i - 1] + Math.min(left[i] + right[i - 1], num[i]),
        );
        const currentRight = Math.max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }

    return Math.max(subLeft, subRight);
}
```

</details>

<br>

## Approach 3: Two Pointers + Dynamic Programming + Space Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int comparePair(const void* a, const void* b) {
    int* pairA = (int*)a;
    int* pairB = (int*)b;
    return pairA[0] - pairB[0];
}

int maxInt(int a, int b) { return a > b ? a : b; }

int minInt(int a, int b) { return a < b ? a : b; }

int maxWalls(int* robots, int robotsSize, int* distance, int distanceSize,
             int* walls, int wallsSize) {
    int n = robotsSize;

    int (*robotDist)[2] = malloc(n * sizeof(int[2]));
    for (int i = 0; i < n; i++) {
        robotDist[i][0] = robots[i];
        robotDist[i][1] = distance[i];
    }
    qsort(robotDist, n, sizeof(int[2]), comparePair);
    qsort(walls, wallsSize, sizeof(int), compare);

    int m = wallsSize;
    int rightPtr = 0;
    int leftPtr = 0;
    int curPtr = 0;
    int robotPtr = 0;

    int prevLeft = 0;
    int prevRight = 0;
    int prevNum = 0;
    int subLeft = 0;
    int subRight = 0;

    for (int i = 0; i < n; i++) {
        int robotPos = robotDist[i][0];
        int robotDistVal = robotDist[i][1];

        while (rightPtr < m && walls[rightPtr] <= robotPos) {
            rightPtr++;
        }
        int pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robotPos) {
            curPtr++;
        }
        int pos2 = curPtr;

        int leftBound = robotPos - robotDistVal;
        if (i >= 1) {
            leftBound =
                maxInt(robotPos - robotDistVal, robotDist[i - 1][0] + 1);
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        int leftPos = leftPtr;
        int currentLeft = pos1 - leftPos;

        int rightBound = robotPos + robotDistVal;
        if (i < n - 1) {
            rightBound =
                minInt(robotPos + robotDistVal, robotDist[i + 1][0] - 1);
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        int rightPos = rightPtr;
        int currentRight = rightPos - pos2;

        int currentNum = 0;
        if (i > 0) {
            while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                robotPtr++;
            }
            int pos3 = robotPtr;
            currentNum = pos1 - pos3;
        }

        if (i == 0) {
            subLeft = currentLeft;
            subRight = currentRight;
        } else {
            int newsubLeft =
                maxInt(subLeft + currentLeft,
                       subRight - prevRight +
                           minInt(currentLeft + prevRight, currentNum));
            int newsubRight =
                maxInt(subLeft + currentRight, subRight + currentRight);
            subLeft = newsubLeft;
            subRight = newsubRight;
        }

        prevLeft = currentLeft;
        prevRight = currentRight;
        prevNum = currentNum;
    }

    int result = maxInt(subLeft, subRight);
    free(robotDist);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> robotDist;
        for (int i = 0; i < n; i++) {
            robotDist.push_back({robots[i], distance[i]});
        }
        sort(robotDist.begin(), robotDist.end());
        sort(walls.begin(), walls.end());

        int m = walls.size();
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        // DP variable: saves only the previous value
        int prevLeft = 0, prevRight = 0, prevNum = 0;
        int subLeft = 0, subRight = 0;

        for (int i = 0; i < n; i++) {
            int robotPos = robotDist[i].first;
            int robotDistVal = robotDist[i].second;

            // rightPtr finds the first position greater than robotPos
            // (corresponding to upper_bound)
            while (rightPtr < m && walls[rightPtr] <= robotPos) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            // curPtr finds the first position >= robotPos (corresponding to
            // lower_bound)
            while (curPtr < m && walls[curPtr] < robotPos) {
                curPtr++;
            }
            int pos2 = curPtr;

            // leftPtr finds the first wall >= the left boundary
            int leftBound = (i >= 1) ? max(robotPos - robotDistVal,
                                           robotDist[i - 1].first + 1)
                                     : robotPos - robotDistVal;
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            int currentLeft = pos1 - leftPos;

            // Count the number of walls that can be reached on the right side
            int rightBound = (i < n - 1) ? min(robotPos + robotDistVal,
                                               robotDist[i + 1].first - 1)
                                         : robotPos + robotDistVal;
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            int currentRight = rightPos - pos2;

            // robotPtr finds the position of the previous robot
            int currentNum = 0;
            if (i > 0) {
                while (robotPtr < m &&
                       walls[robotPtr] < robotDist[i - 1].first) {
                    robotPtr++;
                }
                int pos3 = robotPtr;
                currentNum = pos1 - pos3;
            }

            if (i == 0) {
                subLeft = currentLeft;
                subRight = currentRight;
            } else {
                int newsubLeft =
                    max(subLeft + currentLeft,
                        subRight - prevRight +
                            min(currentLeft + prevRight, currentNum));
                int newsubRight =
                    max(subLeft + currentRight, subRight + currentRight);
                subLeft = newsubLeft;
                subRight = newsubRight;
            }

            prevLeft = currentLeft;
            prevRight = currentRight;
            prevNum = currentNum;
        }

        return max(subLeft, subRight);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.Length;
        int[][] robotDist = new int [n][];
        for (int i = 0; i < n; i++) {
            robotDist[i] = new int[] { robots[i], distance[i] };
        }
        Array.Sort(robotDist, (a, b) => a[0].CompareTo(b[0]));
        Array.Sort(walls);

        int m = walls.Length;
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        int prevLeft = 0, prevRight = 0, prevNum = 0;
        int subLeft = 0, subRight = 0;

        for (int i = 0; i < n; i++) {
            int robotPos = robotDist[i][0];
            int robotDistVal = robotDist[i][1];

            while (rightPtr < m && walls[rightPtr] <= robotPos) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            while (curPtr < m && walls[curPtr] < robotPos) {
                curPtr++;
            }
            int pos2 = curPtr;

            int leftBound = robotPos - robotDistVal;
            if (i >= 1) {
                leftBound =
                    Math.Max(robotPos - robotDistVal, robotDist[i - 1][0] + 1);
            }
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            int currentLeft = pos1 - leftPos;

            int rightBound = robotPos + robotDistVal;
            if (i < n - 1) {
                rightBound =
                    Math.Min(robotPos + robotDistVal, robotDist[i + 1][0] - 1);
            }
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            int currentRight = rightPos - pos2;

            int currentNum = 0;
            if (i > 0) {
                while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                    robotPtr++;
                }
                int pos3 = robotPtr;
                currentNum = pos1 - pos3;
            }

            if (i == 0) {
                subLeft = currentLeft;
                subRight = currentRight;
            } else {
                int newsubLeft =
                    Math.Max(subLeft + currentLeft,
                             subRight - prevRight +
                                 Math.Min(currentLeft + prevRight, currentNum));
                int newsubRight =
                    Math.Max(subLeft + currentRight, subRight + currentRight);
                subLeft = newsubLeft;
                subRight = newsubRight;
            }

            prevLeft = currentLeft;
            prevRight = currentRight;
            prevNum = currentNum;
        }

        return Math.Max(subLeft, subRight);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxWalls(robots []int, distance []int, walls []int) int {
    n := len(robots)
    type RobotDist struct {
        pos   int
        dist  int
    }
    robotDist := make([]RobotDist, n)
    for i := 0; i < n; i++ {
        robotDist[i] = RobotDist{robots[i], distance[i]}
    }

    sort.Slice(robotDist, func(i, j int) bool {
        return robotDist[i].pos < robotDist[j].pos
    })
    sort.Ints(walls)

    m := len(walls)
    rightPtr, leftPtr, curPtr, robotPtr := 0, 0, 0, 0

    var prevLeft, prevRight, prevNum int
    var subLeft, subRight int

    for i := 0; i < n; i++ {
        robotPos := robotDist[i].pos
        robotDistVal := robotDist[i].dist

        for rightPtr < m && walls[rightPtr] <= robotPos {
            rightPtr++
        }
        pos1 := rightPtr

        for curPtr < m && walls[curPtr] < robotPos {
            curPtr++
        }
        pos2 := curPtr

        leftBound := robotPos - robotDistVal
        if i >= 1 {
            leftBound = max(robotPos-robotDistVal, robotDist[i-1].pos+1)
        }
        for leftPtr < m && walls[leftPtr] < leftBound {
            leftPtr++
        }
        leftPos := leftPtr
        currentLeft := pos1 - leftPos

        rightBound := robotPos + robotDistVal
        if i < n-1 {
            rightBound = min(robotPos+robotDistVal, robotDist[i+1].pos-1)
        }
        for rightPtr < m && walls[rightPtr] <= rightBound {
            rightPtr++
        }
        rightPos := rightPtr
        currentRight := rightPos - pos2

        currentNum := 0
        if i > 0 {
            for robotPtr < m && walls[robotPtr] < robotDist[i-1].pos {
                robotPtr++
            }
            pos3 := robotPtr
            currentNum = pos1 - pos3
        }

        if i == 0 {
            subLeft = currentLeft
            subRight = currentRight
        } else {
            newsubLeft := max(subLeft+currentLeft, subRight-prevRight+min(currentLeft+prevRight, currentNum))
            newsubRight := max(subLeft+currentRight, subRight+currentRight)
            subLeft = newsubLeft
            subRight = newsubRight
        }

        prevLeft = currentLeft
        prevRight = currentRight
        prevNum = currentNum
    }

    return max(subLeft, subRight)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.length;
        int[][] robotDist = new int[n][2];
        for (int i = 0; i < n; i++) {
            robotDist[i][0] = robots[i];
            robotDist[i][1] = distance[i];
        }
        Arrays.sort(robotDist, (a, b) -> a[0] - b[0]);
        Arrays.sort(walls);

        int m = walls.length;
        int rightPtr = 0;
        int leftPtr = 0;
        int curPtr = 0;
        int robotPtr = 0;

        int prevLeft = 0;
        int prevRight = 0;
        int prevNum = 0;
        int subLeft = 0;
        int subRight = 0;

        for (int i = 0; i < n; i++) {
            int robotPos = robotDist[i][0];
            int robotDistVal = robotDist[i][1];

            while (rightPtr < m && walls[rightPtr] <= robotPos) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            while (curPtr < m && walls[curPtr] < robotPos) {
                curPtr++;
            }
            int pos2 = curPtr;

            int leftBound = robotPos - robotDistVal;
            if (i >= 1) {
                leftBound = Math.max(
                    robotPos - robotDistVal,
                    robotDist[i - 1][0] + 1
                );
            }
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            int currentLeft = pos1 - leftPos;

            int rightBound = robotPos + robotDistVal;
            if (i < n - 1) {
                rightBound = Math.min(
                    robotPos + robotDistVal,
                    robotDist[i + 1][0] - 1
                );
            }
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            int currentRight = rightPos - pos2;

            int currentNum = 0;
            if (i > 0) {
                while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                    robotPtr++;
                }
                int pos3 = robotPtr;
                currentNum = pos1 - pos3;
            }

            if (i == 0) {
                subLeft = currentLeft;
                subRight = currentRight;
            } else {
                int newsubLeft = Math.max(
                    subLeft + currentLeft,
                    subRight -
                    prevRight +
                    Math.min(currentLeft + prevRight, currentNum)
                );
                int newsubRight = Math.max(
                    subLeft + currentRight,
                    subRight + currentRight
                );
                subLeft = newsubLeft;
                subRight = newsubRight;
            }

            prevLeft = currentLeft;
            prevRight = currentRight;
            prevNum = currentNum;
        }

        return Math.max(subLeft, subRight);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function maxWalls(robots, distance, walls) {
    const n = robots.length;
    const robotDist = robots.map((r, i) => [r, distance[i]]);
    robotDist.sort((a, b) => a[0] - b[0]);
    walls.sort((a, b) => a - b);

    const m = walls.length;
    let rightPtr = 0,
        leftPtr = 0,
        curPtr = 0,
        robotPtr = 0;

    let prevLeft = 0,
        prevRight = 0,
        prevNum = 0;
    let subLeft = 0,
        subRight = 0;

    for (let i = 0; i < n; i++) {
        const [robotPos, robotDistVal] = robotDist[i];

        while (rightPtr < m && walls[rightPtr] <= robotPos) {
            rightPtr++;
        }
        const pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robotPos) {
            curPtr++;
        }
        const pos2 = curPtr;

        let leftBound = robotPos - robotDistVal;
        if (i >= 1) {
            leftBound = Math.max(
                robotPos - robotDistVal,
                robotDist[i - 1][0] + 1,
            );
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        const leftPos = leftPtr;
        const currentLeft = pos1 - leftPos;

        let rightBound = robotPos + robotDistVal;
        if (i < n - 1) {
            rightBound = Math.min(
                robotPos + robotDistVal,
                robotDist[i + 1][0] - 1,
            );
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        const rightPos = rightPtr;
        const currentRight = rightPos - pos2;

        let currentNum = 0;
        if (i > 0) {
            while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                robotPtr++;
            }
            const pos3 = robotPtr;
            currentNum = pos1 - pos3;
        }

        if (i === 0) {
            subLeft = currentLeft;
            subRight = currentRight;
        } else {
            const newsubLeft = Math.max(
                subLeft + currentLeft,
                subRight -
                    prevRight +
                    Math.min(currentLeft + prevRight, currentNum),
            );
            const newsubRight = Math.max(
                subLeft + currentRight,
                subRight + currentRight,
            );
            subLeft = newsubLeft;
            subRight = newsubRight;
        }

        prevLeft = currentLeft;
        prevRight = currentRight;
        prevNum = currentNum;
    }

    return Math.max(subLeft, subRight);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxWalls(
        self, robots: List[int], distance: List[int], walls: List[int]
    ) -> int:
        n = len(robots)
        robot_dist = list(zip(robots, distance))
        robot_dist.sort(key=lambda x: x[0])
        walls.sort()

        m = len(walls)
        right_ptr = left_ptr = cur_ptr = robot_ptr = 0

        prev_left = prev_right = prev_num = 0
        sub_left = sub_right = 0

        for i in range(n):
            robot_pos, robot_dist_val = robot_dist[i]

            while right_ptr < m and walls[right_ptr] <= robot_pos:
                right_ptr += 1
            pos1 = right_ptr

            while cur_ptr < m and walls[cur_ptr] < robot_pos:
                cur_ptr += 1
            pos2 = cur_ptr

            if i >= 1:
                left_bound = max(
                    robot_pos - robot_dist_val, robot_dist[i - 1][0] + 1
                )
            else:
                left_bound = robot_pos - robot_dist_val

            while left_ptr < m and walls[left_ptr] < left_bound:
                left_ptr += 1
            left_pos = left_ptr
            current_left = pos1 - left_pos

            if i < n - 1:
                right_bound = min(
                    robot_pos + robot_dist_val, robot_dist[i + 1][0] - 1
                )
            else:
                right_bound = robot_pos + robot_dist_val

            while right_ptr < m and walls[right_ptr] <= right_bound:
                right_ptr += 1
            right_pos = right_ptr
            current_right = right_pos - pos2

            current_num = 0
            if i > 0:
                while robot_ptr < m and walls[robot_ptr] < robot_dist[i - 1][0]:
                    robot_ptr += 1
                pos3 = robot_ptr
                current_num = pos1 - pos3

            if i == 0:
                sub_left = current_left
                sub_right = current_right
            else:
                new_sub_left = max(
                    sub_left + current_left,
                    sub_right
                    - prev_right
                    + min(current_left + prev_right, current_num),
                )
                new_sub_right = max(
                    sub_left + current_right, sub_right + current_right
                )
                sub_left = new_sub_left
                sub_right = new_sub_right

            prev_left = current_left
            prev_right = current_right
            prev_num = current_num

        return max(sub_left, sub_right)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxWalls(
    robots: number[],
    distance: number[],
    walls: number[],
): number {
    const n = robots.length;
    const robotDist: [number, number][] = robots.map((r, i) => [
        r,
        distance[i],
    ]);
    robotDist.sort((a, b) => a[0] - b[0]);
    walls.sort((a, b) => a - b);

    const m = walls.length;
    let rightPtr = 0,
        leftPtr = 0,
        curPtr = 0,
        robotPtr = 0;

    let prevLeft = 0,
        prevRight = 0,
        prevNum = 0;
    let subLeft = 0,
        subRight = 0;

    for (let i = 0; i < n; i++) {
        const [robotPos, robotDistVal] = robotDist[i];

        while (rightPtr < m && walls[rightPtr] <= robotPos) {
            rightPtr++;
        }
        const pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robotPos) {
            curPtr++;
        }
        const pos2 = curPtr;

        let leftBound = robotPos - robotDistVal;
        if (i >= 1) {
            leftBound = Math.max(
                robotPos - robotDistVal,
                robotDist[i - 1][0] + 1,
            );
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        const leftPos = leftPtr;
        const currentLeft = pos1 - leftPos;

        let rightBound = robotPos + robotDistVal;
        if (i < n - 1) {
            rightBound = Math.min(
                robotPos + robotDistVal,
                robotDist[i + 1][0] - 1,
            );
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        const rightPos = rightPtr;
        const currentRight = rightPos - pos2;

        let currentNum = 0;
        if (i > 0) {
            while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                robotPtr++;
            }
            const pos3 = robotPtr;
            currentNum = pos1 - pos3;
        }

        if (i === 0) {
            subLeft = currentLeft;
            subRight = currentRight;
        } else {
            const newsubLeft = Math.max(
                subLeft + currentLeft,
                subRight -
                    prevRight +
                    Math.min(currentLeft + prevRight, currentNum),
            );
            const newsubRight = Math.max(
                subLeft + currentRight,
                subRight + currentRight,
            );
            subLeft = newsubLeft;
            subRight = newsubRight;
        }

        prevLeft = currentLeft;
        prevRight = currentRight;
        prevNum = currentNum;
    }

    return Math.max(subLeft, subRight);
}
```

</details>
