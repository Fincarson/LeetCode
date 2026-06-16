# 1244. Design A Leaderboard

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/design-a-leaderboard/)  
`Hash Table` `Design` `Sorting`

**Problem Link:** [LeetCode 1244 - Design A Leaderboard](https://leetcode.com/problems/design-a-leaderboard/)

## Problem

Design a Leaderboard class, which has 3 functions:

Initially, the leaderboard is empty.

### Example 1

```text
Input:
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
Output:
[null,null,null,null,null,null,73,null,null,null,141]

Explanation:
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
```

## Constraints

- 1 <= playerId, K <= 10000
- It's guaranteed that K is less than or equal to the current number of players.
- 1 <= score <= 100
- There will be at most 1000 function calls.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1244. Design A Leaderboard

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java, Python3 |
| Heap for top-K | Java, Python3 |
| Using a TreeMap / SortedMap | Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Leaderboard {

    private HashMap<Integer, Integer> scores;
    
    public Leaderboard() {
      
        // Since this is a single threaded application and we don't need synchronized access, a 
        // HashMap is a good choice of data structure as compared to a Hashtable. Read more here:
        // https://stackoverflow.com/questions/40471/what-are-the-differences-between-a-hashmap-and-a-hashtable-in-java 
        this.scores = new HashMap<Integer, Integer>();
    }
    
    public void addScore(int playerId, int score) {
        
        if (!this.scores.containsKey(playerId)) {
            this.scores.put(playerId, 0);
        }
        
        this.scores.put(playerId, this.scores.get(playerId) + score);
    }
    
    public int top(int K) {
        
        List<Integer> values = new ArrayList<Integer>(this.scores.values());
        Collections.sort(values, Collections.reverseOrder());
        
        int total = 0;
        for (int i = 0; i < K; i++) {
            total += values.get(i);            
        }
        
        return total;
    }
    
    public void reset(int playerId) {
        this.scores.put(playerId, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Leaderboard:

    def __init__(self):
        self.scores = defaultdict()

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.scores:
            self.scores[playerId] = 0
        self.scores[playerId] += score

    def top(self, K: int) -> int:
        values = [v for _, v in sorted(self.scores.items(), key=lambda item: item[1])]
        values.sort(reverse=True)
        total, i = 0, 0
        while i < K:
            total += values[i]
            i += 1
        
        return total

    def reset(self, playerId: int) -> None:
        self.scores[playerId] = 0
```

</details>

<br>

## Approach 2: Heap for top-K

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Leaderboard {

    private HashMap<Integer, Integer> scores;
    
    public Leaderboard() {
        this.scores = new HashMap<Integer, Integer>();
    }
    
    public void addScore(int playerId, int score) {
        
        if (!this.scores.containsKey(playerId)) {
            this.scores.put(playerId, 0);
        }
        
        this.scores.put(playerId, this.scores.get(playerId) + score);
    }
    
    public int top(int K) {
        
        // A min-heap in java containing entries of a hash map. Note that we have to provide
        // a comparator of our own to make sure we get the ordering right of these objects.
        PriorityQueue<Map.Entry<Integer, Integer>> heap = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        
        for (Map.Entry<Integer, Integer> entry : this.scores.entrySet()) {
            heap.offer(entry);
            if (heap.size() > K) {
                heap.poll();
            }
        }
        
        int total = 0;
        Iterator value = heap.iterator();
        while (value.hasNext()) { 
            total += ((Map.Entry<Integer, Integer>)value.next()).getValue();   
        }
        
        return total;
    }
    
    public void reset(int playerId) {
        this.scores.put(playerId, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Leaderboard:

    def __init__(self):
        self.scores = {}

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.scores:
            self.scores[playerId] = 0
        self.scores[playerId] += score

    def top(self, K: int) -> int:
    
        # This is a min-heap by default in Python.
        heap = []
        for x in self.scores.values():
            heapq.heappush(heap, x)
            if len(heap) > K:
                heapq.heappop(heap)
        res = 0
        while heap:
            res += heapq.heappop(heap)
        return res

    def reset(self, playerId: int) -> None:
        self.scores[playerId] = 0
```

</details>

<br>

## Approach 3: Using a TreeMap / SortedMap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Leaderboard {

    Map<Integer, Integer> scores;
    TreeMap<Integer, Integer> sortedScores;
    
    public Leaderboard() {
        this.scores = new HashMap<Integer, Integer>();
        this.sortedScores = new TreeMap<>(Collections.reverseOrder());
    }
    
    public void addScore(int playerId, int score) {
        
        // The scores dictionary simply contains the mapping from the
        // playerId to their score. The sortedScores contain a BST with 
        // key as the score and value as the number of players that have
        // that score.        
        if (!this.scores.containsKey(playerId)) {
            this.scores.put(playerId, score);
            this.sortedScores.put(score, this.sortedScores.getOrDefault(score, 0) + 1);
        } else {
            
            // Since the current player's score is changing, we need to
            // update the sortedScores map to reduce count for the old
            // score.
            int preScore = this.scores.get(playerId);
            int playerCount = this.sortedScores.get(preScore);
            
            
            // If no player has this score, remov it from the tree.
            if (playerCount == 1) {
                this.sortedScores.remove(preScore);
            } else {
                this.sortedScores.put(preScore, playerCount - 1);
            }
            
            // Updated score
            int newScore = preScore + score;
            this.scores.put(playerId, newScore);
            this.sortedScores.put(newScore, this.sortedScores.getOrDefault(newScore, 0) + 1);
        }
    }
    
    public int top(int K) {
        
        int count = 0;
        int sum = 0;
        
        // In-order traversal over the scores in the TreeMap
        for (Map.Entry<Integer, Integer> entry: this.sortedScores.entrySet()) {
            
            // Number of players that have this score.
            int times = entry.getValue();
            int key = entry.getKey();
            
            for (int i = 0; i < times; i++) {
                sum += key;
                count++;
                
                // Found top-K scores, break.
                if (count == K) {
                    break;
                }
            }
            
            // Found top-K scores, break.
            if (count == K) {
                break;
            }
        }
        
        return sum;
    }
    
    public void reset(int playerId) {
        int preScore = this.scores.get(playerId);
        this.sortedScores.put(preScore, this.sortedScores.get(preScore) - 1);
        if (this.sortedScores.get(preScore) == 0) {
            this.sortedScores.remove(preScore);
        }
        
        this.scores.remove(playerId);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedDict

class Leaderboard:

    def __init__(self):
        self.scores = {}
        self.sortedScores = SortedDict()

    def addScore(self, playerId: int, score: int) -> None:

        # The scores dictionary simply contains the mapping from the
        # playerId to their score. The sortedScores contain a BST with 
        # key as the score and value as the number of players that have
        # that score.     
        if playerId not in self.scores:
            self.scores[playerId] = score
            self.sortedScores[-score] = self.sortedScores.get(-score, 0) + 1
        else:
            preScore = self.scores[playerId]
            val = self.sortedScores.get(-preScore)
            if val == 1:
                del self.sortedScores[-preScore]
            else:
                self.sortedScores[-preScore] = val - 1    
            
            newScore = preScore + score;
            self.scores[playerId] = newScore
            self.sortedScores[-newScore] = self.sortedScores.get(-newScore, 0) + 1
        
    def top(self, K: int) -> int:
        count, total = 0, 0;

        for key, value in self.sortedScores.items():
            times = self.sortedScores.get(key)
            for _ in range(times): 
                total += -key;
                count += 1;
                
                # Found top-K scores, break.
                if count == K:
                    break;
                
            # Found top-K scores, break.
            if count == K:
                break;
        
        return total;

    def reset(self, playerId: int) -> None:
        preScore = self.scores[playerId]
        if self.sortedScores[-preScore] == 1:
            del self.sortedScores[-preScore]
        else:
            self.sortedScores[-preScore] -= 1
        del self.scores[playerId];
```

</details>
