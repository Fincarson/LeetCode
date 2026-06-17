# 506. Relative Ranks

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/relative-ranks/)  
`Array` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 506 - Relative Ranks](https://leetcode.com/problems/relative-ranks/)

## Problem

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

- The 1st place athlete's rank is "Gold Medal".
- The 2nd place athlete's rank is "Silver Medal".
- The 3rd place athlete's rank is "Bronze Medal".
- For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.

### Example 1

```text
Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
```

### Example 2

```text
Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
```

## Constraints

- n == score.length
- 1 <= n <= 104
- 0 <= score[i] <= 106
- All the values in score are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 506. Relative Ranks

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort & Reverse | C++, Java, Python3 |
| Heap (Priority Queue) | C++, Java, Python3 |
| Array as Map | C++, Java, Python3 |

## Approach 1: Sort & Reverse

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int N = score.size();
        vector<int> scoreCopy(N);
        copy(score.begin(), score.end(), scoreCopy.begin());
        
        // Save the index of each athlete
        unordered_map<int, int> scoreToIndex;
        for (int i = 0; i < N; i++) {
            scoreToIndex[scoreCopy[i]] = i;
        }
        
        // Sort scoreCopy in descending order
        sort(scoreCopy.begin(), scoreCopy.end(), greater<int>());

        // Assign ranks to athletes
        vector<string> rank(N);
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                rank[scoreToIndex[scoreCopy[i]]] = "Gold Medal";
            } else if (i == 1) {
                rank[scoreToIndex[scoreCopy[i]]] = "Silver Medal";
            } else if (i == 2) {
                rank[scoreToIndex[scoreCopy[i]]] = "Bronze Medal";
            } else {
                rank[scoreToIndex[scoreCopy[i]]] = to_string(i + 1);
            }
        }
        
        return rank;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int N = score.length;
        int[] scoreCopy = new int[N];
        System.arraycopy(score, 0, scoreCopy, 0, N);
       
        // Save the index of each athlete
        Map<Integer, Integer> scoreToIndex = new HashMap<>();
        for (int i = 0; i < N; i++) {
            scoreToIndex.put(scoreCopy[i], i);
        }
        
        // Sort scoreCopy in ascending order
        Arrays.sort(scoreCopy);

        // Assign ranks to athletes
        // Traverse scoreCopy in reverse
        String[] rank = new String[N]; 
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                rank[scoreToIndex.get(scoreCopy[N - i - 1])] = "Gold Medal";
            } else if (i == 1) {
                rank[scoreToIndex.get(scoreCopy[N - i - 1])] = "Silver Medal";
            } else if (i == 2) {
                rank[scoreToIndex.get(scoreCopy[N - i - 1])] = "Bronze Medal";
            } else {
                rank[scoreToIndex.get(scoreCopy[N - i - 1])] = Integer.toString(i + 1);
            }
        }
        
        return rank;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        N = len(score)
        score_copy = score.copy()
       
        # Save the index of each athlete
        score_to_index = defaultdict(int)
        for i in range(N):
            score_to_index[score_copy[i]] = i

        # Sort score copy in descending order
        score_copy.sort(reverse = True)

        # Assign ranks to athletes
        rank = [" "] * N
        for i in range(N):
            if i == 0:
                rank[score_to_index[score_copy[i]]] = "Gold Medal"
            elif i == 1:
                rank[score_to_index[score_copy[i]]] = "Silver Medal"
            elif i == 2:
                rank[score_to_index[score_copy[i]]] = "Bronze Medal"
            else:
                rank[score_to_index[score_copy[i]]] = str(i + 1)

        return rank
```

</details>

<br>

## Approach 2: Heap (Priority Queue)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int N = score.size();

        // Create a max heap of pairs (score, index)
        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < N; i++) {
            heap.push({score[i], i});
        }

        // Assign ranks to athletes
        vector<string> rank(N);
        int place = 1;
        while (!heap.empty()) {
            int originalIndex = heap.top().second;
            heap.pop();
            if (place == 1) {
                rank[originalIndex] = "Gold Medal";
            } else if (place == 2) {
                rank[originalIndex] = "Silver Medal";
            } else if (place == 3) {
                rank[originalIndex] = "Bronze Medal";
            } else {
                rank[originalIndex] = to_string(place);
            }
            place++;
        }
        return rank;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int N = score.length;

        // Create a max heap of pairs (score, index)
        PriorityQueue<Pair<Integer, Integer>> heap = new PriorityQueue<>(
                (a, b) -> b.getKey() - a.getKey());
        for (int i = 0; i < N; i++) {
            heap.add(new Pair<>(score[i], i));
        }

        // Assign ranks to athletes
        String[] rank = new String[N];
        int place = 1;
        while (!heap.isEmpty()) {
            Pair<Integer, Integer> pair = heap.poll();
            int originalIndex = pair.getValue();
            if (place == 1) {
                rank[originalIndex] = "Gold Medal";
            } else if (place == 2) {
                rank[originalIndex] = "Silver Medal";
            } else if (place == 3) {
                rank[originalIndex] = "Bronze Medal";
            } else {
                rank[originalIndex] = String.valueOf(place);
            }
            place++;
        }
        return rank;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        N = len(score)

        # Create a heap of pairs (score, index)
        heap = []
        for index, score in enumerate(score):
            heapq.heappush(heap, (-score, index))
        
        # Assign ranks to athletes
        rank = [0] * N
        place = 1
        while heap:
            original_index = heapq.heappop(heap)[1]
            if place == 1:
                rank[original_index] = "Gold Medal"
            elif place == 2:
                rank[original_index] = "Silver Medal"
            elif place == 3:
                rank[original_index] = "Bronze Medal"
            else:
                rank[original_index] = str(place)
            place +=1
            
        return rank
```

</details>

<br>

## Approach 3: Array as Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int findMax(vector<int>& score) {
        int maxScore = 0;
        for (int s : score) {
            if (s > maxScore) {
                maxScore = s;
            }
        }
        return maxScore;
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int N = score.size();

        // Add the original index of each score to the array
        // Where the score is the key
        int M = findMax(score);
        vector<int> scoreToIndex(M + 1, 0);
        for (int i = 0; i < N; i++) {
            scoreToIndex[score[i]] = i + 1;
        }

        const vector<string> MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        // Assign ranks to athletes
        vector<string> rank(N);
        int place = 1;
        for (int i = M; i >= 0; i--) {
            if (scoreToIndex[i] != 0) {
                int originalIndex = scoreToIndex[i] - 1;
                if (place < 4) {
                    rank[originalIndex] = MEDALS[place - 1];
                } else {
                    rank[originalIndex] = to_string(place);
                }
                place++;
            }
        }
        return rank;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int findMax(int[] score) {
        int maxScore = 0;
        for (int s : score) {
            if (s > maxScore) {
                maxScore = s;
            }
        }
        return maxScore;
    }

    public String[] findRelativeRanks(int[] score) {
        int N = score.length;

        // Add the original index of each score to the array
        // Where the score is the key
        int M = findMax(score);
        int[] scoreToIndex = new int[M + 1];
        for (int i = 0; i < N; i++) {
            scoreToIndex[score[i]] = i + 1;
        }

        final String[] MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        // Assign ranks to athletes
        String[] rank = new String[N];
        int place = 1;
        for (int i = M; i >= 0; i--) {
            if (scoreToIndex[i] != 0) {
                int originalIndex = scoreToIndex[i] - 1;
                if (place < 4) {
                    rank[originalIndex] = MEDALS[place - 1];
                } else {
                    rank[originalIndex] = String.valueOf(place);
                }
                place++;
            }
        }
        return rank;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find_max(self, score):
        max_score = 0
        for s in score:
            if s > max_score :
                max_score = s
        return max_score

    def findRelativeRanks(self, score):
        N = len(score)

        # Add the original index of each score to the array
        # Where the score is the key
        M = self.find_max(score)
        score_to_index = [0] * (M + 1)
        for i in range(N):
            score_to_index[score[i]] = i + 1

        MEDALS = ["Gold Medal", "Silver Medal", "Bronze Medal"]

        # Assign ranks to athletes
        rank = [None] * N
        place = 1
        for i in range(M, -1, -1):
            if score_to_index[i] != 0:
                original_index = score_to_index[i] - 1
                if place < 4:
                    rank[original_index] = MEDALS[place - 1]
                else:
                    rank[original_index] = str(place)
                place += 1
        return rank
```

</details>
