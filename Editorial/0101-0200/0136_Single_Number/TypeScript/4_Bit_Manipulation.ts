// TypeScript
function singleNumber(nums: number[]): number {
    let a = 0;
    for (let i of nums) {
        a ^= i;
    }
    return a;
}
