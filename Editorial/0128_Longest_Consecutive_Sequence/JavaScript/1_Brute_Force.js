var longestConsecutive = function (nums) {
    let longestStreak = 0;
    for (let num of nums) {
        let currentNum = num;
        let currentStreak = 1;
        while (nums.includes(currentNum + 1)) {
            currentNum += 1;
            currentStreak += 1;
        }
        longestStreak = Math.max(longestStreak, currentStreak);
    }
    return longestStreak;
};
