# 2225. Find Players With Zero or One Losses

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-players-with-zero-or-one-losses/)  
`Array` `Hash Table` `Sorting` `Counting`

**Problem Link:** [LeetCode 2225 - Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses/)

## Problem

You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

- answer[0] is a list of all players that have not lost any matches.
- answer[1] is a list of all players that have lost exactly one match.

The values in the two lists should be returned in increasing order.

Note:

- You should only consider the players that have played at least one match.
- The testcases will be generated such that no two matches will have the same outcome.

### Example 1

```text
Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
```

### Example 2

```text
Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].
```

## Constraints

- 1 <= matches.length <= 105
- matches[i].length == 2
- 1 <= winneri, loseri <= 105
- winneri != loseri
- All matches[i] are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2225. Find Players With Zero or One Losses

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Set | C++, Java, Python3 |
| Hash Set + Hash Map | C++, Java, Python3 |
| Hash Map | C++, Java, Python3 |
| Counting with Array | C++, Java, Python3 |

## Approach 1: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> zeroLoss, oneLoss, moreLoss;

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            // Add winner.
            if ((oneLoss.find(winner) == oneLoss.end()) &&
                (moreLoss.find(winner) == moreLoss.end())) {
                zeroLoss.insert(winner);
            }
            // Add or move loser.
            if (zeroLoss.find(loser) != zeroLoss.end()) {
                zeroLoss.erase(loser);
                oneLoss.insert(loser);
            } else if (oneLoss.find(loser) != oneLoss.end()) {
                oneLoss.erase(loser);
                moreLoss.insert(loser);
            } else if (moreLoss.find(loser) != moreLoss.end()) {
                continue;
            } else {
                oneLoss.insert(loser);
            }
        }

        vector<vector<int>> answer(2, vector<int>());
        answer[0].assign(zeroLoss.begin(), zeroLoss.end());
        answer[1].assign(oneLoss.begin(), oneLoss.end());
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Set<Integer> zeroLoss = new HashSet<>(), oneLoss = new HashSet<>(),
                moreLosses = new HashSet<>();

        for (int[] match : matches) {
            int winner = match[0], loser = match[1];
            // Add winner.
            if (!oneLoss.contains(winner) && !moreLosses.contains(winner)) {
                zeroLoss.add(winner);
            }
            // Add or move loser.
            if (zeroLoss.contains(loser)) {
                zeroLoss.remove(loser);
                oneLoss.add(loser);
            } else if (oneLoss.contains(loser)) {
                oneLoss.remove(loser);
                moreLosses.add(loser);
            } else if (moreLosses.contains(loser)) {
                continue;
            } else {
                oneLoss.add(loser);
            }
        }

        List<List<Integer>> answer =
            Arrays.asList(new ArrayList<>(), new ArrayList<>());
        answer.get(0).addAll(zeroLoss);
        answer.get(1).addAll(oneLoss);
        Collections.sort(answer.get(0));
        Collections.sort(answer.get(1));

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        zero_loss = set()
        one_loss = set()
        more_losses = set()
        
        for winner, loser in matches:
            # Add winner
            if (winner not in one_loss) and (winner not in more_losses):
                zero_loss.add(winner)
            # Add or move loser.
            if loser in zero_loss:
                zero_loss.remove(loser)
                one_loss.add(loser)
            elif loser in one_loss:
                one_loss.remove(loser)
                more_losses.add(loser)
            elif loser in more_losses:
                continue
            else:
                one_loss.add(loser)          
            
        return [sorted(list(zero_loss)), sorted(list(one_loss))]
```

</details>

<br>

## Approach 2: Hash Set + Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> seen;
        unordered_map<int, int> lossesCount;

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            seen.insert(winner);
            seen.insert(loser);
            lossesCount[loser]++;
        }

        // Add players with 0 or 1 loss to the corresponding list.
        vector<vector<int>> answer(2, vector<int>());
        for (auto player : seen) {
            if (lossesCount.find(player) == lossesCount.end()) {
                answer[0].push_back(player);
            } else if (lossesCount[player] == 1) {
                answer[1].push_back(player);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Set<Integer> seen = new HashSet<>();
        Map<Integer, Integer> lossesCount = new HashMap<>();

        for (int[] match : matches) {
            int winner = match[0], loser = match[1];
            seen.add(winner);
            seen.add(loser);
            lossesCount.put(loser, lossesCount.getOrDefault(loser, 0) + 1);
        }

        // Add players with 0 or 1 loss to the corresponding list.
        List<List<Integer>> answer =
            Arrays.asList(new ArrayList<>(), new ArrayList<>());
        for (int player : seen) {
            if (!lossesCount.containsKey(player)) {
                answer.get(0).add(player);
            } else if (lossesCount.get(player) == 1) {
                answer.get(1).add(player);
            }
        }

        Collections.sort(answer.get(0));
        Collections.sort(answer.get(1));

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution: 
    def findWinners(self, matches : List[List[int]]) ->List[List[int]]: 
        seen = set() losses_count = {}
        
        for winner, loser in matches:
            seen.add(winner)
            seen.add(loser)
            losses_count[loser] = losses_count.get(loser, 0) + 1
        
        #Add players with 0 or 1 loss to the corresponding list.
        zero_lose, one_lose = [], []
        for player in seen:
            count = losses_count.get(player, 0)
            if count == 0:
                zero_lose.append(player)
            elif count == 1:
                one_lose.append(player)
        
        return [sorted(zero_lose), sorted(one_lose)]
```

</details>

<br>

## Approach 3: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lossesCount;
        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            if (lossesCount.find(winner) == lossesCount.end()) {
                lossesCount[winner] = 0;
            }
            lossesCount[loser]++;
        }

        vector<vector<int>> answer(2, vector<int>());
        for (auto [player, count] : lossesCount) {
            if (count == 0) {
                answer[0].push_back(player);
            } else if (count == 1) {
                answer[1].push_back(player);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> lossesCount = new HashMap<>();
        for (int[] match : matches) {
            int winner = match[0], loser = match[1];
            lossesCount.put(winner, lossesCount.getOrDefault(winner, 0));
            lossesCount.put(loser, lossesCount.getOrDefault(loser, 0) + 1);
        }

        List<List<Integer>> answer =
            Arrays.asList(new ArrayList<>(), new ArrayList<>());
        for (Integer player : lossesCount.keySet())
            if (lossesCount.get(player) == 0) {
                answer.get(0).add(player);
            } else if (lossesCount.get(player) == 1) {
                answer.get(1).add(player);
            }

        Collections.sort(answer.get(0));
        Collections.sort(answer.get(1));

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution: 
    def findWinners(self, matches: List[List[int]]) ->List[List[int]]: 
        losses_count = {}
        
        for winner, loser in matches:
            losses_count[winner] = losses_count.get(winner, 0)
            losses_count[loser] = losses_count.get(loser, 0) + 1
        
        zero_lose, one_lose = [], []
        for player, count in losses_count.items():
            if count == 0:
                zero_lose.append(player)
            if count == 1:
                one_lose.append(player)
        
        return [sorted(zero_lose), sorted(one_lose)]
```

</details>

<br>

## Approach 4: Counting with Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> lossesCount(100001, -1);

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            if (lossesCount[winner] == -1) {
                lossesCount[winner] = 0;
            }
            if (lossesCount[loser] == -1) {
                lossesCount[loser] = 1;
            } else {
                lossesCount[loser]++;
            }
        }

        vector<vector<int>> answer(2, vector<int>());
        for (int i = 1; i < 100001; ++i) {
            if (lossesCount[i] == 0) {
                answer[0].push_back(i);
            } else if (lossesCount[i] == 1) {
                answer[1].push_back(i);
            }
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        int[] lossesCount = new int[100001];
        Arrays.fill(lossesCount, -1);

        for (int[] match : matches) {
            int winner = match[0], loser = match[1];
            if (lossesCount[winner] == -1) {
                lossesCount[winner] = 0;
            }
            if (lossesCount[loser] == -1) {
                lossesCount[loser] = 1;
            } else {
                lossesCount[loser]++;
            }
        }

        List<List<Integer>> answer =
            Arrays.asList(new ArrayList<>(), new ArrayList<>());
        for (int i = 1; i < 100001; ++i) {
            if (lossesCount[i] == 0) {
                answer.get(0).add(i);
            } else if (lossesCount[i] == 1) {
                answer.get(1).add(i);
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losses_count = [-1] * 100001

        for winner, loser in matches:
            if losses_count[winner] == -1:
                losses_count[winner] = 0
            if losses_count[loser] == -1:
                losses_count[loser] = 1
            else:
                losses_count[loser] += 1
            
        answer = [[], []]
        for i in range(100001):
            if losses_count[i] == 0:
                answer[0].append(i)
            elif losses_count[i] == 1:
                answer[1].append(i)
                
        return answer
```

</details>
