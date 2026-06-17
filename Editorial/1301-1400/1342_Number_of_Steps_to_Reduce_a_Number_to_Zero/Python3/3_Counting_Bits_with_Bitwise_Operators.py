class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0

        steps = 0
        powerOfTwo = 1
        while powerOfTwo <= num:
            if (powerOfTwo & num) != 0:
                steps = steps + 2
            else:
                steps = steps + 1
            powerOfTwo = powerOfTwo * 2

        return steps - 1
