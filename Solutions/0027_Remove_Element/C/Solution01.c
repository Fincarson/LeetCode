int removeElement(int* nums, int numsSize, int val) {
    if(numsSize == 0) return 0;

    int result = 0, j = 0;
    for(int i = 0; i < numsSize; ++i){
        if(nums[i] != val){
            nums[j++] = nums[i];
            ++result;
        }
    }
    return result;
}