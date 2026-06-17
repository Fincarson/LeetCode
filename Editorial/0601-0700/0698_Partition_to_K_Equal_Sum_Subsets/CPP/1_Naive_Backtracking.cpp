class Solution {
public:
    bool backtrack(vector<int>& arr, int count, int currSum, int k, int targetSum, vector<bool>& taken) {
        int n = arr.size();
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // Current subset sum exceeds target sum, no need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
      
        // When current subset sum reaches target sum then one subset is made.
        // Increment count and reset current subset sum to 0.
        if (currSum == targetSum) {
            return backtrack(arr, count + 1, 0, k, targetSum, taken);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = 0; j < n; ++j) {
            if (!taken[j]) {
                // Include this element in current subset.
                taken[j] = true;
                
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, count, currSum + arr[j], k, targetSum, taken)) {
                    return true;
                }
                
                // Backtrack step.
                taken[j] = false;
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        int targetSum = totalArraySum / k;
        vector<bool> taken(n, false);
      
        return backtrack(arr, 0, 0, k, targetSum, taken);
    }
};
