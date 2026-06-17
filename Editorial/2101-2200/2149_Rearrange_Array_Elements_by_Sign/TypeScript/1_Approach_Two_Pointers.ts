function rearrangeArray(nums: number[]): number[] {
    const n: number = nums.length;

    // Initializing an answer array of size n
    const ans: number[] = new Array(n);

    // Initializing two pointers to track even and 
    // odd indices for positive and negative integers respectively
    let posIndex: number = 0;
    let negIndex: number = 1;

    for (let i = 0; i < n; i++) {
        if (nums[i] > 0) {
            // Placing the positive integer at the 
            // desired index in ans and incrementing posIndex by 2
            ans[posIndex] = nums[i];
            posIndex += 2;
        } else {
            // Placing the negative integer at the 
            // desired index in ans and incrementing negIndex by 2
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return ans;
};
