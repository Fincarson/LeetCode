# 679. 24 Game

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/24-game/)  
`Array` `Math` `Backtracking`

**Problem Link:** [LeetCode 679 - 24 Game](https://leetcode.com/problems/24-game/)

## Problem

You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

- The division operator '/' represents real division, not integer division.

		For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
- Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.

		For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
- You cannot concatenate numbers together

		For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.

Return true if you can get such expression that evaluates to 24, and false otherwise.

### Example 1

```text
Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24
```

### Example 2

```text
Input: cards = [1,2,1,2]
Output: false
```

## Constraints

- cards.length == 4
- 1 <= cards[i] <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 679. 24 Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, JavaScript, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // All possible operations we can perform on two numbers.
    vector<double> generatePossibleResults(double& a, double& b) {
        vector<double> res = { a + b, a - b, b - a, a * b };
        if (a) {
            res.push_back(b / a);
        } 
        if (b) {
            res.push_back(a / b);
        }
        return res;
    }
    
    // Check if using current list we can react result 24.
    bool checkIfResultReached(vector<double> list) {
        if (list.size() == 1) {
            // Base Case: We have only one number left, check if it is approximately 24.
            return abs(list[0] - 24) <= 0.1;
        }

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                // Create a new list with the remaining numbers and the new result.
                vector<double> newList;
                for (int k = 0; k < list.size(); k++) {
                    if (k != j && k != i) {
                        newList.push_back(list[k]);
                    }
                }
                
                // For any two numbers in our list,
                // we perform every operation one by one.
                for (double& res : generatePossibleResults(list[i], list[j])) {
                    // Push the new result in the list.
                    newList.push_back(res); 
                    
                    // Check if using this new list we can obtain the result 24.
                    if (checkIfResultReached(newList)) {
                        return true;
                    }
                    
                    // Backtrack: remove the result from the list.
                    newList.pop_back();
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> list(cards.begin(), cards.end());
        return checkIfResultReached(list);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // All possible operations we can perform on two numbers.
    private List<Double> generatePossibleResults(double a, double b) {
        List<Double> res = new ArrayList<>();
        res.add(a + b); 
        res.add(a - b);
        res.add(b - a); 
        res.add(a * b);
        if (b != 0) {
            res.add(a / b);
        }
        if (a != 0) {
            res.add(b / a);
        }
        return res;
    }
    
    // Check if using current list we can react result 24.
    private boolean checkIfResultReached(List<Double> list) {
        if (list.size() == 1) {
            // Base Case: We have only one number left, check if it is approximately 24.
            return Math.abs(list.get(0) - 24) <= 0.1;
        }

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                // Create a new list with the remaining numbers and the new result.
                List<Double> newList = new ArrayList<>();
                for (int k = 0; k < list.size(); k++) {
                    if (k != j && k != i) {
                        newList.add(list.get(k));
                    }
                }
                
                // For any two numbers in our list,
                // we perform every operation one by one.
                for (double res : generatePossibleResults(list.get(i), list.get(j))) {
                    // Push the new result in the list
                    newList.add(res);
                    
                    // Check if using this new list we can obtain the result 24.
                    if (checkIfResultReached(newList)) {
                        return true;
                    }
                    
                    // Backtrack: remove the result from the list.
                    newList.remove(newList.size() - 1);
                }
            }
        }
        return false;
    }
    
    public boolean judgePoint24(int[] cards) {
        List<Double> list = new ArrayList<>();
        for (int card : cards) {
            list.add((double) card);
        }
        
        return checkIfResultReached(list);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// All possible operations we can perform on two numbers.
let generatePossibleResults = (a, b) => {
    let res = [ a + b, a - b, b - a, a * b ];
    if (a) {
        res.push(b / a);
    }
    if (b) {
        res.push(a / b);
    }
    return res;
}

// Check if using current list we can react result 24.
let checkIfResultReached = list => {
    if (list.length == 1) {
        // Base Case: We have only one number left, check if it is approximately 24.
        return Math.abs(list[0] - 24.0) <= 0.1;
    }

    for (let i = 0; i < list.length; i++) {
        for (let j = i + 1; j < list.length; j++) {
            // Create a new list with the remaining numbers and the new result.
            let newList = [];
            for (let k = 0; k < list.length; k++) {
                if (k != i && k != j) {
                    newList.push(list[k]);
                }
            }
            
            // For any two numbers in our list,
            // we perform every operation one by one.
            let results = generatePossibleResults(list[i], list[j]);
            for (let resIdx = 0; resIdx < results.length; ++resIdx) {
                // Push the new result in the list
                newList.push(results[resIdx]);
                
                // Check if using this new list we can obtain the result 24.
                if (checkIfResultReached(newList)) {
                    return true;
                }
                
                // Backtrack: remove the result from the list.
                newList.pop();
            }
        }
    }
    return false;
};

let judgePoint24 = cards => checkIfResultReached(cards);
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # All possible operations we can perform on two numbers.
    def generate_possible_results(self, a: float, b: float) -> List[float]:
        res = [a + b, a - b, b - a, a * b]
        if a:
            res.append(b / a)
        if b:
            res.append(a / b)  
        return res
    
    # Check if using current list we can react result 24.
    def check_if_result_reached(self, cards: List[float]) -> bool:
        # Base Case: We have only one number left, check if it is approximately 24.
        if len(cards) == 1:
            return abs(cards[0] - 24.0) <= 0.1

        for i in range(len(cards)):
            for j in range(i + 1, len(cards)):
                # Create a new list with the remaining numbers and the new result.
                new_list = [number for k, number in enumerate(cards) if (k != i and k != j)]
                
                # For any two numbers in our list, we perform every operation one by one.
                for res in self.generate_possible_results(cards[i], cards[j]):
                    # Add the new result to the list.
                    new_list.append(res)
                    
                    # Check if using this new list we can obtain the result 24.
                    if self.check_if_result_reached(new_list):
                        return True
                    
                    # Backtrack: remove the result from the list.
                    new_list.pop()
                    
        return False
    
    def judgePoint24(self, cards: List[int]) -> bool:
        return self.check_if_result_reached(cards)
```

</details>
