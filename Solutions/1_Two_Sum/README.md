# 1. Two Sum

## Solution #1: Double For-Loops

### The Solution Window (Select Language)

<details open>
  <summary><strong>C++</strong> — <code>1_Two_Sums/CPP/Solution01.cpp</code></summary>

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