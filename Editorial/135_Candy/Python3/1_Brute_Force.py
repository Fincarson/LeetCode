class Solution:
    def candy(self, ratings: List[int]) -> int:
        candies = [1] * len(ratings)
        hasChanged = True
        while hasChanged:
            hasChanged = False
            for i in range(len(ratings)):
                if (
                    i != len(ratings) - 1
                    and ratings[i] > ratings[i + 1]
                    and candies[i] <= candies[i + 1]
                ):
                    candies[i] = candies[i + 1] + 1
                    hasChanged = True
                if (
                    i > 0
                    and ratings[i] > ratings[i - 1]
                    and candies[i] <= candies[i - 1]
                ):
                    candies[i] = candies[i - 1] + 1
                    hasChanged = True
        return sum(candies)
