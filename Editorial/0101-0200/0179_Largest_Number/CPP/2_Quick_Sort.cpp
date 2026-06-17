class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort the numbers using Quick Sort
        quickSort(nums, 0, nums.size() - 1);
        // Concatenate sorted numbers to form the largest number
        string largestNum;
        for (int num : nums) {
            largestNum += to_string(num);
        }
        // Handle the case where the largest number is zero
        return largestNum[0] == '0' ? "0" : largestNum;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        // Base case: if the range has one or no elements, it is already sorted
        if (left >= right) return;
        // Partition the array and get the pivot index
        int pivotIndex = partition(nums, left, right);
        // Recursively sort the sub-arrays
        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int lowIndex = left;
        // Rearrange elements so that those greater than the pivot are on the
        // left
        for (int i = left; i < right; ++i) {
            if (compare(nums[i], pivot)) {
                swap(nums[i], nums[lowIndex]);
                ++lowIndex;
            }
        }
        // Place the pivot in its correct position
        swap(nums[lowIndex], nums[right]);
        return lowIndex;
    }

    bool compare(int firstNum, int secondNum) {
        // Compare concatenated strings to decide the order
        return to_string(firstNum) + to_string(secondNum) >
               to_string(secondNum) + to_string(firstNum);
    }
};
