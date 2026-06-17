# 1200. Minimum Absolute Difference

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-absolute-difference/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 1200 - Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)

## Problem

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

- a, b are from arr
- a < b
- b - a equals to the minimum absolute difference of any two elements in arr

### Example 1

```text
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
```

### Example 2

```text
Input: arr = [1,3,6,10,15]
Output: [[1,3]]
```

### Example 3

```text
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
```

## Constraints

- 2 <= arr.length <= 105
- -106 <= arr[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimize the Maximum Difference of Pairs](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1200. Minimum Absolute Difference

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort + 2 Traversals | C++, Java, JavaScript, Python3 |
| Sort + 1 Traversal | C++, Java, JavaScript, Python3 |
| Counting Sort | C++, Java, JavaScript, Python3 |

## Approach 1: Sort + 2 Traversals

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) { 
        // Sort the original array 
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;

        // Initialize minimum difference as a huge integer in order not
        // to miss the absolute difference of the first pair. 
        int minPairDiff = INT_MAX;

        // Traverse the sorted array and calcalute the minimum absolute difference.
        for (int i = 0; i < arr.size() - 1; ++i) {
            minPairDiff = min(minPairDiff, arr[i + 1] - arr[i]);
        }

        // Traverse the sorted array and check every pair again, if 
        // the absolute difference equals the minimum difference, add 
        // this pair to the answer list.
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == minPairDiff) {
                answer.push_back({arr[i], arr[i + 1]});
            }
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
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        // Sort the original array 
        Arrays.sort(arr);
        List<List<Integer>> answer = new ArrayList();

        // Initialize minimum difference as a huge integer in order not 
        // to miss the absolute difference of the first pair. 
        int minPairDiff = Integer.MAX_VALUE;
        
        // Traverse the sorted array and calcalute the minimum absolute difference.
        for (int i = 0; i < arr.length - 1; ++i) {
            minPairDiff = Math.min(minPairDiff, arr[i + 1] - arr[i]);
        }

        // Traverse the sorted array and check every pair again, if 
        // the absolute difference equals the minimum difference, 
        // add this pair to the answer list.        
        for (int i = 0; i < arr.length - 1; ++i) {
            if (arr[i + 1] - arr[i] == minPairDiff) {
                answer.add(Arrays.asList(arr[i], arr[i + 1]));
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
var minimumAbsDifference = function(arr) {
    // Sort the original array
    arr.sort((x, y) => x - y);
    let answer = [];

    // Initialize minimum difference as a huge integer in order not 
    // to miss the absolute difference of the first pair. 
    let minPairDiff = Infinity;

    // Traverse the sorted array and calcalute the minimum absolute difference.
    for (let i = 0; i < arr.length - 1; ++i) {
        minPairDiff = Math.min(minPairDiff, arr[i + 1] - arr[i]);
    }

    // Traverse the sorted array and check every pair again, if 
    // the absolute difference equals the minimum difference, 
    // add this pair to the answer list.
    for (let i = 0; i < arr.length - 1; ++i) {
        if (arr[i + 1] - arr[i] == minPairDiff) {
            answer.push([arr[i], arr[i + 1]]);
        }
    }

    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # Sort the original array 
        arr.sort()
        answer = []

        # Initialize minimum difference as a huge integer in order not 
        # to miss the absolute difference of the first pair. 
        min_pair_diff = float('inf')
        
        # Traverse the sorted array and calcalute the minimum absolute difference.
        for i in range(len(arr) - 1):
            min_pair_diff = min(min_pair_diff, arr[i + 1] - arr[i])
        
        # Traverse the sorted array and check every pair again, if 
        # the absolute difference equals the minimum difference, 
        # add this pair to the answer list. 
        for i in range(len(arr) - 1):   
            if arr[i + 1] - arr[i] == min_pair_diff:
                answer.append([arr[i], arr[i + 1]])
        return answer
```

</details>

<br>

## Approach 2: Sort + 1 Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Sort the original array
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;

        // Initialize minimum difference `minPairDiff` as a huge integer in order not 
        // to miss the absolute difference of the first pair. 
        int minPairDiff = INT_MAX;

        // Traverse the sorted array
        for (int i = 0; i < arr.size() - 1; ++i) {            
            // For the absolute value `currPairDiff` of the current pair:
            int currPairDiff = arr[i + 1] - arr[i];

            // If `currPairDiff` equals `minPairDiff`, add this pair to the answer list.
            // If `currPairDiff` is smaller than `minPairDiff`, discard all pairs in the answer list, 
            // add this pair to the answer list and update `minPairDiff`.
            // If `currPairDiff` is larger than `minPairDiff`, we just go ahead.
            if (currPairDiff == minPairDiff) {
                answer.push_back({arr[i], arr[i + 1]});           
            } else if (currPairDiff < minPairDiff) {
                answer = {};
                answer.push_back({arr[i], arr[i + 1]});
                minPairDiff = currPairDiff;
            }
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
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        // Sort the original array
        Arrays.sort(arr);

        // Initialize minimum difference `minPairDiff` as a huge integer in order not 
        // to miss the absolute difference of the first pair. 
        int minPairDiff = Integer.MAX_VALUE;
        List<List<Integer>> answer = new ArrayList();

        // Traverse the sorted array
        for (int i = 0; i < arr.length - 1; ++i) {
            // For the absolute value `currPairDiff` of the current pair:
            int currPairDiff = arr[i + 1] - arr[i];

            // If `currPairDiff` equals `minPairDiff`, add this pair to the answer list.
            // If `currPairDiff` is smaller than `minPairDiff`, discard all pairs in the answer list, 
            // add this pair to the answer list and update `minPairDiff`.
            // If `currPairDiff` is larger than `minPairDiff`, we just go ahead.
            if (currPairDiff == minPairDiff) {
                answer.add(Arrays.asList(arr[i], arr[i + 1]));
            } else if (currPairDiff < minPairDiff) {
                answer.clear();
                answer.add(Arrays.asList(arr[i], arr[i + 1]));
                minPairDiff = currPairDiff;
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
var minimumAbsDifference = function(arr) {
    // Sort the original array
    arr.sort((x, y) => x - y);

    // Initialize minimum difference `minPairDiff` as a huge integer in order not 
    // to miss the absolute difference of the first pair. 
    let minPairDiff = Infinity;
    let answer = [];

    // Traverse the sorted array
    for (let i = 0; i < arr.length - 1; ++i) {
        // For the absolute value `currPairDiff` of the current pair:
        let currPairDiff = arr[i + 1] - arr[i];

        // If `currPairDiff` equals `minPairDiff`, add this pair to the answer list.
        // If `currPairDiff` is smaller than `minPairDiff`, discard all pairs in the answer list, 
        //add this pair to the answer list and update `minPairDiff`.
        // If `currPairDiff` is larger than `minPairDiff`, we just go ahead.
        if (currPairDiff == minPairDiff) {
            answer.push([arr[i], arr[i + 1]]);
        } else if (currPairDiff < minPairDiff) {
            answer = [];
            answer.push([arr[i], arr[i + 1]]);
            minPairDiff = currPairDiff;
        }
    } 

    return answer;   
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # Sort the original array
        arr.sort()

        # Initialize minimum difference `min_pair_diff` as a huge integer in order not 
        # to miss the absolute difference of the first pair. 
        min_pair_diff = float('inf')
        answer = []

        # Traverse the sorted array
        for i in range(len(arr) - 1):
            # For the absolute value `curr_pair_diff` of the current pair:
            curr_pair_diff = arr[i + 1] - arr[i]

            # If `curr_pair_diff` equals `min_pair_diff`, add this pair to the answer list.
            # If `curr_pair_diff` is smaller than `min_pair_diff`, discard all pairs in the answer list, 
            # add this pair to the answer list and update `min_pair_diff`.
            # If `curr_pair_diff` is larger than `min_pair_diff`, we just go ahead.
            if curr_pair_diff == min_pair_diff:
                answer.append([arr[i], arr[i + 1]])
            elif curr_pair_diff < min_pair_diff:
                answer = [[arr[i], arr[i + 1]]]
                min_pair_diff = curr_pair_diff

        return answer
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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Initialize the auxiliary array `line`.
        // Keep a record of the minimum element and the maximum element.
        int minElement = *min_element(arr.begin(), arr.end());
        int maxElement = *max_element(arr.begin(), arr.end());
        int shift = -minElement;
        vector<uint8_t> line(maxElement - minElement + 1);
        vector<vector<int>> answer;
        
        // For each integer `num` in `arr`, we increment line[num + shift] by 1.
        for (const int& num : arr) {
            line[num + shift] = 1;
        }
        
        // Start from the index representing the minimum integer, initialize the 
        // absolute difference `min_pair_diff` as a huge value such as
        // `max_element - min_element` in order not to miss the absolute 
        // difference of the first pair.
        int minPairDiff = maxElement - minElement;
        int prev = 0;
        
        // Iterate over the array `line` and check if line[curr] 
        // holds the occurrence of an input integer.
        for (int curr = 1; curr <= maxElement + shift; ++curr) {
            // If line[curr] == 0, meaning there is no occurrence of the integer (curr - shift) 
            // held by this index, we will move on to the next index.
            if (line[curr] == 0) {
                continue;
            }
            
            // If the difference (curr - prev) equals `minPairDiff`, we add this pair 
            // {prev - shift, curr - shift} to the answer list. Otherwise, if the difference 
            // (curr - prev) is smaller than `minPairDiff`, we empty the answer list and add 
            // the pair {curr - shift, prev - shift} to the answre list and update the `minPairDiff`
            if (curr - prev == minPairDiff) {
                answer.push_back({prev - shift, curr - shift});
            } else if (curr - prev < minPairDiff) {
                minPairDiff = curr - prev;
                answer = {{prev - shift, curr - shift}};
            }        

            // Update prev as curr.
            prev = curr;
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
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        // Initialize the auxiliary array `line`.
        // Keep a record of the minimum element and the maximum element.
        int minElement = arr[0];
        int maxElement = arr[0];
        for (int num : arr) {
            minElement = Math.min(minElement, num);
            maxElement = Math.max(maxElement, num);
        }
        int shift = -minElement;
        int[] line = new int[maxElement - minElement + 1];
        List<List<Integer>> answer = new ArrayList();
        
        // For each integer `num` in `arr`, we increment line[num + shift] by 1.
        for (int num : arr) {
            line[num + shift] = 1;
        }
        
        // Start from the index representing the minimum integer, initialize the 
        // absolute difference `min_pair_diff` as a huge value such as
        // `max_element - min_element` in order not to miss the absolute 
        // difference of the first pair.
        int minPairDiff = maxElement - minElement;
        int prev = 0;
        
        // Iterate over the array `line` and check if line[curr] 
        // holds the occurrence of an input integer.
        for (int curr = 1; curr <= maxElement + shift; ++curr) {
            // If line[curr] == 0, meaning there is no occurrence of the integer (curr - shift) 
            // held by this index, we will move on to the next index.
            if (line[curr] == 0) {
                continue;
            }
            
            // If the difference (curr - prev) equals `minPairDiff`, we add this pair 
            // {prev - shift, curr - shift} to the answer list. Otherwise, if the difference 
            // (curr - prev) is smaller than `minPairDiff`, we empty the answer list and add 
            // the pair {curr - shift, prev - shift} to the answre list and update the `minPairDiff`
            if (curr - prev == minPairDiff) {       
                answer.add(Arrays.asList(prev - shift, curr - shift));
            } else if (curr - prev < minPairDiff) {
                answer = new ArrayList();
                minPairDiff = curr - prev;
                answer.add(Arrays.asList(prev - shift, curr - shift));                
            } 

            // Update prev as curr.           
            prev = curr;
        }  
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumAbsDifference = function(arr) {
    // Initialize the auxiliary array `line`.
    // Keep a record of the minimum element and the maximum element.
    var minElement = arr[0],
        maxElement = arr[0];
    for (const num of arr) {
        minElement = Math.min(minElement, num);
        maxElement = Math.max(maxElement, num);
    }
    var shift = -minElement;
    var line = new Array(maxElement - minElement + 1).fill(0);
    var answer = [];
    
    // For each integer `num` in `arr`, we increment line[num + shift] by 1.
    for (const num of arr) {
        line[num + shift] = 1;
    }
    
    // Initialize the absolute difference `minPairDiff` as a huge value 
	// like `maxElement - minElement` in order not to miss the absolute 
	// difference of the first pair.
    var minPairDiff = maxElement - minElement;
    var prev = 0;
    
    // Iterate over the array `line` and check if line[curr] 
    // holds the occurrence of an input integer.
    for (let curr = 1; curr <= maxElement + shift; ++curr) {
        // If line[curr] == 0, meaning there is no occurrence of the integer (curr - shift) 
        // held by this index, we will move on to the next index.
        if (line[curr] === 0) {
            continue;
        }
        // If the difference (curr - prev) equals `minPairDiff`, we add this pair 
        // {prev - shift, curr - shift} to the answer list. Otherwise, if the difference 
        // (curr - prev) is smaller than `minPairDiff`, we empty the answer list and add 
        // the pair {curr - shift, prev - shift} to the answre list and update the `minPairDiff`
        if (curr - prev === minPairDiff) {
            answer.push([prev - shift, curr - shift]);
        } else if (curr - prev < minPairDiff) {
            answer = [];
            minPairDiff = curr - prev;
            answer.push([prev - shift, curr - shift]);
        }
        
        // Update prev as curr.     
        prev = curr;
    }
    return answer;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # Initialize the auxiliary array `line`.
        # Keep a record of the minimum element and the maximum element.
        min_element = min(arr)
        max_element = max(arr)
        shift = -min_element
        line = [0] * (max_element - min_element + 1)
        answer = []
        
        # For each integer `num` in `arr`, we increment line[num + shift] by 1.
        for num in arr:
            line[num + shift] = 1
        
        # Start from the index representing the minimum integer, initialize the 
        # absolute difference `min_pair_diff` as a huge value such as
        # `max_element - min_element` in order not to miss the absolute 
        # difference of the first pair.
        min_pair_diff = max_element - min_element
        prev = 0
        
        # Iterate over the array `line` and check if line[curr] 
        # holds the occurrence of an input integer.
        for curr in range(1, max_element + shift + 1):
            # If line[curr] == 0, meaning there is no occurrence of the integer (curr - shift) 
            # held by this index, we will move on to the next index.
            if line[curr] == 0:
                continue
                
            # If the difference (curr - prev) equals `min_pair_diff`, we add this pair 
            # {prev - shift, curr - shift} to the answer list. 
            if curr - prev == min_pair_diff:
                answer.append([prev - shift, curr - shift])
            elif curr - prev < min_pair_diff:
                # If the difference (curr - prev) is smaller than `min_pair_diff`, 
                # we empty the answer list and add the pair {curr - shift, prev - shift} 
                # to the answer list and update the `min_pair_diff`
                answer = [[prev - shift, curr - shift]]
                min_pair_diff = curr - prev
            
            # Update prev as curr.     
            prev = curr
            
        return answer
```

</details>
