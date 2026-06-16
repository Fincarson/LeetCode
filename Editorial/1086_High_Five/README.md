# 1086. High Five

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/high-five/)  
`Array` `Hash Table` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 1086 - High Five](https://leetcode.com/problems/high-five/)

## Problem

Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score from a student with IDi, calculate each student's top five average.

Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.

A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using integer division.

### Example 1

```text
Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation:
The student with ID = 1 got scores 91, 92, 60, 65, 87, and 100. Their top five average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division their average converts to 88.
```

### Example 2

```text
Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
Output: [[1,100],[7,100]]
```

## Constraints

- 1 <= items.length <= 1000
- items[i].length == 2
- 1 <= IDi <= 1000
- 0 <= scorei <= 100
- For each IDi, there will be at least five scores.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Determine the Winner of a Bowling Game](https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1086. High Five

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Sorting | C++, Java |
| Using Map and Max Heap | C++, Java |
| Using Map and Min Heap | C++, Java |

## Approach 1: Using Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int K;

public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        this->K = 5;
        // sort items using the custom comparator      
        sort(items.begin(), items.end(),
            [](const vector<int> &a, const vector<int> &b) {
                if (a[0] != b[0])
                // item with lower id goes first
                return a[0] < b[0];
                // in case of tie for ids, item with higher score goes first 
                return a[1] > b[1];
            });
        vector<vector<int>> solution;
        int n = items.size();
        int i = 0;
        while (i < n) {
            int id = items[i][0];
            int sum = 0;
            // obtain total using the top 5 scores
            for (int k = i; k < i + this->K; ++k)
                sum += items[k][1];
            // ignore all the other scores for the same id
            while (i < n && items[i][0] == id)
                i++;
            solution.push_back({id, sum / this->K});
        }
        return solution;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int K;

    public int[][] highFive(int[][] items) {
        this.K = 5;
        Arrays.sort(
                items,
                new Comparator<int[]>() {
                    @Override
                    public int compare(int[] a, int[] b) {
                        if (a[0] != b[0])
                            // item with lower id goes first
                            return a[0] - b[0];
                        // in case of tie for ids, item with higher score goes first
                        return b[1] - a[1];
                    }
                });
        List<int[]> solution = new ArrayList<>();
        int n = items.length;
        int i = 0;
        while (i < n) {
            int id = items[i][0];
            int sum = 0;
            // obtain total using the top 5 scores
            for (int k = i; k < i + this.K; ++k)
                sum += items[k][1];
            // ignore all the other scores for the same id
            while (i < n && items[i][0] == id)
                i++;
            solution.add(new int[] {id, sum / this.K});
        }
        int[][] solutionArray = new int[solution.size()][];
        return solution.toArray(solutionArray);
    }
}
```

</details>

<br>

## Approach 2: Using Map and Max Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int K;

public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        this->K = 5;
        map<int, priority_queue<int>> allScores;
        for (const auto &item: items) {
            int id = item[0];
            int score = item[1];
            // Add score to the max heap
            allScores[id].push(score);
        }
        vector<vector<int>> solution;
        for (auto &[id, scores] : allScores) {
            int sum = 0;
            // obtain the top k scores (k = 5)
            for (int i = 0; i < this->K; ++i) {
                sum += scores.top();
                scores.pop();
            }
            solution.push_back({id, sum / this->K});
        }
        return solution;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int K;

    public int[][] highFive(int[][] items) {
        this.K = 5;
        TreeMap<Integer, Queue<Integer>> allScores = new TreeMap<>();
        for (int[] item : items) {
            int id = item[0];
            int score = item[1];
            if (!allScores.containsKey(id))
                // max heap
                allScores.put(id, new PriorityQueue<>((a,b) -> b - a));
            // Add score to the max heap
            allScores.get(id).add(score);
        }

        List<int[]> solution = new ArrayList<>();

        for (int id : allScores.keySet()) {
            int sum = 0;
            // obtain the top k scores (k = 5)
            for (int i = 0; i < this.K; ++i)
                sum += allScores.get(id).poll();
            solution.add(new int[] {id, sum / this.K});
        }
        int[][] solutionArray = new int[solution.size()][];
        return solution.toArray(solutionArray);
    }
}
```

</details>

<br>

## Approach 3: Using Map and Min Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int K;

public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        this->K = 5;
        map<int, priority_queue<int, vector<int>, greater<int>>> allScores;
        for (const auto &item: items) {
            int id = item[0];
            int score = item[1];
            // insert the score in the min heap
            allScores[id].push(score);
            // remove the minimum element from the min heap in case the size of the min heap exceeds 5 
            if (allScores[id].size() > this->K)
                allScores[id].pop();
        }
        vector<vector<int>> solution;
        for (auto &[id, top_scores]: allScores) {
            int total = 0;
            // min heap contains the top 5 scores
            for (int i = 0; i < this->K; ++i) {
                total += top_scores.top();
                top_scores.pop();
            }
            solution.push_back({id, total / this->K});
        }
        return solution;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int K;

    public int[][] highFive(int[][] items) {
        this.K = 5;
        TreeMap<Integer, Queue<Integer>> allScores = new TreeMap<>();
        for (int[] item : items) {
            int id = item[0];
            int score = item[1];
            if (!allScores.containsKey(id))
                allScores.put(id, new PriorityQueue<>());
            // insert the score in the min heap
            allScores.get(id).add(score);
            // remove the minimum element from the min heap in case the size of the min heap exceeds 5 
            if (allScores.get(id).size() > this.K)
                allScores.get(id).poll();
        }

        List<int[]> solution = new ArrayList<>();

        for (int id : allScores.keySet()) {
            int sum = 0;
            // min heap contains the top 5 scores
            for (int i = 0; i < this.K; ++i)
                sum += allScores.get(id).poll();
            solution.add(new int[] {id, sum / this.K});
        }
        int[][] solutionArray = new int[solution.size()][];
        return solution.toArray(solutionArray);
    }
}
```

</details>
