# Problem 26 - Remove Duplicates from Sorted Array
**Problem Link:** [LeetCode Problem 26 - Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=problem-list-v2&envId=array) <br>
<br>

## Solution:

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
Status           : ✅ Accepted (362/362) <br>
Time Complexity  : <i>O</i>(n) <br>
Space Complexity : <i>O</i>(1) <br>
Date Solved      : Sunday, 22nd March 2026
<br>

🎯 Topics:
- Array
<br>

---

</details>