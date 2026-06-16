var canJumpFromPosition = function (position, nums) {
    if (position == nums.length - 1) {
        return true;
    }
    let furthestJump = Math.min(position + nums[position], nums.length - 1);
    for (
        let nextPosition = position + 1;
        nextPosition <= furthestJump;
        nextPosition++
    ) {
        if (canJumpFromPosition(nextPosition, nums)) {
            return true;
        }
    }
    return false;
};
var canJump = function (nums) {
    return canJumpFromPosition(0, nums);
};
