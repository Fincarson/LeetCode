# Problem 27 - Remove Element
**Problem Link:** [LeetCode Problem 27 - Remove Element](https://leetcode.com/problems/remove-element/description/?envType=problem-list-v2&envId=array) <br>
<br>

## Solution:

<!-- C -->
<details close><summary><strong>C</strong></summary>

```c
int removeElement(int* nums, int numsSize, int val) {
    if(numsSize == 0) return 0;

    int result = 0, j = 0;
    for(int i = 0; i < numsSize; ++i){
        if(nums[i] != val){
            nums[j++] = nums[i];
            ++result;
        }
    }
    return result;
}
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (116/116) <br>
Time Complexity  : <i>O</i>(n) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Monday, 23rd March 2026
<br>

🎯 Topics:
- Array
<br>

---

</details>

<!-- C++ -->
<details close><summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;

        int result = 0, j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[j++] = nums[i];
                ++result;
            }
        }
        return result;
    }
};
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (116/116) <br>
Time Complexity  : <i>O</i>(n) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Monday, 23rd March 2026
<br>

🎯 Topics:
- Array
<br>

---

</details>

<!-- Python -->
<details close><summary><strong>Python3</strong></summary>

```py
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if(len(nums) == 0): return 0

        result = 0
        j = 0

        for i in range(len(nums)):
            if(nums[i] != val):
                nums[j] = nums[i]
                j += 1
                result += 1

        return result
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (362/362) <br>
Time Complexity  : <i>O</i>(n) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Monday, 23rd March 2026
<br>

🎯 Topics:
- Array
<br>

---

</details>