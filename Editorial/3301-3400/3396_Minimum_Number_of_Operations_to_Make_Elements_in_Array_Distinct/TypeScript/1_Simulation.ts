function minimumOperations(nums: number[]): number {
    let ans = 0;
    for (let i = 0; i < nums.length; i += 3, ans++) {
        if (checkUnique(nums, i)) {
            return ans;
        }
    }
    return ans;
}

function checkUnique(nums: number[], start: number): boolean {
    let seen = new Set<number>();
    for (let i = start; i < nums.length; i++) {
        if (seen.has(nums[i])) {
            return false;
        }
        seen.add(nums[i]);
    }
    return true;
}
