# 1125. Smallest Sufficient Team

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/smallest-sufficient-team/)  
`Array` `Dynamic Programming` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 1125 - Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team/)

## Problem

In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

- For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

### Example 1

```text
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
```

### Example 2

```text
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
```

## Constraints

- 1 <= req_skills.length <= 16
- 1 <= req_skills[i].length <= 16
- req_skills[i] consists of lowercase English letters.
- All the strings of req_skills are unique.
- 1 <= people.length <= 60
- 0 <= people[i].length <= 16
- 1 <= people[i][j].length <= 16
- people[i][j] consists of lowercase English letters.
- All the strings of people[i] are unique.
- Every skill in people[i] is a skill in req_skills.
- It is guaranteed a sufficient team exists.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Number of Good Subsets](https://leetcode.com/problems/the-number-of-good-subsets/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Number of Work Sessions to Finish the Tasks](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Rows Covered by Columns](https://leetcode.com/problems/maximum-rows-covered-by-columns/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1125. Smallest Sufficient Team

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-Up Dynamic Programming with Bitmasks | C++, Java, Python3 |
| Top-Down Dynamic Programming (Memoization) | C++, Java, Python3 |

## Approach 1: Bottom-Up Dynamic Programming with Bitmasks

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(), m = req_skills.size();
        unordered_map<string, int> skillId;
        for (int i = 0; i < m; i++) {
            skillId[req_skills[i]] = i;
        }
        vector<int> skillsMaskOfPerson(n);
        for (int i = 0; i < n; i++) {
            for (string skill : people[i]) {
                skillsMaskOfPerson[i] |= 1 << skillId[skill];
            }
        }
        vector<long long> dp(1 << m, (1LL << n) - 1);
        dp[0] = 0;
        for (int skillsMask = 1; skillsMask < (1 << m); skillsMask++) {
            for (int i = 0; i < n; i++) {
                int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
                if (smallerSkillsMask != skillsMask) {
                    long long peopleMask = dp[smallerSkillsMask] | (1LL << i);
                    if (__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
        }
        long long answerMask = dp[(1 << m) - 1];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((answerMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n = people.size(), m = req_skills.length;
        HashMap<String, Integer> skillId = new HashMap<String, Integer>();
        for (int i = 0; i < m; i++) {
            skillId.put(req_skills[i], i);
        }
        int skillsMaskOfPerson[] = new int[n];
        for (int i = 0; i < n; i++) {
            for (String skill : people.get(i)) {
                skillsMaskOfPerson[i] |= 1 << skillId.get(skill);
            }
        }
        long dp[] = new long [1 << m];
        Arrays.fill(dp, (1L << n) - 1);
        dp[0] = 0;
        for (int skillsMask = 1; skillsMask < (1 << m); skillsMask++) {
            for (int i = 0; i < n; i++) {
                int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
                if (smallerSkillsMask != skillsMask) {
                    long peopleMask = dp[smallerSkillsMask] | (1L << i);
                    if (Long.bitCount(peopleMask) < Long.bitCount(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
        }
        long answerMask = dp[(1 << m) - 1];
        int ans[] = new int [Long.bitCount(answerMask)];
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (((answerMask >> i) & 1) == 1) {
                ans[ptr++] = i;
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
class Solution:
    def smallestSufficientTeam(self, req_skills: List[str],
                               people: List[List[str]]) -> List[int]:
        n = len(people)
        m = len(req_skills)
        skill_id = dict()
        for i, skill in enumerate(req_skills):
            skill_id[skill] = i
        skills_mask_of_person = [0] * n
        for i in range(n):
            for skill in people[i]:
                skills_mask_of_person[i] |= 1 << skill_id[skill]
        dp = [(1 << n) - 1] * (1 << m)
        dp[0] = 0
        for skills_mask in range(1, 1 << m):
            for i in range(n):
                smaller_skills_mask = skills_mask & ~skills_mask_of_person[i]
                if smaller_skills_mask != skills_mask:
                    people_mask = dp[smaller_skills_mask] | (1 << i)
                    if people_mask.bit_count() < dp[skills_mask].bit_count():
                        dp[skills_mask] = people_mask

        answer_mask = dp[(1 << m) - 1]
        ans = []
        for i in range(n):
            if (answer_mask >> i) & 1:
                ans.append(i)
        return ans
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(), m = req_skills.size();
        unordered_map<string, int> skillId;
        for (int i = 0; i < m; i++) {
            skillId[req_skills[i]] = i;
        }
        vector<int> skillsMaskOfPerson(n);
        vector<long long> dp(1 << m, -1);
        for (int i = 0; i < n; i++) {
            for (string skill : people[i]) {
                skillsMaskOfPerson[i] |= 1 << skillId[skill];
            }
        }
        function<long long(int)> f = [&](int skillsMask) -> long long {
            if (skillsMask == 0) {
                return 0;
            }
            if (dp[skillsMask] != -1) {
                return dp[skillsMask];
            }
            for (int i = 0; i < n; i++) {
                int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
                if (smallerSkillsMask != skillsMask) {
                    long long peopleMask = f(smallerSkillsMask) | (1LL << i);
                    if (dp[skillsMask] == -1 || __builtin_popcountll(peopleMask) <
                                                    __builtin_popcountll(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
            return dp[skillsMask];
        };
        long long answerMask = f((1 << m) - 1);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((answerMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int n;
    int skillsMaskOfPerson[];
    long dp[];
    private Long f(int skillsMask) {
        if (skillsMask == 0) {
            return 0L;
        }
        if (dp[skillsMask] != -1) {
            return dp[skillsMask];
        }
        for (int i = 0; i < n; i++) {
            int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
            if (smallerSkillsMask != skillsMask) {
                long peopleMask = f(smallerSkillsMask) | (1L << i);
                if (dp[skillsMask] == -1 || Long.bitCount(peopleMask) <
                                                Long.bitCount(dp[skillsMask])) {
                    dp[skillsMask] = peopleMask;
                }
            }
        }
        return dp[skillsMask];
    }
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        n = people.size();
        int m = req_skills.length;
        HashMap<String, Integer> skillId = new HashMap<String, Integer>();
        for (int i = 0; i < m; i++) {
            skillId.put(req_skills[i], i);
        }
        skillsMaskOfPerson = new int[n];
        for (int i = 0; i < n; i++) {
            for (String skill : people.get(i)) {
                skillsMaskOfPerson[i] |= 1 << skillId.get(skill);
            }
        }
        dp = new long [1 << m];
        Arrays.fill(dp, -1);
        long answerMask = f((1 << m) - 1);
        int ans[] = new int [Long.bitCount(answerMask)];
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (((answerMask >> i) & 1) == 1) {
                ans[ptr++] = i;
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
class Solution:
    def smallestSufficientTeam(self, req_skills: List[str],
                               people: List[List[str]]) -> List[int]:
        n = len(people)
        m = len(req_skills)
        skill_id = dict()
        for i, skill in enumerate(req_skills):
            skill_id[skill] = i
        skills_mask_of_person = [0] * n
        for i in range(n):
            for skill in people[i]:
                skills_mask_of_person[i] |= 1 << skill_id[skill]
        dp = [-1] * (1 << m)
        dp[0] = 0

        def f(skills_mask):
            if dp[skills_mask] != -1:
                return dp[skills_mask]
            for i in range(n):
                new_skills_mask = skills_mask & ~skills_mask_of_person[i]
                if new_skills_mask != skills_mask:
                    people_mask = f(new_skills_mask) | (1 << i)
                    if (dp[skills_mask] == -1 or
                        people_mask.bit_count()
                       < dp[skills_mask].bit_count()):
                        dp[skills_mask] = people_mask
            return dp[skills_mask]
        answer_mask = f((1 << m) - 1)
        ans = []
        for i in range(n):
            if (answer_mask >> i) & 1:
                ans.append(i)
        return ans
```

</details>
