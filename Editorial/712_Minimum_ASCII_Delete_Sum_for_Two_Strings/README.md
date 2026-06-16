# 712. Minimum ASCII Delete Sum for Two Strings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 712 - Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

## Problem

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

### Example 1

```text
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
```

### Example 2

```text
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
```

## Constraints

- 1 <= s1.length, s2.length <= 1000
- s1 and s2 consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Edit Distance](https://leetcode.com/problems/edit-distance/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 712. Minimum ASCII Delete Sum for Two Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python3 |
| Top-down Dynamic Programming | Java, Python3 |
| Bottom-up Dynamic Programming | Java, Python3 |
| Space-Optimized Bottom-up Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        
        // Call helper function for complete strings
        return computeCost(s1, s2, s1.length()-1, s2.length()-1);
    }

    // Return minimum cost to make s1[0...i] and s2[0...j] equal
    private int computeCost(String s1, String s2, int i, int j) {

        // If s1 is empty, then we need to delete all characters of s2
        if (i < 0) {
            int deleteCost = 0;
            for (int pointer = 0; pointer <= j; pointer++) {
                deleteCost += s2.charAt(pointer);
            }
            return deleteCost;
        }

        // If s2 is empty, then we need to delete all characters of s1
        if (j < 0) {
            int deleteCost = 0;
            for (int pointer = 0; pointer <= i; pointer++) {
                deleteCost += s1.charAt(pointer);
            }
            return deleteCost;
        }

        // Check s1[i] and s2[j]
        if (s1.charAt(i) == s2.charAt(j)) {
            return computeCost(s1, s2, i-1, j-1);
        } else {
            return Math.min(
                s1.charAt(i) + computeCost(s1, s2, i-1, j),
                Math.min(
                    s2.charAt(j) + computeCost(s1, s2, i, j-1),
                    s1.charAt(i) + s2.charAt(j) + computeCost(s1, s2, i-1, j-1)
                )
            );
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:

        # Return minimum cost to make s1[0...i] and s2[0...j] equal
        def compute_cost(i, j):

            # If s1 is empty, then we need to delete all characters of s2
            if i < 0:
                delete_cost = 0
                for pointer in range(j+1):
                    delete_cost += ord(s2[pointer])
                return delete_cost
            
            # If s2 is empty, then we need to delete all characters of s1
            if j < 0:
                delete_cost = 0
                for pointer in range(i+1):
                    delete_cost += ord(s1[pointer])
                return delete_cost
            
            # Check s1[i] and s2[j]
            if s1[i] == s2[j]:
                return compute_cost(i-1, j-1)
            else:
                return min(
                    ord(s1[i]) + compute_cost(i-1, j),
                    ord(s2[j]) + compute_cost(i, j-1),
                    ord(s1[i]) + ord(s2[j]) + compute_cost(i-1, j-1)
                )
        
        # Call helper function for complete strings
        return compute_cost(len(s1)-1, len(s2)-1)
```

</details>

<br>

## Approach 2: Top-down Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Hash Map to store the result of each sub-problem.
    Map<Pair<Integer, Integer>, Integer> savedResult = new HashMap<>();
        
    public int minimumDeleteSum(String s1, String s2) {
        
        // Return minimum cost to make s1[0...i] and s2[0...j] equal
        return computeCost(s1, s2, s1.length()-1, s2.length()-1);
    }

    private int computeCost(String s1, String s2, int i, int j) {

        // If both strings are empty, then no deletion is required
        if (i < 0 && j < 0) {
            return 0;
        }

        // If already computed, then return the result from the hash map
        Pair<Integer, Integer> key = new Pair<>(i, j);
        if (savedResult.containsKey(key)) {
            return savedResult.get(key);
        }
        
        // If any one string is empty, delete all characters of the other string
        if (i < 0) {
            savedResult.put(key, s2.charAt(j) + computeCost(s1, s2, i, j-1));
            return savedResult.get(key);
        }
        if (j < 0) {
            savedResult.put(key, s1.charAt(i) + computeCost(s1, s2, i-1, j));
            return savedResult.get(key);
        }
        
        // Call sub-problem depending on s1[i] and s2[j]
        // Save the computed result.
        if (s1.charAt(i) == s2.charAt(j)) {
            savedResult.put(key, computeCost(s1, s2, i-1, j-1));
        } else {
            savedResult.put(key, Math.min(
                s1.charAt(i) + computeCost(s1, s2, i-1, j),
                s2.charAt(j) + computeCost(s1, s2, i, j-1)
            ));
        }
        return savedResult.get(key);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
    
        # Dictionary to store the result of each sub-problem
        saved_result = {}

        # Return minimum cost to make s1[0...i] and s2[0...j] equal
        def compute_cost(i, j):

            # If both strings are empty, then no deletion is required
            if i < 0 and j < 0:
                return 0
            
            # If already computed, then return the result from the dictionary
            if (i, j) in saved_result:
                return saved_result[(i, j)]
            
            # If any one string is empty, delete all characters of the other string
            if i < 0:
                saved_result[(i, j)] = ord(s2[j]) + compute_cost(i, j-1)
                return saved_result[(i, j)]
            if j < 0:
                saved_result[(i, j)] = ord(s1[i]) + compute_cost(i-1, j)
                return saved_result[(i, j)]
            
            # Call sub-problem depending on s1[i] and s2[j]
            # Save the computed result.
            if s1[i] == s2[j]:
                saved_result[(i, j)] = compute_cost(i-1, j-1)
            else:
                saved_result[(i, j)] = min(
                    ord(s1[i]) + compute_cost(i-1, j),
                    ord(s2[j]) + compute_cost(i, j-1)
                )

            return saved_result[(i, j)]

        # Return the result of the main problem
        return compute_cost(len(s1)-1, len(s2)-1)
```

</details>

<br>

## Approach 3: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        
        // Prepare the two-dimensional array
        int m = s1.length(), n = s2.length();
        int[][] computeCost = new int[m + 1][n + 1];

        // Fill in the base case values
        for (int i = 1; i <= m; i++) {
            computeCost[i][0] = computeCost[i-1][0] + s1.charAt(i-1);
        }
        for (int j = 1; j <= n; j++) {
            computeCost[0][j] = computeCost[0][j-1] + s2.charAt(j-1);
        }
        
        // Fill the remaining cells using the Bellman Equation
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    computeCost[i][j] = computeCost[i-1][j-1];
                } else {
                    computeCost[i][j] = Math.min(
                        s1.charAt(i-1) + computeCost[i-1][j],
                        s2.charAt(j-1) + computeCost[i][j-1]
                    );
                }
            }
        }
        
        // Return the answer for entire input strings
        return computeCost[m][n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        # Prepare the two-dimensional array
        m, n = len(s1), len(s2)
        compute_cost = [[0] * (n + 1) for _ in range(m + 1)]

        # Fill the base case values
        for i in range(1, m + 1):
            compute_cost[i][0] = compute_cost[i-1][0] + ord(s1[i-1])
        for j in range(1, n + 1):
            compute_cost[0][j] = compute_cost[0][j-1] + ord(s2[j-1])
        
        # Fill the remaining cells using the Bellman Equation
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i-1] == s2[j-1]:
                    compute_cost[i][j] = compute_cost[i-1][j-1]
                else:
                    compute_cost[i][j] = min(
                        ord(s1[i-1]) + compute_cost[i-1][j],
                        ord(s2[j-1]) + compute_cost[i][j-1]
                    )
        
        # Return the answer for entire input strings
        return compute_cost[m][n]
```

</details>

<br>

## Approach 4: Space-Optimized Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumDeleteSum(char * s1, char * s2){
    
    // Make sure s2 is smaller string
    if (strlen(s1) < strlen(s2)) {
        return minimumDeleteSum(s2, s1);
    }
    
    // Case for empty s1
    int m = strlen(s1), n = strlen(s2);
    int *currRow = malloc((n + 1) * sizeof(int));
    currRow[0] = 0;
    for (int j = 1; j <= n; j++) {
        currRow[j] = currRow[j - 1] + s2[j - 1];
    }
    
    // Compute answer row-by-row
    for (int i = 1; i <= m; i++) {
        
        int diag = currRow[0];
        currRow[0] += s1[i - 1];
        
        for (int j = 1; j <= n; j++) {

            int answer;
            
            // If characters are the same, the answer is top-left-diagonal value
            if (s1[i - 1] == s2[j - 1]) {
                answer = diag;
            }
            
            // Otherwise, the answer is minimum of top and left values with
            // deleted character's ASCII value
            else {
                answer = fmin(
                    s1[i - 1] + currRow[j],
                    s2[j - 1] + currRow[j - 1]
                );
            }
            
            // Before overwriting currRow[j] with answer, save it in diag
            // for the next column
            diag = currRow[j];
            currRow[j] = answer;
        }
    }
    
    // Return the answer
    return currRow[n];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        // Make sure s2 is smaller string
        if (s1.length() < s2.length()) {
            return minimumDeleteSum(s2, s1);
        }
        
        // Case for empty s1
        int m = s1.length(), n = s2.length();
        vector<int> currRow(n + 1);
        for (int j = 1; j <= n; j++) {
            currRow[j] = currRow[j - 1] + s2[j - 1];
        }
        
        // Compute answer row-by-row
        for (int i = 1; i <= m; i++) {
            
            int diag = currRow[0];
            currRow[0] += s1[i - 1];
            
            for (int j = 1; j <= n; j++) {

                int answer;
                
                // If characters are the same, the answer is top-left-diagonal value
                if (s1[i - 1] == s2[j - 1]) {
                    answer = diag;
                }
                
                // Otherwise, the answer is minimum of top and left values with
                // deleted character's ASCII value
                else {
                    answer = min(
                        s1[i - 1] + currRow[j],
                        s2[j - 1] + currRow[j - 1]
                    );
                }
                
                // Before overwriting currRow[j] with answer, save it in diag
                // for the next column
                diag = currRow[j];
                currRow[j] = answer;
            }
        }
        
        // Return the answer
        return currRow[n];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumDeleteSum(string s1, string s2) {
        
        // Make sure s2 is smaller string
        if (s1.Length < s2.Length) {
            return MinimumDeleteSum(s2, s1);
        }
        
        // Case for empty s1
        int m = s1.Length, n = s2.Length;
        int[] currRow = new int[n + 1];
        for (int j = 1; j <= n; j++) {
            currRow[j] = currRow[j - 1] + s2[j - 1];
        }
        
        // Compute answer row-by-row
        for (int i = 1; i <= m; i++) {
            
            int diag = currRow[0];
            currRow[0] += s1[i - 1];
            
            for (int j = 1; j <= n; j++) {

                int answer;
                
                // If characters are the same, the answer is top-left-diagonal value
                if (s1[i - 1] == s2[j - 1]) {
                    answer = diag;
                }
                
                // Otherwise, the answer is minimum of top and left values with
                // deleted character's ASCII value
                else {
                    answer = Math.Min(
                        s1[i - 1] + currRow[j],
                        s2[j - 1] + currRow[j - 1]
                    );
                }
                
                // Before overwriting currRow[j] with answer, save it in diag
                // for the next column
                diag = currRow[j];
                currRow[j] = answer;
            }
        }
        
        // Return the answer
        return currRow[n];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumDeleteSum(s1 string, s2 string) int {
    
    // Make sure s2 is smaller string
    if len(s1) < len(s2) {
        return minimumDeleteSum(s2, s1)
    }
    
    // Case for empty s1
    m, n := len(s1), len(s2)
    currRow := make([]int, n + 1)
    for j := 1; j <= n; j++ {
        currRow[j] = currRow[j - 1] + int(s2[j - 1])
    }
    
    // Compute answer row-by-row
    for i := 1; i <= m; i++ {
        
        diag := currRow[0]
        currRow[0] += int(s1[i - 1])
        
        for j := 1; j <= n; j++ {

            var answer int
            
            // If characters are the same, the answer is top-left-diagonal value
            if s1[i - 1] == s2[j - 1] {
                answer = diag
            } else {
                answer = int(math.Min(
                    float64(s1[i - 1]) + float64(currRow[j]),
                    float64(s2[j - 1]) + float64(currRow[j - 1]),
                ))
            }
            
            // Before overwriting currRow[j] with answer, save it in diag
            // for the next column
            diag = currRow[j]
            currRow[j] = answer
        }
    }
    
    // Return the answer
    return currRow[n]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        
        // Make sure s2 is smaller string
        if (s1.length() < s2.length()) {
            return minimumDeleteSum(s2, s1);
        }
        
        // Case for empty s1
        int m = s1.length(), n = s2.length();
        int[] currRow = new int[n + 1];
        for (int j = 1; j <= n; j++) {
            currRow[j] = currRow[j - 1] + s2.charAt(j - 1);
        }
        
        // Compute answer row-by-row
        for (int i = 1; i <= m; i++) {
            
            int diag = currRow[0];
            currRow[0] += s1.charAt(i - 1);
            
            for (int j = 1; j <= n; j++) {

                int answer;
                
                // If characters are the same, the answer is top-left-diagonal value
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    answer = diag;
                }
                
                // Otherwise, the answer is minimum of top and left values with
                // deleted character's ASCII value
                else {
                    answer = Math.min(
                        s1.charAt(i - 1) + currRow[j],
                        s2.charAt(j - 1) + currRow[j - 1]
                    );
                }
                
                // Before overwriting currRow[j] with answer, save it in diag
                // for the next column
                diag = currRow[j];
                currRow[j] = answer;
            }
        }
        
        // Return the answer
        return currRow[n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumDeleteSum = function(s1, s2) {
    
    // Make sure s2 is smaller string
    if (s1.length < s2.length) {
        return minimumDeleteSum(s2, s1);
    }
    
    // Case for empty s1
    let m = s1.length, n = s2.length;
    let currRow = new Array(n + 1);
    currRow[0] = 0;
    for (let j = 1; j <= n; j++) {
        currRow[j] = currRow[j - 1] + s2[j - 1].charCodeAt(0);
    }
    
    // Compute answer row-by-row
    for (let i = 1; i <= m; i++) {
        
        let diag = currRow[0];
        currRow[0] += s1[i - 1].charCodeAt(0);
        
        for (let j = 1; j <= n; j++) {

            let answer;
            
            // If characters are the same, the answer is top-left-diagonal value
            if (s1[i - 1] == s2[j - 1]) {
                answer = diag;
            }
            
            // Otherwise, the answer is minimum of top and left values with
            // deleted character's ASCII value
            else {
                answer = Math.min(
                    s1[i - 1].charCodeAt(0) + currRow[j],
                    s2[j - 1].charCodeAt(0) + currRow[j - 1]
                );
            }
            
            // Before overwriting currRow[j] with answer, save it in diag
            // for the next column
            diag = currRow[j];
            currRow[j] = answer;
        }
    }
    
    // Return the answer
    return currRow[n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        # Make sure s2 is smaller string
        if len(s1) < len(s2):
            return self.minimumDeleteSum(s1 = s2, s2 = s1)
        
        # Case for empty s1
        m, n = len(s1), len(s2)
        curr_row = [0] * (n + 1)
        for j in range(1, n + 1):
            curr_row[j] = curr_row[j - 1] + ord(s2[j - 1])
        
        # Compute answer row-by-row
        for i in range(1, m + 1):
            
            diag = curr_row[0]
            curr_row[0] += ord(s1[i - 1])

            for j in range(1, n + 1):
                
                # If characters are the same, the answer is top-left-diagonal value
                if s1[i - 1] == s2[j - 1]:
                    answer = diag
                
                # Otherwise, the answer is minimum of top and left values with
                # deleted character's ASCII value
                else:
                    answer = min(
                        ord(s1[i - 1]) + curr_row[j],
                        ord(s2[j - 1]) + curr_row[j - 1]
                    )

                # Before overwriting curr_row[j] with the answer, save it in diag
                # for the next column
                diag = curr_row[j]
                curr_row[j] = answer
        
        # Return answer
        return curr_row[-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumDeleteSum(s1: string, s2: string): number {
    // Make sure s2 is smaller string
    if (s1.length < s2.length) {
        return minimumDeleteSum(s2, s1);
    }

    // Case for empty s1
    const m = s1.length;
    const n = s2.length;
    let currRow = new Array(n + 1).fill(0);
    for (let j = 1; j <= n; j++) {
        currRow[j] = currRow[j - 1] + s2.charCodeAt(j - 1);
    }

    // Compute answer row-by-row
    for (let i = 1; i <= m; i++) {

        let diag = currRow[0];
        currRow[0] += s1.charCodeAt(i - 1);

        for (let j = 1; j <= n; j++) {

            let answer = 0;

            // If characters are the same, the answer is top-left-diagonal value
            if (s1[i - 1] == s2[j - 1]) {
                answer = diag;
            }

            // Otherwise, the answer is minimum of top and left values with
            // deleted character's ASCII value
            else {
                answer = Math.min(
                    s1.charCodeAt(i - 1) + currRow[j],
                    s2.charCodeAt(j - 1) + currRow[j - 1]
                );
            }

            // Before overwriting currRow[j] with answer, save it in diag
            // for the next column
            diag = currRow[j];
            currRow[j] = answer;
        }
    }

    // Return the answer
    return currRow[n];
};
```

</details>
