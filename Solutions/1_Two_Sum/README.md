# Two Sum

## Solution #1: Double For-Loops


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
Author: Fincarson [GitHub](https://github.com/Fincarson) <br>
Time Complexity: O(N^2) <br>
Space Complexity: O(1) <br>
</details>