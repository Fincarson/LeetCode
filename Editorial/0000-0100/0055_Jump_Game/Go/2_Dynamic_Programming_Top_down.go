type Index int

const (
    GOOD    Index = 1
    BAD     Index = 2
    UNKNOWN Index = 0
)

var memo []Index

func canJumpFromPosition(position int, nums []int) bool {
    if memo[position] != UNKNOWN {
        return memo[position] == GOOD
    }
    furthestJump := position + nums[position]
    if furthestJump > len(nums)-1 {
        furthestJump = len(nums) - 1
    }
    for nextPosition := position + 1; nextPosition <= furthestJump; nextPosition++ {
        if canJumpFromPosition(nextPosition, nums) {
            memo[position] = GOOD
            return true
        }
    }
    memo[position] = BAD
    return false
}

func canJump(nums []int) bool {
    memo = make([]Index, len(nums))
    for i := range memo {
        memo[i] = UNKNOWN
    }
    memo[len(nums)-1] = GOOD
    return canJumpFromPosition(0, nums)
}
