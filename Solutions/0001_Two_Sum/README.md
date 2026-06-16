# Problem 1 - Two Sum
**Problem Link:** [LeetCode Problem 1 - Two Sum](https://leetcode.com/problems/two-sum/description/) <br>
<br>

## Solution #1: Double For-Loops (Brute Force)

<!-- C -->
<details close><summary><strong>C</strong></summary>

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                int* result = malloc(2*sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                
                return result;
            }
        }
    }
    return malloc(0);
}
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (63/63) <br>
Time Complexity  : <i>O</i>O(N<sup>2</sup>) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Wednesday 25th February 2026
<br>

📝 Explanation:<br>
1. Loop `i` from `0` to `n-1`. <br>
2. For each `i`, loop `j` from `i+1` to `n-1`. <br>
3. Check whether `nums[i] + nums[j] == target` is true or not. <br>
4. If yes, return the result immediately. <br>
5. If no pair matches, return an empty array. <br>
<br>

🎯 Topics:
- Looping
<br>

---

</details>

<!-- C++ -->
<details close><summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (63/63) <br>
Time Complexity  : <i>O</i>O(N<sup>2</sup>) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Wednesday 25th February 2026
<br>

📝 Explanation:<br>
1. Loop `i` from `0` to `n-1`. <br>
2. For each `i`, loop `j` from `i+1` to `n-1`. <br>
3. Check whether `nums[i] + nums[j] == target` is true or not. <br>
4. If yes, return `{i, j}` immediately. <br>
5. If no pair matches, return an empty vector. <br>
<br>

🎯 Topics:
- Looping
<br>

---

</details>


<!-- Python -->
<details close><summary><strong>Python</strong></summary>

```py
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        size = len(nums)
        for i in range(size):
            for j in range(i+1, size):
                if(nums[i] + nums[j] == target):
                    return [i, j]
        
        return []
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (63/63) <br>
Time Complexity  : <i>O</i>O(N<sup>2</sup>) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Wednesday 25th February 2026
<br>

📝 Explanation:<br>
1. Loop `i` from `0` to `n-1`. <br>
2. For each `i`, loop `j` from `i+1` to `n-1`. <br>
3. Check whether `nums[i] + nums[j] == target` is true or not. <br>
4. If yes, return `[i, j]` immediately. <br>
5. If no pair matches, return an empty list. <br>
<br>

🎯 Topics:
- Looping
<br>

---

</details>


<!-- Python3 -->
<details close><summary><strong>Python3</strong></summary>

```py3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        size = len(nums)
        for i in range(size):
            for j in range(i+1, size):
                if(nums[i] + nums[j] == target):
                    return [i, j]

        return []
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (63/63) <br>
Time Complexity  : <i>O</i>O(N<sup>2</sup>) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Wednesday 25th February 2026
<br>

📝 Explanation:<br>
1. Loop `i` from `0` to `n-1`. <br>
2. For each `i`, loop `j` from `i+1` to `n-1`. <br>
3. Check whether `nums[i] + nums[j] == target` is true or not. <br>
4. If yes, return `[i, j]` immediately. <br>
5. If no pair matches, return an empty list. <br>
<br>

🎯 Topics:
- Looping
<br>

---

</details>


<!-- Dart -->
<details close><summary><strong>Dart</strong></summary>

```dart
class Solution {
  List<int> twoSum(List<int> nums, int target) {
    for(int i = 0; i < nums.length; i++){
        for(int j = i + 1; j < nums.length; j++){
            if(nums[i] + nums[j] == target){
                return [i, j];
            }
        }
    }
    return [];
  }
}
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (63/63) <br>
Time Complexity  : <i>O</i>O(N<sup>2</sup>) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Tuesday 3rd March 2026
<br>

📝 Explanation:<br>
1. Loop `i` from `0` to `n-1`. <br>
2. For each `i`, loop `j` from `i+1` to `n-1`. <br>
3. Check whether `nums[i] + nums[j] == target` is true or not. <br>
4. If yes, return `[i, j]` immediately. <br>
5. If no pair matches, return an empty list. <br>
<br>

🎯 Topics:
- Looping
<br>

---

</details>



<br>

## Solution 2: Hash Table
<!-- C++ -->
<details close><summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(hash.find(complement) != hash.end())
                return {hash[complement], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (63/63) <br>
Time Complexity  : <i>O</i>O(N) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Sunday, 22nd March 2026
<br>

🎯 Topics:
- Hash-Table
<br>

---

</details>

<!-- Python3 -->
<details close><summary><strong>Python3</strong></summary>

```py3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hash: return [hash[complement], i]
            hash[nums[i]] = i
        return []
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (63/63) <br>
Time Complexity  : <i>O</i>O(N) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Sunday, 22nd March 2026
<br>

🎯 Topics:
- Python Dictionary
- Hash-Table
<br>

---

</details>