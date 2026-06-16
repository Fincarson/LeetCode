# 360. Sort Transformed Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sort-transformed-array/)  
`Array` `Math` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 360 - Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array/)

## Problem

Given a sorted integer array nums and three integers a, b and c, apply a quadratic function of the form f(x) = ax2 + bx + c to each element nums[i] in the array, and return the array in a sorted order.

### Example 1

```text
Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
```

### Example 2

```text
Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
```

## Constraints

- 1 <= nums.length <= 200
- -100 <= nums[i], a, b, c <= 100
- nums is sorted in ascending order.

Follow up: Could you solve it in O(n) time?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Time to Repair Cars](https://leetcode.com/problems/minimum-time-to-repair-cars/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 360. Sort Transformed Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Naive Sorting | C++, Java, JavaScript, Python3 |
| Two Pointers | C++, Java, JavaScript, Python3 |
| Non-Comparison Based Sorting | C++, Java, Python3 |

## Approach 1: Naive Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> answer;
        for(int& num : nums) {
            // Push transformed value in the 'answer' array.
            answer.push_back((a * num * num) + (b * num) + c);
        }
        // Sort the array of transformed values.
        sort(answer.begin(), answer.end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int[] answer = new int[n];
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            // Push transformed value in the 'answer' array.
            answer[i] = (a * num * num) + (b * num) + c;
        }
        // Sort the array of transformed values.
        Arrays.sort(answer);
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortTransformedArray = function(nums, a, b, c) {
    let answer = [];
    nums.forEach(num => {
        // Push transformed value in the 'answer' array.
        answer.push((a * num * num) + (b * num) + c);
    });
    // Sort the array of transformed values.
    answer.sort((num1, num2) => num1 - num2);
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        answer = []
        for num in nums:
            # Push transformed value in the 'answer' array.
            answer.append((a * num * num) + (b * num) + c)
        # Sort the array of transformed values.
        answer.sort()
        return answer
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int transform(int& x, int& a, int& b, int& c) {
        // Return the transformed result for element 'x'
        return (a * x * x) + (b * x) + c;
    }

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> answer;
        int left = 0, right = nums.size() - 1;
        
        if (a < 0) {
            // When 'downward parabola' we will put the edge element (smaller elements) first.
            while (left <= right) {
                int leftTransformedVal = transform(nums[left], a, b, c);
                int rightTransformedVal = transform(nums[right], a, b, c);
                if (leftTransformedVal < rightTransformedVal) {
                    answer.push_back(leftTransformedVal);
                    left++;
                } else {
                    answer.push_back(rightTransformedVal);
                    right--;
                }
            }
        } else {
            while (left <= right) {
                // When 'upward parabola' or a 'straight line' 
                // we will put the edge element (bigger elements) first.
                int leftTransformedVal = transform(nums[left], a, b, c);
                int rightTransformedVal = transform(nums[right], a, b, c);
                if (leftTransformedVal > rightTransformedVal) {
                    answer.push_back(leftTransformedVal);
                    left++;
                } else {
                    answer.push_back(rightTransformedVal);
                    right--;
                }
            }
            // Reverse the decreasing 'answer' array.
            reverse(answer.begin(), answer.end());
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int transform(int x, int a, int b, int c) {
        // Return the transformed result for element 'x'
        return (a * x * x) + (b * x) + c;
    }

    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int[] answer = new int[nums.length];
        int left = 0, right = nums.length - 1;
        int index = 0;
        
        if (a < 0) {
            // When 'downward parabola' we will put the edge element (smaller elements) first.
            while (left <= right) {
                int leftTransformedVal = transform(nums[left], a, b, c);
                int rightTransformedVal = transform(nums[right], a, b, c);
                if (leftTransformedVal < rightTransformedVal) {
                    answer[index++] = leftTransformedVal;
                    left++;
                } else {
                    answer[index++] = rightTransformedVal;
                    right--;
                }
            }
        } else {
            while (left <= right) {
                // When 'upward parabola' or a 'straight line' 
                // we will put the edge element (bigger elements) first.
                int leftTransformedVal = transform(nums[left], a, b, c);
                int rightTransformedVal = transform(nums[right], a, b, c);
                if (leftTransformedVal > rightTransformedVal) {
                    answer[index++] = leftTransformedVal;
                    left++;
                } else {
                    answer[index++] = rightTransformedVal;
                    right--;
                }
            }
            // Reverse the decreasing 'answer' array.
            for (int i = 0; i < answer.length / 2; i++) {
                int temp = answer[i];
                answer[i] = answer[answer.length - i - 1];
                answer[answer.length - i - 1] = temp;
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Return the transformed result for element 'x'
let transform = (x, a, b, c) => (a * x * x) + (b * x) + c;
    
let sortTransformedArray = function(nums, a, b, c) {
    let answer = [];
    let left = 0, right = nums.length - 1;
        
    if (a < 0) {
        // When 'downward parabola' we will put the edge element (smaller elements) first.
        while (left <= right) {
            const leftTransformedVal = transform(nums[left], a, b, c);
            const rightTransformedVal = transform(nums[right], a, b, c);
            if (leftTransformedVal < rightTransformedVal) {
                answer.push(leftTransformedVal);
                left++;
            } else {
                answer.push(rightTransformedVal);
                right--;
            }
        }
    } else {
        while (left <= right) {
            // When 'upward parabola' or a 'straight line' 
            // we will put the edge element (bigger elements) first.
            const leftTransformedVal = transform(nums[left], a, b, c);
            const rightTransformedVal = transform(nums[right], a, b, c);
            if (leftTransformedVal > rightTransformedVal) {
                answer.push(leftTransformedVal);
                left++;
            } else {
                answer.push(rightTransformedVal);
                right--;
            }
        }
        // Reverse the decreasing 'answer' array.
        answer.reverse();
    }
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        def transform(x):
            # Return the transformed result for element 'x'
            return (a * x * x) + (b * x) + c

        answer = []
        left, right = 0, len(nums) - 1
        
        if a < 0:
            # When 'downward parabola' we will put the edge element (smaller elements) first.
            while left <= right:
                left_transformed_val = transform(nums[left])
                right_transformed_val = transform(nums[right])
                if left_transformed_val < right_transformed_val:
                    answer.append(left_transformed_val)
                    left += 1
                else:
                    answer.append(right_transformed_val)
                    right -= 1
        else:
            while left <= right:
                # When 'upward parabola' or a 'straight line' 
                # we will put the edge element (bigger elements) first.
                left_transformed_val = transform(nums[left])
                right_transformed_val = transform(nums[right])
                if left_transformed_val > right_transformed_val:
                    answer.append(left_transformed_val)
                    left += 1
                else:
                    answer.append(right_transformed_val)
                    right -= 1
            # Reverse the decreasing 'answer' array.
            answer.reverse()
        return answer
```

</details>

<br>

## Approach 3: Non-Comparison Based Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> answer(n);

        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            // Push transformed value in 'answer' array.
            answer[i] = (a * num * num) + (b * num) + c;
        }

        // Find the absolute maximum element to find max number of digits.
        int maxElement = nums[0];
        for (int& num : answer) {
            maxElement = max(abs(num), maxElement);
        }
        int maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++digit) {
            sort(answer, placeValue);
            placeValue *= 10;
        }

        // Seperate out negatives and reverse them. 
        vector<int> negatives, positives;
        for (int& num : answer) {
            if (num < 0) {
                negatives.push_back(num);
            } else {
                positives.push_back(num);
            }
        }
        reverse(negatives.begin(), negatives.end());

        // Final 'answer' will be 'negative' elements, then 'positive' elements.
        merge(negatives.begin(), negatives.end(), positives.begin(), positives.end(), answer.begin());
        return answer;
    }
    
private:
    void sort(vector<int>& array, int placeValue) {
        vector<vector<int>> mapDigits(10, vector<int>());
        for (int& num : array) {
            int digit = abs(num) / placeValue;
            digit = digit % 10;
            mapDigits[digit].push_back(num);
        }

        // Overwrite 'array' in sorted order of current place digits.
        int index = 0;
        for (int digit = 0; digit < 10; ++digit) {
            for (int& num : mapDigits[digit]) {
                array[index] = num;
                index++;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int[] answer = new int[n];
        
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            // Push transformed value in 'answer' array.
            answer[i] = (a * num * num) + (b * num) + c;
        }

        // Find the absolute maximum element to find max number of digits.
        int maxElement = nums[0];
        for (int num : answer) {
            maxElement = Math.max(Math.abs(num), maxElement);
        }
        int maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++digit) {
            sort(answer, placeValue);
            placeValue *= 10;
        }

        // Seperate out negatives and reverse them. 
        ArrayList<Integer> negatives = new ArrayList<>();
        ArrayList<Integer> positives = new ArrayList<>();

        for (int num : answer) {
            if (num < 0) {
                negatives.add(num);
            } else {
                positives.add(num);
            }
        }
        Collections.reverse(negatives);

        // Final 'answer' will be 'negative' elements, then 'positive' elements.
        int index = 0;
        for (int num : negatives) {
            answer[index] = num;
            index++;
        }
        for (int num : positives) {
            answer[index] = num;
            index++;
        }
        return answer;
    }

    private void sort(int[] array, int placeValue) {
        ArrayList<List<Integer>> mapDigits = new ArrayList<>(10);
        for (int digit = 0; digit < 10; ++digit) {
            mapDigits.add(digit, new ArrayList<Integer>());
        }

        for (int num : array) {
            int digit = Math.abs(num) / placeValue;
            digit = digit % 10;
            mapDigits.get(digit).add(num);
        }

        // Overwrite 'array' in sorted order of current place digits.
        int index = 0;
        for (int digit = 0; digit < 10; ++digit) {
            for (int num : mapDigits.get(digit)) {
                array[index] = num;
                index++;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortTransformedArray(self, nums: List[int], a: int, b: int, c: int) -> List[int]:
        answer = [0] * len(nums)
        for i, num in enumerate(nums):
            # Push transformed value in 'answer' array.
            answer[i] = (a * num * num) + (b * num) + c

        # Find the absolute maximum element to find max number of digits.
        max_element = nums[0]
        for num in answer:
            max_element = max(abs(num), max_element)

        max_digits = 0
        while max_element > 0:
            max_digits += 1
            max_element /= 10

        place_value = 1
        def sort():
            map_digits = [[] for i in range(10)]
            for num in answer:
                digit = abs(num) / place_value
                digit = int(digit % 10)
                map_digits[digit].append(num)

            # Overwrite 'answer' in sorted order of current place digits.
            index = 0
            for digit in range(10):
                for num in map_digits[digit]:
                    answer[index] = num
                    index += 1

        # Radix sort, least significant digit place to most significant.      
        for _ in range(max_digits):
            sort()
            place_value *= 10

        # Seperate out negatives and reverse them. 
        positives = [num for num in answer if num >= 0]
        negatives = [num for num in answer if num < 0]
        negatives.reverse()

        # Final 'answer' will be 'negative' elements, then 'positive' elements.
        answer = negatives + positives
        return answer
```

</details>
