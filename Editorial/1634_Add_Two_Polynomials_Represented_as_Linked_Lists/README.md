# 1634. Add Two Polynomials Represented as Linked Lists

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/)  
`Linked List` `Math` `Two Pointers`

**Problem Link:** [LeetCode 1634 - Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/)

## Problem

A polynomial linked list is a special type of linked list where every node represents a term in a polynomial expression.

Each node has three attributes:

- coefficient: an integer representing the number multiplier of the term. The coefficient of the term 9x4 is 9.
- power: an integer representing the exponent. The power of the term 9x4 is 4.
- next: a pointer to the next node in the list, or null if it is the last node of the list.

For example, the polynomial 5x3 + 4x - 7 is represented by the polynomial linked list illustrated below:

The polynomial linked list must be in its standard form: the polynomial must be in strictly descending order by its power value. Also, terms with a coefficient of 0 are omitted.

Given two polynomial linked list heads, poly1 and poly2, add the polynomials together and return the head of the sum of the polynomials.

PolyNode format:

The input/output format is as a list of n nodes, where each node is represented as its [coefficient, power]. For example, the polynomial 5x3 + 4x - 7 would be represented as: [[5,3],[4,1],[-7,0]].

### Example 1

```text
Input: poly1 = [[1,1]], poly2 = [[1,0]]
Output: [[1,1],[1,0]]
Explanation: poly1 = x. poly2 = 1. The sum is x + 1.
```

### Example 2

```text
Input: poly1 = [[2,2],[4,1],[3,0]], poly2 = [[3,2],[-4,1],[-1,0]]
Output: [[5,2],[2,0]]
Explanation: poly1 = 2x2 + 4x + 3. poly2 = 3x2 - 4x - 1. The sum is 5x2 + 2. Notice that we omit the "0x" term.
```

### Example 3

```text
Input: poly1 = [[1,2]], poly2 = [[-1,2]]
Output: []
Explanation: The sum is 0. We return an empty list.
```

## Constraints

- 0 <= n <= 104
- -109 <= PolyNode.coefficient <= 109
- PolyNode.coefficient != 0
- 0 <= PolyNode.power <= 109
- PolyNode.power > PolyNode.next.power

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1634. Add Two Polynomials Represented as Linked Lists

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Map | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |

## Approach 1: Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* sum = new PolyNode();
        PolyNode* current = sum;

        map<int, int, greater<int>> table;

        // Calculate terms for sum
        processNodes(table, poly1);
        processNodes(table, poly2);

        // Iterate over sorted keys and build sum
        for (auto& [key, val] : table) {
            current->next = new PolyNode(val, key);
            current = current->next;
        }

        return sum->next;
    }

private:
    void processNodes(map<int, int, greater<int>>& table, PolyNode* node) {
        while (node != nullptr) {
            if (table.find(node->power) != table.end()) {
                int newCoefficient = node->coefficient + table[node->power];
                if (newCoefficient == 0) {
                    table.erase(node->power);
                } else {
                    table[node->power] = newCoefficient;
                }
            } else {
                table[node->power] = node->coefficient;
            }
            node = node->next;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public PolyNode addPoly(PolyNode poly1, PolyNode poly2) {
        // Initialize dummy node and pointer to track the last node
        PolyNode sum = new PolyNode();
        PolyNode current = sum;

        // Use TreeMap with reverse order comparator
        Map<Integer, Integer> map = new TreeMap<>(Collections.reverseOrder());

        // Calculate terms for sum
        processNodes(map, poly1);
        processNodes(map, poly2);

        // Iterate over sorted keys and build sum
        for (int key : map.keySet()) {
            current.next = new PolyNode(map.get(key), key);
            current = current.next;
        }

        return sum.next;
    }

    private void processNodes(Map<Integer, Integer> map, PolyNode node) {
        while (node != null) {
            if (map.containsKey(node.power)) {
                int newCoefficient = node.coefficient + map.get(node.power);
                if (newCoefficient == 0) {
                    map.remove(node.power);
                } else {
                    map.put(node.power, newCoefficient);
                }
            } else {
                map.put(node.power, node.coefficient);
            }
            node = node.next;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addPoly(self, poly1: "PolyNode", poly2: "PolyNode") -> "PolyNode":
        sum_ = PolyNode()
        current = sum_
        table = {}

        # Calculate terms for sum
        self._process_nodes(table, poly1)
        self._process_nodes(table, poly2)

        # Iterate over sorted keys and build sum
        for key in sorted(table.keys(), reverse=True):
            current.next = PolyNode(table[key], key)
            current = current.next

        return sum_.next

    def _process_nodes(self, table, node):
        while node:
            if node.power in table:
                new_coefficient = node.coefficient + table[node.power]
                if new_coefficient == 0:
                    table.pop(node.power)
                else:
                    table[node.power] = new_coefficient
            else:
                table[node.power] = node.coefficient
            node = node.next
```

</details>

<br>

## Approach 2: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* p1 = poly1;
        PolyNode* p2 = poly2;
        // initial dummy node
        PolyNode* sum = new PolyNode();
        // maintain pointer to last node
        PolyNode* current = sum;

        // Maintain two pointers
        while (p1 != NULL && p2 != NULL) {
            if (p1->power == p2->power) {
                if (p1->coefficient + p2->coefficient != 0) {
                    current->next = new PolyNode(
                        p1->coefficient + p2->coefficient, p1->power);
                    current = current->next;
                }
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->power > p2->power) {
                current->next = p1;
                p1 = p1->next;
                current = current->next;
            } else {
                current->next = p2;
                p2 = p2->next;
                current = current->next;
            }
        }
        if (p1 == NULL) {
            current->next = p2;
        } else {
            current->next = p1;
        }
        return sum->next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public PolyNode addPoly(PolyNode poly1, PolyNode poly2) {
        PolyNode p1 = poly1;
        PolyNode p2 = poly2;
        // initial dummy node
        PolyNode sum = new PolyNode();
        // maintain pointer to last node
        PolyNode current = sum;

        // Maintain two pointers
        while (p1 != null && p2 != null) {
            if (p1.power == p2.power) {
                if (p1.coefficient + p2.coefficient != 0) {
                    current.next = new PolyNode(
                        p1.coefficient + p2.coefficient,
                        p1.power
                    );
                    current = current.next;
                }
                p1 = p1.next;
                p2 = p2.next;
            } else if (p1.power > p2.power) {
                current.next = p1;
                p1 = p1.next;
                current = current.next;
            } else {
                current.next = p2;
                p2 = p2.next;
                current = current.next;
            }
        }
        if (p1 == null) {
            current.next = p2;
        } else {
            current.next = p1;
        }
        return sum.next;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def addPoly(self, poly1, poly2):
        p1 = poly1
        p2 = poly2
        # initial dummy node
        sum = PolyNode()
        # maintain pointer to last node
        current = sum

        # Maintain two pointers
        while p1 != None and p2 != None:
            if p1.power == p2.power:
                if p1.coefficient + p2.coefficient != 0:
                    current.next = PolyNode(
                        p1.coefficient + p2.coefficient, p1.power
                    )
                    current = current.next
                p1 = p1.next
                p2 = p2.next
            elif p1.power > p2.power:
                current.next = p1
                p1 = p1.next
                current = current.next
            else:
                current.next = p2
                p2 = p2.next
                current = current.next

        if p1 == None:
            current.next = p2
        else:
            current.next = p1
        return sum.next
```

</details>
