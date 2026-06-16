# 2706. Buy Two Chocolates

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/buy-two-chocolates/)  
`Array` `Greedy` `Sorting`

**Problem Link:** [LeetCode 2706 - Buy Two Chocolates](https://leetcode.com/problems/buy-two-chocolates/)

## Problem

You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money, which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt, return money. Note that the leftover must be non-negative.

### Example 1

```text
Input: prices = [1,2,2], money = 3
Output: 0
Explanation: Purchase the chocolates priced at 1 and 2 units respectively. You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.
```

### Example 2

```text
Input: prices = [3,2,3], money = 3
Output: 3
Explanation: You cannot buy 2 chocolates without going in debt, so we return 3.
```

## Constraints

- 2 <= prices.length <= 50
- 1 <= prices[i] <= 100
- 1 <= money <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2706. Buy Two Chocolates

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Check Every Pair of Chocolate | C++, C#, Java, JavaScript, Python3 |
| Greedy | C++, C#, Java, JavaScript, Python3 |
| Counting Sort | C++, C#, Java, JavaScript, Python3 |
| Two Passes | C++, C#, Java, JavaScript, Python3 |
| One Pass | C++, C#, Java, JavaScript, Python3 |

## Approach 1: Check Every Pair of Chocolate

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Assume Minimum Cost to be Infinity
        int minCost = INT_MAX;

        // Number of Chocolates
        int n = prices.size();

        // Check Every Pair of Chocolates
        for (int firstChoco = 0; firstChoco < n; firstChoco++) {
            for (int secondChoco = firstChoco + 1; secondChoco < n; secondChoco++) {
                // Sum of Prices of the Two Chocolates
                int cost = prices[firstChoco] + prices[secondChoco];

                // If the Sum of Prices is Less than the Minimum Cost
                if (cost < minCost) {
                    // Update the Minimum Cost
                    minCost = cost;
                }
            }
        }

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int BuyChoco(int[] prices, int money) {
        // Assume Minimum Cost to be Infinity
        int minCost = int.MaxValue;

        // Number of Chocolates
        int n = prices.Length;

        // Check Every Pair of Chocolates
        for (int firstChoco = 0; firstChoco < n; firstChoco++) {
            for (int secondChoco = firstChoco + 1; secondChoco < n; secondChoco++) {
                // Sum of Prices of the Two Chocolates
                int cost = prices[firstChoco] + prices[secondChoco];

                // If the Sum of Prices is Less than the Minimum Cost
                if (cost < minCost) {
                    // Update the Minimum Cost
                    minCost = cost;
                }
            }
        }

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int buyChoco(int[] prices, int money) {
        // Assume Minimum Cost to be Infinity
        int minCost = Integer.MAX_VALUE;

        // Number of Chocolates
        int n = prices.length;

        // Check Every Pair of Chocolates
        for (int firstChoco = 0; firstChoco < n; firstChoco++) {
            for (int secondChoco = firstChoco + 1; secondChoco < n; secondChoco++) {
                // Sum of Prices of the Two Chocolates
                int cost = prices[firstChoco] + prices[secondChoco];

                // If the Sum of Prices is Less than the Minimum Cost
                if (cost < minCost) {
                    // Update the Minimum Cost
                    minCost = cost;
                }
            }
        }

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buyChoco = function(prices, money) {
    // Assume Minimum Cost to be Infinity
    let minCost = Infinity;

    // Number of Chocolates
    let n = prices.length;

    // Check Every Pair of Chocolates
    for (let firstChoco = 0; firstChoco < n; firstChoco++) {
        for (let secondChoco = firstChoco + 1; secondChoco < n; secondChoco++) {
            // Sum of Prices of the Two Chocolates
            let cost = prices[firstChoco] + prices[secondChoco];

            // If the Sum of Prices is Less than the Minimum Cost
            if (cost < minCost) {
                // Update the Minimum Cost
                minCost = cost;
            }
        }
    }

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    } else {
        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        # Assume the Minimum Cost to be Infinity
        min_cost = float('inf')

        # Number of Chocolates
        n = len(prices)

        # Check Every Pair of Chocolates
        for first_choco in range(n):
            for second_choco in range(first_choco + 1, n):
                # Sum of Prices of the Two Chocolates
                cost = prices[first_choco] + prices[second_choco]

                # If the Sum of Prices is Less than the Minimum Cost
                if cost < min_cost:
                    # Update the Minimum Cost
                    min_cost = cost
        
        # We can buy chocolates only if we have enough money
        if min_cost <= money:
            # Return the Amount of Money Left
            return money - min_cost
        else:
            # We cannot buy chocolates. Return the initial amount of money
            return money
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Sort the Array in Increasing Order
        sort(prices.begin(), prices.end());

        // Minimum Cost
        int minCost = prices[0] + prices[1];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int BuyChoco(int[] prices, int money) {
        // Sort the Array in Increasing Order
        Array.Sort(prices);

        // Minimum Cost
        int minCost = prices[0] + prices[1];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int buyChoco(int[] prices, int money) {
        // Sort the Array in Increasing Order
        Arrays.sort(prices);

        // Minimum Cost
        int minCost = prices[0] + prices[1];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        } else {
            // We cannot buy chocolates. Return the initial amount of money
            return money;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buyChoco = function(prices, money) {
    // Sort the Array in Increasing Order
    prices.sort((a, b) => a - b);

    // Minimum Cost
    let minCost = prices[0] + prices[1];

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    } else {
        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        # Sort the Array in Increasing Order
        prices.sort()

        # Minimum Cost
        min_cost = prices[0] + prices[1]

        # We can buy chocolates only if we have enough money
        if min_cost <= money:
            # Return the Amount of Money Left
            return money - min_cost
        else:
            # We cannot buy chocolates. Return the initial amount of money
            return money
```

</details>

<br>

## Approach 3: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Array to store frequency of prices
        vector<int> freq(101, 0);
        for (int p : prices) {
            freq[p]++;
        }

        // Assume minimum and second minimum to be zero.
        // Since prices[i] cannot be 0, the 0 value implies
        //They haven't been computed yet.
        int minimum = 0;
        int secondMinimum = 0;
        for (int price = 1; price <= 100; price++) {
            if (freq[price] > 1) {
                minimum = price;
                secondMinimum = price;
                break;
            } else if (freq[price] == 1) {
                minimum = price;
                break;
            }
        }

        // If the second minimum is not found, then find it
        if (secondMinimum == 0) {
            for (int price = minimum + 1; price <= 100; price++) {
                if (freq[price] > 0) {
                    secondMinimum = price;
                    break;
                }
            }
        }

        // Minimum Cost
        int minCost = minimum + secondMinimum;

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int BuyChoco(int[] prices, int money) {
        // Array to store frequency of prices
        int[] freq = new int[101];
        foreach (int p in prices) {
            freq[p]++;
        }

        // Assume minimum and second minimum to be zero.
        // Since prices[i] cannot be 0, the 0 value implies
        //They haven't been computed yet.
        int minimum = 0;
        int secondMinimum = 0;
        for (int price = 1; price <= 100; price++) {
            if (freq[price] > 1) {
                minimum = price;
                secondMinimum = price;
                break;
            } else if (freq[price] == 1) {
                minimum = price;
                break;
            }
        }

        // If the second minimum is not found, then find it
        if (secondMinimum == 0) {
            for (int price = minimum + 1; price <= 100; price++) {
                if (freq[price] > 0) {
                    secondMinimum = price;
                    break;
                }
            }
        }

        // Minimum Cost
        int minCost = minimum + secondMinimum;

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int buyChoco(int[] prices, int money) {
        // Array to store frequency of prices
        int[] freq = new int[101];
        for (int p : prices) {
            freq[p]++;
        }

        // Assume minimum and second minimum to be zero.
        // Since prices[i] cannot be 0, the 0 value implies
        //They haven't been computed yet.
        int minimum = 0;
        int secondMinimum = 0;
        for (int price = 1; price <= 100; price++) {
            if (freq[price] > 1) {
                minimum = price;
                secondMinimum = price;
                break;
            } else if (freq[price] == 1) {
                minimum = price;
                break;
            }
        }

        // If the second minimum is not found, then find it
        if (secondMinimum == 0) {
            for (int price = minimum + 1; price <= 100; price++) {
                if (freq[price] > 0) {
                    secondMinimum = price;
                    break;
                }
            }
        }

        // Minimum Cost
        int minCost = minimum + secondMinimum;

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buyChoco = function(prices, money) {
    // Array to store frequency of prices
    let freq = new Array(101).fill(0);
    for (let p of prices) {
        freq[p]++;
    }

    // Assume minimum and second minimum to be zero.
    // Since prices[i] cannot be 0, the 0 value implies
    //They haven't been computed yet.
    let minimum = 0;
    let secondMinimum = 0;
    for (let price = 1; price <= 100; price++) {
        if (freq[price] > 1) {
            minimum = price;
            secondMinimum = price;
            break;
        } else if (freq[price] == 1) {
            minimum = price;
            break;
        }
    }

    // If the second minimum is not found, then find it
    if (secondMinimum == 0) {
        for (let price = minimum + 1; price <= 100; price++) {
            if (freq[price] > 0) {
                secondMinimum = price;
                break;
            }
        }
    }

    // Minimum Cost
    let minCost = minimum + secondMinimum;

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    }

    // We cannot buy chocolates. Return the initial amount of money
    return money;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        # Array to store the frequency of prices
        freq = [0] * 101
        for p in prices:
            freq[p] += 1
        
        # Assume minimum and second minimum to be zero.
        # Since prices[i] cannot be 0, the 0 value implies
        # They haven't been computed yet.
        minimum = 0
        second_minimum = 0
        for price in range(1, 101):
            if freq[price] > 1:
                minimum = price
                second_minimum = price
                break
            elif freq[price] == 1:
                minimum = price
                break
        
        # If the second minimum is not found, then find it
        if second_minimum == 0:
            for price in range(minimum + 1, 101):
                if freq[price] > 0:
                    second_minimum = price
                    break
        
        # Minimum Cost
        min_cost = minimum + second_minimum

        # We can buy chocolates only if we have enough money
        if min_cost <= money:
            # Return the Amount of Money Left
            return money - min_cost
    
        # We cannot buy chocolates. Return the initial amount of money
        return money
```

</details>

<br>

## Approach 4: Two Passes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int indexMinimum(vector<int>& arr) {
        // Assume the First Element to be the Minimum
        int minIndex = 0;

        // Compare the Assumed Minimum with the Remaining Elements
        // and update assumed minimum if necessary
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        // Return the Index of the Minimum Element
        return minIndex;
    }

    int buyChoco(vector<int>& prices, int money) {
        // Find the index of the minimum price
        int minIndex = indexMinimum(prices);

        // Save the minimum price in a variable minCost
        int minCost = prices[minIndex];
        // Assign the minimum price to be a very large integer
        prices[minIndex] = INT_MAX;

        // Find the index of the second minimum price
        // which is the minimum of the remaining array
        int secondMinIndex = indexMinimum(prices);

        // Add the second minimum price to minCost
        minCost += prices[secondMinIndex];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int IndexMinimum(int[] arr) {
        // Assume the First Element to be the Minimum
        int minIndex = 0;

        // Compare the Assumed Minimum with the Remaining Elements
        // and update assumed minimum if necessary
        for (int i = 1; i < arr.Length; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        // Return the Index of the Minimum Element
        return minIndex;
    }

    public int BuyChoco(int[] prices, int money) {
        // Find the index of the minimum price
        int minIndex = IndexMinimum(prices);

        // Save the minimum price in a variable minCost
        int minCost = prices[minIndex];
        // Assign the minimum price to be a very large integer
        prices[minIndex] = int.MaxValue;

        // Find the index of the second minimum price
        // which is the minimum of the remaining array
        int secondMinIndex = IndexMinimum(prices);

        // Add the second minimum price to minCost
        minCost += prices[secondMinIndex];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int indexMinimum(int[] arr) {
        // Assume the First Element to be the Minimum
        int minIndex = 0;

        // Compare the Assumed Minimum with the Remaining Elements
        // and update assumed minimum if necessary
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        // Return the Index of the Minimum Element
        return minIndex;
    }

    public int buyChoco(int[] prices, int money) {
        // Find the index of the minimum price
        int minIndex = indexMinimum(prices);

        // Save the minimum price in a variable minCost
        int minCost = prices[minIndex];
        // Assign the minimum price to be a very large integer
        prices[minIndex] = Integer.MAX_VALUE;

        // Find the index of the second minimum price
        // which is the minimum of the remaining array
        int secondMinIndex = indexMinimum(prices);

        // Add the second minimum price to minCost
        minCost += prices[secondMinIndex];

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var indexMinimum = function(arr) {
    // Assume the First Element to be the Minimum
    let minIndex = 0;

    // Compare the Assumed Minimum with the Remaining Elements
    // and update assumed minimum if necessary
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Return the Index of the Minimum Element
    return minIndex;
};

var buyChoco = function(prices, money) {
    // Find the index of the minimum price
    let minIndex = indexMinimum(prices);

    // Save the minimum price in a variable minCost
    let minCost = prices[minIndex];
    // Assign the minimum price to be a very large integer
    prices[minIndex] = Number.MAX_SAFE_INTEGER;

    // Find the index of the second minimum price
    // which is the minimum of the remaining array
    let secondMinIndex = indexMinimum(prices);

    // Add the second minimum price to minCost
    minCost += prices[secondMinIndex];

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    }

    // We cannot buy chocolates. Return the initial amount of money
    return money;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def indexMinimum(self, arr: List[int]) -> int:
        # Assume the First Element to be the Minimum
        min_index = 0

        # Compare the Assumed Minimum with the Remaining Elements
        # and update assumed minimum if necessary
        for i in range(1, len(arr)):
            if arr[i] < arr[min_index]:
                min_index = i
        
        # Return the Index of the Minimum Element
        return min_index

    def buyChoco(self, prices: List[int], money: int) -> int:
        # Find the index of the minimum price
        min_index = self.indexMinimum(prices)

        # Remove the minimum price from the array.
        # Save the minimum price in a variable min_cost
        min_cost = prices.pop(min_index)

        # Find the index of the second minimum price
        # which is the minimum of the remaining array
        second_min_index = self.indexMinimum(prices)
        
        # Add the second minimum price to min_cost
        min_cost += prices[second_min_index]

        # We can buy chocolates only if we have enough money
        if min_cost <= money:
            # Return the Amount of Money Left
            return money - min_cost
        
        # We cannot buy chocolates. Return the initial amount of money
        return money
```

</details>

<br>

## Approach 5: One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Assume minimum and second minimum
        int minimum = min(prices[0], prices[1]);
        int secondMinimum = max(prices[0], prices[1]);

        // Iterate over the remaining elements
        for (int i = 2; i < prices.size(); i++) {
            if (prices[i] < minimum) {
                secondMinimum = minimum;
                minimum = prices[i];
            } else if (prices[i] < secondMinimum) {
                secondMinimum = prices[i];
            }
        }

        // Minimum Cost
        int minCost = minimum + secondMinimum;

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int BuyChoco(int[] prices, int money) {
        // Assume minimum and second minimum
        int minimum = Math.Min(prices[0], prices[1]);
        int secondMinimum = Math.Max(prices[0], prices[1]);

        // Iterate over the remaining elements
        for (int i = 2; i < prices.Length; i++) {
            if (prices[i] < minimum) {
                secondMinimum = minimum;
                minimum = prices[i];
            } else if (prices[i] < secondMinimum) {
                secondMinimum = prices[i];
            }
        }

        // Minimum Cost
        int minCost = minimum + secondMinimum;

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int buyChoco(int[] prices, int money) {
        // Assume minimum and second minimum
        int minimum = Math.min(prices[0], prices[1]);
        int secondMinimum = Math.max(prices[0], prices[1]);

        // Iterate over the remaining elements
        for (int i = 2; i < prices.length; i++) {
            if (prices[i] < minimum) {
                secondMinimum = minimum;
                minimum = prices[i];
            } else if (prices[i] < secondMinimum) {
                secondMinimum = prices[i];
            }
        }

        // Minimum Cost
        int minCost = minimum + secondMinimum;

        // We can buy chocolates only if we have enough money
        if (minCost <= money) {
            // Return the Amount of Money Left
            return money - minCost;
        }

        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buyChoco = function(prices, money) {
    // Assume minimum and second minimum
    let minimum = Math.min(prices[0], prices[1]);
    let secondMinimum = Math.max(prices[0], prices[1]);

    // Iterate over the remaining elements
    for (let i = 2; i < prices.length; i++) {
        if (prices[i] < minimum) {
            secondMinimum = minimum;
            minimum = prices[i];
        } else if (prices[i] < secondMinimum) {
            secondMinimum = prices[i];
        }
    }

    // Minimum Cost
    let minCost = minimum + secondMinimum;

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    }

    // We cannot buy chocolates. Return the initial amount of money
    return money;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        # Assume minimum and second minimum
        minimum = min(prices[0], prices[1])
        second_minimum = max(prices[0], prices[1])

        # Iterate over the remaining elements
        for i in range(2, len(prices)):
            if prices[i] < minimum:
                second_minimum = minimum
                minimum = prices[i]
            elif prices[i] < second_minimum:
                second_minimum = prices[i]
            
        # Minimum Cost
        min_cost = minimum + second_minimum

        # We can buy chocolates only if we have enough money
        if min_cost <= money:
            # Return the Amount of Money Left
            return money - min_cost
        
        # We cannot buy chocolates. Return the initial amount of money
        return money
```

</details>
