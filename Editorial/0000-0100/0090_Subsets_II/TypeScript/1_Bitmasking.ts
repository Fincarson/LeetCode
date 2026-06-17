var subsetsWithDup = function (nums: number[]): number[][] {
    var n: number = nums.length;
    nums.sort((a: number, b: number): number => a - b);
    var subsets: number[][] = [];
    var seen: Set<string> = new Set();
    var maxNumberOfSubsets: number = Math.pow(2, n);
    for (var subsetIndex = 0; subsetIndex < maxNumberOfSubsets; subsetIndex++) {
        var currentSubset: number[] = [];
        var hashcode: string = "";
        for (var j = 0; j < n; j++) {
            var mask: number = 1 << j;
            var isSet: number = mask & subsetIndex;
            if (isSet != 0) {
                currentSubset.push(nums[j]);
                hashcode += nums[j] + ",";
            }
        }
        if (!seen.has(hashcode)) {
            subsets.push(currentSubset);
            seen.add(hashcode);
        }
    }
    return subsets;
};
