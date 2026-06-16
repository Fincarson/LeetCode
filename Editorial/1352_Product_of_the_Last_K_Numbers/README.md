# 1352. Product of the Last K Numbers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/product-of-the-last-k-numbers/)  
`Array` `Math` `Design` `Data Stream` `Prefix Sum`

**Problem Link:** [LeetCode 1352 - Product of the Last K Numbers](https://leetcode.com/problems/product-of-the-last-k-numbers/)

## Problem

Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

- ProductOfNumbers() Initializes the object with an empty stream.
- void add(int num) Appends the integer num to the stream.
- int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.

The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

Example:

```text
Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32
```

## Constraints

- 0 <= num <= 100
- 1 <= k <= 4 * 104
- At most 4 * 104 calls will be made to add and getProduct.
- The product of the stream at any point in time will fit in a 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1352. Product of the Last K Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Product | C++, Java, Python3 |

## Approach: Prefix Product

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class ProductOfNumbers {
private:
    // Stores cumulative product of the stream
    vector<int> prefixProduct;
    int size = 0;

public:
    ProductOfNumbers() {
        // Initialize the product list with 1 to handle multiplication logic
        prefixProduct.push_back(1);
        size = 0;
    }

    void add(int num) {
        if (num == 0) {
            // If num is 0, reset the cumulative products since multiplication
            // with 0 invalidates previous products
            prefixProduct = {1};
            size = 0;
        } else {
            // Append the cumulative product of the current number with the last
            // product
            prefixProduct.push_back(prefixProduct[size] * num);
            size++;
        }
    }

    int getProduct(int k) {
        // Check if the requested product length exceeds the size of the valid
        // product list
        if (k > size) return 0;

        // Compute the product of the last k elements using division
        return prefixProduct[size] / prefixProduct[size - k];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class ProductOfNumbers {

    // Stores cumulative product of the stream
    private ArrayList<Integer> prefixProduct = new ArrayList<>();
    private int size = 0;

    public ProductOfNumbers() {
        // Initialize the product list with 1 to handle multiplication logic
        this.prefixProduct.add(1);
        this.size = 0;
    }

    public void add(int num) {
        if (num == 0) {
            // If num is 0, reset the cumulative products since multiplication
            // with 0 invalidates previous products
            this.prefixProduct = new ArrayList<Integer>();
            this.prefixProduct.add(1);
            this.size = 0;
        } else {
            // Append the cumulative product of the current number with the last
            // product
            this.prefixProduct.add(this.prefixProduct.get(size) * num);
            this.size++;
        }
    }

    public int getProduct(int k) {
        // Check if the requested product length exceeds the size of the valid
        // product list
        if (k > this.size) return 0;

        // Compute the product of the last k elements using division
        return (
            this.prefixProduct.get(this.size) /
            this.prefixProduct.get(this.size - k)
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class ProductOfNumbers:
    # Stores cumulative product of the stream
    def __init__(self):
        # Initialize the product list with 1 to handle multiplication logic
        self.prefix_product = [1]
        self.size = 0

    def add(self, num: int):
        if num == 0:
            # If num is 0, reset the cumulative products since multiplication
            # with 0 invalidates previous products
            self.prefix_product = [1]
            self.size = 0
        else:
            # Append the cumulative product of the current number with the last
            # product
            self.prefix_product.append(self.prefix_product[self.size] * num)
            self.size += 1

    def getProduct(self, k: int) -> int:
        # Check if the requested product length exceeds the size of the valid
        # product list
        if k > self.size:
            return 0
        # Compute the product of the last k elements using division
        return (
            self.prefix_product[self.size] // self.prefix_product[self.size - k]
        )
```

</details>
