var longestConsecutive = function (nums) {
    if (nums.length == 0) {
        return 0;
    }
    nums.sort((a, b) => a - b);
    let longestStreak = 1;
    let currentStreak = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] != nums[i - 1]) {
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak += 1;
            } else {
                longestStreak = Math.max(longestStreak, currentStreak);
                currentStreak = 1;
            }
        }
    }
    return Math.max(longestStreak, currentStreak);
};
