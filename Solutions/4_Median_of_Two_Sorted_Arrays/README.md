# Problem 4 - Median of Two Sorted Arrays
**Problem Link:** [LeetCode Problem 4 - Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=problem-list-v2&envId=array) <br>
<br>

## Solution #1: Double Heap Tree

<!-- C++ -->
<details close><summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> LHS;
        priority_queue<int, vector<int>, greater<int>> RHS;
        int n = 0, m = 0;
        int size_1 = nums1.size(), size_2 = nums2.size();

        while(n < size_1 || m < size_2){
            if(LHS.empty()) {n < size_1 ? LHS.push(nums1[n++]) : LHS.push(nums2[m++]); continue;}

            if(n < size_1){
                if(nums1[n] <= LHS.top()){
                    LHS.push(nums1[n++]);
                } else {
                    RHS.push(nums1[n++]);
                }

                if(LHS.size() < RHS.size()){
                    int temp = RHS.top();
                    RHS.pop();
                    LHS.push(temp);
                } else if(LHS.size() > RHS.size() + 1){
                    int temp = LHS.top();
                    LHS.pop();
                    RHS.push(temp);
                }
            }

            if(m < size_2){
                if(nums2[m] <= LHS.top()){
                    LHS.push(nums2[m++]);
                } else {
                    RHS.push(nums2[m++]);
                }

                if(LHS.size() < RHS.size()){
                    int temp = RHS.top();
                    RHS.pop();
                    LHS.push(temp);
                } else if(LHS.size() > RHS.size() + 1){
                    int temp = LHS.top();
                    LHS.pop();
                    RHS.push(temp);
                }
            }
        }
        return LHS.size() == RHS.size() ? (LHS.top() + RHS.top()) / 2.0 : LHS.top();
    }
};
``` 
Author           : Fincarson [(GitHub)](https://github.com/Fincarson) <br>
Status           : ✅ Accepted (2098/2098) <br>
Time Complexity  : <i>O</i>((M + N)log(m + n)) <br>
Space Complexity : <i>O</i>(M + N) <br>
Date Solved      : Sunday, 22nd March 2026
<br>

🎯 Topics:
- Median
- Heap Tree
- Heap Sort
<br>

---

</details>