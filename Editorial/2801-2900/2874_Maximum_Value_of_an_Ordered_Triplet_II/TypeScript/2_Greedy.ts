function maximumTripletValue(nums: number[]): number {
    const n: number = nums.length;
    let res: number = 0,
        imax: number = 0,
        dmax: number = 0;
    for (let k = 0; k < n; k++) {
        res = Math.max(res, dmax * nums[k]);
        dmax = Math.max(dmax, imax - nums[k]);
        imax = Math.max(imax, nums[k]);
    }
    return res;
}
