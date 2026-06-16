# 1488. Avoid Flood in The City

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/avoid-flood-in-the-city/)  
`Array` `Hash Table` `Binary Search` `Greedy` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1488 - Avoid Flood in The City](https://leetcode.com/problems/avoid-flood-in-the-city/)

## Problem

Your country has 109 lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.

Given an integer array rains where:

- rains[i] > 0 means there will be rains over the rains[i] lake.
- rains[i] == 0 means there are no rains this day and you must choose one lake this day and dry it.

Return an array ans where:

- ans.length == rains.length
- ans[i] == -1 if rains[i] > 0.
- ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.

If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes.

### Example 1

```text
Input: rains = [1,2,3,4]
Output: [-1,-1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day full lakes are [1,2,3]
After the fourth day full lakes are [1,2,3,4]
There's no day to dry any lake and there is no flood in any lake.
```

### Example 2

```text
Input: rains = [1,2,0,0,2,1]
Output: [-1,-1,2,1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day, we dry lake 2. Full lakes are [1]
After the fourth day, we dry lake 1. There is no full lakes.
After the fifth day, full lakes are [2].
After the sixth day, full lakes are [1,2].
It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.
```

### Example 3

```text
Input: rains = [1,2,0,1,2]
Output: []
Explanation: After the second day, full lakes are  [1,2]. We have to dry one lake in the third day.
After that, it will rain over lakes [1,2]. It's easy to prove that no matter which lake you choose to dry in the 3rd day, the other one will flood.
```

## Constraints

- 1 <= rains.length <= 105
- 0 <= rains[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1488. Avoid Flood in The City

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy + Binary Search | C++, Go, Java, Python3 |

## Approach: Greedy + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        set<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                st.insert(i);
            } else {
                ans[i] = -1;
                if (mp.count(rains[i])) {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if (it == st.end()) {
                        return {};
                    }
                    ans[*it] = rains[i];
                    st.erase(it);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func avoidFlood(rains []int) []int {
	n := len(rains)
	ans := make([]int, n)
	st := []int{}
	mp := make(map[int]int)
	for i := 0; i < n; i++ {
		ans[i] = 1
	}
	for i, rain := range rains {
		if rain == 0 {
			st = append(st, i)
		} else {
			ans[i] = -1
			if day, ok := mp[rain]; ok {
				it := sort.SearchInts(st, day)
				if it == len(st) {
					return []int{}
				}
				ans[st[it]] = rain
				copy(st[it:len(st)-1], st[it+1:])
				st = st[:len(st)-1]
			}
			mp[rain] = i
		}
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] avoidFlood(int[] rains) {
        int[] ans = new int[rains.length];
        Arrays.fill(ans, 1);
        TreeSet<Integer> st = new TreeSet<Integer>();
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for (int i = 0; i < rains.length; ++i) {
            if (rains[i] == 0) {
                st.add(i);
            } else {
                ans[i] = -1;
                if (mp.containsKey(rains[i])) {
                    Integer it = st.ceiling(mp.get(rains[i]));
                    if (it == null) {
                        return new int[0];
                    }
                    ans[it] = rains[i];
                    st.remove(it);
                }
                mp.put(rains[i], i);
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedList


class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        ans = [1] * len(rains)
        st = SortedList()
        mp = {}
        for i, rain in enumerate(rains):
            if rain == 0:
                st.add(i)
            else:
                ans[i] = -1
                if rain in mp:
                    it = st.bisect(mp[rain])
                    if it == len(st):
                        return []
                    ans[st[it]] = rain
                    st.discard(st[it])
                mp[rain] = i
        return ans
```

</details>
