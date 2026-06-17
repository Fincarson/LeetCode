function maxSubsequence(nums: number[], k: number): number[] {
    const n = nums.length;
    const vals: { index: number; value: number }[] = []; // auxiliary array
    for (let i = 0; i < n; ++i) {
        vals.push({ index: i, value: nums[i] }); // store index and value
    }
    // sort by numerical value in descending order
    vals.sort((x1, x2) => x2.value - x1.value);
    // select the first k elements and sort them in ascending order by index
    const topK = vals.slice(0, k); // get the first k elements
    topK.sort((x1, x2) => x1.index - x2.index); // Sort the first k elements in ascending index
    const res: number[] = []; // target subsequence
    for (let i = 0; i < k; ++i) {
        res.push(topK[i].value); // add the sorted values to the result
    }
    return res;
}
