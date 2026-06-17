# Problem 26 - Remove Duplicates from Sorted Array
**Problem Link:** [LeetCode Problem 26 - Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=problem-list-v2&envId=array) <br>
<br>

## Solution:

<!-- C -->
<details close><summary><strong>C</strong></summary>

```c
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) return 0;

    int result = 0, j = 0;
    for(int i = 1; i < numsSize; ++i){
        if(nums[i] != nums[j]){
            nums[++j] = nums[i];
            ++result;
        }
    }
    return result + 1;
}
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : Ã¢Å“â€¦ Accepted (362/362) <br>
Time Complexity  : <i>O</i>(n) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Monday, 23rd March 2026
<br>

Ã°Å¸Å½Â¯ Topics:
- Array
<br>

---

</details>

<!-- C++ -->
<details close><summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 0) return 0;

        int n = nums.size();
        int i = 0;
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : Ã¢Å“â€¦ Accepted (362/362) <br>
Time Complexity  : <i>O</i>(n) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Sunday, 22nd March 2026
<br>

Ã°Å¸Å½Â¯ Topics:
- Array
<br>

---

</details>

<!-- Python -->
<details close><summary><strong>Python3</strong></summary>

```py
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if(len(nums) == 0): return 0

        result = 0
        j = 0

        for i in range(1, len(nums)):
            if(nums[j] != nums[i]):
                nums[j+1] = nums[i]
                j += 1
                result += 1
        
        return result + 1
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : Ã¢Å“â€¦ Accepted (362/362) <br>
Time Complexity  : <i>O</i>(n) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Monday, 23rd March 2026
<br>

Ã°Å¸Å½Â¯ Topics:
- Array
<br>

---

</details>