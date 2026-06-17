# 2147. Number of Ways to Divide a Long Corridor

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/)  
`Math` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 2147 - Number of Ways to Divide a Long Corridor](https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/)

## Problem

Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.

### Example 1

```text
Input: corridor = "SSPPSPS"
Output: 3
Explanation: There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, each section has exactly two seats.
```

### Example 2

```text
Input: corridor = "PPSPSP"
Output: 1
Explanation: There is only 1 way to divide the corridor, by not installing any additional dividers.
Installing any would create some section that does not have exactly two seats.
```

### Example 3

```text
Input: corridor = "S"
Output: 0
Explanation: There is no way to divide the corridor because there will always be a section that does not have exactly two seats.
```

## Constraints

- n == corridor.length
- 1 <= n <= 105
- corridor[i] is either 'S' or 'P'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Decode Ways II](https://leetcode.com/problems/decode-ways-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Ways to Split Array Into Three Subarrays](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2147. Number of Ways to Divide a Long Corridor

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C, C++, Java, JavaScript, Python3 |
| Bottom-up Dynamic Programming | C, C++, Java, JavaScript, Python3 |
| Space-Optimized Bottom-up Dynamic Programming | C, C++, Java, JavaScript, Python3 |
| Combinatorics | C, C++, Java, JavaScript, Python3 |
| Combinatorics, Space Optimized | C, C++, Java, JavaScript, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Count the number of ways to divide from "index" to the last index
// with "seats" number of "S" in the current section
int count(int index, int seats, char * corridor, int cache[][3]) {
    // If we have reached the end of the corridor, then
    // the current section is valid only if "seats" is 2
    if (index == strlen(corridor)) {
        return seats == 2 ? 1 : 0;
    }

    // If we have already computed the result of this sub-problem,
    // then return the cached result
    if (cache[index][seats] != -1) {
        return cache[index][seats];
    }

    // Result of the sub-problem
    int result = 0;

    // If the current section has exactly 2 "S"
    if (seats == 2) {
        // If the current element is "S", then we have to close the
        // section and start a new section from this index. Next index
        // will have one "S" in the current section
        if (corridor[index] == 'S') {
            result = count(index + 1, 1, corridor, cache);
        } else {
            // If the current element is "P", then we have two options
            // 1. Close the section and start a new section from this index
            // 2. Keep growing the section
            result = (count(index + 1, 0, corridor, cache) + count(index + 1, 2, corridor, cache)) % 1000000007;  
        }
    } else {
        // Keep growing the section. Increment "seats" if present
        // element is "S"
        if (corridor[index] == 'S') {
            result = count(index + 1, seats + 1, corridor, cache);
        } else {
            result = count(index + 1, seats, corridor, cache);
        }
    }

    // Memoize the result, and return it
    cache[index][seats] = result;
    return cache[index][seats];
}

int numberOfWays(char * corridor){
    // Cache the result of each sub-problem
    int cache[strlen(corridor)][3];
    memset(cache, -1, sizeof(cache));

    // Call the count function
    return count(0, 0, corridor, cache);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Store 1000000007 in a variable for convenience
    const int MOD = 1e9 + 7;
    
    // Count the number of ways to divide from "index" to the last index
    // with "seats" number of "S" in the current section
    int count(int index, int seats, string& corridor, int cache[][3]) {
        // If we have reached the end of the corridor, then
        // the current section is valid only if "seats" is 2
        if (index == corridor.length()) {
            return seats == 2 ? 1 : 0;
        }

        // If we have already computed the result of this sub-problem,
        // then return the cached result
        if (cache[index][seats] != -1) {
            return cache[index][seats];
        }

        // Result of the sub-problem
        int result = 0;

        // If the current section has exactly 2 "S"
        if (seats == 2) {
            // If the current element is "S", then we have to close the
            // section and start a new section from this index. Next index
            // will have one "S" in the current section
            if (corridor[index] == 'S') {
                result = count(index + 1, 1, corridor, cache);
            } else {
                // If the current element is "P", then we have two options
                // 1. Close the section and start a new section from this index
                // 2. Keep growing the section
                result = (count(index + 1, 0, corridor, cache) + count(index + 1, 2, corridor, cache)) % MOD;  
            }
        } else {
            // Keep growing the section. Increment "seats" if present
            // element is "S"
            if (corridor[index] == 'S') {
                result = count(index + 1, seats + 1, corridor, cache);
            } else {
                result = count(index + 1, seats, corridor, cache);
            }
        }

        // Memoize the result, and return it
        cache[index][seats] = result;
        return cache[index][seats];
    }

    int numberOfWays(string corridor) {
        // Cache the result of each sub-problem
        int cache[corridor.length()][3];
        memset(cache, -1, sizeof(cache));

        // Call the count function
        return count(0, 0, corridor, cache);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Store 1000000007 in a variable for convenience
    private static final int MOD = 1_000_000_007;

    // Count the number of ways to divide from "index" to the last index
    // with "seats" number of "S" in the current section
    private int count(int index, int seats, String corridor, Map<Pair<Integer, Integer>, Integer> cache) {
        // If we have reached the end of the corridor, then
        // the current section is valid only if "seats" is 2
        if (index == corridor.length()) {
            return seats == 2 ? 1 : 0;
        }

        // If we have already computed the result of this sub-problem,
        // then return the cached result
        if (cache.containsKey(new Pair<>(index, seats))) {
            return cache.get(new Pair<>(index, seats));
        }

        // Result of the sub-problem
        int result = 0;

        // If the current section has exactly 2 "S"
        if (seats == 2) {
            // If the current element is "S", then we have to close the
            // section and start a new section from this index. Next index
            // will have one "S" in the current section
            if (corridor.charAt(index) == 'S') {
                result = count(index + 1, 1, corridor, cache);
            } else {
                // If the current element is "P", then we have two options
                // 1. Close the section and start a new section from this index
                // 2. Keep growing the section
                result = (count(index + 1, 0, corridor, cache) + count(index + 1, 2, corridor, cache)) % MOD;  
            }
        } else {
            // Keep growing the section. Increment "seats" if present
            // element is "S"
            if (corridor.charAt(index) == 'S') {
                result = count(index + 1, seats + 1, corridor, cache);
            } else {
                result = count(index + 1, seats, corridor, cache);
            }
        }

        // Memoize the result, and return it
        cache.put(new Pair<>(index, seats), result);
        return result;
    }


    public int numberOfWays(String corridor) {
        // Cache the result of each sub-problem
        Map<Pair<Integer, Integer>, Integer> cache = new HashMap<>();

        // Call the count function
        return count(0, 0, corridor, cache);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;
    
    // Cache the result of each sub-problem
    const cache = new Map();

    // Count the number of ways to divide from "index" to the last index
    // with "seats" number of "S" in the current section
    const count = (index, seats) => {
        // If we have reached the end of the corridor, then
        // the current section is valid only if "seats" is 2
        if (index == corridor.length) {
            return seats == 2 ? 1 : 0;
        }

        // If we have already computed the result of this sub-problem,
        // then return the cached result
        if (cache.has(`${index}-${seats}`)) {
            return cache.get(`${index}-${seats}`);
        }

        // Result of the sub-problem
        let result = 0;

        // If the current section has exactly 2 "S"
        if (seats == 2) {
            // If the current element is "S", then we have to close the
            // section and start a new section from this index. Next index
            // will have one "S" in the current section
            if (corridor[index] == 'S') {
                result = count(index + 1, 1);
            } else {
                // If the current element is "P", then we have two options
                // 1. Close the section and start a new section from this index
                // 2. Keep growing the section
                result = (count(index + 1, 0) + count(index + 1, 2)) % MOD;  
            }
        } else {
            // Keep growing the section. Increment "seats" if present
            // element is "S"
            if (corridor[index] == 'S') {
                result = count(index + 1, seats + 1);
            } else {
                result = count(index + 1, seats);
            }
        }

        // Memoize the result, and return it
        cache.set(`${index}-${seats}`, result);
        return result;
    }

    // Call the count function
    return count(0, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # Store 1000000007 in a variable for convenience
        MOD = 1_000_000_007

        # Cache the result of each sub-problem
        cache = [[-1] * 3 for _ in range(len(corridor))]

        # Count the number of ways to divide from "index" to the last index
        # with "seats" number of "S" in the current section
        def count(index, seats):
            # If we have reached the end of the corridor, then
            # the current section is valid only if "seats" is 2
            if index == len(corridor):
                return 1 if seats == 2 else 0

            # If we have already computed the result of this sub-problem,
            # then return the cached result
            if cache[index][seats] != -1:
                return cache[index][seats]
            
            # If the current section has exactly 2 "S"
            if seats == 2:
                # If the current element is "S", then we have to close the
                # section and start a new section from this index. Next index
                # will have one "S" in the current section
                if corridor[index] == "S":
                    result = count(index + 1, 1)
                else:
                    # If the current element is "P", then we have two options
                    # 1. Close the section and start a new section from this index
                    # 2. Keep growing the section
                    result = (count(index + 1, 0) + count(index + 1, 2)) % MOD
            else:
                # Keep growing the section. Increment "seats" if present
                # element is "S"
                if corridor[index] == "S":
                    result = count(index + 1, seats + 1)
                else:
                    result = count(index + 1, seats)
            
            # Memoize the result, and return it
            cache[index][seats] = result
            return cache[index][seats]
        
        # Call the count function
        return count(0, 0)
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfWays(char * corridor){
    // Store 1000000007 in a variable for convenience
    const int MOD = 1e9 + 7;

    // Initialize the array to store the result of each sub-problem
    int count[strlen(corridor) + 1][3];

    // Base cases
    count[strlen(corridor)][0] = 0;
    count[strlen(corridor)][1] = 0;
    count[strlen(corridor)][2] = 1;

    // Fill the array in a bottom-up fashion
    for (int index = strlen(corridor) - 1; index >= 0; index--) {
        if (corridor[index] == 'S') {
            count[index][0] = count[index + 1][1];
            count[index][1] = count[index + 1][2];
            count[index][2] = count[index + 1][1];
        } else {
            count[index][0] = count[index + 1][0];
            count[index][1] = count[index + 1][1];
            count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD;
        }
    }

    // Return the result
    return count[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Initialize the array to store the result of each sub-problem
        int count[corridor.length() + 1][3];

        // Base cases
        count[corridor.length()][0] = 0;
        count[corridor.length()][1] = 0;
        count[corridor.length()][2] = 1;

        // Fill the array in a bottom-up fashion
        for (int index = corridor.length() - 1; index >= 0; index--) {
            if (corridor[index] == 'S') {
                count[index][0] = count[index + 1][1];
                count[index][1] = count[index + 1][2];
                count[index][2] = count[index + 1][1];
            } else {
                count[index][0] = count[index + 1][0];
                count[index][1] = count[index + 1][1];
                count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD;
            }
        }

        // Return the result
        return count[0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfWays(String corridor) {
        // Store 1000000007 in a variable for convenience
        final int MOD = 1_000_000_007;

        // Initialize the array to store the result of each sub-problem
        int[][] count = new int[corridor.length() + 1][3];

        // Base cases
        count[corridor.length()][0] = 0;
        count[corridor.length()][1] = 0;
        count[corridor.length()][2] = 1;

        // Fill the array in a bottom-up fashion
        for (int index = corridor.length() - 1; index >= 0; index--) {
            if (corridor.charAt(index) == 'S') {
                count[index][0] = count[index + 1][1];
                count[index][1] = count[index + 1][2];
                count[index][2] = count[index + 1][1];
            } else {
                count[index][0] = count[index + 1][0];
                count[index][1] = count[index + 1][1];
                count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD;
            }
        }

        // Return the result
        return count[0][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;
    
    // Initialize the array to store the result of each sub-problem
    const count = new Array(corridor.length + 1).fill(0).map(() => new Array(3).fill(0));

    // Base cases
    count[corridor.length][0] = 0;
    count[corridor.length][1] = 0;
    count[corridor.length][2] = 1;

    // Fill the array in a bottom-up fashion
    for (let index = corridor.length - 1; index >= 0; index--) {
        if (corridor[index] == 'S') {
            count[index][0] = count[index + 1][1];
            count[index][1] = count[index + 1][2];
            count[index][2] = count[index + 1][1];
        } else {
            count[index][0] = count[index + 1][0];
            count[index][1] = count[index + 1][1];
            count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD;
        }
    }

    // Return the result
    return count[0][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # Store 1000000007 in a variable for convenience
        MOD = 1_000_000_007

        # Initialize the array to store the result of each sub-problem
        count = [[-1] * 3 for _ in range(len(corridor) + 1)]

        # Base cases
        count[len(corridor)][0] = 0
        count[len(corridor)][1] = 0
        count[len(corridor)][2] = 1

        # Fill the array in a bottom-up fashion
        for index in range(len(corridor) - 1, -1, -1):
            if corridor[index] == "S":
                count[index][0] = count[index + 1][1]
                count[index][1] = count[index + 1][2]
                count[index][2] = count[index + 1][1]
            else:
                count[index][0] = count[index + 1][0]
                count[index][1] = count[index + 1][1]
                count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD

        # Return the result
        return count[0][0]
```

</details>

<br>

## Approach 3: Space-Optimized Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int numberOfWays(char * corridor) { 
    // Initial values of three variables
    int zero = 0;
    int one = 0;
    int two = 1;

    // Compute using derived equations
    for (int index = 0; index < strlen(corridor); index++) {
        if (corridor[index] == 'S') {
            zero = one;
            swap(&one, &two);
        } else {
            two = (two + zero) % 1000000007;
        }
    }

    // Return the result
    return zero;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Initial values of three variables
        int zero = 0;
        int one = 0;
        int two = 1;

        // Compute using derived equations
        for (char thing : corridor) {
            if (thing == 'S') {
                zero = one;
                swap(one, two);
            } else {
                two = (two + zero) % MOD;
            }
        }

        // Return the result
        return zero;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfWays(String corridor) {
        // Store 1000000007 in a variable for convenience
        final int MOD = 1_000_000_007;

        // Initial values of three variables
        int zero = 0;
        int one = 0;
        int two = 1;

        // Compute using derived equations
        for (char thing : corridor.toCharArray()) {
            if (thing == 'S') {
                zero = one;
                int temp = one;
                one = two;
                two = temp;
            } else {
                two = (two + zero) % MOD;
            }
        }

        // Return the result
        return zero;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;
    
    // Initial values of three variables
    let zero = 0;
    let one = 0;
    let two = 1;

    // Compute using derived equations
    for (thing of corridor) {
        if (thing == 'S') {
            zero = one;
            [one, two] = [two, one];
        } else {
            two = (two + zero) % MOD;
        }
    }

    // Return the result
    return zero;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # Store 1000000007 in a variable for convenience
        MOD = 1_000_000_007

        # Initial values of three variables
        zero = 0
        one = 0
        two = 1

        # Compute using derived equations
        for thing in corridor:
            if thing == "S":
                zero = one
                one, two = two, one
            else:
                two = (two + zero) % MOD

        # Return the result
        return zero
```

</details>

<br>

## Approach 4: Combinatorics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfWays(char * corridor) {
    // Store 1000000007 in a variable for convenience
    const int MOD = 1e9 + 7;

    // Store indices of S in an array
    int indices[strlen(corridor)];
    int indicesLength = 0;
    for (int index = 0; index < strlen(corridor); index++) {
        if (corridor[index] == 'S') {
            indices[indicesLength++] = index;
        }
    }

    // When division is not possible
    if (indicesLength == 0 || indicesLength % 2 == 1) {
        return 0;
    }

    // Total number of ways
    long count = 1;

    // Take product of non-paired neighbors
    int previousPairLast = 1;
    int currentPairFirst = 2;
    while (currentPairFirst < indicesLength) {
        count *= (indices[currentPairFirst] - indices[previousPairLast]);
        count %= MOD;
        previousPairLast += 2;
        currentPairFirst += 2;
    }

    // Return the number of ways
    return (int) count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Store indices of S in an array
        vector<int> indices;
        for (int index = 0; index < corridor.length(); index++) {
            if (corridor[index] == 'S') {
                indices.push_back(index);
            }
        }

        // When division is not possible
        if (indices.size() == 0 || indices.size() % 2 == 1) {
            return 0;
        }

        // Total number of ways
        long count = 1;

        // Take product of non-paired neighbors
        int previousPairLast = 1;
        int currentPairFirst = 2;
        while (currentPairFirst < indices.size()) {
            count *= (indices[currentPairFirst] - indices[previousPairLast]);
            count %= MOD;
            previousPairLast += 2;
            currentPairFirst += 2;
        }

        // Return the number of ways
        return (int) count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfWays(String corridor) {
        // Store 1000000007 in a variable for convenience
        final int MOD = 1_000_000_007;

        // Store indices of S in an array
        List<Integer> indices = new ArrayList<>();
        for (int index = 0; index < corridor.length(); index++) {
            if (corridor.charAt(index) == 'S') {
                indices.add(index);
            }
        }

        // When division is not possible
        if (indices.size() == 0 || indices.size() % 2 == 1) {
            return 0;
        }

        // Total number of ways
        long count = 1;

        // Take product of non-paired neighbors
        int previousPairLast = 1;
        int currentPairFirst = 2;
        while (currentPairFirst < indices.size()) {
            count *= (indices.get(currentPairFirst) - indices.get(previousPairLast));
            count %= MOD;
            previousPairLast += 2;
            currentPairFirst += 2;
        }

        // Return the number of ways
        return (int) count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;
    
    // Store indices of S in an array
    const indices = [];
    for (let index = 0; index < corridor.length; index++) {
        if (corridor[index] == 'S') {
            indices.push(index);
        }
    }

    // When division is not possible
    if (indices.length == 0 || indices.length % 2 == 1) {
        return 0;
    }

    // Total number of ways
    let count = 1;

    // Take product of non-paired neighbors
    let previousPairLast = 1;
    let currentPairFirst = 2;
    while (currentPairFirst < indices.length) {
        count *= (indices[currentPairFirst] - indices[previousPairLast]);
        count %= MOD;
        previousPairLast += 2;
        currentPairFirst += 2;
    }

    // Return the number of ways
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # Store 1000000007 in a variable for convenience
        MOD = 1_000_000_007

        # Store indices of S in an array
        indices = []
        for i, thing in enumerate(corridor):
            if thing == "S":
                indices.append(i)
        
        # When division is not possible
        if indices == [] or len(indices) % 2 == 1:
            return 0
        
        # Total number of ways
        count = 1

        # Take the product of non-paired neighbors
        previous_pair_last = 1
        current_pair_first = 2
        while current_pair_first < len(indices):
            count *= (indices[current_pair_first] - indices[previous_pair_last])
            count %= MOD
            previous_pair_last += 2
            current_pair_first += 2

        # Return the number of ways
        return count
```

</details>

<br>

## Approach 5: Combinatorics, Space Optimized

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfWays(char * corridor){
    // Store 1000000007 in a variable for convenience
    const int MOD = 1e9 + 7;

    // Total number of ways
    long count = 1;

    // Number of seats in the current section
    int seats = 0;

    // Tracking Index of last S in the previous section
    int previousPairLast = -1;

    int len = strlen(corridor);

    // Keep track of seats in the corridor
    for (int index = 0; index < len; index++) {
        if (corridor[index] == 'S') {
            seats += 1;

            // If two seats, then this is the last S in the section
            // Update seats for the next section
            if (seats == 2) {
                previousPairLast = index;
                seats = 0;
            }

            // If one seat, then this is the first S in the section
            // Compute product of non-paired neighbors
            else if (seats == 1 && previousPairLast != -1) {
                count *= (index - previousPairLast);
                count %= MOD;
            }
        }
    }

    // If odd seats, or zero seats
    if (seats == 1 || previousPairLast == -1) {
        return 0;
    }

    // Return the number of ways
    return (int) count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Total number of ways
        long count = 1;

        // Number of seats in the current section
        int seats = 0;

        // Tracking Index of last S in the previous section
        int previousPairLast = -1;

        // Keep track of seats in corridor
        for (int index = 0; index < corridor.length(); index++) {
            if (corridor[index] == 'S') {
                seats += 1;

                // If two seats, then this is the last S in the section
                // Update seats for the next section
                if (seats == 2) {
                    previousPairLast = index;
                    seats = 0;
                }

                // If one seat, then this is the first S in the section
                // Compute product of non-paired neighbors
                else if (seats == 1 && previousPairLast != -1) {
                    count *= (index - previousPairLast);
                    count %= MOD;
                }
            }
        }

        // If odd seats, or zero seats
        if (seats == 1 || previousPairLast == -1) {
            return 0;
        }

        // Return the number of ways
        return (int) count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfWays(String corridor) {
        // Store 1000000007 in a variable for convenience
        final int MOD = 1_000_000_007;

        // Total number of ways
        long count = 1;

        // Number of seats in the current section
        int seats = 0;

        // Tracking Index of last S in the previous section
        Integer previousPairLast = null;

        // Keep track of seats in corridor
        for (int index = 0; index < corridor.length(); index++) {
            if (corridor.charAt(index) == 'S') {
                seats += 1;

                // If two seats, then this is the last S in the section
                // Update seats for the next section
                if (seats == 2) {
                    previousPairLast = index;
                    seats = 0;
                }

                // If one seat, then this is the first S in the section
                // Compute product of non-paired neighbors
                else if (seats == 1 && previousPairLast != null) {
                    count *= (index - previousPairLast);
                    count %= MOD;
                }
            }
        }

        // If odd seats, or zero seats
        if (seats == 1 || previousPairLast == null) {
            return 0;
        }

        // Return the number of ways
        return (int) count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;

    // Total number of ways
    let count = 1;

    // Number of seats in the current section
    let seats = 0;

    // Tracking Index of last S in the previous section
    let previousPairLast = -1;

    // Keep track of seats in corridor
    for (let index = 0; index < corridor.length; index++) {
        if (corridor[index] == 'S') {
            seats += 1;

            // If two seats, then this is the last S in the section
            // Update seats for the next section
            if (seats == 2) {
                previousPairLast = index;
                seats = 0;
            }

            // If one seat, then this is the first S in the section
            // Compute product of non-paired neighbors
            else if (seats == 1 && previousPairLast != -1) {
                count *= (index - previousPairLast);
                count %= MOD;
            }
        }
    }

    // If odd seats, or zero seats
    if (seats == 1 || previousPairLast == -1) {
        return 0;
    }

    // Return the number of ways
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        # Store 1000000007 in a variable for convenience
        MOD = 1_000_000_007

        # Total number of ways
        count = 1

        # Number of seats in current section
        seats = 0

        # Tracking Index of last S in the previous section
        previous_pair_last = None

        # Keep track of seats in the corridor
        for index, thing in enumerate(corridor):
            if thing == "S":
                seats += 1

                # If two seats, then this is the last S in the section
                # Update seats for the next section
                if seats == 2:
                    previous_pair_last = index
                    seats = 0
                
                # If one seat, then this is the first S in the section
                # Compute the product of non-paired neighbors
                elif seats == 1 and previous_pair_last is not None:
                    count *= (index - previous_pair_last)
                    count %= MOD
        
        # If odd seats, or zero seats
        if seats == 1 or previous_pair_last is None:
            return 0

        # Return the number of ways
        return count
```

</details>
