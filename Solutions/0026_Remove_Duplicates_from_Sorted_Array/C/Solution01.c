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