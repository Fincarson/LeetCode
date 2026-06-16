# 2064. Minimized Maximum of Products Distributed to Any Store

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)  
`Array` `Binary Search` `Greedy`

**Problem Link:** [LeetCode 2064 - Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/)

## Problem

You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

- A store can only be given at most one product type but can be given any amount of it.
- After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.

Return the minimum possible x.

### Example 1

```text
Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.
```

### Example 2

```text
Input: n = 7, quantities = [15,10,10]
Output: 5
Explanation: One optimal way is:
- The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
- The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
- The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.
```

### Example 3

```text
Input: n = 1, quantities = [100000]
Output: 100000
Explanation: The only optimal way is:
- The 100000 products of type 0 are distributed to the only store.
The maximum number of products given to any store is max(100000) = 100000.
```

## Constraints

- m == quantities.length
- 1 <= m <= n <= 105
- 1 <= quantities[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Candies Allocated to K Children](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Time to Complete Trips](https://leetcode.com/problems/minimum-time-to-complete-trips/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2064. Minimized Maximum of Products Distributed to Any Store

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search on The Answer | C++, Java, Python3 |
| Greedy Approach Using a Heap | C++, Java, Python3 |

## Approach 1: Binary Search on The Answer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canDistribute(int x, vector<int>& quantities, int n) {
        // Pointer to the first not fully distributed product type
        int j = 0;
        // Remaining quantity of the jth product type
        int remaining = quantities[j];

        // Loop through each store
        for (int i = 0; i < n; i++) {
            // Check if the remaining quantity of the jth product type
            // can be fully distributed to the ith store
            if (remaining <= x) {
                // If yes, move the pointer to the next product type
                j++;
                // Check if all products have been distributed
                if (j == quantities.size()) {
                    return true;
                } else {
                    remaining = quantities[j];
                }
            } else {
                // Distribute the maximum possible quantity (x) to the ith store
                remaining -= x;
            }
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // Initialize the boundaries of the binary search
        int left = 0;
        int right = *max_element(quantities.begin(), quantities.end());

        // Perform binary search until the boundaries converge
        while (left < right) {
            int middle = (left + right) / 2;
            if (canDistribute(middle, quantities, n)) {
                // Try for a smaller maximum
                right = middle;
            } else {
                // Increase the minimum possible maximum
                left = middle + 1;
            }
        }
        return left;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canDistribute(int x, int[] quantities, int n) {
        // Pointer to the first not fully distributed product type
        int j = 0;
        // Remaining quantity of the jth product type
        int remaining = quantities[j];

        // Loop through each store
        for (int i = 0; i < n; i++) {
            // Check if the remaining quantity of the jth product type
            // can be fully distributed to the ith store
            if (remaining <= x) {
                // If yes, move the pointer to the next product type
                j++;
                // Check if all products have been distributed
                if (j == quantities.length) {
                    return true;
                } else {
                    remaining = quantities[j];
                }
            } else {
                // Distribute the maximum possible quantity (x) to the ith store
                remaining -= x;
            }
        }
        return false;
    }

    public int minimizedMaximum(int n, int[] quantities) {
        // Initialize the boundaries of the binary search
        int left = 0;
        int right = 0;

        // Find the maximum element in quantities
        for (int quantity : quantities) {
            if (quantity > right) {
                right = quantity;
            }
        }

        // Perform binary search until the boundaries converge
        while (left < right) {
            int middle = (left + right) / 2;
            if (canDistribute(middle, quantities, n)) {
                // Try for a smaller maximum
                right = middle;
            } else {
                // Increase the minimum possible maximum
                left = middle + 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def can_distribute(self, x: int, quantities: List[int], n: int) -> bool:
        # Pointer to the first not fully distributed product type
        j = 0
        # Remaining quantity of the jth product type
        remaining = quantities[j]

        # Loop through each store
        for i in range(n):
            # Check if the remaining quantity of the jth product type
            # can be fully distributed to the ith store
            if remaining <= x:
                # If yes, move the pointer to the next product type
                j += 1
                # Check if all products have been distributed
                if j == len(quantities):
                    return True
                else:
                    remaining = quantities[j]
            else:
                # Distribute the maximum possible quantity (x) to the ith store
                remaining -= x

        return False

    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        # Initialize the boundaries of the binary search
        left = 0
        right = max(quantities)

        # Perform binary search until the boundaries converge
        while left < right:
            middle = (left + right) // 2
            if self.can_distribute(middle, quantities, n):
                # Try for a smaller maximum
                right = middle
            else:
                # Increase the minimum possible maximum
                left = middle + 1

        return left
```

</details>

<br>

## Approach 2: Greedy Approach Using a Heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        // Define a custom comparator for the priority queue
        // It sorts the pairs based on the ratio of their first to their second
        // element
        auto compareTypeStorePairs = [](pair<int, int>& a, pair<int, int>& b) {
            return (long long)a.first * b.second <
                   (long long)a.second * b.first;
        };

        // Helper array - useful for the efficient initialization of the
        // priority queue
        vector<pair<int, int>> typeStorePairsArray;

        // Push all product types to the array, after assigning one store to
        // each of them
        for (int i = 0; i < m; i++) {
            typeStorePairsArray.push_back({quantities[i], 1});
        }

        // Initialize the priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(compareTypeStorePairs)>
            typeStorePairs(typeStorePairsArray.begin(),
                           typeStorePairsArray.begin() + m);

        // Iterate over the remaining n - m stores.
        for (int i = 0; i < n - m; i++) {
            // Pop first element
            pair<int, int> pairWithMaxRatio = typeStorePairs.top();
            int totalQuantityOfType = pairWithMaxRatio.first;
            int storesAssignedToType = pairWithMaxRatio.second;
            typeStorePairs.pop();

            // Push same element after assigning one more store to its product
            // type
            typeStorePairs.push(
                {totalQuantityOfType, storesAssignedToType + 1});
        }

        // Pop first element
        pair<int, int> pairWithMaxRatio = typeStorePairs.top();
        int totalQuantityOfType = pairWithMaxRatio.first;
        int storesAssignedToType = pairWithMaxRatio.second;

        // Return the maximum minimum ratio
        return ceil((double)totalQuantityOfType / storesAssignedToType);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimizedMaximum(int n, int[] quantities) {
        int m = quantities.length;

        // Helper arrays - useful for the efficient initialization of the
        // priority queue
        List<int[]> typeStorePairsArray = new ArrayList<>();

        // Push all product types to the list, after assigning one store to each of them
        for (int i = 0; i < m; i++) {
            typeStorePairsArray.add(new int[] { quantities[i], 1 });
        }

        PriorityQueue<int[]> typeStorePairs = new PriorityQueue<>((a, b) ->
            Long.compare((long) b[0] * a[1], (long) a[0] * b[1])
        );

        // Initialize the priority queue
        typeStorePairs.addAll(typeStorePairsArray);

        // Iterate over the remaining n - m stores.
        for (int i = 0; i < n - m; i++) {
            // Pop the first element
            int[] pairWithMaxRatio = typeStorePairs.poll();
            int totalQuantityOfType = pairWithMaxRatio[0];
            int storesAssignedToType = pairWithMaxRatio[1];

            // Push the same element after assigning one more store to its product type
            typeStorePairs.offer(
                new int[] { totalQuantityOfType, storesAssignedToType + 1 }
            );
        }

        // Pop the first element
        int[] pairWithMaxRatio = typeStorePairs.poll();
        int totalQuantityOfType = pairWithMaxRatio[0];
        int storesAssignedToType = pairWithMaxRatio[1];

        // Return the maximum minimum ratio
        return (int) Math.ceil(
            (double) totalQuantityOfType / storesAssignedToType
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimizedMaximum(self, n, quantities):
        m = len(quantities)

        # Create a list of tuples (-ratio, quantity, stores_assigned)
        type_store_pairs = [(-q, q, 1) for q in quantities]

        # Use heapq.heapify() to convert the list into a heap in O(m) time
        heapq.heapify(type_store_pairs)

        # Iterate over the remaining n - m stores
        for _ in range(n - m):
            # Pop the element with the maximum ratio (due to negative sign it's min-heap)
            (
                neg_ratio,
                total_quantity_of_type,
                stores_assigned_to_type,
            ) = heapq.heappop(type_store_pairs)

            # Calculate the new ratio after assigning one more store
            new_stores_assigned_to_type = stores_assigned_to_type + 1
            new_ratio = total_quantity_of_type / new_stores_assigned_to_type

            # Push the updated pair back into the heap
            heapq.heappush(
                type_store_pairs,
                (
                    -new_ratio,
                    total_quantity_of_type,
                    new_stores_assigned_to_type,
                ),
            )

        # Pop the first element to get the final ratio
        _, total_quantity_of_type, stores_assigned_to_type = heapq.heappop(
            type_store_pairs
        )

        # Return the maximum minimum ratio
        return math.ceil(total_quantity_of_type / stores_assigned_to_type)
```

</details>
