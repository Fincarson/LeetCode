# Two Sum

## Solution #1: Double For-Loops
**Problem Link:** https://leetcode.com/problems/two-sum/  

<details open>
  <summary><strong>C++</strong></summary>
  
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
Author: Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Time Complexity: O(N<sup>2</sup>) <br>
Space Complexity: O(1) <br>
<br>
Step-by-step Explanation<br>
1. Loop i from 0 to n-1. <br>
2. For each i, loop j from i+1 to n-1. <br>
3. Check whether nums[i] + nums[j] == target. <br>
4. If yes, return {i, j} immediately. <br>
5. If no pair matches, return an empty vector. <br>
<br>
Author's Note <br>
This brute-force solution is the most straightforward <br>
Later, you can upgrade to the hash-map approach to achieve O(N) time.
</details>