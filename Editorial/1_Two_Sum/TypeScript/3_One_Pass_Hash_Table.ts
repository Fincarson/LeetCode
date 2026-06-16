function twoSum(nums: number[], target: number): number[] {
    const seen = new Map<number, number>();

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        const complementIndex = seen.get(complement);
        if (complementIndex !== undefined) {
            return [complementIndex, i];
        }

        seen.set(nums[i], i);
    }

    return [];
}
