# 2491. Divide Players Into Teams of Equal Skill

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/)  
`Array` `Hash Table` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 2491 - Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/)

## Problem

You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

### Example 1

```text
Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation:
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
```

### Example 2

```text
Input: skill = [3,4]
Output: 12
Explanation:
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
```

### Example 3

```text
Input: skill = [1,1,2,3]
Output: -1
Explanation:
There is no way to divide the players into teams such that the total skill of each team is equal.
```

## Constraints

- 2 <= skill.length <= 105
- skill.length is even.
- 1 <= skill[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Max Number of K-Sum Pairs](https://leetcode.com/problems/max-number-of-k-sum-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2491. Divide Players Into Teams of Equal Skill

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Frequency Table | C++, Java, Python3 |
| Map | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int n = skill.size();
        long long totalChemistry = 0;

        // Calculate the target sum
        int targetTeamSkill = skill[0] + skill[n - 1];

        // Iterate through half of the array, pairing players from both ends
        for (int i = 0; i < n / 2; i++) {
            int currentTeamSkill = skill[i] + skill[n - i - 1];

            // If any team's skill doesn't match the target, return -1
            if (currentTeamSkill != targetTeamSkill) {
                return -1;
            }

            // Calculate and add the chemistry of the current team
            totalChemistry += (long long)skill[i] * (long long)skill[n - i - 1];
        }

        return totalChemistry;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);

        int n = skill.length;
        long totalChemistry = 0;

        // Calculate the target sum
        int targetTeamSkill = skill[0] + skill[n - 1];

        // Iterate through half of the array, pairing players from both ends
        for (int i = 0; i < n / 2; i++) {
            int currentTeamSkill = skill[i] + skill[n - i - 1];

            // If any team's skill doesn't match the target, return -1
            if (currentTeamSkill != targetTeamSkill) {
                return -1;
            }

            // Calculate and add the chemistry of the current team
            totalChemistry += (long) skill[i] * (long) skill[n - i - 1];
        }

        return totalChemistry;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        n = len(skill)
        total_chemistry = 0

        # Calculate the target sum
        target_team_skill = skill[0] + skill[-1]

        # Iterate through half of the array, pairing players from both ends
        for i in range(n // 2):
            # If any team's skill doesn't match the target, return -1
            if skill[i] + skill[-i - 1] != target_team_skill:
                return -1

            # Calculate and add the chemistry of the current team
            total_chemistry += skill[i] * skill[-i - 1]

        return total_chemistry
```

</details>

<br>

## Approach 2: Frequency Table

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        vector<int> skillFrequency(2001, 0);

        // Calculate total skill and skill frequency
        for (int playerSkill : skill) {
            totalSkill += playerSkill;
            skillFrequency[playerSkill]++;
        }

        // Check if total skill can be evenly distributed among teams
        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetTeamSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;

        // Calculate total chemistry while verifying valid team formations
        for (int playerSkill : skill) {
            int partnerSkill = targetTeamSkill - playerSkill;

            // Check if a valid partner exists
            if (skillFrequency[partnerSkill] == 0) {
                return -1;
            }

            totalChemistry += (long long)playerSkill * (long long)partnerSkill;
            skillFrequency[partnerSkill]--;
        }

        // Return half of totalChemistry as each pair is counted twice
        return totalChemistry / 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long dividePlayers(int[] skill) {
        int n = skill.length;
        int totalSkill = 0;
        int[] skillFrequency = new int[2001];

        // Calculate total skill and skill frequency
        for (int playerSkill : skill) {
            totalSkill += playerSkill;
            skillFrequency[playerSkill]++;
        }

        // Check if total skill can be evenly distributed among teams
        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetTeamSkill = totalSkill / (n / 2);
        long totalChemistry = 0;

        // Calculate total chemistry while verifying valid team formations
        for (int playerSkill : skill) {
            int partnerSkill = targetTeamSkill - playerSkill;

            // Check if a valid partner exists
            if (skillFrequency[partnerSkill] == 0) {
                return -1;
            }

            totalChemistry += (long) playerSkill * (long) partnerSkill;
            skillFrequency[partnerSkill]--;
        }

        // Return half of totalChemistry as each pair is counted twice
        return totalChemistry / 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        total_skill = sum(skill)
        skill_frequency = [0] * 2001

        # Calculate total skill and skill frequency
        for player_skill in skill:
            skill_frequency[player_skill] += 1

        # Check if total skill can be evenly distributed among teams
        if total_skill % (n // 2) != 0:
            return -1

        target_team_skill = total_skill // (n // 2)
        total_chemistry = 0

        # Calculate total chemistry while verifying valid team formations
        for player_skill in skill:
            partner_skill = target_team_skill - player_skill

            # Check if a valid partner exists
            if skill_frequency[partner_skill] == 0:
                return -1

            # Calculate and add chemistry of the current pair
            total_chemistry += player_skill * partner_skill
            skill_frequency[partner_skill] -= 1

        # Return half of total_chemistry as each pair is counted twice
        return total_chemistry // 2
```

</details>

<br>

## Approach 3: Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        unordered_map<int, int> skillMap;

        // Calculate total skill and build frequency map
        for (int s : skill) {
            totalSkill += s;
            skillMap[s] = skillMap[s] + 1;
        }

        // Check if total skill can be evenly distributed among teams
        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;

        // Iterate through unique skill values
        for (auto& [currSkill, currFreq] : skillMap) {
            int partnerSkill = targetSkill - currSkill;

            // Check if valid partner skill exists with matching frequency
            if (skillMap.find(partnerSkill) == skillMap.end() ||
                currFreq != skillMap[partnerSkill]) {
                return -1;
            }

            // Calculate chemistry for all pairs with this skill
            totalChemistry += (long long)currSkill * (long long)partnerSkill *
                              (long long)currFreq;
        }

        // Return half of total chemistry (as each pair is counted twice)
        return totalChemistry / 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long dividePlayers(int[] skill) {
        int n = skill.length;
        int totalSkill = 0;
        Map<Integer, Integer> skillMap = new HashMap<>();

        // Calculate total skill and build frequency map
        for (int s : skill) {
            totalSkill += s;
            skillMap.put(s, skillMap.getOrDefault(s, 0) + 1);
        }

        // Check if total skill can be evenly distributed among teams
        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetSkill = totalSkill / (n / 2);
        long totalChemistry = 0;

        // Iterate through unique skill values
        for (int currSkill : skillMap.keySet()) {
            int currFreq = skillMap.get(currSkill);
            int partnerSkill = targetSkill - currSkill;

            // Check if valid partner skill exists with matching frequency
            if (
                !skillMap.containsKey(partnerSkill) ||
                currFreq != skillMap.get(partnerSkill)
            ) {
                return -1;
            }

            // Calculate chemistry for all pairs with this skill
            totalChemistry +=
            (long) currSkill * (long) partnerSkill * (long) currFreq;
        }

        // Return half of total chemistry (as each pair is counted twice)
        return totalChemistry / 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        total_skill = sum(skill)

        # Check if total skill can be evenly distributed
        if total_skill % (n // 2) != 0:
            return -1

        target_skill = total_skill // (n // 2)
        skill_map = Counter(skill)
        total_chemistry = 0

        # Iterate through unique skill values
        for curr_skill, curr_freq in skill_map.items():
            partner_skill = target_skill - curr_skill

            # Check if valid partner skill exists with matching frequency
            if (
                partner_skill not in skill_map
                or curr_freq != skill_map[partner_skill]
            ):
                return -1

            # Calculate chemistry for all pairs with this skill
            total_chemistry += curr_skill * partner_skill * curr_freq

        # Return half of total chemistry (as each pair is counted twice)
        return total_chemistry // 2
```

</details>
