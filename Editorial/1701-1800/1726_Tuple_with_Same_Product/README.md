# 1726. Tuple with Same Product

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/tuple-with-same-product/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 1726 - Tuple with Same Product](https://leetcode.com/problems/tuple-with-same-product/)

## Problem

Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

### Example 1

```text
Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
```

### Example 2

```text
Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 104
- All elements in nums are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1726. Tuple with Same Product

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Optimized Brute Force | C++, Java, Python3 |
| Count Product Frequency | C++, Java, Python3 |
| Product Frequency Hash Map | C++, Java, Python3 |

## Approach 1: Optimized Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();
        sort(nums.begin(), nums.end());

        int totalNumberOfTuples = 0;

        // Iterate over all possible values for 'a'
        for (int aIndex = 0; aIndex < numsLength; aIndex++) {
            // Iterate over all possible values for 'b', starting from the end
            // of the array
            for (int bIndex = numsLength - 1; bIndex >= aIndex + 1; bIndex--) {
                int product = nums[aIndex] * nums[bIndex];

                // Use a hash set to store possible values of 'd'
                unordered_set<int> possibleDValues;

                // Iterate over all possible values for 'c' between 'a' and 'b'
                for (int cIndex = aIndex + 1; cIndex < bIndex; cIndex++) {
                    // Check if the product is divisible by nums[cIndex]
                    if (product % nums[cIndex] == 0) {
                        int dValue = product / nums[cIndex];

                        // If 'dValue' is in the set, increment the tuple count
                        // by 8
                        if (possibleDValues.find(dValue) !=
                            possibleDValues.end()) {
                            totalNumberOfTuples += 8;
                        }

                        // Add nums[cIndex] to the set for future checks
                        possibleDValues.insert(nums[cIndex]);
                    }
                }
            }
        }

        return totalNumberOfTuples;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int tupleSameProduct(int[] nums) {
        int numsLength = nums.length;
        Arrays.sort(nums);

        int totalNumberOfTuples = 0;

        // Iterate over all possible values for 'a'
        for (int aIndex = 0; aIndex < numsLength; aIndex++) {
            // Iterate over all possible values for 'b', starting from the end
            // of the array
            for (int bIndex = numsLength - 1; bIndex >= aIndex + 1; bIndex--) {
                int product = nums[aIndex] * nums[bIndex];

                // Use a hash set to store possible values of 'd'
                Set<Integer> possibleDValues = new HashSet<>();

                // Iterate over all possible values for 'c' between 'a' and 'b'
                for (int cIndex = aIndex + 1; cIndex < bIndex; cIndex++) {
                    // Check if the product is divisible by nums[cIndex]
                    if (product % nums[cIndex] == 0) {
                        int dValue = product / nums[cIndex];

                        // If 'dValue' is in the set, increment the tuple count
                        // by 8
                        if (possibleDValues.contains(dValue)) {
                            totalNumberOfTuples += 8;
                        }

                        // Add nums[cIndex] to the set for future checks
                        possibleDValues.add(nums[cIndex]);
                    }
                }
            }
        }

        return totalNumberOfTuples;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        nums_length = len(nums)
        nums.sort()

        total_number_of_tuples = 0

        # Iterate over all possible values for 'a'
        for a_index in range(nums_length):
            # Iterate over all possible values for 'b', starting from the end
            # of the list
            for b_index in range(nums_length - 1, a_index, -1):
                product = nums[a_index] * nums[b_index]

                # Use a set to store possible values of 'd'
                possible_d_values = set()

                # Iterate over all possible values for 'c' between 'a' and 'b'
                for c_index in range(a_index + 1, b_index):
                    # Check if the product is divisible by nums[c_index]
                    if product % nums[c_index] == 0:
                        d_value = product // nums[c_index]

                        # If 'd_value' is in the set, increment the tuple count
                        # by 8
                        if d_value in possible_d_values:
                            total_number_of_tuples += 8

                        # Add nums[c_index] to the set for future checks
                        possible_d_values.add(nums[c_index])

        return total_number_of_tuples
```

</details>

<br>

## Approach 2: Count Product Frequency

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();

        vector<int> pairProducts;

        int totalNumberOfTuples = 0;

        // Iterate over nums to calculate all pairwise products
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                 secondIndex++) {
                pairProducts.push_back(nums[firstIndex] * nums[secondIndex]);
            }
        }

        sort(pairProducts.begin(), pairProducts.end());

        int lastProductSeen = -1;
        int sameProductCount = 0;

        // Iterate over pairProducts to count how many times each product occurs
        for (int productIndex = 0; productIndex < pairProducts.size();
             productIndex++) {
            if (pairProducts[productIndex] == lastProductSeen) {
                // Increment the count of same products
                sameProductCount++;
            } else {
                // Calculate how many pairs had the previous product value
                int pairsOfEqualProduct =
                    (sameProductCount - 1) * sameProductCount / 2;

                totalNumberOfTuples += 8 * pairsOfEqualProduct;

                // Update lastProductSeen and reset sameProductCount
                lastProductSeen = pairProducts[productIndex];
                sameProductCount = 1;
            }
        }

        // Handle the last group of products (since the loop ends without adding
        // it)
        int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
        totalNumberOfTuples += 8 * pairsOfEqualProduct;

        return totalNumberOfTuples;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int tupleSameProduct(int[] nums) {
        int numsLength = nums.length;

        List<Integer> pairProducts = new ArrayList<>();

        int totalNumberOfTuples = 0;

        // Iterate over nums to calculate all pairwise products
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (
                int secondIndex = firstIndex + 1;
                secondIndex < numsLength;
                secondIndex++
            ) {
                pairProducts.add(nums[firstIndex] * nums[secondIndex]);
            }
        }

        Collections.sort(pairProducts);

        int lastProductSeen = -1;
        int sameProductCount = 0;

        // Iterate over pairProducts to count how many times each product occurs
        for (
            int productIndex = 0;
            productIndex < pairProducts.size();
            productIndex++
        ) {
            if (pairProducts.get(productIndex) == lastProductSeen) {
                // Increment the count of same products
                sameProductCount++;
            } else {
                // Calculate how many pairs had the previous product value
                int pairsOfEqualProduct =
                    ((sameProductCount - 1) * sameProductCount) / 2;

                totalNumberOfTuples += 8 * pairsOfEqualProduct;

                // Update lastProductSeen and reset sameProductCount
                lastProductSeen = pairProducts.get(productIndex);
                sameProductCount = 1;
            }
        }

        // Handle the last group of products (since the loop ends without adding
        // it)
        int pairsOfEqualProduct =
            ((sameProductCount - 1) * sameProductCount) / 2;
        totalNumberOfTuples += 8 * pairsOfEqualProduct;

        return totalNumberOfTuples;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tupleSameProduct(self, nums):
        nums_length = len(nums)

        pair_products = []

        total_number_of_tuples = 0

        # Iterate over nums to calculate all pairwise products
        for first_index in range(nums_length):
            for second_index in range(first_index + 1, nums_length):
                pair_products.append(nums[first_index] * nums[second_index])

        pair_products.sort()

        last_product_seen = -1
        same_product_count = 0

        # Iterate over pair_products to count how many times each product occurs
        for product_index in range(len(pair_products)):
            if pair_products[product_index] == last_product_seen:
                # Increment the count of same products
                same_product_count += 1
            else:
                # Calculate how many pairs had the previous product value
                pairs_of_equal_product = (
                    (same_product_count - 1) * same_product_count // 2
                )

                total_number_of_tuples += 8 * pairs_of_equal_product

                # Update last_product_seen and reset same_product_count
                last_product_seen = pair_products[product_index]
                same_product_count = 1

        # Handle the last group of products (since the loop ends without adding
        # it)
        pairs_of_equal_product = (
            (same_product_count - 1) * same_product_count // 2
        )
        total_number_of_tuples += 8 * pairs_of_equal_product

        return total_number_of_tuples
```

</details>

<br>

## Approach 3: Product Frequency Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();

        // Initialize an unordered map to store the frequency of each product of
        // pairs
        unordered_map<int, int> pairProductsFrequency;

        int totalNumberOfTuples = 0;

        // Iterate through each pair of numbers in `nums`
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                 secondIndex++) {
                // Increment the frequency of the product of the current pair
                pairProductsFrequency[nums[firstIndex] * nums[secondIndex]]++;
            }
        }

        // Iterate through each product value and its frequency in the map
        for (auto [productValue, productFrequency] : pairProductsFrequency) {
            // Calculate the number of ways to choose two pairs with the same
            // product
            int pairsOfEqualProduct =
                (productFrequency - 1) * productFrequency / 2;

            // Add the number of tuples for this product to the total (each pair
            // can form 8 tuples)
            totalNumberOfTuples += 8 * pairsOfEqualProduct;
        }

        return totalNumberOfTuples;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int tupleSameProduct(int[] nums) {
        int numsLength = nums.length;

        // Initialize a map to store the frequency of each product of pairs
        Map<Integer, Integer> pairProductsFrequency = new HashMap<>();

        int totalNumberOfTuples = 0;

        // Iterate through each pair of numbers in `nums`
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (
                int secondIndex = firstIndex + 1;
                secondIndex < numsLength;
                secondIndex++
            ) {
                // Increment the frequency of the product of the current pair
                pairProductsFrequency.put(
                    nums[firstIndex] * nums[secondIndex],
                    pairProductsFrequency.getOrDefault(
                        nums[firstIndex] * nums[secondIndex],
                        0
                    ) +
                    1
                );
            }
        }

        // Iterate through each product value and its frequency in the map
        for (int productValue : pairProductsFrequency.keySet()) {
            int productFrequency = pairProductsFrequency.get(productValue);
            // Calculate the number of ways to choose two pairs with the same product
            int pairsOfEqualProduct =
                ((productFrequency - 1) * productFrequency) / 2;

            // Add the number of tuples for this product to the total (each pair
            // can form 8 tuples)
            totalNumberOfTuples += 8 * pairsOfEqualProduct;
        }

        return totalNumberOfTuples;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def tupleSameProduct(self, nums):
        nums_length = len(nums)

        # Initialize a dictionary to store the frequency of each product of pairs
        pair_products_frequency = {}

        total_number_of_tuples = 0

        # Iterate through each pair of numbers in `nums`
        for first_index in range(nums_length):
            for second_index in range(first_index + 1, nums_length):
                # Increment the frequency of the product of the current pair
                product_value = nums[first_index] * nums[second_index]
                if product_value in pair_products_frequency:
                    pair_products_frequency[product_value] += 1
                else:
                    pair_products_frequency[product_value] = 1

        # Iterate through each product value and its frequency in the dictionary
        for product_frequency in pair_products_frequency.values():
            # Calculate the number of ways to choose two pairs with the same product
            pairs_of_equal_product = (
                (product_frequency - 1) * product_frequency // 2
            )

            # Add the number of tuples for this product to the total (each pair
            # can form 8 tuples)
            total_number_of_tuples += 8 * pairs_of_equal_product

        return total_number_of_tuples
```

</details>
