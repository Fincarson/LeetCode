# 1359. Count All Valid Pickup and Delivery Options

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/)  
`Math` `Dynamic Programming` `Combinatorics`

**Problem Link:** [LeetCode 1359 - Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/)

## Problem

Given n orders, each order consists of a pickup and a delivery service.

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i).

Since the answer may be too large, return it modulo 10^9 + 7.

### Example 1

```text
Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
```

### Example 2

```text
Input: n = 2
Output: 6
Explanation: All possible orders:
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
```

### Example 3

```text
Input: n = 3
Output: 90
```

## Constraints

- 1 <= n <= 500

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1359. Count All Valid Pickup and Delivery Options

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion with Memoization (Top-Down DP) | C++, Java, JavaScript, Python3 |
| Tabulation (Bottom-Up DP) | C++, Java, JavaScript, Python3 |
| Permutations (Math) | C++, Java, JavaScript, Python3 |
| Probability (Math) | C++, Java, JavaScript, Python3 |

## Approach 1: Recursion with Memoization (Top-Down DP)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    
    long totalWays(int unpicked, int undelivered) {
        if (unpicked == 0 && undelivered == 0) {
            // We have completed all orders.
            return 1;
        }
        
        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
            // We can't pick or deliver more than N items
            // Number of deliveries can't exceed number of pickups 
            // as we can only deliver after a pickup.
            return 0;
        }
        
        if (memo[unpicked][undelivered]) {
            // Return cached value, if already present. 
            return memo[unpicked][undelivered];
        }
        
        long ans = 0;
        
        // Count all choices of picking up an order.
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        // Handle integer overflow.
        ans %= MOD;
        
        // Count all choices of delivering a picked order.
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        // Handle integer overflow.
        ans %= MOD;
        
        return memo[unpicked][undelivered] = ans;
    }
    
public:
    int countOrders(int n) {
        memo = vector<vector<int>> (n + 1, vector<int>(n + 1, 0));
        return totalWays(n, n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int MOD = 1_000_000_007;
    private long[][] memo;
    
    private long totalWays(int unpicked, int undelivered) {
        if (unpicked == 0 && undelivered == 0) {
            // We have completed all orders.
            return 1;
        }
        
        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
            // We can't pick or deliver more than N items
            // Number of deliveries can't exceed number of pickups 
            // as we can only deliver after a pickup.
            return 0;
        }
        
        if (memo[unpicked][undelivered] != 0) {
            // Return cached value, if already present. 
            return memo[unpicked][undelivered];
        }
        
        long ans = 0;
        
        // Count all choices of picking up an order.
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        // Handle integer overflow.
        ans %= MOD;
        
        // Count all choices of delivering a picked order.
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        // Handle integer overflow.
        ans %= MOD;
        
        return memo[unpicked][undelivered] = ans;
    }
    
    public int countOrders(int n) {
        memo = new long[n + 1][n + 1];
        return (int)totalWays(n, n);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let MOD = 1_000_000_007;
let memo;

let totalWays = (unpicked, undelivered) => {
    if (unpicked == 0 && undelivered == 0) {
        // We have completed all orders.
        return 1;
    }

    if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
        // We can't pick or deliver more than N items
        // Number of deliveries can't exceed number of pickups 
        // as we can only deliver after a pickup.
        return 0;
    }

    if (memo[unpicked][undelivered]) {
        // Return cached value, if already present. 
        return memo[unpicked][undelivered];
    }

    let ans = 0;

    // Count all choices of picking up an order.
    ans += unpicked * totalWays(unpicked - 1, undelivered);
    // Handle integer overflow.
    ans %= MOD;

    // Count all choices of delivering a picked order.
    ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
    // Handle integer overflow.
    ans %= MOD;

    return memo[unpicked][undelivered] = ans;
}

var countOrders = function(n) {
    memo = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    return totalWays(n, n);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOrders(self, n: int) -> int:
        @functools.cache
        def totalWays(unpicked, undelivered):
            if not unpicked and not undelivered:
                # We have completed all orders.
                return 1

            if (unpicked < 0 or undelivered < 0 or undelivered < unpicked):
                # We can't pick or deliver more than N items
                # Number of deliveries can't exceed number of pickups 
                # as we can only deliver after a pickup.
                return 0

            # Count all choices of picking up an order.
            ans = unpicked * totalWays(unpicked - 1, undelivered)
            ans %= MOD

            # Count all choices of delivering a picked order.
            ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1)
            ans %= MOD

            return ans
        
        MOD = 1_000_000_007
        return totalWays(n, n)
```

</details>

<br>

## Approach 2: Tabulation (Bottom-Up DP)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int MOD = 1e9 + 7;
    
    int countOrders(int n) {
        vector<vector<long>> dp (n + 1, vector<long>(n + 1, 0));

        for (int unpicked = 0; unpicked <= n; unpicked++) {
            for (int undelivered = unpicked; undelivered <= n; undelivered++) {
                // If all orders are picked and delivered then,
                // for remaining '0' orders we have only one way.
                if (unpicked == 0 && undelivered == 0) {
                    dp[unpicked][undelivered] = 1;
                    continue;
                }
                
                // There are some unpicked elements left. 
                // We have choice to pick any one of those orders.
                if (unpicked > 0) {
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
                }
                dp[unpicked][undelivered] %= MOD;
                
                // Number of deliveries done is less than picked orders.
                // We have choice to deliver any one of (undelivered - unpicked) orders. 
                if (undelivered > unpicked) {
                    dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
                }
                dp[unpicked][undelivered] %= MOD;
            }
        }
        
        return dp[n][n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int MOD = 1_000_000_007;
    
    public int countOrders(int n) {
        long[][] dp = new long[n + 1][n + 1];

        for (int unpicked = 0; unpicked <= n; unpicked++) {
            for (int undelivered = unpicked; undelivered <= n; undelivered++) {
                // If all orders are picked and delivered then,
                // for remaining '0' orders we have only one way.
                if (unpicked == 0 && undelivered == 0) {
                    dp[unpicked][undelivered] = 1;
                    continue;
                }
                
                // There are some unpicked elements left. 
                // We have choice to pick any one of those orders.
                if (unpicked > 0) {
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
                }
                dp[unpicked][undelivered] %= MOD;
                
                // Number of deliveries done is less than picked orders.
                // We have choice to deliver any one of (undelivered - unpicked) orders. 
                if (undelivered > unpicked) {
                    dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
                }
                dp[unpicked][undelivered] %= MOD;
            }
        }
        
        return (int)dp[n][n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countOrders = function(n) {
    let MOD = 1_000_000_007;
    let dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));

    for (let unpicked = 0; unpicked <= n; unpicked++) {
        for (let undelivered = unpicked; undelivered <= n; undelivered++) {
            // If all orders are picked and delivered then,
            // for remaining '0' orders we have only one way.
            if (unpicked == 0 && undelivered == 0) {
                dp[unpicked][undelivered] = 1;
                continue;
            }

            // There are some unpicked elements left. 
            // We have choice to pick any one of those orders.
            if (unpicked > 0) {
                dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
            }
            dp[unpicked][undelivered] %= MOD;

            // Number of deliveries done is less than picked orders.
            // We have choice to deliver any one of (undelivered - unpicked) orders. 
            if (undelivered > unpicked) {
                dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
            }
            dp[unpicked][undelivered] %= MOD;
        }
    }

    return dp[n][n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOrders(self, n: int) -> int:
        MOD = 1_000_000_007
        dp = [[0] * (n + 1) for i in range(n + 1)]
        
        for unpicked in range(n + 1):
            for undelivered in range(unpicked, n + 1):
                # If all orders are picked and delivered then,
                # for remaining '0' orders we have only one way.
                if not unpicked and not undelivered:
                    dp[unpicked][undelivered] = 1
                    continue
                
                # There are some unpicked elements left. 
                # We have choice to pick any one of those orders.
                if unpicked > 0:
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered]
                dp[unpicked][undelivered] %= MOD
                
                # Number of deliveries done is less than picked orders.
                # We have choice to deliver any one of (undelivered - unpicked) orders. 
                if undelivered > unpicked:
                    dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1]
                dp[unpicked][undelivered] %= MOD
        
        return dp[n][n]
```

</details>

<br>

## Approach 3: Permutations (Math)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countOrders(int n) {
        long ans = 1;
        int MOD = 1e9 + 7;

        for (int i = 1; i <= n; ++i) {
            // Ways to arrange all pickups, 1*2*3*4*5*...*n
            ans = ans * i;
            // Ways to arrange all deliveries, 1*3*5*...*(2n-1)
            ans = ans * (2 * i - 1);
            ans %= MOD;
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
    public int countOrders(int n) {
        long ans = 1;
        int MOD = 1_000_000_007;

        for (int i = 1; i <= n; ++i) {
            // Ways to arrange all pickups, 1*2*3*4*5*...*n
            ans = ans * i;
            // Ways to arrange all deliveries, 1*3*5*...*(2n-1)
            ans = ans * (2 * i - 1);
            ans %= MOD;
        }
        
        return (int)ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countOrders = function(n) {
    let ans = 1;
    let MOD = 1_000_000_007;

    for (let i = 1; i <= n; ++i) {
        // Ways to arrange all pickups, 1*2*3*4*5*...*n
        ans = ans * i;
        // Ways to arrange all deliveries, 1*3*5*...*(2n-1)
        ans = ans * (2 * i - 1);
        ans %= MOD;
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOrders(self, n: int) -> int:
        MOD = 1_000_000_007
        ans = 1

        for i in range(1, n + 1):
            # Ways to arrange all pickups, 1*2*3*4*5*...*n
            ans = ans * i
            # Ways to arrange all deliveries, 1*3*5*...*(2n-1)
            ans = ans * (2 * i - 1)
            ans %= MOD
        
        return ans
```

</details>

<br>

## Approach 4: Probability (Math)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countOrders(int n) {
        long ans = 1;
        int MOD = 1e9 + 7;
        
        for (int i = 1; i <= 2 * n; ++i) {
            ans = ans * i;
            
            // We only need to divide the result by 2 n-times.
            // To prevent decimal results we divide after multiplying an even number.
            if (i % 2 == 0) {
                ans = ans / 2;
            }
            ans %= MOD;
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
    public int countOrders(int n) {
        long ans = 1;
        int MOD = 1_000_000_007;
        
        for (int i = 1; i <= 2 * n; ++i) {
            ans = ans * i;
            
            // We only need to divide the result by 2 n-times.
            // To prevent decimal results we divide after multiplying an even number.
            if (i % 2 == 0) {
                ans = ans / 2;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countOrders = function(n) {
    let ans = 1;
    let MOD = 1_000_000_007;

    for (let i = 1; i <= 2 * n; ++i) {
        ans = ans * i;

        // We only need to divide the result by 2 n-times.
        // To prevent decimal results we divide after multiplying an even number.
        if (i % 2 == 0) {
            ans = ans / 2;
        }
        ans %= MOD;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOrders(self, n: int) -> int:
        MOD = 1_000_000_007
        ans = 1

        for i in range(1, 2 * n + 1):
            ans = ans * i
            
            # We only need to divide the result by 2 n-times.
            # To prevent decimal results we divide after multiplying an even number.
            if not i % 2:
                ans = ans // 2
            ans %= MOD
        
        return ans
```

</details>
