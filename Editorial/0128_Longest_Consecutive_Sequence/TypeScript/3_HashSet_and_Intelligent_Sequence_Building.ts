function longestConsecutive(nums: number[]): number {
    let num_set: Set<number> = new Set(nums);
    let longestStreak: number = 0;
    for (let num of num_set) {
        if (!num_set.has(num - 1)) {
            let currentNum: number = num;
            let currentStreak: number = 1;
            while (num_set.has(currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = Math.max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}
