# 1733. Minimum Number of People to Teach

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-people-to-teach/)  
`Array` `Hash Table` `Greedy`

**Problem Link:** [LeetCode 1733 - Minimum Number of People to Teach](https://leetcode.com/problems/minimum-number-of-people-to-teach/)

## Problem

On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

- There are n languages numbered 1 through n,
- languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
- friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.

You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

### Example 1

```text
Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.
```

### Example 2

```text
Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
```

## Constraints

- 2 <= n <= 500
- languages.length == m
- 1 <= m <= 500
- 1 <= languages[i].length <= n
- 1 <= languages[i][j] <= n
- 1 <= u​​​​​​i < v​​​​​​i <= languages.length
- 1 <= friendships.length <= 500
- All tuples (u​​​​​i, v​​​​​​i) are unique
- languages[i] contains only unique values

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1733. Minimum Number of People to Teach

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
typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int minimumTeachings(int n, int **languages, int languagesSize,
                     int *languagesColSize, int **friendships,
                     int friendshipsSize, int *friendshipsColSize) {
    HashItem *cncon = NULL;
    for (int i = 0; i < friendshipsSize; i++) {
        HashItem *mp = NULL;
        bool conm = false;
        int person1 = friendships[i][0] - 1;
        int person2 = friendships[i][1] - 1;
        for (int j = 0; j < languagesColSize[person1]; j++) {
            hashAddItem(&mp, languages[person1][j]);
        }
        for (int j = 0; j < languagesColSize[person2]; j++) {
            if (hashFindItem(&mp, languages[person2][j])) {
                conm = true;
                break;
            }
        }
        if (!conm) {
            hashAddItem(&cncon, person1);
            hashAddItem(&cncon, person2);
        }
        hashFree(&mp);
    }

    int max_cnt = 0;
    int *cnt = (int *)calloc(n + 1, sizeof(int));
    for (HashItem *pEntry = cncon; pEntry; pEntry = pEntry->hh.next) {
        int person = pEntry->key;
        for (int i = 0; i < languagesColSize[person]; i++) {
            int lan = languages[person][i];
            cnt[lan]++;
            max_cnt = fmax(max_cnt, cnt[lan]);
        }
    }

    int ret = HASH_COUNT(cncon) - max_cnt;
    hashFree(&cncon);
    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_set<int> cncon;
        for (auto friendship : friendships) {
            unordered_map<int, int> mp;
            bool conm = false;
            for (int lan : languages[friendship[0] - 1]) {
                mp[lan] = 1;
            }
            for (int lan : languages[friendship[1] - 1]) {
                if (mp[lan]) {
                    conm = true;
                    break;
                }
            }
            if (!conm) {
                cncon.insert(friendship[0] - 1);
                cncon.insert(friendship[1] - 1);
            }
        }
        int max_cnt = 0;
        vector<int> cnt(n + 1, 0);
        for (auto friendship : cncon) {
            for (int lan : languages[friendship]) {
                cnt[lan]++;
                max_cnt = max(max_cnt, cnt[lan]);
            }
        }
        return cncon.size() - max_cnt;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumTeachings(int n, int[][] languages, int[][] friendships) {
        HashSet<int> cncon = new HashSet<int>();
        foreach (var friendship in friendships) {
            HashSet<int> mp = new HashSet<int>();
            bool conm = false;
            foreach (var lan in languages[friendship[0] - 1]) {
                mp.Add(lan);
            }
            foreach (var lan in languages[friendship[1] - 1]) {
                if (mp.Contains(lan)) {
                    conm = true;
                    break;
                }
            }
            if (!conm) {
                cncon.Add(friendship[0] - 1);
                cncon.Add(friendship[1] - 1);
            }
        }

        int max_cnt = 0;
        int[] cnt = new int[n + 1];
        foreach (var person in cncon) {
            foreach (var lan in languages[person]) {
                cnt[lan]++;
                max_cnt = Math.Max(max_cnt, cnt[lan]);
            }
        }
        return cncon.Count - max_cnt;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumTeachings(n int, languages [][]int, friendships [][]int) int {
	cncon := make(map[int]bool)
	for _, friendship := range friendships {
		mp := make(map[int]bool)
		conm := false
		for _, lan := range languages[friendship[0]-1] {
			mp[lan] = true
		}
		for _, lan := range languages[friendship[1]-1] {
			if mp[lan] {
				conm = true
				break
			}
		}
		if !conm {
			cncon[friendship[0]-1] = true
			cncon[friendship[1]-1] = true
		}
	}

	maxCnt := 0
	cnt := make([]int, n+1)
	for person := range cncon {
		for _, lan := range languages[person] {
			cnt[lan]++
			maxCnt = max(maxCnt, cnt[lan])
		}
	}

	return len(cncon) - maxCnt
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer> cncon = new HashSet<>();
        for (int[] friendship : friendships) {
            Map<Integer, Integer> mp = new HashMap<>();
            boolean conm = false;
            for (int lan : languages[friendship[0] - 1]) {
                mp.put(lan, 1);
            }
            for (int lan : languages[friendship[1] - 1]) {
                if (mp.containsKey(lan)) {
                    conm = true;
                    break;
                }
            }
            if (!conm) {
                cncon.add(friendship[0] - 1);
                cncon.add(friendship[1] - 1);
            }
        }
        int max_cnt = 0;
        int[] cnt = new int[n + 1];
        for (int friendship : cncon) {
            for (int lan : languages[friendship]) {
                cnt[lan]++;
                max_cnt = Math.max(max_cnt, cnt[lan]);
            }
        }
        return cncon.size() - max_cnt;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumTeachings = function (n, languages, friendships) {
    const cncon = new Set();
    for (const friendship of friendships) {
        const mp = new Set();
        let conm = false;
        for (const lan of languages[friendship[0] - 1]) {
            mp.add(lan);
        }
        for (const lan of languages[friendship[1] - 1]) {
            if (mp.has(lan)) {
                conm = true;
                break;
            }
        }

        if (!conm) {
            cncon.add(friendship[0] - 1);
            cncon.add(friendship[1] - 1);
        }
    }

    let max_cnt = 0;
    const cnt = new Array(n + 1).fill(0);
    for (const person of cncon) {
        for (const lan of languages[person]) {
            cnt[lan]++;
            max_cnt = Math.max(max_cnt, cnt[lan]);
        }
    }

    return cncon.size - max_cnt;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTeachings(
        self, n: int, languages: List[List[int]], friendships: List[List[int]]
    ) -> int:
        cncon = set()
        for friendship in friendships:
            mp = {}
            conm = False
            for lan in languages[friendship[0] - 1]:
                mp[lan] = 1
            for lan in languages[friendship[1] - 1]:
                if lan in mp:
                    conm = True
                    break
            if not conm:
                cncon.add(friendship[0] - 1)
                cncon.add(friendship[1] - 1)

        max_cnt = 0
        cnt = [0] * (n + 1)
        for friendship in cncon:
            for lan in languages[friendship]:
                cnt[lan] += 1
                max_cnt = max(max_cnt, cnt[lan])

        return len(cncon) - max_cnt
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumTeachings(
    n: number,
    languages: number[][],
    friendships: number[][],
): number {
    const cncon: Set<number> = new Set();
    for (const friendship of friendships) {
        const mp: Set<number> = new Set();
        let conm = false;
        for (const lan of languages[friendship[0] - 1]) {
            mp.add(lan);
        }
        for (const lan of languages[friendship[1] - 1]) {
            if (mp.has(lan)) {
                conm = true;
                break;
            }
        }

        if (!conm) {
            cncon.add(friendship[0] - 1);
            cncon.add(friendship[1] - 1);
        }
    }

    let max_cnt = 0;
    const cnt: number[] = new Array(n + 1).fill(0);
    for (const person of cncon) {
        for (const lan of languages[person]) {
            cnt[lan]++;
            max_cnt = Math.max(max_cnt, cnt[lan]);
        }
    }

    return cncon.size - max_cnt;
}
```

</details>
