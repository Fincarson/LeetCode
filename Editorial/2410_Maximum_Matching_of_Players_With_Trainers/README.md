# 2410. Maximum Matching of Players With Trainers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/)  
`Array` `Two Pointers` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2410 - Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/)

## Problem

You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

Return the maximum number of matchings between players and trainers that satisfy these conditions.

### Example 1

```text
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
```

### Example 2

```text
Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
```

## Constraints

- 1 <= players.length, trainers.length <= 105
- 1 <= players[i], trainers[j] <= 109

Note: This question is the same as  445: Assign Cookies.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Most Profit Assigning Work](https://leetcode.com/problems/most-profit-assigning-work/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Long Pressed Name](https://leetcode.com/problems/long-pressed-name/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Largest Merge Of Two Strings](https://leetcode.com/problems/largest-merge-of-two-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Tasks You Can Assign](https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [The Latest Time to Catch a Bus](https://leetcode.com/problems/the-latest-time-to-catch-a-bus/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize Greatness of an Array](https://leetcode.com/problems/maximize-greatness-of-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2410. Maximum Matching of Players With Trainers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting + Two Pointers + Greedy | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Sorting + Two Pointers + Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers,
                            int trainersSize) {
    qsort(players, playersSize, sizeof(int), cmp);
    qsort(trainers, trainersSize, sizeof(int), cmp);
    int m = playersSize, n = trainersSize;
    int count = 0;
    for (int i = 0, j = 0; i < m && j < n; i++, j++) {
        while (j < n && players[i] > trainers[j]) {
            j++;
        }
        if (j < n) {
            count++;
        }
    }
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int m = players.size(), n = trainers.size();
        int count = 0;
        for (int i = 0, j = 0; i < m && j < n; i++, j++) {
            while (j < n && players[i] > trainers[j]) {
                j++;
            }
            if (j < n) {
                count++;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MatchPlayersAndTrainers(int[] players, int[] trainers) {
        Array.Sort(players);
        Array.Sort(trainers);
        int m = players.Length, n = trainers.Length;
        int count = 0;
        for (int i = 0, j = 0; i < m && j < n; i++, j++) {
            while (j < n && players[i] > trainers[j]) {
                j++;
            }
            if (j < n) {
                count++;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func matchPlayersAndTrainers(players []int, trainers []int) (ans int) {
	sort.Ints(players)
	sort.Ints(trainers)
	m, n := len(players), len(trainers)
	for i, j := 0, 0; i < m && j < n; i++ {
		for j < n && players[i] > trainers[j] {
			j++
		}
		if j < n {
			ans++
			j++
		}
	}
	return
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);

        int m = players.length;
        int n = trainers.length;
        int count = 0;

        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (players[i] <= trainers[j]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var matchPlayersAndTrainers = function (players, trainers) {
    players.sort((a, b) => a - b);
    trainers.sort((a, b) => a - b);
    const m = players.length,
        n = trainers.length;
    let count = 0;
    for (let i = 0, j = 0; i < m && j < n; i++, j++) {
        while (j < n && players[i] > trainers[j]) {
            j++;
        }
        if (j < n) {
            count++;
        }
    }
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def matchPlayersAndTrainers(
        self, players: List[int], trainers: List[int]
    ) -> int:
        players.sort()
        trainers.sort()
        m, n = len(players), len(trainers)
        i = j = count = 0

        while i < m and j < n:
            while j < n and players[i] > trainers[j]:
                j += 1
            if j < n:
                count += 1
            i += 1
            j += 1

        return count
```

</details>
