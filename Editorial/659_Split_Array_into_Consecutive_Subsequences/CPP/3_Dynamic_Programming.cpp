class Solution {
public:
    bool isPossible(vector<int> &nums) {
        int n = nums.size();
        int start = 0;

        for (int i = 1; i < n; i++) {
            // Check the possibility of a valid segment starting at index start and ending at index i - 1.
            if (nums[i] - nums[i - 1] > 1) {
                if (!isSegmentValid(nums, start, i - 1)) {
                    return false;
                }
                // Update the starting index of the next segment.
                start = i;
            }
        }
        // Check for the last segment
        return isSegmentValid(nums, start, n - 1);
    }
    
private:
    bool isSegmentValid(vector<int> &nums, int start, int end) {
        int noOfUniqueNumbers = nums[end] - nums[start] + 1;

        // Count the frequency of each number in the current segment.
        vector<int> frequency(noOfUniqueNumbers);
        
        for (int i = start; i <= end; i++) {
            frequency[nums[i] - nums[start]]++;
        }
        // lengthOneSubsequences[i] holds the count of subsequences of length 1 ending with index i
        vector<int> lengthOneSubsequences(noOfUniqueNumbers);

        // lengthTwoSubsequences[i] holds the count of subsequences of length 2 ending with index i
        vector<int> lengthTwoSubsequences(noOfUniqueNumbers);

        // totalNoOfSubsequences[i] holds the count of all subsequences ending with index i
        vector<int> totalNoOfSubsequences(noOfUniqueNumbers);

        lengthOneSubsequences[0] = totalNoOfSubsequences[0] = frequency[0];

        for (int i = 1; i < noOfUniqueNumbers; i++) {

            // If the frequency[i] is less than the total number of subsequences ending with i - 1,
            // we do not have enough subsequences where we can put i.
            if (frequency[i] < lengthOneSubsequences[i - 1] + lengthTwoSubsequences[i - 1]) {
                return false;
            }
            
            //Total number of subsequences of length 2 can be obtained by adding i 
            //to subsequences of length 1 ending with i - 1.
            lengthTwoSubsequences[i] = lengthOneSubsequences[i - 1];
            
            // For the remaining i valued numbers we can either add them to an existing subsequence
            // or create a new one. We first try to add them to the existing subsequences ending 
            // with i - 1. If there are not enough of such subsequences, we start a new subsequence.
            // The existing subsequences ending with i - 1 are denoted by totalNoOfSubsequences[i - 1];
            lengthOneSubsequences[i] = max(0, frequency[i] - totalNoOfSubsequences[i - 1]);
            totalNoOfSubsequences[i] = frequency[i];
        }

        // If there is no remaining subsequence of length one or two, we can return true. 
        // Otherwise, return false.
        return lengthOneSubsequences[noOfUniqueNumbers - 1] == 0 && 
               lengthTwoSubsequences[noOfUniqueNumbers - 1] == 0;
    }
};
