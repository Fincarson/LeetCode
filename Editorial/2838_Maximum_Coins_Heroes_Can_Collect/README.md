# 2838. Maximum Coins Heroes Can Collect

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-coins-heroes-can-collect/)  
`Array` `Two Pointers` `Binary Search` `Sorting` `Prefix Sum`

**Problem Link:** [LeetCode 2838 - Maximum Coins Heroes Can Collect](https://leetcode.com/problems/maximum-coins-heroes-can-collect/)

## Problem

There is a battle and n heroes are trying to defeat m monsters. You are given two 1-indexed arrays of positive integers heroes and monsters of length n and m, respectively. heroes[i] is the power of ith hero, and monsters[i] is the power of ith monster.

The ith hero can defeat the jth monster if monsters[j] <= heroes[i].

You are also given a 1-indexed array coins of length m consisting of positive integers. coins[i] is the number of coins that each hero earns after defeating the ith monster.

Return an array ans of length n where ans[i] is the maximum number of coins that the ith hero can collect from this battle.

Notes

- The health of a hero doesn't get reduced after defeating a monster.
- Multiple heroes can defeat a monster, but each monster can be defeated by a given hero only once.

### Example 1

```text
Input: heroes = [1,4,2], monsters = [1,1,5,2,3], coins = [2,3,4,5,6]
Output: [5,16,10]
Explanation: For each hero, we list the index of all the monsters he can defeat:
1st hero: [1,2] since the power of this hero is 1 and monsters[1], monsters[2] <= 1. So this hero collects coins[1] + coins[2] = 5 coins.
2nd hero: [1,2,4,5] since the power of this hero is 4 and monsters[1], monsters[2], monsters[4], monsters[5] <= 4. So this hero collects coins[1] + coins[2] + coins[4] + coins[5] = 16 coins.
3rd hero: [1,2,4] since the power of this hero is 2 and monsters[1], monsters[2], monsters[4] <= 2. So this hero collects coins[1] + coins[2] + coins[4] = 10 coins.
So the answer would be [5,16,10].
```

### Example 2

```text
Input: heroes = [5], monsters = [2,3,1,2], coins = [10,6,5,2]
Output: [23]
Explanation: This hero can defeat all the monsters since monsters[i] <= 5. So he collects all of the coins: coins[1] + coins[2] + coins[3] + coins[4] = 23, and the answer would be [23].
```

### Example 3

```text
Input: heroes = [4,4], monsters = [5,7,8], coins = [1,1,1]
Output: [0,0]
Explanation: In this example, no hero can defeat a monster. So the answer would be [0,0],
```

## Constraints

- 1 <= n == heroes.length <= 105
- 1 <= m == monsters.length <= 105
- coins.length == m
- 1 <= heroes[i], monsters[i], coins[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2838. Maximum Coins Heroes Can Collect

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting + Prefix Sum + Binary Search | C++, Java, Python3 |

## Approach 1: Sorting + Prefix Sum + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters,
                                   vector<int>& coins) {
        vector<long long> ans(heroes.size());
        vector<pair<int, int>> monsterAndCoin(monsters.size());

        for (int i = 0; i < monsters.size(); i++) {
            monsterAndCoin[i].first = monsters[i];
            monsterAndCoin[i].second = coins[i];
        }

        // sort by ascending value of monster power
        sort(monsterAndCoin.begin(), monsterAndCoin.end());

        vector<long long> coinsSum(coins.size());
        long long prefixSum = 0;
        for (int i = 0; i < monsterAndCoin.size(); i++) {
            prefixSum += monsterAndCoin[i].second;
            coinsSum[i] = prefixSum;
        }

        for (int i = 0; i < heroes.size(); i++) {
            ans[i] = findTotalCoins(monsterAndCoin, heroes[i], coinsSum);
        }

        return ans;
    }

private:
    long long findTotalCoins(vector<pair<int, int>>& monsterAndCoin,
                             int heroPower, vector<long long>& coinsSum) {
        int l = 0;
        int r = monsterAndCoin.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (monsterAndCoin[mid].first > heroPower)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (l == 0 && monsterAndCoin[l].first > heroPower) {
            // hero can't defeat any monsters
            return 0;
        }

        return coinsSum[r];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long[] maximumCoins(int[] heroes, int[] monsters, int[] coins) {
        long[] ans = new long[heroes.length];
        int[][] monsterAndCoin = new int[monsters.length][2];
        for (int i = 0; i < monsters.length; i++) {
            monsterAndCoin[i][0] = monsters[i];
            monsterAndCoin[i][1] = coins[i];
        }

        // sort by ascending value of monster power
        Arrays.sort(monsterAndCoin, (a, b) -> a[0] - b[0]);

        long[] coinsSum = new long[coins.length];
        long prefixSum = 0;
        for (int i = 0; i < monsterAndCoin.length; i++) {
            prefixSum += monsterAndCoin[i][1];
            coinsSum[i] = prefixSum;
        }

        for (int i = 0; i < heroes.length; i++) {
            int heroPower = heroes[i];
            ans[i] = findTotalCoins(monsterAndCoin, heroes[i], coinsSum);
        }

        return ans;
    }

    private long findTotalCoins(
        int[][] monsterAndCoin,
        int heroPower,
        long[] coinsSum
    ) {
        int l = 0;
        int r = monsterAndCoin.length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (monsterAndCoin[mid][0] > heroPower) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l == 0 && monsterAndCoin[l][0] > heroPower) {
            // hero can't defeat any monsters
            return 0;
        }

        return coinsSum[r];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumCoins(self, heroes, monsters, coins):
        ans = [0] * len(heroes)
        monster_and_coin = sorted(zip(monsters, coins), key=lambda x: x[0])
        coins_sum = [0] * len(coins)
        prefix_sum = 0
        for i, (_, coin) in enumerate(monster_and_coin):
            prefix_sum += coin
            coins_sum[i] = prefix_sum

        for i, hero in enumerate(heroes):
            ans[i] = self.findTotalCoins(monster_and_coin, hero, coins_sum)
        return ans

    def findTotalCoins(self, monster_and_coin, hero_power, coins_sum):
        l, r = 0, len(monster_and_coin) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if monster_and_coin[mid][0] > hero_power:
                r = mid - 1
            else:
                l = mid + 1

        if l == 0 and monster_and_coin[l][0] > hero_power:
            return 0
        return coins_sum[r]
```

</details>
