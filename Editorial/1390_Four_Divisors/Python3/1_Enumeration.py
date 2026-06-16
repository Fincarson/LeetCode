class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            # factor_cnt: number of factors
            # factor_sum: sum of factors
            factor_cnt = factor_sum = 0
            i = 1
            while i * i <= num:
                if num % i == 0:
                    factor_cnt += 1
                    factor_sum += i
                    if (
                        i * i != num
                    ):  # check if i and num/i are equal; if not, consider num/i as a new factor.
                        factor_cnt += 1
                        factor_sum += num // i
                i += 1
            if factor_cnt == 4:
                ans += factor_sum
        return ans
